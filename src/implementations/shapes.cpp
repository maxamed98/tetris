#include "../declarations/shapes.hpp"

/*

    1375 / 25 = 55 cells in the x-axis      (0 - 54)
    950  / 25 = 38 cells in the y-axis      (0 - 37)


*/


Shapes::Shapes() {

    initialiseShapes();

}


void Shapes::initialiseShapes() {

    shapesVector.push_back(shape.shape_two);    // Square 4x4
    shapesVector.push_back(shape.shape_five);   // 2x3 block
    shapesVector.push_back(shape.shape_nine);   // Staircase right-side
    shapesVector.push_back(shape.shape_one);    // L
    shapesVector.push_back(shape.shape_eight);  // I
    shapesVector.push_back(shape.shape_ten);    // Staircase left-side
    shapesVector.push_back(shape.shape_six);    // U 
    shapesVector.push_back(shape.shape_five);   // 2x3 block
    shapesVector.push_back(shape.shape_three);  // Square 5x5
    shapesVector.push_back(shape.shape_seven);  // 3x4 block (central location)
    shapesVector.push_back(shape.shape_one);    // L
    shapesVector.push_back(shape.shape_four);   // Central Pillar w/ 2x(2x3 block) missing
    shapesVector.push_back(shape.shape_two);    // Square 4x4
    shapesVector.push_back(shape.shape_five);   // 2x3 block
    shapesVector.push_back(shape.shape_three);  // Square 5x5
    shapesVector.push_back(shape.shape_five);   // 2x3 block

    currentShape = shapesVector[0];

}


void Shapes::reset() {

    completedCells.clear();
    currentShapeIndex = 0;
    currentShape = shapesVector[currentShapeIndex];
    holdShape.clear();
    score = 0;
    isGameOver = false;

}


void Shapes::calculateChanges(double currentTime) {

    if(currentShapeIndex >= 0 && currentShapeIndex < shapesVector.size() - 1) {
        nextShapeIndex = currentShapeIndex + 1;
    }
    else{
        nextShapeIndex = 0;
    }

    nextShape = shapesVector[nextShapeIndex];
    
    checkCompletedCellsOutOfBounds();

    checkFlatRow();
    

    if(releaseNewShape) {
        addNewShape();
    }

    if(IsKeyPressed(KEY_W)) {
        hold_flow = true;

        if(!holdClickedInital) {
            holdClickedInital = true;
            auto placeholder = currentShape;

            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(i == 0) {
                        placeholder[i][j].position.y = -5;
                    }
                    else if(i == 1) {
                        placeholder[i][j].position.y = -4;
                    }
                    else if(i == 2) {
                        placeholder[i][j].position.y = -3;
                    }
                    else if(i == 3) {
                        placeholder[i][j].position.y = -2;
                    }
                    else if(i == 4) {
                        placeholder[i][j].position.y = -1;
                    }



                    if(j == 0) {
                        placeholder[i][j].position.x = 20;
                    }
                    else if(j == 1) {
                        placeholder[i][j].position.x = 21;
                    }
                    else if(j == 2) {
                        placeholder[i][j].position.x = 22;
                    }
                    else if(j == 3) {
                        placeholder[i][j].position.x = 23;
                    }
                    else if(j == 4) {
                        placeholder[i][j].position.x = 24;
                    }
                }
            }

            holdShape = placeholder;
            releaseNewShape = true;

        }
        else{

            if(!holdClickedAfterInitial)    {
                holdClickedAfterInitial = true;
            }

            auto placeholder = currentShape;

            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(i == 0) {
                        placeholder[i][j].position.y = -5;
                    }
                    else if(i == 1) {
                        placeholder[i][j].position.y = -4;
                    }
                    else if(i == 2) {
                        placeholder[i][j].position.y = -3;
                    }
                    else if(i == 3) {
                        placeholder[i][j].position.y = -2;
                    }
                    else if(i == 4) {
                        placeholder[i][j].position.y = -1;
                    }
                    

                    
                    if(j == 0) {
                        placeholder[i][j].position.x = 20;
                    }
                    else if(j == 1) {
                        placeholder[i][j].position.x = 21;
                    }
                    else if(j == 2) {
                        placeholder[i][j].position.x = 22;
                    }
                    else if(j == 3) {
                        placeholder[i][j].position.x = 23;
                    }
                    else if(j == 4) {
                        placeholder[i][j].position.x = 24;
                    }
                }
            }

            currentShape = holdShape;
            holdShape = placeholder;
        }

    }


    if(currentTime - lastTime > interval) {
        lastTime = currentTime;

        if(!checkCollisionDown()) {

            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    currentShape[i][j].position.y += 1;
                }
            }

        }
        
    }

    if(IsKeyPressed(KEY_UP) && currentShape[4][0].position.y < 37) {

        if(!(currentShape[0][0].position.x < 0) && !(currentShape[0][4].position.x > 54)) {
            rotate();
        }
    }
    

    if(IsKeyDown(KEY_RIGHT) && !checkCollisionRight()) {

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                currentShape[i][j].position.x += 1;
            }
        }

    }


    if(IsKeyPressed(KEY_D) && !checkCollisionRight()) {

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                currentShape[i][j].position.x += 1;
            }
        }

    }


    if(IsKeyDown(KEY_LEFT) && !checkCollisionLeft()) {

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                currentShape[i][j].position.x -= 1;
            }
        }

    }

    if(IsKeyPressed(KEY_A) && !checkCollisionLeft()) {

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                currentShape[i][j].position.x -= 1;
            }
        }

    }

}


