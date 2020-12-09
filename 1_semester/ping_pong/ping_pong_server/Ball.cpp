//
// Created by maxym_ko on 12/9/20.
//

#include "Ball.h"

#include <utility>
#include <iostream>

Ball::Ball(PlayerBoard *player_left, PlayerBoard *player_right, float step, sf::Color color,
           unsigned int window_width, unsigned int window_height) : ball(player_left->getWidth() / 2) {
    this->player_left = player_left;
    this->player_right = player_right;
    this->delta_x = -step;
    this->delta_y = -step;
    this->window_width = window_width;
    this->window_height = window_height;
    this->stopped = true;

    start_x = window_width / 2 - ball.getRadius();
    start_y = window_height / 2;

    ball.setPosition(start_x, start_y);
    ball.setFillColor(color);
}

void Ball::reset() {
    stopMove();
    player_left->reset();
    player_right->reset();
    ball.setPosition(start_x, start_y);
}

bool Ball::scored() {
    float ball_x = ball.getPosition().x;
    float ball_y = ball.getPosition().y;
    if ((ball_y > player_left->getY() + player_left->getHeight() || ball_y < player_left->getY()) &&
        ball_x <= player_left->getX() + player_left->getWidth()) {
        player_right->incrementScore();
        return true;
    }
    if ((ball_y > player_right->getY() + player_right->getHeight() || ball_y < player_right->getY()) &&
            ball_x + 2 * ball.getRadius() >= player_right->getX()) {
        player_left->incrementScore();
        return true;
    }
    if (ball.getPosition().x > player_right->getX() + player_right->getWidth()) return true;
    return false;
}

void Ball::move() {
    if (!stopped) {
        if (scored()) {
            reset();
        } else {
            float ball_x = ball.getPosition().x;
            float ball_y = ball.getPosition().y;
            if (ball_y <= 0 || ball_y >= window_height - 2 * ball.getRadius()) {
                delta_y *= -1;
            }
            if (ball_x < player_left->getX() + player_left->getWidth() ||
                ball_x > player_right->getX() - player_right->getWidth()) {
                delta_x += delta_x > 0 ? 0.05 : -0.05;
                delta_y += delta_y > 0 ? 0.05 : -0.05;
                delta_x *= -1;
            }
            ball.setPosition(ball_x + delta_x, ball_y + delta_y);
        }
    }
}

void Ball::draw(sf::RenderWindow &window) {
    window.draw(ball);
}

void Ball::stopMove() {
    stopped = true;
}

void Ball::startMove() {
    stopped = false;
}

float Ball::getX() const {
    return ball.getPosition().x;
}

float Ball::getY() const {
    return ball.getPosition().y;
}

void Ball::setPosition(float x, float y) {
    if (x == start_x && y == start_y) reset();
    ball.setPosition(x, y);
}

