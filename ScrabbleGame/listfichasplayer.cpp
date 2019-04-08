#include "listfichasplayer.h"
#include "game.h"
#include <QDebug>
#include <QGraphicsTextItem>
#include <QBrush>

extern Game *game;
listFichasPlayer::listFichasPlayer(QString player, QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    side = player;

}

void listFichasPlayer:: mousePressEvent (QGraphicsSceneMouseEvent *event){

    if(this == game->pieceToMove){
        //game->pieceToMove.ge

    }
}
