#include "../declarations/shape.hpp"


Shape::Shape() {

    initialiseShapes();

}


/*
            0           1           2           3           4
    0   cell_0_0    cell_0_1    cell_0_2    cell_0_3    cell_0_4
    1   cell_1_0    cell_1_1    cell_1_2    cell_1_3    cell_1_4
    2   cell_2_0    cell_2_1    cell_2_2    cell_2_3    cell_2_4
    3   cell_3_0    cell_3_1    cell_3_2    cell_3_3    cell_3_4
    4   cell_4_0    cell_4_1    cell_4_2    cell_4_3    cell_4_4

*/


/*

    0   {20, 10}     {21, 10}     {22, 10}     {23, 10}     {24, 10}  
    1   {20, 11}     {21, 11}     {22, 11}     {23, 11}     {24, 11}
    2   {20, 12}     {21, 12}     {22, 12}     {23, 12}     {24, 12}
    3   {20, 13}     {21, 13}     {22, 13}     {23, 13}     {24, 13}
    4   {20, 14}     {21, 14}     {22, 14}     {23, 14}     {24, 14}


*/

/*                  NEW POSITIONS

    0   {20, -5}     {21, -5}     {22, -5}     {23, -5}     {24, -5}  
    1   {20, -4}     {21, -4}     {22, -4}     {23, -4}     {24, -4}
    2   {20, -3}     {21, -3}     {22, -3}     {23, -3}     {24, -3}
    3   {20, -2}     {21, -2}     {22, -2}     {23, -2}     {24, -2}
    4   {20, -1}     {21, -1}     {22, -1}     {23, -1}     {24, -1}


*/



/*
            LIST OF ALL SHAPES

    Shape 1:        L
            
    10000
    10000
    10000
    10000
    11111

    Shape 2:        Square 4x4        
            
    01111
    01111
    01111
    01111
    00000

    Shape 3:        Square 5x5    
            
    11111
    11111
    11111
    11111
    11111

    Shape 4:        Central Pillar w/ 2x(2x3 block) missing    
            
    00100
    00100
    00100
    11111
    11111

    Shape 5:        2x3 block    
            
    11000
    11000
    11000
    00000
    00000

    Shape 6:        U    
            
    10001
    10001
    10001
    10001
    11111

    Shape 7:        3x4 block (central location)    
            
    01110
    01110
    01110
    01110
    00000

    Shape 8:        I    
            
    11111
    00100
    00100
    00100
    11111

    Shape 9:        Staircase right-side    
            
    00001
    00011
    00111
    01111
    11111

    Shape 10:       Staircase left-side    
            
    11110
    1110
    11000
    10000
    00000



*/

void Shape::initialiseShapes() {

    setCellPosition();

    initialiseShapeOne();
    initialiseShapeTwo();
    initialiseShapeThree();
    initialiseShapeFour();
    initialiseShapeFive();
    initialiseShapeSix();
    initialiseShapeSeven();
    initialiseShapeEight();
    initialiseShapeNine();
    initialiseShapeTen();
   

}

void Shape::setCellPosition() {

    // arr[0]
    cell_0_0.position = {20, -5};
    cell_0_1.position = {21, -5};
    cell_0_2.position = {22, -5};
    cell_0_3.position = {23, -5};
    cell_0_4.position = {24, -5};

    // arr[1]
    cell_1_0.position = {20, -4};
    cell_1_1.position = {21, -4};
    cell_1_2.position = {22, -4};
    cell_1_3.position = {23, -4};
    cell_1_4.position = {24, -4};

    // arr[2]
    cell_2_0.position = {20, -3};
    cell_2_1.position = {21, -3};
    cell_2_2.position = {22, -3};
    cell_2_3.position = {23, -3};
    cell_2_4.position = {24, -3};

    // arr[3]
    cell_3_0.position = {20, -2};
    cell_3_1.position = {21, -2};
    cell_3_2.position = {22, -2};
    cell_3_3.position = {23, -2};
    cell_3_4.position = {24, -2};

    // arr[4]
    cell_4_0.position = {20, -1};
    cell_4_1.position = {21, -1};
    cell_4_2.position = {22, -1};
    cell_4_3.position = {23, -1};
    cell_4_4.position = {24, -1};

}


