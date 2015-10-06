
#pragma once

#include "Chara.h"


class Player :public Chara {

private:

	CharaDate player_;

public:

	Player(Vec2f);

	Vec2f getPos();
	void setPos(Vec2f);
	Vec2f getSize();

	void setup(int);
	void update();
	void draw();

};
