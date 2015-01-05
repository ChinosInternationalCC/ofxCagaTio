#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   
	ofSetFrameRate(30);
    ofBackground(50);
    
    // ----
    _mapping = new ofxMtlMapping2D();
    _mapping->init(ofGetWidth(), ofGetHeight(), "mapping/xml/shapes.xml", "mapping/controls/mapping.xml");

	cagaTio.setup();
				
}
			
//--------------------------------------------------------------
void ofApp::update(){
	
    _mapping->update();
	
	cagaTio.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255, 255, 255);
	
	// ----
    _mapping->bind();
    
	cagaTio.draw();
    
    _mapping->unbind();
    
    //-------- mapping of the towers/shapes
    _mapping->draw();
	
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	cagaTio.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
