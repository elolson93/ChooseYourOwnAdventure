#include "Scene.h"
#include <vector>
#include "User.h"

class SceneManager {
private:
	std::vector<Scene*> m_vector;
	int m_current_scene;
	User* m_user;
	const static int QUIT_VALUE = -1;
	const static int CONTINUE_VALUE = 1;
	int displayScene(int scene);
	void buildScript();
public:
	SceneManager(User* user);
	~SceneManager();
	void begin();
};