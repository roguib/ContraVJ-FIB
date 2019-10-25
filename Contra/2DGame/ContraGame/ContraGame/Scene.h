#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include <String.h>
#include "ShaderProgram.h"
#include "SoundSystem.h"
#include "TileMap.h"
#include "Player.h"
#include "Enemy.h"
#include "SpreadGun.h"
#include "IconLife.h"


// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene
{

public:
	Scene();
	~Scene();
	void loadMenu();
	void loadControls();
	void menuUpdate(int deltaTime);
	void controlsUpdate(int deltaTime);
	void level2Update(int deltaTime);
	
	void init();
	void initLv01();
	void initLv02();
	void initLv03();

	void update(int deltaTime);
	void updateLv01(int deltaTime);
	void updateLv02(int deltaTime);
	void updateLv03(int deltaTime);

	void CameraUpdate();

	void render();
	void renderLv01();
	void renderLv02();
	void renderLv03();

private:
	void initShaders();

private:
	string state = "MENU"; // MENU, CONTROLS, PLAYING
	TileMap *map;
	Texture spritesheet, spritesheetSelector, spritesheetControls, spritesheetLifes, spritesheetPower;
	Sprite *sprite, *spriteSelector, *spriteControls, *spriteLifes, *spritePower;
	Player *player;
	ShaderProgram texProgram;
	Enemy *enemy;
	SpreadGun *spread;
	IconLife *Icon1,*Icon2, *Icon3;
	float currentTime;
	glm::mat4 projection;
	bool playing = false;
	// testing only
	long long lastSecondFired = 0;
	float limitCamera;
	string currentLevel = "LEVEL01";

};


#endif // _SCENE_INCLUDE

