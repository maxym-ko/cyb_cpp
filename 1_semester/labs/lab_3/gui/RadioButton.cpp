//
// Created by maxym_ko on 11/28/20.
//

#include <iostream>
#include "RadioButton.h"

RadioButton::RadioButton(float x, float y, float size, const sf::Font &font, const std::string &text_msg) :
        Button(x, y, size / 2, size / 2, font, text_msg, (int) size, sf::Color::Black, sf::Color::Black, sf::Color::Green) {
    text.setPosition(x + size / 2 + 10, y - size / 2.4f);
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2);
}

void RadioButton::update(sf::Vector2f mouse_pos) {
    if (shape.getGlobalBounds().contains(mouse_pos)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            was_clicked = true;
        } else {
            if (was_clicked && button_state == BTN_ACTIVE) {
                button_state = BTN_IDLE;
            } else if (was_clicked && button_state == BTN_IDLE) {
                button_state = BTN_ACTIVE;
            }
            was_clicked = false;
        }
    }

    switch (button_state) {
        case BTN_IDLE:
            shape.setFillColor(idle_color);
            break;

        case BTN_ACTIVE:
            shape.setFillColor(active_color);
            break;

        default:
            shape.setFillColor(sf::Color::Red);
            break;
    }
}

bool RadioButton::isActive() {
    return button_state == BTN_ACTIVE;
}

void RadioButton::disable() {
    was_clicked = false;
    button_state = BTN_IDLE;
}
