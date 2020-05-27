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

void stick(){

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(220,415);
    glVertex2i(220,380);
    glEnd();
}

void stick1(){
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(300,415);
    glVertex2i(300,380);
    glEnd();
}

void stick2(){
    glBegin(GL_LINES);
    glVertex2i(1660,420);
    glVertex2i(1660,385);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(1740,420);
    glVertex2i(1740,385);
    glEnd();
}

void human(){
    //head
    glColor3ub(161,102,94);
    glPushMatrix();
    glTranslatef(260,450,0);
    glScalef(1.0,1.5,0);
    glutSolidSphere(20,100,90);
    glPopMatrix();

    //eye
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(250,460,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(5,100,100);
    glPopMatrix();

    //eye
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(270,460,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(5,100,100);
    glPopMatrix();

    //ear
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(280,450,0);
    glScalef(1.0,5.0,0);
    glutSolidSphere(3,100,100);
    glPopMatrix();

    //ear
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(240,450,0);
    glScalef(1.0,5.0,0);
    glutSolidSphere(3,100,100);
    glPopMatrix();

    //nose
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(259,450);
    glVertex2i(259,445);
    glEnd();

    //mouth
    glBegin(GL_POLYGON);
    glVertex2i(249,440);
    glVertex2i(265,430);
    glVertex2i(270,440);
    glEnd();

    glColor3ub(155,100,80); //Body
    glBegin(GL_POLYGON);
    glVertex2i(245,418);
    glVertex2i(275,418);
    glVertex2i(275,350);
    glVertex2i(245,350);
    glEnd();


    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(245,410);
    glVertex2i(220,385);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(275,410);
    glVertex2i(300,385);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(275,410);
    glVertex2i(300,385);
    glEnd();

    glColor3f(0.0,2.5,1.5);
    glPushMatrix();
    glTranslatef(220,420,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(9,100,100);
    glPopMatrix();

    //stick();

    glColor3f(0.0,2.5,1.5);
    glPushMatrix();
    glTranslatef(300,420,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(9,100,100);
    glPopMatrix();

    //stick1();



}

void human2(){
    //head 2
    glColor3ub(161,102,94);
    glPushMatrix();
    glTranslatef(1700,455,0);
    glScalef(1.0,1.5,0);
    glutSolidSphere(20,100,90);
    glPopMatrix();

    //eye
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(1690,465,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(5,100,100);
    glPopMatrix();

    //eye
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(1710,465,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(5,100,100);
    glPopMatrix();

    //nose
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2i(1700,455);
    glVertex2i(1700,450);
    glEnd();

    //ear
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(1680,455,0);
    glScalef(1.0,5.0,0);
    glutSolidSphere(3,100,100);
    glPopMatrix();

    //ear
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(1720,455,0);
    glScalef(1.0,5.0,0);
    glutSolidSphere(3,100,100);
    glPopMatrix();


    glColor3ub(155,100,80); //Body
    glBegin(GL_POLYGON);
    glVertex2i(1685,425);
    glVertex2i(1715,425);
    glVertex2i(1715,350);
    glVertex2i(1685,350);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(245,410);
    glVertex2i(220,385);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(275,410);
    glVertex2i(300,385);
    glEnd();

    //right stall hand
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(1690,420);
    glVertex2i(1660,390);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(1710,420);
    glVertex2i(1740,390);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(275,410);
    glVertex2i(300,385);
    glEnd();

    glColor3f(0.0,2.5,1.5);
    glPushMatrix();
    glTranslatef(220,420,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(9,100,100);
    glPopMatrix();

    stick();

    glColor3f(0.0,2.5,1.5);
    glPushMatrix();
    glTranslatef(300,420,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(9,100,100);
    glPopMatrix();

    stick1();


    glColor3f(0.0,2.5,1.5);
    glPushMatrix();
    glTranslatef(1660,420,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(9,100,100);
    glPopMatrix();

    glColor3f(0.0,2.5,1.5);
    glPushMatrix();
    glTranslatef(1740,420,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(9,100,100);
    glPopMatrix();
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

void chairs(){

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2i(600,400);
    glVertex2i(600,600);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(400,600);
    glVertex2i(800,600);
    glVertex2i(600,700);
    glVertex2i(400,600);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2i(1300,400);
    glVertex2i(1300,600);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(1100,600);
    glVertex2i(1510,600);
    glVertex2i(1300,700);
    glVertex2i(1100,600);
    glEnd();


    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(450,550);
    glVertex2i(470,460);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(470,460);
    glVertex2i(530,460);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(530,460);
    glVertex2i(550,400);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(470,460);
    glVertex2i(450,400);
    glEnd();

    //right chair

    glBegin(GL_LINES);
    glVertex2i(760,550);
    glVertex2i(740,460);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(740,460);
    glVertex2i(680,460);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(680,460);
    glVertex2i(660,400);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(740,460);
    glVertex2i(760,400);
    glEnd();

    //right umbrella chair

    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(1150,550);
    glVertex2i(1170,460);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(1170,460);
    glVertex2i(1240,460);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(1240,460);
    glVertex2i(1260,400);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(1170,460);
    glVertex2i(1150,400);
    glEnd();

    //right umbrella right chair
    glBegin(GL_LINES);
    glVertex2i(1460,550);
    glVertex2i(1440,460);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(1440,460);
    glVertex2i(1370,460);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(1370,460);
    glVertex2i(1350,400);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(1440,460);
    glVertex2i(1460,400);
    glEnd();

    glColor3ub(162,102,94);
    drawCircleBall(470,540,13,0.6);
    drawCircleBall(740,539.5,13,0.6);
    drawCircleBall(1170,540,13,0.6);




    glBegin(GL_POLYGON);
    glVertex2i(460,515);
    glVertex2i(485,535);
    glVertex2i(510,465);
    glVertex2i(475,465);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2i(470,520);
    glVertex2i(490,550);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(750,515);
    glVertex2i(725,530);
    glVertex2i(709,465);
    glVertex2i(740,465);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(1160,519);
    glVertex2i(1190,534);
    glVertex2i(1205,465);
    glVertex2i(1170,465);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(1160,519);
    glVertex2i(1190,534);
    glVertex2i(1205,465);
    glVertex2i(1170,465);
    glEnd();



}

void stalls2(){

    glBegin(GL_POLYGON);
    glColor3f(0,0,1);
    glVertex2i(1800,200);
    glVertex2i(1600,200);
    glVertex2i(1600,350);
    glVertex2i(1800,350);
    glEnd();
    int x1=1600,y11=200,y22=350;
    glColor3f(0.0, 1.0, 0.0);
    for(int i=0;i<10;i++) {
        x1=x1+20;
        drawLine(x1,y11,y22,2.5);
    }

    drawLine(1610,350,530,2.5);
    drawLine(1790,350,530,2.5);

    glBegin(GL_TRIANGLES);//roof
    glColor3f(0.1, 0.2, 0.3);
    glVertex2i(1600, 530);
    glVertex2i(1700, 580);
    glVertex2i(1800, 530);
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

    //head
    glColor3f(162.0,125.0,1.0);
    glPushMatrix();
    glTranslatef(1825,445,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(25,100,100);
    glPopMatrix();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON); //body
    glVertex2f(1810,410);
    glVertex2i(1840,410);
    glVertex2i(1840,350);
    glVertex2i(1810,350);
    glEnd();

    glBegin(GL_LINES);  //neck
    glLineWidth(5.0);
    glColor3f(1,0,0);
    glVertex2i(1825,420);
    glVertex2i(1825,410);
    glEnd();

    glBegin(GL_LINES);  //neck
    glLineWidth(5.0);
    glColor3f(1,0,0);
    glVertex2i(1825,440);
    glVertex2i(1825,437);
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

    //eye
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(1813,450,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(5,100,100);
    glPopMatrix();

    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(1835,450,0);
    glScalef(1.0,1.0,0);
    glutSolidSphere(5,100,100);
    glPopMatrix();


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
    stick();
    stick1();
    stick2();
    stall();
    chairs();
    boat1();
    human2();
    stalls2();
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
    stick();
    stick1();
    stall();
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
    movingCloud();
    human();
    stick();
    stick1();
    stall1();
    boat1();
    volleyball();
    stall2();
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