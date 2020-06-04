#include <Game.h>
#include <Button2.h>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <Button.h>
#include <QMediaPlayer>
#include <QMediaPlaylist>

//QList<int> List = {5,10,15,20};
QList<int> List = {30,40,20,19,89,63,42,66,23,67,37,16,14,37,22,44,50,75,45,67,89,25,62,58};
//QList<int> List = {20,20,20,20};

QString final="";

QGraphicsTextItem *arrTxt;
QFont arrFont("comic sans", 20);
QFont gameover("comic sans", 50);
int listLen = List.count();

int score = 0;
QGraphicsTextItem *scoreTxt;

int pcScore =0;
QGraphicsTextItem *pcScoreTxt;

Game::Game()
{
       // set up the screen
       setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       // set up the scene
       scene = new QGraphicsScene();
       scene->setSceneRect(0,0,800,400);
       setScene(scene);
}
int getCoins(int arr[], int n)
{
    // Find sum of even positioned coins
    int evenSum = 0;
    for (int i = 0; i < n; i += 2)
        evenSum += arr[i];

    // Find sum of odd positioned coins
    int oddSum = 0;
    for (int i = 1; i < n; i += 2)
        oddSum += arr[i];

    // Print even or odd coins depending upon which sum is greater.
    if(oddSum >= evenSum){
        return oddSum;
    }else{
        return evenSum;
    }
}
//int arr[]={1,1,20,10};
int arr[]={30,40,20,19,89,63,42,66,23,67,37,16,14,37,22,44,50,75,45,67,89,25,62,58};
//int arr[]={20,20,20,20};
int RequiredScore= getCoins(arr,listLen);
void Game::displayMainMenu()
{
        //background image and scene
        scene->setBackgroundBrush(QBrush(QImage(":/image/Coin.jpg")));
        //create the play button
        Button2* playButton = new Button2(QString("Play"));
        int bxPos = 235 - playButton->boundingRect().width()/2;
        int byPos = 185;
        playButton->setPos(bxPos,byPos);
        connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
        scene->addItem(playButton);

        // create the quit button
        Button2* quitButton = new Button2(QString("Quit"));
        int qxPos = 575 - quitButton->boundingRect().width()/2;
        int qyPos = 185;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);

        //play background music
        QMediaPlaylist *music = new QMediaPlaylist();
        music->addMedia(QUrl("qrc:/sound/Spongebob Music - Background Music (HD).mp3"));
        music->setPlaybackMode(QMediaPlaylist::Loop);
        QMediaPlayer *musicplay = new QMediaPlayer();
        musicplay->setPlaylist(music);
//        musicplay->play();
}

void Game::Remove1() // Left bottom reomval
{
    // last click (end of list)
    if(::List.count()==2){
        ::score=::score+::List[0];
        ::List.removeFirst();
        ::pcScore=::pcScore+::List[::List.count()-1];
        ::List.removeLast();
        ::scoreTxt->setHtml("Your Score: "+ QString::number(::score));
        ::pcScoreTxt->setHtml("PC Score: "+ QString::number(::pcScore));
        if (::score == ::pcScore){
            ::arrTxt->setDefaultTextColor("yellow");
            ::arrTxt->setHtml("TIE!");
            ::arrTxt->setPos(300,30);
            ::arrTxt->setFont(::gameover);
        }
        else if (::score >= ::RequiredScore){
            ::arrTxt->setDefaultTextColor("blue");
            ::arrTxt->setHtml("YOU WIN!");
            ::arrTxt->setPos(215,30);
            ::arrTxt->setFont(::gameover);
        }
        else {
            ::arrTxt->setDefaultTextColor("red");
            ::arrTxt->setHtml("YOU LOST!");
            ::arrTxt->setPos(215,30);
            ::arrTxt->setFont(::gameover);
        }
    }
    // list with more than 2 values
    else if(::List.count()!=0){
        ::score=::score+::List[0];
        ::List.removeFirst();
        ::pcScore=::pcScore+::List[::List.count()-1];
        ::List.removeLast();
        ::final = "";
        for(int i = 0; i < ::List.count(); i++){
            QString tmp = QString::number(::List[i]);
            ::final=::final+" "+tmp;
        }
        ::arrTxt->setHtml(::final);
        ::scoreTxt->setHtml("Your Score: "+ QString::number(::score));
        ::pcScoreTxt->setHtml("PC Score: "+ QString::number(::pcScore));
    }
}

