
#include "Player.h"


Player::Player(Vec2f start_player_pos, Vec2f start_player_size)
{

	player_.pos = start_player_pos;
	player_.size = start_player_size;
	player_.speed = Vec2f::Zero();
	player_.cut_pos = Vec2f::Zero();
	player_.cut_size = Vec2i(512, 512);

}


Vec2f Player::getPos() {
	return player_.pos;
}

void Player::setPos(Vec2f change_pos) {
	player_.pos = change_pos;
}

Vec2f Player::getSize() {
	return player_.size;
}


void Player::setup(int selection_player_number) {

	if (selection_player_number == 0)
		player_.pic = *chara_list_[ALICE];
	else if (selection_player_number == 1)
		player_.pic = *chara_list_[CINDERELLA];
	else if (selection_player_number == 2)
		player_.pic = *chara_list_[KAGUYA];
	else if (selection_player_number == 3)
		player_.pic = *chara_list_[MUCH_GIRL];
	else if (selection_player_number == 4)
		player_.pic = *chara_list_[RED_HOOD];
	else if (selection_player_number == 5)
		player_.pic = *chara_list_[SNOW_WHITE];

}

void Player::update() {

	if (App::env->isPressKey('A'))
		player_.pos.x() -= 5.0f;

}

void Player::draw() {

	drawTextureBox(
		player_.pos.x(),
		player_.pos.y(),
		player_.size.x(),
		player_.size.y(),
		player_.cut_pos.x(),
		player_.cut_pos.y(),
		player_.cut_size.x(),
		player_.cut_size.y(),
		player_.pic,
		Color::white);

}
