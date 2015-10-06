
#include "Chara.h"


Chara::Chara(){

	const char* texture_name[CHARA_MAX]{
		"res/Texture/Chara/alice.png",
		"res/Texture/Chara/cinderella.png",
		"res/Texture/Chara/kaguya.png",
		"res/Texture/Chara/much.png",
		"res/Texture/Chara/red_zukin.png",
		"res/Texture/Chara/snow_white.png",

		"res/Texture/Chara/alice_evo.png",
		"res/Texture/Chara/cinderella_evo.png",
		"res/Texture/Chara/kaguya_evo.png",
		"res/Texture/Chara/much_evo.png",
		"res/Texture/Chara/red_zukin_evo.png",
		"res/Texture/Chara/snow_white_evo.png",
	};
	for (int index = 0; index < CHARA_MAX; ++index) {
		chara_list_[index] = new Texture(texture_name[index]);
	}

}
