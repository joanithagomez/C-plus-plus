  #include "Rectangle.h"
#include <math.h>
//**************************************************
// setWidth assigns a value to the width member.   *
//**************************************************

void Rectangle::setWidth(double w)
{
   if( w < 0)
   {
     width = fabs(w);
   }
   else if(w == 0)
   {
     width = 10;
   }
   else
   {
     width = w;
   }
}

//**************************************************
// setLength assigns a value to the length member. *
//**************************************************

void Rectangle::setLength(double len)
{
  if(len < 0)
  {
    length = fabs(len);
  }
  else if(len == 0)
  {
    length = 10;
  }
  else
  {
    length = len;
  }
}

//*****************************************************
// getArea returns the product of width times length. *
//*****************************************************

double Rectangle::getArea() const
{
   return width * length;
}

//*****************************************************
// getPerimeter returns 2 times the sum of width and length. *
//*****************************************************

double Rectangle::getPerimeter() const
{
  return (2*length + 2*width);
}
//*****************************************************
// Function main                                      *
//*****************************************************
