//============================================================================
// Name        : Metaballs.cpp
// Author      : Cassiano Honorio da Silva
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define WIDTH 800
#define HEIGHT 600

#define PIXEL_WIDTH 10
#define PIXEL_HEIGHT 10

using namespace sf;

void drawCircles(RenderWindow& window) {
	CircleShape c1(10);
	c1.setPosition(10, 10);
	c1.setOutlineColor(Color(0, 0xFF, 0));

	window.draw(c1);
}

int main(void) {
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "MetaBalls");

	int gridWidth = WIDTH / PIXEL_WIDTH;
	int gridHeight = HEIGHT / PIXEL_HEIGHT;

	Uint8 imageGrid[gridWidth * gridHeight * 4];

	CircleShape c1(100);
	c1.setPosition(100, 100);
	c1.setFillColor(Color(0, 0, 0, 0));
	c1.setOutlineColor(Color(0, 0xFF, 0));
	c1.setOutlineThickness(1);

	CircleShape c2(40);
	c2.setPosition(150, 240);
	c2.setFillColor(Color(0, 0, 0, 0));
	c2.setOutlineColor(Color(0, 0xFF, 0));
	c2.setOutlineThickness(1);

	CircleShape c3(70);
	c3.setPosition(240, 170);
	c3.setFillColor(Color(0, 0, 0, 0));
	c3.setOutlineColor(Color(0, 0xFF, 0));
	c3.setOutlineThickness(1);
	CircleShape circles[] = { c1, c2, c3 };

	Sprite screen;
	Image image;

	for (int iPixelY = 0; iPixelY < gridHeight; ++iPixelY) {
		for (int iPixelX = 0; iPixelX < gridWidth; ++iPixelX) {
			float value = 0.0f;

			for (int iCircle = 0; iCircle < 3; ++iCircle) {
				float r = circles[iCircle].getRadius();
				float x0 = circles[iCircle].getPosition().x + r;
				float y0 = circles[iCircle].getPosition().y + r;

				value += pow(r, 2)
						/ (pow((iPixelX * PIXEL_WIDTH - x0), 2)
								+ pow((iPixelY * PIXEL_HEIGHT - y0), 2));
			}

//			if (grid[iPixelY][iPixelX] > 1.0) {
			if (value > 1.0) {
				imageGrid[iPixelY * gridWidth * 4 + iPixelX * 4 + 0] = 0xff;
				imageGrid[iPixelY * gridWidth * 4 + iPixelX * 4 + 1] = 0xff;
				imageGrid[iPixelY * gridWidth * 4 + iPixelX * 4 + 2] = 0xff;
				imageGrid[iPixelY * gridWidth * 4 + iPixelX * 4 + 3] = 0xff;

			} else {
				imageGrid[iPixelY * gridWidth * 4 + iPixelX * 4 + 0] = 0;
				imageGrid[iPixelY * gridWidth * 4 + iPixelX * 4 + 1] = 0;
				imageGrid[iPixelY * gridWidth * 4 + iPixelX * 4 + 2] = 0;
				imageGrid[iPixelY * gridWidth * 4 + iPixelX * 4 + 3] = 0xff;
			}

//			printf("%d\n", (iPixelY * gridWidth * 4 + iPixelX * 4));
		}
//		printf("\n");
	}

	image.create(gridWidth, gridHeight, imageGrid);

	Texture t;
	t.loadFromImage(image);

	screen.setTexture(t);

	screen.setScale(WIDTH / (float) t.getSize().x,
	HEIGHT / (float) t.getSize().y);

	while (window.isOpen()) {
		Event e;

		if (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
			}
		}

		window.clear(Color(0, 0, 0));
		window.draw(screen);
		window.draw(c1);
		window.draw(c2);
		window.draw(c3);
		window.display();
	}

	return EXIT_SUCCESS;
}
