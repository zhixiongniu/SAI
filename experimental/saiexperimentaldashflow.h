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

#include <saitypes.h>

/**
 * @defgroup SAIEXPERIMENTALDASH_FLOW SAI - Extension specific API definitions
 *
 * @{
 */

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
     * @brief Exact matched key dst_ip
     */
    sai_ip_address_t dst_ip;

    /**
     * @brief Exact matched key src_ip
     */
    sai_ip_address_t src_ip;

    /**
     * @brief Exact matched key protocol
     */
    sai_uint8_t protocol;

    /**
     * @brief Exact matched key src_port
     */
    sai_uint16_t src_port;

    /**
     * @brief Exact matched key dst_port
     */
    sai_uint16_t dst_port;

    /**
     * @brief Exact matched key direction
     */
    sai_uint16_t direction;

    /**
     * @brief Exact matched key eni_addr
     */
    sai_mac_t eni_addr;

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
     * @brief Action flow_entry_action parameter FLOW_TABLE_ID
     *
     * @type sai_object_id_t
     * @flags CREATE_AND_SET
     * @objects SAI_OBJECT_TYPE_FLOW_TABLE
     * @allownull true
     * @default SAI_NULL_OBJECT_ID
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_TABLE_ID = SAI_FLOW_ENTRY_ATTR_START,

    /**
     * @brief Action flow_entry_action parameter FLOW_VERSION
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_VERSION,

    /**
     * @brief Action flow_entry_action parameter FLOW_PROTOBUF
     *
     * @type sai_u8_list_t
     * @flags CREATE_AND_SET
     * @default empty
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_PROTOBUF,

    /**
     * @brief Action flow_entry_action parameter FLOW_BIDIRECTIONAL
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_BIDIRECTIONAL,

    /**
     * @brief Action flow_entry_action parameter FLOW_DIRECTION
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_DIRECTION,

    /**
     * @brief Action flow_entry_action parameter FLOW_REVERSE_KEY
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_REVERSE_KEY,

    /**
     * @brief Action flow_entry_action parameter FLOW_VENDOR_METADATA
     *
     * @type sai_u8_list_t
     * @flags CREATE_AND_SET
     * @default empty
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_VENDOR_METADATA,

    /**
     * @brief Action flow_entry_action parameter FLOW_TARGET_SERVER
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_TARGET_SERVER,

    /**
     * @brief Action flow_entry_action parameter FLOW_ENTRY_FILTER
     *
     * @type sai_uint64_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_FLOW_ENTRY_FILTER,

    /**
     * @brief Action flow_entry_action parameter VNI
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_VNI,

    /**
     * @brief Action flow_entry_action parameter DEST_VNET_VNI
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_DEST_VNET_VNI,

    /**
     * @brief Action flow_entry_action parameter UNDERLAY_SIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_UNDERLAY_SIP,

    /**
     * @brief Action flow_entry_action parameter UNDERLAY_DIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_UNDERLAY_DIP,

    /**
     * @brief Action flow_entry_action parameter UNDERLAY_SMAC
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_FLOW_ENTRY_ATTR_UNDERLAY_SMAC,

    /**
     * @brief Action flow_entry_action parameter UNDERLAY_DMAC
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_FLOW_ENTRY_ATTR_UNDERLAY_DMAC,

    /**
     * @brief Action flow_entry_action parameter DASH_ENCAPSULATION
     *
     * @type sai_dash_encapsulation_t
     * @flags CREATE_AND_SET
     * @default SAI_DASH_ENCAPSULATION_INVALID
     */
    SAI_FLOW_ENTRY_ATTR_DASH_ENCAPSULATION,

    /**
     * @brief Action flow_entry_action parameter ORIGINAL_OVERLAY_SIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_ORIGINAL_OVERLAY_SIP,

    /**
     * @brief Action flow_entry_action parameter ORIGINAL_OVERLAY_DIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_ORIGINAL_OVERLAY_DIP,

    /**
     * @brief Action flow_entry_action parameter DEST_MAC
     *
     * @type sai_mac_t
     * @flags CREATE_AND_SET
     * @default 0:0:0:0:0:0
     */
    SAI_FLOW_ENTRY_ATTR_DEST_MAC,

    /**
     * @brief Action flow_entry_action parameter SIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_SIP,

    /**
     * @brief Action flow_entry_action parameter DIP
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_DIP,

    /**
     * @brief Action flow_entry_action parameter SIP_MASK
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_SIP_MASK,

    /**
     * @brief Action flow_entry_action parameter DIP_MASK
     *
     * @type sai_ip_address_t
     * @flags CREATE_AND_SET
     * @default 0.0.0.0
     */
    SAI_FLOW_ENTRY_ATTR_DIP_MASK,

    /**
     * @brief Action flow_entry_action parameter METER_CLASS
     *
     * @type sai_uint16_t
     * @flags CREATE_AND_SET
     * @isvlan false
     * @default 0
     */
    SAI_FLOW_ENTRY_ATTR_METER_CLASS,

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
 * @brief Bulk Get Op filter keywords for flow_entry in get_flow_entries_attribute call
 */
