
#include "Result.h"


Result::Result() {
}


void Result::setup() {

}

void Result::update() {

	/*
	//BGM Ä¶
	if (music_flag.result_music_flag == false){
		music_list[RESULT_MUSIC]->gain(150);
		music_list[RESULT_MUSIC]->play();
		music_flag.result_music_flag = true;
	}*/

}

void Result::draw() {

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
	if (App::env->isPushKey('D'))
	return SceneName::TITLE;

	return SceneName::RESULT;
}

void Result::reset() {

}

 