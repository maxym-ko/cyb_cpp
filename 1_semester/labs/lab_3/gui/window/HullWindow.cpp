//
// Created by maxym_ko on 11/28/20.
//

#include <iostream>
#include "HullWindow.h"
#include "../../algorithm/JarvisAndrewAlgorithm.h"
#include "../../algorithm/JarvisAndrewAlgorithm.h"

HullWindow::HullWindow() {
    sf::Font font;
    font.loadFromFile("../arial.ttf");

    selection_menu = new SelectionMenu(10, 10, 45, font, "Select algorithm", "Start");
    selection_menu->addItem("1. Kirkpatrick-Seidel algorithm");
    selection_menu->addItem("2. Jarvis-Andrew algorithm");
    selection_menu->addItem("3. Graham scan");
    selection_menu->addItem("4. Recursive algorithm");

    generate_button = new Button(20, selection_menu->getHeight() + 420, 125, 45,
                                 font, "Generate", 25,
                                 sf::Color(89, 153, 217),
                                 sf::Color(68, 103, 173),
                                 sf::Color(42, 53, 110));

    clear_button = new Button(160, selection_menu->getHeight() + 420, 100, 45,
                              font, "Clear", 25,
                              sf::Color(89, 153, 217),
                              sf::Color(68, 103, 173),
                              sf::Color(42, 53, 110));

    back_button = new Button(270, selection_menu->getHeight() + 420, 70, 45,
                             font, "Back", 25,
                             sf::Color(89, 153, 217),
                             sf::Color(68, 103, 173),
                             sf::Color(42, 53, 110));
    back_request = false;

    animation_area = new AnimationArea(360, 25, 900, 600, sf::Color::Red, sf::Color::Black, 2);
}

void HullWindow::render(sf::RenderWindow &window) {
    window.setSize(sf::Vector2u(1280, 650));

    selection_menu->render(window);
    generate_button->render(window);
    clear_button->render(window);
    back_button->render(window);
    animation_area->render(window);

    if (selection_menu->started()) {
        std::string selected_algorithm = selection_menu->getSelected();
        animation_area->start(selected_algorithm, window);
    }

}

void HullWindow::update(sf::RenderWindow &window) {
    selection_menu->update(sf::Vector2f(sf::Mouse::getPosition(window)));
    generate_button->update(sf::Vector2f(sf::Mouse::getPosition(window)));
    clear_button->update(sf::Vector2f(sf::Mouse::getPosition(window)));
    back_button->update(sf::Vector2f(sf::Mouse::getPosition(window)));
    animation_area->update(sf::Vector2f(sf::Mouse::getPosition(window)));

    if (generate_button->wasClicked()) {
        animation_area->generate();
    }

    if (clear_button->wasClicked()) {
        animation_area->clear();
    }

    if (back_button->wasClicked()) {
        back_request = true;
    }
}

void HullWindow::draw(sf::RenderWindow &window) {
    update(window);
    render(window);
}

bool HullWindow::backRequest() {
    bool res = back_request;
    back_request = false;
    return res;
}
