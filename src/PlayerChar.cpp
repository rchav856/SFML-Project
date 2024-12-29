#include "PlayerChar.h"


PlayerChar::PlayerChar(const std::filesystem::path& dir) : texture(dir), sprite(texture){
    sprite.setTextureRect({ sf::IntRect({614, 334}, {50,50}) });
    sprite.setOrigin(sprite.getGlobalBounds().getCenter());
}

// Handles movement of any sprite based on user keyboard inputs
void PlayerChar::keyboardMovements() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        sprite.move({ -5,0 });
        sprite.rotate(sf::degrees(-5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        sprite.move({ 5,0 });
        sprite.rotate(sf::degrees(5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        sprite.move({ 0, -5 });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        sprite.move({ 0,5 });
    }
}

void PlayerChar::mouseMovements() {
    sprite.setPosition((sf::Vector2f)(sf::Mouse::getPosition()));
}