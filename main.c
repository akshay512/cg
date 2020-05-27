#include <GL/glut.h>
#include <math.h>
#include<stdio.h>

int boatStatus1 = 1;
const GLfloat deg2Rad = 3.14159/180;
int sc=1;

int cloudStatus = 1;
int sunStatus =  1;
int waterStatus =  1;


float boatX1 = 0;
float boatY1 = 0;

float sunX = 0;
float sunY = 0;

float cloudX = 0;
float cloudY = 0;
float waterX=0;
float waterY=0;

int ballstatus=1;

float ballX = 0;
float ballY = 0;

float fserveX=0;
float fserveY = 0;

int middlemanStatus=0;

float middlepassX=0;
float middlepassY=0;




void DrawCircle(float cx, float cy, float r, int num_segments){

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * (i) / (num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void circle(float xrad,float yrad){
    GLint i;
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++){
        float degInRad = i*deg2Rad;
        glVertex2f(cos(degInRad)*xrad,sin(degInRad)*yrad);
    }
    glEnd();

}

void drawXLine(int x1,int x2,int y1,int y2,float width) {
    glLineWidth(width);

    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x2, y1);
    glVertex2f(x1, y2);
    glEnd();
}

void drawLine(int x,int y1,int y2,float width) {
    glLineWidth(width);

    glBegin(GL_LINES);
    glVertex2f(x, y1);
    glVertex2f(x, y2);
    glEnd();
}

void drawSun(int x)
{
    glColor3f(3.0, 1.0, 0.5);
    DrawCircle(800, 1000, 70, 1000);
}


void cloud(int x){

    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(100, 1300, 60, 2000);//1
    DrawCircle(200,1300, 80, 2000);//2
    DrawCircle(300, 1300, 55, 2000);//3


    DrawCircle(700, 1300, 60, 2000);//1
    DrawCircle(800,1300, 80, 2000);//2
    DrawCircle(900, 1300, 55, 2000);//3

    DrawCircle(1100, 1300, 60, 2000);//1
    DrawCircle(1200,1300, 80, 2000);//2
    DrawCircle(1300, 1300, 55, 2000);//3

    DrawCircle(1700, 1300, 60, 2000);//1
    DrawCircle(1800,1300, 80, 2000);//2
    DrawCircle(1900, 1300, 55, 2000);//3


}

void movingCloud()

{
    if (cloudStatus == 1)
    {
        cloudX +=.5;
    }
    if (cloudX>2000)
    {
        cloudX = -200;
    }
    glPushMatrix();
    glTranslatef(cloudX, cloudY, 0);
    cloud(1);
    glPopMatrix();

}

void moveSun()
{


    if(sunStatus == 1)
    {
        if (sunY>=350)
            sunY=350;
        else
            sunY += .5;
    }

    glPushMatrix();

    glTranslatef(sunX, sunY, 0);

    drawSun(1);
    glPopMatrix();


}

void sky(){

    glBegin(GL_POLYGON); //Sky
    glColor3f(0.4, 0.5, 1.0);
    glVertex2i(0, 1500);
    glVertex2i(2000, 1500);
    glColor3f(0.7, 0.7, 1.0);
    glVertex2i(2000, 0);
    glVertex2i(0, 0);
    glEnd();

}
void ocean(){

    glBegin(GL_POLYGON); // Ocean
    glColor3f(0.2, 0.3, 1.1);
    glVertex2i(0, 600);
    glVertex2i(550, 400);
    glVertex2i(2000, 300);
    glVertex2i(2000, 1150);
    glVertex2i(0, 1150);
    glEnd();


}

void volleyball() {
    glBegin(GL_LINE_STRIP);
    glColor3f(0, 0,0);
    glVertex2i(900, 440);
    glVertex2i(900, 330);
    glVertex2i(1000, 640);
    glVertex2i(1000, 730);
    glVertex2i(900, 440);
//    glVertex2i(849, 514-40);

    glEnd();
    glBegin(GL_LINES);
    glColor3f(0, 0,0);
    glVertex2i(900, 330);
    glVertex2i(900, 300);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0, 0,0);
    glVertex2i(1000, 640);
    glVertex2i(1000, 600);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(370, 300);
    glVertex2i(1400, 300);
    glVertex2i(1500, 600);
    glVertex2i(550, 600);
    glVertex2i(370, 300);
    glEnd();
    //stick man
}