void Shape::initialiseShapeOne() {

    // arr[0]
    cell_0_0.isOn = true;
    cell_0_1.isOn = false;
    cell_0_2.isOn = false;
    cell_0_3.isOn = false;
    cell_0_4.isOn = false;

    // arr[1]
    cell_1_0.isOn = true;
    cell_1_1.isOn = false;
    cell_1_2.isOn = false;
    cell_1_3.isOn = false;
    cell_1_4.isOn = false;

    // arr[2]
    cell_2_0.isOn = true;
    cell_2_1.isOn = false;
    cell_2_2.isOn = false;
    cell_2_3.isOn = false;
    cell_2_4.isOn = false;

    // arr[3]
    cell_3_0.isOn = true;
    cell_3_1.isOn = false;
    cell_3_2.isOn = false;
    cell_3_3.isOn = false;
    cell_3_4.isOn = false;

    // arr[4]
    cell_4_0.isOn = true;
    cell_4_1.isOn = true;
    cell_4_2.isOn = true;
    cell_4_3.isOn = true;
    cell_4_4.isOn = true;

    shape_one[0].push_back(cell_0_0);
    shape_one[0].push_back(cell_0_1);
    shape_one[0].push_back(cell_0_2);
    shape_one[0].push_back(cell_0_3);
    shape_one[0].push_back(cell_0_4);

    shape_one[1].push_back(cell_1_0);
    shape_one[1].push_back(cell_1_1);
    shape_one[1].push_back(cell_1_2);
    shape_one[1].push_back(cell_1_3);
    shape_one[1].push_back(cell_1_4);

    shape_one[2].push_back(cell_2_0);
    shape_one[2].push_back(cell_2_1);
    shape_one[2].push_back(cell_2_2);
    shape_one[2].push_back(cell_2_3);
    shape_one[2].push_back(cell_2_4);

    shape_one[3].push_back(cell_3_0);
    shape_one[3].push_back(cell_3_1);
    shape_one[3].push_back(cell_3_2);
    shape_one[3].push_back(cell_3_3);
    shape_one[3].push_back(cell_3_4);

    shape_one[4].push_back(cell_4_0);
    shape_one[4].push_back(cell_4_1);
    shape_one[4].push_back(cell_4_2);
    shape_one[4].push_back(cell_4_3);
    shape_one[4].push_back(cell_4_4);


}



void Shape::initialiseShapeTwo() {

    // arr[0]
    cell_0_0.isOn = false;
    cell_0_1.isOn = true;
    cell_0_2.isOn = true;
    cell_0_3.isOn = true;
    cell_0_4.isOn = true;

    // arr[1]
    cell_1_0.isOn = false;
    cell_1_1.isOn = true;
    cell_1_2.isOn = true;
    cell_1_3.isOn = true;
    cell_1_4.isOn = true;

    // arr[2]
    cell_2_0.isOn = false;
    cell_2_1.isOn = true;
    cell_2_2.isOn = true;
    cell_2_3.isOn = true;
    cell_2_4.isOn = true;

    // arr[3]
    cell_3_0.isOn = false;
    cell_3_1.isOn = true;
    cell_3_2.isOn = true;
    cell_3_3.isOn = true;
    cell_3_4.isOn = true;

    // arr[4]
    cell_4_0.isOn = false;
    cell_4_1.isOn = false;
    cell_4_2.isOn = false;
    cell_4_3.isOn = false;
    cell_4_4.isOn = false;

    shape_two[0].push_back(cell_0_0);
    shape_two[0].push_back(cell_0_1);
    shape_two[0].push_back(cell_0_2);
    shape_two[0].push_back(cell_0_3);
    shape_two[0].push_back(cell_0_4);

    shape_two[1].push_back(cell_1_0);
    shape_two[1].push_back(cell_1_1);
    shape_two[1].push_back(cell_1_2);
    shape_two[1].push_back(cell_1_3);
    shape_two[1].push_back(cell_1_4);

    shape_two[2].push_back(cell_2_0);
    shape_two[2].push_back(cell_2_1);
    shape_two[2].push_back(cell_2_2);
    shape_two[2].push_back(cell_2_3);
    shape_two[2].push_back(cell_2_4);

    shape_two[3].push_back(cell_3_0);
    shape_two[3].push_back(cell_3_1);
    shape_two[3].push_back(cell_3_2);
    shape_two[3].push_back(cell_3_3);
    shape_two[3].push_back(cell_3_4);

    shape_two[4].push_back(cell_4_0);
    shape_two[4].push_back(cell_4_1);
    shape_two[4].push_back(cell_4_2);
    shape_two[4].push_back(cell_4_3);
    shape_two[4].push_back(cell_4_4);


}



