#include "pch.h"
#include "TitleScene.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "opencv2/opencv.hpp"

#include "Sprite.h"

GLuint g_texID[2];
/*
	glBindTextureの動作は重いらしいので、
	テクスチャアトラス（1枚の画像ファイルに複数の絵をくっつけ切り取る）を作成し、
	1回だけ関数を呼び出すようにしたら高速化が図れる
*/

float posx = 0;

//------------------------------------------------------------------------------
// コンストラクタ
//------------------------------------------------------------------------------
TitleScene::TitleScene() {
	// Step1. テクスチャのロード
	glGenTextures(2, g_texID);
	setupTexture(g_texID[0], "Resources/Impling.png");
	setupTexture(g_texID[1], "Resources/SAMPLE.png");
}

TitleScene::~TitleScene() {

}

void TitleScene::Update() {

	render();
	glTranslatef(0.05f, 0, 0);
	//glRotatef(0.1f, 0.0f, 0.0f, 1.0f);
	//posx += 0.05f;
	
}

void TitleScene::render(){
	// Step5. テクスチャの表示領域を座標で指定
	// 画面左下が原点　原点から反時計回りに領域指定
	static const GLfloat vtx[] = {
		-100, -100,
		 100, -100,
		 100,  100,
		-100,  100,
	};
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	// テクスチャデータの使用する範囲を指定
	// 画面左上が原点　左下から反時計回りに領域指定
	static const GLfloat texuv[] = {
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
	};
	glTexCoordPointer(2, GL_FLOAT, 0, texuv);

	// Step6. テクスチャの画像指定
	//glBindTexture(GL_TEXTURE_2D, g_texID);

	// Step7. テクスチャの描画
	glEnable(GL_BLEND); // 透過画像用
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 透過画像用
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// 1枚目の画像
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_texID[0]);
	glTranslatef(100, 100, 0);
	glDrawArrays(GL_QUADS, 0, 4);
	glPopMatrix();

	// 2枚目の画像
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_texID[1]);
	glTranslatef(100, 300, 0);
	glDrawArrays(GL_QUADS, 0, 4);
	glPopMatrix();
	

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
}

void TitleScene::setupTexture(GLuint texID, const char *file)
{
	// Step2. 画像データのロード
	cv::Mat img = cv::imread(file, cv::IMREAD_UNCHANGED);
	cv::cvtColor(img, img, cv::COLOR_BGRA2RGBA);
	
	// Step3. 画像データとテクスチャiDを結びつける
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.data);

	// Step4. テクスチャの各種設定
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

}