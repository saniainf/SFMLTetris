#ifndef Figures
#define Figures

struct Figure
{
    int shapes[4][4][4];
    int shapeCount;
};

int LoadFigures(Figure *figures);

#endif