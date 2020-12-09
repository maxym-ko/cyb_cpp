//
// Created by maxym_ko on 12/9/20.
//

#include <iostream>
#include "Score.h"

Score::Score(bool enemy, unsigned int window_width, const sf::Font& font) {
    score = 0;
    score_text.setFont(font);
    score_text.setString(std::to_string(score));
    score_text.setFillColor(sf::Color::White);
    score_text.setCharacterSize(window_width / 16);
    unsigned int score_x = !enemy ? window_width / 2 - window_width / 8 : window_width / 2 + window_width / 10;
    unsigned int score_y = window_width / 64;
    score_text.setPosition(sf::Vector2f(score_x, score_y));
}

void Score::incrementScore() {
    score++;
    score_text.setString(std::to_string(score));
}

void Score::draw(sf::RenderWindow &window) {
    window.draw(score_text);
}

int Score::getScore() const {
    return score;
}

void Score::setScore(int score) {
    this->score = score;
    score_text.setString(std::to_string(score));
}
