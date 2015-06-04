#include "Arrow.hpp"

Arrow::Arrow(int id, int x, int y){
	Arrow::id = id;
	/*if (!Arrow::tempImage.loadFromFile("./img/.png", sf::IntRect(0,0,349,69)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;
    }*/
    //Arrow::arrowSprite.setTexture(Arrow::tempImage);
    //Arrow::shape.setDiameter(10.f);
    sf::CircleShape shape(10.f);
    Arrow::shape = shape;
    Arrow::arrowSprite.setPosition(x, y);
    Arrow::shape.setFillColor(sf::Color::Black);
    Arrow::shape.setPosition(x,y);
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
