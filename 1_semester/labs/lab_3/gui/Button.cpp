//
// Created by maxym_ko on 11/27/20.
//

#include <iostream>
#include "Button.h"

Button::Button(float x, float y, float width, float height, const sf::Font &font, const std::string &text_msg,
               int text_size,
               sf::Color idle_color, sf::Color hover_color, sf::Color active_color) {
    is_clicked = false;
    was_clicked = false;
    button_state = BTN_IDLE;

    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));

    this->font = font;
    text.setFont(this->font);
    text.setString(text_msg);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(text_size);
    text.setPosition(
            shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) -
            text.getGlobalBounds().width / 2.f,
            shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) -
            text.getGlobalBounds().height / 2.f - text_size / 3.5f
    );

    this->idle_color = idle_color;
    this->hover_color = hover_color;
    this->active_color = active_color;

    shape.setFillColor(idle_color);
}

void Button::update(const sf::Vector2f mouse_pos) {
    /*Update the booleans for hover and pressed*/
    //Idle
    button_state = BTN_IDLE;

    //Hover
    if (shape.getGlobalBounds().contains(mouse_pos)) {
        button_state = BTN_HOVER;

        //Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (!is_clicked) {
                button_state = BTN_ACTIVE;
                was_clicked = true;
            }
            is_clicked = true;
        } else {
            is_clicked = false;
        }
    } else {
        is_clicked = false;
    }

    switch (button_state) {
        case BTN_IDLE:
            shape.setFillColor(idle_color);
            break;

        case BTN_HOVER:
            shape.setFillColor(hover_color);
            break;

        case BTN_ACTIVE:
            shape.setFillColor(active_color);
            break;

        default:
            shape.setFillColor(sf::Color::Red);
            break;
    }
}

void Button::render(sf::RenderTarget &window) {
    window.draw(shape);
    window.draw(text);
}

void Button::lower(int y) {
    shape.setPosition(shape.getPosition().x, shape.getPosition().y + y);
    text.setPosition(text.getPosition().x, text.getPosition().y + y);
}

bool Button::wasClicked() {
    bool res = was_clicked;
    was_clicked = false;
    return res;
}

ButtonState Button::getButtonStatus() const {
    return button_state;
}

std::string Button::getLabel() {
    return text.getString().toAnsiString();
}