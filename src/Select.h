
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Select {

private:

	enum {
		ALICE,
		CINDERELLA,
		KAGUYA,
		MUCH_GIRL,
		RED_HOOD,
		SNOW_WHITE,

		CHARA_MAX,
	};
	Texture* chara_list[CHARA_MAX];
	
	TextureObject chara_[CHARA_MAX];
	TextureObject back_ground_;
	TextureObject select_logo_;
	TextureObject selection_;

	Font font;


	int select_chara_number_;
	int move_interval_;

	float select_chara_mover_;

public:

	Select();

	int getSelectChara();

	void setup();
	void update();
	void draw();
	SceneName shift();
	void reset();

};

