#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "Scene.h"

class TitleScene : Scene {

public:
	// �R���X�g���N�^
	TitleScene();
	// �f�X�g���N�^
	~TitleScene();

	void Update();
private:
};

#endif // !_TITLESCENE_H_
