
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Chara {

protected:

	enum CharaTextureName {
		ALICE,
		CINDERELLA,
		KAGUYA,
		MUCH_GIRL,
		RED_HOOD,
		SNOW_WHITE,

		ALICE_DASH,
		CINDERELLA_DASH,
		KAGUYA_DASH,
		MUCH_GIRL_DASH,
		RED_HOOD_DASH,
		SNOW_WHITE_DASH,

		CHARA_MAX,
	};
	Texture* chara_list_[CHARA_MAX];
	

	struct CharaDate :TextureObject {
		Vec2f speed;
	};

public:

	Chara();

};