void Game::Remove2() // right bottom reomval
{
    // last click (end of list)
    if(::List.count()==2){
        ::score=::score+::List[::List.count()-1];
        ::List.removeLast();
        ::pcScore=::pcScore+::List[::List.count()-1];
        ::List.removeLast();
        ::scoreTxt->setHtml("Your Score: "+ QString::number(::score));
        ::pcScoreTxt->setHtml("PC Score: "+ QString::number(::pcScore));
        if (::score == ::pcScore){
            ::arrTxt->setDefaultTextColor("white");
            ::arrTxt->setHtml("TIE!");
            ::arrTxt->setPos(215,30);
            ::arrTxt->setFont(::gameover);
        }
        else if (::score >= ::RequiredScore){
            ::arrTxt->setDefaultTextColor("blue");
            ::arrTxt->setHtml("YOU WIN!");
            ::arrTxt->setPos(215,30);
            ::arrTxt->setFont(::gameover);
        }
        else {
            ::arrTxt->setDefaultTextColor("red");
            ::arrTxt->setHtml("YOU LOST!");
            ::arrTxt->setPos(215,30);
            ::arrTxt->setFont(::gameover);
        }
    }
    // list with more than 2 values
    else if(::List.count()!=0){
        ::score=::score+::List[::List.count()-1];
        ::List.removeLast();
        ::pcScore=::pcScore+::List[::List.count()-1];
        ::List.removeLast();
        ::final = "";
        for(int i = 0; i < ::List.count(); i++){
            QString tmp = QString::number(::List[i]);
            ::final=::final+" "+tmp;
        }
        ::arrTxt->setHtml(::final);
        ::scoreTxt->setHtml("Your Score: "+ QString::number(::score));
        ::pcScoreTxt->setHtml("PC Score: "+ QString::number(::pcScore));
    }
}

void Game::start()
{
    // create new background
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage(":/image/background.jpg")));
    // create the left button
    Button2* leftButton = new Button2(QString("Left"));
    int bxPos = 235 - leftButton->boundingRect().width()/2;
    int byPos = 185;
    leftButton->setPos(bxPos,byPos);
    connect(leftButton,SIGNAL(clicked()),this,SLOT(Remove1()));
    scene->addItem(leftButton);

    // create the right button
    Button2* rightButton = new Button2(QString("Right"));
    int qxPos = 575 - rightButton->boundingRect().width()/2;
    int qyPos = 185;
    rightButton->setPos(qxPos,qyPos);
    connect(rightButton,SIGNAL(clicked()),this,SLOT(Remove2()));
    scene->addItem(rightButton);

    for(int i = 0; i < ::List.count(); i++){
        QString tmp = QString::number(::List[i]);
        ::final=::final+" "+tmp;
    }

    ::scoreTxt = scene->addText("Your Score: "+ QString::number(::score));
    ::scoreTxt->setFont(::arrFont);
    ::scoreTxt->setDefaultTextColor("blue");
    ::scoreTxt->setPos(50, 350);

    ::pcScoreTxt = scene->addText("PC Score: "+ QString::number(::pcScore));
    ::pcScoreTxt->setFont(::arrFont);
    ::pcScoreTxt->setDefaultTextColor("red");
    ::pcScoreTxt->setPos(550, 350);

    ::arrTxt = scene->addText(::final);
    ::arrTxt->setFont(::arrFont);
    ::arrTxt->setPos(-10*::listLen+400,30);
    ::arrTxt->setTextWidth(500);
}
