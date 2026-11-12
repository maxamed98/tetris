#pragma once

#include "./cell.hpp"
#include <vector>

class Shape {

    public:
        Shape();
        void initialiseShapes();

        Cell cell_0_0;
        Cell cell_0_1;
        Cell cell_0_2;
        Cell cell_0_3;
        Cell cell_0_4;

        Cell cell_1_0;
        Cell cell_1_1;
        Cell cell_1_2;
        Cell cell_1_3;
        Cell cell_1_4;

        Cell cell_2_0;
        Cell cell_2_1;
        Cell cell_2_2;
        Cell cell_2_3;
        Cell cell_2_4;

        Cell cell_3_0;
        Cell cell_3_1;
        Cell cell_3_2;
        Cell cell_3_3;
        Cell cell_3_4;

        Cell cell_4_0;
        Cell cell_4_1;
        Cell cell_4_2;
        Cell cell_4_3;
        Cell cell_4_4;

        std::vector<std::vector<Cell>> shape_one = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_two = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_three = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_four = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_five = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_six = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_seven = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_eight = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_nine = {{}, {}, {}, {}, {}};
        std::vector<std::vector<Cell>> shape_ten = {{}, {}, {}, {}, {}};

        void setCellPosition();
        void initialiseShapeOne();
        void initialiseShapeTwo();
        void initialiseShapeThree();
        void initialiseShapeFour();
        void initialiseShapeFive();
        void initialiseShapeSix();
        void initialiseShapeSeven();
        void initialiseShapeEight();
        void initialiseShapeNine();
        void initialiseShapeTen();

};