void drawmovingwater(){
    int x=0,y=0.01;

    glBegin(GL_POLYGON); //Middle ground
    glColor3f(1, 1,0);
    glVertex2i(0, 0);
    glVertex2i(2100,0);
    glVertex2i(2100, 200+600);
    glVertex2i(1100,0);
    glColor3f(1,1,0);
    glVertex2i(0,0);
    glVertex2i(2100, 600+200);
    glVertex2i(650, 600+200);
    glVertex2i(0, 600+200);
    glEnd();
}

void stage() {
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2i(750,780);
    glVertex2i(1380,780);
    glVertex2i(1350,750);
    glVertex2i(780,750);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.6,.2,.3);
    glVertex2i(780,750);
    glVertex2i(1350,750);
    glVertex2i(1320,730);
    glVertex2i(800,730);
    glEnd();
    glColor3f(1,0.5,0);
    drawLine(820,730,450,5);
    drawLine(860,730,450,5);
    glColor3f(0,0,0);
    int x=730;
    for(int i=0;i<9;i++){
        drawXLine(825,857,x,x-30,2.5);
        x=x-30;
    }
    glColor3f(1,0.5,0);
    drawLine(1300,730,450,5);
    drawLine(1260,730,450,5);
    glColor3f(0,0,0);
    x=730;
    for(int i=0;i<9;i++){
        drawXLine(1263,1297,x,x-30,2.5);
        x=x-30;
    }
    glBegin(GL_POLYGON);
    glVertex2i(750,450);
    glVertex2i(1350,450);
    glVertex2i(1350,380);
    glVertex2i(750,380);
    glEnd();

    //mic
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex2f(1040, 452);
    glVertex2f(1060, 452);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(1050, 450);
    glVertex2f(1050, 500);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(1030, 480);
    glVertex2f(1070, 520);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(1070,515);
    glVertex2i(1078,520);
    glVertex2i(1078,530);
    glVertex2i(1070,525);
    glEnd();



    //speaker 1
    glBegin(GL_POLYGON);
    glVertex2i(650,530);
    glVertex2i(720,530);
    glVertex2i(720,380);
    glVertex2i(650,380);
    glEnd();
    glColor3f(1,1,1);
    DrawCircle(683,500,10,1000);
    glColor3f(0,0,0);
    DrawCircle(683,500,8,1000);

    glColor3f(1,1,1);
    DrawCircle(683,420,20,1000);
    glColor3f(0,0,0);
    DrawCircle(683,420,17,1000);

    //speaker 2
    glBegin(GL_POLYGON);
    glVertex2i(650+720,530);
    glVertex2i(720+720,530);
    glVertex2i(720+720,380);
    glVertex2i(650+720,380);
    glEnd();
    glColor3f(1,1,1);
    DrawCircle(683+720,500,10,1000);
    glColor3f(0,0,0);
    DrawCircle(683+720,500,8,1000);

    glColor3f(1,1,1);
    DrawCircle(683+720,420,20,1000);
    glColor3f(0,0,0);
    DrawCircle(683+720,420,17,1000);

}

void sand() {
    //water wave looping
    if(waterStatus == 1)
    {
        if (waterY<=-100){
            waterY=-100;
            waterStatus = 0;
        }
        else
            waterY -= .05;
    }
    if(waterStatus == 0){
        if (waterY>=0){
            waterY=0;
            waterStatus = 1;
        }
        else
            waterY += .05;
    }


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(waterX,waterY,0);
    drawmovingwater();
    glPopMatrix();

}
void human(){

    //Human 1
    glBegin(GL_POLYGON);    //BODY
    glVertex2f(240,300);
    glVertex2f(270.5,300);
    glVertex2f(270.5,425.5);
    glVertex2f(240,425.5);
    glEnd();

    glBegin(GL_POLYGON);    //hand
    glVertex2f(270.5,415);
    glVertex2f(350,300);
    glVertex2f(350,290);
    glVertex2f(270.5,390);
    glEnd();

    glBegin(GL_POLYGON);    //hand
    glVertex2f(240.5,415);
    glVertex2f(150,300);
    glVertex2f(150,290);
    glVertex2f(240.5,390);
    glEnd();

    glBegin(GL_POLYGON);    //neck
    glVertex2f(250.5,425.5);
    glVertex2f(260.5,425.5);
    glVertex2f(260.5,435.5);
    glVertex2f(250.5,435.5);
    glEnd();

    glPushMatrix();     //head
    glColor3f(1.0,1.0,1.0);
    glScalef(0.5,1,1);
    glTranslatef(510,451,0);
    circle(19,19);
    glPopMatrix();


}

