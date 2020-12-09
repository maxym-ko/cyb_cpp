//
// Created by maxym_ko on 12/9/20.
//

#ifndef PING_PONG_SERVER_PLAYER_BOARD_H
#define PING_PONG_SERVER_PLAYER_BOARD_H


#include <SFML/Graphics.hpp>
#include "Score.h"

class PlayerBoard {
private:
    unsigned int window_height;
    unsigned int step;
    Score *score;
    unsigned int start_x;
    unsigned int start_y;

    sf::RectangleShape board;
public:
    PlayerBoard(bool enemy, unsigned int window_width, unsigned int window_height,
                unsigned int step, sf::Color color, const sf::Font& font);

    void moveUp();

    void moveDown();

    void draw(sf::RenderWindow &window);

    void reset();

    int getScore();

    void setScore(int score);

    void incrementScore();

    int getX() const;

    int getY() const;

    int getWidth() const;

    int getHeight() const;
};


#endif //PING_PONG_SERVER_PLAYER_BOARD_H
