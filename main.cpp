#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <windows.h>
#include "tga.h"
#include "tga.c"
#include <mmsystem.h>
#define JUDULGAME "Buang Sampah"
#include <fstream>
using namespace std;

int heightWindow = 768;
int widthWindow = 1366;
float ratioWindow = widthWindow / (float) heightWindow;
int startFullscreen = 1;
int screenstate = 0;
int stay=0;
int x=0;
int MAX_P = 3;
//double animationInterval = 1.0/10;
double animationInterval = 1.0/500;
double tinggi = 650.0;
bool cekKena = false;
bool cekLewat=false;
int  nyawa=10;
double speed=15;
int tombol1=0;
int score = 0;
float SCREEN_RIGHT=900,SCREEN_LEFT=940,SCREEN_TOP=738, SCREEN_BOTTOM=688;
int highscore=0;

#include "system/scored.cpp"
#include "system/textured.cpp"
void kelompok()
{
    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 8);
    glPushMatrix();
    glBegin(GL_POLYGON);


    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(450, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(962, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(962,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(450, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 9);
    glPushMatrix();
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(0, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(1366, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(1366,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(0, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void nilai1(float x, float y, float z, int digit)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 10+digit);
    glBegin(GL_POLYGON);
    x=900;
    y=738;
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(x, y);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(x+40, y);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(x+40,y-50);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(x, y-50);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void nilai2(float x, float y, float z, int digit)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 10+digit);
    glBegin(GL_POLYGON);
    x=870;
    y=738;
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(x, y);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(x+40, y);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(x+40,y-50);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(x, y-50);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void nilai3(float x, float y, float z, int digit)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 10+digit);
    glBegin(GL_POLYGON);
    x=840;
    y=738;
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(x, y);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(x+40, y);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(x+40,y-50);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(x, y-50);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void nilai4(float x, float y, float z, int digit)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 10+digit);
    glBegin(GL_POLYGON);
    x=810;
    y=738;
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(x, y);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(x+40, y);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(x+40,y-50);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(x, y-50);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void poin()
{
    int digit1, digit2, digit3, digit4, temp;
    if(score>9999) score=9999;
    temp=score;
    digit4=temp%10;
    nilai1(SCREEN_RIGHT-5, SCREEN_BOTTOM-50, 0, digit4);
    temp/= 10;
    digit3=temp%10;
    nilai2(SCREEN_RIGHT-35, SCREEN_BOTTOM-50, 0, digit3);
    temp/= 10;
    digit2=temp%10;
    nilai3(SCREEN_RIGHT-65, SCREEN_BOTTOM-50, 0, digit2);
    temp/= 10;
    digit1=temp%10;
    nilai4(SCREEN_RIGHT-95, SCREEN_BOTTOM-50, 0, digit1);
}

void highpoin()
{
    int digit1, digit2, digit3, digit4, temp;
    if(highscore>9999) highscore=9999;
    temp=highscore;
    digit4=temp%10;
    nilai1(SCREEN_RIGHT-5, SCREEN_BOTTOM-50, 0, digit4);
    temp/= 10;
    digit3=temp%10;
    nilai2(SCREEN_RIGHT-35, SCREEN_BOTTOM-50, 0, digit3);
    temp/= 10;
    digit2=temp%10;
    nilai3(SCREEN_RIGHT-65, SCREEN_BOTTOM-50, 0, digit2);
    temp/= 10;
    digit1=temp%10;
    nilai4(SCREEN_RIGHT-95, SCREEN_BOTTOM-50, 0, digit1);
}

void play()
{

    glPushMatrix();
    glTranslated(-170,-230,0);
    highpoin();
    glPopMatrix();

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 3);
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(450, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(962, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(962,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(450, 768);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 9);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(0, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(1366, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(1366,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(0, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void credits()
{

    glPushMatrix();
    glTranslated(-170,-230,0);
    highpoin();
    glPopMatrix();

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 4);
    glPushMatrix();
    glBegin(GL_POLYGON);


    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(450, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(962, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(962,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(450, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 9);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(0, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(1366, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(1366,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(0, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void exit()
{

    glPushMatrix();
    glTranslated(-170,-230,0);
    highpoin();
    glPopMatrix();

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 5);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(450, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(962, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(962,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(450, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 9);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(0, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(1366, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(1366,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(0, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void gameover_replay()
{
    glPushMatrix();
    glTranslated(-80,-170,0);
    poin();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-240,-170,0);
    highpoin();
    glPopMatrix();

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 6);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(450, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(962, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(962,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(450, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 9);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(0, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(1366, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(1366,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(0, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void gameover_menu()
{
    glPushMatrix();
    glTranslated(-80,-170,0);
    poin();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-240,-170,0);
    highpoin();
    glPopMatrix();

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 7);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(450, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(962, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(962,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(450, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 9);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(0, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(1366, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(1366,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(0, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void hati(float x, float y, float z, int nyawa)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 30-nyawa);
    glBegin(GL_POLYGON);
    x=480;
    y=750;
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(x, y);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(x+80, y);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(x+80,y-80);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(x, y-80);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void hearth()
{
    if (nyawa<0) nyawa=0;
    int coba=nyawa;
    hati(480,738,0,nyawa);
}

class Objek
{
public:
    int N;
    double x, y, sizes;
    double posX, posY;
    int texture;
    int score;

    Objek(); //constructor
    void setObjek(int N, double x, double y, double sizes, int texture); //untuk membuat objek lingkaran
    void buatObjek();
    void setPosition(double posX, double posY); //untuk menentukan posisi objek main character
    void setScore(int score);
    int getScore();
};

class Makanan: public Objek
{
public:
    // void showMakanan();
    void setPosY(double y); //posisi ketinggian makanan
    void setPosX(double x); //posisi x makanan
    double getPosY();
    double getPosX();
    void setTexture(int texture);
    int getTexture();
};

Objek mainChar; //nama objeknya
Makanan makanan[100]; //membuat array makanan

Objek::Objek()
{
    posX = posY = x = y = sizes = 0.0;
    N = texture = score = 0;
}

void Objek::setObjek(int N, double x, double y, double sizes, int texture=-1)
{
    this->N = N;
    this->x = x;
    this->y = y;
    this->sizes = sizes;
    this->texture = texture;
}

void Objek::buatObjek()  //cara manggilnya, panggil setObjek terlebih dahulu
{
    double cons = 2*3.14/this->N;
    double pX, pY;
    double tx, ty;

    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, this->texture);

    glBegin(GL_POLYGON);
    for(int i=0; i<this->N; i++)
    {
        pX = sin(i*cons)*this->sizes+this->x;
        pY = cos(i*cons)*this->sizes+this->y;

        tx = sin(i*cons) * 0.5 + 0.5;
        ty = cos(i*cons) * 0.5 + 0.5;

        glTexCoord2f(tx, ty);
        glVertex2f(pX,pY);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Objek::setPosition(double posX, double posY=0)
{
    glPushMatrix();
    glTranslatef(posX,posY,0);
    glColor3ub(255, 255, 255);
    buatObjek();
    glPopMatrix();
}

void Objek::setScore(int score)
{
    this->score = score;
}

int Objek::getScore()
{
    return this->score;
}

void Makanan::setPosY(double y)
{
    this->posY = y;
}

void Makanan::setPosX(double x)
{
    this->posX = x;
}

double Makanan::getPosY()
{
    return this->posY;
}

double Makanan::getPosX()
{
    return this->posX;
}

void Makanan::setTexture(int texture)
{
    this->texture = texture;
}

int Makanan::getTexture()
{
    return this->texture;
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    switch(action)
    {
    case GLFW_PRESS:
        switch(key)
        {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GL_TRUE);
            break;
        case GLFW_KEY_RIGHT:
            tombol1=1;
            break;
        case GLFW_KEY_LEFT:
            tombol1=2;
            break;
        case GLFW_KEY_DOWN:
            if (stay != -1)
            {
//                    mciSendString("stop music/move.mp3", NULL, NULL, NULL);
//                    mciSendString("play music/move.mp3", NULL, NULL, NULL);
            }
            if (stay == 0 & screenstate < 4 )          //menu awal
            {
                screenstate++;
                if(screenstate>2) screenstate = 0;
            }
            else if (stay == 2 & screenstate >= 4)   //game over
            {
                screenstate++;
                if (screenstate > 5) screenstate=4;
            }
            break;
        case GLFW_KEY_UP:
            if (stay != -1)
            {
//                    mciSendString("stop music/move.mp3", NULL, NULL, NULL);
//                    mciSendString("play music/move.mp3", NULL, NULL, NULL);
            }
            if (stay == 0 & screenstate < 4)  //menu awal
            {
                screenstate--;
                if(screenstate<0) screenstate = 2;
            }
            else if ( stay == 2 & screenstate >= 4)  //game over
            {
                screenstate--;
                if (screenstate < 4) screenstate = 5;

            }
            break;
        case GLFW_KEY_ENTER:
            if(screenstate == 0)   //play
            {
                screenstate = 3;
                stay = -1;
            }
            else if (screenstate == 1)  //credits
            {
                screenstate = 6;
                stay = -1;
            }
            else if(screenstate == 2)  //exit
            {
                glfwSetWindowShouldClose(window, GL_TRUE);
            }
            else if (screenstate == 4)   //gameover_replay
            {

//                    mciSendString("stop music/over.mp3", NULL, NULL, NULL);
//                    mciSendString("stop music/over2.mp3", NULL, NULL, NULL);

                screenstate = 3 ;
                speed = 15;
                nyawa = 10;
                score = 0;
                stay = -1;
            }
            else if (screenstate==5)  //gameover_menu
            {
                screenstate = 0;
                stay = 0;
                speed = 15;
                nyawa = 10;
                score = 0;
            }
            else if (screenstate == 6)  // kelompok
            {
                screenstate = 0;
                stay = 0;
            }
            break;
        }
        break;

    case GLFW_RELEASE:
        switch(key)
        {
        case GLFW_KEY_LEFT:
        case GLFW_KEY_RIGHT:
            tombol1=0;
            break;
        }
    }
}

void setup_viewport(GLFWwindow* window)
{
    // setting viewports size, projection etc
    //float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    //ratio = width / (float) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.f, width, 0, height, 1.f, -1.f); // kiri-kanan-bawah-atas atau manual screen 640x480 (0, 640, 0, 480, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void display()
{

    //main character
    mainChar.setObjek(500,530,80,80,0);//set character kucing
    mainChar.setPosition(x);
    poin();
    hearth();





    //background
    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 1);
    glPushMatrix();
    glBegin(GL_POLYGON);


    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(450, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(962, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(962,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(450, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    glEnable (GL_TEXTURE_2D);
    glBindTexture (GL_TEXTURE_2D, 2);
    glPushMatrix();
    glBegin(GL_POLYGON);
    //glColor3ub(0,0,0);
    glTexCoord2f(0.0f,0.0f);
    glVertex2d(0, 0);
    glTexCoord2f(1.0f,0.0f);
    glVertex2d(1366, 0);
    glTexCoord2f(1.0f,1.0f);
    glVertex2d(1366,768);
    glTexCoord2f(0.0f,1.0f);
    glVertex2d(0, 768);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}

void setTinggi()  // hanya dipanggil di awal. Sebatas penentuan tinggi awal dari semua objek makanan
{
    int j=0;

    for(j; j<MAX_P; j++)
    {
        makanan[j].setPosY(rand()%650+750);
        makanan[j].setPosX(rand()%362+550);
        makanan[j].setTexture(31+rand()%10);
    }

}

#include "system/kolisi.cpp"

void animate()
{
    //animasi makanan turun
    int i=0;

    for(i; i<MAX_P; i++) // i sampai 3, berarti makanan yang dibuat ada 3
    {
        if(makanan[i].getPosY()<0)
        {
            makanan[i].setPosY(rand()%650+750); // posisi Y di random rentang [0-649] + 750 (+750 supaya benar2 berada di atas layar) di random agar makanan tidak turun bersamaan
            makanan[i].setPosX(rand()%362+550); // posisi X di random rentang [0-362] + 5500 (+550 supaya mulai dari screen x = 550)
            makanan[i].setTexture(31+rand()%10);
        }

        tinggi = makanan[i].getPosY() - speed; //semakin besar speed, makin cepat turunnya
        makanan[i].setPosY(tinggi); // update tinggi setiap makanan,
        makanan[i].setObjek(500,0,0,50,makanan[i].getTexture());
        makanan[i].setPosition(makanan[i].getPosX(),makanan[i].getPosY());

        cekKena=isKena(i);
        if(cekKena)
        {

            makanan[i].setPosY(-1000);
            if(speed <= 22)
            {
                speed+=0.5;
            }

            if(makanan[i].getTexture()<38)
            {
                score += 5;
            }    //score nambah 10
            mainChar.setScore(score);
//            mciSendString("stop music/eat.mp3", NULL, NULL, NULL);
//            mciSendString("play music/eat.mp3", NULL, NULL, NULL);


            if(makanan[i].getTexture()>=38)
            {
                nyawa-=1;
            }
            printf("Score kamu: %d\n", score);


        }

        cekLewat=isLewat(i);                    //AAA
        if(cekLewat)                            //AAA
        {
            if(makanan[i].getTexture()<38)
            {
                nyawa-=1;
            }
            //AAA
        }                                       //AAA

        if(nyawa==0)
        {
            NulisHighScore();                        //AAA
            screenstate=4;
            stay = 2;
            //AAA
        }
        //AAA
    }
}

void animate2()
{
    switch(tombol1)
    {
    case 1:
        if(x<352)
        {
            if (speed <=20)
            {
                x+=2;
            }
            else if(speed>20)
            {
                x+=2.5;
            }

            mainChar.setPosition(x);
        }
        break;
    case 2:
        if(x>0)
        {
            if (speed <= 20)
            {
                x-=2;
            }
            else if(speed>20)
            {
                x-=2.5;
            }
            mainChar.setPosition(x);
        }
        break;
    }
}

int main(void)
{
    GetHighScore();
    cout << highscore;
    GLFWwindow* window;
    if (!glfwInit()) exit(EXIT_FAILURE);

    window = glfwCreateWindow(1366, 1024, "Makan Sampah", NULL, NULL);
    window = glfwCreateWindow(widthWindow, heightWindow, JUDULGAME, (startFullscreen) ? glfwGetPrimaryMonitor() : NULL, NULL);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    //transparasi
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,
                GL_ONE_MINUS_SRC_ALPHA);


    int ticks = 0;
    //int frame = 0;
    //mengatur ketinggian objek di awal sebelum di-display
    setTinggi();
    while (!glfwWindowShouldClose(window))
    {

        glfwGetFramebufferSize(window, &widthWindow, &heightWindow);
        ratioWindow = widthWindow / (float) heightWindow;

        setup_viewport(window);

        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glTga();

        switch(screenstate)
        {
        case 0:
            stay = 0;
            nyawa=10;
//                mciSendString("stop music/over.mp3", NULL, NULL, NULL);
//                mciSendString("stop music/over2.mp3", NULL, NULL, NULL);
//                mciSendString("stop music/backsound.mp3", NULL, NULL, NULL);
//                mciSendString("play music/opening.mp3 repeat", NULL, NULL, NULL);
            play();
            break;
        case 1:
            credits();
            break;
        case 2:
            exit();
            break;
        case 3:
//                mciSendString("stop music/opening.mp3", NULL, NULL, NULL);
//                mciSendString("play music/backsound.mp3 repeat", NULL, NULL, NULL);
            animate();
            display();
            break;
        case 4:
//                mciSendString("stop music/backsound.mp3", NULL, NULL, NULL);
//                mciSendString("play music/over.mp3", NULL, NULL, NULL);
//                mciSendString("play music/over2.mp3", NULL, NULL, NULL);
            gameover_replay();
            break;
        case 5:
            gameover_menu();
            break;
        case 6:
            kelompok();
            break;

        }
        double currentTime = glfwGetTime();

        cout << nyawa << endl;

        while (currentTime / animationInterval > ticks)
        {
            animate2();
            ticks++;
            currentTime = glfwGetTime();
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
