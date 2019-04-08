#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include<board.h>
#include "BoxScrabble.h"
#include <QMessageBox>
#include"listafichas.h"

class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    void drawZoneFichas(int x, int y, QColor color);
    void displayMainMenu();
    BoxScrabble *collection[15][15];
    void addToScene(QGraphicsItem *item);

    QGraphicsTextItem *codigo;
    void removeFromScene(QGraphicsItem *item);
    void drawBoard();
    void setTurn( QString value);
    void displayFichasPlayer();
    void displayFichasPool();
    ListaFichas listaF;
    void crearLista();
    QList <QGraphicsItem *> listG;
    void listaFPlayer();
    void addFichas();
    ListaFichas listaFP;
    QString letras[29]={"A","B","C","CH","D","E","F","COMODIN","G","H","I","J","L","LL","M","N","O","P","Q","R","RR","S","T","U","V","X","Y","Z","Ñ"};


    QString setImagen(QString caso);
    QString generarFichaAzar();
public slots:
    void start();
    void addInBoard();

private:
    QGraphicsScene *gameScene;

    //QGraphicsTextItem * turnDisplay;
    board *Scrabbleboard;
    QString turn;
    QGraphicsRectItem * drawZF;
    QString getCodigo();


};

#endif // GAME_H
