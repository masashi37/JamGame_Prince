
#include "Scene.h"


//shared_ptrでAppEnvを作成
std::shared_ptr<AppEnv> App::env;

int main() {

	Scene scene;

	//作ったAppEnvに情報を代入
	App::env = 
		std::make_shared<AppEnv>(WIDTH, HEIGHT, false, true);

	scene.setup();

	while (App::env->isOpen()) {

		scene.update();
		scene.shift();

		App::env->begin();

		scene.draw();

		App::env->end();

	}

}
