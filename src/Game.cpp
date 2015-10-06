
#include "Game.h"


Game::Game(){
	map.load();	

	map_speed_ = Vec2f(-3.0f, 0);
}


void Game::setPlayer(int chara_selection_) {
	player.setup(chara_selection_);
}


void Game::setup() {
	map.setup();
}

void Game::update() {

	map.setPos(map_speed_);

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

	return SceneName::GAME;
}

void Game::reset() {

}

