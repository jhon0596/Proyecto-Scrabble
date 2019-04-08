#include "BoxScrabble.h"
#include "game.h"
#include <QDebug>

extern Game *game;
BoxScrabble::~BoxScrabble()
{
    delete this;
}
BoxScrabble::BoxScrabble(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //making the Square CHess Box
    setRect(0,0,53,53);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);

}
void BoxScrabble::setOriginalColor(QColor value)
{
    originalColor = value;
    setColor(originalColor);
}
void BoxScrabble::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}
