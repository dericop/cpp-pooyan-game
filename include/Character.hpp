#ifndef CHARACTER_H
#define CHARACTER_H value

#include "List.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

class Character
{
	public:
		Character(int id, int x, int y, bool user);
		virtual ~Character();

		string toString() const;

		void setId(int id);
		void setScore(int score);
		void setUser(bool user);
		void setArrows(List *arrows);
		int getId();
		int getScore();
		List *getArrows();
		bool isUser();

		sf::Texture tempImage;
		sf::Sprite playerSprite;
	private:
		int id;
		int score;
		bool user;
		List *arrows;
};

#endif