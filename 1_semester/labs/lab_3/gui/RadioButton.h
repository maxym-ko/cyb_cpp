//
// Created by maxym_ko on 11/28/20.
//

#ifndef LAB_3_RADIO_BUTTON_H
#define LAB_3_RADIO_BUTTON_H


#include <SFML/Graphics.hpp>
#include "Button.h"

class RadioButton : public Button {
private:
public:
    RadioButton(float x, float y, float size, const sf::Font &font, const std::string &text_msg);

    void update(sf::Vector2f mouse_pos) override;

    bool isActive();

    void disable();
};


#endif //LAB_3_RADIO_BUTTON_H
