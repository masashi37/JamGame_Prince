
#pragma once

#include "AppEnv.h"
#include "Common.h"


class Map {

private:

	enum {
		MAP_LENGTH = 10,
		MAP_WIDE = 120,
	};

	struct MapDate :TextureObject {
		int state;
	};
	MapDate map_[MAP_LENGTH][MAP_WIDE];


	std::ifstream map_type_;


	enum BlockTextureType {
		FLOOR_PIC,
		GROUND_PIC,
		TRANS_PIC,
		CONCRETE_PIC,
		RED_CARPET_PIC,
		PRINCE_PIC,
		SPEED_DOWN_PIC,

		BLOCK_TEXTURE_MAX,
	};
	Texture* block_list_[BLOCK_TEXTURE_MAX];

public:

	Map();

	enum BlockType {
		AIR,
		FLOOR,
		GROUND,
		TRANS,
		CONCRETE,
		RED_CARPET,
		GOAL,
		PRINCE,
		SPEED_DOWN,

		BLOCK_TYPE_MAX,
	};


	Vec2f getPos();
	//int(�X�e�[�^�X�h�c)
	Vec2f getPos(int);
	//int(y�Ԓn), int(x�Ԓn)
	Vec2f getPos(int, int);

	void setPos(Vec2f);
	Vec2f getSize();

	void load();
	void setup();
	void update();
	void draw();

};

