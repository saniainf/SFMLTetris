#include<vector>
#include <SFML/Graphics.hpp>
#include"Figures.h"


void LoadFigures(std::vector<Figure>& figures)
{
    Figure figI =
    {
        {
            {{0,1,0,0},
             {0,1,0,0},
             {0,1,0,0},
             {0,1,0,0}},
            {{0,0,0,0},
             {1,1,1,1},
             {0,0,0,0},
             {0,0,0,0}}
        },
        sf::Color(255,0,0)
    };
    figures.push_back(figI);

    Figure figO =
    {
        {
            {{1,1,0,0},
             {1,1,0,0},
             {0,0,0,0},
             {0,0,0,0}}
        },
        sf::Color(0,255,0)
    };
    figures.push_back(figO);

}