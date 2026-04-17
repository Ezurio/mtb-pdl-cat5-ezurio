/*******************************************************************************
* THIS INFORMATION IS PROPRIETARY TO INFINEON TECHNOLOGIES
*
* ------------------------------------------------------------------------------
*
* Copyright (c) 2025 Infineon Technologies.
*
*          ALL RIGHTS RESERVED
*
********************************************************************************
*
********************************************************************************
*
* File Name: matterkey_cryptoservice.h
*
* Abstract: This file provides prototypes towards crypto service(s) related to
*           Matter Key services.`
*
*******************************************************************************/

#if !defined(_MATTERKEY_CRYPTOSERVICE_H_)
#define _MATTERKEY_CRYPTOSERVICE_H_

#include <stdint.h>

/* Requirement is to support DAC & 5 NoC (can be revoked) certificates */
#define MAX_MATTER_SUPPORTED_NOC_INSTANCES (5)

/* Maximum public key length supported (i.e. ECC-384) */
#define MAX_MATTER_MAX_PUB_KEYLEN          (48)

/* Error Code */
#define STATUS_MATTERKEY_SUCCESS                 (0UL)
#define STATUS_MATTERKEY_OPERATION_NOT_ALLOWED   (1UL)
#define STATUS_MATTERKEY_INVALID_PARAMS          (2UL)
#define STATUS_MATTERKEY_INVALID_KEYTYPE         (3UL)
#define STATUS_MATTERKEY_INVALID_ALGORITHM       (4UL)
#define STATUS_MATTERKEY_INVALID_CALLERCONTEXT   (5UL)
#define STATUS_MATTERKEY_INVALID_HANDLE          (6UL)
#define STATUS_MATTERKEY_KEY_ADD_FAILED          (7UL)
#define STATUS_MATTERKEY_KEY_REMOVE_FAILED       (8UL)
#define STATUS_MATTERKEY_ECC_SIGN_FAILED         (9UL)
#define STATUS_MATTERKEY_KEY_GET_FAILED          (10UL)


/* CAUTION -> Keep below enum(s) consistent with BTFW (sec & nsec) */
/* Alogirthm supported */
typedef enum _tag_enum_matterkey_algo_id
{
    MATTERKEY_ALGO_ECC_SECP256R1,
    MATTERKEY_ALGO_ECC_SECP384R1, /* currently not supported */
    MATTERKEY_ALGO_MAX_ID

}E_MATTERKEY_ALGO_ID;

typedef enum _tag_enum_matterkey_key_id
{
    MATTERKEY_TYPE_DAC=0,
    MATTERKEY_TYPE_NOC_1,
    MATTERKEY_TYPE_NOC_2,
    MATTERKEY_TYPE_NOC_3,
    MATTERKEY_TYPE_NOC_4,
    MATTERKEY_TYPE_NOC_5,
    MATTERKEY_TYPE_MAX_ID
}E_MATTERKEY_KEY_ID;

typedef struct _tag_struct_matterkey_key_property
{
    E_MATTERKEY_KEY_ID      key;
    E_MATTERKEY_ALGO_ID     algo;
    size_t                  len_private_key;
    BOOL32                  mutable;
    uint8_t                 instance;
}T_MATTERKEY_KEY_PROPERTY;

typedef struct _tag_struct_matterkey_stored_key_attributes
{
    E_MATTERKEY_KEY_ID id;
    size_t             keylen;
    uint8_t            p_buff_pubkey[MAX_MATTER_MAX_PUB_KEYLEN];

}E_MATTERKEY_STORED_KEY_ATTRIBUTES;

typedef struct _tag_struct_matterkey_sign_params
{
    E_MATTERKEY_KEY_ID type;

    const uint8_t *ptr_in_msg_buffer; /* message (HASHED/256 bit) buffer to be signed */
    size_t len_in_msg_buffer;         /* 256-bit buffer */

    uint8_t *ptr_out_sig_buffer;      /* buffer to hold signature */
    size_t len_out_sig_buffer;        /* size of buffer signature */
    size_t *ptr_actual_sig_len;      /* actual size of signature */

}T_MATTERKEY_SIGN_PARAMS;