void Shapes::checkFlatRow() {

    
    completedCellsYPosition.clear();

    std::vector<Vector2> completedCellsCopy = {};


    for(int i = 37; i >= 0; i--) {
        
        for(int j = 0, z = 0; j < completedCells.size(); j++) {

            if(completedCells[j].y == i) z++;

            if(z == 55) {
                completedCellsYPosition.insert(i);
            }

        }

    }



    if(!completedCellsYPosition.empty()) {


        for(int i = 0; i < completedCells.size(); i++) {
            if(!checkIfInsideCompletedIndexVector(completedCells[i].y)) {
                completedCellsCopy.push_back(
                                                {
                                                    completedCells[i].x,
                                                    completedCells[i].y + completedCellsYPosition.size()
                                                }
                                            );
            }
        }

        completedCells.clear();
        completedCells = completedCellsCopy;
        score += ( 55 * completedCellsYPosition.size() );

    }
    


}


bool Shapes::checkIfInsideCompletedIndexVector(int positionY) {

    for(int index : completedCellsYPosition) {
        if(index == positionY) {
            return true;
        }
        
    }

    return false;

}


void Shapes::checkCompletedCellsOutOfBounds() {

    for(int i = 0; i < completedCells.size(); i++) {
        if(completedCells[i].y < 0 ) {
            isGameOver = true;
        }
    }
    
}


bool Shapes::checkCollisionRight() {

    std::vector<Vector2> nextSpaces;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(currentShape[i][j].isOn){
                nextSpaces.push_back(
                                        {
                                            currentShape[i][j].position.x + 1,
                                            currentShape[i][j].position.y
                                        }
                                    );
            }
        }
    }


    for(int i = 0; i < nextSpaces.size(); i++) {
        if(nextSpaces[i].x == 55) {
            return true;
        }
    }


    for(int i = 0; i < nextSpaces.size(); i++) {

        for(int j = 0; j < completedCells.size(); j++) {

            if(Vector2Equals(nextSpaces[i], completedCells[j])) {
                return true;
            }
        }

    }

    return false;

}



bool Shapes::checkCollisionLeft() {

    std::vector<Vector2> nextSpaces;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(currentShape[i][j].isOn){
                nextSpaces.push_back(
                                        {
                                            currentShape[i][j].position.x - 1,
                                            currentShape[i][j].position.y
                                        }
                                    );
            }
        }
    }


    for(int i = 0; i < nextSpaces.size(); i++) {
        if(nextSpaces[i].x == -1) {
            return true;
        }
    }


    for(int i = 0; i < nextSpaces.size(); i++) {

        for(int j = 0; j < completedCells.size(); j++) {

            if(Vector2Equals(nextSpaces[i], completedCells[j])) {
                return true;
            }
        }

    }

    return false;

}


