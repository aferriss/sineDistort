#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    w = 834;
    h = 969;
    
    ofSetWindowShape(w, h);
    
    
    baseShader.load("shaders/base");
    sinShader.load("shaders/base.vert","shaders/sin.frag");
    contourShader.load("shaders/base.vert", "shaders/contour.frag");
    fbo.allocate(w, h, GL_RGBA);
    
    img.load("images/beach.jpg");
    marker.load("images/marker.png");
    leafs.load("images/island.jpg");
    water.load("images/water.jpg");
    
    img.resize(w, h);
    
    fbo.begin();
        ofClear(0,0,0);
    fbo.end();
    
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_LEFT);
    
    ampSlider = gui->addSlider("Amp", 0.001, 0.2,0.05);
    ampSlider->setPrecision(4);
    waveSlider = gui->addSlider("Wave", 0.001, 500,5);
    
    save = false;
    drawLines = false;
    hideGui = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(save){
        ofPixels savepix;
        fbo.readToPixels(savepix);
        ofSaveImage(savepix, "saved/"+ofGetTimestampString()+".png");
        save = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
        sinShader.begin();
            sinShader.setUniformTexture("u_image", img.getTexture(), 0);
            sinShader.setUniformTexture("img2", leafs.getTexture(), 1);
            sinShader.setUniform1f("time", ofGetFrameNum()*0.05 );
            sinShader.setUniform1f("amp", ampSlider->getValue());
            sinShader.setUniform1f("wavelength", waveSlider->getValue());
                img.draw(0,0);
        sinShader.end();
    
//    contourShader.begin();
//        contourShader.setUniform1f("time", ofGetFrameNum()*0.025);
//        contourShader.setUniform2f("res", w, h);
//        contourShader.setUniformTexture("water", water.getTexture(), 0);
//        contourShader.setUniformTexture("leafs", leafs.getTexture(), 1);
//    
//        water.draw(0,0);
//    contourShader.end();
    
    if(drawLines){
        drawOnImage();
    }
    
    fbo.end();
    
    fbo.draw(0,0);
}
//--------------------------------------------------------------
void ofApp::drawOnImage(){
       img.draw(0,0, w, h);
        ofPixels imgPix = img.getPixels();
        cout<<ofToString(imgPix.getHeight())<<endl;
        for(int y= 0; y<fbo.getHeight(); y++){
            for(int x = 0; x<fbo.getWidth(); x++){
                ofImageType imgType = img.getImageType();
                int numChannels = 3;
                if(imgType == OF_IMAGE_COLOR_ALPHA){
                    numChannels = 4;
                }
                int loc = (y * w + x) * numChannels;
                int r = imgPix[loc];
                int g = imgPix[loc+1];
                int b = imgPix[loc+2];
//                int avg = (r+g+b)/3;
                ofColor col = ofColor(r, g, b);
                
                if( col.getBrightness() > 220){
                    
                    float angle = col.getHueAngle();
                    ofSetColor(r,g,b,255);//col.getBrightness()*0.99);
                    float randX = ofRandom(-3,3);
                    float randY = ofRandom(5, angle/8);
                    float randRad = ofRandom(1,5);
//                    marker.draw(x-marker.getWidth()/2, y);
                    ofDrawLine(x, y, x + randX, y - randY);
                    ofDrawEllipse(x + randX, y - randY, randRad, randRad);
                }
            }
        }
        ofSetColor(255);
        cout<<"Done Drawing"<<endl;
        drawLines = false;

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        save = !save;
    }
    
    if(key == 'h'){
        hideGui = !hideGui;
        gui->setVisible(hideGui);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
