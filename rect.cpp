#include "rect.h"
#include <QPainter>

Rect::Rect()
    :Rect(0, 0, 0, 0)
{}

Rect::Rect(int x, int y, int w, int h)
    :x(x), y(y), w(w), h(h)
{}

int Rect::getX()
{
    return x;
}

void Rect::setX(int newX)
{
    x = newX;
}

int Rect::getY()
{
    return y;
}

void Rect::setY(int newY)
{
    y = newY;
}

int Rect::getW()
{
    return w;
}

void Rect::setW(int newW)
{
    w = newW;
}

int Rect::getH()
{
    return h;
}

void Rect::setH(int newH)
{
    h = newH;
}

void Rect::draw(QPainter *painter)
{
    QPen pen(Qt::black);
    QBrush brush(Qt::gray);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(getX(), getY(), getW(), getH());

}