bool Shapes::checkCollisionDown() {
    
    std::vector<Vector2> nextSpaces;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(currentShape[i][j].isOn){
                nextSpaces.push_back(
                                        {
                                            currentShape[i][j].position.x,
                                            currentShape[i][j].position.y + 1
                                        }
                                    );
            }
        }
    }

    for(int i = 0; i < nextSpaces.size(); i++) {
        if(nextSpaces[i].y == 38) {
            releaseNewShape = true;
            return true;
        }
    }

    for(int i = 0; i < nextSpaces.size(); i++) {

        for(int j = 0; j < completedCells.size(); j++) {

            if(Vector2Equals(nextSpaces[i], completedCells[j])) {
                if(completedCells[j].y <= 0){
                    isGameOver = true;
                }
                else{

                    releaseNewShape = true;
                    return true;
                }
            }
        }

    }

    return false;

}


void Shapes::addNewShape() {

    if(!isGameOver){

        if(hold_flow && !holdClickedAfterInitial) {
            hold_flow = false;
        }
        else if(hold_flow && holdClickedAfterInitial) {

            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(currentShape[i][j].isOn == true) {
                        completedCells.push_back(currentShape[i][j].position);
                    }
                    
                }
            }

            hold_flow = false;
        }
        else{
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(currentShape[i][j].isOn == true) {
                        completedCells.push_back(currentShape[i][j].position);
                    }
                    
                }
            }
        }

        releaseNewShape = false;

        if(currentShapeIndex >= 0 && currentShapeIndex < shapesVector.size() - 1 ) {
            currentShapeIndex++;
        }
        else{
            currentShapeIndex = 0;
        }
        
        currentShape = shapesVector[currentShapeIndex];

    }


}



void Shapes::render() {

    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            DrawRectangleV(
                            {400 + (currentShape[i][j].position.x * cellSize), currentShape[i][j].position.y * cellSize},
                            {cellSize, cellSize},
                            currentShape[i][j].isOn ? colorOn : colorOff
                        );


        }

    }


    for(int i = 0; i < completedCells.size(); i++) {

        DrawRectangleV(
                            {400 + (completedCells[i].x * cellSize), completedCells[i].y * cellSize},
                            {cellSize, cellSize},
                            colorCompleted
                        );

    }


}


/*
                            ORIGINAL
            0           1           2           3           4
    0   cell_0_0    cell_0_1    cell_0_2    cell_0_3    cell_0_4
    1   cell_1_0    cell_1_1    cell_1_2    cell_1_3    cell_1_4
    2   cell_2_0    cell_2_1    cell_2_2    cell_2_3    cell_2_4
    3   cell_3_0    cell_3_1    cell_3_2    cell_3_3    cell_3_4
    4   cell_4_0    cell_4_1    cell_4_2    cell_4_3    cell_4_4

*/


/*
                    90deg Clockwise Rotation
            0           1           2           3           4
    0   cell_4_0    cell_3_0    cell_2_0    cell_1_0    cell_0_0
    1   cell_4_1    cell_3_1    cell_2_1    cell_1_1    cell_0_1
    2   cell_4_2    cell_3_2    cell_2_2    cell_1_2    cell_0_2
    3   cell_4_3    cell_3_3    cell_2_3    cell_1_3    cell_0_3
    4   cell_4_4    cell_3_4    cell_2_4    cell_1_4    cell_0_4

*/

/*

pairs

[0][0] -> [0][4]
[0][1] -> [1][4]
[0][2] -> [2][4]
[0][3] -> [3][4]
[0][4] -> [4][4]

[1][0] -> [0][3]
[1][1] -> [1][3]
[1][2] -> [2][3]
[1][3] -> [3][3]
[1][4] -> [4][3]

[2][0] -> [0][2]
[2][1] -> [1][2]
[2][2] -> [2][2]
[2][3] -> [3][2]
[2][4] -> [4][2]

[3][0] -> [0][1]
[3][1] -> [1][1]
[3][2] -> [2][1]
[3][3] -> [3][1]
[3][4] -> [4][1]

[4][0] -> [0][0]
[4][1] -> [1][0]
[4][2] -> [2][0]
[4][3] -> [3][0]
[4][4] -> [4][0]



*/