void drawCircleBall(GLfloat x, GLfloat y, GLfloat r,GLfloat width) {
    static const double inc = M_PI / 12;
    static const double max = 2 * M_PI;
    glLineWidth(width);
    glBegin(GL_POLYGON);

    for(double d = 0; d < max; d += inc) {
        glVertex2f(cos(d) * r + x, sin(d) * r + y);
    }
    glEnd();
}

void drawCircleOutline(GLfloat x, GLfloat y, GLfloat r,GLfloat width) {
    static const double inc = M_PI / 12;
    static const double max = 2 * M_PI;
    glLineWidth(width);
    glBegin(GL_LINE_LOOP);

    for(double d = 0; d < max; d += inc) {
        glVertex2f(cos(d) * r + x, sin(d) * r + y);
    }
    glEnd();
}
void leftHand(int x,int y){
    glBegin(GL_LINES);
    glVertex2i(x,y-21);
    glVertex2i(x-16,y-31);
    glEnd();
}
void rightHand(int x,int y){
    glBegin(GL_LINES);
    glVertex2i(x,y-21);
    glVertex2i(x+18,y-31);
    glEnd();
}

void leftLeg(int x,int y){
    glBegin(GL_LINES);
    glVertex2i(x,y-51);
    glVertex2i(x-16,y-61);
    glEnd();
}
void rightLeg(int x,int y){
    glBegin(GL_LINES);
    glVertex2i(x,y-51);
    glVertex2i(x+18,y-61);
    glEnd();
}

void stickman(GLfloat x,GLfloat y,GLfloat r){
    glColor3f(0,0,0);
    glPushMatrix();
    drawCircleOutline(x,y,10,1);
    glPopMatrix();
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(x,y-8);
    glVertex2i(x,y-51);
    glEnd();
    leftHand(x,y);
    rightHand(x,y);
    leftLeg(x,y);
    rightLeg(x,y);
}

void man(float x,float y)
{

    //face
    float radius = 25.0;
    glColor3f(1.0,0.90,0.85);

    glBegin(GL_POLYGON);
    for(float i=0;i<360;i+=0.1)
        glVertex2f(cos(i)*radius+x,sin(i)*radius+y+150);
    glEnd();

//    radius=6.0;
//    glColor3f(1.0,1.0,1.0);
//    glBegin(GL_POLYGON);
//    for(float i=0;i<360;i++)
//        glVertex2f(cos(i)*radius+x+20,sin(i)*radius+y+160);
//    glEnd();
//
//    radius=3.0;
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_POLYGON);
//    for(float i=0;i<360;i++)
//        glVertex2f(cos(i)*radius+x+20,sin(i)*radius+y+160);
//    glEnd();
    glColor3f(0.0,0.0,0.0);
    drawCircleBall(x+20,y+160,2,1);


    //Hair
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-25,y+150);
    glVertex2f(x-25,y+170);
    glVertex2f(x-15,y+195);
    glVertex2f(x+30,y+195);
    glVertex2f(x+30,y+175);
    glVertex2f(x+30,y+170);
    glEnd();


    //neck
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x-10.0,y+100.0);
    glVertex2f(x-10.0,y+120.0);
    glVertex2f(x+10.0,y+120.0);
    glVertex2f(x+10.0,y+100.0);
    glEnd();


    //lefthand
    glBegin(GL_POLYGON);
    glVertex2f(x+10,y+90);
    glVertex2f(x+10,y+100);
    glVertex2f(x+50,y+85);
    glVertex2f(x+50,y+75);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+50,y+75);
    glVertex2f(x+50,y+85);
    glVertex2f(x+75,y+105);
    glVertex2f(x+75,y+95);
    glEnd();



    //shirt
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-25,y);
    glVertex2f(x-25,y+75);
    glVertex2f(x-10,y+100);
    glVertex2f(x+10,y+100);
    glVertex2f(x+25,y+75);
    glVertex2f(x+25,y);
    glEnd();



    //leftleg
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x-15,y-75);
    glVertex2f(x-15,y);
    glVertex2f(x-5,y);
    glVertex2f(x-5,y-75);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-15,y-75);
    glVertex2f(x-5,y-65);
    glVertex2f(x+15,y-70);
    glVertex2f(x+15,y-75);
    glEnd();

    //right leg

    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x+10,y-75);
    glVertex2f(x+10,y);
    glVertex2f(x+20,y);
    glVertex2f(x+20,y-75);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x+10,y-75);
    glVertex2f(x+20,y-65);
    glVertex2f(x+40,y-70);
    glVertex2f(x+40,y-75);
    glEnd();

    //shoes



    //pant
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-25,y);
    glVertex2f(x-25,y+25);
    glVertex2f(x+25,y+25);
    glVertex2f(x+25,y);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x-25,y-30);
    glVertex2f(x-25,y);
    glVertex2f(x-2,y);
    glVertex2f(x-2,y-30);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+4,y-30);
    glVertex2f(x+4,y);
    glVertex2f(x+25,y);
    glVertex2f(x+25,y-30);
    glEnd();



    //right hand
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x,y+70);
    glVertex2f(x,y+80);
    glVertex2f(x+55,y+65);
    glVertex2f(x+55,y+55);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+55,y+55);
    glVertex2f(x+55,y+65);
    glVertex2f(x+80,y+95);
    glVertex2f(x+80,y+85);
    glEnd();


    //mouth
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+25,y+125);
    glVertex2f(x+10,y+125);
    glVertex2f(x+10,y+127);
    glEnd();

    //nose

    glBegin(GL_LINE_STRIP);
    glVertex2f(x+32,y+140);
    glVertex2f(x+32,y+150);
    glVertex2f(x+34,y+155);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x-10,y+160);
    glVertex2f(x-20,y+160);
    glVertex2f(x-20,y+140);
    glVertex2f(x-10,y+140);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(x-20,y+150);
    glVertex2f(x-10,y+150);
    glEnd();


