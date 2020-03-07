#include "pch.h"
#include "TitleScene.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "opencv2/opencv.hpp"

#include "Sprite.h"

GLuint g_texID[2];
/*
	glBindTexture�̓���͏d���炵���̂ŁA
	�e�N�X�`���A�g���X�i1���̉摜�t�@�C���ɕ����̊G���������؂���j���쐬���A
	1�񂾂��֐����Ăяo���悤�ɂ����獂�������}���
*/

float posx = 0;

//------------------------------------------------------------------------------
// �R���X�g���N�^
//------------------------------------------------------------------------------
TitleScene::TitleScene() {
	// Step1. �e�N�X�`���̃��[�h
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
	// Step5. �e�N�X�`���̕\���̈�����W�Ŏw��
	// ��ʍ��������_�@���_���甽���v���ɗ̈�w��
	static const GLfloat vtx[] = {
		-100, -100,
		 100, -100,
		 100,  100,
		-100,  100,
	};
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	// �e�N�X�`���f�[�^�̎g�p����͈͂��w��
	// ��ʍ��オ���_�@�������甽���v���ɗ̈�w��
	static const GLfloat texuv[] = {
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
	};
	glTexCoordPointer(2, GL_FLOAT, 0, texuv);

	// Step6. �e�N�X�`���̉摜�w��
	//glBindTexture(GL_TEXTURE_2D, g_texID);

	// Step7. �e�N�X�`���̕`��
	glEnable(GL_BLEND); // ���߉摜�p
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // ���߉摜�p
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	// 1���ڂ̉摜
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, g_texID[0]);
	glTranslatef(100, 100, 0);
	glDrawArrays(GL_QUADS, 0, 4);
	glPopMatrix();

	// 2���ڂ̉摜
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
	// Step2. �摜�f�[�^�̃��[�h
	cv::Mat img = cv::imread(file, cv::IMREAD_UNCHANGED);
	cv::cvtColor(img, img, cv::COLOR_BGRA2RGBA);
	
	// Step3. �摜�f�[�^�ƃe�N�X�`��iD�����т���
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.cols, img.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.data);

	// Step4. �e�N�X�`���̊e��ݒ�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

}