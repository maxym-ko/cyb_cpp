//
// Created by maxym_ko on 11/28/20.
//

#ifndef LAB_3_HULL_INPUT_H
#define LAB_3_HULL_INPUT_H


#include "../SelectionMenu.h"
#include "../animation/AnimationArea.h"
#include "../../geo/Point.h"

class HullWindow {
private:
    SelectionMenu *selection_menu;
    Button *generate_button;
    Button *clear_button;
    Button *back_button;
    bool back_request;
    AnimationArea *animation_area;

    void render(sf::RenderWindow &window);

    void update(sf::RenderWindow &window);

public:
    HullWindow();

    void draw(sf::RenderWindow &window);

    bool backRequest();
};


#endif //LAB_3_HULL_INPUT_H
