#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "algorithm/KirkpatrickSeidelAlgorithm.h"
#include "geo/Point.h"
#include "algorithm/JarvisAndrewAlgorithm.h"
#include "gui/Button.h"
#include "gui/window/MenuWindow.h"
#include "gui/window/HullWindow.h"

using namespace std;

static const int START_WIDTH = 500;
static const int START_HEIGHT = 300;
static const int WIDTH = 1280;
static const int HEIGHT = 720;
static const int MARGIN = 100;

enum State {
    MENU, DIAGRAM, HULL
};

int main() {
    State current_state = State::MENU;

    sf::RenderWindow window(sf::VideoMode(START_WIDTH, START_HEIGHT), "LAB_3");
    MenuWindow menu;
    HullWindow hull_input;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized: {
                    sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    break;
                }
                case sf::Event::MouseButtonReleased: {
                    Action selected_action = menu.getSelectedAction();
                    if (selected_action == ACTION_DIAGRAM) {
                        current_state = DIAGRAM;
                    } else if (selected_action == ACTION_HULL) {
                        current_state = HULL;
                    } else if (hull_input.backRequest()) {
                        current_state = MENU;
                    }
                    break;
                }
            }
        }

        window.clear();
        switch (current_state) {
            case MENU:
                menu.draw(window);
                break;
            case HULL:
                hull_input.draw(window);
                break;
            default:
                break;
        }

        window.display();
    }

    return 0;
}