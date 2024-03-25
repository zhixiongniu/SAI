/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiexperimentaldashflow.h
 *
 * @brief   This module defines SAI P4 extension  interface
 */

#if !defined (__SAIEXPERIMENTALDASHFLOW_H_)
#define __SAIEXPERIMENTALDASHFLOW_H_

#include <saitypesextensions.h>

/**
 * @defgroup SAIEXPERIMENTALDASH_FLOW SAI - Extension specific API definitions
 *
 * @{
 */

/**
 * @brief Attribute ID for dash_flow_flow_table
 */
typedef enum _sai_flow_table_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_FLOW_TABLE_ATTR_START,

    /**
     * @brief Action set_flow_table_attr parameter MAX_FLOW_COUNT
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_TABLE_ATTR_MAX_FLOW_COUNT = SAI_FLOW_TABLE_ATTR_START,

    /**
     * @brief Action set_flow_table_attr parameter DASH_FLOW_ENABLED_KEY
     *
     * @type sai_dash_flow_enabled_key_t
     * @flags CREATE_AND_SET
     * @default SAI_DASH_FLOW_ENABLED_KEY_NONE
     */
    SAI_FLOW_TABLE_ATTR_DASH_FLOW_ENABLED_KEY,

    /**
     * @brief Action set_flow_table_attr parameter FLOW_TTL_IN_MILLISECONDS
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_TABLE_ATTR_FLOW_TTL_IN_MILLISECONDS,

    /**
     * @brief End of attributes
     */
    SAI_FLOW_TABLE_ATTR_END,

    /** Custom range base value */
    SAI_FLOW_TABLE_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_FLOW_TABLE_ATTR_CUSTOM_RANGE_END,

} sai_flow_table_attr_t;

/**
 * @brief Entry for flow_entry
 */
typedef struct _sai_flow_entry_t
{
    /**
     * @brief Switch ID
     *
     * @objects SAI_OBJECT_TYPE_SWITCH
     */
    sai_object_id_t switch_id;

    /**
     * @brief Exact matched key flow_table_id
     *
     * @objects SAI_OBJECT_TYPE_FLOW_TABLE
     */
    sai_object_id_t flow_table_id;

    /**
     * @brief Exact matched key eni_addr
     */
    sai_mac_t eni_addr;

    /**
     * @brief Exact matched key ip_protocol
     */
    sai_uint8_t ip_protocol;

    /**
     * @brief Exact matched key src_ip_addr
     */
    sai_ip_address_t src_ip_addr;

    /**
     * @brief Exact matched key dst_ip_addr
     */
    sai_ip_address_t dst_ip_addr;

    /**
     * @brief Exact matched key src_l4_port
     */
    sai_uint16_t src_l4_port;

    /**
     * @brief Exact matched key dst_l4_port
     */
    sai_uint16_t dst_l4_port;

} sai_flow_entry_t;

/**
 * @brief Attribute ID for dash_flow_flow_entry
 */
