#include "include/helloMayaNode.h"

const char* HelloMayaNode::s_commandName = "helloMayaNode";
const char* HelloMayaNode::s_author = "Idris Miles";
const char* HelloMayaNode::s_pluginVersion = "1.0";
const char* HelloMayaNode::s_mayaVersion = "Any";

MTypeId HelloMayaNode::id(0x00000001);
MObject HelloMayaNode::a_input;
MObject HelloMayaNode::a_output;


HelloMayaNode::HelloMayaNode()
{
}


MStatus HelloMayaNode::initialze()
{
    MFnNumericAttribute nAttr;

    // cretae output attribute
    a_output = nAttr.create("output", "out", MFnNumericData::kFloat);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(a_output); 

    // cretae input attribute
    a_input = nAttr.create("input", "in", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    addAttribute(a_input);
    attributeAffects(a_input, a_output);

    return MS::kSuccess; 

}

MStatus HelloMayaNode::compute(const MPlug& plug, MDataBlock &data)
{
    if(plug != a_output)
    {
        return MS::kUnknownParameter;
    }

    // Get input
    float inputValue = data.inputValue(a_input).asFloat();

    // Do something with input
    inputValue *= 2;

    // Set the output
    MDataHandle hOutput = data.outputValue(a_output);
    hOutput.setFloat(inputValue);
    data.setClean(plug);

    MGlobal::displayInfo("Hello Maya, this is a node!");
    return MS::kSuccess;
}

void* HelloMayaNode::creator()
{
    return new HelloMayaNode();
}
