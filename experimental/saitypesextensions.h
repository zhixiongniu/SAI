/**
 * Copyright (c) 2018 Microsoft Open Technologies, Inc.
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
 * @file    saitypesextensions.h
 *
 * @brief   This module defines type extensions of the Switch Abstraction Interface (SAI)
 */

#ifndef __SAITYPESEXTENSIONS_H_
#define __SAITYPESEXTENSIONS_H_

#include <saitypes.h>

/**
 * @brief SAI object type extensions
 *
 * @flags free
 */
typedef enum _sai_object_type_extensions_t
{
    SAI_OBJECT_TYPE_EXTENSIONS_RANGE_START = SAI_OBJECT_TYPE_MAX,

    SAI_OBJECT_TYPE_TABLE_BITMAP_CLASSIFICATION_ENTRY = SAI_OBJECT_TYPE_EXTENSIONS_RANGE_START,

    SAI_OBJECT_TYPE_TABLE_BITMAP_ROUTER_ENTRY,

    SAI_OBJECT_TYPE_TABLE_META_TUNNEL_ENTRY,

    SAI_OBJECT_TYPE_DASH_ACL_GROUP,

    SAI_OBJECT_TYPE_DASH_ACL_RULE,

    SAI_OBJECT_TYPE_DIRECTION_LOOKUP_ENTRY,

    SAI_OBJECT_TYPE_ENI_ETHER_ADDRESS_MAP_ENTRY,

    SAI_OBJECT_TYPE_ENI,

    SAI_OBJECT_TYPE_INBOUND_ROUTING_ENTRY,

    SAI_OBJECT_TYPE_METER_BUCKET,

    SAI_OBJECT_TYPE_METER_POLICY,

    SAI_OBJECT_TYPE_METER_RULE,

    SAI_OBJECT_TYPE_OUTBOUND_CA_TO_PA_ENTRY,

    SAI_OBJECT_TYPE_OUTBOUND_ROUTING_ENTRY,

    SAI_OBJECT_TYPE_VNET,

    SAI_OBJECT_TYPE_PA_VALIDATION_ENTRY,

    SAI_OBJECT_TYPE_VIP_ENTRY,

    SAI_OBJECT_TYPE_FLOW_TABLE,

    SAI_OBJECT_TYPE_FLOW_ENTRY,

    /* Add new experimental object types above this line */

    SAI_OBJECT_TYPE_EXTENSIONS_RANGE_END

} sai_object_type_extensions_t;

typedef enum _sai_dash_direction_t
{
    SAI_DASH_DIRECTION_INVALID,

    SAI_DASH_DIRECTION_OUTBOUND,

    SAI_DASH_DIRECTION_INBOUND,

} sai_dash_direction_t;

typedef enum _sai_dash_encapsulation_t
{
    SAI_DASH_ENCAPSULATION_INVALID,

    SAI_DASH_ENCAPSULATION_VXLAN,

    SAI_DASH_ENCAPSULATION_NVGRE,

} sai_dash_encapsulation_t;

typedef enum _sai_bulk_get_filter_op_t
{
    /** Operation to compare the value is equal */
    SAI_BULK_GET_FILTER_OP_EQUAL_TO,

    /** Operation to compare the value is greater than */
    SAI_BULK_GET_FILTER_OP_GREATER_THAN,

    /** Operation to compare the value is greater than or equal to */
    SAI_BULK_GET_FILTER_OP_GREATER_THAN_OR_EQUAL_TO,

    /** Operation to compare the value is less than */
    SAI_BULK_GET_FILTER_OP_LESS_THAN,

    /** Operation to compare the value is less than or equal to */
    SAI_BULK_GET_FILTER_OP_LESS_THAN_OR_EQUAL_TO,

} sai_bulk_get_filter_op_t;

typedef enum _sai_dash_tunnel_dscp_mode_t
{
    SAI_DASH_TUNNEL_DSCP_MODE_INVALID,

    SAI_DASH_TUNNEL_DSCP_MODE_PRESERVE_MODEL,

    SAI_DASH_TUNNEL_DSCP_MODE_PIPE_MODEL,

} sai_dash_tunnel_dscp_mode_t;

typedef enum _sai_dash_flow_action_t
{
    SAI_DASH_FLOW_ACTION_NONE,

} sai_dash_flow_action_t;

typedef enum _sai_dash_flow_enabled_key_t
{
    SAI_DASH_FLOW_ENABLED_KEY_NONE,

    SAI_DASH_FLOW_ENABLED_KEY_PROTOCOL,

    SAI_DASH_FLOW_ENABLED_KEY_SRC_IP,

    SAI_DASH_FLOW_ENABLED_KEY_DST_IP,

    SAI_DASH_FLOW_ENABLED_KEY_SRC_PORT,

    SAI_DASH_FLOW_ENABLED_KEY_DST_PORT,

} sai_dash_flow_enabled_key_t;

#endif /* __SAITYPESEXTENSIONS_H_ */

