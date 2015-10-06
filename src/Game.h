
#pragma once

#include "AppEnv.h"
#include "Common.h"

#include "Map.h"
#include "Player.h"



class Game {

private:

	Map map;
	Player player = Player(map.getPos(6, 10));


	Vec2f map_speed_;

public:

	Game();

	void setPlayer(int);

	void setup();
	void update();
	void draw();
	SceneName shift();
	void reset();

};

