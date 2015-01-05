//
//  ofxCagaTio.h
//  myChinoCagaTio
//
//  Created by carles on 05/01/15.
//
//

#pragma once

#include "ofMain.h"

class ofxCagaTio {
public:
	ofxCagaTio();
	~ofxCagaTio();
	
	void setup();
	void update();
	void draw();
	void keyReleased(int key);
	
	////////////////
	void setupAllGolpeVideos();
	void setupAllNormalVideos();
	void jump2NextVideo();
	
	//normal
	ofDirectory dir;
	int numVideos = 0;
	vector<ofVideoPlayer> videos;
	//golpe
	ofDirectory dirGolpe;
	int numVideosGolpe = 0;
	vector<ofVideoPlayer> videosGolpe;
	
	////////////////
	//Control vars
	int idChinVid = 0;
	bool bGolpeActive = false;
	bool bGolpe = false;
	float golpePosVideo = 0.4;
	
	
};