
#include "Game.h"


Game::Game() {
	map.load();

	map_speed_ = Vec2f(-3.0f, 0);

	is_game_end_ = false;
	is_clear_ = NULL;
}


void Game::setPlayer(int chara_selection_) {
	player.setup(chara_selection_);
}

bool Game::getIsCreared() {
	return is_clear_;
}


void Game::setup() {
	map.setup();
}

void Game::update() {

	map.setPos(map_speed_);

	if ((player.getPos().x() + player.getSize().x()) >
		map.getPos(map.GOAL).x()) {
		is_clear_ = true;
		is_game_end_ = true;
	}
	else if (player.getPos().x() < -WIDTH / 2) {
		is_clear_ = false;
		is_game_end_ = true;
	}

	/*
	//BGM Ä¶
	if (music_flag.stage_music1_flag == false){
		music_list[STAGE_MUSIC1]->play();
		charaInit();
		music_flag.stage_music1_flag = true;
	}
	*/

}

void Game::draw() {
	map.draw();
	player.draw();
}

SceneName Game::shift() {

	return (is_game_end_) ?
		SceneName::RESULT : SceneName::GAME;
}

void Game::reset() {

}

