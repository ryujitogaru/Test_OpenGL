/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		class  :Scene.cs
	copyright  :Ryuji.Togaru
	 Contents  :

 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#include "pch.h"
#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {

}

bool Scene::Init() {

	glGenTextures(1, GetTexID());
	return false;
}

void Scene::Update() {

}
void Scene::Render(std::vector<Sprite2D> splist) {

	glBindTexture(GL_TEXTURE_2D, GetTexID()[0]);

	// 各画像の有効化
	glEnable(GL_BLEND); // 透過画像用
	glEnable(GL_TEXTURE_2D); // 通常画像用

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 透過画像用

	// 頂点配列を有効化
	glEnableClientState(GL_VERTEX_ARRAY); // 頂点配列
	glEnableClientState(GL_TEXTURE_COORD_ARRAY); // テクスチャ座標配列

	for (int i = 0; i < splist.size(); i++) {
		Sprite2D sp = splist.at(i);
		// 画面上の座標を指定
		// 画面左下が原点　原点から反時計回りに領域指定
		GLfloat vtx[] = {
			sp.position.x, sp.position.y,
			sp.position.x + sp.size.width, sp.position.y,
			sp.position.x + sp.size.width, sp.position.y + sp.size.height,
			sp.position.x, sp.position.y + sp.size.height,
		};

		glVertexPointer(2, GL_FLOAT, 0, vtx);	// 座標を指定
		glTexCoordPointer(2, GL_FLOAT, 0, sp.texuv);	// UV座標を指定

		glPushMatrix();
		glDrawArrays(GL_QUADS, 0, 4);
		glPopMatrix();
	}

	// 有効化した設定を無効化
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	return;

	// 画面左下が原点　原点から反時計回りに領域指定
	static const GLfloat vtx[] = {
		//-100, -100,
		// 100, -100,
		// 100,  100,
		//-100,  100,
		-32, -32,
		 32, -32,
		 32,  32,
		-32,  32,
	};
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	// テクスチャデータの使用する範囲を指定
	// 画面左上が原点(0,0)　左下から反時計回りに領域指定
	static const GLfloat texuv[] = {
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
	};
	glTexCoordPointer(2, GL_FLOAT, 0, texuv);

	//glBindTexture(GL_TEXTURE_2D, g_texID);
	glBindTexture(GL_TEXTURE_2D, GetTexID()[0]);

	// 各画像の有効化
	glEnable(GL_BLEND); // 透過画像用
	glEnable(GL_TEXTURE_2D); // 通常画像用

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 透過画像用

	// 頂点配列を有効化
	glEnableClientState(GL_VERTEX_ARRAY); // 頂点配列
	glEnableClientState(GL_TEXTURE_COORD_ARRAY); // テクスチャ座標配列

	//--------------------------------------------------
	// テクスチャの描画１枚目
	static const GLfloat texauv[] = {
		0.0f, 0.1f,
		0.1f, 0.1f,
		0.1f, 0.0f,
		0.0f, 0.0f,
	};
	glTexCoordPointer(2, GL_FLOAT, 0, texauv);

	glPushMatrix();
	glTranslatef(150, 250, 0);
	glDrawArrays(GL_QUADS, 0, 4);
	glPopMatrix();
	//---------------------------------------------------
	// テクスチャの描画２枚目
	static const GLfloat texuv2[] = {
		0.1f, 0.1f,
		0.2f, 0.1f,
		0.2f, 0.0f,
		0.1f, 0.0f,
	};
	glTexCoordPointer(2, GL_FLOAT, 0, texuv2);

	glPushMatrix();
	glTranslatef(500, 250, 0);
	glDrawArrays(GL_QUADS, 0, 4);
	glPopMatrix();


	// 有効化した設定を無効化
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
}
//------------------------------------------------------------------------------
// テクスチャIDをvectorから配列に変換して取得
//------------------------------------------------------------------------------
GLuint* Scene::GetTexID() {
	int length = (int)texID.size();
	GLuint* reTex = new GLuint[length];
	for (int i = 0; i < length; i++) {
		reTex[i] = *texID[i];
	}
	return reTex;
}
Scene* Scene::GetScene() {
	return this;
}