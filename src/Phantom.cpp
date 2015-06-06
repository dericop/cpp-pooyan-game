#include "Phantom.hpp"

Phantom::Phantom(int id, int limX){
	Phantom::id = id;
	Phantom::limX = limX;
	Phantom::collided = false;
    if(!Phantom::tempImage.loadFromFile("./img/phantomMove.png", sf::IntRect(0,0,80,91))){
        std::cout << "Problema al cargar recurso" << std::endl;
    }
    Phantom::phantomSprite.setTexture(tempImage);
    Phantom::phantomSprite.setPosition(-80,40);
    Phantom::phantomSprite.scale(-0.8f,0.8f);
}

Phantom::~Phantom(){
}

string Phantom::toString() const{
	stringstream ss;
	ss << "Id: " << Phantom::id;
	return ss.str();
}

void Phantom::setId(int id){
	Phantom::id = id;
}

int Phantom::getId(){
	return Phantom::id;
}

void Phantom::setLimX(int limX){
	Phantom::limX=limX;
}
int Phantom::getLimX(){
	return Phantom::limX;
}

void Phantom::setCollided(bool collided){
	Phantom::collided = collided;
}

bool Phantom::isCollided(){
	return Phantom::collided;
}