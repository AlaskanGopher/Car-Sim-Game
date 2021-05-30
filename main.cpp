#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "controller.h"
#include "proceduralGenerate.h"

sf::Sprite road[MAP_SIZE][MAP_SIZE];

int main()
{
    // Window
    sf::RenderWindow window(sf::VideoMode(1200, 960), "SFML works!");
    sf::View carView;
    unsigned int carViewScale = 1;

    // Clock
    sf::Clock gameTime;

    // Framerate
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // Car
    sf::Texture carText;
    if (!carText.loadFromFile("sprites/car.png")){}
    sf::Sprite car;
    car.setTexture(carText);
    car.setScale(0.05f, 0.05f);
    car.setOrigin(car.getLocalBounds().width / 2, car.getLocalBounds().height / 2);
    car.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    // ---

    // --- ROADS ---
    sf::Texture roadText[120];
    if (!roadText[0].loadFromFile("sprites/roadEW.png")) {}
    if (!roadText[1].loadFromFile("sprites/roadSE.png")) {}
    if (!roadText[2].loadFromFile("sprites/roadNEWS.png")) {}
    if (!roadText[3].loadFromFile("sprites/roadNS.png")) {}
    if (!roadText[4].loadFromFile("sprites/roadSW.png")) {}
    if (!roadText[5].loadFromFile("sprites/roadPLAZA.png")) {}
    if (!roadText[6].loadFromFile("sprites/roadNE.png")) {}
    if (!roadText[7].loadFromFile("sprites/roadNW.png")) {}
    if (!roadText[8].loadFromFile("sprites/roadTE.png")) {}
    if (!roadText[9].loadFromFile("sprites/roadTS.png")) {}
    if (!roadText[10].loadFromFile("sprites/roadTN.png")) {}
    if (!roadText[11].loadFromFile("sprites/roadTW.png")) {}
    for (int i = 0; i < 11; i++)
    {
        roadText[i].generateMipmap();
        roadText[i].setSmooth(true);
    }
    // --- ----- ---
    // --- BUILDINGS ---
    if (!roadText[100].loadFromFile("sprites/facade00.png")) {}
    if (!roadText[101].loadFromFile("sprites/facade01.png")) {}
    if (!roadText[102].loadFromFile("sprites/facade02.png")) {}
    if (!roadText[103].loadFromFile("sprites/facade03.png")) {}
    if (!roadText[104].loadFromFile("sprites/facade04.png")) {}
    if (!roadText[105].loadFromFile("sprites/facade05.png")) {}
    if (!roadText[106].loadFromFile("sprites/facade06.png")) {}
    if (!roadText[107].loadFromFile("sprites/facade07.png")) {}
    if (!roadText[108].loadFromFile("sprites/facade08.png")) {}
    if (!roadText[109].loadFromFile("sprites/facade09.png")) {}
    if (!roadText[110].loadFromFile("sprites/facade10.png")) {}
    if (!roadText[111].loadFromFile("sprites/facade11.png")) {}
    if (!roadText[112].loadFromFile("sprites/facade12.png")) {}
    if (!roadText[113].loadFromFile("sprites/facade13.png")) {}
    if (!roadText[114].loadFromFile("sprites/facade14.png")) {}
    if (!roadText[115].loadFromFile("sprites/facade15.png")) {}
    if (!roadText[116].loadFromFile("sprites/facade16.png")) {}
    // --- --------- ---
    generateMap();
    for (int mx = 0; mx < MAP_SIZE; mx++)
    {
        for (int my = 0; my < MAP_SIZE; my++)
        {
            road[mx][my].setTexture(roadText[gmap[mx][my]]);
            //road[mx][my].setScale(sf::Vector2f(0.25, 0.25));
            road[mx][my].setPosition(256 * mx, 256 * my);
        }
    }
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Dash)
                carViewScale++;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Equal)
                carViewScale--;
        }

        if (carViewScale < 1)
        {
            carViewScale = 1;
        } else if (carViewScale > 20)
        {
            carViewScale = 20;
        }

        controller(car);

        carView.setRotation(car.getRotation() + 90);
        carView.setCenter(car.getPosition());
        carView.setSize(sf::Vector2f(window.getSize() * carViewScale));
        window.setView(carView);


        window.clear();
        for (int mx = 0; mx < MAP_SIZE; mx++)
        {
            for (int my = 0; my < MAP_SIZE; my++)
            {
                window.draw(road[mx][my]);
            }
        }
        window.draw(car);

        window.display();
    }

    return 0;
}