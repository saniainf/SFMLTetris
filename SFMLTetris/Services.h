#ifndef Services
#define Services
//#include <SFML/Graphics.hpp>

struct Point
{
    int x;
    int y;
};

struct Prefs
{
    Point boardSize;
    Point shapeSize{ 4,4 };
    int figuresCount;
    int currentShape{ 0 };
    Figure figures[7];
    Figure currentFigure;
    Point offset{ 0,0 };
    Point drawOffset;
    int(*shapeMatrix)[4][4];
    int boardMatrix[20][10]{ 0 };
    sf::Texture boardTexture;
    sf::Texture figureTexture;
    sf::Sprite shapeSprite;
    sf::Sprite boardSprite;
    float fallTick;
    float fallTime{ 0 };
    bool dropFigure{ false };
};

void Initialization(Prefs& prefs);

#endif