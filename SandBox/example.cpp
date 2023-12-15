#include <SedenGL.h>

class Example_class : public Seden::App {
};

int main() {
	Example_class* app = new Example_class();
	app->init();
	delete app;
}