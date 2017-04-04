#include <string>

class User {
private:
	int m_current_scene;
	std::string m_user_name;
	int m_user_score;

public:
	User(std::string name);
	User(std::string name, int scene, int score);
	~User();
	void viewPlayer();
	int increaseScoreBy(int score);
	int decreaseScoreBy(int score);
	int getCurrentScore();
	void setCurrentScore();
	std::string getUserName();
	int getCurrentScene();
	void setCurrentScene();
};