#include "pch.h"
#include "PlayScene.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

PlayScene::PlayScene() {
	xpos = 0.0f;
	ypos = 0.0f;
}

PlayScene::~PlayScene() {

}

void PlayScene::Update() {

	glPushMatrix();

	glTranslatef(xpos, ypos, 0.0f);

	// ���W
	static const GLfloat vtx1[] = { 320, 240 };
	// ���W�̐ݒ�
	glVertexPointer(2, GL_FLOAT, 0, vtx1);
	// �T�C�Y
	glPointSize(40.0f);
	// �F

	static const GLfloat vtx2[] = { 320, 340 };
	// ���W�̐ݒ�
	glVertexPointer(2, GL_FLOAT, 0, vtx2);
	// �T�C�Y
	glPointSize(40.0f);
	// �F


	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	xpos += 0.01f;
}

