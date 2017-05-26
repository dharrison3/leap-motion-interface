#include "ofApp.h"
#include <iostream>

ofVec3f center;
ofVec3f camPos(0, 0, 800);




GLfloat lightOnePosition[] = {0.0, 300.0, 0.0, 1.0};
GLfloat lightOneColor[] = {0.99, 0.99, 0.99, 1.0};

GLfloat lightTwoPosition[] = {-40.0, 40, 100.0, 0.0};
GLfloat lightTwoColor[] = {0.99, 0.99, 0.99, 1.0};
GLfloat odiffuse[] = {0, 0, 0, 1};
GLfloat oambient[] = {0, 0, 0, 1};
GLfloat ospecular[] = {1.0, 1.0, 1.0, 1};
GLfloat oshininess[] = {10};


//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255,255,255);
    
    ofSetVerticalSync(true);
    
    //some model / light stuff
    ofEnableDepthTest();
    glShadeModel (GL_SMOOTH);
    
    camera.setPosition(camPos);
    camera.lookAt(center);
    
    /* initialize lighting */
    
    
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, lightOneColor);
    
    
    glEnable (GL_LIGHT0);
    glEnable (GL_LIGHTING);
    glColorMaterial (GL_FRONT, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, odiffuse);
    glMaterialfv(GL_FRONT, GL_AMBIENT, oambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ospecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, oshininess);
    
    glEnable(GL_NORMALIZE);

    
    rotationY = 0.0;
    oldMouseX = 0.0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    camera.begin();
    //cam.begin();
    
    camera.setPosition(camPos);
    camera.rotate(rotationY, camera.getUpDir());
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, odiffuse);
    
    
    glLightfv (GL_LIGHT0, GL_POSITION, lightOnePosition);
    ofSetColor(67, 195, 255);
    for(int z = -200; z <= 200; z += 200){
        for(int y = - 200; y <= 200; y += 200){
            for(int x = -200; x <= 200; x += 200){
                ofDrawSphere(x, y, z, 80);
            }
        }
    }
    
    camera.end();
    //cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int step = 10;
    if(key == OF_KEY_UP) camPos.z = camPos.z - step;
    if(key == OF_KEY_DOWN) camPos.z = camPos.z + step;
    if(key == 'w') camPos.y = camPos.y + step;
    if(key == 's') camPos.y = camPos.y - step;
    if(key == OF_KEY_LEFT) camPos.x = camPos.x - step;
    if(key == OF_KEY_RIGHT) camPos.x = camPos.x + step;
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
   
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(x - oldMouseX > 0) rotationY += 1.0;
    if(x - oldMouseX < 0) rotationY -= 1.0;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    oldMouseX = x;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    rotationY = 0.0;
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
