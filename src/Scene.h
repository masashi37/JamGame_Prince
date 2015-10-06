
#pragma once

#include "Title.h"
#include "Select.h"
#include "Game.h"
#include "Result.h"


class Scene {

private:

	SceneName scene_changer_;

	Title title;
	Select select;
	Game game;
	Result result;

public:

	Scene();

	void setup();
	void update();
	void draw();
	void shift();

};

