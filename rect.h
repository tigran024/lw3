#ifndef RECT_H
#define RECT_H

class QPainter;

class Rect
{
public:
    Rect();
    Rect(int x, int y, int w, int h);
    int getX();
    void setX(int newX);

    int getY();
    void setY(int newY1);

    int getW();
    void setW(int newW);

    int getH();
    void setH(int newH);

    void draw(QPainter *painter);
protected:
    int x, y, w, h;
};

#endif // RECT_H
