//
//  ofxCagaTio.cpp
//  myChinoCagaTio
//
//  Created by carles on 05/01/15.
//
//

#include "ofxCagaTio.h"

ofxCagaTio::ofxCagaTio(){

}

ofxCagaTio::~ofxCagaTio() {

}

//--------------------------------------------------------------
void ofxCagaTio::setup(){
	
	setupAllNormalVideos();
	setupAllGolpeVideos();
	jump2NextVideo();
}

//--------------------------------------------------------------
void ofxCagaTio::update(){
	
	if(idChinVid > -1){
		
		//Control if play or stop
		if(bGolpe && bGolpeActive){
			videos[idChinVid].stop();
			videosGolpe[idChinVid].play();
			videosGolpe[idChinVid].setPosition(golpePosVideo
											   );
			bGolpe = false;
		}else if(bGolpe && !bGolpeActive){
			videos[idChinVid].stop();
			videosGolpe[idChinVid].play();
			bGolpeActive = true;
			bGolpe = false;
		}
		
		if(videosGolpe[idChinVid].getPosition() > 0.9){
			videosGolpe[idChinVid].setPosition(golpePosVideo);
			videosGolpe[idChinVid].stop();
			videos[idChinVid].play();
			bGolpeActive = false;
		}
		
		
		//Then Update
		if(bGolpeActive == true){
			videosGolpe[idChinVid].update();
		}
		else {
			videos[idChinVid].update();
		}
	}
	
	cout << "bGolpeActive = " << bGolpeActive << endl;
	if(idChinVid > -1)cout << "videos[idChinVid].getPosition() = " << videos[idChinVid].getPosition() << endl;
	if(idChinVid > -1)cout << "videosGolpe[idChinVid].getPosition() = " << videosGolpe[idChinVid].getPosition() << endl;
	
	
}

//--------------------------------------------------------------
void ofxCagaTio::draw(){
	
	if(idChinVid > -1){
		if(bGolpeActive == true){
			videosGolpe[idChinVid].draw(0, 0);
		}else{
			videos[idChinVid].draw(0, 0);
		}
	}
	
}


//--------------------------------------------------------------
void ofxCagaTio::jump2NextVideo(){
	//actual position
	if(idChinVid > -1){
		videos[idChinVid].stop();
	}
	//next position
	idChinVid++;
	if (idChinVid > numVideos-1) {
		idChinVid = 0;
		videos[idChinVid].play();
	}
}


//--------------------------------------------------------------
void ofxCagaTio::setupAllNormalVideos(){
	
	idChinVid = -1;
	
	dir.allowExt("mov");
	dir.listDir("videos/normal/");
	numVideos = dir.size();
	cout << "numVideos = " << numVideos << endl;
	dir.sort(); // in linux the file system doesn't return file lists ordered in alphabetical order
	
	for(int i=0; i< numVideos; i++ ){
		videos.assign(dir.size(), ofVideoPlayer());
	}
	
	for(int i=0; i< numVideos; i++ ){
		cout << "getPath(i)=" << dir.getPath(i) << endl;
		videos[i].loadMovie(dir.getPath(i));
		videos[i].play();
		cout << "loaded new chino " << endl;
	}
	
	
}



//--------------------------------------------------------------
void ofxCagaTio::setupAllGolpeVideos(){
	
	idChinVid = -1;
	
	dirGolpe.allowExt("mov");
	dirGolpe.listDir("videos/golpe/");
	numVideosGolpe = dirGolpe.size();
	cout << "numVideos Golpe= " << numVideos << endl;
	dirGolpe.sort(); // in linux the file system doesn't return file lists ordered in alphabetical order
	
	for(int i=0; i< numVideosGolpe; i++ ){
		videosGolpe.assign(dirGolpe.size(), ofVideoPlayer());
	}
	
	for(int i=0; i< numVideosGolpe; i++ ){
		cout << "Golpe getPath(i)=" << dirGolpe.getPath(i) << endl;
		videosGolpe[i].loadMovie(dirGolpe.getPath(i));
		videosGolpe[i].stop();
		cout << "loaded new chino Golpe" << endl;
	}
	
}

//--------------------------------------------------------------
void ofxCagaTio::keyReleased(int key){
	if( key == 'k' ){
		bGolpe = true;
	}
	else if( key == 'n' ){
		
		jump2NextVideo();
	}
}
