/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		class  :.cs
	copyright  :Ryuji.Togaru
	 Contents  :
		sprite�錾
		�摜�f�[�^�R�t��
		�e��ݒ�ύX�i���W��T�C�Y���j
		����
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#include "pch.h"
#include "Sprite2D.h"
#include "opencv2/opencv.hpp"
#include "Debug.h"

#define PATH "Resources/"

GLuint* texID;
std::string filename;

//------------------------------------------------------------------------------
// �R���X�g���N�^�@�f�X�g���N�^
//------------------------------------------------------------------------------
Sprite2D::Sprite2D(GLuint* texid) {
	texID = texid;
	position.x = 0;
	position.y = 0;
}
Sprite2D::~Sprite2D() {

}
//------------------------------------------------------------------------------
// �摜�t�@�C������e�N�X�`���𐶐����R�t��
//------------------------------------------------------------------------------
void Sprite2D::Create() {
	// Step2. �摜�f�[�^�̃��[�h
	cv::Mat img = cv::imread(filename, cv::IMREAD_UNCHANGED);
	cv::cvtColor(img, img, cv::COLOR_BGRA2RGBA); // BGRA����RGBA�֕ϊ�
	
	// Step3. �摜�f�[�^�ƃe�N�X�`��iD�����т���
	glBindTexture(GL_TEXTURE_2D, *texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.data);

	// Step4. �e�N�X�`���̊e��ݒ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//// �e�N�X�`�����擾
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