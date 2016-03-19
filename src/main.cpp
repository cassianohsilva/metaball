//============================================================================
// Name        : Metaballs.cpp
// Author      : Cassiano Honorio da Silva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

void drawCircles(RenderWindow& window) {
	CircleShape c1(10);
	c1.setPosition(10, 10);
	c1.setOutlineColor(Color(0, 0xFF, 0));

	window.draw(c1);
}

int main(void) {

	RenderWindow window(VideoMode(800, 600), "MetaBalls");

	CircleShape c1(100);
	c1.setPosition(100, 100);
	c1.setFillColor(Color(0, 0, 0, 0));
	c1.setOutlineColor(Color(0xFF, 0xFF, 0xFF));
	c1.setOutlineThickness(1);

	CircleShape c2(40);
	c2.setPosition(150, 240);
	c2.setFillColor(Color(0, 0, 0, 0));
	c2.setOutlineColor(Color(0xFF, 0xFF, 0xFF));
	c2.setOutlineThickness(1);

	CircleShape c3(70);
	c3.setPosition(240, 170);
	c3.setFillColor(Color(0, 0, 0, 0));
	c3.setOutlineColor(Color(0xFF, 0xFF, 0xFF));
	c3.setOutlineThickness(1);

	while (window.isOpen()) {
		Event e;

		if (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		window.clear(Color(0, 0, 0));
		//drawCircles(window);
		window.draw(c1);
		window.draw(c2);
		window.draw(c3);
		window.display();
	}

	return EXIT_SUCCESS;
}
