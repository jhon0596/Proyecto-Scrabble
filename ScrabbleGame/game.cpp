#include "game.h"
#include "button.h"
#include <QPixmap>
#include <QDebug>
#include"board.h"
#include"BoxScrabble.h"
#include <QMessageBox>
#include<iostream>
#include"listafichas.h"
#include"node.h"
#include<QLabel>

Game::Game(QWidget *parent ):QGraphicsView(parent)
{

    //Making the Scene
    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,1400,800);

    //Making the view
    setFixedSize(1400,800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(gameScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    crearLista();


}
void Game::drawBoard()
{
    Scrabbleboard = new board();
    drawZoneFichas(0,0,Qt::lightGray);
    drawZoneFichas(1095,0,Qt::lightGray);
    Scrabbleboard->drawBoxes(width()/2-400,0);

}
void Game::displayMainMenu()
{

    //Create the title
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Scrabble");
    QFont titleFont("arial" , 50);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    addToScene(titleText);
    listG.append(titleText);


    QString codigoPartida = getCodigo();
    QGraphicsTextItem *codigo = new QGraphicsTextItem("Codigo de partida: "+ codigoPartida);
    QFont codigoFont("arial" , 25);
    codigo->setFont(codigoFont);
    codigo->setDefaultTextColor(Qt::white);
    int xPosC = 300;
    int yPosC = 19;
    codigo->setPos(xPosC,yPosC);
    addToScene(codigo);
    listG.append(codigo);

    //create Button
    Button * playButton = new Button("Crear Partida");
    int pxPos = width()/2 - playButton->boundingRect().width()/2;
    int pyPos = 300;
    playButton->setPos(pxPos,pyPos);
    //QString codigoPartida = getCodigo();
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    addToScene(playButton);
    listG.append(playButton);



    //Create Quit Button
    Button * UnirPartida = new Button("Unirse a Partida");
    int upxPos = width()/2 - UnirPartida->boundingRect().width()/2;
    int upyPos = 375;
    UnirPartida->setPos(upxPos,upyPos);
    //connect(UnirPartida, SIGNAL(clicked()),this,SLOT(start()));
    addToScene(UnirPartida);
    drawBoard();
    listG.append(UnirPartida);

    Button * quitButton = new Button("Cerrar Partida");
    int qxPos = width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 450;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    addToScene(quitButton);
    drawBoard();
    listG.append(quitButton);
}
void Game::addToScene(QGraphicsItem *item)
{
    gameScene->addItem(item);
}


void Game::setTurn(QString value)
{
    turn = value;
}
void Game::drawZoneFichas(int x, int y,QColor color)
{
    drawZF = new QGraphicsRectItem(x,y,300,800);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    drawZF->setBrush(brush);
    addToScene(drawZF);
}

QString Game:: getCodigo(){

    int codigoPartida = 0 + rand()%(999999-100000);
    QString cp = QString::number(codigoPartida);
    return cp;
}

void Game:: crearLista(){

    for(int i = 0; i <=12 ;i++){
        listaF.addF("A",1);
        listaF.addF("E",1);

    }
    for (int i = 0; i <= 9; ++i) {
        listaF.addF("O",1);

    }

    for (int i = 0; i <= 6; ++i) {
        listaF.addF("I",1);
        listaF.addF("S",6);

    }
    for (int i = 0; i <= 5; ++i) {
        listaF.addF("N",1);
        listaF.addF("R",1);
        listaF.addF("U",1);
        listaF.addF("D",2);
    }
    for (int i = 0; i <= 4; ++i) {
        listaF.addF("L",1);
        listaF.addF("T",1);
        listaF.addF("C",3);

    }
    for (int i = 0; i <= 2; ++i) {
        listaF.addF("G",2);
        listaF.addF("B",3);
        listaF.addF("M",3);
        listaF.addF("P",3);
        listaF.addF("H",4);
        listaF.addF("COMODIN",0);

    }
    listaF.addF("F",4);
    listaF.addF("V",4);
    listaF.addF("Y",4);
    listaF.addF("Q",5);
    listaF.addF("J",8);
    listaF.addF("Ñ",8);
    listaF.addF("X",8);
    listaF.addF("Z",10);
    listaF.addF("CH",5);
    listaF.addF("RR",1);
    listaF.addF("LL",8);


}


void Game::start(){
    for(size_t i =0, n = listG.size(); i < n; i++)
        removeFromScene(listG[i]);
    QGraphicsTextItem* Fichas = new QGraphicsTextItem();
    Fichas->setPos(1170,10);
    Fichas->setZValue(1);
    Fichas->setDefaultTextColor(Qt::black);
    Fichas->setFont(QFont("",14));
    Fichas->setPlainText("Fichas");
    addToScene(Fichas);

    QGraphicsTextItem *Pool = new QGraphicsTextItem();
    Pool->setPos(70,10);
    Pool->setZValue(1);
    Pool->setDefaultTextColor(Qt::black);
    Pool->setFont(QFont("",14));
    Pool->setPlainText("Pool");
    addToScene(Pool);

    addFichas();

}
void Game::removeFromScene(QGraphicsItem *item)
{
    gameScene->removeItem(item);

}
void Game::addFichas(){

    int x = 1110;
    int y = 50;

    for (int i = 0; i < 4; ++i) {
        QString ficha = generarFichaAzar();
        node* nodeD = listaF.deleteFicha(ficha);
        listaFP.addFF(nodeD);
        QString casoF = setImagen(ficha);
        QGraphicsPixmapItem *imagenF =new QGraphicsPixmapItem();
        imagenF->setPixmap(casoF);
        imagenF->setPos(x,y);
        addToScene(imagenF);
        listG.append(imagenF);
        y+=175;

    }
    y=50;

    for (int i = 0; i < 3; ++i) {

        QString ficha = generarFichaAzar();
        node* nodeD = listaF.deleteFicha(ficha);
        listaFP.addFF(nodeD);
        QString casoF = setImagen(ficha);
        QGraphicsPixmapItem *imagenF =new QGraphicsPixmapItem();
        imagenF->setPixmap(casoF);
        imagenF->setPos(x+150,y);
        addToScene(imagenF);
        listG.append(imagenF);
        y+=175;

    }


}

QString Game::generarFichaAzar(){

    QString letra = letras[rand() % 28];
    return letra;

}
QString Game::setImagen(QString caso){

        if(caso =="A"){
          QString ficha = ":/CarpetaFichas/fichaAG.png";
          return ficha ;
        }
        else if (caso == "B") {
            QString ficha = ":/CarpetaFichas/fichaBG.png";
            return ficha ;
        }
        else if (caso == "C") {
            QString ficha = ":/CarpetaFichas/fichaCG.png";
            return ficha;
        }
        else if (caso == "D") {
            QString ficha = ":/CarpetaFichas/fichaDG.png";
            return ficha;
        }
        else if (caso == "CH") {
            QString ficha = ":/CarpetaFichas/fichaCHG.png";
            return ficha;
        }
        else if (caso == "E") {
            QString ficha = ":/CarpetaFichas/fichaEG.png";
            return ficha;
        }
        else if (caso == "F") {
            QString ficha = ":/CarpetaFichas/fichaFG.png";
            return ficha;
        }
        else if (caso == "G") {
            QString ficha = ":/CarpetaFichas/fichaGG.png";
            return ficha;
        }
        else if (caso == "H") {
            QString ficha = ":/CarpetaFichas/fichaHG.png";
            return ficha;
        }
        else if (caso == "I") {
            QString ficha = ":/CarpetaFichas/fichaIG.png";
            return ficha;
        }
        else if (caso == "J") {
            QString ficha = ":/CarpetaFichas/fichaJG.png";
            return ficha;
        }
        else if (caso == "L") {
            QString ficha = ":/CarpetaFichas/fichaLG.png";
            return ficha;
        }
        else if (caso == "LL") {
            QString ficha = ":/CarpetaFichas/fichaLLG.png";
            return ficha;
        }
        else if (caso == "M") {
            QString ficha = ":/CarpetaFichas/fichaMG.png";
            return ficha;
        }
        else if (caso == "N") {
            QString ficha = ":/CarpetaFichas/fichaNG.png";
            return ficha;
        }
        else if (caso == "O") {
            QString ficha = ":/CarpetaFichas/fichaOG.png";
            return ficha;
        }
        else if (caso == "P") {
            QString ficha = ":/CarpetaFichas/fichaPG.png";
            return ficha;
        }
        else if (caso == "Q") {
            QString ficha = ":/CarpetaFichas/fichaQG.png";
            return ficha;
        }
        else if (caso == "R") {
            QString ficha = ":/CarpetaFichas/fichaRG.png";
            return ficha;
        }
        else if (caso == "RR") {
            QString ficha = ":/CarpetaFichas/fichRRG.png";
            return ficha;
        }
        else if (caso == "S") {
            QString ficha = ":/CarpetaFichas/fichaSG.png";
            return ficha;
        }
        else if (caso == "T") {
            QString ficha = ":/CarpetaFichas/fichaTG.png";
            return ficha;
        }
        else if (caso == "U") {
            QString ficha = ":/CarpetaFichas/fichaUG.png";
            return ficha;
        }
        else if (caso == "V") {
            QString ficha = ":/CarpetaFichas/fichaVG.png";
            return ficha;
        }
        else if (caso == "X") {
            QString ficha = ":/CarpetaFichas/fichaXG.png";
            return ficha;
        }
        else if (caso == "Y") {
            QString ficha = ":/CarpetaFichas/fichaYG.png";
            return ficha;
       }
        else if (caso == "Z") {
            QString ficha = ":/CarpetaFichas/fichaZG.png";
            return ficha;
        }
        else if (caso == "Ñ") {
            QString ficha = ":/CarpetaFichas/fichaÑG.png";
            return ficha;
        }
        else{
            QString ficha = ":/CarpetaFichas/fichaEnBlancoG.png";
            return ficha;
        }

}


