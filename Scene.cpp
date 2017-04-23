#include "Scene.h"

using namespace std;

Scene::Scene(string text, vector<Option*> options) {
	m_text = text;
	m_options = options;
}

Scene::~Scene() {}

string Scene::getText() {
	return m_text;
}

vector<Option*> Scene::getOptions() {
	return m_options;
}