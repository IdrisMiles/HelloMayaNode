#ifndef _HELLOMAYANODE__H_
#define _HELLOMAYANODE__H_

// Maya include
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MStatus.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MGlobal.h>
#include <maya/MPxNode.h>


class HelloMayaNode : public MPxNode
{
public:
    HelloMayaNode();
    virtual MStatus compute (const MPlug& plug, MDataBlock &data);
    static void* creator();
    static MStatus initialze();

    static MTypeId id;
    static MObject a_input;
    static MObject a_output;
    
    static const char* s_commandName;
    static const char* s_author;
    static const char* s_pluginVersion;
    static const char* s_mayaVersion;
};

#endif //_HELLOMAYANODE__H_
