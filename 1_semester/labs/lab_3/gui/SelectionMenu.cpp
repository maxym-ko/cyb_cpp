//
// Created by maxym_ko on 11/28/20.
//

#include <iostream>
#include "SelectionMenu.h"

SelectionMenu::SelectionMenu(float x, float y, float size, const sf::Font &font, const std::string &title_msg,
                             const std::string &btn_msg) {
    selected_button = nullptr;

    this->font = font;
    title.setFont(this->font);
    title.setString(title_msg);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize((int) (size * 0.7f));
    title.setPosition(x + 10, y + 10);

    start_button = new Button(x + 10, y + size + 20, 100, size,
                              this->font, btn_msg, (int) size / 2,
                              sf::Color(89, 153, 217),
                              sf::Color(68, 103, 173),
                              sf::Color(42, 53, 110));

    height = title.getGlobalBounds().height + size;
}

void SelectionMenu::addItem(const std::string &title_msg) {
    int font_size = (int) (title.getCharacterSize() * 5 / 7);
    buttons.push_back(new RadioButton(
            title.getPosition().x + 5,
            title.getPosition().y + title.getGlobalBounds().height * 2.f + (float) (buttons.size() * (font_size + 10)),
            (float) font_size, font, title_msg));
    start_button->lower((int) (font_size + 10));

    height += (float) font_size;
}

void SelectionMenu::update(sf::Vector2f mouse_pos) {
    for (RadioButton *button : buttons) {
        button->update(mouse_pos);
    }

    // leave only one selected button
    if (selected_button != nullptr && !selected_button->isActive()) selected_button = nullptr;
    for (RadioButton *button : buttons) {
        if (button->isActive() && selected_button != button) {
            if (selected_button != nullptr) selected_button->disable();
            selected_button = button;
        }
    }

    start_button->update(mouse_pos);
}

void SelectionMenu::render(sf::RenderTarget &window) {
    window.draw(title);
    for (RadioButton *button : buttons) {
        button->render(window);
    }
    start_button->render(window);
}

std::string SelectionMenu::getSelected() {
    return selected_button == nullptr ? std::string("none") : selected_button->getLabel();
}

bool SelectionMenu::started() {
    return start_button->wasClicked();
}

float SelectionMenu::getHeight() const {
    return height;
}
