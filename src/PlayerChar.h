#pragma once
#include <SFML/Graphics.hpp>

class PlayerChar{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	PlayerChar() = default;
	PlayerChar(const std::filesystem::path&);
	//Keyboard movement
	sf::Sprite& getSprite() { return sprite; }
	void keyboardMovements();
	void mouseMovements();
};