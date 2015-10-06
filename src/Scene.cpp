
#include "Scene.h"


Scene::Scene() {
	scene_changer_ = SceneName::TITLE;
}


void Scene::setup() {
	title.setup();
	select.setup();
	game.setup();
	result.setup();
}

void Scene::update() {

	switch (scene_changer_) {

	case TITLE:
		title.update();
		break;

	case SELECT:
		select.update();
		break;

	case GAME:
		game.update();
		break;

	case RESULT:
		result.update();
		break;

	}

}

void Scene::draw() {

	switch (scene_changer_) {

	case TITLE:
		title.draw();
		break;

	case SELECT:
		select.draw();
		break;

	case GAME:
		game.draw();
		break;

	case RESULT:
		result.draw();
		break;

	}

}

void Scene::shift() {

	switch (scene_changer_) {

	case TITLE:
		if (App::env->isPushKey(GLFW_KEY_ENTER))
			scene_changer_ = title.shift();
		break;

	case SELECT:
		if (App::env->isPushKey(GLFW_KEY_ENTER)) {
			game.setPlayer(select.getSelectChara());
			scene_changer_ = select.shift();
		}
		break;

	case GAME:
		scene_changer_ = game.shift();
		break;

	case RESULT:
		scene_changer_ = result.shift();
		break;

	}

}

