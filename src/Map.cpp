
#include "Map.h"


Map::Map() :
	map_type_("res/mapType/map_type01.txt")
{

	for (int y = 0; y < MAP_LENGTH; ++y) {
		for (int x = 0; x < MAP_WIDE; ++x) {

			map_[y][x].size =
				Vec2f(100, 100);

			map_[y][x].pos.x() =
				-WIDTH / 2 + (map_[y][x].size.x() * x);
			map_[y][x].pos.y() =
				HEIGHT / 2 - map_[y][x].size.y() -
				(map_[y][x].size.y() * y);

			map_[y][x].cut_pos =
				Vec2f(0, 0);
			map_[y][x].cut_size =
				Vec2i(512, 512);

		}
	}

}


Vec2f Map::getPos() {
	Vec2f map_pos;
	for (int y = 0; y < MAP_LENGTH; ++y) {
		for (int x = 0; x < MAP_WIDE; ++x) {
			map_pos = map_[y][x].pos;
		}
	}
	return map_pos;
}

Vec2f Map::getPos(int y, int x) {
	return map_[y][x].pos;
}

void  Map::setPos(Vec2f change_pos) {

	for (int y = 0; y < MAP_LENGTH; ++y) {
		for (int x = 0; x < MAP_WIDE; ++x) {

			map_[y][x].pos += change_pos;

		}
	}
}

Vec2f Map::getSize() {
	return map_[0][0].size;
}


void Map::load() {

	for (int y = 0; y < MAP_LENGTH; ++y) {
		for (int x = 0; x < MAP_WIDE; ++x) {

			map_type_ >> map_[y][x].state;

		}
	}

}

void Map::setup() {

	//ƒ}ƒbƒv---------------------------------------------
	const char* block_name[BLOCK_TEXTURE_MAX]{
		"res/Texture/Block/floor.png",
		"res/Texture/Block/ground.png",
		"res/Texture/Block/trans.png",
		"res/Texture/Block/concrete.png",
		"res/Texture/Block/red_carpet.png",
		"res/Texture/Block/prince.png",
		"res/Texture/Block/speed_down.png",
	};
	for (int index = 0; index < BLOCK_TEXTURE_MAX; ++index) {
		block_list_[index] = new Texture(block_name[index]);
	}

}

void Map::draw() {

	auto map_pic_type = 0;

	for (int y = 0; y < MAP_LENGTH; ++y) {
		for (int x = 0; x < MAP_WIDE; ++x) {

			if (map_[y][x].state == FLOOR) {
				map_pic_type = FLOOR_PIC;
			}
			else if (map_[y][x].state == GROUND)
				map_pic_type = GROUND_PIC;
			else if (map_[y][x].state == TRANS)
				map_pic_type = TRANS_PIC;
			else if (map_[y][x].state == CONCRETE)
				map_pic_type = CONCRETE_PIC;
			else if (map_[y][x].state == RED_CARPET)
				map_pic_type = RED_CARPET_PIC;
			else if (map_[y][x].state == PRINCE)
				map_pic_type = PRINCE_PIC;
			else if (map_[y][x].state == SPEED_DOWN)
				map_pic_type = SPEED_DOWN_PIC;

			if (map_[y][x].state != AIR &&
				map_[y][x].state != GOAL) {
				drawTextureBox(
					map_[y][x].pos.x(), map_[y][x].pos.y(),
					map_[y][x].size.x(), map_[y][x].size.y(),
					map_[y][x].cut_pos.x(), map_[y][x].cut_pos.y(),
					map_[y][x].cut_size.x(), map_[y][x].cut_size.y(),
					*block_list_[map_pic_type],
					Color::white);
			}

		}
	}

}