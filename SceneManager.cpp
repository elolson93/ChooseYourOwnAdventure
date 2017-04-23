#include "SceneManager.h"
#include <iostream>

using namespace std;

SceneManager::SceneManager(User* user) {
	m_user = user;
	m_current_scene = user->getCurrentScene();
	this->buildScript();
}

SceneManager::~SceneManager() {}

int SceneManager::displayScene(int scene) {

	cout << "######################################" << endl << endl;

	string text = m_vector.at(scene-1)->getText();
	cout << text << endl << endl;

	int option = 0;
	cout << "Options:" << endl;
	vector<Option*> options = m_vector.at(scene-1)->getOptions();
	while (option == 0) {
		int i;
		for(i = 0; i < options.size(); i++) {
			string temp_text = options.at(i)->getText();
			cout << (i+1) << ".) " << temp_text << endl;
		} 
		cin >> option;
		if (option > options.size()) {
			cout << "Input a valid option!" << endl << endl;
			option = 0;
		} else {
			if (options.at(option-1)->getNextScene() != QUIT_VALUE) {
				m_user->increaseScoreBy(options.at(option-1)->getPoints());
				m_user->setCurrentScene(scene);
				m_current_scene = options.at(option-1)->getNextScene();
				cout << "######################################" << endl << endl;	
				return CONTINUE_VALUE;
			} else {
				cout << "######################################" << endl << endl;
				m_user->setCurrentScene(scene);
				return QUIT_VALUE;
			}
		}
	}
	return 0;
}

void SceneManager::begin() {
	int status = CONTINUE_VALUE;
	while (status != QUIT_VALUE) {
		status = displayScene(m_current_scene);
	}
}

void SceneManager::buildScript() {
	cout << "Building the script" << endl;

	vector<Option*> narrative_options1;
	narrative_options1.push_back(new Option("Continue", 0, 2));
	narrative_options1.push_back(new Option("Save and Quit", 0, QUIT_VALUE));

	vector<Option*> choice_options;
	choice_options.push_back(new Option("Up", 100, 5));
	choice_options.push_back(new Option("Down", 200, 6));
	choice_options.push_back(new Option("Left", 300, 7));
	choice_options.push_back(new Option("Right", 400, 8));

	string text = "Narrative scene 1";
	m_vector.push_back(new Scene(text, narrative_options1));

	text = "Narrative scene 2";
	vector<Option*> narrative_options2;
	narrative_options2.push_back(new Option("Continue", 0, 3));
	narrative_options2.push_back(new Option("Save and Quit", 0, QUIT_VALUE));
	m_vector.push_back(new Scene(text, narrative_options2));

	text = "Narrative scene 3";
	vector<Option*> narrative_options3;
	narrative_options3.push_back(new Option("Continue", 0, 4));
	narrative_options3.push_back(new Option("Save and Quit", 0, QUIT_VALUE));
	m_vector.push_back(new Scene(text, narrative_options3));

	text = "Options Scene 1";
	m_vector.push_back(new Scene(text, choice_options));

	text = "Narrative scene 5";
	vector<Option*> narrative_options4;
	narrative_options4.push_back(new Option("Continue", 0, 6));
	narrative_options4.push_back(new Option("Save and Quit", 0, QUIT_VALUE));
	m_vector.push_back(new Scene(text, narrative_options4));

	text = "Narrative scene 6";
	vector<Option*> narrative_options5;
	narrative_options5.push_back(new Option("Continue", 0, 7));
	narrative_options5.push_back(new Option("Save and Quit", 0, QUIT_VALUE));
	m_vector.push_back(new Scene(text, narrative_options5));

	text = "Narrative scene 7";
	vector<Option*> narrative_options6;
	narrative_options6.push_back(new Option("Continue", 0, 8));
	narrative_options6.push_back(new Option("Save and Quit", 0, QUIT_VALUE));
	m_vector.push_back(new Scene(text, narrative_options6));

	text = "Narrative scene 8";
	vector<Option*> narrative_options9;
	narrative_options9.push_back(new Option("Save and Quit", 0, QUIT_VALUE));
	m_vector.push_back(new Scene(text, narrative_options9));

}