#include <SedenGL.h>
#include <iostream>

class Example_class : public Seden::App {
public:
	void onInit() override {

	}
};

int main() {
	Example_class* app = new Example_class();
	app->start();
	delete app;
}