typedef enum _sai_flow_entry_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_FLOW_ENTRY_ATTR_START,

    /**
     * @brief Action set_flow_entry_attr parameter VERSION
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_VERSION = SAI_FLOW_ENTRY_ATTR_START,

    /**
     * @brief Action set_flow_entry_attr parameter DASH_DIRECTION
     *
     * @type sai_dash_direction_t
     * @flags CREATE_AND_SET
     * @default SAI_DASH_DIRECTION_INVALID
     */
    SAI_FLOW_ENTRY_ATTR_DASH_DIRECTION,

    /**
     * @brief Action set_flow_entry_attr parameter DASH_FLOW_ACTION
     *
     * @type sai_dash_flow_action_t
     * @flags CREATE_AND_SET
     * @default SAI_DASH_FLOW_ACTION_NONE
     */
    SAI_FLOW_ENTRY_ATTR_DASH_FLOW_ACTION,

    /**
     * @brief Action set_flow_entry_attr parameter VNI
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_VNI,

    /**
     * @brief Action set_flow_entry_attr parameter DEST_VNET_VNI
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_DEST_VNET_VNI,

    /**
     * @brief Action set_flow_entry_attr parameter UNDERLAY_SIP
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_UNDERLAY_SIP,

    /**
     * @brief Action set_flow_entry_attr parameter UNDERLAY_DIP
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_UNDERLAY_DIP,

    /**
     * @brief Action set_flow_entry_attr parameter UNDERLAY_SMAC
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_FLOW_ENTRY_ATTR_UNDERLAY_SMAC,

    /**
     * @brief Action set_flow_entry_attr parameter UNDERLAY_DMAC
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_FLOW_ENTRY_ATTR_UNDERLAY_DMAC,

    /**
     * @brief Action set_flow_entry_attr parameter DASH_ENCAPSULATION
     *
     * @type sai_dash_encapsulation_t
     * @flags CREATE_AND_SET
     * @default SAI_DASH_ENCAPSULATION_INVALID
     */
    SAI_FLOW_ENTRY_ATTR_DASH_ENCAPSULATION,

    /**
     * @brief Action set_flow_entry_attr parameter ORIGINAL_OVERLAY_SIP
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_ORIGINAL_OVERLAY_SIP,

    /**
     * @brief Action set_flow_entry_attr parameter ORIGINAL_OVERLAY_DIP
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_ORIGINAL_OVERLAY_DIP,

    /**
     * @brief Action set_flow_entry_attr parameter IS_IPV6
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_FLOW_ENTRY_ATTR_IS_IPV6,

    /**
     * @brief Action set_flow_entry_attr parameter DST_MAC
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_FLOW_ENTRY_ATTR_DST_MAC,

    /**
     * @brief Action set_flow_entry_attr parameter SIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_SIP,

    /**
     * @brief Action set_flow_entry_attr parameter DIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_DIP,

    /**
     * @brief Action set_flow_entry_attr parameter SIP_MASK
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_SIP_MASK,

    /**
     * @brief Action set_flow_entry_attr parameter DIP_MASK
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_DIP_MASK,

    /**
     * @brief Action set_flow_entry_attr parameter METER_CLASS
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_METER_CLASS,

    /**
     * @brief Action set_flow_entry_attr parameter IS_BIDIRECTIONAL_FLOW
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_FLOW_ENTRY_ATTR_IS_BIDIRECTIONAL_FLOW,

    /**
     * @brief Action set_flow_entry_attr parameter REVERSE_ENI_ADDR
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_FLOW_ENTRY_ATTR_REVERSE_ENI_ADDR,

    /**
     * @brief Action set_flow_entry_attr parameter REVERSE_IP_PROTOCOL
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_REVERSE_IP_PROTOCOL,

    /**
     * @brief Action set_flow_entry_attr parameter SRC_IP_ADDR
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_SRC_IP_ADDR,

    /**
     * @brief Action set_flow_entry_attr parameter DST_IP_ADDR
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_DST_IP_ADDR,

    /**
     * @brief Action set_flow_entry_attr parameter REVERSE_SRC_L4_PORT
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_REVERSE_SRC_L4_PORT,

    /**
     * @brief Action set_flow_entry_attr parameter REVERSE_DST_L4_PORT
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_REVERSE_DST_L4_PORT,

    /**
     * @brief Action set_flow_entry_attr parameter VENDOR_METADATA
     *
     * @type sai_u8_list_t
     * @flags CREATE_AND_SET
     * @default empty
     */
    SAI_FLOW_ENTRY_ATTR_VENDOR_METADATA,

    /**
     * @brief Action set_flow_entry_attr parameter FLOW_DATA_PB
     *
     * @type sai_u8_list_t
     * @flags CREATE_AND_SET
     * @default empty
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_DATA_PB,

    /**
     * @brief IP address family for resource accounting
     *
     * @type sai_ip_addr_family_t
     * @flags READ_ONLY
     * @isresourcetype true
     */
    SAI_FLOW_ENTRY_ATTR_IP_ADDR_FAMILY,

    /**
     * @brief End of attributes
     */
    SAI_FLOW_ENTRY_ATTR_END,

    /** Custom range base value */
    SAI_FLOW_ENTRY_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_FLOW_ENTRY_ATTR_CUSTOM_RANGE_END,

} sai_flow_entry_attr_t;

/**
 * @brief Attribute ID for dash_flow_flow_entry_bulk_get_session_filter
 */