//    //Draws the axe
//    glColor3f(0.8456,0.684,0.4424);
//    glBegin(GL_POLYGON);
//    glVertex2f(x-95,y+95);
//    glVertex2f(x-95,y+105);
//    glVertex2f(x+95,y+105);
//    glVertex2f(x+95,y+95);
//    glEnd();
//
//
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_POLYGON);
//    glVertex2f(x-90,y+65);
//    glVertex2f(x-90,y+115);
//    glVertex2f(x-60,y+115);
//    glVertex2f(x-60,y+65);
//    glEnd();

    //Right fist
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x+80,y+85);
    glVertex2f(x+80,y+105);
    glVertex2f(x+90,y+105);
    glVertex2f(x+90,y+95);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x+80,y+105);
    glVertex2f(x+80,y+100);
    glVertex2f(x+82.5,y+105);
    glVertex2f(x+82.5,y+100);
    glVertex2f(x+85,y+105);
    glVertex2f(x+85,y+100);
    glVertex2f(x+87,y+105);
    glVertex2f(x+87,y+100);
    glVertex2f(x+89.5,y+105);
    glVertex2f(x+89.5,y+100);
    glEnd();

    //left fist
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x+65,y+95);
    glVertex2f(x+65,y+105);
    glVertex2f(x+75,y+105);
    glVertex2f(x+75,y+95);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x+65,y+105);
    glVertex2f(x+65,y+100);
    glVertex2f(x+67.5,y+105);
    glVertex2f(x+67.5,y+100);
    glVertex2f(x+70,y+105);
    glVertex2f(x+70,y+100);
    glVertex2f(x+72.5,y+105);
    glVertex2f(x+72.5,y+100);
    glVertex2f(x+74.5,y+105);
    glVertex2f(x+74.5,y+100);
    glEnd();

}
void man2(float x, float y) {
    glColor3f(1.0,0.90,0.85);
    DrawCircle(x,y+60,25,1000);
    //eye
    drawCircleOutline(x+20,y+40,5,1);

    //Hair
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-25,y+55);
    glVertex2f(x-25,y+65);
    glVertex2f(x-15,y+95);
    glVertex2f(x+25,y+95);
    glVertex2f(x+25,y+75);
    glVertex2f(x+25,y+90);
    glEnd();

    //right hand
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x+5,y+15);
    glVertex2f(x+5,y+25);
    glVertex2f(x+25,y+15);
    glVertex2f(x+25,y+5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+20,y+5);
    glVertex2f(x+20,y+15);
    glVertex2f(x+35,y+30);
    glVertex2f(x+35,y+20);
    glEnd();


    //neck
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x-5.0,y+100.0-80);
    glVertex2f(x-5.0,y+120.0-80);
    glVertex2f(x+5.0,y+120.0-80);
    glVertex2f(x+5.0,y+100.0-80);
    glEnd();

    //mouth
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x+15,y+43);
    glVertex2f(x+10,y+43);
    glVertex2f(x+10,y+45);
    glEnd();

    //nose

    glBegin(GL_LINE_STRIP);
    glVertex2f(x+20,y+50);
    glVertex2f(x+20,y+55);
    glVertex2f(x+25,y+60);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x-5,y+65);
    glVertex2f(x-10,y+65);
    glVertex2f(x-10,y+55);
    glVertex2f(x-5,y+55);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(x-10,y+60);
    glVertex2f(x-5,y+60);
    glEnd();

    //eye
    drawCircleBall(x+15,y+65,3,1);

    //shirt
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-15,y-40);
    glVertex2f(x-15,y+75-60);
    glVertex2f(x-2,y+100-70);
    glVertex2f(x+2,y+100-70);
    glVertex2f(x+15,y+75-60);
    glVertex2f(x+15,y-40);

    glEnd();

    //pant
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-15,y-50);
    glVertex2f(x-15,y-25);
    glVertex2f(x+15,y-25);
    glVertex2f(x+15,y-50);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x-15,y-80);
    glVertex2f(x-15,y-50);
    glVertex2f(x-2,y-50);
    glVertex2f(x-2,y-80);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+4,y-80);
    glVertex2f(x+4,y-50);
    glVertex2f(x+15,y-50);
    glVertex2f(x+15,y-80);
    glEnd();

    glColor3f(1.0,0.90,0.85);

    //lefthand
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x,y+10);
    glVertex2f(x+30,y);
    glVertex2f(x+30,y-10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+30,y-10);
    glVertex2f(x+30,y);
    glVertex2f(x+45,y+15);
    glVertex2f(x+45,y+5);
    glEnd();

    //left fist
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x+65-27,y+95-88);
    glVertex2f(x+65-27,y+105-88);
    glVertex2f(x+75-27,y+105-88);
    glVertex2f(x+75-27,y+95-88);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x+65-27,y+105-88);
    glVertex2f(x+65-27,y+100-88);
    glVertex2f(x+67.5-27,y+105-88);
    glVertex2f(x+67.5-27,y+100-88);
    glVertex2f(x+70-27,y+105-88);
    glVertex2f(x+70-27,y+100-88);
    glVertex2f(x+72.5-27,y+105-88);
    glVertex2f(x+72.5-27,y+100-88);
    glVertex2f(x+74.5-27,y+105-88);
    glVertex2f(x+74.5-27,y+100-88);
    glEnd();


    //Right fist
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x+80-45,y+85-66);
    glVertex2f(x+80-45,y+105-66);
    glVertex2f(x+90-45,y+105-66);
    glVertex2f(x+90-45,y+95-66);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x+80-45,y+105-66);
    glVertex2f(x+80-45,y+100-66);
    glVertex2f(x+82.5-45,y+105-66);
    glVertex2f(x+82.5-45,y+100-66);
    glVertex2f(x+85-45,y+105-66);
    glVertex2f(x+85-45,y+100-66);
    glVertex2f(x+87-45,y+105-66);
    glVertex2f(x+87-45,y+100-66);
    glVertex2f(x+89.5-45,y+105-66);
    glVertex2f(x+89.5-45,y+100-66);
    glEnd();

    glColor3f(1.0,0.90,0.85);

    //leg left
    drawCircleBall(x-10,y-80,8,1);

    //leg right
    drawCircleBall(x+10,y-80,8,1);

}

