#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
	int m_current_scene;
	std::string m_user_name;
	int m_current_score;

public:
	User(std::string name);
	User(std::string name, int scene, int score);
	~User();
	void viewPlayer();
	int increaseScoreBy(int score);
	int decreaseScoreBy(int score);
	int getCurrentScore();
	void setCurrentScore(int score);
	std::string getUserName();
	int getCurrentScene();
	void setCurrentScene(int scene);
};

#endif