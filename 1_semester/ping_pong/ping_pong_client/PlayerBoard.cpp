//
// Created by maxym_ko on 12/9/20.
//

#include <iostream>
#include "PlayerBoard.h"

PlayerBoard::PlayerBoard(bool enemy, unsigned int window_width, unsigned int window_height,
                         unsigned int step, sf::Color color, const sf::Font& font) {
    this->score = new Score(enemy, window_width, font);
    this->window_height = window_height;

    unsigned int board_width = window_width / 32;
    unsigned int board_height = window_height / 5;
    unsigned int padding = board_width / 2;
    start_x = !enemy ? padding : window_width - board_width - padding;
    start_y = (window_height - board_height) / 2;

    board.setPosition(start_x, start_y);
    board.setSize(sf::Vector2f(board_width, board_height));
    board.setFillColor(color);
    this->step = step;
}


void PlayerBoard::moveUp() {
    unsigned int x = board.getPosition().x;
    unsigned int y = board.getPosition().y;

    if (y >= step) board.setPosition(sf::Vector2f(x, y - step));
}

void PlayerBoard::moveDown() {
    unsigned int x = board.getPosition().x;
    unsigned int y = board.getPosition().y;

    if (y + (int) board.getSize().y < window_height) board.setPosition(sf::Vector2f(x, y + step));
}

void PlayerBoard::draw(sf::RenderWindow &window) {
    score->draw(window);
    window.draw(board);
}

void PlayerBoard::reset() {
    board.setPosition(start_x, start_y);
}


int PlayerBoard::getScore() {
    return score->getScore();
}

void PlayerBoard::setScore(int score) {
    this->score->setScore(score);
}


void PlayerBoard::incrementScore() {
    score->incrementScore();
}


int PlayerBoard::getX() const {
    return board.getPosition().x;
}

int PlayerBoard::getY() const {
    return board.getPosition().y;
}

int PlayerBoard::getWidth() const {
    return board.getSize().x;
}

int PlayerBoard::getHeight() const {
    return board.getSize().y;
}