void Shape::initialiseShapeThree() {

    // arr[0]
    cell_0_0.isOn = true;
    cell_0_1.isOn = true;
    cell_0_2.isOn = true;
    cell_0_3.isOn = true;
    cell_0_4.isOn = true;

    // arr[1]
    cell_1_0.isOn = true;
    cell_1_1.isOn = true;
    cell_1_2.isOn = true;
    cell_1_3.isOn = true;
    cell_1_4.isOn = true;

    // arr[2]
    cell_2_0.isOn = true;
    cell_2_1.isOn = true;
    cell_2_2.isOn = true;
    cell_2_3.isOn = true;
    cell_2_4.isOn = true;

    // arr[3]
    cell_3_0.isOn = true;
    cell_3_1.isOn = true;
    cell_3_2.isOn = true;
    cell_3_3.isOn = true;
    cell_3_4.isOn = true;

    // arr[4]
    cell_4_0.isOn = true;
    cell_4_1.isOn = true;
    cell_4_2.isOn = true;
    cell_4_3.isOn = true;
    cell_4_4.isOn = true;

    shape_three[0].push_back(cell_0_0);
    shape_three[0].push_back(cell_0_1);
    shape_three[0].push_back(cell_0_2);
    shape_three[0].push_back(cell_0_3);
    shape_three[0].push_back(cell_0_4);

    shape_three[1].push_back(cell_1_0);
    shape_three[1].push_back(cell_1_1);
    shape_three[1].push_back(cell_1_2);
    shape_three[1].push_back(cell_1_3);
    shape_three[1].push_back(cell_1_4);

    shape_three[2].push_back(cell_2_0);
    shape_three[2].push_back(cell_2_1);
    shape_three[2].push_back(cell_2_2);
    shape_three[2].push_back(cell_2_3);
    shape_three[2].push_back(cell_2_4);

    shape_three[3].push_back(cell_3_0);
    shape_three[3].push_back(cell_3_1);
    shape_three[3].push_back(cell_3_2);
    shape_three[3].push_back(cell_3_3);
    shape_three[3].push_back(cell_3_4);

    shape_three[4].push_back(cell_4_0);
    shape_three[4].push_back(cell_4_1);
    shape_three[4].push_back(cell_4_2);
    shape_three[4].push_back(cell_4_3);
    shape_three[4].push_back(cell_4_4);


}



