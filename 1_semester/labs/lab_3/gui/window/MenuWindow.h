//
// Created by maxym_ko on 11/27/20.
//

#ifndef LAB_3_MENUWINDOW_H
#define LAB_3_MENUWINDOW_H


#include "../SelectionMenu.h"
#include "../InfoArea.h"

enum Action {
    ACTION_NONE, ACTION_DIAGRAM, ACTION_HULL
};

class MenuWindow {
private:
    Button *create_diagram;
    Button *compute_hull;
    Button *test_button;
    SelectionMenu *test_menu;
    InfoArea *info_area;
public:
    MenuWindow();

    void draw(sf::RenderWindow &window);

    Action getSelectedAction();
};


#endif //LAB_3_MENUWINDOW_H
