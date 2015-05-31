#include "Balloon.hpp"

Balloon::Balloon(int id, int x, int y){
	Balloon::id = id;
	Balloon::x = x;
	Balloon::y = y;
}

Balloon::~Balloon(){
}

string Balloon::toString() const{
	stringstream ss;
	ss << "Id: " << Balloon::id;
	return ss.str();
}

void Balloon::setId(int id){
	Balloon::id = id;
}

void Balloon::setX(int x){
	Balloon::x = x;
}

void Balloon::setY(int y){
	Balloon::y = y;
}

int Balloon::getId(){
	return Balloon::id;
}

int Balloon::getX(){
	return Balloon::x;
}

int Balloon::getY(){
	return Balloon::y;
}
