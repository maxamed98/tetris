#pragma once

#include <vector>
#include <raylib.h>

class GameMetadata {

    public:
        std::vector<std::vector<Vector2>> nextShape = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Vector2>> hold = {{}, {}, {}, {}, {}};
        GameMetadata();
        void initialise();
        int cellSize = 50;



};