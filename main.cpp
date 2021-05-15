    //The Scenario of Sea-Port in Bangladesh//
    //      Mehedi Hasan       ID: CSE06507618 //
    // Chandrika Roy Chowdhury ID: CSE06507620 //

#include<iostream>
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#define PI 3.1416
#include <stdlib.h>
static float
    cx = 0,
    cy = 0,
    cloud_1 = 0,
    cloud_2 = 0,
    cloud_3 = 0,
    shipMove1 = 0,
    shipMove2 = 0,
    shipMove3 = 0,
    shipMove4 = 0,
    carMove1 = 0,
    carMove2 = 0,
    cramHook = 0;



void circle(float radiusX, float radiusY){
    int i;
    float angle=0.0;
    glBegin(GL_POLYGON);
        for(i=0; i<100; i++){
            angle=2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));
        }
        glEnd();
}

void halfCircle(float radiusX, float radiusY){
    int i;
    float angle=0.0;
    glBegin(GL_POLYGON);
        for(i=0; i<50; i++){
            angle=2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));
        }
        glEnd();
}


void init(){
    glClearColor(0, 0, 0, 0);
    glOrtho(-50,50,-50,50,-1,1);
}


void declare(char *string)
{
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *string++);
}


void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

    //SKY
    glBegin(GL_QUADS);
        glColor3f(0.52f, 0.80f, 0.92f);
        glVertex2d(-50.0,50.0);
        glVertex2d(50.0,50.0);
        glVertex2d(50.0,42.0);
        glVertex2d(-50.0,42.0);
    glEnd();

    //SEA
    glBegin(GL_QUADS);
        glColor3f(0.11f, 0.53f, 0.84f);
        glVertex2d(-50.0,42.0);
        glVertex2d(50.0,42.0);
        glVertex2d(50.0,-30.0);
        glVertex2d(-50.0,-30.0);
    glEnd();

    glBegin(GL_QUADS);//sun shine
        glColor3f(1.0f,1.0f,0.6f);
        glVertex2d(-5.0,42.0);
        glVertex2d(5.0,42.0);
         glColor3f(0.11f, 0.53f, 0.84f);
        glVertex2d(15.0,30.0);
        glVertex2d(-15.0,30.0);
    glEnd();

    //sun Start
    glBegin(GL_POLYGON);
        glColor3f(0.94f,0.96f,0.96f);
        glVertex2d(0.0,43.0);
        //glColor3f(0.94f,0.94f,0.94f);//*
        glColor3f(0.52f, 0.80f, 0.92f);
        glVertex2d(8.0,50.0);
        glVertex2d(14.0,50.0);
        glColor3f(0.94f,0.96f,0.96f);
        glVertex2d(0.0,42.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,43.0);
        //glColor3f(0.94f,0.94f,0.94f);//*
        glColor3f(0.52f, 0.80f, 0.92f);
        glVertex2d(3.0,50.0);
        glVertex2d(5.0,50.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,43.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,43.0);
        //glColor3f(0.94f,0.94f,0.94f);//*
        glColor3f(0.52f, 0.80f, 0.92f);
        glVertex2d(-3.0,50.0);
        glVertex2d(-5.0,50.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,43.0);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,43.0);
        //glColor3f(0.94f,0.94f,0.94f);//*
        glColor3f(0.52f, 0.80f, 0.92f);
        glVertex2d(-8.0,50.0);
        glVertex2d(-14.0,50.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,42.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,42.0);
        glColor3f(0.52f, 0.80f, 0.92f);
        glVertex2d(14.0,47.0);
        glVertex2d(16.0,44.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,42.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,42.0);
        glColor3f(0.52f, 0.80f, 0.92f);
        glVertex2d(-14.0,47.0);
        glVertex2d(-16.0,44.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,42.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,43.0);
        glColor3f(0.52f, 0.80f, 0.92f);
        glVertex2d(-1.0,50.0);
        glVertex2d(1.0,50.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2d(0.0,43.0);
    glEnd();

    glPushMatrix();
    glTranslatef(0.0,41.7,0.0);
        glColor3f(1.0f,1.0f,0.6f);
        halfCircle(5,6);
    glPopMatrix();
    //Sun End




    //CLOUD-1
    glPushMatrix();
    glTranslatef(cloud_1+19.0,46.0,0.0);
        glColor3f(0.91f,0.92f,0.93f);
        circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_1+20.0,46.0,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_1+21.0,46.0,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_1+20.0,47.0,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    //CLOUD-1 End


    //CLOUD-2
    glPushMatrix();
    glTranslatef(cloud_2-26.0,47.0,0.0);
        glColor3f(0.91f,0.92f,0.93f);
        circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_2-25.0,47.0,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_2-24.0,47.0,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_2-25.0,48.0,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    //CLOUD-2 End
    //CLOUD-3
    glPushMatrix();
    glTranslatef(cloud_3-10.0,44.5,0.0);
        glColor3f(0.91f,0.92f,0.93f);
        circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_3-9.0,44.5,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_3-8.0,44.5,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(cloud_3-9.0,45.5,0.0);
        glColor3f(0.91f,0.92f,0.93f);
            circle(1,2);
    glPopMatrix();
    //CLOUD-3 End







    //Ship-1
    glColor3f(0.0f, 0.4f, 0.4f);//ship Body1
    glBegin(GL_QUADS);
        glVertex2d(-41.0,-11.0);
        glVertex2d(-5.0,-11.0);
        glVertex2d(-8.0,-16.0);
        glVertex2d(-38.0,-16.0);
    glEnd();
    glColor3f(0.0f, 0.4f, 0.4f);//ship Body2
    glBegin(GL_QUADS);
        glVertex2d(-9.5,-10.0);
        glVertex2d(-4.0,-10.0);
        glVertex2d(-5.0,-11.0);
        glVertex2d(-10.5,-11.0);
    glEnd();

    glPushMatrix();//C1
    glTranslatef(-9,-11,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.2,0.5);
    glPopMatrix();

    glPushMatrix();//C2
    glTranslatef(-7.5,-11,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.2,0.5);
    glPopMatrix();

    glPushMatrix();//C3
    glTranslatef(-6,-11,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.2,0.5);
    glPopMatrix();


    glColor3f(0.8f, 0.7f, 0.1f);//ship Room-1
    glBegin(GL_QUADS);
        glVertex2d(-39.0,-8.0);
        glVertex2d(-30.0,-8.0);
        glVertex2d(-29.0,-11.0);
        glVertex2d(-39.0,-11.0);
    glEnd();

    glColor3f(0.8f, 0.4f, 0.2f);//ship Room-2
    glBegin(GL_QUADS);
        glVertex2d(-39.0,-5.0);
        glVertex2d(-32.0,-5.0);
        glVertex2d(-31.0,-8.0);
        glVertex2d(-39.0,-8.0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);//ship Chad
    glBegin(GL_QUADS);
        glVertex2d(-36.5,-2.5);
        glVertex2d(-34.5,-2.5);
        glVertex2d(-34.0,-5.0);
        glVertex2d(-36.0,-5.0);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);//1
    glBegin(GL_LINES);
        glVertex2d(-36.360,-3.198);
        glVertex2d(-34.359,-3.201);
    glEnd();

    glColor3f(0.0f, 0.4f, 0.4f);//ship Body3
    glBegin(GL_QUADS);
        glVertex2d(-42.0,-10.0);
        glVertex2d(-36.0,-10.0);
        glVertex2d(-35.0,-11.0);
        glVertex2d(-41.0,-11.0);
    glEnd();
    glPushMatrix();//C1
    glTranslatef(-36.5,-11,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.2,0.5);
    glPopMatrix();

    glPushMatrix();//C2
    glTranslatef(-38,-11,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.2,0.5);
    glPopMatrix();

    glPushMatrix();//C3
    glTranslatef(-39.5,-11,0);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.2,0.5);
    glPopMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2d(-34.0,-12.0);
        glVertex2d(-30.0,-12.0);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2d(-26.0,-12.0);
        glVertex2d(-22.0,-12.0);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
        glVertex2d(-18.0,-12.0);
        glVertex2d(-14.0,-12.0);
    glEnd();
    //ship inside Container
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2d(-25.0,-7.0);
        glVertex2d(-15.0,-7.0);
        glVertex2d(-15.0,-11.0);
        glVertex2d(-25.0,-11.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(-24.0,-7.0);
        glVertex2d(-24.0,-11.0);
        glVertex2d(-23.0,-7.0);
        glVertex2d(-23.0,-11.0);
        glVertex2d(-22.0,-7.0);
        glVertex2d(-22.0,-11.0);
        glVertex2d(-21.0,-7.0);
        glVertex2d(-21.0,-11.0);
        glVertex2d(-20.0,-7.0);
        glVertex2d(-20.0,-11.0);
        glVertex2d(-19.0,-7.0);
        glVertex2d(-19.0,-11.0);
        glVertex2d(-18.0,-7.0);
        glVertex2d(-18.0,-11.0);
        glVertex2d(-17.0,-7.0);
        glVertex2d(-17.0,-11.0);
        glVertex2d(-16.0,-7.0);
        glVertex2d(-16.0,-11.0);
    glEnd();
    //Ship-1 End


    //Ship Moving-4
    glPushMatrix();
    glTranslatef(shipMove4,0.0f,0.0f);
    glColor3f(0.15f,0.15f,0.15f);
        glBegin(GL_QUADS);
        glVertex2d(-38.7,40.3);
        glVertex2d(-38.1,40.3);
        glVertex2d(-38.0,39.5);
        glVertex2d(-38.6,39.5);
    glEnd();
    glColor3f(0.85f,0.85f,0.85f);
        glBegin(GL_QUADS);
        glVertex2d(-39.0,39.5);
        glVertex2d(-35.0,39.5);
        glVertex2d(-34.5,38.5);
        glVertex2d(-39.5,38.5);
    glEnd();
    glColor3f(0.15f,0.15f,0.15f);//Window
        glBegin(GL_QUADS);
        glVertex2d(-36.2,39.4);
        glVertex2d(-35.2,39.4);
        glVertex2d(-35.2,38.8);
        glVertex2d(-36.2,38.8);
    glEnd();
    glColor3f(0.14f,0.14f,0.45f);//B
        glBegin(GL_QUADS);
        glVertex2d(-40.5,38.5);
        glVertex2d(-33.5,38.5);
        glVertex2d(-34.0,37.0);
        glVertex2d(-40.0,37.0);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_LINES);
        glVertex2d(-40.335,38.007);
        glVertex2d(-33.666,38.001);
    glEnd();
    glPopMatrix();
    //Ship Moving-4 End


    //Ship Moving-3
    glPushMatrix();
    glTranslatef(shipMove3,0.0f,0.0f);

        glColor3f(0.30f,0.30f,0.30f);
        glBegin(GL_QUADS);
        glVertex2d(12.0,35.5);
        glVertex2d(13.0,35.5);
        glVertex2d(12.5,34.5);
        glVertex2d(11.5,34.5);
        glEnd();

        glColor3f(0.90f,0.90f,0.90f);//B
        glBegin(GL_QUADS);
        glVertex2d(7.5,34.5);
        glVertex2d(13.5,34.5);
        glVertex2d(14.5,32.5);
        glVertex2d(6.5,32.5);
        glEnd();

        glPushMatrix();//Circle-1
        glTranslatef(8.5,33.5,0.0);
        glColor3f(0.0f,0.0f,0.0f);
        circle(0.45,0.8);
        glPopMatrix();
        glPushMatrix();//Circle-2
        glTranslatef(10.5,33.5,0.0);
        glColor3f(0.0f,0.0f,0.0f);
        circle(0.45,0.8);
        glPopMatrix();
        glPushMatrix();//Circle-3
        glTranslatef(12.5,33.5,0.0);
        glColor3f(0.0f,0.0f,0.0f);
        circle(0.45,0.8);
        glPopMatrix();

        glColor3f(0.30f,0.30f,0.30f);//D
        glBegin(GL_QUADS);
        glVertex2d(5.0,32.5);
        glVertex2d(16.0,32.5);
        glVertex2d(15.0,30.0);
        glVertex2d(6.0,30.0);
        glEnd();
        glColor3f(1.0f,1.0f,1.0f);
        glBegin(GL_LINES);//1
        glVertex2d(5.2,32.0);
        glVertex2d(15.8,32.0);
    glEnd();
    glPopMatrix();
    //Ship Moving-3 End


    //Ship Moving-2
    glPushMatrix();
    glTranslatef(shipMove2,0.0,0.0);

    glColor3f(0.0f,0.0f,0.0f);//C1
    glBegin(GL_QUADS);
        glVertex2d(-32.0,26.0);
        glVertex2d(-31.0,27.0);
        glVertex2d(-31.0,25.0);
        glVertex2d(-32.0,25.0);
    glEnd();
    /*glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
        glVertex2d(-31.9,26.0);
        glVertex2d(-31.0,26.0);
    glEnd()*/


    glColor3f(0.0f,0.0f,0.0f);//C2
    glBegin(GL_QUADS);
        glVertex2d(-30.0,26.0);
        glVertex2d(-29.0,27.0);
        glVertex2d(-29.0,25.0);
        glVertex2d(-30.0,25.0);
    glEnd();
  /*  glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
        glVertex2d(-29.9,26.0);
        glVertex2d(-29.0,26.0);
    glEnd();*/

    glColor3f(0.94f,0.94f,0.94f);//B1
    glBegin(GL_QUADS);
        glVertex2d(-33.0,25.0);
        glVertex2d(-23.0,25.0);
        glVertex2d(-22.0,22.0);
        glVertex2d(-34.2,22.0);
    glEnd();
    glPushMatrix();//Circle-1
    glTranslatef(-24.0,23.5,0.0);
    glColor3f(0.0f,0.0f,0.0f);
        circle(0.5,1);
    glPopMatrix();
    glPushMatrix();//Circle-2
    glTranslatef(-26.0,23.5,0.0);
    glColor3f(0.0f,0.0f,0.0f);
        circle(0.5,1);
    glPopMatrix();
    glPushMatrix();//Circle-3
    glTranslatef(-28.0,23.5,0.0);
    glColor3f(0.0f,0.0f,0.0f);
        circle(0.5,1);
    glPopMatrix();
    glPushMatrix();//Circle-4
    glTranslatef(-30.0,23.5,0.0);
    glColor3f(0.0f,0.0f,0.0f);
        circle(0.5,1);
    glPopMatrix();
    glPushMatrix();//Circle-5
    glTranslatef(-32.0,23.5,0.0);
    glColor3f(0.0f,0.0f,0.0f);
        circle(0.5,1);
    glPopMatrix();
    glColor3f(0.01f,0.2f,0.38f);
    glBegin(GL_QUADS);
        glVertex2d(-35.0,22.0);
        glVertex2d(-20.0,22.0);
        glVertex2d(-22.0,18.5);
        glVertex2d(-34.0,18.5);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);//1
        glVertex2d(-34.610,20.992);
        glVertex2d(-20.500,20.999);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);//2
        glVertex2d(-34.550,20.498);
        glVertex2d(-20.749,20.500);
    glEnd();

    glPopMatrix();
    //Moving Ship End

    //Moving Ship-1
    glPushMatrix();
    glTranslatef(shipMove1,0.0,0.0);

    glColor3f(1.0f, 0.2f, 0.2f);//Container-1
    glBegin(GL_QUADS);
        glVertex2d(20.,12.0);
        glVertex2d(24.0,12.0);
        glVertex2d(24.0,10.0);
        glVertex2d(20.0,10.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(20.5,12.0);
        glVertex2d(20.5,10.0);
        glVertex2d(21.0,12.0);
        glVertex2d(21.0,10.0);
        glVertex2d(21.5,12.0);
        glVertex2d(21.5,10.0);
        glVertex2d(22.0,12.0);
        glVertex2d(22.0,10.0);
        glVertex2d(22.5,12.0);
        glVertex2d(22.5,10.0);
        glVertex2d(23.0,12.0);
        glVertex2d(23.0,10.0);
        glVertex2d(23.5,12.0);
        glVertex2d(23.5,10.0);
    glEnd();
    glColor3f(0.0f, 0.90f, 0.30f);//Container-2
    glBegin(GL_QUADS);
        glVertex2d(24.5,12.0);
        glVertex2d(28.5,12.0);
        glVertex2d(28.5,10.0);
        glVertex2d(24.5,10.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(25.0,12.0);
        glVertex2d(25.0,10.0);
        glVertex2d(25.5,12.0);
        glVertex2d(25.5,10.0);
        glVertex2d(26.0,12.0);
        glVertex2d(26.0,10.0);
        glVertex2d(26.5,12.0);
        glVertex2d(26.5,10.0);
        glVertex2d(27.0,12.0);
        glVertex2d(27.0,10.0);
        glVertex2d(27.5,12.0);
        glVertex2d(27.5,10.0);
        glVertex2d(28.0,12.0);
        glVertex2d(28.0,10.0);
    glEnd();
    glColor3f(1.0f, 0.65f, 0.30f);//Container-3
    glBegin(GL_QUADS);
        glVertex2d(29.0,12.0);
        glVertex2d(33.0,12.0);
        glVertex2d(33.0,10.0);
        glVertex2d(29.0,10.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(29.5,12.0);
        glVertex2d(29.5,10.0);
        glVertex2d(30.0,12.0);
        glVertex2d(30.0,10.0);
        glVertex2d(30.5,12.0);
        glVertex2d(30.5,10.0);
        glVertex2d(31.0,12.0);
        glVertex2d(31.0,10.0);
        glVertex2d(31.5,12.0);
        glVertex2d(31.5,10.0);
        glVertex2d(32.0,12.0);
        glVertex2d(32.0,10.0);
        glVertex2d(32.5,12.0);
        glVertex2d(32.5,10.0);
    glEnd();
    glColor3f(1.0f, 1.0f, 0.50f);//Container-4
    glBegin(GL_QUADS);
        glVertex2d(22.0,14.0);
        glVertex2d(26.0,14.0);
        glVertex2d(26.0,12.0);
        glVertex2d(22.0,12.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(22.5,14.0);
        glVertex2d(22.5,12.0);
        glVertex2d(23.0,14.0);
        glVertex2d(23.0,12.0);
        glVertex2d(23.5,14.0);
        glVertex2d(23.5,12.0);
        glVertex2d(24.0,14.0);
        glVertex2d(24.0,12.0);
        glVertex2d(24.5,14.0);
        glVertex2d(24.5,12.0);
        glVertex2d(25.0,14.0);
        glVertex2d(25.0,12.0);
        glVertex2d(25.5,14.0);
        glVertex2d(25.5,12.0);
    glEnd();
    glColor3f(1.0f, 0.2f, 0.2f);//Container-5
    glBegin(GL_QUADS);
        glVertex2d(27.0,14.0);
        glVertex2d(31.0,14.0);
        glVertex2d(31.0,12.0);
        glVertex2d(27.0,12.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(27.5,14.0);
        glVertex2d(27.5,12.0);
        glVertex2d(28.0,14.0);
        glVertex2d(28.0,12.0);
        glVertex2d(28.5,14.0);
        glVertex2d(28.5,12.0);
        glVertex2d(29.0,14.0);
        glVertex2d(29.0,12.0);
        glVertex2d(29.5,14.0);
        glVertex2d(29.5,12.0);
        glVertex2d(30.0,14.0);
        glVertex2d(30.0,12.0);
        glVertex2d(30.5,14.0);
        glVertex2d(30.5,12.0);
    glEnd();

    glColor3f(0.94f,0.94f,0.94f);//Building1
    glBegin(GL_POLYGON);
        glVertex2d(34.0,13.0);
        glVertex2d(39.0,13.0);
        glVertex2d(39.0,10.0);
        glVertex2d(34.0,10.0);
    glEnd();
    glColor3f(0.94f,0.94f,0.94f);//Building2
    glBegin(GL_POLYGON);
        glVertex2d(36.0,15.0);
        glVertex2d(39.0,15.0);
        glVertex2d(39.0,13.0);
        glVertex2d(36.0,13.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
        glVertex2d(38.0,16.5);
        glVertex2d(39.0,16.0);
        glVertex2d(39.0,15.0);
        glVertex2d(38.0,15.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
        glVertex2d(34.5,12.5);
        glVertex2d(35.5,12.5);
        glVertex2d(35.5,11.5);
        glVertex2d(34.5,11.5);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(34.0,13.0);
        glVertex2d(39.0,13.0);
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
        glVertex2d(38.0,16.0);
        glVertex2d(39.0,15.6);
    glEnd();

    glColor3f(0.01f,0.2f,0.38f);//down1
    glBegin(GL_POLYGON);
        glVertex2d(18.0,10.0);
        glVertex2d(40.0,10.0);
        glVertex2d(38.0,6.0);
        glVertex2d(20.0,6.0);
    glEnd();
    glColor3f(0.8f,0.2f,0.2f);//down2
    glBegin(GL_POLYGON);
        glVertex2d(20.0,6.0);
        glVertex2d(38.0,6.0);
        glVertex2d(39.0,5.0);
        glVertex2d(20.5,5.0);
    glEnd();
    glPushMatrix();//circle
    glTranslatef(20.0,9.0,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    circle(0.3,0.5);
    glPopMatrix();
    glPopMatrix();
    //Moving Ship End




    //SeaPort-1
    glColor3f(0.380f,0.415f,0.419f);
    glBegin(GL_QUADS);
        glVertex2d(-45.0,-15.0);
        glVertex2d(-5.0,-15.0);
        glVertex2d(0.0,-30.0);
        glVertex2d(-50.0,-30.0);
    glEnd();

    //Cran
    glColor3f(0.10f, 0.32f, 0.46f);
    glBegin(GL_QUADS);
        glVertex2d(-44.0,-20.0);
        glVertex2d(-34.0,-20.0);
        glVertex2d(-34.0,-22.0);
        glVertex2d(-44.0,-22.0);
    glEnd();
    glColor3f(0.74f,0.78f,0.79f);
    glBegin(GL_QUADS);
        glVertex2d(-42.0,-18.0);
        glVertex2d(-36.0,-18.0);
        glVertex2d(-36.0,-20.0);
        glVertex2d(-42.0,-20.0);
    glEnd();

    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-44.0,8.0);
        glVertex2d(-42.0,10.0);
        glVertex2d(-40.0,8.0);
        glVertex2d(-38.0,10.0);
        glVertex2d(-36.0,8.0);
        glVertex2d(-34.0,10.0);
        glVertex2d(-32.0,8.0);
        glVertex2d(-30.0,10.0);
        glVertex2d(-28.0,8.0);
        glVertex2d(-26.0,10.0);
        glVertex2d(-24.0,8.0);
        glVertex2d(-22.0,10.0);
        glVertex2d(-22.0,8.0);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-44.0,10.0);
        glVertex2d(-42.0,8.0);
        glVertex2d(-40.0,10.0);
        glVertex2d(-38.0,8.0);
        glVertex2d(-36.0,10.0);
        glVertex2d(-34.0,8.0);
        glVertex2d(-32.0,10.0);
        glVertex2d(-30.0,8.0);
        glVertex2d(-28.0,10.0);
        glVertex2d(-26.0,8.0);
        glVertex2d(-24.0,10.0);
        glVertex2d(-22.0,8.0);
        glVertex2d(-22.0,10.0);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-44.0,10.0);
        glVertex2d(-22.0,10.0);
        glVertex2d(-20.0,8.0);
        glVertex2d(-22.0,8.0);
        glVertex2d(-44.0,8.0);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-38.0,-18.0);
        glVertex2d(-40.0,-18.0);
        glVertex2d(-38.0,-16.0);
        glVertex2d(-40.0,-14.0);
        glVertex2d(-38.0,-12.0);
        glVertex2d(-40.0,-10.0);
        glVertex2d(-38.0,-8.0);
        glVertex2d(-40.0,-6.0);
        glVertex2d(-38.0,-4.0);
        glVertex2d(-40.0,-2.0);
        glVertex2d(-38.0,0.0);
        glVertex2d(-40.0,2.0);
        glVertex2d(-38.0,4.0);
        glVertex2d(-40.0,6.0);
        glVertex2d(-38.0,8.0);
        glVertex2d(-40.0,10.0);
        glVertex2d(-38.0,10.0);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-40.0,-18.0);
        glVertex2d(-38.0,-18.0);
        glVertex2d(-40.0,-16.0);
        glVertex2d(-38.0,-14.0);
        glVertex2d(-40.0,-12.0);
        glVertex2d(-38.0,-10.0);
        glVertex2d(-40.0,-8.0);
        glVertex2d(-38.0,-6.0);
        glVertex2d(-40.0,-4.0);
        glVertex2d(-38.0,-2.0);
        glVertex2d(-40.0,0.0);
        glVertex2d(-38.0,2.0);
        glVertex2d(-40.0,4.0);
        glVertex2d(-38.0,6.0);
        glVertex2d(-40.0,8.0);
        glVertex2d(-38.0,10.0);
        glVertex2d(-40.0,10.0);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-39.5,10.0);
        glVertex2d(-37.5,10.0);
        glVertex2d(-38.5,17.0);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-38.5,17.0);
        glVertex2d(-44.0,10.0);
        glVertex2d(-30.5,10.0);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-39.356,11.007);
        glVertex2d(-37.644,11.013);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-39.215,11.990);
        glVertex2d(-37.788,12.017);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-39.070,13.006);
        glVertex2d(-37.926,12.986);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-38.929,13.994);
        glVertex2d(-38.070,13.990);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-38.784,15.009);
        glVertex2d(-38.214,15.001);
    glEnd();//Cran End

    glColor3f(0.14f, 0.14f, 0.14f);
    glBegin(GL_QUADS);
        glVertex2d(-45.0,11.0);
        glVertex2d(-44.0,11.0);
        glVertex2d(-44.0,7.0);
        glVertex2d(-45.0,7.0);
    glEnd();
    glColor3f(1.00f,1.00f,1.00f);
    glBegin(GL_LINES);
        glVertex2d(-44.5,11.0);
        glVertex2d(-44.5,7.0);
    glEnd();

    //Cram Hook
    glPushMatrix();
    glTranslatef(cramHook,0.0,0.0);
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_QUADS);
        glVertex2d(-22.0,8.0);
        glVertex2d(-20.0,8.0);
        glVertex2d(-20.0,7.0);
        glVertex2d(-22.0,7.0);
    glEnd();
    glColor3f(0.15f,0.21f,0.27f);
    glBegin(GL_LINE_LOOP);
        glVertex2d(-22.0,7.0);
        glVertex2d(-20.0,7.0);
        glVertex2d(-21.0,0.0);
    glEnd();
    glColor3f(0.0f,0.90f,0.30f);//Container
    glBegin(GL_QUADS);
        glVertex2d(-26.0,0.0);
        glVertex2d(-16.0,0.0);
        glVertex2d(-16.0,-4.0);
        glVertex2d(-26.0,-4.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(-25.0,0.0);
        glVertex2d(-25.0,-4.0);
        glVertex2d(-24.0,0.0);
        glVertex2d(-24.0,-4.0);
        glVertex2d(-23.0,0.0);
        glVertex2d(-23.0,-4.0);
        glVertex2d(-22.0,0.0);
        glVertex2d(-22.0,-4.0);
        glVertex2d(-21.0,0.0);
        glVertex2d(-21.0,-4.0);
        glVertex2d(-20.0,0.0);
        glVertex2d(-20.0,-4.0);
        glVertex2d(-19.0,0.0);
        glVertex2d(-19.0,-4.0);
        glVertex2d(-18.0,0.0);
        glVertex2d(-18.0,-4.0);
        glVertex2d(-17.0,0.0);
        glVertex2d(-17.0,-4.0);
    glEnd();
    glPopMatrix();
    //Cram Hook End

    //Container-1
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2d(-16.0,-24.0);
        glVertex2d(-6.0,-24.0);
        glVertex2d(-6.0,-28.0);
        glVertex2d(-16.0,-28.0);
    glEnd();
     glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(-15.0,-24.0);
        glVertex2d(-15.0,-28.0);
        glVertex2d(-14.0,-24.0);
        glVertex2d(-14.0,-28.0);
        glVertex2d(-13.0,-24.0);
        glVertex2d(-13.0,-28.0);
        glVertex2d(-12.0,-24.0);
        glVertex2d(-12.0,-28.0);
        glVertex2d(-11.0,-24.0);
        glVertex2d(-11.0,-28.0);
        glVertex2d(-10.0,-24.0);
        glVertex2d(-10.0,-28.0);
        glVertex2d(-9.0,-24.0);
        glVertex2d(-9.0,-28.0);
        glVertex2d(-8.0,-24.0);
        glVertex2d(-8.0,-28.0);
        glVertex2d(-7.0,-24.0);
        glVertex2d(-7.0,-28.0);
    glEnd();//Container-1 end

    //Container-2
    glColor3f(0.0f, 0.90f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2d(-27.0,-24.0);
        glVertex2d(-17.0,-24.0);
        glVertex2d(-17.0,-28.0);
        glVertex2d(-27.0,-28.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(-26.0,-24.0);
        glVertex2d(-26.0,-28.0);
        glVertex2d(-25.0,-24.0);
        glVertex2d(-25.0,-28.0);
        glVertex2d(-24.0,-24.0);
        glVertex2d(-24.0,-28.0);
        glVertex2d(-23.0,-24.0);
        glVertex2d(-23.0,-28.0);
        glVertex2d(-22.0,-24.0);
        glVertex2d(-22.0,-28.0);
        glVertex2d(-21.0,-24.0);
        glVertex2d(-21.0,-28.0);
        glVertex2d(-20.0,-24.0);
        glVertex2d(-20.0,-28.0);
        glVertex2d(-19.0,-24.0);
        glVertex2d(-19.0,-28.0);
        glVertex2d(-18.0,-24.0);
        glVertex2d(-18.0,-28.0);
    glEnd();//Container-2 end

    //Container-3
    glColor3f(0.03f, 0.58f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2d(-16.0,-19.5);
        glVertex2d(-6.0,-19.5);
        glVertex2d(-6.0,-23.5);
        glVertex2d(-16.0,-23.5);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(-15.0,-19.5);
        glVertex2d(-15.0,-23.5);
        glVertex2d(-14.0,-19.5);
        glVertex2d(-14.0,-23.5);
        glVertex2d(-13.0,-19.5);
        glVertex2d(-13.0,-23.5);
        glVertex2d(-12.0,-19.5);
        glVertex2d(-12.0,-23.5);
        glVertex2d(-11.0,-19.5);
        glVertex2d(-11.0,-23.5);
        glVertex2d(-10.0,-19.5);
        glVertex2d(-10.0,-23.5);
        glVertex2d(-9.0,-19.5);
        glVertex2d(-9.0,-23.5);
        glVertex2d(-8.0,-19.5);
        glVertex2d(-8.0,-23.5);
        glVertex2d(-7.0,-19.5);
        glVertex2d(-7.0,-23.5);
    glEnd();//Container-3 end

    //Container-4
    glColor3f(1.0f, 0.65f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2d(-27.0,-19.5);
        glVertex2d(-17.0,-19.5);
        glVertex2d(-17.0,-23.5);
        glVertex2d(-27.0,-23.5);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(-26.0,-19.5);
        glVertex2d(-26.0,-23.5);
        glVertex2d(-25.0,-19.5);
        glVertex2d(-25.0,-23.5);
        glVertex2d(-24.0,-19.5);
        glVertex2d(-24.0,-23.5);
        glVertex2d(-23.0,-19.5);
        glVertex2d(-23.0,-23.5);
        glVertex2d(-22.0,-19.5);
        glVertex2d(-22.0,-23.5);
        glVertex2d(-21.0,-19.5);
        glVertex2d(-21.0,-23.5);
        glVertex2d(-20.0,-19.5);
        glVertex2d(-20.0,-23.5);
        glVertex2d(-19.0,-19.5);
        glVertex2d(-19.0,-23.5);
        glVertex2d(-18.0,-19.5);
        glVertex2d(-18.0,-23.5);
    glEnd(); //Container-4 end

    //Container-5
    glColor3f(1.0f, 1.0f, 0.50f);
    glBegin(GL_QUADS);
        glVertex2d(-31.0,-24.0);
        glVertex2d(-28.0,-24.0);
        glVertex2d(-28.0,-28.0);
        glVertex2d(-31.0,-28.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(-30.5,-24.0);
        glVertex2d(-30.5,-28.0);
        glVertex2d(-30.0,-24.0);
        glVertex2d(-30.0,-28.0);
        glVertex2d(-29.5,-24.0);
        glVertex2d(-29.5,-28.0);
        glVertex2d(-29.0,-24.0);
        glVertex2d(-29.0,-28.0);
        glVertex2d(-28.5,-24.0);
        glVertex2d(-28.5,-28.0);
    glEnd();//Container-5 end

    //Container-6
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2d(-31.0,-19.5);
        glVertex2d(-28.0,-19.5);
        glVertex2d(-28.0,-23.5);
        glVertex2d(-31.0,-23.5);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(-30.5,-19.5);
        glVertex2d(-30.5,-23.5);
        glVertex2d(-30.0,-19.5);
        glVertex2d(-30.0,-23.5);
        glVertex2d(-29.5,-19.5);
        glVertex2d(-29.5,-23.5);
        glVertex2d(-29.0,-19.5);
        glVertex2d(-29.0,-23.5);
        glVertex2d(-28.5,-19.5);
        glVertex2d(-28.5,-23.5);
    glEnd();//Container-6 end

    //SeaPort-1 End


//**************************************************************
//**************************************************************

    //SeaPort-2
    glColor3f(0.380f,0.415f,0.419f);
    glBegin(GL_QUADS);
        glVertex2d(5.0,-15.0);
        glVertex2d(45.0,-15.0);
        glVertex2d(50.0,-30.0);
        glVertex2d(0.0,-30.0);
    glEnd();

    //Ship-2 Start
    glColor3f(0.0f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
        glVertex2d(7.0,-10.0);
        glVertex2d(43.0,-10.0);
        glVertex2d(40.0,-15.0);
        glVertex2d(10.0,-15.0);
    glEnd();
    glColor3f(1.0f, 0.2f, 0.2f);//Container-1
    glBegin(GL_QUADS);
        glVertex2d(9.0,-6.0);
        glVertex2d(19.0,-6.0);
        glVertex2d(19.0,-10.0);
        glVertex2d(9.0,-10.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(10.0,-6.0);
        glVertex2d(10.0,-10.0);
        glVertex2d(11.0,-6.0);
        glVertex2d(11.0,-10.0);
        glVertex2d(12.0,-6.0);
        glVertex2d(12.0,-10.0);
        glVertex2d(13.0,-6.0);
        glVertex2d(13.0,-10.0);
        glVertex2d(14.0,-6.0);
        glVertex2d(14.0,-10.0);
        glVertex2d(15.0,-6.0);
        glVertex2d(15.0,-10.0);
        glVertex2d(16.0,-6.0);
        glVertex2d(16.0,-10.0);
        glVertex2d(17.0,-6.0);
        glVertex2d(17.0,-10.0);
        glVertex2d(18.0,-6.0);
        glVertex2d(18.0,-10.0);
    glEnd();
    glColor3f(0.0f, 0.90f, 0.30f);//Container-2
    glBegin(GL_QUADS);
        glVertex2d(20.0,-6.0);
        glVertex2d(30.0,-6.0);
        glVertex2d(30.0,-10.0);
        glVertex2d(20.0,-10.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(21.0,-6.0);
        glVertex2d(21.0,-10.0);
        glVertex2d(22.0,-6.0);
        glVertex2d(22.0,-10.0);
        glVertex2d(23.0,-6.0);
        glVertex2d(23.0,-10.0);
        glVertex2d(24.0,-6.0);
        glVertex2d(24.0,-10.0);
        glVertex2d(25.0,-6.0);
        glVertex2d(25.0,-10.0);
        glVertex2d(26.0,-6.0);
        glVertex2d(26.0,-10.0);
        glVertex2d(27.0,-6.0);
        glVertex2d(27.0,-10.0);
        glVertex2d(28.0,-6.0);
        glVertex2d(28.0,-10.0);
        glVertex2d(29.0,-6.0);
        glVertex2d(29.0,-10.0);
    glEnd();
    glColor3f(1.0f, 1.0f, 0.50f);//Container-3
    glBegin(GL_QUADS);
        glVertex2d(20.0,-1.8);
        glVertex2d(30.0,-1.8);
        glVertex2d(30.0,-5.8);
        glVertex2d(20.0,-5.8);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(21.0,-1.8);
        glVertex2d(21.0,-5.8);
        glVertex2d(22.0,-1.8);
        glVertex2d(22.0,-5.8);
        glVertex2d(23.0,-1.8);
        glVertex2d(23.0,-5.8);
        glVertex2d(24.0,-1.8);
        glVertex2d(24.0,-5.8);
        glVertex2d(25.0,-1.8);
        glVertex2d(25.0,-5.8);
        glVertex2d(26.0,-1.8);
        glVertex2d(26.0,-5.8);
        glVertex2d(27.0,-1.8);
        glVertex2d(27.0,-5.8);
        glVertex2d(28.0,-1.8);
        glVertex2d(28.0,-5.8);
        glVertex2d(29.0,-1.8);
        glVertex2d(29.0,-5.8);
    glEnd();
    glColor3f(1.0f, 0.65f, 0.30f);//Container-4
    glBegin(GL_QUADS);
        glVertex2d(9.0,-1.8);
        glVertex2d(19.0,-1.8);
        glVertex2d(19.0,-5.8);
        glVertex2d(9.0,-5.8);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(10.0,-1.8);
        glVertex2d(10.0,-5.8);
        glVertex2d(11.0,-1.8);
        glVertex2d(11.0,-5.8);
        glVertex2d(12.0,-1.8);
        glVertex2d(12.0,-5.8);
        glVertex2d(13.0,-1.8);
        glVertex2d(13.0,-5.8);
        glVertex2d(14.0,-1.8);
        glVertex2d(14.0,-5.8);
        glVertex2d(15.0,-1.8);
        glVertex2d(15.0,-5.8);
        glVertex2d(16.0,-1.8);
        glVertex2d(16.0,-5.8);
        glVertex2d(17.0,-1.8);
        glVertex2d(17.0,-5.8);
        glVertex2d(18.0,-1.8);
        glVertex2d(18.0,-5.8);
    glEnd();
    glColor3f(1.0f, 0.74f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2d(33.0,-7.0);
        glVertex2d(41.0,-7.0);
        glVertex2d(41.0,-10.0);
        glVertex2d(32.0,-10.0);
    glEnd();
    glColor3f(0.94f, 0.23f, 0.05f);
    glBegin(GL_POLYGON);
        glVertex2d(35.0,-5.0);
        glVertex2d(41.0,-5.0);
        glVertex2d(41.0,-7.0);
        glVertex2d(34.0,-7.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2d(38.0,-2.5);
        glVertex2d(40.0,-2.5);
        glVertex2d(39.0,-5.0);
        glVertex2d(37.0,-5.0);
    glEnd();
    glColor3f(1.0f, 1.0f , 1.0f);
    glBegin(GL_LINES);
       glVertex2d(37.719, -3.201);
       glVertex2d(39.721, -3.197);
    glEnd();
    glColor3f(0.0f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
        glVertex2d(6.0,-9.0);
        glVertex2d(12.0,-9.0);
        glVertex2d(13.0,-10.0);
        glVertex2d(7.0,-10.0);
    glEnd();
    glColor3f(0.0f, 0.4f, 0.4f);
    glBegin(GL_QUADS);
        glVertex2d(38.0,-9.0);
        glVertex2d(44.0,-9.0);
        glVertex2d(43.0,-10.0);
        glVertex2d(37.0,-10.0);
    glEnd();

    glPushMatrix();//C1
    glTranslatef(8.5,-10.0,0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
        circle(0.2,0.5);
    glPopMatrix();

    glPushMatrix();//C2
    glTranslatef(10.0,-10.0,0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
        circle(0.2,0.5);
    glPopMatrix();

    glPushMatrix();//C3
    glTranslatef(11.5,-10.0,0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
        circle(0.2,0.5);
    glPopMatrix();
    glPushMatrix();//C4
    glTranslatef(38.5,-10.0,0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
        circle(0.2,0.5);
    glPopMatrix();
    glPushMatrix();//C5
    glTranslatef(40.0,-10.0,0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
        circle(0.2,0.5);
    glPopMatrix();
    glPushMatrix();//C6
    glTranslatef(41.5,-10.0,0.0);
    glColor3f(1.0f, 1.0f, 1.0f);
        circle(0.2,0.5);
    glPopMatrix();

    glColor3f(1.0f, 1.0f, 1.0f);//Line1
    glBegin(GL_LINES);
        glVertex2d(15.0,-11.0);
        glVertex2d(19.0,-11.0);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);//Line2
    glBegin(GL_LINES);
        glVertex2d(23.0,-11.0);
        glVertex2d(27.0,-11.0);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);//Line3
    glBegin(GL_LINES);
        glVertex2d(31.0,-11.0);
        glVertex2d(35.0,-11.0);
    glEnd();
    //Ship-2 End







    //Container-1
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2d(35.0,-25.0);
        glVertex2d(45.0,-25.0);
        glVertex2d(45.0,-29.0);
        glVertex2d(35.0,-29.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(36.0,-25.0);
        glVertex2d(36.0,-29.0);
        glVertex2d(37.0,-25.0);
        glVertex2d(37.0,-29.0);
        glVertex2d(38.0,-25.0);
        glVertex2d(38.0,-29.0);
        glVertex2d(39.0,-25.0);
        glVertex2d(39.0,-29.0);
        glVertex2d(40.0,-25.0);
        glVertex2d(40.0,-29.0);
        glVertex2d(41.0,-25.0);
        glVertex2d(41.0,-29.0);
        glVertex2d(42.0,-25.0);
        glVertex2d(42.0,-29.0);
        glVertex2d(43.0,-25.0);
        glVertex2d(43.0,-29.0);
        glVertex2d(44.0,-25.0);
        glVertex2d(44.0,-29.0);
    glEnd();

    //Container-2
    glColor3f(0.0f, 0.90f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2d(24.0,-25.0);
        glVertex2d(34.0,-25.0);
        glVertex2d(34.0,-29.0);
        glVertex2d(24.0,-29.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(25.0,-25.0);
        glVertex2d(25.0,-29.0);
        glVertex2d(26.0,-25.0);
        glVertex2d(26.0,-29.0);
        glVertex2d(27.0,-25.0);
        glVertex2d(27.0,-29.0);
        glVertex2d(28.0,-25.0);
        glVertex2d(28.0,-29.0);
        glVertex2d(29.0,-25.0);
        glVertex2d(29.0,-29.0);
        glVertex2d(30.0,-25.0);
        glVertex2d(30.0,-29.0);
        glVertex2d(31.0,-25.0);
        glVertex2d(31.0,-29.0);
        glVertex2d(32.0,-25.0);
        glVertex2d(32.0,-29.0);
        glVertex2d(33.0,-25.0);
        glVertex2d(33.0,-29.0);
    glEnd();
    //Container-3
    glColor3f(0.30f, 0.58f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2d(35.0,-20.5);
        glVertex2d(45.0,-20.5);
        glVertex2d(45.0,-24.5);
        glVertex2d(35.0,-24.5);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(36.0,-20.5);
        glVertex2d(36.0,-24.5);
        glVertex2d(37.0,-20.5);
        glVertex2d(37.0,-24.5);
        glVertex2d(38.0,-20.5);
        glVertex2d(38.0,-24.5);
        glVertex2d(39.0,-20.5);
        glVertex2d(39.0,-24.5);
        glVertex2d(40.0,-20.5);
        glVertex2d(40.0,-24.5);
        glVertex2d(41.0,-20.5);
        glVertex2d(41.0,-24.5);
        glVertex2d(42.0,-20.5);
        glVertex2d(42.0,-24.5);
        glVertex2d(43.0,-20.5);
        glVertex2d(43.0,-24.5);
        glVertex2d(44.0,-20.5);
        glVertex2d(44.0,-24.5);
    glEnd();
    //Container-4
    glColor3f(1.0f, 0.65f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2d(24.0,-20.5);
        glVertex2d(34.0,-20.5);
        glVertex2d(34.0,-24.5);
        glVertex2d(24.0,-24.5);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(25.0,-20.5);
        glVertex2d(25.0,-24.5);
        glVertex2d(26.0,-20.5);
        glVertex2d(26.0,-24.5);
        glVertex2d(27.0,-20.5);
        glVertex2d(27.0,-24.5);
        glVertex2d(28.0,-20.5);
        glVertex2d(28.0,-24.5);
        glVertex2d(29.0,-20.5);
        glVertex2d(29.0,-24.5);
        glVertex2d(30.0,-20.5);
        glVertex2d(30.0,-24.5);
        glVertex2d(31.0,-20.5);
        glVertex2d(31.0,-24.5);
        glVertex2d(32.0,-20.5);
        glVertex2d(32.0,-24.5);
        glVertex2d(33.0,-20.5);
        glVertex2d(33.0,-24.5);
    glEnd();
    //Container-5
    glColor3f(1.0f, 1.0f, 0.50f);
    glBegin(GL_QUADS);
        glVertex2d(35.0,-16.0);
        glVertex2d(45.0,-16.0);
        glVertex2d(45.0,-20.0);
        glVertex2d(35.0,-20.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(36.0,-16.0);
        glVertex2d(36.0,-20.0);
        glVertex2d(37.0,-16.0);
        glVertex2d(37.0,-20.0);
        glVertex2d(38.0,-16.0);
        glVertex2d(38.0,-20.0);
        glVertex2d(39.0,-16.0);
        glVertex2d(39.0,-20.0);
        glVertex2d(40.0,-16.0);
        glVertex2d(40.0,-20.0);
        glVertex2d(41.0,-16.0);
        glVertex2d(41.0,-20.0);
        glVertex2d(42.0,-16.0);
        glVertex2d(42.0,-20.0);
        glVertex2d(43.0,-16.0);
        glVertex2d(43.0,-20.0);
        glVertex2d(44.0,-16.0);
        glVertex2d(44.0,-20.0);
    glEnd();
    //Container-6
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2d(24.0,-16.0);
        glVertex2d(34.0,-16.0);
        glVertex2d(34.0,-20.0);
        glVertex2d(24.0,-20.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(25.0,-16.0);
        glVertex2d(25.0,-20.0);
        glVertex2d(26.0,-16.0);
        glVertex2d(26.0,-20.0);
        glVertex2d(27.0,-16.0);
        glVertex2d(27.0,-20.0);
        glVertex2d(28.0,-16.0);
        glVertex2d(28.0,-20.0);
        glVertex2d(29.0,-16.0);
        glVertex2d(29.0,-20.0);
        glVertex2d(30.0,-16.0);
        glVertex2d(30.0,-20.0);
        glVertex2d(31.0,-16.0);
        glVertex2d(31.0,-20.0);
        glVertex2d(32.0,-16.0);
        glVertex2d(32.0,-20.0);
        glVertex2d(33.0,-16.0);
        glVertex2d(33.0,-20.0);
    glEnd();
    //Container-7
    glColor3f(0.0f, 0.90f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2d(20.0,-25.0);
        glVertex2d(23.0,-25.0);
        glVertex2d(23.0,-29.0);
        glVertex2d(20.0,-29.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(20.5,-25.0);
        glVertex2d(20.5,-29.0);
        glVertex2d(21.0,-25.0);
        glVertex2d(21.0,-29.0);
        glVertex2d(21.5,-25.0);
        glVertex2d(21.5,-29.0);
        glVertex2d(22.0,-25.0);
        glVertex2d(22.0,-29.0);
        glVertex2d(22.5,-25.0);
        glVertex2d(22.5,-29.0);
    glEnd();
    //Container-8
    glColor3f(0.30f, 0.58f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2d(20.0,-20.5);
        glVertex2d(23.0,-20.5);
        glVertex2d(23.0,-24.5);
        glVertex2d(20.0,-24.5);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(20.5,-20.5);
        glVertex2d(20.5,-24.5);
        glVertex2d(21.0,-20.5);
        glVertex2d(21.0,-24.5);
        glVertex2d(21.5,-20.5);
        glVertex2d(21.5,-24.5);
        glVertex2d(22.0,-20.5);
        glVertex2d(22.0,-24.5);
        glVertex2d(22.5,-20.5);
        glVertex2d(22.5,-24.5);
    glEnd();
    //Container-9
    glColor3f(1.0f, 0.65f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2d(20.0,-16.0);
        glVertex2d(23.0,-16.0);
        glVertex2d(23.0,-20.0);
        glVertex2d(20.0,-20.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(20.5,-16.0);
        glVertex2d(20.5,-20.0);
        glVertex2d(21.0,-16.0);
        glVertex2d(21.0,-20.0);
        glVertex2d(21.5,-16.0);
        glVertex2d(21.5,-20.0);
        glVertex2d(22.0,-16.0);
        glVertex2d(22.0,-20.0);
        glVertex2d(22.5,-16.0);
        glVertex2d(22.5,-20.0);
    glEnd();
    //Container-10
    glColor3f(1.0f, 1.0f, 0.50f);
    glBegin(GL_QUADS);
        glVertex2d(16.0,-25.0);
        glVertex2d(19.0,-25.0);
        glVertex2d(19.0,-29.0);
        glVertex2d(16.0,-29.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(16.5,-25.0);
        glVertex2d(16.5,-29.0);
        glVertex2d(17.0,-25.0);
        glVertex2d(17.0,-29.0);
        glVertex2d(17.5,-25.0);
        glVertex2d(17.5,-29.0);
        glVertex2d(18.0,-25.0);
        glVertex2d(18.0,-29.0);
        glVertex2d(18.5,-25.0);
        glVertex2d(18.5,-29.0);
    glEnd();
    //Container-11
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2d(16.0,-20.5);
        glVertex2d(19.0,-20.5);
        glVertex2d(19.0,-24.5);
        glVertex2d(16.0,-24.5);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(16.5,-20.5);
        glVertex2d(16.5,-24.5);
        glVertex2d(17.0,-20.0);
        glVertex2d(17.0,-24.5);
        glVertex2d(17.5,-20.5);
        glVertex2d(17.5,-24.5);
        glVertex2d(18.0,-20.5);
        glVertex2d(18.0,-24.5);
        glVertex2d(18.5,-20.5);
        glVertex2d(18.5,-24.5);
    glEnd();
    //Container-12
    glColor3f(10.0f, 0.90f, 0.30f);
    glBegin(GL_QUADS);
        glVertex2d(16.0,-16.0);
        glVertex2d(19.0,-16.0);
        glVertex2d(19.0,-20.0);
        glVertex2d(16.0,-20.0);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2d(16.5,-16.0);
        glVertex2d(16.5,-20.0);
        glVertex2d(17.0,-16.0);
        glVertex2d(17.0,-20.0);
        glVertex2d(17.5,-16.0);
        glVertex2d(17.5,-20.0);
        glVertex2d(18.0,-16.0);
        glVertex2d(18.0,-20.0);
        glVertex2d(18.5,-16.0);
        glVertex2d(18.5,-20.0);
    glEnd();
    // All Container End


    //ROAD
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2d(-50.0,-30.0);
        glVertex2d(50.0,-30.0);
        glVertex2d(50.0,-50.0);
        glVertex2d(-50.0,-50.0);
    glEnd();
    //Up-Line
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-32.0);
        glVertex2d(50.0,-32.0);
    glEnd();

    //Middle-Line-1
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-40.0);
        glVertex2d(-40.0,-40.0);
    glEnd();

    //Middle-Line-2
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-38.0,-40.0);
        glVertex2d(-32.0,-40.0);
    glEnd();

    //Middle-Line-3
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-30.0,-40.0);
        glVertex2d(-20.0,-40.0);
    glEnd();

    //Middle-Line-4
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-18.0,-40.0);
        glVertex2d(-12.0,-40.0);
    glEnd();

    //Middle-Line-5
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-10.0,-40.0);
        glVertex2d(-0.0,-40.0);
    glEnd();

    //Middle-Line-6
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(2.0,-40.0);
        glVertex2d(8.0,-40.0);
    glEnd();

    //Middle-Line-7
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(10.0,-40.0);
        glVertex2d(20.0,-40.0);
    glEnd();

    //Middle-Line-8
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(22.0,-40.0);
        glVertex2d(28.0,-40.0);
    glEnd();

    //Middle-Line-9
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(30.0,-40.0);
        glVertex2d(40.0,-40.0);
    glEnd();

    //Middle-Line-10
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(42.0,-40.0);
        glVertex2d(50.0,-40.0);
    glEnd();

    //Down-Line
    glColor3f(1.02f,1.02f,1.02f);
    glBegin(GL_LINES);
        glVertex2d(-50.0,-48.0);
        glVertex2d(50.0,-48.0);
    glEnd();
    //Road End

    //Crane-2
    glPushMatrix();
    glTranslatef(cx,cy,0);
    glColor3f(0.94f,0.76f,0.05f);//room
    glBegin(GL_POLYGON);
        glVertex2d(2.0,-3.0);
        glVertex2d(5.5,-3.0);
        glVertex2d(5.5,-7.1);
        glVertex2d(5.3,-7.3);
        glVertex2d(5.1,-7.5);
        glVertex2d(2.4,-7.5);
        glVertex2d(2.2,-7.3);
        glVertex2d(2.0,-7.1);
    glEnd();
    glColor3f(0.282f,0.788f,0.690f);//room mirror
    glBegin(GL_QUADS);
        glVertex2d(2.5,-3.0);
        glVertex2d(5.0,-3.0);
        glVertex2d(5.0,-6.5);
        glVertex2d(2.5,-6.5);
    glEnd();
    glColor3f(0.878f,0.890f,0.917f);//mirror reflection
    glBegin(GL_POLYGON);
        glVertex2d(2.5,-3.0);
        glVertex2d(3.0,-3.0);
        glVertex2d(5.0,-6.0);
        glVertex2d(5.0,-6.5);
        glVertex2d(4.5,-6.5);
        glVertex2d(2.5,-3.5);
    glEnd();

    glColor3f(0.94f,0.76f,0.05f);
    glBegin(GL_QUADS);
        glVertex2d(16.0,-1.5);
        glVertex2d(17.0,-1.5);
        glVertex2d(17.0,-4.0);
        glVertex2d(16.0,-4.0);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(7.4,-3.0);
        glVertex2d(7.4,-11.8);
        glVertex2d(7.6,-3.0);
        glVertex2d(7.6,-11.8);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(12.4,-3.0);
        glVertex2d(12.4,-11.8);
        glVertex2d(12.6,-3.0);
        glVertex2d(12.6,-11.8);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);//*
    glBegin(GL_QUADS);
        glVertex2d(4.6,-11.8);
        glVertex2d(15.4,-11.8);
        glVertex2d(15.4,-12.4);
        glVertex2d(4.6,-12.4);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
        glVertex2d(4.6,-12.4);
        glVertex2d(5.0,-12.4);
        glVertex2d(5.0,-13.8);
        glVertex2d(4.6,-13.8);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
        glVertex2d(15.0,-12.4);
        glVertex2d(15.4,-12.4);
        glVertex2d(15.4,-13.8);
        glVertex2d(15.0,-13.8);
    glEnd();

    glColor3f(0.0f,0.90f,0.30f);//container
    glBegin(GL_QUADS);
        glVertex2d(5.0,-13.0);
        glVertex2d(15.0,-13.0);
        glVertex2d(15.0,-17.0);
        glVertex2d(5.0,-17.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(6.0,-13.0);
        glVertex2d(6.0,-17.0);
        glVertex2d(7.0,-13.0);
        glVertex2d(7.0,-17.0);
        glVertex2d(8.0,-13.0);
        glVertex2d(8.0,-17.0);
        glVertex2d(9.0,-13.0);
        glVertex2d(9.0,-17.0);
        glVertex2d(10.0,-13.0);
        glVertex2d(10.0,-17.0);
        glVertex2d(11.0,-13.0);
        glVertex2d(11.0,-17.0);
        glVertex2d(12.0,-13.0);
        glVertex2d(12.0,-17.0);
        glVertex2d(13.0,-13.0);
        glVertex2d(13.0,-17.0);
        glVertex2d(14.0,-13.0);
        glVertex2d(14.0,-17.0);
    glEnd();

    glColor3f(0.94f,0.76f,0.05f);
    glBegin(GL_QUADS);
        glVertex2d(6.0,-2.0);
        glVertex2d(6.5,-2.0);
        glVertex2d(6.5,-24.0);
        glVertex2d(6.0,-24.0);
    glEnd();

    glColor3f(0.94f,0.76f,0.05f);
    glBegin(GL_QUADS);
        glVertex2d(13.5,-2.0);
        glVertex2d(14.0,-2.0);
        glVertex2d(14.0,-24.0);
        glVertex2d(13.5,-24.0);
    glEnd();

    glColor3f(0.94f,0.76f,0.05f);
    glBegin(GL_QUADS);
        glVertex2d(2.0,-2.5);
        glVertex2d(16.0,-2.5);
        glVertex2d(16.0,-3.0);
        glVertex2d(2.0,-3.0);
    glEnd();

    glColor3f(0.94f,0.76f,0.05f);//basement
    glBegin(GL_QUADS);
        glVertex2d(5.0,-23.5);
        glVertex2d(15.0,-23.5);
        glVertex2d(15.0,-27.0);
        glVertex2d(5.0,-27.0);
    glEnd();

    glPushMatrix();//Chaka
    glTranslatef(6.5,-26.5,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    circle(1,1.5);
    glPopMatrix();
    glPushMatrix();//Chaka
    glTranslatef(6.5,-26.5,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    circle(0.5,0.8);
    glPopMatrix();
    glPushMatrix();//Chaka
    glTranslatef(13.5,-26.5,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    circle(1,1.5);
    glPopMatrix();
    glPushMatrix();//Chaka
    glTranslatef(13.5,-26.5,0.0);
    glColor3f(1.0f,1.0f,1.0f);
    circle(0.5,0.8);
    glPopMatrix();
    glPopMatrix();
    //Crame-2 End

    //Car Moving-1
    glPushMatrix();
    glTranslatef(carMove1,0.0,0.0);
    glColor3f(1.0f,0.30f,0.30f);//Front side
    glBegin(GL_POLYGON);
        glVertex2d(-21.0,-29.0);
        glVertex2d(-18.0,-29.0);
        glVertex2d(-17.0,-32.0);
        glVertex2d(-17.0,-37.0);
        glVertex2d(-21.0,-37.0);
    glEnd();
    glColor3f(0.94f,0.94f,0.94f);//Mirror
    glBegin(GL_QUADS);
        glVertex2d(-20.6,-29.6);
        glVertex2d(-18.2,-29.6);
        glVertex2d(-17.4,-32.0);
        glVertex2d(-20.6,-32.0);
    glEnd();

    glColor3f(1.0f,0.30f,0.30f);//Back Side
    glBegin(GL_QUADS);
        glVertex2d(-33.0,-35.0);
        glVertex2d(-21.0,-35.0);
        glVertex2d(-21.0,-37.0);
        glVertex2d(-33.0,-37.0);
    glEnd();
    glColor3f(0.0f,0.90f,0.30f);//Container
    glBegin(GL_QUADS);
        glVertex2d(-33.0,-29.0);
        glVertex2d(-21.5,-29.0);
        glVertex2d(-21.5,-35.0);
        glVertex2d(-33.0,-35.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(-31.5,-29.0);
        glVertex2d(-31.5,-35.0);
        glVertex2d(-30.5,-29.0);
        glVertex2d(-30.5,-35.0);
        glVertex2d(-29.5,-29.0);
        glVertex2d(-29.5,-35.0);
        glVertex2d(-28.5,-29.0);
        glVertex2d(-28.5,-35.0);
        glVertex2d(-27.5,-29.0);
        glVertex2d(-27.5,-35.0);
        glVertex2d(-26.5,-29.0);
        glVertex2d(-26.5,-35.0);
        glVertex2d(-25.5,-29.0);
        glVertex2d(-25.5,-35.0);
        glVertex2d(-24.5,-29.0);
        glVertex2d(-24.5,-35.0);
        glVertex2d(-23.5,-29.0);
        glVertex2d(-23.5,-35.0);
        glVertex2d(-22.5,-29.0);
        glVertex2d(-22.5,-35.0);
    glEnd();

    glPushMatrix();//Chaka-1
    glTranslatef(-19.0,-36.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-19.0,-36.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();
    glPushMatrix();//Chaka-2
    glTranslatef(-31.0,-36.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-31.0,-36.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();

    glPopMatrix();

    //Car Moving-1 End


    //Car Moving-2
    glPushMatrix();
    glTranslatef(carMove2,0.0,0.0);
    glColor3f(1.0f,0.30f,0.0f);//Front side
    glBegin(GL_POLYGON);
        glVertex2d(18.0,-37.0);
        glVertex2d(21.0,-37.0);
        glVertex2d(21.0,-45.0);
        glVertex2d(17.0,-45.0);
        glVertex2d(17.0,-40.0);
    glEnd();
     glColor3f(0.94f,0.94f,0.94f);//Mirror
    glBegin(GL_QUADS);
        glVertex2d(18.2,-37.6);
        glVertex2d(20.6,-37.6);
        glVertex2d(20.6,-40.0);
        glVertex2d(17.4,-40.0);
    glEnd();
    glColor3f(1.0f,0.30f,0.0f);//Back Side
    glBegin(GL_QUADS);
        glVertex2d(21.0,-43.0);
        glVertex2d(32.0,-43.0);
        glVertex2d(32.0,-45.0);
        glVertex2d(21.0,-45.0);
    glEnd();
    glColor3f(0.30f,0.58f,1.0f);//Container
    glBegin(GL_QUADS);
        glVertex2d(21.5,-37.0);
        glVertex2d(32.0,-37.0);
        glVertex2d(32.0,-43.0);
        glVertex2d(21.5,-43.0);
    glEnd();
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_LINES);
        glVertex2d(22.0,-37.0);
        glVertex2d(22.0,-43.0);
        glVertex2d(23.0,-37.0);
        glVertex2d(23.0,-43.0);
        glVertex2d(24.0,-37.0);
        glVertex2d(24.0,-43.0);
        glVertex2d(25.0,-37.0);
        glVertex2d(25.0,-43.0);
        glVertex2d(26.0,-37.0);
        glVertex2d(26.0,-43.0);
        glVertex2d(27.0,-37.0);
        glVertex2d(27.0,-43.0);
        glVertex2d(28.0,-37.0);
        glVertex2d(28.0,-43.0);
        glVertex2d(29.0,-37.0);
        glVertex2d(29.0,-43.0);
        glVertex2d(30.0,-37.0);
        glVertex2d(30.0,-43.0);
        glVertex2d(31.0,-37.0);
        glVertex2d(31.0,-43.0);
    glEnd();

    glPushMatrix();//Chaka-1
    glTranslatef(19.0,-44.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(19.0,-44.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();
    glPushMatrix();//Chaka-2
    glTranslatef(30.0,-44.5,0.0);
    glColor3f(0.34f,0.34f,0.34f);
    circle(1.2,2.3);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(30.0,-44.5,0.0);
    glColor3f(1.05f,1.05f,1.05f);
    circle(0.8,1.5);
    glPopMatrix();

    glPopMatrix();
    //Car Moving-2 End


    //Text-Show
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(45.0,-49.5);
    declare("PRESS-A");



    glFlush();
}

void Move(){
    shipMove1 = shipMove1 -0.005;
        if(shipMove1<-90){
            shipMove1=35;
            shipMove1=shipMove1;
        }

    shipMove2 = shipMove2 +0.003;
        if(shipMove2>85){
            shipMove2=-30;
            shipMove2=shipMove2;
        }

    shipMove3 = shipMove3 -0.002;
        if(shipMove3<-70){
            shipMove3=45;
            shipMove3=shipMove3;
        }

    shipMove4 = shipMove4 +0.00199;
        if(shipMove4>90){
            shipMove4=-17;
            shipMove4=shipMove4;
        }

    carMove1 = carMove1 +0.02;
        if(carMove1>85){
            carMove1=-35;
            carMove1=carMove1;
        }
    carMove2 = carMove2 -0.03;
        if(carMove2<-85){
            carMove2=35;
            carMove2=carMove2;
        }
    glutPostRedisplay();
}

void normal_key(unsigned char key,int x, int y){
    switch(key){
    case 'a':
        glutIdleFunc(Move);
        break;

    case 's':
        glutIdleFunc(NULL);
        break;

    default:
        break;
    }
}

void spe_key(int key, int x, int y){
    switch(key){
    case GLUT_KEY_LEFT:
        cx=cx-0.5;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        cx=cx+0.5;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        cy=cy-0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_UP:
        cy=cy+0.5;
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

void moving (int value){

        cloud_1 += 0.04;
        if (cloud_1-32.0 > 1.0)
        {
            cloud_1 = -72.0;
        }
        cloud_2 += 0.05;
        if (cloud_2-75.0 > 1.0)
        {
            cloud_2 = -27.0;
        }
        cloud_3 += 0.03;
        if (cloud_3-60.0 > 1.0)
        {
            cloud_3 = -43.0;
        }

        cramHook += 0.02;
        if (cramHook+1.0 > 1.0)
        {
            cramHook = -7.0;
        }

        glutPostRedisplay();
        glutTimerFunc(10, moving, 0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,600);
    glutInitWindowPosition(30,30);
    glutCreateWindow("Seaport-Final Project");
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(spe_key);
     glutKeyboardFunc(normal_key);
    glutTimerFunc(10, moving, 0);
    //PlaySound("2.wav", NULL, SND_FILENAME | SND_ASYNC);
    glutMainLoop();
    return 0;
}
