#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>
#include <cmath>

/*
class UserBall {
    public:
	    UserBall(sf::Sprite& ballUser) : ballUser(ballUser) {}
	    void moveBall() {
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
			    ballUser.move({ -2,0 });
			    ballUser.rotate(sf::degrees(-5));
		    }
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
			    ballUser.move({ 2,0 });
			    ballUser.rotate(sf::degrees(5));
		    }
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			    ballUser.move({ 0, -2 });
		    }
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			    ballUser.move({ 0,2 });
		    }
	};*/

void keyboardMovements(sf::Sprite&);
// random number generators for screen in 1600 x 800
std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr))); // Seed with time
std::uniform_real_distribution<float> distX(0.0f, 1600.0f); // Range for x-axis
std::uniform_real_distribution<float> distY(0.0f, 800.0f);  // Range for y-axis

// resolution
const auto SCREEN_WIDTH = 1600, SCREEN_HEIGHT = 800;
const sf::Vector2f SMALL_RECT_SIZE = { 5,20 }, MEDIUM_RECT_SIZE = { 25,100 }, LARGE_RECT_SIZE = { 125, 500};

int main()
{   
    // Main Window Creation
    sf::RenderWindow window(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), "SillyGame", sf::State::Windowed);
    window.setMouseCursorVisible(1);
    window.setFramerateLimit(60);
    // Get ball photo
    sf::Texture blackBallTexture("assets/chars/BlackBallPurp1.png");
    // Load ball into sprite
    sf::Sprite ballUser(blackBallTexture);
    ballUser.setTextureRect({ sf::IntRect({614, 334}, {50,50}) }); // grab ball picture
    ballUser.setOrigin(ballUser.getGlobalBounds().getCenter());
    // Set the sprite's position
    ballUser.setPosition({SCREEN_WIDTH/2.f, SCREEN_HEIGHT/2.f});
    ballUser.setScale({ 1, 1 });
    sf::RectangleShape rect1(MEDIUM_RECT_SIZE);
	rect1.setFillColor(sf::Color::Red);
    rect1.setPosition({distX(rng), distY(rng)});
	sf::FloatRect rect1Bounds = rect1.getGlobalBounds();
	//std::cout << rect1.getGlobalBounds().position.x << " " << rect1.getGlobalBounds().position.y << std::endl;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(ballUser);
		window.draw(rect1);
        window.display();
        keyboardMovements(ballUser);
        sf::FloatRect ballBounds = ballUser.getGlobalBounds();
        if (const std::optional intersection = ballBounds.findIntersection(rect1Bounds)){
			std::cout << ballUser.getGlobalBounds().position.x << " " << ballUser.getGlobalBounds().position.y << std::endl;    
		}
    }
}

// Handles movement of any sprite based on user keyboard inputs
void keyboardMovements(sf::Sprite& ballUser) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        ballUser.move({ -2,0 });
        ballUser.rotate(sf::degrees(-5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        ballUser.move({ 2,0 });
        ballUser.rotate(sf::degrees(5));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        ballUser.move({ 0, -2 });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        ballUser.move({ 0,2 });
     }
 }