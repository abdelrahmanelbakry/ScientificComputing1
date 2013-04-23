#ifndef UTILS_H
#define UTILS_H

struct Point
{
    public:
      Point()
      {
          x_=0;
          y_=0;
      }
      Point(double X, double Y)
      {
          x_=X;
          y_=Y;
      }

      double getX() { return x_; }
      double getY() { return y_;}
      void setX(double value) { x_= value;}
      void setY(double value) { y_ = value;}

    private:
        double x_;
        double y_;
};
#endif // UTILS_H