void Shapes::rotate() {


    /*

    pairs

    [0][0] -> [0][4]
    [0][1] -> [1][4]
    [0][2] -> [2][4]
    [0][3] -> [3][4]
    [0][4] -> [4][4]

    [1][0] -> [0][3]
    [1][1] -> [1][3]
    [1][2] -> [2][3]
    [1][3] -> [3][3]
    [1][4] -> [4][3]

    [2][0] -> [0][2]
    [2][1] -> [1][2]
    [2][2] -> [2][2]
    [2][3] -> [3][2]
    [2][4] -> [4][2]

    [3][0] -> [0][1]
    [3][1] -> [1][1]
    [3][2] -> [2][1]
    [3][3] -> [3][1]
    [3][4] -> [4][1]

    [4][0] -> [0][0]
    [4][1] -> [1][0]
    [4][2] -> [2][0]
    [4][3] -> [3][0]
    [4][4] -> [4][0]

    */

    std::vector<std::vector<bool>> shapeCopy = {{}, {}, {}, {}, {}};


    for(int i = 0; i < 5; i++) {

        for(int j = 0; j < 5; j++) {

            shapeCopy[i].push_back(currentShape[i][j].isOn);

        }

    }

    // currentShape[0][4].isOn = shapeCopy[0][0] == true ? true : false;
    // currentShape[1][4].isOn = shapeCopy[0][1] == true ? true : false;
    // currentShape[2][4].isOn = shapeCopy[0][2] == true ? true : false;
    // currentShape[3][4].isOn = shapeCopy[0][3] == true ? true : false;
    // currentShape[4][4].isOn = shapeCopy[0][4] == true ? true : false;

    // currentShape[0][3].isOn = shapeCopy[1][0] == true ? true : false;
    // currentShape[1][3].isOn = shapeCopy[1][1] == true ? true : false;
    // currentShape[2][3].isOn = shapeCopy[1][2] == true ? true : false;
    // currentShape[3][3].isOn = shapeCopy[1][3] == true ? true : false;
    // currentShape[4][3].isOn = shapeCopy[1][4] == true ? true : false;

    // currentShape[0][2].isOn = shapeCopy[2][0] == true ? true : false;
    // currentShape[1][2].isOn = shapeCopy[2][1] == true ? true : false;
    // currentShape[2][2].isOn = shapeCopy[2][2] == true ? true : false;
    // currentShape[3][2].isOn = shapeCopy[2][3] == true ? true : false;
    // currentShape[4][2].isOn = shapeCopy[2][4] == true ? true : false;

    // currentShape[0][1].isOn = shapeCopy[3][0] == true ? true : false;
    // currentShape[1][1].isOn = shapeCopy[3][1] == true ? true : false;
    // currentShape[2][1].isOn = shapeCopy[3][2] == true ? true : false;
    // currentShape[3][1].isOn = shapeCopy[3][3] == true ? true : false;
    // currentShape[4][1].isOn = shapeCopy[3][4] == true ? true : false;

    // currentShape[0][0].isOn = shapeCopy[4][0] == true ? true : false;
    // currentShape[1][0].isOn = shapeCopy[4][1] == true ? true : false;
    // currentShape[2][0].isOn = shapeCopy[4][2] == true ? true : false;
    // currentShape[3][0].isOn = shapeCopy[4][3] == true ? true : false;
    // currentShape[4][0].isOn = shapeCopy[4][4] == true ? true : false;

    for(int i = 4, z = 0; i >= 0; i--, z++) {

        for(int j = 0; j < 5; j++) {
            
            currentShape[j][i].isOn = shapeCopy[z][j] == true ? true : false;

        }

    }
    


}