

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from TopicTypes.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef TopicTypes_115571206_h
#define TopicTypes_115571206_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *SoftwareStateTYPENAME;

}

struct SoftwareStateSeq;
#ifndef NDDS_STANDALONE_TYPE
class SoftwareStateTypeSupport;
class SoftwareStateDataWriter;
class SoftwareStateDataReader;
#endif

class SoftwareState 
{
  public:
    typedef struct SoftwareStateSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef SoftwareStateTypeSupport TypeSupport;
    typedef SoftwareStateDataWriter DataWriter;
    typedef SoftwareStateDataReader DataReader;
    #endif

    DDS_Char *   taskID ;
    DDS_Short   priority ;
    DDS_Float   missileX ;
    DDS_Float   missileY ;
    DDS_Float   missileSpeed ;
    DDS_Float   missileD ;
    DDS_Boolean   missileTag ;
    DDS_Float   shipX ;
    DDS_Float   shipY ;
    DDS_Float   shipSpeed ;
    DDS_Float   shipD ;
    DDS_Float   shipLength ;
    DDS_Char *   cabinID ;
    DDS_Float   cabinT ;
    DDS_Float   cabinH ;
    DDS_Char *   hostID ;
    DDS_Boolean   hostState ;
    DDS_Float   hostComputeOR ;
    DDS_Float   hostMemoryOR ;
    DDS_Float   hostBandwidthOR ;
    DDS_Float   hostStorageOR ;
    DDS_Float   hostMainboardT ;
    DDS_Float   hostCpuT ;
    DDS_Float   hostHarddiskT ;
    DDS_Char *   softwareID ;
    DDS_Boolean   softwareHeartBeat ;
    DDS_Float   softwareComputeOR ;
    DDS_Float   softwareMemoryOR ;
    DDS_Float   softwareBandwidthOR ;
    DDS_Float   softwareStroageOR ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* SoftwareState_get_typecode(void); /* Type code */

DDS_SEQUENCE(SoftwareStateSeq, SoftwareState);

NDDSUSERDllExport
RTIBool SoftwareState_initialize(
    SoftwareState* self);

NDDSUSERDllExport
RTIBool SoftwareState_initialize_ex(
    SoftwareState* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool SoftwareState_initialize_w_params(
    SoftwareState* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void SoftwareState_finalize(
    SoftwareState* self);

NDDSUSERDllExport
void SoftwareState_finalize_ex(
    SoftwareState* self,RTIBool deletePointers);

NDDSUSERDllExport
void SoftwareState_finalize_w_params(
    SoftwareState* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void SoftwareState_finalize_optional_members(
    SoftwareState* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool SoftwareState_copy(
    SoftwareState* dst,
    const SoftwareState* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* TopicTypes */