typedef enum _sai_flow_entry_bulk_get_session_filter_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_START,

    /**
     * @brief Action set_flow_entry_bulk_get_session_filter_attr parameter DASH_FLOW_ENTRY_BULK_GET_SESSION_FILTER_KEY
     *
     * @type sai_dash_flow_entry_bulk_get_session_filter_key_t
     * @flags CREATE_AND_SET
     * @default SAI_DASH_FLOW_ENTRY_BULK_GET_SESSION_FILTER_KEY_INVAILD
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_DASH_FLOW_ENTRY_BULK_GET_SESSION_FILTER_KEY = SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_START,

    /**
     * @brief Action set_flow_entry_bulk_get_session_filter_attr parameter DASH_FLOW_ENTRY_BULK_GET_SESSION_OP_KEY
     *
     * @type sai_dash_flow_entry_bulk_get_session_op_key_t
     * @flags CREATE_AND_SET
     * @default SAI_DASH_FLOW_ENTRY_BULK_GET_SESSION_OP_KEY_FILTER_OP_INVALID
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_DASH_FLOW_ENTRY_BULK_GET_SESSION_OP_KEY,

    /**
     * @brief Action set_flow_entry_bulk_get_session_filter_attr parameter INT_VALUE
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_INT_VALUE,

    /**
     * @brief Action set_flow_entry_bulk_get_session_filter_attr parameter IP_VALUE
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_IP_VALUE,

    /**
     * @brief End of attributes
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_END,

    /** Custom range base value */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ATTR_CUSTOM_RANGE_END,

} sai_flow_entry_bulk_get_session_filter_attr_t;

/**
 * @brief Attribute ID for dash_flow_flow_entry_bulk_get_session
 */
typedef enum _sai_flow_entry_bulk_get_session_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_START,

    /**
     * @brief Action set_flow_entry_bulk_get_session_attr parameter BULK_GET_SESSION_IP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_BULK_GET_SESSION_IP = SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_START,

    /**
     * @brief Action set_flow_entry_bulk_get_session_attr parameter BULK_GET_SESSION_PORT
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_BULK_GET_SESSION_PORT,

    /**
     * @brief Action set_flow_entry_bulk_get_session_attr parameter FIRST_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID
     *
     * @type sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_FLOW_ENTRY_BULK_GET_SESSION_FILTER
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_FIRST_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID,

    /**
     * @brief Action set_flow_entry_bulk_get_session_attr parameter SECOND_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID
     *
     * @type sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_FLOW_ENTRY_BULK_GET_SESSION_FILTER
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_SECOND_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID,

    /**
     * @brief Action set_flow_entry_bulk_get_session_attr parameter THIRD_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID
     *
     * @type sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_FLOW_ENTRY_BULK_GET_SESSION_FILTER
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_THIRD_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID,

    /**
     * @brief Action set_flow_entry_bulk_get_session_attr parameter FOURTH_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID
     *
     * @type sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_FLOW_ENTRY_BULK_GET_SESSION_FILTER
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_FOURTH_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID,

    /**
     * @brief Action set_flow_entry_bulk_get_session_attr parameter FIFTH_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID
     *
     * @type sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_FLOW_ENTRY_BULK_GET_SESSION_FILTER
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_FIFTH_FLOW_ENTRY_BULK_GET_SESSION_FILTER_ID,

    /**
     * @brief End of attributes
     */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_END,

    /** Custom range base value */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_CUSTOM_RANGE_START = 0x10000000,

    /** End of custom range base */
    SAI_FLOW_ENTRY_BULK_GET_SESSION_ATTR_CUSTOM_RANGE_END,

} sai_flow_entry_bulk_get_session_attr_t;

