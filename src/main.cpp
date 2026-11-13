#include <raylib.h>

#include "./declarations/shapes.hpp";
#include "./declarations/gameMetadata.hpp";

int main() 
{
    
    char* current_window = "start";

    Color playButtonColor = DARKGRAY;
    Color instructionsButtonColor = DARKGRAY;
    Color aboutButtonColor = DARKGRAY;
    Color backButtonColor = DARKPURPLE;
    Color playAgainButtonColor = DARKGRAY;

    Rectangle playButton = {725, 200, 300, 120};
    Rectangle instructionsButton = {670, 400, 425, 120};
    Rectangle aboutButton = {725, 600, 300, 120};
    Rectangle backButton = {20, 20, 300, 80};
    Rectangle playAgainButton = {665, 400, 450, 120};
    
    int screenWidth = 1775;
    int screenHeight = 950;

    Color grey = {117, 114, 115, 255};
    
    
    
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    Shapes shapes;
    GameMetadata gameMetadata;
    
    while (!WindowShouldClose()) {
        
        BeginDrawing();

        if(current_window == "start") {
            ClearBackground(LIGHTGRAY);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(CheckCollisionPointRec(GetMousePosition(), playButton)) {
                    current_window = "game";

                }

                if(CheckCollisionPointRec(GetMousePosition(), instructionsButton)) {
                    current_window = "instructions";

                }

                if(CheckCollisionPointRec(GetMousePosition(), aboutButton)) {
                    current_window = "about";
                }
            }
            
            if(CheckCollisionPointRec(GetMousePosition(), playButton)) {
                playButtonColor = GRAY;
            }
            else {
                playButtonColor = DARKGRAY;
            }

            if(CheckCollisionPointRec(GetMousePosition(), instructionsButton)) {
                instructionsButtonColor = GRAY;
            }
            else {
                instructionsButtonColor = DARKGRAY;
            }

            

            if(CheckCollisionPointRec(GetMousePosition(), aboutButton)) {
                aboutButtonColor = GRAY;
            }
            else {
                aboutButtonColor = DARKGRAY;
            }

            DrawRectangleRounded(playButton, 1, 0, playButtonColor);
            DrawText("PLAY", 820, 245, 40, BLACK);

            DrawRectangleRounded(instructionsButton, 1, 0, instructionsButtonColor);
            DrawText("INSTRUCTIONS", 730, 445, 40, BLACK);

            DrawRectangleRounded(aboutButton, 1, 0, aboutButtonColor);
            DrawText("ABOUT", 810, 645, 40, BLACK);

            DrawText("Tetris", 750, 50, 80, BLACK);


        }


        if(current_window == "instructions") {

            ClearBackground(LIGHTGRAY);
            
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                    current_window = "start";

                }

            }

            if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                backButtonColor = PURPLE;
            }
            else {
                backButtonColor = DARKPURPLE;
            }

            DrawText("HOW TO PLAY", 680, 120, 55, BLACK);

            DrawText("KEY", 300, 255, 30, RED);
                DrawText("RIGHT ARROW", 240, 350, 30, BLACK);
                DrawText("D", 330, 425, 30, BLACK);
                DrawText("LEFT ARROW", 250, 575, 30, BLACK);
                DrawText("A", 330, 650, 30, BLACK);
                DrawText("UP ARROW", 275, 800, 30, BLACK);
                DrawText("W", 330, 875, 30, BLACK);

            DrawText("FUNCTION", 1250, 255, 30, RED);
                DrawText("MOVE THE SHAPE TOWARDS THE RIGHT QUICKLY", 960, 350, 30, BLACK);
                DrawText("MOVE THE SHAPE TOWARDS THE RIGHT BY 1 CELL", 960, 425, 30, BLACK);
                DrawText("MOVE THE SHAPE TOWARDS THE LEFT QUICKLY", 960, 575, 30, BLACK);
                DrawText("MOVE THE SHAPE TOWARDS THE LEFT BY 1 CELL", 960, 650, 30, BLACK);
                DrawText("ROTATE THE SHAPE 90 DEGREES CLOCKWISE", 960, 800, 30, BLACK);
                DrawText("STORE OR USE A SHAPE IN THE HOLD STORAGE", 960, 875, 30, BLACK);



            DrawRectangleRounded(backButton, 1, 0, backButtonColor);
            DrawText("BACK", 115, 45, 40, BLACK);

        }

        if(current_window == "about") {

            ClearBackground(LIGHTGRAY);
            
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

                if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                    current_window = "start";

                }

            }

            if(CheckCollisionPointRec(GetMousePosition(), backButton)) {
                backButtonColor = PURPLE;
            }
            else {
                backButtonColor = DARKPURPLE;
            }

            DrawText("Created By Mohamed Dahir.", 630, 400, 40, BLACK);
            DrawText("© MMXXVI", 795, 470, 40, BLACK);

            DrawRectangleRounded(backButton, 1, 0, backButtonColor);
            DrawText("BACK", 115, 45, 40, BLACK);

        }


        if(current_window == "game") {

        

            ClearBackground(LIGHTGRAY);
            
            
            shapes.calculateChanges(GetTime());

            if(shapes.isGameOver)   {
                shapes.reset();
                current_window = "game_over";
            }
            
            shapes.render();
            
            DrawRectangleV({0, 0}, {400, GetScreenHeight()}, grey);

            DrawText(
                "NEXT SHAPE",
                65,
                30,
                40,
                BLACK
            );


            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    DrawRectangleLinesEx(
                                            {
                                                gameMetadata.nextShape[i][j].x,
                                                gameMetadata.nextShape[i][j].y,
                                                gameMetadata.cellSize,
                                                gameMetadata.cellSize
                                            },
                                            1,
                                            BLACK
                                        );
                }
            }

            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {

                    if(shapes.nextShape[i][j].isOn){

                        DrawRectangleRec(
                                                {
                                                    gameMetadata.nextShape[i][j].x,
                                                    gameMetadata.nextShape[i][j].y,
                                                    gameMetadata.cellSize,
                                                    gameMetadata.cellSize
                                                },
                                                GOLD
                                            );

                        DrawRectangleLinesEx(
                                                {
                                                    gameMetadata.nextShape[i][j].x,
                                                    gameMetadata.nextShape[i][j].y,
                                                    gameMetadata.cellSize,
                                                    gameMetadata.cellSize
                                                },
                                                1,
                                                BLACK
                                            );
                    }   
                }
            }


             DrawText(
                "HOLD",
                150,
                400,
                40,
                BLACK
            );


            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    DrawRectangleLinesEx(
                                            {
                                                gameMetadata.hold[i][j].x,
                                                gameMetadata.hold[i][j].y,
                                                gameMetadata.cellSize,
                                                gameMetadata.cellSize
                                            },
                                            1,
                                            BLACK
                                        );
                }
            }

            if(shapes.holdShape.size() >= 1) {

                for(int i = 0; i < 5; i++) {
                    for(int j = 0; j < 5; j++) {

                        if(shapes.holdShape[i][j].isOn){

                            DrawRectangleRec(
                                                    {
                                                        gameMetadata.hold[i][j].x,
                                                        gameMetadata.hold[i][j].y,
                                                        gameMetadata.cellSize,
                                                        gameMetadata.cellSize
                                                    },
                                                    GOLD
                                                );

                            DrawRectangleLinesEx(
                                                    {
                                                        gameMetadata.hold[i][j].x,
                                                        gameMetadata.hold[i][j].y,
                                                        gameMetadata.cellSize,
                                                        gameMetadata.cellSize
                                                    },
                                                    1,
                                                    BLACK
                                                );
                        }   
                    }
                }

            }

            DrawText(
                    "SCORE",
                    140,
                    800,
                    40,
                    BLACK
                );

    
            if(shapes.score == 0) {

                DrawText(
                    TextFormat("%i", shapes.score),
                    180,
                    860,
                    50,
                    BLACK
                );
            }


            if(shapes.score < 100 && shapes.score > 0) {

                DrawText(
                    TextFormat("%i", shapes.score),
                    165,
                    860,
                    50,
                    BLACK
                );
            }

            if(shapes.score < 1000 && shapes.score > 100){

                DrawText(
                    TextFormat("%i", shapes.score),
                    158,
                    860,
                    50,
                    BLACK
                );
            }
                
            if(shapes.score > 1000) {

                DrawText(
                    TextFormat("%i", shapes.score),
                    150,
                    860,
                    50,
                    BLACK
                );
            }

        }


        if(current_window == "game_over") {

            ClearBackground(LIGHTGRAY);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){


                if(CheckCollisionPointRec(GetMousePosition(), playAgainButton)) {
                    current_window = "game";
                }

            }
            
                        
            if(CheckCollisionPointRec(GetMousePosition(), playAgainButton)) {
                playAgainButtonColor = GRAY;
            }
            else {
                playAgainButtonColor = DARKGRAY;
            }


            DrawText("Game Over", 700, 245, 75, BLACK);

            DrawRectangleRounded(playAgainButton, 1, 0, playAgainButtonColor);
            DrawText("PLAY AGAIN", 770, 445, 40, BLACK);

        }



        EndDrawing();

    }
    
    CloseWindow();
}