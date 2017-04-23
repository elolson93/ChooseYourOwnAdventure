#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include "Option.h"

class Scene {
private:
	std::vector<Option*> m_options;
	std::string m_text;

public:
	Scene(std::string text, std::vector<Option*> options);
	~Scene();
	std::string getText();
	std::vector<Option*> getOptions();
};

#endif