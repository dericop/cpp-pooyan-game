#ifndef CHARACTER_H
#define CHARACTER_H value

#include "List.hpp"

class Character
{
	public:
		Character(int id, int score, int x, int y, bool user, List arrows);
		Character(int id, int score, int x, int y, bool user);
		virtual ~Character();

		string toString() const;

		void setId(int id);
		void setScore(int score);
		void setX(int x);
		void setY(int y);
		void setUser(bool user);
		void setArrows(List arrows);
		int getId();
		int getScore();
		int getX();
		int getY();
		List getArrows();
		bool isUser();

	private:
		int id;
		int score;
		int x;
		int y;
		bool user;
		List arrows;
};

#endif