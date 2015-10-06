
#include "Title.h"


Title::Title(){

	title_back_ground_.pos = 
		Vec2f(-WIDTH / 2, -HEIGHT / 2);
	title_back_ground_.size = 
		Vec2f(WIDTH, HEIGHT);
	title_back_ground_.cut_pos = 
		Vec2f(0, 0);
	title_back_ground_.cut_size = 
		Vec2i(1024, 512);
	
	title_name_logo_.pos =
		Vec2f(-WIDTH / 3, -150);
	title_name_logo_.size =
		Vec2f(WIDTH / 1.4f, HEIGHT / 1.4f);
	title_name_logo_.cut_pos = 
		Vec2f(0, 0);
	title_name_logo_.cut_size = 
		Vec2i(1024, 512);

	game_start_logo_.pos =
		Vec2f(-(WIDTH / 2.3f) + 100, -HEIGHT / 2);
	game_start_logo_.size =
		Vec2f(WIDTH / 1.4f, HEIGHT / 1.4f);
	game_start_logo_.cut_pos = 
		Vec2f(0, 0);
	game_start_logo_.cut_size = 
		Vec2i(512, 512);

}


void Title::setup() {
	title_back_ground_.pic =
		Texture("res/Texture/BackGround/title.png");
	title_name_logo_.pic =
		Texture("res/Texture/Logo/title.png");
	game_start_logo_.pic =
		Texture("res/Texture/Logo/game_start.png");
}

void Title::update() {

	/*
	if (App::env->isPushKey(GLFW_KEY_ENTER)) {
		scene_mover = CHARA_SELECT;
		music_list[SELECT_SE_DECIDE]->play();
	}

	//BGM çƒê∂
	if (music_flag.title_music_flag == false) {
		music_list[TITLE_MUSIC]->play();
		music_list[RESULT_MUSIC]->stop();
		music_flag.title_music_flag = true;
	}
	*/

}

void Title::draw() {

	drawTextureBox(
		title_back_ground_.pos.x(), 
		title_back_ground_.pos.y(),
		title_back_ground_.size.x(), 
		title_back_ground_.size.y(),
		title_back_ground_.cut_pos.x(), 
		title_back_ground_.cut_pos.y(),
		title_back_ground_.cut_size.x(), 
		title_back_ground_.cut_size.y(),
		title_back_ground_.pic, 
		Color::white);

	drawTextureBox(
		title_name_logo_.pos.x(),
		title_name_logo_.pos.y(),
		title_name_logo_.size.x(),
		title_name_logo_.size.y(),
		title_name_logo_.cut_pos.x(),
		title_name_logo_.cut_pos.y(),
		title_name_logo_.cut_size.x(),
		title_name_logo_.cut_size.y(),
		title_name_logo_.pic,
		Color::white);

	drawTextureBox(
		game_start_logo_.pos.x(),
		game_start_logo_.pos.y(),
		game_start_logo_.size.x(),
		game_start_logo_.size.y(),
		game_start_logo_.cut_pos.x(),
		game_start_logo_.cut_pos.y(),
		game_start_logo_.cut_size.x(),
		game_start_logo_.cut_size.y(),
		game_start_logo_.pic,
		Color::white);

}

SceneName Title::shift() {
	return SceneName::SELECT;
}

void Title::reset() {

}

//TODO : âπÇÃì«Ç›çûÇ›
//TODO : EnterâüÇµÇΩÇÁâπ
