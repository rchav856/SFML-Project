#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

void keyboardMovements(sf::Sprite&);

int main()
{
    // resolution
    const auto SCREEN_WIDTH = 1600, SCREEN_HEIGHT = 800;
    // Main Window Creation
    sf::RenderWindow window(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), "SillyGame", sf::State::Windowed);
    window.setMouseCursorVisible(1);
    window.setFramerateLimit(60);
    // Get ball photo
    sf::Texture blackBallTexture("assets/chars/BlackBall.png");
    // Load ball into sprite
    sf::Sprite ballUser(blackBallTexture);
    ballUser.setTextureRect({ sf::IntRect({614, 334}, {50,50}) }); // grab ball picture
    ballUser.setOrigin(ballUser.getGlobalBounds().getCenter());
    // Set the sprite's position
    ballUser.setPosition({SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f});
    ballUser.setScale({ .8f, .8f });
    
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(ballUser);
        window.display();
        keyboardMovements(ballUser);
    }
}

// Handles movement of any sprite based on user keyboard inputs
void keyboardMovements(sf::Sprite& ballUser) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        ballUser.move({ -5,0 });
        ballUser.rotate(sf::degrees(-5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        ballUser.move({ 5,0 });
        ballUser.rotate(sf::degrees(5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        ballUser.move({ 0, -5 });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        ballUser.move({ 0,5 });
     }
 }