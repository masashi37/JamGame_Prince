
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Title {

private:

	TextureObject title_back_ground_;
	TextureObject title_name_logo_;
	TextureObject game_start_logo_;
	
public:

	Title();

	void setup();
	void update();
	void draw();
	SceneName shift();
	void reset();

};