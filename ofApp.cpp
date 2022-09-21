#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofSetColor(0);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int i = 0; i < 39; i++) {

		auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));
		int span = ofRandom(2, 4);
		int len = ofRandom(1, span);

		for (int k = 0; k < 18; k += span) {

			auto location = glm::vec2(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k) * 0.008), 0, 1, -350, 350),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k) * 0.008), 0, 1, -350, 350));

			auto next = glm::vec2(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k + len) * 0.008), 0, 1, -350, 350),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k + len) * 0.008), 0, 1, -350, 350));

			ofDrawLine(location, next);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}