#ifndef _SOLDIER_INCLUDE
#define _SOLDIER_INCLUDE

#include "Game.h"
#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Enemy.h"


class Soldier: public Enemy
{
public:

	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram) override;
	void update(glm::ivec2 &posPlayer1, glm::ivec2 &posPlayer2, int deltaTime) override;
	void render() override;

	void setTileMap(TileMap *tileMap) override;
	void setPosition(const glm::vec2 &pos) override;
	glm::ivec2 getPosition() override;
	glm::ivec2 getSize() override;
	string type() override;

	glm::ivec2 getTopLeftPos() override;

private:
	bool bJumping;
	glm::ivec2 tileMapDispl, posPlayer;
	int jumpAngle, startY;
	Texture spritesheet;
	Sprite *sprite;
	TileMap *map;
};

#endif