#include "Character.hpp"

Character::Character(int id, int x, int y, bool user){
	Character::id = id;
	Character::score = 0;
	Character::user = user;
	if (!Character::tempImage.loadFromFile("./img/dragon.png", sf::IntRect(0,0,349,69)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;
    }
    Character::playerSprite.setTexture(Character::tempImage);
    Character::playerSprite.setPosition(x, y);
    Character::arrows = new List();
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

void Character::setUser(bool user){
	Character::user = user;
}

void Character::setArrows(List *arrows){
	Character::arrows = arrows;
}

int Character::getId(){
	return Character::id;
}

int Character::getScore(){
	return Character::score;
}

List *Character::getArrows(){
	return Character::arrows;
}

bool Character::isUser(){
	return Character::user;
}