/******************************************************************************

| |__   ___| |_ ____
| '_ \ / _ \ __/ _` |
| |_) |  __/ || (_| |
|_.__/ \___|\__\__._|

FEATURE STATUS: INCOMPLETE+WORK IN PROGRESS
Known Issue:
- key delete (mutable) not implemented.TBD
- failsafe handling to be implemented.TBD
- additional testing required.
- secp-ecc-384 to be added
******************************************************************************/

/**
 * Function matterkey_cryptoservice_init
 *
 * Initialize matter context before use (one-time only). If context lock is enabled, only this caller
 * thread can invoke matter related key-service APIs.
 *
 * \param[in]    flags_lock_context : Enable / Disable thread-context lock.
 *
 * \return       Result - Pass -> STATUS_MATTERKEY_SUCCESS
 */
uint32_t matterkey_cryptoservice_init( uint32_t flags_lock_context );

/**
 * Function matterkey_cryptoservice_inject_key
 *
 * Inject private-key buffer into key-storage. Will fail if key is already present.
 *
 * \param[in]    id_key           : Key id to be stored (mapped to <E_MATTERKEY_KEY_ID>).
 * \param[in]    id_algo          : Algorithm associated with <injected> key.
 * \param[in]    ptr_buffer_key   : Buffer points to RAW private-key data.
 * \param[in]    len_buffer_key   : Length of private-key buffer.
 *
 * \return       Result - Pass -> STATUS_MATTERKEY_SUCCESS
 */
uint32_t matterkey_cryptoservice_inject_key( E_MATTERKEY_KEY_ID id_key, E_MATTERKEY_ALGO_ID id_algo, uint8_t *ptr_buffer_key, size_t len_buffer_key );

/**
 * Function matterkey_cryptoservice_delete_key
 *
 * Delete (mutable) stored key. Required before adding a new one.
 *
 * \param[in]    id_key           : Key id to be stored (mapped to <E_MATTERKEY_KEY_ID>).
 *
 * \return       Result - Pass -> STATUS_MATTERKEY_SUCCESS
 */
uint32_t matterkey_cryptoservice_delete_key( E_MATTERKEY_KEY_ID id_key );

/**
 * Function matterkey_cryptoservice_ecc_get_publickey
 *
 * Returns uncompressed ECC public key corresding to (if) stored. Output format "0x4 <Qx> <Qy>"
 *
 * \param[in]    id_key            : Key id to be stored (mapped to <E_MATTERKEY_KEY_ID>).
 * \param[out]   ptr_out_buffer    : Pointer to the  buffer to hold public-key.
 * \param[in]    len_out_buffer    : Buffer length to hold public-key.
 * \param[out]   ptr_len_act_key   : Holds actual public-key length
 *
 * \return       Result - Pass -> STATUS_MATTERKEY_SUCCESS
 */
uint32_t matterkey_cryptoservice_ecc_get_publickey( E_MATTERKEY_KEY_ID id_key, uint8_t *ptr_out_buffer, uint32_t len_out_buffer, uint32_t *ptr_len_act_key );

/**
 * Function matterkey_cryptoservice_ecc_sign
 *
 * Sign the HASHed input. Output format "<R> <S>"
 *
 * \param[in,out]    ecc_sign_params  : ECC structure to hold signed params. Input is HASH of the input message and size
 *                                      correspinds to alogorthm. i.e. 256-bit (i.e. 32 bytes).
 *
 * \return       Result - Pass -> STATUS_MATTERKEY_SUCCESS
 */
uint32_t matterkey_cryptoservice_ecc_sign( T_MATTERKEY_SIGN_PARAMS *ecc_sign_params );

#endif /* _CRYPTO_SERVICES_KEYRELATED_H_ */
