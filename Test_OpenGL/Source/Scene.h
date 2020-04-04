#ifndef _SCENE_H_
#define _SCENE_H_

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "opencv2/opencv.hpp"

#include "stdio.h"
#include "vector"
#include "Sprite2D.h"

class Scene
{
public:
	Scene();
	~Scene();
	Scene* GetScene();

	void Render(std::vector<Sprite2D>);

	GLuint* GetTexID();

private:
	std::vector<GLuint*> texID;

protected:
	virtual bool Init();
	virtual void Update();

};

#endif