void Shape::initialiseShapeFour() {

    // arr[0]
    cell_0_0.isOn = false;
    cell_0_1.isOn = false;
    cell_0_2.isOn = true;
    cell_0_3.isOn = false;
    cell_0_4.isOn = false;

    // arr[1]
    cell_1_0.isOn = false;
    cell_1_1.isOn = false;
    cell_1_2.isOn = true;
    cell_1_3.isOn = false;
    cell_1_4.isOn = false;

    // arr[2]
    cell_2_0.isOn = false;
    cell_2_1.isOn = false;
    cell_2_2.isOn = true;
    cell_2_3.isOn = false;
    cell_2_4.isOn = false;

    // arr[3]
    cell_3_0.isOn = true;
    cell_3_1.isOn = true;
    cell_3_2.isOn = true;
    cell_3_3.isOn = true;
    cell_3_4.isOn = true;

    // arr[4]
    cell_4_0.isOn = true;
    cell_4_1.isOn = true;
    cell_4_2.isOn = true;
    cell_4_3.isOn = true;
    cell_4_4.isOn = true;

    shape_four[0].push_back(cell_0_0);
    shape_four[0].push_back(cell_0_1);
    shape_four[0].push_back(cell_0_2);
    shape_four[0].push_back(cell_0_3);
    shape_four[0].push_back(cell_0_4);

    shape_four[1].push_back(cell_1_0);
    shape_four[1].push_back(cell_1_1);
    shape_four[1].push_back(cell_1_2);
    shape_four[1].push_back(cell_1_3);
    shape_four[1].push_back(cell_1_4);

    shape_four[2].push_back(cell_2_0);
    shape_four[2].push_back(cell_2_1);
    shape_four[2].push_back(cell_2_2);
    shape_four[2].push_back(cell_2_3);
    shape_four[2].push_back(cell_2_4);

    shape_four[3].push_back(cell_3_0);
    shape_four[3].push_back(cell_3_1);
    shape_four[3].push_back(cell_3_2);
    shape_four[3].push_back(cell_3_3);
    shape_four[3].push_back(cell_3_4);

    shape_four[4].push_back(cell_4_0);
    shape_four[4].push_back(cell_4_1);
    shape_four[4].push_back(cell_4_2);
    shape_four[4].push_back(cell_4_3);
    shape_four[4].push_back(cell_4_4);


}



void Shape::initialiseShapeFive() {

    // arr[0]
    cell_0_0.isOn = true;
    cell_0_1.isOn = true;
    cell_0_2.isOn = false;
    cell_0_3.isOn = false;
    cell_0_4.isOn = false;

    // arr[1]
    cell_1_0.isOn = true;
    cell_1_1.isOn = true;
    cell_1_2.isOn = false;
    cell_1_3.isOn = false;
    cell_1_4.isOn = false;

    // arr[2]
    cell_2_0.isOn = true;
    cell_2_1.isOn = true;
    cell_2_2.isOn = false;
    cell_2_3.isOn = false;
    cell_2_4.isOn = false;

    // arr[3]
    cell_3_0.isOn = false;
    cell_3_1.isOn = false;
    cell_3_2.isOn = false;
    cell_3_3.isOn = false;
    cell_3_4.isOn = false;

    // arr[4]
    cell_4_0.isOn = false;
    cell_4_1.isOn = false;
    cell_4_2.isOn = false;
    cell_4_3.isOn = false;
    cell_4_4.isOn = false;

    shape_five[0].push_back(cell_0_0);
    shape_five[0].push_back(cell_0_1);
    shape_five[0].push_back(cell_0_2);
    shape_five[0].push_back(cell_0_3);
    shape_five[0].push_back(cell_0_4);

    shape_five[1].push_back(cell_1_0);
    shape_five[1].push_back(cell_1_1);
    shape_five[1].push_back(cell_1_2);
    shape_five[1].push_back(cell_1_3);
    shape_five[1].push_back(cell_1_4);

    shape_five[2].push_back(cell_2_0);
    shape_five[2].push_back(cell_2_1);
    shape_five[2].push_back(cell_2_2);
    shape_five[2].push_back(cell_2_3);
    shape_five[2].push_back(cell_2_4);

    shape_five[3].push_back(cell_3_0);
    shape_five[3].push_back(cell_3_1);
    shape_five[3].push_back(cell_3_2);
    shape_five[3].push_back(cell_3_3);
    shape_five[3].push_back(cell_3_4);

    shape_five[4].push_back(cell_4_0);
    shape_five[4].push_back(cell_4_1);
    shape_five[4].push_back(cell_4_2);
    shape_five[4].push_back(cell_4_3);
    shape_five[4].push_back(cell_4_4);


}



