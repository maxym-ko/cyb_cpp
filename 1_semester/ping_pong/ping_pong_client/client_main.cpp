#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "PlayerBoard.h"
#include "Ball.h"

int main() {
    int port = 25123;

    sf::TcpListener listener;

    sf::Socket::Status status = listener.listen(port);
    if (status != sf::Socket::Done) {
        throw std::runtime_error("Listen failed");
    }

    sf::TcpSocket socket;

    std::cout << "Waiting for connection" << std::endl;
    status = listener.accept(socket);
    if (status != sf::Socket::Done) {
        throw std::runtime_error("Accept failed");
    }
    std::cout << "Connected" << std::endl;

    unsigned int width = 850;
    unsigned int height = 500;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 9;

    sf::RenderWindow window(sf::VideoMode(width, height), "Ping Pong client", 7, settings);

    sf::Font font;
    font.loadFromFile("../arial.ttf");
    PlayerBoard *player_me = new PlayerBoard(true, width, height, 10, sf::Color::White, font);
    PlayerBoard *player_enemy = new PlayerBoard(false, width, height, 10, sf::Color::White, font);
    Ball ball(player_enemy, player_me, 10, sf::Color::White, width, height);

    while (window.isOpen()) {
        int moveIndicator = 0;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                    case sf::Keyboard::W:
                        player_me->moveUp();
                        moveIndicator = 1;
                        break;
                    case sf::Keyboard::Down:
                    case sf::Keyboard::S:
                        player_me->moveDown();
                        moveIndicator = -1;
                        break;
                }
            }
        }

        sf::Packet data;
        data << moveIndicator;

        status = socket.send(data);
        if (status != sf::Socket::Done) {
            throw std::runtime_error("Cannot send data");
        }

        sf::SocketSelector selector;
        selector.add(socket);

        if (selector.wait(sf::Time::Zero)) {
            sf::Packet receivedData;
            status = socket.receive(receivedData);
            if (status != sf::Socket::Done && status != sf::Socket::Disconnected) {
                throw std::runtime_error("Cannot receive data");
            }

            int indicator;
            receivedData >> indicator;
            if (indicator == 1) {
                player_enemy->moveUp();
            } else if (indicator == -1) {
                player_enemy->moveDown();
            }

            float ball_x;
            float ball_y;
            receivedData >> ball_x >> ball_y;
            ball.setPosition(ball_x, ball_y);

            int score_my;
            int score_enemy;
            receivedData >> score_enemy >> score_my;
            player_me->setScore(score_my);
            player_enemy->setScore(score_enemy);
        }


        window.clear();

        player_me->draw(window);
        player_enemy->draw(window);
        ball.draw(window);

        window.display();
    }

    socket.disconnect();
    listener.close();

    return 0;
}
