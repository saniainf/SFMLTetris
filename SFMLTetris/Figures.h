#ifndef Figures
#define Figures

struct Figure
{
    std::vector<std::vector<std::vector<int>>> shapes;
    sf::Color color;
};

void LoadFigures(std::vector<Figure>&);

#endif