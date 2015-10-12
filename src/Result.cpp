
#include "Result.h"


Result::Result() {

	const char* result_texture_name[RESULT_TEXTURE_MAX]{
		"res/Texture/Ending/arisu.png",
		"res/Texture/Ending/sinderera.png",
		"res/Texture/Ending/kaguya.png",
		"res/Texture/Ending/matti.png",
		"res/Texture/Ending/akazukin.png",
		"res/Texture/Ending/sirayuki.png",

		"res/Texture/Ending/kuria.png"

	};
	for (int index = 0; index < RESULT_TEXTURE_MAX; ++index) {
		result_list[index] = new Texture(result_texture_name[index]);
	}

	//--------------------------------------------------------------

	result.pos = Vec2f(-WIDTH / 2, -HEIGHT / 2);
	result.size = Vec2f(WIDTH, HEIGHT);
	result.cut_size = Vec2i(1024, 512);

}


void Result::setResultWinner(bool win_or_lose) {
	is_clear = win_or_lose;
}

void Result::setResultChara(int selection_result_number) {

	if (is_clear == true)
		result.pic = *result_list[WINNER];
	else if (is_clear == false) {
		if (selection_result_number == 0)
			result.pic = *result_list[ALICE_LOSE];
		else if (selection_result_number == 1)
			result.pic = *result_list[CINDERELLA_LOSE];
		else if (selection_result_number == 2)
			result.pic = *result_list[KAGUYA_LOSE];
		else if (selection_result_number == 3)
			result.pic = *result_list[MUCH_GIRL_LOSE];
		else if (selection_result_number == 4)
			result.pic = *result_list[RED_HOOD_LOSE];
		else if (selection_result_number == 5)
			result.pic = *result_list[SNOW_WHITE_LOSE];
	}
}


void Result::update() {


	if (is_clear == true)
	{

	}
	if (is_clear == false)
	{

	}




	/*
	//BGM Ä¶
	if (music_flag.result_music_flag == false){
	music_list[RESULT_MUSIC]->gain(150);
	music_list[RESULT_MUSIC]->play();
	music_flag.result_music_flag = true;
	}*/

}

void Result::draw() {

	drawTextureBox(result.pos.x(),
		result.pos.y(),
		result.size.x(),
		result.size.y(),
		result.cut_pos.x(),
		result.cut_pos.y(),
		result.cut_size.x(),
		result.cut_size.y(),
		result.pic, Color::white);

	/*
	if (is_clear == true)
	drawTextureBox(x, y,
	size_x, size_y,
	cut_x, cut_y,
	cut_size_x, cut_size_y,
	clear_bg,
	Color::white);

	else if (is_gameover == true)
	drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
	WIDTH, HEIGHT,
	0, 0,
	image_size_bg_width, image_size,
	*result_list[result_pic_select],
	Color::white);*/
}

SceneName Result::shift() {
	return SceneName::TITLE;
}

void Result::reset() {

}

