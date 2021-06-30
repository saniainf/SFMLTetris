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
    sprite.setTextureRect(IntRect(0, 0, 18, 18));

    std::vector<std::vector<int>>a = cFigures[0].shapes[currentShape];
    while (window.isOpen())
    {
        // ������������ ������� ������� � �����
        Event event;
        while (window.pollEvent(event))
        {
            // ������������ ����� �� �������� � ����� ������� ����?
            if (event.type == Event::Closed)
                // ����� ��������� ���
                window.close();
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up)
                {
                    currentShape = (currentShape + 1) % (cFigures[0].shapes.size());
                    a = cFigures[0].shapes[currentShape];
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
                if (a[i][j] == 1)
                {
                    sprite.setColor(cFigures[0].color);
                    sprite.setPosition(i * 18.f + fx * 18, j * 18.f);
                    window.draw(sprite);
                }
            }
        }

        // ��������� ����	
        window.display();
    }

    return 0;
}