void man3(float x, float y) {
    glColor3f(1.0,0.90,0.85);
    DrawCircle(x,y+60,25,1000);
    //eye
    drawCircleOutline(x+20,y+40,5,1);

    //Hair
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x+25,y+55);
    glVertex2f(x+25,y+65);
    glVertex2f(x+15,y+95);
    glVertex2f(x-25,y+95);
    glVertex2f(x-25,y+75);
    glVertex2f(x-25,y+90);
    glEnd();

    //right hand
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x-5,y+15);
    glVertex2f(x-5,y+25);
    glVertex2f(x-25,y+15);
    glVertex2f(x-25,y+5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x-20,y+5);
    glVertex2f(x-20,y+15);
    glVertex2f(x-35,y+30);
    glVertex2f(x-35,y+20);
    glEnd();


    //neck
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x-5.0,y+100.0-80);
    glVertex2f(x-5.0,y+120.0-80);
    glVertex2f(x+5.0,y+120.0-80);
    glVertex2f(x+5.0,y+100.0-80);
    glEnd();

    //mouth
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x-15,y+43);
    glVertex2f(x-10,y+43);
    glVertex2f(x-10,y+45);
    glEnd();

    //nose

    glBegin(GL_LINE_STRIP);
    glVertex2f(x-20,y+50);
    glVertex2f(x-20,y+55);
    glVertex2f(x-25,y+60);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(x+5,y+65);
    glVertex2f(x+10,y+65);
    glVertex2f(x+10,y+55);
    glVertex2f(x+5,y+55);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(x+10,y+60);
    glVertex2f(x+5,y+60);
    glEnd();

    //eye
    drawCircleBall(x-15,y+65,3,1);

    //shirt
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-15,y-40);
    glVertex2f(x-15,y+75-60);
    glVertex2f(x-2,y+100-70);
    glVertex2f(x+2,y+100-70);
    glVertex2f(x+15,y+75-60);
    glVertex2f(x+15,y-40);

    glEnd();

    //pant
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(x-15,y-50);
    glVertex2f(x-15,y-25);
    glVertex2f(x+15,y-25);
    glVertex2f(x+15,y-50);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x-15,y-80);
    glVertex2f(x-15,y-50);
    glVertex2f(x-2,y-50);
    glVertex2f(x-2,y-80);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x+4,y-80);
    glVertex2f(x+4,y-50);
    glVertex2f(x+15,y-50);
    glVertex2f(x+15,y-80);
    glEnd();

    glColor3f(1.0,0.90,0.85);

    //lefthand
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x,y+10);
    glVertex2f(x-30,y);
    glVertex2f(x-30,y-10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x-30,y-10);
    glVertex2f(x-30,y);
    glVertex2f(x-45,y+15);
    glVertex2f(x-45,y+5);
    glEnd();

    //left fist
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x-65+27,y+95-88);
    glVertex2f(x-65+27,y+105-88);
    glVertex2f(x-75+27,y+105-88);
    glVertex2f(x-75+27,y+95-88);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x-65+27,y+105-88);
    glVertex2f(x-65+27,y+100-88);
    glVertex2f(x-67.5+27,y+105-88);
    glVertex2f(x-67.5+27,y+100-88);
    glVertex2f(x-70+27,y+105-88);
    glVertex2f(x-70+27,y+100-88);
    glVertex2f(x-72.5+27,y+105-88);
    glVertex2f(x-72.5+27,y+100-88);
    glVertex2f(x-74.5+27,y+105-88);
    glVertex2f(x-74.5+27,y+100-88);
    glEnd();


    //Right fist
    glColor3f(1.0,0.90,0.85);
    glBegin(GL_POLYGON);
    glVertex2f(x-80+45,y+85-66);
    glVertex2f(x-80+45,y+105-66);
    glVertex2f(x-90+45,y+105-66);
    glVertex2f(x-90+45,y+95-66);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(x-80+45,y+105-66);
    glVertex2f(x-80+45,y+100-66);
    glVertex2f(x-82.5+45,y+105-66);
    glVertex2f(x-82.5+45,y+100-66);
    glVertex2f(x-85+45,y+105-66);
    glVertex2f(x-85+45,y+100-66);
    glVertex2f(x-87+45,y+105-66);
    glVertex2f(x-87+45,y+100-66);
    glVertex2f(x-89.5+45,y+105-66);
    glVertex2f(x-89.5+45,y+100-66);
    glEnd();

    glColor3f(1.0,0.90,0.85);

    //leg left
    drawCircleBall(x-10,y-80,8,1);

    //leg right
    drawCircleBall(x+10,y-80,8,1);

}

