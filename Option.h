#ifndef OPTION_H
#define OPTION_H

#include <string>

class Option {
private:
	std::string m_text;
	int m_points;
	int m_next_scene;
public:
	Option(std::string text, int points, int next);
	void setNextScene(int scene_number);
	int getNextScene();
	std::string getText();
	int getPoints();
};

#endif