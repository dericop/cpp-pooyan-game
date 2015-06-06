#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Phantom.hpp"
#include "Character.hpp"

#define ScreenWidth 800
#define ScreenHeight 600
#define MAX_PHANTOMS 20
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
void colisionPhantom();
void createPhantoms();
void initPlayers();
void createShMem(const char* arg);
bool collision(Phantom *, Arrow *);
void freeShMem();

int shmid;
Character *players[3];
Phantom **phantoms;//[MAX_PHANTOMS];
Arrow arrows[MAX_PHANTOMS];

sf::RenderWindow window(sf::VideoMode(ScreenWidth,ScreenHeight), "POOYAN!");
float velx = 0, vely = 0;
float x = 10, y = 10, moveSpeed = 0.3;
int sourceX = 0, sourceY = sUp;
int flag = 0;

sf::Texture txtBackground;
sf::Sprite spBackground;
sf::Texture txtground;
sf::Sprite spground;

sf::Event event;
sf::Thread *thCOM1;
sf::Thread *thCOM2;
sf::Thread *thPhantoms;
sf::Mutex mutex;


int main(int argc, char const *argv[]){
    srand((unsigned)time(0));
    createShMem(argv[0]);
    initPlayers();

    thCOM1->launch();
    //thCOM2->launch();
    thPhantoms->launch();

    if (!txtBackground.loadFromFile("./img/bg.jpg", sf::IntRect(0,0,800,600)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;
    }

    if (!txtground.loadFromFile("./img/groundOver.png", sf::IntRect(0,0,800,63)))
    {
        std::cout << "Problema al cargar recurso" << std::endl;
    } 
    
    spBackground.setTexture(txtBackground);
    /*spground.setTexture(txtground);
    spground.setPosition(0,(800-63));*/

    while (window.isOpen()){
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
                break;
            }

            if (event.key.code == sf::Keyboard::Up)
            {
                if(players[0]->playerSprite.getPosition().y>LIM_SUP){
                    players[0]->playerSprite.move(0,-5);
                    sourceY = sUp;
                    vely = -moveSpeed;
                }
            }
            else if (event.key.code == sf::Keyboard::Down){
                if(players[0]->playerSprite.getPosition().y<LIM_INF){
                    players[0]->playerSprite.move(0,5);
                    sourceY = sDown;
                    vely = moveSpeed;
                }
            }
            else{
                vely = 0;
            }            

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                if(flag==0){
                    Arrow *a = new Arrow(players[0]->getArrows()->size(), players[0]->playerSprite.getPosition().x, players[0]->playerSprite.getPosition().y);
                    a->arrowSprite.scale(-1.f,1.f);
                    players[0]->getArrows()->add(a);
                    flag = 1;
                }
                else {
                    flag = 0;
                }
            }
        } 

        if(!window.isOpen())
            break;

        window.draw(spBackground);

        for (int i = 0; i<3; i++){
            players[i]->playerSprite.setTextureRect(sf::IntRect(sourceX, sourceY, sourceX+players[i]->tempImage.getSize().x/5, 69));
            window.draw(players[i]->playerSprite); //dibuja personaje

            if(i==0){
                List *l = players[i]->getArrows();
                int tamArrows = l->size();
                if(tamArrows>0){
                    for(int j=0;j<tamArrows;j++){
                        Arrow *ar=l->getElementAt(j);
                        ar->arrowSprite.move(-5,0);
                        
                        /*else{
                            ar->arrowSprite.move(5,0);
                        }*/
                        ar->arrowSprite.setTextureRect(sf::IntRect(0, 0, ar->tempImage.getSize().x/2, 17));
                        for (int k = 0; k<MAX_PHANTOMS;k++){
                            if(phantoms[k]!=NULL && !phantoms[k]->isCollided() && !ar->isCollided()){
                                if(collision(phantoms[k], ar)){
                                    /*l->remove(ar->getId());
                                    tamArrows = l->size();
                                    delete phantoms[k];*/
                                    players[i]->setScore(players[i]->getScore() + 1);
                                    cout << "Jugador " << i << " puntaje " << players[i]->getScore() << endl;
                                    ar->setCollided(true);
                                    phantoms[k]->setCollided(true);
                                }
                                else if(!ar->isCollided()){                          
                                    window.draw(ar->arrowSprite);
                                }
                            }
                        }
                    }
                }
            }
            else{
                for (int j = 0;j<MAX_PHANTOMS;j++){
                    if(arrows[j].getId()==i){
                        arrows[j].arrowSprite.move(5,0);
                        arrows[j].arrowSprite.setTextureRect(sf::IntRect(0, 0, arrows[j].tempImage.getSize().x/2, 17));
                        if(phantoms[j]!=NULL && !phantoms[j]->isCollided() && !arrows[j].isCollided() && collision(phantoms[j], &arrows[j])){
                            players[i]->setScore(players[i]->getScore() + 1);
                            cout << "Jugador " << i << " puntaje " << players[i]->getScore() << endl;
                            arrows[j].setCollided(true);
                            phantoms[j]->setCollided(true);
                        }
                        if(!arrows[j].isCollided()){
                            window.draw(arrows[j].arrowSprite);
                        }
                    }
                }
            }
        }

        colisionPhantom();
        for (int i = 0;i<MAX_PHANTOMS;i++){
            if(phantoms[i]!=NULL && !phantoms[i]->isCollided())
                window.draw(phantoms[i]->phantomSprite);
        }

        window.display();
    }

    freeShMem();
    return 0;
}

