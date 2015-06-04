#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Character.hpp"

#define ScreenWidth 800
#define ScreenHeight 600

#define sDown 0
#define sUp 0
#define X1 600
#define Y1 400
#define X2 210
#define Y2 250
#define X3 150
#define Y3 400
#define LIM_SUP 180
#define LIM_INF 460

void movMachine(Character *);

Character *players[3];

sf::RenderWindow window(sf::VideoMode(ScreenWidth,ScreenHeight), "POOYAN!");
float velx = 0, vely = 0;
float x = 10, y = 10, moveSpeed = 0.3;
int sourceX = 0, sourceY = sUp;


sf::Texture txtBackground;
sf::Texture tile;
sf::Texture ground;
sf::Sprite spBackground;

sf::Sprite sprite2;
sf::Sprite sprite3;
sf::Sprite sprite4;
sf::Sprite spGround;
sf::Event event;


void initTileMap(){
    
}


void createBalloon()
{
    

    
}

void initPlayers(){
    players[0] = new Character(0, X1, Y1, true);
    players[1] = new Character(1, X2, Y2, false);
    players[2] = new Character(2, X3, Y3, false);

    players[1]->playerSprite.scale(-1.f, 1.f);
    players[2]->playerSprite.scale(-1.f, 1.f);

    /*sf::Thread thCOM1(&movMachine, players[1]);
    //sf::Thread thCOM2(&movMachine, &players[2]);
    thCOM1.launch();*/
//    thCOM2.launch();
}

int main()
{  
    initPlayers();
    
    if (!tile.loadFromFile("./img/tile.png", sf::IntRect(0,0,50,50)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;

    }

    if (!txtBackground.loadFromFile("./img/bg.jpg", sf::IntRect(0,0,800,600)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;
    }

    if (!ground.loadFromFile("./img/tile.png", sf::IntRect(100,100,49,50)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;
    }
    
    
    /*sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(600,200);*/
    
    sprite2.setTexture(tile);
    sprite3.setTexture(tile);
    sprite4.setTexture(tile);
    spGround.setTexture(ground);
    sprite2.setPosition(400,100);

    sprite2.setPosition(200,200);
    sprite3.setPosition(20,100);
    sprite4.setPosition(100,130);
    spGround.setPosition(100,130);
    spBackground.setTexture(txtBackground);

    while (window.isOpen())
    {
        
        while (window.pollEvent(event))
        {

            /*
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
*/

            if(event.type == sf::Event::Closed){
                window.close();
            }

            if (event.key.code == sf::Keyboard::Up)
            {
                if(players[0]->playerSprite.getPosition().y>LIM_SUP){
                    players[0]->playerSprite.move(0,-5);
                    std::cout << "Moviendo" << std::endl;
                    sourceY = sUp;
                    vely = -moveSpeed;
                }
            }else if (event.key.code == sf::Keyboard::Down)
            {
                //if((players[0]->playerSprite.getPosition().y+players[0]->tempImage.getSize().y)<LIM_INF){
                if(players[0]->playerSprite.getPosition().y<LIM_INF){
                    players[0]->playerSprite.move(0,5);
                    std::cout << "Moviendo" << std::endl;
                    sourceY = sDown;
                    vely = moveSpeed;
                }
            }else{
                vely = 0;
                std::cout << "do" << std::endl;
            }

            

            if (event.key.code == sf::Keyboard::Space)
            {
                std::cout << "Plum!!" << std::endl;
                Arrow *a = new Arrow(players[0]->getArrows()->size(), players[0]->playerSprite.getPosition().x, players[0]->playerSprite.getPosition().y);
                players[0]->getArrows()->add(a);
                sf::CircleShape bala(10.f);
                bala.setFillColor(sf::Color::Black);
                bala.setPosition(600,500);
                window.draw(bala);
            }
            
            //break;

        // we don't process other types of events
        //default:
          //  break;
    //}

        }

        sprite2.move(0,0.2);
        sprite3.move(0,0.5);
        sprite4.move(0,0.1);

        /*x+=velx;
        y+=vely;

        std::cout << sourceX<< std::endl;
        
        if (vely!=0)
        {
            sourceX += tempImage.getSize().x/5;
        }

        if (sourceX >= tempImage.getSize().x)
        {
            sourceX = 0;
            std::cout << "Nunca entro" << std::endl;
        }*/


        //window.clear(sf::Color::Blue);


        
        players[0]->playerSprite.setTextureRect(sf::IntRect(sourceX, sourceY, sourceX+players[0]->tempImage.getSize().x/5, 69));
        players[1]->playerSprite.setTextureRect(sf::IntRect(sourceX, sourceY, sourceX+players[1]->tempImage.getSize().x/5, 69));
        players[2]->playerSprite.setTextureRect(sf::IntRect(sourceX, sourceY, sourceX+players[2]->tempImage.getSize().x/5, 69));

        //players[0]->getPlayerSprite().setPosition(x, y);
        window.draw(spBackground);
        //window.draw(sprite2);
        //window.draw(sprite3);
        //window.draw(sprite4);
        window.draw(spGround);
        window.draw(players[0]->playerSprite);
        window.draw(players[1]->playerSprite);
        window.draw(players[2]->playerSprite);
        for(int i = 0; i<players[0]->getArrows()->size();i++){
            Arrow *ar=players[0]->getArrows()->getElementAt(i);
            //ar->arrowSprite.setPosition(ar->arrowSprite.getPosition().x-5,ar->arrowSprite.getPosition().y);
            ar->shape.setPosition(ar->shape.getPosition().x-5,ar->shape.getPosition().y);
            window.draw(ar->shape);
        }
        //window.draw(shape);
        window.display();
    }

    return 0;
}

void movMachine(Character *c){
    /*while (window.isOpen())
    {
        float tShoot;
        
        srand((unsigned)time(0));
        float offset = (rand()%10)-5;
        sf::Time t = sf::seconds(2.f);
        //sf::sleep(t);
        cout << window.isOpen() << endl;
        
    }*/
}