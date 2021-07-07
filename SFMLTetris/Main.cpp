#include <iostream>
#include <SFML/Graphics.hpp>
#include"Figures.h"
#include"Services.h"

using namespace sf;

void PrintMatrix(int(*a)[4][4]);
void UpdateInput(RenderWindow& window, Prefs& prefs);
void Update(RenderWindow& window, Prefs& prefs);
void Draw(RenderWindow& window, Prefs& prefs);
bool CheckCollision(Prefs& prefs);
void RotateFigure(Prefs& prefs);
void PlaceNextFigure(Prefs& prefs);
void CopyFigureToBoard(Prefs& prefs);
void CheckLines(Prefs& prefs);

float elapsedTime;

int main()
{
    Clock clock;

    Prefs prefs;

    Initialization(prefs);

    PlaceNextFigure(prefs);

    RenderWindow window(VideoMode(320, 480), "SFML Brick!");

    while (window.isOpen())
    {
        UpdateInput(window, prefs);
        Update(window, prefs);
        Draw(window, prefs);
        elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart();
    }

    return 0;
}

void UpdateInput(RenderWindow& window, Prefs& prefs)
{
    Event event;
    Point prevOffset = prefs.offset;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            // тогда закрываем его
            window.close();
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Up)
                RotateFigure(prefs);

            if (event.key.code == Keyboard::Space)
                prefs.dropFigure = true;

            if (event.key.code == Keyboard::Down)
                prefs.fallTime = prefs.fallTick;

            if (event.key.code == Keyboard::Left)
            {
                prefs.offset.x--;
                if (CheckCollision(prefs))
                    prefs.offset = prevOffset;
            }
            else if (event.key.code == Keyboard::Right)
            {
                prefs.offset.x++;
                if (CheckCollision(prefs))
                    prefs.offset = prevOffset;
            }
        }
    }
}

void Update(RenderWindow& window, Prefs& prefs)
{
    Point prevOffset = prefs.offset;
    prefs.fallTime += elapsedTime;

    if (prefs.dropFigure || prefs.fallTime > prefs.fallTick)
    {
        prefs.offset.y++;
        prefs.fallTime = 0;
    }
    if (CheckCollision(prefs))
    {
        prefs.offset = prevOffset;
        CopyFigureToBoard(prefs);
        CheckLines(prefs);
        PlaceNextFigure(prefs);
    }
}

void Draw(RenderWindow& window, Prefs& prefs)
{
    window.clear(Color::White);

    window.draw(prefs.boardSprite);

    for (size_t i = 0; i < prefs.shapeSize.y; i++)
        for (size_t j = 0; j < prefs.shapeSize.x; j++)
        {
            if ((*prefs.shapeMatrix)[i][j] == 0)
                continue;

            prefs.shapeSprite.setTextureRect(IntRect((*prefs.shapeMatrix)[i][j] * 18, 0, 18, 18));
            prefs.shapeSprite.setPosition(j * 18.f + prefs.offset.x * 18, i * 18.f + prefs.offset.y * 18);
            prefs.shapeSprite.move(prefs.drawOffset.x, prefs.drawOffset.y);
            window.draw(prefs.shapeSprite);

        }

    for (size_t i = 0; i < prefs.boardSize.y; i++)
        for (size_t j = 0; j < prefs.boardSize.x; j++)
        {
            if (prefs.boardMatrix[i][j] == 0)
                continue;

            prefs.shapeSprite.setTextureRect(IntRect(prefs.boardMatrix[i][j] * 18, 0, 18, 18));
            prefs.shapeSprite.setPosition(j * 18.f, i * 18.f);
            prefs.shapeSprite.move(prefs.drawOffset.x, prefs.drawOffset.y);
            window.draw(prefs.shapeSprite);
        }

    // Отрисовка окна
    window.display();
}

void RotateFigure(Prefs& prefs)
{
    int prevShape = prefs.currentShape;
    prefs.currentShape = ++prefs.currentShape < prefs.currentFigure.shapeCount ? prefs.currentShape : 0;
    prefs.shapeMatrix = &prefs.currentFigure.shapes[prefs.currentShape];

    if (CheckCollision(prefs))
    {
        prefs.currentShape = prevShape;
        prefs.shapeMatrix = &prefs.currentFigure.shapes[prefs.currentShape];
    }
}

bool CheckCollision(Prefs& prefs)
{
    for (size_t i = 0; i < prefs.shapeSize.y; i++)
        for (size_t j = 0; j < prefs.shapeSize.x; j++)
        {
            if ((*prefs.shapeMatrix)[i][j] == 0)
                continue;

            if ((j + prefs.offset.x < 0) ||
                (j + prefs.offset.x >= prefs.boardSize.x) ||
                (i + prefs.offset.y >= prefs.boardSize.y))
                return true;

            if (prefs.boardMatrix[i + prefs.offset.y][j + prefs.offset.x] != 0)
                return true;
        }
    return false;
}

void PlaceNextFigure(Prefs& prefs)
{
    prefs.offset = { 3,0 };
    prefs.currentShape = 0;
    prefs.currentFigure = prefs.figures[std::rand() % prefs.figuresCount];
    prefs.shapeMatrix = &prefs.currentFigure.shapes[prefs.currentShape];
    prefs.dropFigure = false;
}

void CopyFigureToBoard(Prefs& prefs)
{
    for (size_t i = 0; i < prefs.shapeSize.y; i++)
        for (size_t j = 0; j < prefs.shapeSize.x; j++)
        {
            if ((*prefs.shapeMatrix)[i][j] == 0)
                continue;

            prefs.boardMatrix[i + prefs.offset.y][j + prefs.offset.x] = (*prefs.shapeMatrix)[i][j];
        }
}

void CheckLines(Prefs& prefs)
{
    //проверку линий честно спер )))
    int k = prefs.boardSize.y - 1;
    for (int i = prefs.boardSize.y - 1; i > 0; i--)
    {
        int count = 0;
        for (int j = 0; j < prefs.boardSize.x; j++)
        {
            if (prefs.boardMatrix[i][j]) count++;
            prefs.boardMatrix[k][j] = prefs.boardMatrix[i][j];
        }
        if (count < prefs.boardSize.x) k--;
    }
}

void PrintMatrix(int(*a)[4][4])
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << (*a)[i][j] << " ";
        }
        std::cout << "\n";
    }
}