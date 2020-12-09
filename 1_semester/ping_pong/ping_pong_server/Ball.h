//
// Created by maxym_ko on 12/9/20.
//

#ifndef PING_PONG_SERVER_BALL_H
#define PING_PONG_SERVER_BALL_H


#include <SFML/Graphics.hpp>
#include "PlayerBoard.h"

class Ball {
private:
    PlayerBoard *player_left;
    PlayerBoard *player_right;
    float start_x;
    float start_y;
    float delta_y;
    float delta_x;
    unsigned int window_width;
    unsigned int window_height;
    bool stopped;

    sf::CircleShape ball;

    void reset();

    bool scored();
public:
    Ball(PlayerBoard *player_left, PlayerBoard *player_right, float step, sf::Color color,
         unsigned int window_width, unsigned int window_height);

    void move();

    void draw(sf::RenderWindow &window);

    void stopMove();

    void startMove();

    float getX() const;

    float getY() const;

    void setPosition(float x, float y);
};


#endif //PING_PONG_SERVER_BALL_H
