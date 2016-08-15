//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2015 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#ifndef __CHANNELCONTROLLER_H_
#define __CHANNELCONTROLLER_H_

#include <osg/Node>
#include <osgEarth/MapNode>
#include <osgEarthAnnotation/FeatureNode>
#include <osgEarthSymbology/Style>
#include <osgEarthSymbology/Geometry>
#include <osgEarthFeatures/Feature>

#include <omnetpp.h>
#include "OsgEarthScene.h"
#include "GenericNode.h"

using namespace omnetpp;

/**
 * This module is responsible for tracking the distance of mobile nodes
 * and visualizing the connectivity graph using OSG nodes.
 */
class ChannelController : public cSimpleModule
{
  protected:
    static ChannelController *instance;
    std::vector<IGenericNode *> nodeList;
    double playgroundLat;
    double playgroundLon;
    bool showConnections;
    std::string connectionColor;
    // the node containing the osgEarth data
    osg::observer_ptr<osgEarth::MapNode> mapNode = nullptr;
    // a node containing a geometry showing all connections in the connection graph
    osg::ref_ptr<osgEarth::Annotation::FeatureNode> connectionGraphNode = nullptr;
    osgEarth::Symbology::Style connectionStyle;

    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return 2; }
    virtual void handleMessage(cMessage *msg) override;
    int findGenericNode(IGenericNode *p);

  public:
    ChannelController();
    virtual ~ChannelController();
    static ChannelController *getInstance();
    virtual void addGenericNode(IGenericNode *p);
    virtual void removeGenericNode(IGenericNode *p);
    virtual void refreshDisplay() const override;
};

#endif
