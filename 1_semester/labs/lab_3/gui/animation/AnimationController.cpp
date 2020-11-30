//
// Created by maxym_ko on 11/28/20.
//

#include <ctime>
#include <chrono>
#include <iostream>
#include "AnimationController.h"

float AnimationController::delta_x = 0;
float AnimationController::delta_y = 0;

void AnimationController::drawPoint(float x, float y, float radius, sf::Color color, sf::RenderTarget &window) {
    sf::CircleShape circle(radius);
    circle.setPosition(x + delta_x, y + delta_y);
    circle.setFillColor(color);

    window.draw(circle);
}

void AnimationController::drawLine(Point a, Point b, sf::Color color, sf::RenderTarget &window) {
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(a.getX() + delta_x, a.getY() + delta_y);
    lines[0].color = color;
    lines[1].position = sf::Vector2f(b.getX() + delta_x, b.getY() + delta_y);
    lines[1].color = color;

    window.draw(lines);
}

void
AnimationController::drawPoints(std::vector<Point> points, float radius, sf::Color color, sf::RenderTarget &window) {
    for (Point point : points) {
        drawPoint(point.getX(), point.getY(), radius, color, window);
    }
}


void AnimationController::drawLines(std::vector<Point> points, sf::Color color, sf::RenderTarget &window) {
    for (int i = 0; i < (int) points.size() - 1; i++) {
        AnimationController::drawLine(points[i], points[i + 1], color, window);
    }
}

void AnimationController::removeLine(Point a, Point b, sf::RenderTarget &window) {
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(a.getX() + delta_x, a.getY() + delta_y);
    lines[0].color = sf::Color::Black;
    lines[1].position = sf::Vector2f(b.getX() + delta_x, b.getY() + delta_y);
    lines[1].color = sf::Color::Black;

    window.draw(lines);
}

void AnimationController::animatePoint(float x, float y, float radius, sf::Color color, unsigned int speed, sf::RenderTarget &window) {
    drawPoint(x, y, radius, color, window);
    ((sf::RenderWindow*) &window)->display();
    AnimationController::wait(speed);
}

void AnimationController::animateLine(Point a, Point b, sf::Color color, unsigned int speed, sf::RenderTarget &window) {
    drawLine(a, b, color, window);
    ((sf::RenderWindow*) &window)->display();
    AnimationController::wait(speed);
}

void AnimationController::wait(unsigned int msec) {
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_span{};
    do {
        std::chrono::high_resolution_clock::time_point current = std::chrono::high_resolution_clock::now();
        time_span = current - start;
    } while (time_span.count() < msec);
}