#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Sprite2D {
	public:
		struct Position
		{
			float x, y;
		};
		Position position;

		struct Size
		{
			float width, height;
		};
		Size size;

		// �R���X�g���N�^�E�f�X�g���N�^
		Sprite2D();
		~Sprite2D();

		// �摜�t�@�C������e�N�X�`���𐶐����R�t��
		void Create();
		void SetupTexture(GLuint, const char*);
		void Draw();
};

#endif // !_SPRITE_H_
