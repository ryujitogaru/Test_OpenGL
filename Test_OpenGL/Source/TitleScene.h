#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class TitleScene {

public:
	// �R���X�g���N�^
	TitleScene();
	// �f�X�g���N�^
	~TitleScene();

	void Update();

	void render();
	void setupTexture(GLuint, const char*);

private:
};

#endif // !_TITLESCENE_H_
