//
// Created by maxym_ko on 11/28/20.
//

#ifndef LAB_3_SELECTION_MENU_H
#define LAB_3_SELECTION_MENU_H


#include "RadioButton.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class SelectionMenu {
private:
    float height;

    sf::Text title;
    sf::Font font;

    std::vector<RadioButton *> buttons;
    RadioButton *selected_button;
    Button *start_button;

public:
    SelectionMenu(float x, float y, float size, const sf::Font &font, const std::string &title,
                  const std::string &btn_msg);

    void addItem(const std::string &title);

    void update(sf::Vector2f mouse_pos);

    void render(sf::RenderTarget &window);

    bool started();

    std::string getSelected();

    float getHeight() const;
};


#endif //LAB_3_SELECTION_MENU_H
