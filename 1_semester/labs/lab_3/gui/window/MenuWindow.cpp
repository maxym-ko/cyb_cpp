//
// Created by maxym_ko on 11/27/20.
//

#include <iostream>
#include "MenuWindow.h"

MenuWindow::MenuWindow() {
    sf::Font font;
    font.loadFromFile("../arial.ttf");

    create_diagram = new Button(25, 75, 200, 100,
                                font, "Create Voronoi \n      diagram", 25,
                                sf::Color(89, 153, 217),
                                sf::Color(68, 103, 173),
                                sf::Color(42, 53, 110));
    compute_hull = new Button(275, 75, 200, 100,
                              font, "Compute convex\n            hull", 25,
                              sf::Color(89, 153, 217),
                              sf::Color(68, 103, 173),
                              sf::Color(42, 53, 110));
    info_area = new InfoArea(0, 200, 500, 100, font, 15);

//    test_button = new RadioButton(10, 250, 30, font, "Grakham algorithm");
//    test_menu = new SelectionMenu(0, 130, 45, font, "Select algorithm", "Start");
//    test_menu->addItem("1. First");
//    test_menu->addItem("2. Second");
//    test_menu->addItem("3. Third");
//    test_menu->addItem("4. Fourth");
}

void MenuWindow::draw(sf::RenderWindow &window) {
    window.setSize(sf::Vector2u(500, 300));

    create_diagram->update(sf::Vector2f(sf::Mouse::getPosition(window)));
    compute_hull->update(sf::Vector2f(sf::Mouse::getPosition(window)));
    info_area->update(create_diagram->getButtonStatus(), compute_hull->getButtonStatus());

    create_diagram->render(window);
    compute_hull->render(window);
    info_area->render(window);

//    test_button->update(sf::Vector2f(sf::Mouse::getPosition(window)));
//    test_button->render(window);

//    test_menu->update(sf::Vector2f(sf::Mouse::getPosition(window)));
//    test_menu->render(window);
//
//    if (test_menu->started()) {
//        std::cout << test_menu->getSelected() << std::endl;
//    }
}

Action MenuWindow::getSelectedAction() {
    if (create_diagram->wasClicked()) {
        return ACTION_DIAGRAM;
    } else if (compute_hull->wasClicked()) {
        return ACTION_HULL;
    } else {
        return ACTION_NONE;
    }
}
