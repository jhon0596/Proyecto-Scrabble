#include "scrabble.h"
#include "ui_scrabble.h"
#include "listafichas.h"
#include "listafichas.h"
#include <time.h>
#include <QtGui>
#include<QtCore>
Scrabble::Scrabble(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scrabble)
{
    ui->setupUi(this);
}

Scrabble::~Scrabble()
{
    delete ui;
}

void Scrabble::on_crearPartida_clicked()
{
    int codigoPartida = 0 + rand()%(999999-100000);
    QString s = QString::number(codigoPartida);
   // ListaFichas lista = ListaFichas.crearlista();
    QMessageBox::information(this,"Codigo de la partida",s );
}
