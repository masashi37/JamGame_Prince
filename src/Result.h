
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Result {

private:

	enum {
		ALICE_LOSE,
		CINDERELLA_LOSE,
		KAGUYA_LOSE,
		MUCH_GIRL_LOSE,
		RED_HOOD_LOSE,
		SNOW_WHITE_LOSE,

		WINNER,

		RESULT_TEXTURE_MAX,
	};
	Texture* result_list[RESULT_TEXTURE_MAX];

	TextureObject result;


	bool is_clear;

public:

	Result();
	
	void setResultWinner(bool);
	void setResultChara(int);

	void update();
	void draw();
	SceneName shift();
	void reset();

};