void stall() {
    glBegin(GL_POLYGON);//stall body
    glColor3f(1,0.5,0);
    glVertex2i(400,200);
    glVertex2i(120,200);
    glVertex2i(120,350);
    glVertex2i(400,350);
    glEnd();
    int x = 120,y1=200,y2=350;
    glColor3f(1.0, 0.0, 0.0);
    for(int i=0;i<13;i++) {
        x=x+20;
        drawLine(x,y1,y2,2.5);
    }
    drawLine(130,350,500,2.5);
    drawLine(390,350,500,2.5);
    glBegin(GL_TRIANGLES);//roof
    glColor3f(0.1, 0.2, 0.3);
    glVertex2i(120, 500);
    glVertex2i(260, 550);
    glVertex2i(400, 500);
    glEnd();


}

void stall1(){
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex2i(350,200);
    glVertex2i(120,200);
    glVertex2i(120,350);
    glVertex2i(350,350);
    glEnd();
    int x=120,y1=200,y2=350;
    glColor3f(1.0, 0.0, 0.0);
    for(int i=0;i<11;i++) {
        x=x+20;
        drawLine(x,y1,y2,2.5);
    }
    drawLine(130,350,500,2.5);
    drawLine(340,350,500,2.5);
    glBegin(GL_TRIANGLES);//roof
    glColor3f(0.1, 0.2, 0.3);
    glVertex2i(120, 500);
    glVertex2i(260, 550);
    glVertex2i(350, 500);
    glEnd();

}

