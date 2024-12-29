#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include "PlayerChar.h"

// Methods
void checkEvents(sf::RenderWindow& window);
// Get the user's profile directory
const char* userProfile = std::getenv("USERPROFILE");
// Construct the full path for sprites
std::filesystem::path worldPath = std::filesystem::path(userProfile) / "source\\repos\\SFML-Project\\src\\assets\\world";
std::filesystem::path charPath = std::filesystem::path(userProfile) / "source\\repos\\SFML-Project\\src\\assets\\chars";

// random number generators for screen in 1600 x 800
std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr))); // Seed with time
std::uniform_real_distribution<float> distX(0.0f, 1600.0f); // Range for x-axis
std::uniform_real_distribution<float> distY(0.0f, 800.0f);  // Range for y-axis

// resolution
const auto SCREEN_WIDTH = 1600, SCREEN_HEIGHT = 800;
const sf::Vector2f SMALL_RECT_SIZE = { 5,20 }, MEDIUM_RECT_SIZE = { 25,100 }, LARGE_RECT_SIZE = { 125, 500};
sf::Vector2f SCREEN_CENTER = { 1600 / 2.f, 800 / 2.f };



int main()
{   
    if (!userProfile) {
        std::cerr << "Error: USERPROFILE environment variable not found." << std::endl;
        return -1;
    }
    // Main Window Creation
    sf::RenderWindow window(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), "SillyGame", sf::Style::Default);
    window.setMouseCursorVisible(0);
    window.setFramerateLimit(60);
    // Textures
    sf::Texture skyTexture(worldPath / "wallpaperflare.com_wallpaper.png");
    // Sprites
	sf::Sprite skySprite(skyTexture);
    sf::RectangleShape rect1(MEDIUM_RECT_SIZE);
    rect1.setOrigin(rect1.getGeometricCenter());
	rect1.setFillColor(sf::Color::Red);
    rect1.setPosition({distX(rng), distY(rng)});
    PlayerChar player(charPath / "BlackBall.png");


  
    while (window.isOpen())
    {
        window.clear(sf::Color::White);
		window.draw(skySprite);
        window.draw(player.getSprite());
        //window.draw(ballUser);
		window.draw(rect1);
        window.display();
		player.keyboardMovements();
        player.mouseMovements();
        sf::FloatRect rect1Bounds = rect1.getGlobalBounds();
        sf::FloatRect ballBounds = player.getSprite().getGlobalBounds();
        if (const std::optional intersection = ballBounds.findIntersection(rect1Bounds)) {
            std::cout << player.getSprite().getGlobalBounds().position.x << " " << player.getSprite().getGlobalBounds().position.y << std::endl;
        }
        checkEvents(window);
    }
}

// Handles events on user input
void checkEvents(sf::RenderWindow& window) {
    while (const std::optional event = window.pollEvent()) {
        // Events to close window
        if (event->is<sf::Event::Closed>() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();
    }
}