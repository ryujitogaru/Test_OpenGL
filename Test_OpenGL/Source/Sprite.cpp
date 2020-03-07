#include "pch.h"
#include "Sprite.h"
#include "opencv2/opencv.hpp"

//------------------------------------------------------------------------------
// コンストラクタ　デストラクタ
//------------------------------------------------------------------------------
Sprite2D::Sprite2D() {

}
Sprite2D::~Sprite2D() {

}
//------------------------------------------------------------------------------
// 画像ファイルからテクスチャを生成し紐付け
//------------------------------------------------------------------------------
void Sprite2D::Create() {

}
//------------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
void Sprite2D::SetupTexture(GLuint texID, const char* file) {
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