void stall2(){
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glScalef(0.5,1,1);
    glTranslatef(3650,440.5,0);
    circle(19,19);
    glPopMatrix();

    glBegin(GL_POLYGON); //body
    glVertex2f(1810,410);
    glVertex2i(1840,410);
    glVertex2i(1840,350);
    glVertex2i(1810,350);
    glEnd();

    glBegin(GL_LINES);  //neck
    glLineWidth(5.0);
    glColor3f(1,0,0);
    glVertex2i(1825,425);
    glVertex2i(1825,410);
    glEnd();

    glBegin(GL_POLYGON);    //left hand
    glVertex2i(1810,410);
    glVertex2i(1770,300);
    glVertex2i(1770,290);
    glVertex2i(1810,390);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(1840,410);
    glVertex2i(1880,300);
    glVertex2i(1880,290);
    glVertex2i(1840,390);
    glEnd();



    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex2i(1950,200);
    glVertex2i(1720,200);
    glVertex2i(1720,350);
    glVertex2i(1950,350);
    glEnd();
    int x=1720,y1=200,y2=350;
    glColor3f(1.0, 0.0, 0.0);
    for(int i=0;i<11;i++) {
        x=x+20;
        drawLine(x,y1,y2,2.5);
    }
    drawLine(1730,350,500,2.5);
    drawLine(1940,350,500,2.5);
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0);
    glVertex2i(1730,500);
    glVertex2i(1940,500);
    glVertex2i(1940,550);
    glVertex2i(1730,550);
    glEnd();


}

void humans(){

    glPushMatrix();     //head
    glColor3f(1.0,1.0,1.0);
    glScalef(0.5,1,1);
    glTranslatef(499.5,317.5,0);
    circle(19,19);
    glPopMatrix();

    glBegin(GL_POLYGON);    //body
    glVertex2f(238,220);
    glVertex2f(263,220);
    glVertex2f(263,290);
    glVertex2f(238,290);
    glEnd();

    glBegin(GL_POLYGON);    //neck
    glVertex2f(245.75,290);
    glVertex2f(254,290);
    glVertex2f(254,310);
    glVertex2f(245.75,310);
    glEnd();

    glBegin(GL_POLYGON);    //hand Left
    glVertex2f(238,280);
    glVertex2f(220,240);
    glVertex2f(220,232);
    glVertex2f(238,260);
    glEnd();


    glBegin(GL_POLYGON);    //hand Right
    glVertex2f(263,280);
    glVertex2f(278,240);
    glVertex2f(278,232);
    glVertex2f(263,260);
    glEnd();


    glBegin(GL_POLYGON);    //leg left
    glVertex2f(246.25,166);
    glVertex2f(238,166);
    glVertex2f(238,220);
    glVertex2f(246.25,220);
    glEnd();


    glBegin(GL_POLYGON);    //leg right
    glVertex2f(254,166);
    glVertex2f(262.25,166);
    glVertex2f(262.25,220);
    glVertex2f(254,220);
    glEnd();

}



