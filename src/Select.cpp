
#include "Select.h"


Select::Select() :
	font("")
{

	back_ground_.pos =
		Vec2f(-WIDTH / 2, -HEIGHT / 2);
	back_ground_.size =
		Vec2f(WIDTH, HEIGHT);
	back_ground_.cut_size =
		Vec2i(1024, 512);

	select_logo_.pos =
		Vec2f((-WIDTH / 2) + 600, (HEIGHT / 2) - 300);
	select_logo_.size =
		Vec2f(800, 500);
	select_logo_.cut_size =
		Vec2i(512, 512);

	selection_.pos =
		Vec2f((-WIDTH / 2) + 50, (HEIGHT / 2) - 500);
	selection_.size =
		Vec2f(300, 300);
	selection_.cut_size =
		Vec2i(512, 512);

	back_ground_.cut_pos =
		select_logo_.cut_pos =
		selection_.cut_pos =
		Vec2f(0, 0);


	for (int i = 0; i < CHARA_MAX; ++i) {
		chara_[i].pos =
			Vec2f(-(WIDTH / 2) + (300 * i) + 150,
				(HEIGHT / 2) - 500);
		chara_[i].size =
			Vec2f(300, 300);
		chara_[i].cut_pos =
			Vec2f(0, 0);
		chara_[i].cut_size =
			Vec2i(512, 512);
	}


	select_chara_number_ = 0;
	move_interval_ = 0;

	select_chara_mover_ = 1.0f;

}


int Select::getSelectChara() {
	return select_chara_number_;
}


void Select::setup() {

	const char* text_name[CHARA_MAX]{
		"res/Texture/Chara/alice.png",
		"res/Texture/Chara/cinderella.png",
		"res/Texture/Chara/kaguya.png",
		"res/Texture/Chara/much.png",
		"res/Texture/Chara/red_zukin.png",
		"res/Texture/Chara/snow_white.png",
	};
	for (int index = 0; index < CHARA_MAX; ++index) {
		chara_list[index] = new Texture(text_name[index]);
	}

	selection_.pic =
		Texture("res/Texture/UI/selecticon_right.png");

	back_ground_.pic =
		Texture("res/Texture/BackGround/title.png");

	select_logo_.pic =
		Texture("res/Texture/Logo/chara_select.png");

	font = Font("res/KodomoRounded.otf");
	font.size(50);

}

void Select::update() {

	if (App::env->isPushKey(GLFW_KEY_LEFT)) {
		(select_chara_number_ == 0) ?
			0 : --select_chara_number_;

		for (int i = 0; i < CHARA_MAX; ++i)
			chara_[i].pos.y() = (HEIGHT / 2) - 500;
	}
	else if (App::env->isPushKey(GLFW_KEY_RIGHT)) {
		(select_chara_number_ == 5) ?
			0 : ++select_chara_number_;

		for (int i = 0; i < CHARA_MAX; ++i)
			chara_[i].pos.y() = (HEIGHT / 2) - 500;
	}

	chara_[select_chara_number_].pos.y() +=
		select_chara_mover_;

	++move_interval_;

	if (move_interval_ % 60 == 0)
		select_chara_mover_ *= -1;

}

void Select::draw() {

	drawTextureBox(
		back_ground_.pos.x(),
		back_ground_.pos.y(),
		back_ground_.size.x(),
		back_ground_.size.y(),
		back_ground_.cut_pos.x(),
		back_ground_.cut_pos.y(),
		back_ground_.cut_size.x(),
		back_ground_.cut_size.y(),
		back_ground_.pic,
		Color::white);

	drawTextureBox(
		select_logo_.pos.x(),
		select_logo_.pos.y(),
		select_logo_.size.x(),
		select_logo_.size.y(),
		select_logo_.cut_pos.x(),
		select_logo_.cut_pos.y(),
		select_logo_.cut_size.x(),
		select_logo_.cut_size.y(),
		select_logo_.pic,
		Color::white);

	font.draw("そうさほうほう", Vec2f(-700, -100), Color::white);
	font.draw("スペースキー : ジャンプ", Vec2f(-700, -200), Color::white);
	font.draw("エスケープキー : いちじていし", Vec2f(-700, -300), Color::white);

	for (int i = 0; i < CHARA_MAX; ++i) {
		drawTextureBox(
			chara_[i].pos.x(),
			chara_[i].pos.y(),
			chara_[i].size.x(),
			chara_[i].size.y(),
			chara_[i].cut_pos.x(),
			chara_[i].cut_pos.y(),
			chara_[i].cut_size.x(),
			chara_[i].cut_size.y(),
			*chara_list[i],
			Color::white);
	}

	drawTextureBox(
		selection_.pos.x() + (300 * select_chara_number_),
		selection_.pos.y(),
		selection_.size.x(),
		selection_.size.y(),
		selection_.cut_pos.x(),
		selection_.cut_pos.y(),
		selection_.cut_size.x(),
		selection_.cut_size.y(),
		selection_.pic,
		Color::red);

}

SceneName Select::shift() {
	return SceneName::GAME;
}

void Select::reset() {
}

//TODO : キャラ切替操作時の音
//TODO : キャラのゲーム画面への反映