void movMachine(Character *c){
    float tShoot = -2.f;
    float tMov = 0;
    int offset = 0;

    while (window.isOpen())
    {
        tMov = (rand()%3);
        offset = (rand()%2);

        if(c->getId()==1){
            cout << "Personaje " << c->getId() << " | tshot-> " << tShoot << endl;
            fflush(stdout);
        }
        if(tShoot<-1){
            tShoot = (rand()%2)+2;
        }
        else if(tShoot>=-1 && tShoot<=0.0){
            //cout << "Personaje " << c->getId() << " | size-> " << c->getArrows()->size() << endl;
            //Arrow *ar = new Arrow(c->getArrows()->size(), c->playerSprite.getPosition().x, c->playerSprite.getPosition().y);
            //cout << ar->getId() << endl;
            //c->getArrows()->add(ar);
            //c->getArrows()->add(new Arrow(c->getArrows()->size(), c->playerSprite.getPosition().x, c->playerSprite.getPosition().y));
            //cout << "Personaje " << c->getId() << " | size-> " << c->getArrows()->size() << endl;
            for(int i=0;i<MAX_PHANTOMS;i++){
                cout << "aquie" << endl;
                if(arrows[i].getId()==0){
                    arrows[i].setId(c->getId());
                    arrows[i].arrowSprite.setPosition(c->playerSprite.getPosition().x, c->playerSprite.getPosition().y);
                    break;
                }
            }
            tShoot = -2;
        }
        tShoot-=0.1;
        /*
        * Movimiento hacia abajo
        */
        if(offset && (c->playerSprite.getPosition().y+(c->tempImage.getSize().y))<LIM_INF){
            for(float i=0.f; i<tMov;i+=0.1){
                c->playerSprite.move(0.f,5);
                sf::Time t = sf::seconds(0.1);
                sf::sleep(t);
            }
        }

        /*
        * Movimiento hacia arriba
        */
        if(!offset && (c->playerSprite.getPosition().y-(c->tempImage.getSize().y))>LIM_SUP){
            for(float i=0.f; i<tMov;i+=0.1){
                c->playerSprite.move(0.f,-5);
                sf::Time t = sf::seconds(0.1);
                sf::sleep(t);
            }            
        }
    }
}

void colisionPhantom(){
    for(int i = 0; i<MAX_PHANTOMS;i++){
        if(phantoms[i]!=NULL){
            if(phantoms[i]->phantomSprite.getPosition().x<phantoms[i]->getLimX()){
                phantoms[i]->phantomSprite.move(1,0);
            }
            else{
                phantoms[i]->phantomSprite.move(0,0.6);
            }
        }
    }
}

void createPhantoms(){
    int r;
    float rf;
    for(int i = 0; i<MAX_PHANTOMS; i++){
        r = (rand()%80)+350;
        phantoms[i] = new Phantom(i,r);
        rf = (rand()%4)+3;
        sf::Time t = sf::seconds(rf);
        sf::sleep(t);
    }
}

void initPlayers(){
    players[0] = new Character(0, X1, Y1, true);
    players[1] = new Character(1, X2, Y2, false);
    players[2] = new Character(2, X3, Y3, false);

    players[1]->playerSprite.scale(-1.f, 1.f);
    players[2]->playerSprite.scale(-1.f, 1.f);

    for (int i = 0;i<MAX_PHANTOMS;i++){
        phantoms[i]=NULL;

    }

    thCOM1 = new sf::Thread(&movMachine, players[1]);
    thCOM2 = new sf::Thread(&movMachine, players[2]);
    thPhantoms = new sf::Thread(&createPhantoms);
}

void createShMem(const char* arg){
    if((shmid=shmget(ftok(arg,'K'), ((sizeof(Phantom*))*MAX_PHANTOMS), 0777 | IPC_CREAT))==-1){
        perror("shmget");
        exit(-1);
    }
    else{
        cout << "Segmento creado" << endl;
    }

    if ((phantoms=((Phantom**)shmat(shmid, 0, 0)))==NULL){
        shmctl(shmid, IPC_RMID, 0);
        perror("shmat");
        exit(1);
    }
    else{
        cout << "Vinculado a la memoria" << endl;
    }
}

bool collision(Phantom *p, Arrow *a){
    sf::FloatRect boundingBoxP = p->phantomSprite.getGlobalBounds();
    sf::FloatRect boundingBoxA = a->arrowSprite.getGlobalBounds();
    
    if(boundingBoxP.intersects(boundingBoxA)){
        return true; 
    }
    return false;
}

void freeShMem(){
    shmdt(phantoms);
    shmctl(shmid, IPC_RMID, 0);
    cout << "Memoria liberada" << endl;
}