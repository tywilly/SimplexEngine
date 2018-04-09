#include <iostream>

#include <gl/glew.h>

#include "glfw/glfw3.h"

#include "SimplexEngine.h"

class Main : public SimplexEngine{

public:
	void onStartup() {

	};
	void onShutdown() {

	};

};

int main(const char* argv, int argc) {

	Main mainClass = Main();

	return mainClass.startEngine();
}