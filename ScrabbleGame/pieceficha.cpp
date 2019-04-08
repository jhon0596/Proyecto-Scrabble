#include "pieceficha.h"
#include"game.h"
#include <QGraphicsTextItem>
#include <QBrush>

extern Game *game;
pieceFicha::pieceFicha(QString caso1, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    setRect(0,0,125,125);
    QBrush brush;
    QGraphicsPixmapItem *imagenF =new QGraphicsPixmapItem();
    setImagen(caso1);
    imagenF->setPixmap(caso1);
    brush.setTexture(caso1);
    setBrush(brush);
}

void pieceFicha::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event)
    emit clicked();

}

void pieceFicha:: setImagen(QString caso1){
    this->caso = caso1;
}

QString pieceFicha::getImagen(){
    return caso;
}
