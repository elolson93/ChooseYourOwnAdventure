#include "User.h"
#include <iostream>

using namespace std;

User::User(string name): m_user_name(name), m_current_score(0), m_current_scene(1) {}

User::User(string name, int scene, int score): m_user_name(name), m_current_score(score), m_current_scene(scene) {}

User::~User() {}

int User::increaseScoreBy(int score) {
	m_current_score += score;
	return m_current_score;
}

int User::decreaseScoreBy(int score) {
	m_current_score -= score;
	return m_current_score;
}

int User::getCurrentScore() {return m_current_score;}

void User::setCurrentScore(int score) {m_current_score = score;}

int User::getCurrentScene() {return m_current_scene;}

void User::setCurrentScene(int scene) {m_current_scene = scene;}

string User::getUserName() {return m_user_name}

void User::viewPlayer() {
	cout << "Player: " << m_user_name << ",\tScene: " << m_current_scene <<",\tScore: " << m_current_score << endl;
}