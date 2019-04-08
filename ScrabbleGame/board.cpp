#include "board.h"
#include "game.h"
#include "BoxScrabble.h"
#include <QDebug>

extern Game *game;
board::board()
{
    //listaFPlayer();
}

void board::drawBoxes(int x,int y)
{
    int SHIFT = 53;
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++)
        {
            BoxScrabble *box1 = new BoxScrabble();
            game->collection[i][j] = box1;
            box1->rowLoc = i;
            box1->colLoc = j;
            box1->setPos(x+SHIFT*j,y+SHIFT*i);
            if((i+j)%2==0)
                box1->setOriginalColor(Qt::lightGray);
            else
                box1->setOriginalColor(Qt::darkGray);
            game->addToScene(box1);



        }
    }

}