void Shape::initialiseShapeSix() {

    // arr[0]
    cell_0_0.isOn = true;
    cell_0_1.isOn = false;
    cell_0_2.isOn = false;
    cell_0_3.isOn = false;
    cell_0_4.isOn = true;

    // arr[1]
    cell_1_0.isOn = true;
    cell_1_1.isOn = false;
    cell_1_2.isOn = false;
    cell_1_3.isOn = false;
    cell_1_4.isOn = true;

    // arr[2]
    cell_2_0.isOn = true;
    cell_2_1.isOn = false;
    cell_2_2.isOn = false;
    cell_2_3.isOn = false;
    cell_2_4.isOn = true;

    // arr[3]
    cell_3_0.isOn = true;
    cell_3_1.isOn = false;
    cell_3_2.isOn = false;
    cell_3_3.isOn = false;
    cell_3_4.isOn = true;

    // arr[4]
    cell_4_0.isOn = true;
    cell_4_1.isOn = true;
    cell_4_2.isOn = true;
    cell_4_3.isOn = true;
    cell_4_4.isOn = true;

    shape_six[0].push_back(cell_0_0);
    shape_six[0].push_back(cell_0_1);
    shape_six[0].push_back(cell_0_2);
    shape_six[0].push_back(cell_0_3);
    shape_six[0].push_back(cell_0_4);

    shape_six[1].push_back(cell_1_0);
    shape_six[1].push_back(cell_1_1);
    shape_six[1].push_back(cell_1_2);
    shape_six[1].push_back(cell_1_3);
    shape_six[1].push_back(cell_1_4);

    shape_six[2].push_back(cell_2_0);
    shape_six[2].push_back(cell_2_1);
    shape_six[2].push_back(cell_2_2);
    shape_six[2].push_back(cell_2_3);
    shape_six[2].push_back(cell_2_4);

    shape_six[3].push_back(cell_3_0);
    shape_six[3].push_back(cell_3_1);
    shape_six[3].push_back(cell_3_2);
    shape_six[3].push_back(cell_3_3);
    shape_six[3].push_back(cell_3_4);

    shape_six[4].push_back(cell_4_0);
    shape_six[4].push_back(cell_4_1);
    shape_six[4].push_back(cell_4_2);
    shape_six[4].push_back(cell_4_3);
    shape_six[4].push_back(cell_4_4);


}



void Shape::initialiseShapeSeven() {

    // arr[0]
    cell_0_0.isOn = false;
    cell_0_1.isOn = true;
    cell_0_2.isOn = true;
    cell_0_3.isOn = true;
    cell_0_4.isOn = false;

    // arr[1]
    cell_1_0.isOn = false;
    cell_1_1.isOn = true;
    cell_1_2.isOn = true;
    cell_1_3.isOn = true;
    cell_1_4.isOn = false;

    // arr[2]
    cell_2_0.isOn = false;
    cell_2_1.isOn = true;
    cell_2_2.isOn = true;
    cell_2_3.isOn = true;
    cell_2_4.isOn = false;

    // arr[3]
    cell_3_0.isOn = false;
    cell_3_1.isOn = true;
    cell_3_2.isOn = true;
    cell_3_3.isOn = true;
    cell_3_4.isOn = false;

    // arr[4]
    cell_4_0.isOn = false;
    cell_4_1.isOn = false;
    cell_4_2.isOn = false;
    cell_4_3.isOn = false;
    cell_4_4.isOn = false;

    shape_seven[0].push_back(cell_0_0);
    shape_seven[0].push_back(cell_0_1);
    shape_seven[0].push_back(cell_0_2);
    shape_seven[0].push_back(cell_0_3);
    shape_seven[0].push_back(cell_0_4);

    shape_seven[1].push_back(cell_1_0);
    shape_seven[1].push_back(cell_1_1);
    shape_seven[1].push_back(cell_1_2);
    shape_seven[1].push_back(cell_1_3);
    shape_seven[1].push_back(cell_1_4);

    shape_seven[2].push_back(cell_2_0);
    shape_seven[2].push_back(cell_2_1);
    shape_seven[2].push_back(cell_2_2);
    shape_seven[2].push_back(cell_2_3);
    shape_seven[2].push_back(cell_2_4);

    shape_seven[3].push_back(cell_3_0);
    shape_seven[3].push_back(cell_3_1);
    shape_seven[3].push_back(cell_3_2);
    shape_seven[3].push_back(cell_3_3);
    shape_seven[3].push_back(cell_3_4);

    shape_seven[4].push_back(cell_4_0);
    shape_seven[4].push_back(cell_4_1);
    shape_seven[4].push_back(cell_4_2);
    shape_seven[4].push_back(cell_4_3);
    shape_seven[4].push_back(cell_4_4);


}



