
#pragma once

#include "lib/framework.hpp"
#include <memory>


class App {

public:

	App();

	static std::shared_ptr<AppEnv> env;

};
