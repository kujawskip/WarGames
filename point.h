#ifndef POINT_H
#define POINT_H
class Point {
    int X;
    int Y;
public:
    int getX();
    void setX(int value);
    int getY();
    void setY(int value);
    friend bool operator<(const Point p1,const Point p2)
    {
        if(p1.X == p2.X)
        {
            return p1.Y<p2.Y;
        }
        return p1.X<p2.X;
    }
};
#endif // POINT_H
