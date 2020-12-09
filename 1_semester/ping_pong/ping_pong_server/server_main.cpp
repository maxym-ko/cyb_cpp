#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "PlayerBoard.h"
#include "Ball.h"

int main() {
    std::string address("127.0.0.1");
    int port = 25123;

    sf::TcpSocket socket;

    sf::Socket::Status status = socket.connect(address, port);
    if (status != sf::Socket::Done) {
        throw std::runtime_error("Connection failed");
    }

    unsigned int width = 850;
    unsigned int height = 500;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 9;

    sf::RenderWindow window(sf::VideoMode(width, height), "Ping Pong server", 7, settings);

    sf::Font font;
    font.loadFromFile("../arial.ttf");
    PlayerBoard *player_me = new PlayerBoard(false, width, height, 10, sf::Color::White, font);
    PlayerBoard *player_enemy = new PlayerBoard(true, width, height, 10, sf::Color::White, font);
    Ball ball(player_me, player_enemy, 0.4, sf::Color::White, width, height);

    while (window.isOpen()) {
        int moveIndicator = 0;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                ball.startMove();
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
        data << moveIndicator << ball.getX() << ball.getY() << player_me->getScore() << player_enemy->getScore();

        status = socket.send(data);
        if (status != sf::Socket::Done) {
            throw std::runtime_error("Cannot send data");
        }

        ball.move();

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
                ball.startMove();
                player_enemy->moveUp();
            } else if (indicator == -1) {
                ball.startMove();
                player_enemy->moveDown();
            }

        }


        window.clear();

        player_me->draw(window);
        player_enemy->draw(window);
        ball.draw(window);

        window.display();
    }

    socket.disconnect();

    return 0;
}