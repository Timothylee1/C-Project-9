/*!
@file       pi.c
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Assignment 6
@assignment Deriving Pi
@date       16/10/2021
@brief      This file contains two codes to derive the value of pi. 
            calculus_pi() uses the calculus algorithm which computes a quarter circle area 
            by dividing it into a series of rectangles. These rectangles have similar 
            width but different heights, and height is chosen such that the circle's 
            circumference passes through the midpoint of the rectangle's top. The sum of 
            the area of rectangles are then used to approximate the value of pi.
            leibniz_pi() uses an infinite arithmetic series of additions and subtraction 
            to approximate the value of pi.
            The input from main() to both functions should be >= 1, else the program will
            not run correctly.
*//*______________________________________________________________________________________*/
#include <math.h> //for sqrt() & pow()
#define r 2.0F //defined r for radius of circle as 2.0 type double.

/*!
@brief  This function calculus_pi() contains code that takes input from main() source file
        and int slices copies the value. slices represents the numer of rectangles present,
        as such, slices has to be >=1. The more rectangles present, the higher the accuracy. 
        As the number of rectangles increases to infinity, each rectangle's width decreases 
        to zero, and the summation of the areas of all these rectangles will provide pi's 
        value.

@param  count & slices are declared as an integer
        width & x & height & area & summed_rect are declared as type double

@return summed_rect assigned value, type double
*//*_______________________________________________________________________________________*/
double calculus_pi(int slices){ //slices represents number of rectangles
    double width, x = 0, height; 
    double area = 0, summed_rect = 0;
    
    //Width of rectangle is determined by radius of circle / number of rectangles
    width = r / slices; 
    for (int count = 0; count < slices; count++) {
        
        //X is distance from mid-point of rectangle to centre of circle
        x = width * (count) + (width/2);

        //Using pythaogras theorem to find height
        height = sqrt (r * r - x * x);

        //Area of rectangle is width * height 
        area = width * height;

        //Summed_rect is the summation of the rectangles' area
        summed_rect += area;
    }

    return summed_rect;
}

/*!
@brief  This function leibniz_pi() contains code that takes input from main() source file
        and int terms copies the value. terms refers to the number of terms in the leibniz
        arithmetic series, as such the number of terms should be larger than 0. The code 
        breaks up the series into sequences, and sequences into numerators & denominators. 
        It calculates the numerator and denominator before creating the sequence, 
        for example, numerator is 3, and denominator is 4, the sequence will be ¾. 
        After that, the sequence will be added to pi. Finally, pi is multiplies by 4 to  
        to arrive at the final approximation of pi.

@param  count & terms declared as an integer
        numerator & denominator & pi are declared as type double

@return pi * 4, type double
*//*_______________________________________________________________________________________*/
double leibniz_pi(int terms) { //terms represent the number of terms in the leibniz series
    int count = 0;
    double numerator = 0.0, denominator = 0.0; 
    double pi = 0;

    while (count < terms) {
        
        //Numerator of the arithmetic sequence
        numerator = pow(-1, count);

        //Denominator of the arithmetic sequence
        denominator = 1 + 2 * (count++);

        //Combines the numerator and denominator to form the expression for the individual 
        //sequence and then adds it to pi
        pi += numerator/denominator;
    }

    return pi * 4;
}
