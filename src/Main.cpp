#include <iostream>

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "SimplexEngine.h"

class Main : public SimplexEngine{

public:
	void onStartup() {

	};
	void onShutdown() {

	};

};

int main( int argc, const char** argv) {

	Main mainClass = Main();

	return mainClass.startEngine();
}
