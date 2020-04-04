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

	// 座標
	static const GLfloat vtx1[] = { 320, 240 };
	// 座標の設定
	glVertexPointer(2, GL_FLOAT, 0, vtx1);
	// サイズ
	glPointSize(40.0f);
	// 色

	static const GLfloat vtx2[] = { 320, 340 };
	// 座標の設定
	glVertexPointer(2, GL_FLOAT, 0, vtx2);
	// サイズ
	glPointSize(40.0f);
	// 色


	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableClientState(GL_VERTEX_ARRAY);

	glPopMatrix();

	xpos += 0.01f;
}