typedef enum _sai_flow_entry_bulk_get_filter_t
{
    /** Bulk get filter key word for sai_ip_address_t dst_ip */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_DST_IP,

    /** Bulk get filter key word for sai_ip_address_t src_ip */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_SRC_IP,

    /** Bulk get filter key word for sai_uint8_t protocol */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_PROTOCOL,

    /** Bulk get filter key word for sai_uint16_t src_port */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_SRC_PORT,

    /** Bulk get filter key word for sai_uint16_t dst_port */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_DST_PORT,

    /** Bulk get filter key word for sai_uint16_t direction */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_DIRECTION,

    /** Bulk get filter key word for sai_mac_t eni_addr */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_ENI_ADDR,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_TABLE_ID */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_TABLE_ID,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_VERSION */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_VERSION,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_PROTOBUF */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_PROTOBUF,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_BIDIRECTIONAL */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_BIDIRECTIONAL,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_DIRECTION */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_DIRECTION,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_REVERSE_KEY */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_REVERSE_KEY,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_VENDOR_METADATA */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_VENDOR_METADATA,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_TARGET_SERVER */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_TARGET_SERVER,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_FLOW_ENTRY_FILTER */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_FLOW_ENTRY_FILTER,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_VNI */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_VNI,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_DEST_VNET_VNI */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_DEST_VNET_VNI,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_UNDERLAY_SIP */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_UNDERLAY_SIP,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_UNDERLAY_DIP */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_UNDERLAY_DIP,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_UNDERLAY_SMAC */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_UNDERLAY_SMAC,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_UNDERLAY_DMAC */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_UNDERLAY_DMAC,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_DASH_ENCAPSULATION */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_DASH_ENCAPSULATION,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_ORIGINAL_OVERLAY_SIP */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_ORIGINAL_OVERLAY_SIP,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_ORIGINAL_OVERLAY_DIP */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_ORIGINAL_OVERLAY_DIP,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_DEST_MAC */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_DEST_MAC,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_SIP */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_SIP,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_DIP */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_DIP,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_SIP_MASK */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_SIP_MASK,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_DIP_MASK */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_DIP_MASK,

    /** Bulk get filter key word for SAI_FLOW_ENTRY_ATTR_METER_CLASS */
    SAI_FLOW_ENTRY_BULK_GET_FILTER_T_METER_CLASS,

} sai_flow_entry_bulk_get_filter_t;

/**
 * @brief Bulk Get Op for flow_entry in get_flow_entries_attribute call
 */
typedef enum _sai_flow_entry_bulk_get_op_t
{
    /** Indicate the last operation of the bulk get */
    SAI_FLOW_ENTRY_BULK_GET_OP_LAST_ITEM,

    /** Operation to compare the value is equal */
    SAI_FLOW_ENTRY_BULK_GET_OP_EQUAL_TO,

    /** Operation to compare the value is greater than */
    SAI_FLOW_ENTRY_BULK_GET_OP_GREATER_THAN,

    /** Operation to compare the value is greater than or equal to */
    SAI_FLOW_ENTRY_BULK_GET_OP_GREATER_THAN_OR_EQUAL_TO,

    /** Operation to compare the value is less than */
    SAI_FLOW_ENTRY_BULK_GET_OP_LESS_THAN,

    /** Operation to compare the value is less than or equal to */
    SAI_FLOW_ENTRY_BULK_GET_OP_LESS_THAN_OR_EQUAL_TO,

} sai_flow_entry_bulk_get_op_t;

typedef struct _sai_flow_entry_target_server_data_t
{
    sai_ip_address_t server_ip;
    sai_uint16_t server_port;
} sai_flow_entry_target_server_data_t;

typedef struct _sai_flow_entry_filter_data_t
{
    sai_flow_entry_bulk_get_filter_t filter;
    sai_flow_entry_bulk_get_op_t op;
    sai_uint64_t value;
} sai_flow_entry_filter_data_t;

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
     * @brief Action flow_table_action parameter TABLE_SIZE
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_TABLE_ATTR_TABLE_SIZE = SAI_FLOW_TABLE_ATTR_START,

    /**
     * @brief Action flow_table_action parameter TABLE_EXPIRE_TIME
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_TABLE_ATTR_TABLE_EXPIRE_TIME,

    /**
     * @brief Action flow_table_action parameter TABLE_VERSION
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_TABLE_ATTR_TABLE_VERSION,

    /**
     * @brief Action flow_table_action parameter TABLE_KEY_FLAG
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     * @default 0
     */
    SAI_FLOW_TABLE_ATTR_TABLE_KEY_FLAG,

    /**
     * @brief Action flow_table_action parameter TABLE_TCP_TRACK_STATE
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_FLOW_TABLE_ATTR_TABLE_TCP_TRACK_STATE,

    /**
     * @brief Action flow_table_action parameter TABLE_TCP_RESET_ILLEGAL
     *
     * @type bool
     * @flags CREATE_AND_SET
     * @default false
     */
    SAI_FLOW_TABLE_ATTR_TABLE_TCP_RESET_ILLEGAL,

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

typedef struct _sai_dash_flow_api_t
{
    sai_create_flow_entry_fn           create_flow_entry;
    sai_remove_flow_entry_fn           remove_flow_entry;
    sai_set_flow_entry_attribute_fn    set_flow_entry_attribute;
    sai_get_flow_entry_attribute_fn    get_flow_entry_attribute;
    sai_bulk_create_flow_entry_fn      create_flow_entries;
    sai_bulk_remove_flow_entry_fn      remove_flow_entries;
    sai_bulk_get_flow_entry_fn         get_flow_entries_attribute;

    sai_create_flow_table_fn           create_flow_table;
    sai_remove_flow_table_fn           remove_flow_table;
    sai_set_flow_table_attribute_fn    set_flow_table_attribute;
    sai_get_flow_table_attribute_fn    get_flow_table_attribute;
    sai_bulk_object_create_fn          create_flow_tables;
    sai_bulk_object_remove_fn          remove_flow_tables;

} sai_dash_flow_api_t;

/**
 * @}
 */
#endif /** __SAIEXPERIMENTALDASHFLOW_H_ */
