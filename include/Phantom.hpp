#ifndef PHANTOM_H
#define PHANTOM_H value

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Phantom
{
	public:
		Phantom(int id, int limX);
		virtual ~Phantom();

		string toString() const;

		void setId(int id);
		int getId();
		void setLimX(int limX);
		int getLimX();
		void setCollided(bool collided);
		bool isCollided();

		sf::Texture tempImage;
		sf::Sprite phantomSprite;
	private:
		int id;
		int limX;
		bool collided;
};

#endif