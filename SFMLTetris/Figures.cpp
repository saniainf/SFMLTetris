#include<vector>
#include <SFML/Graphics.hpp>
#include"Figures.h"


void LoadFigures(std::vector<Figure>& figures)
{
    Figure figI =
    {
        {
            {{0,1,0,0},
             {0,2,0,0},
             {0,3,0,0},
             {0,4,0,0}},
            {{0,0,0,0},
             {1,2,3,4},
             {0,0,0,0},
             {0,0,0,0}}
        },
        1
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
        3
    };
    figures.push_back(figO);

}