#include "Arrow.hpp"

Arrow::Arrow(){
    Arrow::id = 0;
    Arrow::collided = false;
    if (!Arrow::tempImage.loadFromFile("./img/arrow.png", sf::IntRect(0,0,97,17)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;
    }
    Arrow::arrowSprite.setTexture(Arrow::tempImage);
    Arrow::arrowSprite.setPosition(0,0);
}

Arrow::Arrow(int id, int x, int y){
	Arrow::id = id;
    Arrow::collided = false;
	if (!Arrow::tempImage.loadFromFile("./img/arrow.png", sf::IntRect(0,0,97,17)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;
    }
    Arrow::arrowSprite.setTexture(Arrow::tempImage);
    Arrow::arrowSprite.setPosition(x, y);
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

int Arrow::getId(){
	return Arrow::id;
}

void Arrow::setCollided(bool collided){
    Arrow::collided = collided;
}

bool Arrow::isCollided(){
    return Arrow::collided;
}