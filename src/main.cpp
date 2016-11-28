#include <maya/MFnPlugin.h>

#include "include/helloMayaNode.h"


MStatus initializePlugin(MObject obj)
{
    MFnPlugin plugin(obj, HelloMayaNode::s_author, HelloMayaNode::s_pluginVersion, HelloMayaNode::s_mayaVersion);
    MStatus status = plugin.registerNode(HelloMayaNode::s_commandName, HelloMayaNode::id, HelloMayaNode::creator, HelloMayaNode::initialze);

    CHECK_MSTATUS_AND_RETURN_IT(status);
    return status;
}


MStatus uninitializePlugin(MObject obj)
{
    MFnPlugin plugin(obj);
    MStatus status = plugin.deregisterNode(HelloMayaNode::id);

    CHECK_MSTATUS_AND_RETURN_IT(status);
    return status;
}
