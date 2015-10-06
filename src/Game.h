
#pragma once

#include "Map.h"
#include "Player.h"



class Game {

private:

	Map map;
	Player player = Player(map.getPos(6, 10));


	Vec2f map_speed_;

	bool is_game_end_;
	bool is_clear_;

public:

	Game();

	void setPlayer(int);
	bool getIsCreared();

	void setup();
	void update();
	void draw();
	SceneName shift();
	void reset();

};

