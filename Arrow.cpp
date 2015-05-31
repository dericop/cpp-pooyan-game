#include "Arrow.hpp"

Arrow::Arrow(){
}

Arrow::Arrow(int id, int x, int y){
	Arrow::id = id;
	Arrow::x = x;
	Arrow::y = y;
}

Arrow::~Arrow(){
}

string Arrow::toString() const{
	stringstream ss;
	ss << "Id: " << Arrow::id;
	return ss.str();
}

void Arrow::setId(int id){
	Arrow::id = id;
}

void Arrow::setX(int x){
	Arrow::x = x;
}

void Arrow::setY(int y){
	Arrow::y = y;
}

int Arrow::getId(){
	return Arrow::id;
}

int Arrow::getX(){
	return Arrow::x;
}

int Arrow::getY(){
	return Arrow::y;
}
