#pragma once

#include <SFML/System.hpp>
#include <math.h>

/** compute a vector from an angle and magnitude */
sf::Vector2f vector_from_angle_and_magnitude(float angle, float magnitude) {
    return sf::Vector2f(magnitude * cosf(angle * (M_PI / 180)), magnitude * sinf(angle * (M_PI / 180)));
}

/** compute the angle of a vector, in radians */
float vector_angle(sf::Vector2f v) {
	return atan2f(v.y, v.x);
}

/** compute the magnitude of a vector */
float vector_magnitude(sf::Vector2f v) {
	return sqrtf((v.x * v.x) + (v.y * v.y));
}

/** compute the unit vector of a vector */
sf::Vector2f vector_unit(sf::Vector2f v) {
	return v / vector_magnitude(v);
}
