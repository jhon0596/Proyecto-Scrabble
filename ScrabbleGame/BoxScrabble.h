#ifndef BOX_H
#define BOX_H
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class BoxScrabble:public QGraphicsRectItem
{
public:
    BoxScrabble(QGraphicsItem *parent=0);
    ~BoxScrabble();
    void setOriginalColor(QColor value);
    void setColor(QColor color);
    int rowLoc;
    int colLoc;
private:
    QColor originalColor;
    QBrush brush;
};

#endif // BOX_H
