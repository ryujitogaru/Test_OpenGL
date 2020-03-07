#ifndef _BASESYSTEM_H_
#define _BASESYSTEM_H_

class BaseSystem {
public:
	BaseSystem();
	~BaseSystem();
	 //ƒV[ƒ“î•ñ
	enum SceneState : int
	{
		TITLE = 0,
		PLAY = 1
	};
	SceneState SCENESTATE;	 

private:

};
#endif // !_BASESYSTEM_H_
