#include "pch.h"
#include "TitleScene.h"

#include "opencv2/opencv.hpp"
#include "Sprite2D.h"

GLuint g_texID[2];
std::vector<Sprite2D> splist;

#define XLEN 72
#define YLEN 56

// テクスチャデータの使用する範囲を指定
// 画面左上が原点(0,0)　左下から反時計回りに領域指定
const GLfloat whblock[] = {
	0.0f, 0.2f,
	0.1f, 0.2f,
	0.1f, 0.1f,
	0.0f, 0.1f,
};
const GLfloat bkblock[] = {
	0.1f, 0.2f,
	0.2f, 0.2f,
	0.2f, 0.1f,
	0.1f, 0.1f,
};

/*
	glBindTextureの動作は重いらしいので、
	テクスチャアトラス（1枚の画像ファイルに複数の絵をくっつけ切り取り使用）を作成し、
	1回だけ関数を呼び出すようにしたら高速化が図れる

	さらにglDrawArayysを呼び出す回数を減らすとさらに高速化できる
	(動くオブジェクトなどは例外だとか。背景などの動かないオブジェクト限定でやるべきか。)
*/

//------------------------------------------------------------------------------
// コンストラクタ
//------------------------------------------------------------------------------
TitleScene::TitleScene() {
	Init();
	int xlen = XLEN;
	int ylen = YLEN;
	int map[YLEN][XLEN] = {
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	for (int y = 0; y < ylen; y++) {
		for (int x = 0; x < xlen; x++) {
			float xpos = 48;
			float ypos = 24;
			int size = 48;

			Sprite2D* sprite = new Sprite2D(GetTexID());
			sprite->TexutreLoad("OpenGL_Test.png");
			if (map[(ylen - 1) - y][(xlen - 1) - x] == 0) {
				sprite->SetTexUV(bkblock);
			}
			else
			{
				sprite->SetTexUV(whblock);
			}
			sprite->SetPosition(xpos + (size * x), ypos + (size * y));
			sprite->SetSize(size, size);
			sprite->Create();
			splist.push_back(*sprite);

		}
	}
}

TitleScene::~TitleScene() {
	
}

void TitleScene::Update() {
	Render(splist);
	//glTranslatef(0.05f, 0, 0);
}
