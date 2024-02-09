#include <SedenGL.h>
#include <iostream>

class Example_class : public Seden::App {
public:
	void onInit() override {

	}

	void onUpdate() {

	}

	void onEvent(Seden::Event& ev) {
		if (ev.getEventType()==Seden::MOUSE_PRESSED)
		{
			ev.print();
		}
	}
};



int main() {
	Example_class* app = new Example_class();
	app->start();
	delete app;
}