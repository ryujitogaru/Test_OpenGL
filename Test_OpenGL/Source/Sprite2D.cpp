/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		class  :.cs
	copyright  :Ryuji.Togaru
	 Contents  :
		sprite宣言
		画像データ紐付け
		各種設定変更（座標やサイズ等）
		生成
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#include "pch.h"
#include "Sprite2D.h"
#include "opencv2/opencv.hpp"
#include "Debug.h"

#define PATH "Resources/"

GLuint* texID;
std::string filename;

//------------------------------------------------------------------------------
// コンストラクタ　デストラクタ
//------------------------------------------------------------------------------
Sprite2D::Sprite2D(GLuint* texid) {
	texID = texid;
	position.x = 0;
	position.y = 0;
}
Sprite2D::~Sprite2D() {

}
//------------------------------------------------------------------------------
// 画像ファイルからテクスチャを生成し紐付け
//------------------------------------------------------------------------------
void Sprite2D::Create() {
	// Step2. 画像データのロード
	cv::Mat img = cv::imread(filename, cv::IMREAD_UNCHANGED);
	cv::cvtColor(img, img, cv::COLOR_BGRA2RGBA); // BGRAからRGBAへ変換
	
	// Step3. 画像データとテクスチャiDを結びつける
	glBindTexture(GL_TEXTURE_2D, *texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.data);

	// Step4. テクスチャの各種設定
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//// テクスチャ情報取得
	//size.width = img.cols;
	//size.height = img.rows;

}
void Sprite2D::TexutreLoad(const char* file) {
	filename = PATH + std::string(file);
}
void Sprite2D::SetTexUV(const GLfloat* uv) {
	texuv = uv;
}
void Sprite2D::SetPosition(float x, float y) {
	position.x = x;
	position.y = y;
}
void Sprite2D::SetSize(int x, int y) {
	size.width = x;
	size.height = y;
}