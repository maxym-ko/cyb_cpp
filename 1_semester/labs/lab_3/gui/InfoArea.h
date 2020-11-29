//
// Created by maxym_ko on 11/27/20.
//

#ifndef LAB_3_INFO_AREA_H
#define LAB_3_INFO_AREA_H


#include <SFML/Graphics.hpp>
#include "Button.h"

class InfoArea {
private:
    float width;
    float height;

    std::string diagram_info;
    std::string hull_info;

    bool visible;

    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;
public:
    InfoArea(float x, float y, float width, float height,
             const sf::Font& font, int text_size);

    void update(ButtonState create_diagram, ButtonState compute_hull);

    void render(sf::RenderTarget &target);
};


#endif //LAB_3_INFO_AREA_H
