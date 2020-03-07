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

		// コンストラクタ・デストラクタ
		Sprite2D();
		~Sprite2D();

		// 画像ファイルからテクスチャを生成し紐付け
		void Create();
		void SetupTexture(GLuint, const char*);
		void Draw();
};

#endif // !_SPRITE_H_
