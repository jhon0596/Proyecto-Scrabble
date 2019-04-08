#ifndef PIECEFICHA_H
#define PIECEFICHA_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class pieceFicha:public QObject, public QGraphicsRectItem
{
     Q_OBJECT

public:
    pieceFicha(QString caso1, QGraphicsItem * parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setImagen(QString caso1);
    QString getImagen();


signals:
    void clicked();
private:
    QString caso;
};

#endif // PIECEFICHA_H
