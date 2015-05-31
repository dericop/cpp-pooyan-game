#ifndef ARROW_H
#define ARROW_H value

#include <string>
#include <sstream>

using namespace std;

class Arrow
{
	public:
		Arrow();
		Arrow(int id, int x, int y);
		virtual ~Arrow();

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