/**
 * @brief Create dash_flow_flow_table
 *
 * @param[out] flow_table_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_flow_table_fn)(
        _Out_ sai_object_id_t *flow_table_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove dash_flow_flow_table
 *
 * @param[in] flow_table_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_flow_table_fn)(
        _In_ sai_object_id_t flow_table_id);

/**
 * @brief Set attribute for dash_flow_flow_table
 *
 * @param[in] flow_table_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_flow_table_attribute_fn)(
        _In_ sai_object_id_t flow_table_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for dash_flow_flow_table
 *
 * @param[in] flow_table_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_flow_table_attribute_fn)(
        _In_ sai_object_id_t flow_table_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create dash_flow_flow_entry
 *
 * @param[in] flow_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_flow_entry_fn)(
        _In_ const sai_flow_entry_t *flow_entry,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove dash_flow_flow_entry
 *
 * @param[in] flow_entry Entry
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_flow_entry_fn)(
        _In_ const sai_flow_entry_t *flow_entry);

/**
 * @brief Set attribute for dash_flow_flow_entry
 *
 * @param[in] flow_entry Entry
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_flow_entry_attribute_fn)(
        _In_ const sai_flow_entry_t *flow_entry,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for dash_flow_flow_entry
 *
 * @param[in] flow_entry Entry
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_flow_entry_attribute_fn)(
        _In_ const sai_flow_entry_t *flow_entry,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Bulk create dash_flow_flow_entry
 *
 * @param[in] object_count Number of objects to create
 * @param[in] flow_entry List of object to create
 * @param[in] attr_count List of attr_count. Caller passes the number
 *    of attribute for each object to create.
 * @param[in] attr_list List of attributes for every object.
 * @param[in] mode Bulk operation error handling mode.
 * @param[out] object_statuses List of status for every object. Caller needs to
 * allocate the buffer
 *
 * @return #SAI_STATUS_SUCCESS on success when all objects are created or
 * #SAI_STATUS_FAILURE when any of the objects fails to create. When there is
 * failure, Caller is expected to go through the list of returned statuses to
 * find out which fails and which succeeds.
 */
typedef sai_status_t (*sai_bulk_create_flow_entry_fn)(
        _In_ uint32_t object_count,
        _In_ const sai_flow_entry_t *flow_entry,
        _In_ const uint32_t *attr_count,
        _In_ const sai_attribute_t **attr_list,
        _In_ sai_bulk_op_error_mode_t mode,
        _Out_ sai_status_t *object_statuses);

/**
 * @brief Bulk remove dash_flow_flow_entry
 *
 * @param[in] object_count Number of objects to remove
 * @param[in] flow_entry List of objects to remove
 * @param[in] mode Bulk operation error handling mode.
 * @param[out] object_statuses List of status for every object. Caller needs to
 * allocate the buffer
 *
 * @return #SAI_STATUS_SUCCESS on success when all objects are removed or
 * #SAI_STATUS_FAILURE when any of the objects fails to remove. When there is
 * failure, Caller is expected to go through the list of returned statuses to
 * find out which fails and which succeeds.
 */
typedef sai_status_t (*sai_bulk_remove_flow_entry_fn)(
        _In_ uint32_t object_count,
        _In_ const sai_flow_entry_t *flow_entry,
        _In_ sai_bulk_op_error_mode_t mode,
        _Out_ sai_status_t *object_statuses);

/**
 * @brief Bulk get dash_flow_flow_entry
 *
 * @param[in] object_count Max number of objects to get
 * @param[in] flow_entry List of object to get
 * @param[in] attr_count List of attr_count. Caller passes the number
 *    of attribute for each object to create.
 * @param[inout] attr_list List of attributes for every object.
 * @param[in] mode Bulk operation error handling mode.
 * @param[out] object_statuses Status for each object.
 *    If the allocated attribute count is not large enough,
 *    set the status to #SAI_STATUS_BUFFER_OVERFLOW.
 *
 * @return #SAI_STATUS_SUCCESS on success when all objects are created or
 * #SAI_STATUS_FAILURE when any of the objects fails to create. When there is
 * failure, Caller is expected to go through the list of returned statuses to
 * find out which fails and which succeeds.
 */
typedef sai_status_t (*sai_bulk_get_flow_entry_fn)(
        _In_ uint32_t object_count,
        _In_ const sai_flow_entry_t *flow_entry,
        _In_ const uint32_t *attr_count,
        _Inout_ sai_attribute_t **attr_list,
        _In_ sai_bulk_op_error_mode_t mode,
        _Out_ sai_status_t *object_statuses);

