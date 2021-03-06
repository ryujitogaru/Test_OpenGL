// Test_OpenGL.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
// OpenGL関連
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "BaseSystem.h"
#include "TitleScene.h"
#include "PlayScene.h"

// ウィンドウサイズの設定
const int g_windowWidth = 960;
const int g_windowHeight = 720;

int WinMain(int argc, char *argv[]) {
	// GLFW初期化
	if (glfwInit() == GL_FALSE) {
		return -1;
	}

	// ウインドウ生成
	GLFWwindow* window = glfwCreateWindow(g_windowWidth, g_windowHeight, "OpenGLSample", NULL, NULL);
	if (!window) {
		glfwTerminate();

		return -2;
	}

	// コンテキストの作成
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// 描画範囲の指定
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, g_windowWidth, 0.0f, g_windowHeight, -1.0f, 1.0f);

	// GLEW初期化
	if (glewInit() != GLEW_OK) {
		return -3;
	}
	// 基本システム
	BaseSystem baseSystem;
	// 各シーンクラス
	TitleScene titleScene;
	PlayScene playScene;

	int frame = 0;

	// ゲームループ
	while (glfwWindowShouldClose(window) == GL_FALSE) {
		// 背景バッファのクリア
		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		switch (baseSystem.SCENESTATE)
		{
		case baseSystem.TITLE:
			titleScene.Update();
			break;
		case baseSystem.PLAY:
			playScene.Update();
			break;
		}


		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			if (baseSystem.SCENESTATE == 0)
				baseSystem.SCENESTATE = baseSystem.PLAY;
			else
				baseSystem.SCENESTATE = baseSystem.TITLE;
		}

		// ダブルバッファのスワップ
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}
//
//int main(int argc, char *argv[]){
//	// GLFW初期化
//	if (glfwInit() == GL_FALSE) {
//		return -1;
//	}
//
//	// ウインドウ生成
//	GLFWwindow* window = glfwCreateWindow(g_windowWidth, g_windowHeight, "OpenGLSample", NULL, NULL);
//	if (!window) {
//		glfwTerminate();
//
//		return -2;
//	}
//
//	// コンテキストの作成
//	glfwMakeContextCurrent(window);
//	glfwSwapInterval(1);
//
//	// 描画範囲の指定
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0f, g_windowWidth, 0.0f, g_windowHeight, -1.0f, 1.0f);
//
//	// GLEW初期化
//	if (glewInit() != GLEW_OK) {
//		return -3;
//	}
//	// 基本システム
//	BaseSystem baseSystem;
//	// 各シーンクラス
//	TitleScene titleScene;
//	PlayScene playScene;
//
//	int frame = 0;
//
//	// ゲームループ
//	while (glfwWindowShouldClose(window) == GL_FALSE) {
//		// バッファのクリア
//		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		switch (baseSystem.SCENESTATE)
//		{
//		case baseSystem.TITLE:
//			titleScene.Update();
//			break;
//		case baseSystem.PLAY:
//			playScene.Update();
//			break;
//		}
//
//
//		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
//			if (baseSystem.SCENESTATE == 0)
//				baseSystem.SCENESTATE = baseSystem.PLAY;
//			else
//				baseSystem.SCENESTATE = baseSystem.TITLE;
//		}
//
//		// ダブルバッファのスワップ
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//}
