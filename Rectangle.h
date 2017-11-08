// Rectangle class declaration.
class Rectangle
{
   private:
      double width;
      double length;
   public:
      void setWidth(double);
      void setLength(double);
      double getWidth() const
      { return width; }

      double getLength() const
      { return length; }

      double getPerimeter() const;
      double getArea() const;
};
