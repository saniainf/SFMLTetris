#ifndef Figures
#define Figures

struct Figure
{
    std::vector<std::vector<std::vector<int>>> shapes;
    int color;
};

void LoadFigures(std::vector<Figure>&);

#endif