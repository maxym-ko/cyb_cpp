//
// Created by maxym_ko on 12/9/20.
//

#ifndef PING_PONG_CLIENT_SCORE_H
#define PING_PONG_CLIENT_SCORE_H


#include <SFML/Graphics.hpp>

class Score {
private:
    int score;
    sf::Text score_text;

public:
    Score(bool enemy, unsigned int window_width, const sf::Font& font);

    void incrementScore();

    void draw(sf::RenderWindow &window);

    int getScore() const;

    void setScore(int score);
};


#endif //PING_PONG_CLIENT_SCORE_H
