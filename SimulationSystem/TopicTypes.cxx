

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from TopicTypes.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif        

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "TopicTypes.h"

#include <new>

/* ========================================================================= */
const char *SoftwareStateTYPENAME = "SoftwareState";

DDS_TypeCode* SoftwareState_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode SoftwareState_g_tc_taskID_string = DDS_INITIALIZE_STRING_TYPECODE((32));
    static DDS_TypeCode SoftwareState_g_tc_cabinID_string = DDS_INITIALIZE_STRING_TYPECODE((32));
    static DDS_TypeCode SoftwareState_g_tc_hostID_string = DDS_INITIALIZE_STRING_TYPECODE((32));
    static DDS_TypeCode SoftwareState_g_tc_softwareID_string = DDS_INITIALIZE_STRING_TYPECODE((32));
    static DDS_TypeCode_Member SoftwareState_g_tc_members[30]=
    {

        {
            (char *)"taskID",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"priority",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"missileX",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"missileY",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"missileSpeed",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"missileD",/* Member name */
            {
                5,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"missileTag",/* Member name */
            {
                6,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"shipX",/* Member name */
            {
                7,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"shipY",/* Member name */
            {
                8,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"shipSpeed",/* Member name */
            {
                9,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"shipD",/* Member name */
            {
                10,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"shipLength",/* Member name */
            {
                11,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"cabinID",/* Member name */
            {
                12,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"cabinT",/* Member name */
            {
                13,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"cabinH",/* Member name */
            {
                14,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostID",/* Member name */
            {
                15,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostState",/* Member name */
            {
                16,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostComputeOR",/* Member name */
            {
                17,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostMemoryOR",/* Member name */
            {
                18,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostBandwidthOR",/* Member name */
            {
                19,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostStorageOR",/* Member name */
            {
                20,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostMainboardT",/* Member name */
            {
                21,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostCpuT",/* Member name */
            {
                22,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"hostHarddiskT",/* Member name */
            {
                23,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"softwareID",/* Member name */
            {
                24,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"softwareHeartBeat",/* Member name */
            {
                25,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"softwareComputeOR",/* Member name */
            {
                26,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"softwareMemoryOR",/* Member name */
            {
                27,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"softwareBandwidthOR",/* Member name */
            {
                28,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"softwareStroageOR",/* Member name */
            {
                29,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode SoftwareState_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"SoftwareState", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            30, /* Number of members */
            SoftwareState_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for SoftwareState*/

    if (is_initialized) {
        return &SoftwareState_g_tc;
    }

    SoftwareState_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&SoftwareState_g_tc_taskID_string;

    SoftwareState_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

    SoftwareState_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    SoftwareState_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[9]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[10]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[11]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[12]._representation._typeCode = (RTICdrTypeCode *)&SoftwareState_g_tc_cabinID_string;

    SoftwareState_g_tc_members[13]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[14]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[15]._representation._typeCode = (RTICdrTypeCode *)&SoftwareState_g_tc_hostID_string;

    SoftwareState_g_tc_members[16]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    SoftwareState_g_tc_members[17]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[18]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[19]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[20]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[21]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[22]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[23]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[24]._representation._typeCode = (RTICdrTypeCode *)&SoftwareState_g_tc_softwareID_string;

    SoftwareState_g_tc_members[25]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_boolean;

    SoftwareState_g_tc_members[26]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[27]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[28]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    SoftwareState_g_tc_members[29]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    is_initialized = RTI_TRUE;

    return &SoftwareState_g_tc;
}

RTIBool SoftwareState_initialize(
    SoftwareState* sample) {
    return SoftwareState_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool SoftwareState_initialize_ex(
    SoftwareState* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return SoftwareState_initialize_w_params(
        sample,&allocParams);

}

RTIBool SoftwareState_initialize_w_params(
    SoftwareState* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory){
        sample->taskID= DDS_String_alloc ((32));
        if (sample->taskID == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->taskID!= NULL) { 
            sample->taskID[0] = '\0';
        }
    }

    if (!RTICdrType_initShort(&sample->priority)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->missileX)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->missileY)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->missileSpeed)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->missileD)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initBoolean(&sample->missileTag)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->shipX)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->shipY)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->shipSpeed)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->shipD)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->shipLength)) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory){
        sample->cabinID= DDS_String_alloc ((32));
        if (sample->cabinID == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->cabinID!= NULL) { 
            sample->cabinID[0] = '\0';
        }
    }

    if (!RTICdrType_initFloat(&sample->cabinT)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->cabinH)) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory){
        sample->hostID= DDS_String_alloc ((32));
        if (sample->hostID == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->hostID!= NULL) { 
            sample->hostID[0] = '\0';
        }
    }

    if (!RTICdrType_initBoolean(&sample->hostState)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->hostComputeOR)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->hostMemoryOR)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->hostBandwidthOR)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->hostStorageOR)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->hostMainboardT)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->hostCpuT)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->hostHarddiskT)) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory){
        sample->softwareID= DDS_String_alloc ((32));
        if (sample->softwareID == NULL) {
            return RTI_FALSE;
        }

    } else {
        if (sample->softwareID!= NULL) { 
            sample->softwareID[0] = '\0';
        }
    }

    if (!RTICdrType_initBoolean(&sample->softwareHeartBeat)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->softwareComputeOR)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->softwareMemoryOR)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->softwareBandwidthOR)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->softwareStroageOR)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void SoftwareState_finalize(
    SoftwareState* sample)
{

    SoftwareState_finalize_ex(sample,RTI_TRUE);
}

void SoftwareState_finalize_ex(
    SoftwareState* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    SoftwareState_finalize_w_params(
        sample,&deallocParams);
}

void SoftwareState_finalize_w_params(
    SoftwareState* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->taskID != NULL) {
        DDS_String_free(sample->taskID);
        sample->taskID=NULL;

    }

    if (sample->cabinID != NULL) {
        DDS_String_free(sample->cabinID);
        sample->cabinID=NULL;

    }

    if (sample->hostID != NULL) {
        DDS_String_free(sample->hostID);
        sample->hostID=NULL;

    }

    if (sample->softwareID != NULL) {
        DDS_String_free(sample->softwareID);
        sample->softwareID=NULL;

    }

}

void SoftwareState_finalize_optional_members(
    SoftwareState* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool SoftwareState_copy(
    SoftwareState* dst,
    const SoftwareState* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyStringEx (
            &dst->taskID, src->taskID, 
            (32) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyShort (
            &dst->priority, &src->priority)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->missileX, &src->missileX)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->missileY, &src->missileY)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->missileSpeed, &src->missileSpeed)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->missileD, &src->missileD)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyBoolean (
            &dst->missileTag, &src->missileTag)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->shipX, &src->shipX)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->shipY, &src->shipY)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->shipSpeed, &src->shipSpeed)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->shipD, &src->shipD)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->shipLength, &src->shipLength)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->cabinID, src->cabinID, 
            (32) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->cabinT, &src->cabinT)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->cabinH, &src->cabinH)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->hostID, src->hostID, 
            (32) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyBoolean (
            &dst->hostState, &src->hostState)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->hostComputeOR, &src->hostComputeOR)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->hostMemoryOR, &src->hostMemoryOR)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->hostBandwidthOR, &src->hostBandwidthOR)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->hostStorageOR, &src->hostStorageOR)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->hostMainboardT, &src->hostMainboardT)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->hostCpuT, &src->hostCpuT)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->hostHarddiskT, &src->hostHarddiskT)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyStringEx (
            &dst->softwareID, src->softwareID, 
            (32) + 1, RTI_FALSE)){
            return RTI_FALSE;
        }
        if (!RTICdrType_copyBoolean (
            &dst->softwareHeartBeat, &src->softwareHeartBeat)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->softwareComputeOR, &src->softwareComputeOR)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->softwareMemoryOR, &src->softwareMemoryOR)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->softwareBandwidthOR, &src->softwareBandwidthOR)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyFloat (
            &dst->softwareStroageOR, &src->softwareStroageOR)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;

    } catch (std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'SoftwareState' sequence class.
*/
#define T SoftwareState
#define TSeq SoftwareStateSeq

#define T_initialize_w_params SoftwareState_initialize_w_params

#define T_finalize_w_params   SoftwareState_finalize_w_params
#define T_copy       SoftwareState_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

