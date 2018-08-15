#include <SDBGUI_math.h>
#include <math.h>
double Distance(sf::Vector2f v1, sf::Vector2f v2)
{
    return std::sqrt((v1.x - v2.x)*(v1.x - v2.x) + (v1.y - v2.y)*(v1.y - v2.y));
}

sf::Vector2f RotatePointOf(sf::Vector2f point, sf::Vector2f center, double angle)
{

    sf::Vector2f new_point;
    new_point.x = (point.x - center.x) * cos(angle) - (point.y - center.y) * sin(angle);
    new_point.y = (point.y - center.y) * cos(angle) + (point.x - center.x) * sin(angle);
    new_point += center;
    return new_point;
}