void Shape::initialiseShapeEight() {

    // arr[0]
    cell_0_0.isOn = true;
    cell_0_1.isOn = true;
    cell_0_2.isOn = true;
    cell_0_3.isOn = true;
    cell_0_4.isOn = true;

    // arr[1]
    cell_1_0.isOn = false;
    cell_1_1.isOn = false;
    cell_1_2.isOn = true;
    cell_1_3.isOn = false;
    cell_1_4.isOn = false;

    // arr[2]
    cell_2_0.isOn = false;
    cell_2_1.isOn = false;
    cell_2_2.isOn = true;
    cell_2_3.isOn = false;
    cell_2_4.isOn = false;

    // arr[3]
    cell_3_0.isOn = false;
    cell_3_1.isOn = false;
    cell_3_2.isOn = true;
    cell_3_3.isOn = false;
    cell_3_4.isOn = false;

    // arr[4]
    cell_4_0.isOn = true;
    cell_4_1.isOn = true;
    cell_4_2.isOn = true;
    cell_4_3.isOn = true;
    cell_4_4.isOn = true;

    shape_eight[0].push_back(cell_0_0);
    shape_eight[0].push_back(cell_0_1);
    shape_eight[0].push_back(cell_0_2);
    shape_eight[0].push_back(cell_0_3);
    shape_eight[0].push_back(cell_0_4);

    shape_eight[1].push_back(cell_1_0);
    shape_eight[1].push_back(cell_1_1);
    shape_eight[1].push_back(cell_1_2);
    shape_eight[1].push_back(cell_1_3);
    shape_eight[1].push_back(cell_1_4);

    shape_eight[2].push_back(cell_2_0);
    shape_eight[2].push_back(cell_2_1);
    shape_eight[2].push_back(cell_2_2);
    shape_eight[2].push_back(cell_2_3);
    shape_eight[2].push_back(cell_2_4);

    shape_eight[3].push_back(cell_3_0);
    shape_eight[3].push_back(cell_3_1);
    shape_eight[3].push_back(cell_3_2);
    shape_eight[3].push_back(cell_3_3);
    shape_eight[3].push_back(cell_3_4);

    shape_eight[4].push_back(cell_4_0);
    shape_eight[4].push_back(cell_4_1);
    shape_eight[4].push_back(cell_4_2);
    shape_eight[4].push_back(cell_4_3);
    shape_eight[4].push_back(cell_4_4);


}



