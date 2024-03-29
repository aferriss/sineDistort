#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        int w, h;
        ofShader baseShader, sinShader, contourShader;
        ofFbo fbo;
        ofImage img, marker, leafs, water;
    
        ofxDatGui* gui;
        ofxDatGuiSlider* ampSlider;
        ofxDatGuiSlider* ampYSlider;
        ofxDatGuiSlider* waveSlider;
        bool save;
        bool drawLines;
        bool hideGui;
    void drawOnImage();
};