/**
 * @brief Create dash_flow_flow_entry_bulk_get_session_filter
 *
 * @param[out] flow_entry_bulk_get_session_filter_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_flow_entry_bulk_get_session_filter_fn)(
        _Out_ sai_object_id_t *flow_entry_bulk_get_session_filter_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove dash_flow_flow_entry_bulk_get_session_filter
 *
 * @param[in] flow_entry_bulk_get_session_filter_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_flow_entry_bulk_get_session_filter_fn)(
        _In_ sai_object_id_t flow_entry_bulk_get_session_filter_id);

/**
 * @brief Set attribute for dash_flow_flow_entry_bulk_get_session_filter
 *
 * @param[in] flow_entry_bulk_get_session_filter_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_flow_entry_bulk_get_session_filter_attribute_fn)(
        _In_ sai_object_id_t flow_entry_bulk_get_session_filter_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for dash_flow_flow_entry_bulk_get_session_filter
 *
 * @param[in] flow_entry_bulk_get_session_filter_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_flow_entry_bulk_get_session_filter_attribute_fn)(
        _In_ sai_object_id_t flow_entry_bulk_get_session_filter_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Create dash_flow_flow_entry_bulk_get_session
 *
 * @param[out] flow_entry_bulk_get_session_id Entry id
 * @param[in] switch_id Switch id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_create_flow_entry_bulk_get_session_fn)(
        _Out_ sai_object_id_t *flow_entry_bulk_get_session_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Remove dash_flow_flow_entry_bulk_get_session
 *
 * @param[in] flow_entry_bulk_get_session_id Entry id
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_remove_flow_entry_bulk_get_session_fn)(
        _In_ sai_object_id_t flow_entry_bulk_get_session_id);

/**
 * @brief Set attribute for dash_flow_flow_entry_bulk_get_session
 *
 * @param[in] flow_entry_bulk_get_session_id Entry id
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_set_flow_entry_bulk_get_session_attribute_fn)(
        _In_ sai_object_id_t flow_entry_bulk_get_session_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get attribute for dash_flow_flow_entry_bulk_get_session
 *
 * @param[in] flow_entry_bulk_get_session_id Entry id
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success Failure status code on error
 */
typedef sai_status_t (*sai_get_flow_entry_bulk_get_session_attribute_fn)(
        _In_ sai_object_id_t flow_entry_bulk_get_session_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

typedef struct _sai_dash_flow_api_t
{
    sai_create_flow_table_fn                                   create_flow_table;
    sai_remove_flow_table_fn                                   remove_flow_table;
    sai_set_flow_table_attribute_fn                            set_flow_table_attribute;
    sai_get_flow_table_attribute_fn                            get_flow_table_attribute;
    sai_bulk_object_create_fn                                  create_flow_tables;
    sai_bulk_object_remove_fn                                  remove_flow_tables;

    sai_create_flow_entry_fn                                   create_flow_entry;
    sai_remove_flow_entry_fn                                   remove_flow_entry;
    sai_set_flow_entry_attribute_fn                            set_flow_entry_attribute;
    sai_get_flow_entry_attribute_fn                            get_flow_entry_attribute;
    sai_bulk_create_flow_entry_fn                              create_flow_entries;
    sai_bulk_remove_flow_entry_fn                              remove_flow_entries;
    sai_bulk_get_flow_entry_fn                                 get_flow_entries_attribute;

    sai_create_flow_entry_bulk_get_session_filter_fn           create_flow_entry_bulk_get_session_filter;
    sai_remove_flow_entry_bulk_get_session_filter_fn           remove_flow_entry_bulk_get_session_filter;
    sai_set_flow_entry_bulk_get_session_filter_attribute_fn    set_flow_entry_bulk_get_session_filter_attribute;
    sai_get_flow_entry_bulk_get_session_filter_attribute_fn    get_flow_entry_bulk_get_session_filter_attribute;
    sai_bulk_object_create_fn                                  create_flow_entry_bulk_get_session_filters;
    sai_bulk_object_remove_fn                                  remove_flow_entry_bulk_get_session_filters;

    sai_create_flow_entry_bulk_get_session_fn                  create_flow_entry_bulk_get_session;
    sai_remove_flow_entry_bulk_get_session_fn                  remove_flow_entry_bulk_get_session;
    sai_set_flow_entry_bulk_get_session_attribute_fn           set_flow_entry_bulk_get_session_attribute;
    sai_get_flow_entry_bulk_get_session_attribute_fn           get_flow_entry_bulk_get_session_attribute;
    sai_bulk_object_create_fn                                  create_flow_entry_bulk_get_sessions;
    sai_bulk_object_remove_fn                                  remove_flow_entry_bulk_get_sessions;

} sai_dash_flow_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALDASHFLOW_H_ */
