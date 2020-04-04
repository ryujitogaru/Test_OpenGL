/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		class  :Sprite.cs
	copyright  :Ryuji.Togaru
	 Contents  :生成した画像を管理するクラス

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#ifndef _SPRITE2D_H_
#define _SPRITE2D_H_

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "opencv2/opencv.hpp"

#include "stdio.h"
#include "string"

class Sprite2D {
	public:
		// 座標
		struct Position{
			float x, y;
		};
		Position position;
		// 画像サイズ
		struct Size{
			int width, height;
		};
		Size size;
		//  テクスチャのUV座標
		const GLfloat* texuv;

		// コンストラクタ・デストラクタ
		Sprite2D(GLuint* texid);
		~Sprite2D();

		// 画像ファイルからテクスチャを生成し紐付け
		void Create();
		void TexutreLoad(const char*);
		void SetPosition(float, float);
		void SetSize(int, int);
		void SetTexUV(const GLfloat*);
};

#endif // !_SPRITE2D_H_
