#pragma once

#include <SFML/Graphics.hpp>

#define _USE_MATH_DEFINES
#include <math.h>

float speed = 25;
float turnspeed = 5;

sf::Vector2f vector_from_angle_and_magnitude(float angle, float magnitude) {
    return sf::Vector2f(magnitude * cosf(angle * (M_PI / 180)), magnitude * sinf(angle * (M_PI / 180)));
}

void controller(sf::Sprite &car)
{
    bool keyA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool keyD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool keyW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool keyS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    if (keyA && keyW) {
        car.setRotation(car.getRotation() - turnspeed);
    }
    if (keyD && keyW) {
        car.setRotation(car.getRotation() + turnspeed);
    }

    if (keyA && keyS) {
        car.setRotation(car.getRotation() + turnspeed);
    }
    if (keyD && keyS) {
        car.setRotation(car.getRotation() - turnspeed);
    }

    if (keyW) {
        car.setPosition(car.getPosition() + vector_from_angle_and_magnitude(car.getRotation(), speed));
    }
    if (keyS) {
        car.setPosition(car.getPosition() - vector_from_angle_and_magnitude(car.getRotation(), speed));
    }
}
