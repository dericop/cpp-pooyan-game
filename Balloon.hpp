#ifndef BALLOON_H
#define BALLOON_H value

#include <string>
#include <sstream>

using namespace std;

class Balloon
{
	public:
		Balloon(int id, int x, int y);
		virtual ~Balloon();

		string toString() const;

		void setId(int id);
		void setX(int x);
		void setY(int y);
		int getId();
		int getX();
		int getY();

	private:
		int id;
		int x;
		int y;
};

#endif