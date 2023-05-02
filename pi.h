/*!
@file       pi.h
@author     Timothy Lee (timothykexin.lee@digipen.edu.sg)
@course     RSE 1201
@section    Assignment 6
@assignment Deriving Pi
@date       16/10/2021
@brief      This file is a header file containing the declaration of functions in pi.c 
            source file. 
*//*______________________________________________________________________________________*/


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
double calculus_pi(int slices);

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
double leibniz_pi(int terms);
