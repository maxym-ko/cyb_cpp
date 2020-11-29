//
// Created by maxym_ko on 11/27/20.
//

#include "InfoArea.h"
#include "Button.h"

InfoArea::InfoArea(float x, float y, float width, float height, const sf::Font &font,
                   int text_size) {
    diagram_info = "Fortune's algorithm is available to create Voronoi diagram.\n"
                   "Delaunay triangulation is available to triangulate Voronoi diagram";
    hull_info = "You can compute convex hull using next algorithms:\n"
                "1) Kirkpatrick-Seidel algorithm\n"
                "2) Jarvis-Andrew algorithm\n"
                "3) Graham scan\n"
                "4) Recursive algorithm\n";

    visible = false;

    shape.setPosition(sf::Vector2f(x, y));
    this->width = width;
    this->height = height;
    shape.setSize(sf::Vector2f(0, 0));

    this->font = font;
    text.setFont(this->font);
    text.setString("");
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(text_size);
    text.setPosition(
            shape.getPosition().x + 10,
            shape.getPosition().y + 5
    );

    shape.setFillColor(sf::Color(255, 255, 255, 200));
}

void InfoArea::update(ButtonState create_diagram, ButtonState compute_hull) {
    if (create_diagram != BTN_IDLE) {
        shape.setSize(sf::Vector2f(width, height));
        text.setString(diagram_info);
    } else if (compute_hull != BTN_IDLE) {
        shape.setSize(sf::Vector2f(width, height));
        text.setString(hull_info);
    } else {
        shape.setSize(sf::Vector2f(0, 0));
        text.setString("");
    }
}

void InfoArea::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(text);
}