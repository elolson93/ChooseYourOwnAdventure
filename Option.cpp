#include "Option.h"

using namespace std;

Option::Option(string text, int points, int next) {
	m_text = text;
	m_points = points;
	m_next_scene = next;
}

void Option::setNextScene(int scene_number) {
	m_next_scene = scene_number;
}

int Option::getNextScene() {
	return m_next_scene;
}

string Option::getText() {
	return m_text;
}

int Option::getPoints() {
	return m_points;
}