#ifndef LISTFICHASPLAYER_H
#define LISTFICHASPLAYER_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include"BoxScrabble.h"
class listFichasPlayer;
class ChessPiece:public QGraphicsPixmapItem
{
public:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected:
    QString player;
    BoxScrabble *currentBox;
};

#endif // LISTFICHASPLAYER_H
