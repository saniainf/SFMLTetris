#include <iostream>
#include <SFML/Graphics.hpp>
#include"Figures.h"

using namespace sf;

int main()
{
    std::vector<Figure> cFigures;
    LoadFigures(cFigures);
    int currentShape = 0;
    int fx = 0, fy = 0;

    RenderWindow window(VideoMode(200, 200), "SFML Works!");

    Texture texture;
    texture.loadFromFile("e:\\projects\\Projects_C++\\SFML_Tutor\\Images\\tiles.png");

    Sprite sprite(texture);
    sprite.setTextureRect(IntRect(18, 0, 18, 18));

    Figure fig = cFigures[0];

    std::vector<std::vector<int>>a = fig.shapes[currentShape];
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                {
                    currentShape = ++currentShape < fig.shapes.size() ? currentShape : 0;
                    a = fig.shapes[currentShape];
                }
                if (event.key.code == Keyboard::Left)
                    fx -= 1;
                else if (event.key.code == Keyboard::Right)
                    fx += 1;
            }
        }

        window.clear(Color::White);

        for (size_t i = 0; i < a[0].size(); i++)
        {
            for (size_t j = 0; j < a[1].size(); j++)
            {
                if (a[i][j] != 0)
                {
                    sprite.setTextureRect(IntRect(a[i][j] * 18, 0, 18, 18));
                    sprite.setPosition(i * 18.f + fx * 18, j * 18.f);
                    window.draw(sprite);
                }
            }
        }

        // Отрисовка окна	
        window.display();
    }

    return 0;
}