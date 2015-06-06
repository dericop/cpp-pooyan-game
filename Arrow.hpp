#ifndef ARROW_H
#define ARROW_H value

#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Arrow
{
	public:
		Arrow();
		Arrow(int id, int x, int y);
		virtual ~Arrow();

		string toString() const;

		void setId(int id);
		int getId();
		void setCollided(bool collided);
		bool isCollided();

		sf::Texture tempImage;
		sf::Sprite arrowSprite;
	private:
		int id;
		bool collided;
};

#endif