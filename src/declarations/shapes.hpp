#pragma once

#include "./shape.hpp"
#include <raymath.h>
#include <set>

class Shapes {

    public:
        Shapes();
        int cellSize = 25;
        void calculateChanges(double currentTime);
        void render();
        void rotate();
        Shape shape;
        Color colorOn = RED;
        Color colorOff = LIGHTGRAY;
        std::vector<std::vector<Cell>> currentShape;
        std::vector<Vector2> completedCells;
        Color colorCompleted = {0, 0, 255, 255};
        double lastTime = 0;
        double interval = 0.1;
        void addNewShape();
        bool checkCollisionDown();
        bool checkCollisionLeft();
        bool checkCollisionRight();
        bool releaseNewShape = false;
        bool isGameOver = false;
        void checkCompletedCellsOutOfBounds();
        std::vector<std::vector<std::vector<Cell>>> shapesVector;
        void initialiseShapes();
        int currentShapeIndex = 0;
        int score = 0;
        void checkFlatRow();
        std::set<int> completedCellsYPosition;
        std::vector<int> completedCellsYPositionCopy;
        bool checkIfInsideCompletedIndexVector(int positionY);
        int nextShapeIndex;
        std::vector<std::vector<Cell>> nextShape;
        std::vector<std::vector<Cell>> holdShape;
        bool holdClickedInital = false;
        bool holdClickedAfterInitial = false;
        bool hold_flow = false;
        void reset();

};