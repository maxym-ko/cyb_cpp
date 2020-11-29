//
// Created by maxym_ko on 11/27/20.
//

#ifndef LAB_3_BUTTON_H
#define LAB_3_BUTTON_H

#include <SFML/Graphics.hpp>

enum ButtonState {
    BTN_IDLE, BTN_HOVER, BTN_ACTIVE
};

class Button {
protected:
    ButtonState button_state;
    bool is_clicked;
    bool was_clicked;

    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;

    sf::Color idle_color;
    sf::Color hover_color;
    sf::Color active_color;

public:
    Button(float x, float y, float width, float height,
           const sf::Font &font, const std::string &text_msg, int text_size,
           sf::Color idle_color, sf::Color hover_color, sf::Color active_color);

    virtual void update(sf::Vector2f mouse_pos);

    void render(sf::RenderTarget &window);

    void lower(int y);

    bool wasClicked();

    ButtonState getButtonStatus() const;

    std::string getLabel();
};


#endif //LAB_3_BUTTON_H
