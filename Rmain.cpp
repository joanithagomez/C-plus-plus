// This program creates three instances of the Rectangle class.
#include <iostream>
#include "Rectangle.h"

using namespace std;


int main()
{
   double number;       // To hold a number
   double totalArea;    // The total area
   double totalPerimeter;// The total perimeter
   Rectangle kitchen;   // To hold kitchen dimensions
   Rectangle bedroom;   // To hold bedroom dimensions
   Rectangle den;       // To hold den dimensions

   // Get the kitchen dimensions.
   cout << "What is the kitchen's length? ";
   cin >> number;                            // Get the length
   kitchen.setLength(number);                // Store in kitchen object
   cout << "What is the kitchen's width? ";
   cin >> number;                            // Get the width
   kitchen.setWidth(number);                 // Store in kitchen object

   // Get the bedroom dimensions.
   cout << "What is the bedroom's length? ";
   cin >> number;                            // Get the length
   bedroom.setLength(number);                // Store in bedroom object
   cout << "What is the bedroom's width? ";
   cin >> number;                            // Get the width
   bedroom.setWidth(number);                 // Store in bedroom object

   // Get the den dimensions.
   cout << "What is the den's length? ";
   cin >> number;                            // Get the length
   den.setLength(number);                    // Store in den object
   cout << "What is the den's width? ";
   cin >> number;                            // Get the width
   den.setWidth(number);                     // Store in den object

   // Calculate the total area of the three rooms.
   totalArea = kitchen.getArea() + bedroom.getArea()
             + den.getArea();

   // Calculate the total perimeter of the three rooms
   totalPerimeter = kitchen.getPerimeter() + bedroom.getPerimeter()
             + den.getPerimeter();

   // Display the total area of the three rooms.
   cout << "The total area of the three rooms is "
        << totalArea << endl;

   // Display the total area of the three rooms.
   cout << "The total perimeter of the three rooms is "
        << totalPerimeter << endl;

   return 0;
}


/*OUTPUT:
What is the kitchen's length? -10
What is the kitchen's width? -5
What is the bedroom's length? -20
What is the bedroom's width? -10
What is the den's length? -1
What is the den's width? -2
The total area of the three rooms is 252
The total perimeter of the three rooms is 96
*/
/*
What is the kitchen's length? 0
What is the kitchen's width? 0
What is the bedroom's length? 0
What is the bedroom's width? 0
What is the den's length? 0
What is the den's width? 0
The total area of the three rooms is 300
The total perimeter of the three rooms is 120
*/
