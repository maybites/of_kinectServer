/*
 *  ofCamera.h
 *  openFrameworksLib
 *
 *  Created by Memo Akten on 10/01/2011.
 *  Copyright 2011 MSA Visuals Ltd. All rights reserved.
 *
 */

// TODO: 
// add off-axis projection options (eventually tile render support)
// fix ortho projection
// add toWorld, toScreen methods
// add get/set projection matrix
// support for left handed or right handed?

#pragma once


#include "ofRectangle.h"
#include "ofAppRunner.h"
#include "ofCamera.h"

// Use the public API of ofNode for all transformations
//class ofCamera : public ofNodeWithTarget {
class ofAdvCamera : public ofCamera {
public:
	ofAdvCamera();
		
	void setupPerspective(bool vFlip = true, float fov = 60, float nearDist = 0, float farDist = 0);

	void setFrustum(float left, float right, float top, float bottom, float nearDist, float farDist);
    void setupFrustum(float left, float right, float top, float bottom, float nearDist, float farDist);
    	    
	// set the matrices
	virtual void begin(ofRectangle viewport = ofGetCurrentViewport());
	virtual void end();
	
	// for hardcore peeps, access to the projection matrix
	ofMatrix4x4 getProjectionMatrix(ofRectangle viewport = ofGetCurrentViewport());	
	ofMatrix4x4 getModelViewMatrix();
	ofMatrix4x4 getModelViewProjectionMatrix(ofRectangle viewport = ofGetCurrentViewport());
	
	// convert between spaces
	ofVec3f worldToScreen(ofVec3f WorldXYZ, ofRectangle viewport = ofGetCurrentViewport()); 
	ofVec3f screenToWorld(ofVec3f ScreenXYZ, ofRectangle viewport = ofGetCurrentViewport());
	ofVec3f worldToCamera(ofVec3f WorldXYZ, ofRectangle viewport = ofGetCurrentViewport());
	ofVec3f cameraToWorld(ofVec3f CameraXYZ, ofRectangle viewport = ofGetCurrentViewport());

protected:
    bool useFrustum, isActive;
    float leftF, rightF, topF, bottomF;
	
};

