#include <QApplication>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsItem>
#include<QGraphicsView>
#include<QBrush>
#include<QImage>
#include<QGraphicsPixmapItem>
#include <QtWidgets>
#include <QPushButton>
#include <Game.h>

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
       game = new Game();
       game->show();
       game->displayMainMenu();
    return a.exec();
}
