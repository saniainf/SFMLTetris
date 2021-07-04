#include<vector>
#include <SFML/Graphics.hpp>
#include"Figures.h"


int LoadFigures(Figure *figures)
{
    Figure figI =
    {
        {
            {{0,1,0,0},
             {0,2,0,0},
             {0,3,0,3},
             {0,4,0,0}},
            {{0,0,0,0},
             {1,2,3,4},
             {0,0,0,0},
             {0,0,0,0}}
        },
        2
    };
    figures[0] = figI;

    Figure figO =
    {
        {
            {{1,1,0,0},
             {1,1,0,0},
             {0,0,0,0},
             {0,0,0,0}}
        },
        1
    };
    figures[1]= figO;

    return 2;
}