void Shape::initialiseShapeNine() {

    // arr[0]
    cell_0_0.isOn = false;
    cell_0_1.isOn = false;
    cell_0_2.isOn = false;
    cell_0_3.isOn = false;
    cell_0_4.isOn = true;

    // arr[1]
    cell_1_0.isOn = false;
    cell_1_1.isOn = false;
    cell_1_2.isOn = false;
    cell_1_3.isOn = true;
    cell_1_4.isOn = true;

    // arr[2]
    cell_2_0.isOn = false;
    cell_2_1.isOn = false;
    cell_2_2.isOn = true;
    cell_2_3.isOn = true;
    cell_2_4.isOn = true;

    // arr[3]
    cell_3_0.isOn = false;
    cell_3_1.isOn = true;
    cell_3_2.isOn = true;
    cell_3_3.isOn = true;
    cell_3_4.isOn = true;

    // arr[4]
    cell_4_0.isOn = true;
    cell_4_1.isOn = true;
    cell_4_2.isOn = true;
    cell_4_3.isOn = true;
    cell_4_4.isOn = true;

    shape_nine[0].push_back(cell_0_0);
    shape_nine[0].push_back(cell_0_1);
    shape_nine[0].push_back(cell_0_2);
    shape_nine[0].push_back(cell_0_3);
    shape_nine[0].push_back(cell_0_4);

    shape_nine[1].push_back(cell_1_0);
    shape_nine[1].push_back(cell_1_1);
    shape_nine[1].push_back(cell_1_2);
    shape_nine[1].push_back(cell_1_3);
    shape_nine[1].push_back(cell_1_4);

    shape_nine[2].push_back(cell_2_0);
    shape_nine[2].push_back(cell_2_1);
    shape_nine[2].push_back(cell_2_2);
    shape_nine[2].push_back(cell_2_3);
    shape_nine[2].push_back(cell_2_4);

    shape_nine[3].push_back(cell_3_0);
    shape_nine[3].push_back(cell_3_1);
    shape_nine[3].push_back(cell_3_2);
    shape_nine[3].push_back(cell_3_3);
    shape_nine[3].push_back(cell_3_4);

    shape_nine[4].push_back(cell_4_0);
    shape_nine[4].push_back(cell_4_1);
    shape_nine[4].push_back(cell_4_2);
    shape_nine[4].push_back(cell_4_3);
    shape_nine[4].push_back(cell_4_4);


}



void Shape::initialiseShapeTen() {

    // arr[0]
    cell_0_0.isOn = true;
    cell_0_1.isOn = true;
    cell_0_2.isOn = true;
    cell_0_3.isOn = true;
    cell_0_4.isOn = false;

    // arr[1]
    cell_1_0.isOn = true;
    cell_1_1.isOn = true;
    cell_1_2.isOn = true;
    cell_1_3.isOn = false;
    cell_1_4.isOn = false;

    // arr[2]
    cell_2_0.isOn = true;
    cell_2_1.isOn = true;
    cell_2_2.isOn = false;
    cell_2_3.isOn = false;
    cell_2_4.isOn = false;

    // arr[3]
    cell_3_0.isOn = true;
    cell_3_1.isOn = false;
    cell_3_2.isOn = false;
    cell_3_3.isOn = false;
    cell_3_4.isOn = false;

    // arr[4]
    cell_4_0.isOn = false;
    cell_4_1.isOn = false;
    cell_4_2.isOn = false;
    cell_4_3.isOn = false;
    cell_4_4.isOn = false;

    shape_ten[0].push_back(cell_0_0);
    shape_ten[0].push_back(cell_0_1);
    shape_ten[0].push_back(cell_0_2);
    shape_ten[0].push_back(cell_0_3);
    shape_ten[0].push_back(cell_0_4);

    shape_ten[1].push_back(cell_1_0);
    shape_ten[1].push_back(cell_1_1);
    shape_ten[1].push_back(cell_1_2);
    shape_ten[1].push_back(cell_1_3);
    shape_ten[1].push_back(cell_1_4);

    shape_ten[2].push_back(cell_2_0);
    shape_ten[2].push_back(cell_2_1);
    shape_ten[2].push_back(cell_2_2);
    shape_ten[2].push_back(cell_2_3);
    shape_ten[2].push_back(cell_2_4);

    shape_ten[3].push_back(cell_3_0);
    shape_ten[3].push_back(cell_3_1);
    shape_ten[3].push_back(cell_3_2);
    shape_ten[3].push_back(cell_3_3);
    shape_ten[3].push_back(cell_3_4);

    shape_ten[4].push_back(cell_4_0);
    shape_ten[4].push_back(cell_4_1);
    shape_ten[4].push_back(cell_4_2);
    shape_ten[4].push_back(cell_4_3);
    shape_ten[4].push_back(cell_4_4);


}





