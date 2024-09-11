#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Array2D.hpp"

using namespace sf;

int main() {
	const int WIDTH = 1920;
	const int HEIGHT = 1080; 
	RenderWindow window(VideoMode(1920,1080), "SFML Works!");
	RectangleShape rect(Vector2f(200, 100));
	rect.setPosition(WIDTH / 2, HEIGHT / 2);
	rect.setFillColor(Color::Green);

	window.setFramerateLimit(120);

	float moveAmt = 2.4;
	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)) {
			if(event.type == Event::Closed) {
				window.close();
			}
		}

		Vector2f dV;
		if(Keyboard::isKeyPressed(Keyboard::A)) {
			dV += Vector2f(-moveAmt, 0);
		}
		if(Keyboard::isKeyPressed(Keyboard::D)) {
			dV += Vector2f(moveAmt, 0);
		}
		if(Keyboard::isKeyPressed(Keyboard::S)) {
			dV += Vector2f(0, moveAmt);
		}
		if(Keyboard::isKeyPressed(Keyboard::W)) {
			dV += Vector2f(0, -moveAmt);
		}

		rect.setPosition(dV + rect.getPosition());

		window.clear();
		window.draw(rect);
		window.display();
	}
	
	return 0;

}