void moveboat1(int x)
{
    glBegin(GL_POLYGON); //BOAT
    glColor3f(1.9, 0.0, 0.0);
    glVertex2i(100,800);
    glVertex2i(400, 800);
    glVertex2i(480,900);
    glVertex2i(50,900);
    glVertex2i(100,800);
    glEnd();

    glBegin(GL_POLYGON); //BOAT
    glColor3f(0.0, 1.8, 0.5);
    glVertex2i(120,900);
    glVertex2i(240, 900);
    glVertex2i(190,960);
    glEnd();

    glBegin(GL_POLYGON); //BOAT
    glColor3f(1.0, 1.7, 0.0);
    glVertex2i(240,900);
    glVertex2i(420, 900);
    glVertex2i(350,960);
    glVertex2i(190,960);
    glVertex2i(240,900);
    glEnd();
}

void ball() {
    glColor3f(0,1,0);
    drawCircleBall(450,470,15,2);
}

void moveBall(int x) {
    if(ballstatus == 1)
    {
        if (ballY>=200){

            ballY=200;
            ballstatus=0;
        }
        else if(ballX>=600){
            ballX = 600;
        }
        else{
            ballY += .5;
            ballX += .5;
        }
    }

    if(ballstatus==0){
        if(ballX>=500){
            ballX = 500;
            ballstatus = 2;
        }
        else{
            ballX += .5;
        }
    }
    if(ballstatus==2){
        if(ballX>=800 && ballY<=50){
            ballX = 800;
            ballstatus = 3;
        }
        else{
            ballX +=.5;
            ballY -=.5;
        }
    }

    if(ballstatus==3) {
        if(ballY>=80){
            ballY=80;
            ballstatus = 4;
        }
        else{
            ballX -= .5;
            ballY +=.3;
        }

    }
    if(ballstatus==4) {
        if(ballY<=20){
            ballY=20;
            ballstatus = 4;
        }
        else{
            ballY -= .2;
            ballX -= .5;
        }
    }


    glPushMatrix();
    glTranslatef(ballX,ballY,0);
    ball();
    glPopMatrix();
}



void firstServe() {
    if(fserveX>=81){
        fserveX = 81;
    }
    else {
        fserveX += .5;
        fserveY -= .5;
    }

    glPushMatrix();
    glTranslatef(fserveX,fserveY,0);
    man2(420,480);
    glPopMatrix();
}
//void middletouchBall() {
//
//    glPushMatrix();
//    glTranslatef();
//    stickman(700,500,10);
//    glPopMatrix();
//}

void playvolleyball() {
    volleyball();

    man2(860,570);
    man2(790,400);
    man2(580,590);
    man2(700,500);
    man3(501+500,451);
    man3(860+500,570);
    man3(790+500,400);
    man3(580+500,590);
    man3(700+500,500);
    moveBall(1);
    firstServe();
//    middletouchBall();
}

void boat1()
{
    if (boatStatus1 == 1)
    {
        boatX1 +=.5;
    }
    if (boatX1>2000)
    {
        boatX1 = -600;
    }
    glPushMatrix();
    glTranslatef(boatX1, boatY1, 0);
    moveboat1(1);
    glPopMatrix();
}


void keyboard(unsigned char key,int x,int y)

{

    if(key=='c'){
        sc=2;
    }
    else if(key=='C') {
        sc=1;
    }
    else if(key=='Z') {
        sc=3;
    }

}


void scene1()
{
    sky();
    moveSun();
    ocean();
    sand();
    movingCloud();
    human();
    boat1();
    stall();
    humans();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}
void scene2()
{
    sky();
    moveSun();
    ocean();
    sand();
    movingCloud();
    human();
    stall();
    humans();
    boat1();
    stage();
    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}

void scene3()
{
    sky();
    moveSun();
    ocean();
    sand();
    stall1();
    stall2();
    movingCloud();
//    human();
//    humans();
    boat1();
//    stage();
    playvolleyball();
//    man2(700,500);

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    if(sc==1){
        scene1();
        glutPostRedisplay();
    }else if(sc==2){
        scene2();
        glutPostRedisplay();
    }else if(sc==3){
        scene3();
        glutPostRedisplay();
    }
}

void mouse(int button, int state, int mousex, int mousey)
{
    printf("x= %d   :   y=%d\n",mousex,mousey);
}

void myInit(void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 2000.0, 0.0, 1500.0);
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(2000, 1500);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("projectphase1_4MT17CS047");
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    myInit();
    glutMainLoop();
}