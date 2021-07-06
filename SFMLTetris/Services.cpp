#include <iostream>
#include <SFML/Graphics.hpp>
#include"Figures.h"
#include"Services.h"

void Initialization(Prefs& prefs)
{
    prefs.figuresCount = LoadFigures(prefs.figures);

    prefs.fallTick = { 0.3 };
    prefs.drawOffset = { 27,31 };
    prefs.boardSize = { 10,20 };

    prefs.figureTexture.loadFromFile("tiles.png");
    prefs.shapeSprite.setTexture(prefs.figureTexture);
    prefs.shapeSprite.setTextureRect(sf::IntRect(18, 0, 18, 18));

    prefs.boardTexture.loadFromFile("background.png");
    prefs.boardSprite.setTexture(prefs.boardTexture);
}