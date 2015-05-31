#include "Character.hpp"

Character::Character(int id, int score, int x, int y, bool user, List arrows){
	Character::id = id;
	Character::score = score;
	Character::x = x;
	Character::y = y;
	Character::user = user;
	Character::arrows = arrows;
}

Character::Character(int id, int score, int x, int y, bool user){
	Character::id = id;
	Character::score = score;
	Character::x = x;
	Character::y = y;
	Character::user = user;
	Character::arrows;
}

Character::~Character(){
	//delete Character::arrows;
}

string Character::toString() const{
	stringstream sstm;
	sstm << "Id: " << Character::id << "\nScore: " << Character::score << "\nIs user?: " << Character::user;
	return sstm.str();
}

void Character::setId(int id){
	Character::id = id;
}

void Character::setScore(int score){
	Character::score = score;
}

void Character::setX(int x){
	Character::x = x;
}

void Character::setY(int y){
	Character::y = y;
}

void Character::setUser(bool user){
	Character::user = user;
}

void Character::setArrows(const List arrows){
	Character::arrows = arrows;
}

int Character::getId(){
	return Character::id;
}

int Character::getScore(){
	return Character::score;
}

int Character::getX(){
	return Character::x;
}

int Character::getY(){
	return Character::y;
}

List Character::getArrows(){
	return Character::arrows;
}

bool Character::isUser(){
	return Character::user;
}
