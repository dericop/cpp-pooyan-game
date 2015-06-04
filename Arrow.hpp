#ifndef ARROW_H
#define ARROW_H value

#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;

class Arrow
{
	public:
		Arrow(int id, int x, int y);
		virtual ~Arrow();

		string toString() const;

		void setId(int id);

		int getId();

		sf::Texture tempImage;
		sf::Sprite arrowSprite;
		sf::CircleShape shape;
	private:
		int id;

};

#endif