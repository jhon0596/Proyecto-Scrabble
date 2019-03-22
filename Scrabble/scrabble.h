#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <QWidget>
#include <QtGui>
#include<QtCore>
#include <QMessageBox>

namespace Ui {
class Scrabble;
}

class Scrabble : public QWidget
{
    Q_OBJECT

public:
    explicit Scrabble(QWidget *parent = 0);
    ~Scrabble();

private slots:
    void on_crearPartida_clicked();

private:
    Ui::Scrabble *ui;
};

#endif // SCRABBLE_H
