#include<windows.h>
#include<iostream>
#include<cstdio>
#include<stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>>
#include <MMSystem.h>
# define PI           3.14159265358979323846
using namespace std;

int day=1;                 ///***  1 for day,0 for night
int starenable=0;         ///***  1 for star,0 for no star
int rainy=0;             ///***  1 for rain,0 for no rain

float red=1;
float green=1;
float blue=1;
float red1=0.980392;
float green1=0.980392;
float blue1=0.823529;
float red2=0.52734375;
float green2=0.8046878;
float blue2=0.99765625;
float red3=0.498039;
float green3= 1;
float blue3= 0.831373;
float red4=1.0;
float green4= 0.95;
float blue4= 0.0;
float red5=1.0;
float green5= 1.0;
float blue5= 0.70;
float red6=0.20;
float green6=0.20;
float blue6=0.26;
float red7=249;
float green7=216;
float blue7=7;
float red8=225;
float green8=249;
float white=255;
float red9=135;
float green9=165;
float blue9=242;
float black=0;
float red10=255;


GLfloat speed =.01;
GLfloat speed1 =.02;
GLfloat speed2 =0.45;
GLfloat speed3 =0.007;
GLfloat position1 =0.0f;
GLfloat position2 =0.0f;
GLfloat position3 =0.0f;
GLfloat position4 =0.0f;
GLfloat position5 =0.0f;
GLfloat position6 =0.0f;
GLfloat position7 =0.0f;


void update(int value)
{
    if(position1 < 0.0)
        position1 = 2.0f;

    position1 -= speed2;

    if(position2 > 2.0)
        position2 = -1.2f;

    position2 += speed;

    if(position3 < -2.0)
        position3 = 1.2f;

    position3 -= speed;

    if(position5 < -3.8)
        position5 = 1.2f;

    position5 -= speed1;

    if(position6 > 2.6)
        position6 = -0.8f;

    position6 += speed;

    if(position7 < -1.85)
        position7 = 0.6f;

    position7 -= speed3;


	glutPostRedisplay(); ///Notify GLUT that the display has changed

	glutTimerFunc(100, update, 0); ///Notify GLUT to call update again in 50 milliseconds
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
        case 'd':
            day=1;
            black=0;
            white=255;
            red10=255;
            if(rainy==1)
            {
                sndPlaySound("Rain.wav",SND_ASYNC);
                 black=100;
                 white=100;
                 red10=30;
            }
            else
                sndPlaySound("Bird.wav",SND_ASYNC);
                //PlaySound(NULL, 0, 0);
            break;

        case 'n':
            day=0;
            white=30;
            black=30;
            red10=30;
            if(rainy==1)
            {
                sndPlaySound("Rain.wav",SND_ASYNC);
            }
            else
                sndPlaySound("Night.wav",SND_ASYNC);
            break;

        case 'r':
            rainy=1;
            sndPlaySound("Rain.wav",SND_ASYNC);

            //sndPlaySound("Rain.wav",SND_ASYNC);
            //savecloudspeed=cloudspeed;
            //cloudspeed=0;
            red=0.498;
            green=0.498;
            blue=0.498;
            red4=0.64;
            green4=0.64;
            blue4=0.64;
            red5=0.20;
            green5=0.20;
            blue5=0.20;
            red7=100;
            green7=100;
            blue7=100;
            red8=100;
            green8=100;
            white=100;
            red9=120;
            green9=120;
            blue9=120;
            //white=100;
            black=100;
            red10=40;
            break;

        case 'e':
            rainy=0;
            if(day==0)
            {
                sndPlaySound("Night.wav",SND_ASYNC);
            }
            else
                PlaySound(NULL, 0, 0);
            //cloudspeed=savecloudspeed;
            red=1;
            green=1;
            blue=1;
            red4=1.0;
            green4= 0.95;
            blue4= 0.0;
            red5=1.0;
            green5= 1.0;
            blue5= 0.70;
            red7=249;
            green7=216;
            blue7=7;
            red8=225;
            green8=249;
            white=255;
            red9=135;
            green9=165;
            blue9=242;
            //white=30;
            black-30;
            red10=30;
            break;

        case 's':
            starenable=1;
            rainy=0;
            //white=30;
            if(starenable==1 && day==0)
                sndPlaySound("Night.wav",SND_ASYNC);
                red6=1;
                green6=1;
                blue6=1;
                white=30;
            if(starenable==1 && day==1)
                PlaySound(NULL, 0, 0);
                red9=135;
                green9=165;
                blue9=242;
                red7=249;
                green7=216;
                blue7=7;
                red8=225;
                green8=249;
                white=255;
                black=0;
                red10=255;
            white = 30;

            break;

        case 'c':
            starenable=0;
            sndPlaySound("Night.wav",SND_ASYNC);
            red6=0.20;
            green6=0.20;
            blue6=0.26;
            white=30;
            black-30;
            red10=30;
            break;
   }
}

void moon()
{
    glColor3f(red5,green5,blue5);
	glTranslatef(0.25,0.90,1.0);
    glutSolidSphere(.08,40,40);
}

void star()
{
    glColor3f(red6,green6,blue6);
    glPointSize(5);
    glLoadIdentity();
    glBegin(GL_POINTS);
        glVertex2f(-0.1,.7);
        glVertex2f(-0.2,.9);
        glVertex2f(-0.3,.65);
        glVertex2f(-0.25,.85);
        glVertex2f(-0.45,.8);
        glVertex2f(-0.5,.75);
        glVertex2f(-0.7,.82);
        glVertex2f(-0.65,.65);
        glVertex2f(-0.8,.93);
        glVertex2f(-0.85,.68);
        glVertex2f(-0.95,.75);

        glVertex2f(0.2,.9);
        glVertex2f(0.3,.7);
        glVertex2f(0.4,.9);
        glVertex2f(0.5,.65);
        glVertex2f(0.45,.75);
        glVertex2f(0.65,.8);
        glVertex2f(0.8,.75);
        glVertex2f(0.9,.68);
        glVertex2f(0.95,.85);
        glVertex2f(0.8,.93);
        glVertex2f(0.75,.86);
        glVertex2f(0.95,.95);
    glEnd();
}

void Rain()
{
    glTranslatef(0,position1,0);
    glColor3f(1,1,1);
    glLineWidth(2);

    glTranslatef(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(-0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(2,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

    glTranslatef(0.1,0,0);
    glBegin(GL_LINES);
        glVertex2f(1,1);
        glVertex2f(0.985,.95);
        glVertex2f(0.97,.9);
        glVertex2f(0.955,.85);
        glVertex2f(0.94,.8);
        glVertex2f(0.925,.75);
        glVertex2f(0.91,.7);
        glVertex2f(0.895,.65);
        glVertex2f(0.88,.6);
        glVertex2f(0.865,.55);
        glVertex2f(0.85,.5);
        glVertex2f(0.835,.45);
        glVertex2f(0.82,.4);
        glVertex2f(0.805,.35);
        glVertex2f(0.79,0.3);
        glVertex2f(0.775,0.25);
        glVertex2f(0.76,0.2);
        glVertex2f(0.745,0.15);
        glVertex2f(0.73,0.1);
        glVertex2f(0.715,0.05);
        glVertex2f(0.7,0);
        glVertex2f(0.685,-.05);
        glVertex2f(0.67,-.1);
        glVertex2f(0.655,-.15);
        glVertex2f(0.64,-.2);
        glVertex2f(0.625,-.25);
        glVertex2f(0.61,-.3);
        glVertex2f(0.595,-.35);
        glVertex2f(0.58,-.4);
        glVertex2f(0.565,-.45);
        glVertex2f(0.55,-.5);
        glVertex2f(0.535,-.55);
        glVertex2f(0.52,-.6);
        glVertex2f(0.505,-.65);
        glVertex2f(0.49,-.7);
        glVertex2f(0.475,-.75);
        glVertex2f(0.46,-.8);
        glVertex2f(0.445,-.85);
        glVertex2f(0.43,-.9);
        glVertex2f(0.415,-.95);
    glEnd();

}

void Axis()
{
    glBegin(GL_LINES);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red

	glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(1.0f, 0.0f);    // x, y

	glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(0.0f, 1.0f);    // x, y

    glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(-1.0f, 0.0f);    // x, y

	glVertex2f(0.0f, 0.0f);    // x, y
	glVertex2f(0.0f, -1.0f);

	glEnd();
}

void Road()
{
    glBegin(GL_QUADS);

	glColor3ub(135, 117, 121);

	glVertex2f(-0.24f, -1.0f);
	glVertex2f(0.06f, -1.0f);
	glVertex2f(0.38f, -0.34f);
	glVertex2f(0.16f, -0.32f);

    glVertex2f(0.16f, -0.32f);
	glVertex2f(0.38f, -0.34);
	glVertex2f(0.28f, -0.12f);
	glVertex2f(0.1f, -0.1f);

	///MIDDLE
	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.28f, -0.12);
	glVertex2f(0.36f, 0.0f);
	glVertex2f(0.26f, 0.08f);

	///LEFT THIN
    glVertex2f(0.15f, 0.24f);
	glVertex2f(-0.75f, 0.28);
	glVertex2f(-0.75f, 0.2f);
	glVertex2f(-0.02f, 0.1f);

	glVertex2f(-0.75f, 0.28);
	glVertex2f(-0.75f, 0.2f);
	glVertex2f(-1.0f, 0.2);
	glVertex2f(-1.0f, 0.28f);

    glEnd();

    ///LEFT TURN

    glBegin(GL_POLYGON);
    glColor3ub(135, 117, 121);

	glVertex2f(0.15f, 0.14f);
	glVertex2f(0.36f, 0.0);
	glVertex2f(0.48f, 0.16f);
	glVertex2f(0.40f, 0.18f);
	glVertex2f(0.15f, 0.24f);

	glEnd();


}

void grassRightSide()
{
    glBegin(GL_POLYGON);

	glColor3ub(0, 219, 43);

	glVertex2f(0.38f, -0.34f);
	glVertex2f(0.46f, -0.34f);
	glVertex2f(0.48f, -0.30f);
	glVertex2f(0.62f, -0.30f);

	glVertex2f(0.62f, -0.22f);
	glVertex2f(0.46f, -0.22);
	glVertex2f(0.40f, -0.08f);
	glVertex2f(0.32f, -0.06f);
	glVertex2f(0.28f, -0.12f);

    glEnd();

    ///***FOR GRASS (After Stair Right Side)***

    glBegin(GL_QUADS);

	glColor3ub(0, 219, 43);

    glVertex2f(0.72f, -0.30f);
	glVertex2f(1.0f, -0.30f);
	glVertex2f(1.0f, -0.22f);
	glVertex2f(0.72f, -0.22f);

	///RIGHT UPPER
	glVertex2f(0.54f, 0.30f);
	glVertex2f(1.0f, 0.30f);
	glVertex2f(1.0f, -0.13f);
	glVertex2f(0.54f, -0.13f);

	glVertex2f(0.54f, 0.30f);
	glVertex2f(1.0f, 0.30f);
	glVertex2f(1.0f, 0.5f);
	glVertex2f(0.54f, 0.5f);

	///MIDDLE
	glVertex2f(-0.10f, 0.0f);
	glVertex2f(-0.06f, -0.06f);
	glVertex2f(0.14f, -0.06f);
	glVertex2f(0.08f, 0.0f);


	glEnd();



	glBegin(GL_TRIANGLES);

	glColor3ub(0, 219, 43);

    glVertex2f(0.54f, 0.30f);
	glVertex2f(0.45f, 0.0f);
	glVertex2f(0.60f, 0.0f);


	///LEFT MIDDLE

	glVertex2f(-1.0f, 0.15f);
	glVertex2f(-1.0f, -0.3f);
	glVertex2f(-0.73f, 0.15f);

	glVertex2f(-0.02f, 0.06f);
	glVertex2f(-0.02f, 0.0f);
	glVertex2f(0.04f, 0.0f);

	glEnd();
}

void grassLeftSide()
{
    glBegin(GL_QUADS);

	glColor3ub(0, 219, 43);

    glVertex2f(0.1f, -0.1f);
	glVertex2f(-0.02f, -0.08f);
	glVertex2f(-0.02f, -0.16f);
	glVertex2f(0.04f, -0.22f);

    glVertex2f(0.04f, -0.22f);
	glVertex2f(0.04f, -0.36f);
	glVertex2f(0.1f, -0.422f);
	glVertex2f(0.16f, -0.32f);

	glVertex2f(0.1f, -0.1f);
	glVertex2f(0.04f, -0.22f);
	glVertex2f(0.04f, -0.36f);
	glVertex2f(0.16f, -0.32f);

	glEnd();

    ///***FOR GRASS(LEFT SIDE) Before Stair***

    glBegin(GL_POLYGON);

	glColor3ub(0, 219, 43);

	glVertex2f(-1.0f, -0.40f);
	glVertex2f(-0.80f, -0.40f);
	glVertex2f(-0.668f, -0.40f);
	glVertex2f(-0.72f, -0.30f);
	glVertex2f(-1.0f, -0.30f);

    glEnd();

    ///***FOR GRASS(LEFT SIDE) After Stair***

    glBegin(GL_QUADS);

	glColor3ub(0, 219, 43);

	glVertex2f(-0.60f, -0.295f);
	glVertex2f(-0.55f, -0.22f);
	glVertex2f(-0.58f, -0.185f);
	glVertex2f(-0.64f, -0.22f);

	glVertex2f(-0.58f, -0.185f);
	glVertex2f(-0.55f, -0.22f);
	glVertex2f(-0.45f, -0.08f);
	glVertex2f(-0.48f, -0.08f);

	glVertex2f(-0.48f, -0.08f);
	glVertex2f(-0.45f, -0.08f);
	glVertex2f(-0.48f, 0.0f);
	glVertex2f(-0.50f, 0.0f);

	glVertex2f(-0.50f, 0.0f);
	glVertex2f(-0.48f, 0.0f);
	glVertex2f(-0.71f, 0.165f);
	glVertex2f(-0.70f, 0.15f);

    glEnd();
}

void grassMiddle()
{
    glLoadIdentity();
    glBegin(GL_POLYGON);

	glColor3ub(0, 219, 43);

    glVertex2f(0.15f, 0.14f);
	glVertex2f(0.18f, 0.12f);
	glVertex2f(0.122f, 0.045f);
	glVertex2f(0.19f, 0.0f);
	glVertex2f(0.26f, 0.08f);

    glEnd();


    ///RIGHT UPPER
	glLoadIdentity();
	glColor3ub(0, 219, 43);

	glBegin(GL_QUADS);
	glVertex2f(0.36f, 0.0f);
	glVertex2f(0.48f, -0.03f);
	glVertex2f(0.5f, 0.1f);
	glVertex2f(0.44f, 0.14f);

	glVertex2f(0.36f, 0.0f);
	glVertex2f(0.5f, 0.1f);
	glVertex2f(0.54f, 0.3f);
	glVertex2f(0.44f, 0.14f);

	///MIDDLE UPPER
	glVertex2f(0.0f, 0.40f);
	glVertex2f(0.0f, 0.25f);
	glVertex2f(0.40f, 0.18f);
	glVertex2f(0.55f, 0.40f);

	///MIDDLE HOME LEFT SIDE
	glVertex2f(-0.2f, 0.1f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.02f, 0.0f);
	glVertex2f(-0.02f, 0.16f);

	glVertex2f(-0.16f, 0.08f);
	glVertex2f(-0.01f, 0.15f);
	glVertex2f(-0.6f, 0.2f);
	glVertex2f(-0.6f, 0.16f);

	///MIDDLE HOME LEFT SIDE(UPPER)
	glVertex2f(0.15f, 0.21f);
	glVertex2f(0.0f, 0.50f);
	glVertex2f(-0.1f, 0.50f);
	glVertex2f(-0.1f, 0.23f);

	glVertex2f(0.43f, 0.23f);
	glVertex2f(0.43f, 0.50f);
	glVertex2f(-1.0f, 0.50f);
	glVertex2f(-1.0f, 0.23f);

	glVertex2f(-0.68f, 0.18f);
	glVertex2f(-0.68f, 0.2f);
	glVertex2f(-1.0f, 0.2f);
	glVertex2f(-1.0f, 0.18f);

	glVertex2f(0.43f, 0.40f);
	glVertex2f(1.0f, 0.40f);
	glVertex2f(1.0f, 0.50f);
	glVertex2f(0.43f, 0.50f);

    glEnd();
}

void Stair()
{
    ///***FOR STAIR(Right Side)***
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(0.62f, -0.32f);
	glVertex2f(0.72f, -0.32f);

	glVertex2f(0.62f, -0.32f);
	glVertex2f(0.62f, -0.22f);

	glVertex2f(0.72f, -0.32f);
	glVertex2f(0.72f, -0.22f);

	glVertex2f(0.62f, -0.22f);
	glVertex2f(0.72f, -0.22f);

	glVertex2f(0.62f, -0.24f);
	glVertex2f(0.72f, -0.24f);

	glVertex2f(0.62f, -0.26f);
	glVertex2f(0.72f, -0.26f);

	glVertex2f(0.62f, -0.28f);
	glVertex2f(0.72f, -0.28f);

	glVertex2f(0.62f, -0.30f);
	glVertex2f(0.72f, -0.30f);

    glEnd();

    ///***FOR STAIR(Left Side)***

    glBegin(GL_QUADS);

	glColor3ub(234, 204, 204);

	glVertex2f(-0.669f, -0.40f);
	glVertex2f(-0.60f, -0.295f);
	glVertex2f(-0.64f, -0.22f);
	glVertex2f(-0.72f, -0.30f);

    glEnd();

    glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(-0.669f, -0.40f);
	glVertex2f(-0.60f, -0.295f);

	glVertex2f(-0.60f, -0.295f);
	glVertex2f(-0.64f, -0.22f);

	glVertex2f(-0.64f, -0.22f);
	glVertex2f(-0.72f, -0.30f);

	glVertex2f(-0.669f, -0.40f);
	glVertex2f(-0.72f, -0.30f);

    ///
	glVertex2f(-0.71f, -0.32f);
	glVertex2f(-0.63f, -0.235f);

	glVertex2f(-0.7f, -0.34f);
	glVertex2f(-0.62f, -0.255f);

	glVertex2f(-0.689f, -0.368f);
	glVertex2f(-0.61f, -0.27f);

    glEnd();
}

void Water()
{
    ///***FOR WATER(RIGHT SIDE)***

	glBegin(GL_QUADS);

	glColor3ub(103, 180, 247);

    glVertex2f(0.16f, -1.0f);
	glVertex2f(0.46f, -0.333f);
	glVertex2f(1.0f, -0.32f);
	glVertex2f(1.0f, -1.0f);

	glEnd();


	///***FOR WATER (LEFT SIDE)***

	glBegin(GL_POLYGON);

	glColor3ub(103, 180, 247);

	glVertex2f(-0.46f, -0.08f);
	glVertex2f(-0.60f, -0.20f);
	glVertex2f(-0.50f, -0.30f);
	glVertex2f(-0.80f, -0.60f);

	glVertex2f(-0.80f, -1.0f);
	glVertex2f(-0.24f, -1.0);
	glVertex2f(-0.30f, -0.86f);
	glVertex2f(0.04f, -0.36f);
	glVertex2f(0.04f, -0.22f);

	glVertex2f(-0.02f, -0.16f);
	glVertex2f(-0.02f, -0.08f);

    glEnd();

    glBegin(GL_TRIANGLES);

	glColor3ub(103, 180, 247);

	glVertex2f(-0.24f, -1.0f);
	glVertex2f(-0.17f, -0.88f);
	glVertex2f(-0.30f, -0.82f);

    glEnd();

    glBegin(GL_QUADS);

	glColor3ub(103, 180, 247);

	glVertex2f(-0.80f, -1.0f);
	glVertex2f(-0.80f, -0.60f);
	glVertex2f(-1.0f, -0.60f);
	glVertex2f(-1.0f, -1.0f);

	///LAST DOWN TO UP LEFT SIDE
	glVertex2f(-0.46f, -0.08f);
	glVertex2f(-0.02f, -0.08f);
	glVertex2f(-0.10f, 0.0f);
	glVertex2f(-0.48f, 0.0f);

	glVertex2f(-0.10f, 0.0f);
	glVertex2f(-0.48f, 0.0f);
	glVertex2f(-0.68f, 0.14f);
	glVertex2f(-0.10f, 0.27f);

	glVertex2f(-0.68f, 0.18f);
	glVertex2f(-0.68f, 0.14f);
	glVertex2f(-1.0f, 0.14f);
	glVertex2f(-1.0f, 0.18f);

	///
	glVertex2f(-1.0f, -0.34f);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f(1.0f, -1.0f);
	glVertex2f(1.0f, -0.34f);

    glEnd();

}

void Stone()
{
    int triangleAmount = 30;
    GLfloat x=0.39f;
    GLfloat y=-0.4f;
    GLfloat radius =.02f;
    glColor3ub(201, 139, 76);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.4f;
    GLfloat y1=-0.375f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.41f;
    GLfloat y2=-0.355f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.42f;
    GLfloat y4=-0.34f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius * cos(i *  twicePi / triangleAmount)),
            y4 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.44f;
    GLfloat y5=-0.33f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius * cos(i *  twicePi / triangleAmount)),
            y5 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=0.46f;
    GLfloat y6=-0.325f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius * cos(i *  twicePi / triangleAmount)),
            y6 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=0.48f;
    GLfloat y7=-0.315f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius * cos(i *  twicePi / triangleAmount)),
            y7 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=0.5f;
    GLfloat y8=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius * cos(i *  twicePi / triangleAmount)),
            y8 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x9=0.52f;
    GLfloat y9=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9, y9); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x9 + (radius * cos(i *  twicePi / triangleAmount)),
            y9 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x10=0.55f;
    GLfloat y10=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x10, y10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x10 + (radius * cos(i *  twicePi / triangleAmount)),
            y10 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x11=0.58f;
    GLfloat y11=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x11, y11); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x11 + (radius * cos(i *  twicePi / triangleAmount)),
            y11 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x12=0.6f;
    GLfloat y12=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x12, y12); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x12 + (radius * cos(i *  twicePi / triangleAmount)),
            y12 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x13=0.74f;
    GLfloat y13=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x13, y13); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x13 + (radius * cos(i *  twicePi / triangleAmount)),
            y13 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x14=0.77f;
    GLfloat y14=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x14, y14); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x14 + (radius * cos(i *  twicePi / triangleAmount)),
            y14 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x15=0.80f;
    GLfloat y15=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x15, y15); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x15 + (radius * cos(i *  twicePi / triangleAmount)),
            y15 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x16=0.83f;
    GLfloat y16=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x16, y16); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x16 + (radius * cos(i *  twicePi / triangleAmount)),
            y16 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x17=0.86f;
    GLfloat y17=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x17, y17); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x17 + (radius * cos(i *  twicePi / triangleAmount)),
            y17 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x18=0.89f;
    GLfloat y18=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x18, y18); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x18 + (radius * cos(i *  twicePi / triangleAmount)),
            y18 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x19=0.92f;
    GLfloat y19=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x19, y19); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x19 + (radius * cos(i *  twicePi / triangleAmount)),
            y19 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x20=0.95f;
    GLfloat y20=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x20, y20); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x20 + (radius * cos(i *  twicePi / triangleAmount)),
            y20 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x21=0.98f;
    GLfloat y21=-0.31f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x21, y21); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x21 + (radius * cos(i *  twicePi / triangleAmount)),
            y21 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    ///LEFT SIDE

    GLfloat x22=-0.60f;
    GLfloat y22=-0.28f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x22, y22); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x22 + (radius * cos(i *  twicePi / triangleAmount)),
            y22 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x23=-0.585f;
    GLfloat y23=-0.255f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x23, y23); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x23 + (radius * cos(i *  twicePi / triangleAmount)),
            y23 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();



    GLfloat x24=-0.570f;
    GLfloat y24=-0.232f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x24, y24); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x24 + (radius * cos(i *  twicePi / triangleAmount)),
            y24 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();



    GLfloat x25=-0.562f;
    GLfloat y25=-0.216f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x25, y25); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x25 + (radius * cos(i *  twicePi / triangleAmount)),
            y25 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x26=-0.551f;
    GLfloat y26=-0.20f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x26, y26); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x26 + (radius * cos(i *  twicePi / triangleAmount)),
            y26 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x27=-0.54f;
    GLfloat y27=-0.184f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x27, y27); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x27 + (radius * cos(i *  twicePi / triangleAmount)),
            y27 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x28=-0.53f;
    GLfloat y28=-0.170f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x28, y28); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x28 + (radius * cos(i *  twicePi / triangleAmount)),
            y28 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    GLfloat x29=-0.52f;
    GLfloat y29=-0.155f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x29, y29); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x29 + (radius * cos(i *  twicePi / triangleAmount)),
            y29 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    /// STONE FONT SIDE


    GLfloat x30=-0.985f;
    GLfloat y30=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x30, y30); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x30 + (radius * cos(i *  twicePi / triangleAmount)),
            y30 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    GLfloat x31=-0.955f;
    GLfloat y31=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x31, y31); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x31 + (radius * cos(i *  twicePi / triangleAmount)),
            y31 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();



    GLfloat x32=-0.925f;
    GLfloat y32=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x32, y32); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x32 + (radius * cos(i *  twicePi / triangleAmount)),
            y32 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    GLfloat x33=-0.895f;
    GLfloat y33=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x33, y33); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x33 + (radius * cos(i *  twicePi / triangleAmount)),
            y33 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    GLfloat x34=-0.865f;
    GLfloat y34=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x34, y34); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x34 + (radius * cos(i *  twicePi / triangleAmount)),
            y34 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x35=-0.835f;
    GLfloat y35=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x35, y35); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x35 + (radius * cos(i *  twicePi / triangleAmount)),
            y35 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x36=-0.805f;
    GLfloat y36=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x36, y36); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x36 + (radius * cos(i *  twicePi / triangleAmount)),
            y36 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x37=-0.775f;
    GLfloat y37=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x37, y37); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x37 + (radius * cos(i *  twicePi / triangleAmount)),
            y37 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x38=-0.745f;
    GLfloat y38=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x38, y38); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x38 + (radius * cos(i *  twicePi / triangleAmount)),
            y38 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x39=-0.715f;
    GLfloat y39=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x39, y39); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x39 + (radius * cos(i *  twicePi / triangleAmount)),
            y39 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x40=-0.69f;
    GLfloat y40=-0.4f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x40, y40); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x40 + (radius * cos(i *  twicePi / triangleAmount)),
            y40 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}

void BridgeLeftSide()
{
    glBegin(GL_QUADS);

	glColor3ub(0, 0, 0);

    glVertex2f(-0.02f, -0.16f);
	glVertex2f(-0.02f, -0.08f);
	glVertex2f(-0.06f, -0.08f);
	glVertex2f(-0.06f, -0.16f);

	glVertex2f(-0.48f, -0.16f);
	glVertex2f(-0.48f, -0.08f);
	glVertex2f(-0.52f, -0.08f);
	glVertex2f(-0.52f, -0.16f);

	///
    glColor3ub(70, 70, 70);
	glVertex2f(-0.52f, -0.08f);
	glVertex2f(-0.02f, -0.08f);
	glVertex2f(-0.03f, -0.06f);
	glVertex2f(-0.51f, -0.06f);

	glEnd();

	///RIGHT TRIANGLE
	glBegin(GL_LINES);

	glColor3ub(255, 0, 0);

    glVertex2f(-0.06f, -0.08f);
	glVertex2f(-0.06f, -0.0266f);

	glVertex2f(-0.06f, 0.0f);
	glVertex2f(-0.028f, -0.067f);

	glVertex2f(-0.06f, -0.0266f);
	glVertex2f(-0.04f, -0.08);

	///LEFT TRIANGLE
	glBegin(GL_LINES);

	glColor3ub(255, 0, 0);

    glVertex2f(-0.512f, -0.065f);
	glVertex2f(-0.48f, 0.0f);

	glVertex2f(-0.48f, -0.0266f);
	glVertex2f(-0.48f, -0.08f);

	glVertex2f(-0.505f, -0.08f);
	glVertex2f(-0.48f, -0.0266f);

	///
	///glLineWidth(3);
	glVertex2f(-0.48f, 0.0f);
	glVertex2f(-0.06f, 0.0f);

	glVertex2f(-0.48f, -0.0266f);
	glVertex2f(-0.06f, -0.0266f);

	glVertex2f(-0.48f, -0.0532f);
	glVertex2f(-0.06f, -0.0532f);

	///RALING
	glVertex2f(-0.45f, -0.0266f);
	glVertex2f(-0.45f, -0.08f);

	glVertex2f(-0.42f, -0.0266f);
	glVertex2f(-0.42f, -0.08f);

	glVertex2f(-0.39f, -0.0266f);
	glVertex2f(-0.39f, -0.08f);

	glVertex2f(-0.36f, -0.0266f);
	glVertex2f(-0.36f, -0.08f);

	glVertex2f(-0.33f, -0.0266f);
	glVertex2f(-0.33f, -0.08f);

	glVertex2f(-0.30f, -0.0266f);
	glVertex2f(-0.30f, -0.08f);

	glVertex2f(-0.27f, -0.0266f);
	glVertex2f(-0.27f, -0.08f);

	glVertex2f(-0.24f, -0.0266f);
	glVertex2f(-0.24f, -0.08f);

	glVertex2f(-0.21f, -0.0266f);
	glVertex2f(-0.21f, -0.08f);

	glVertex2f(-0.18f, -0.0266f);
	glVertex2f(-0.18f, -0.08f);

	glVertex2f(-0.15f, -0.0266f);
	glVertex2f(-0.15f, -0.08f);

	glVertex2f(-0.12f, -0.0266f);
	glVertex2f(-0.12f, -0.08f);

	glVertex2f(-0.09f, -0.0266f);
	glVertex2f(-0.09f, -0.08f);


	glEnd();

}

void BridgeFrontSide()
{
    glBegin(GL_QUADS);

    ///Grass
	glColor3ub(0, 219, 43);

    glVertex2f(0.08f, -0.96f);
    glVertex2f(0.06f, -1.0f);

	glVertex2f(0.13f, -1.0f);
	glVertex2f(0.15f, -0.96f);

	///UP
	glVertex2f(0.34f, -0.42f);
    glVertex2f(0.39f, -0.42f);

	glVertex2f(0.43f, -0.34f);
	glVertex2f(0.38f, -0.34f);


	glEnd();

    glBegin(GL_LINES);

	glColor3ub(0, 0, 7);

    glVertex2f(0.08f, -0.96f);
	glVertex2f(0.05f, -0.90f);

	glVertex2f(0.34f, -0.42f);
	glVertex2f(0.32f, -0.38f);

	///
	glVertex2f(0.05f, -0.90f);
    glVertex2f(0.32f, -0.38f);

    glColor3ub(0, 0, 0);
    glVertex2f(0.08f, -0.96f);
    glVertex2f(0.34f, -0.42f);

    glVertex2f(0.07f, -0.94f);
    glVertex2f(0.332f, -0.408f);

    glVertex2f(0.06f, -0.92f);
    glVertex2f(0.326f, -0.394f);



    ///PILLER
    glVertex2f(0.08f, -0.96f);
    glVertex2f(0.15f, -0.96f);

    glVertex2f(0.34f, -0.42f);
    glVertex2f(0.39f, -0.42f);



    ///RALLING
    glColor3ub(0, 0, 7);
    glVertex2f(0.08f, -0.848f);
    glVertex2f(0.105f, -0.91f);

    glVertex2f(0.10f, -0.801f);
    glVertex2f(0.127f, -0.870f);

    glVertex2f(0.121f, -0.761f);
    glVertex2f(0.144f, -0.826f);

    glVertex2f(0.141f, -0.721f);
    glVertex2f(0.163f, -0.786f);

    glVertex2f(0.161f, -0.681f);
    glVertex2f(0.184f, -0.744f);

    glVertex2f(0.179f, -0.642f);
    glVertex2f(0.207f, -0.708f);

    glVertex2f(0.202f, -0.610f);
    glVertex2f(0.226f, -0.666f);

    glVertex2f(0.218f, -0.574f);
    glVertex2f(0.244f, -0.626);

    glVertex2f(0.238f, -0.531f);
    glVertex2f(0.264f, -0.586);

    glVertex2f(0.258f, -0.491f);
    glVertex2f(0.284f, -0.546);

    glVertex2f(0.280f, -0.450f);
    glVertex2f(0.304f, -0.506);

    glVertex2f(0.304f, -0.414f);
    glVertex2f(0.322f, -0.461);



    ///***LS******
    ///RALLING
    glColor3ub(0, 0, 0);
    glVertex2f(-0.17f, -0.88f);
    glVertex2f(-0.20f, -0.82f);

    glVertex2f(0.11f, -0.41f);
    glVertex2f(0.09f, -0.36f);

    glVertex2f(-0.14f, -0.84f);
    glVertex2f(-0.17f, -0.775f);

    glVertex2f(-0.15f, -0.74f);
    glVertex2f(-0.12, -0.80f);

    glVertex2f(-0.12f, -0.70f);
    glVertex2f(-0.095, -0.755f);

    glVertex2f(-0.095f, -0.66f);
    glVertex2f(-0.068, -0.71f);

    glVertex2f(-0.07f, -0.618f);
    glVertex2f(-0.041, -0.665f);

    glVertex2f(-0.047f, -0.570f);
    glVertex2f(-0.014, -0.62f);

    glVertex2f(-0.0176f, -0.522f);
    glVertex2f(0.013, -0.575f);

    glVertex2f(0.010f, -0.48);
    glVertex2f(0.037, -0.53f);

    glVertex2f(0.038f, -0.438f);
    glVertex2f(0.062, -0.487f);

    glVertex2f(0.066f, -0.396f);
    glVertex2f(0.087, -0.443f);

    ///HEAD
    glVertex2f(-0.20f, -0.82f);
    glVertex2f(0.09f, -0.36f);

    glColor3ub(0, 0, 0);
    glVertex2f(-0.17f, -0.88f);
    glVertex2f(0.11f, -0.41f);

    glVertex2f(-0.178f, -0.86f);
    glVertex2f(0.107f, -0.39f);

    glVertex2f(-0.188f, -0.845f);
    glVertex2f(0.10f, -0.372f);

    ///PILLLER
    glVertex2f(-0.17f, -0.88f);
    glVertex2f(-0.24f, -0.88f);



    glEnd();

    glBegin(GL_QUADS);

	glColor3ub(0, 219, 43);

    glVertex2f(-0.169f, -0.88f);
    glVertex2f(-0.24f, -0.88f);

	glVertex2f(-0.33f, -1.0f);
	glVertex2f(-0.239f, -1.0f);

	glEnd();
    ///********///



}

void Mountain()
{
	int triangleAmount = 30;
    GLfloat x=0.0f;
    GLfloat y=0.51f;
    GLfloat radius =.09f;
    glColor3ub(75, 156, 211);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y+ (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.11f;
    GLfloat y1=0.53f;
    GLfloat radius1 =.09f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.22f;
    GLfloat y2=0.53f;
    GLfloat radius2 =.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius2 * cos(i *  twicePi / triangleAmount)),
            y2 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.33f;
    GLfloat y3=0.56f;
    GLfloat radius3 =0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius3 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius3 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.44f;
    GLfloat y4=0.54f;
    GLfloat radius4 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius4 * cos(i *  twicePi / triangleAmount)),
            y4 + (radius4 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    GLfloat x5=0.55f;
    GLfloat y5=0.55f;
    GLfloat radius5 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius5 * cos(i *  twicePi / triangleAmount)),
            y5 + (radius5 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=0.66f;
    GLfloat y6=0.50f;
    GLfloat radius6 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius6 * cos(i *  twicePi / triangleAmount)),
            y6 + (radius6 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=0.77f;
    GLfloat y7=0.555f;
    GLfloat radius7 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius7 * cos(i *  twicePi / triangleAmount)),
            y7 + (radius7 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=0.86f;
    GLfloat y8=0.55f;
    GLfloat radius8 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius8 * cos(i *  twicePi / triangleAmount)),
            y8 + (radius8 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x9=1.0f;
    GLfloat y9=0.57f;
    GLfloat radius9 =0.13f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9, y9); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x9 + (radius9 * cos(i *  twicePi / triangleAmount)),
            y9 + (radius9 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    ///LEFT SIDE

    GLfloat x10=-0.11f;
    GLfloat y10=0.53f;
    GLfloat radius10 =.09f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x10, y10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x10 + (radius10 * cos(i *  twicePi / triangleAmount)),
            y10 + (radius10 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x11=-0.22f;
    GLfloat y11=0.53f;
    GLfloat radius11 =.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x11, y11); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x11 + (radius11 * cos(i *  twicePi / triangleAmount)),
            y11 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x12=-0.33f;
    GLfloat y12=0.56f;
    GLfloat radius12 =0.08f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x12, y12); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x12 + (radius12 * cos(i *  twicePi / triangleAmount)),
            y12 + (radius12 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x13=-0.44f;
    GLfloat y13=0.54f;
    GLfloat radius13 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x13, y13); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x13 + (radius13 * cos(i *  twicePi / triangleAmount)),
            y13 + (radius13 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


    GLfloat x14=-0.55f;
    GLfloat y14=0.55f;
    GLfloat radius14 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x14, y14); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x14 + (radius14 * cos(i *  twicePi / triangleAmount)),
            y14 + (radius14 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x15=-0.66f;
    GLfloat y15=0.50f;
    GLfloat radius15 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x15, y15); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x15 + (radius15 * cos(i *  twicePi / triangleAmount)),
            y15 + (radius15 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

     GLfloat x16=-0.77f;
    GLfloat y16=0.555f;
    GLfloat radius16 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x16, y16); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x16 + (radius16 * cos(i *  twicePi / triangleAmount)),
            y16 + (radius16 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x17=-0.86f;
    GLfloat y17=0.55f;
    GLfloat radius17 =0.07f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x17, y17); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x17 + (radius17 * cos(i *  twicePi / triangleAmount)),
            y17 + (radius17 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x18=-1.0f;
    GLfloat y18=0.57f;
    GLfloat radius18 =0.13f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x18, y18); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x18 + (radius18 * cos(i *  twicePi / triangleAmount)),
            y18 + (radius18 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


}

void Sky()
{
    glBegin(GL_QUADS);

	glColor3ub(red9, green9, blue9);

    glVertex2f(-1.0f, 0.50f);
    glVertex2f(1.0f, 0.50f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);

	glEnd();
}

void Sun()
{
    int triangleAmount = 30;
    GLfloat x=0.0f;
    GLfloat y=0.85f;
    GLfloat radius =.08f;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(red7, green7, blue7);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.0f;
    GLfloat y1=0.85f;
    GLfloat radius1 =.07f;


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(red8, green8, blue7);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Cloud()
{
    glPushMatrix();
    glTranslatef(position3,0.0f,0.0f);
    ///CLOUD RIGHT SIDE

    ///CLOUD-01
    int triangleAmount = 30;
    GLfloat x=0.8f;
    GLfloat y=0.8f;
    GLfloat radius =.04f;
    glColor3ub(white, white, white);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.86f;
    GLfloat y1=0.8f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.83f;
    GLfloat y2=0.84f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    ///CLOUD-02
    GLfloat x3=0.55f;
    GLfloat y3=0.9f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius * cos(i *  twicePi / triangleAmount)),
            y3 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.61f;
    GLfloat y4=0.9f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius * cos(i *  twicePi / triangleAmount)),
            y4 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.58f;
    GLfloat y5=0.94f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius * cos(i *  twicePi / triangleAmount)),
            y5 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    ///CLOUD-03
    GLfloat x6=0.30f;
    GLfloat y6=0.75f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius * cos(i *  twicePi / triangleAmount)),
            y6 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=0.36f;
    GLfloat y7=0.75f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius * cos(i *  twicePi / triangleAmount)),
            y7 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=0.33f;
    GLfloat y8=0.79f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius * cos(i *  twicePi / triangleAmount)),
            y8 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();

    ///CLOUD LEFT SIDE

    glPushMatrix();
    glTranslatef(position2,0.0f,0.0f);

    ///CLOUD-04
    GLfloat x9=-0.8f;
    GLfloat y9=0.8f;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9, y9); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x9 + (radius * cos(i *  twicePi / triangleAmount)),
            y9 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x10=-0.86f;
    GLfloat y10=0.8f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x10, y10); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x10 + (radius * cos(i *  twicePi / triangleAmount)),
            y10 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x11=-0.83f;
    GLfloat y11=0.84f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x11, y11); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x11 + (radius * cos(i *  twicePi / triangleAmount)),
            y11 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    ///CLOUD-05
    GLfloat x12=-0.55f;
    GLfloat y12=0.9f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x12, y12); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x12 + (radius * cos(i *  twicePi / triangleAmount)),
            y12 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x13=-0.61f;
    GLfloat y13=0.9f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x13, y13); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x13 + (radius * cos(i *  twicePi / triangleAmount)),
            y13 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x14=-0.58f;
    GLfloat y14=0.94f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x14, y14); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x14 + (radius * cos(i *  twicePi / triangleAmount)),
            y14 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    ///CLOUD-06
    GLfloat x15=-0.30f;
    GLfloat y15=0.75f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x15, y15); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x15 + (radius * cos(i *  twicePi / triangleAmount)),
            y15 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x16=-0.36f;
    GLfloat y16=0.75f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x16, y16); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x16 + (radius * cos(i *  twicePi / triangleAmount)),
            y16 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x17=-0.33f;
    GLfloat y17=0.79f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x17, y17); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x17 + (radius * cos(i *  twicePi / triangleAmount)),
            y17 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glPopMatrix();
}

void Home_1()
{
    ///********HOME-01 (LEFT SIDE)***********

    glBegin(GL_QUADS);

	glColor3ub(211, 201, 8);

	///FRONT SIDE
	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.68f, -0.14f);
	glVertex2f(-0.68f, -0.08f);
	glVertex2f(-0.76f, -0.1f);

	///LEFT SIDE
	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.76f, -0.10f);
	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.88f, -0.20f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.75f, -0.11f);
	glVertex2f(-0.67f, -0.09f);
	glVertex2f(-0.70f, -0.04f);


    ///VARANDA
    glColor3ub(70, 70, 46);

	glVertex2f(-0.88f, -0.20f);
	glVertex2f(-0.895f, -0.215f);
	glVertex2f(-0.745f, -0.215f);
	glVertex2f(-0.76f, -0.20f);

	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.745f, -0.215f);
	glVertex2f(-0.675f, -0.155f);
	glVertex2f(-0.68f, -0.14f);

	///DOOR
	glColor3ub(0, 0, 0);
    glVertex2f(-0.71f, -0.165f);
	glVertex2f(-0.73f, -0.178f);
	glVertex2f(-0.73f, -0.128f);
	glVertex2f(-0.71f, -0.12f);

    glEnd();


    ///TRIANGLE
    glBegin(GL_TRIANGLES);

	glColor3ub(211, 201, 8);

	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.76f, -0.10f);

    glEnd();

    ///WALL
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.88f, -0.20f);

	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.76f, -0.10f);

	glVertex2f(-0.68f, -0.14f);
	glVertex2f(-0.68f, -0.09f);

	glColor3ub(255, 0, 0);
	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.89f, -0.11f);

	///WINDOW
	glColor3ub(0, 0, 0);
	glVertex2f(-0.84f, -0.13f);
	glVertex2f(-0.84f, -0.17f);

	glVertex2f(-0.84f, -0.17f);
	glVertex2f(-0.80f, -0.17f);

	glVertex2f(-0.80f, -0.17f);
	glVertex2f(-0.80f, -0.13f);

	glVertex2f(-0.80f, -0.13f);
	glVertex2f(-0.84f, -0.13f);

	///WINDOW SHED

    glVertex2f(-0.83f, -0.13f);
	glVertex2f(-0.83f, -0.17f);

	glVertex2f(-0.82f, -0.13f);
	glVertex2f(-0.82f, -0.17f);

	glVertex2f(-0.81f, -0.13f);
	glVertex2f(-0.81f, -0.17f);


    glEnd();
}

void Home_3()
{
    glLoadIdentity();
    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.68f, -0.14f);
	glVertex2f(0.68f, -0.04f);
	glVertex2f(0.52f, -0.04f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.52f, -0.04f);
	glVertex2f(0.70f, -0.04f);
	glVertex2f(0.68f, 0.02f);

	///DOOR
	glColor3ub(17, 114, 100);

	glVertex2f(0.58f, -0.14f);
	glVertex2f(0.62f, -0.14f);
	glVertex2f(0.62f, -0.06f);
	glVertex2f(0.58f, -0.06f);

	///VARANDA
	glColor3ub(150, 150, 150);

	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.585f, -0.152f);
	glVertex2f(0.58f, -0.14f);

	glVertex2f(0.62f, -0.14f);
	glVertex2f(0.625f, -0.152f);
	glVertex2f(0.685f, -0.152f);
	glVertex2f(0.68f, -0.14f);

	glColor3ub(0, 0, 0);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.525f, -0.178f);
	glVertex2f(0.585f, -0.178f);
	glVertex2f(0.585f, -0.152f);

	glVertex2f(0.625f, -0.152f);
	glVertex2f(0.625f, -0.178f);
	glVertex2f(0.685f, -0.178f);
	glVertex2f(0.685f, -0.152f);

	glEnd();

	glBegin(GL_POLYGON);
	glLoadIdentity();

	glColor3ub(255, 255, 255);

	///LEFT SIDE
	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.52f, -0.04f);
	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.44f, 0.0f);
	glVertex2f(0.44f, -0.06f);

	///GROUND LEFT SIDE
	glColor3ub(0, 0, 0);
	glVertex2f(0.44f, -0.06f);
	glVertex2f(0.44f, -0.08f);
	glVertex2f(0.525f, -0.178f);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.52f, -0.14f);


	glEnd();

	///WALL
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(0.68f, -0.14f);
	glVertex2f(0.68f, -0.04f);

	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.52f, -0.04f);

	glVertex2f(0.44f, -0.06f);
	glVertex2f(0.44f, 0.0f);

	glColor3ub(255, 0, 0);
	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.43f, -0.01f);

	///WINDOW
	glColor3ub(0, 0, 0);

	glVertex2f(0.536f, -0.115f);
	glVertex2f(0.56f, -0.115f);

	glVertex2f(0.536f, -0.115f);
	glVertex2f(0.535f, -0.08f);

	glVertex2f(0.536f, -0.08f);
	glVertex2f(0.56f, -0.08f);

	glVertex2f(0.56f, -0.08f);
	glVertex2f(0.56f, -0.115f);

	///
	glVertex2f(0.544f, -0.115f);
	glVertex2f(0.544f, -0.08f);

	glVertex2f(0.552f, -0.115f);
	glVertex2f(0.552f, -0.08f);

	///RIGHT WINDOW


	glVertex2f(0.64f, -0.115f);
	glVertex2f(0.664f, -0.115f);

	glVertex2f(0.64f, -0.115f);
	glVertex2f(0.64f, -0.08f);

	glVertex2f(0.64f, -0.08f);
	glVertex2f(0.664f, -0.08f);

	glVertex2f(0.664f, -0.08f);
	glVertex2f(0.664f, -0.115f);

	///
	glVertex2f(0.648f, -0.115f);
	glVertex2f(0.648f, -0.08f);

	glVertex2f(0.656f, -0.115f);
	glVertex2f(0.656f, -0.08f);

	///left WINDOW


	glVertex2f(0.46f, -0.03f);
	glVertex2f(0.484f, -0.05f);

	glVertex2f(0.46f, -0.03f);
	glVertex2f(0.46f, -0.06f);

    glVertex2f(0.46f, -0.06f);
	glVertex2f(0.484f, -0.08f);

	glVertex2f(0.484f, -0.08f);
	glVertex2f(0.484f, -0.05f);



	///

	glVertex2f(0.468f, -0.04f);
	glVertex2f(0.468f, -0.065f);

	glVertex2f(0.476f, -0.04f);
	glVertex2f(0.476f, -0.07f);

	///STAIR

	glVertex2f(0.585f, -0.152f);
	glVertex2f(0.625f, -0.152f);

	glVertex2f(0.585f, -0.178f);
	glVertex2f(0.625f, -0.178f);

	glVertex2f(0.585f, -0.165f);
	glVertex2f(0.625f, -0.165f);


	glEnd();


}

void Home_4()
{
    glLoadIdentity();
    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(0.76f, 0.0f);
	glVertex2f(0.76f, -0.12f);
	glVertex2f(0.88f, -0.12f);
	glVertex2f(0.88f, 0.0f);

	///DOOR
	glColor3ub(62, 85, 127);

	glVertex2f(0.805f, -0.12f);
	glVertex2f(0.835f, -0.12f);
	glVertex2f(0.835f, -0.03f);
	glVertex2f(0.805f, -0.03f);

	///VARANDA
	glColor3ub(150, 150, 150);

	glVertex2f(0.76f, -0.12f);
	glVertex2f(0.76f, -0.135f);
	glVertex2f(0.805f, -0.135f);
	glVertex2f(0.805f, -0.12f);

	glVertex2f(0.835f, -0.135f);
	glVertex2f(0.88f, -0.135f);
	glVertex2f(0.88f, -0.12f);
	glVertex2f(0.835f, -0.12f);

	///WINDOW
	glColor3ub(45, 132, 115);

	glVertex2f(0.772f, -0.10f);
	glVertex2f(0.792f, -0.10f);
	glVertex2f(0.792f, -0.06f);
	glVertex2f(0.772f, -0.06f);

	glVertex2f(0.847f, -0.10f);
	glVertex2f(0.867f, -0.10f);
	glVertex2f(0.867f, -0.06f);
	glVertex2f(0.847f, -0.06f);

	///GROUND
	glColor3ub(0, 0, 0);

	glVertex2f(0.76f, -0.135f);
	glVertex2f(0.76f, -0.16f);
	glVertex2f(0.805f, -0.16f);
	glVertex2f(0.805f, -0.135f);

	glVertex2f(0.835f, -0.135f);
	glVertex2f(0.835f, -0.16f);
	glVertex2f(0.88f, -0.16f);
	glVertex2f(0.88f, -0.135f);

	glEnd();

	glBegin(GL_TRIANGLES);
	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(0.74f, 0.0f);
	glVertex2f(0.90f, 0.0f);
	glVertex2f(0.82f, 0.08f);

	glEnd();

    ///STAIR

	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);

	glVertex2f(0.805f, -0.13f);
	glVertex2f(0.835f, -0.131f);

	glVertex2f(0.805f, -0.14f);
	glVertex2f(0.835f, -0.14f);

	glVertex2f(0.805f, -0.15f);
	glVertex2f(0.835f, -0.15f);

	glVertex2f(0.805f, -0.16f);
	glVertex2f(0.835f, -0.16f);


	glEnd();
}

void Home_5()
{
    glLoadIdentity();
    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(-0.02f, 0.08f);
	glVertex2f(0.12f, 0.06f);
	glVertex2f(0.12f, 0.16f);
	glVertex2f(-0.02f, 0.16f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(-0.027f, 0.155f);
	glVertex2f(0.12f, 0.155f);
	glVertex2f(0.15f, 0.24f);
	glVertex2f(0.0f, 0.22f);

	///DOOR
	glColor3ub(0, 0, 0);

	glVertex2f(0.035f, 0.07f);
	glVertex2f(0.065f, 0.069f);
	glVertex2f(0.065f, 0.13f);
	glVertex2f(0.035f, 0.13f);

	///GROUND
	glColor3ub(100, 100, 100);

	glVertex2f(-0.02f, 0.08f);
	glVertex2f(-0.03f, 0.065f);
	glVertex2f(0.122f, 0.045f);
	glVertex2f(0.12f, 0.06f);

	glVertex2f(0.12f, 0.06f);
	glVertex2f(0.122f, 0.045f);
	glVertex2f(0.182f, 0.115f);
	glVertex2f(0.18f, 0.12f);


	glEnd();

	glBegin(GL_POLYGON);

	glColor3ub(255, 255, 255);

	///RIGHT SIDE
	glVertex2f(0.15f, 0.24f);
	glVertex2f(0.12f, 0.16f);
	glVertex2f(0.12f, 0.06f);
	glVertex2f(0.18f, 0.12f);
	glVertex2f(0.18f, 0.20f);


	glEnd();

	///WALL
	glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(0.18f, 0.20f);
	glVertex2f(0.18f, 0.115f);

	glVertex2f(0.12f, 0.16f);
	glVertex2f(0.12f, 0.06f);

	glVertex2f(-0.02f, 0.154f);
    glVertex2f(-0.02f, 0.08f);

    ///
    glColor3ub(255, 0, 0);

	glVertex2f(0.15f, 0.24f);
	glVertex2f(0.187f, 0.195f);

	///WINDOW-01
	glColor3ub(0, 0, 0);

	glVertex2f(0.016f, 0.09f);
	glVertex2f(-0.002f, 0.09f);

	glVertex2f(-0.002f, 0.09f);
	glVertex2f(-0.002f, 0.11f);

	glVertex2f(-0.002f, 0.11f);
	glVertex2f(0.016f, 0.11f);

	glVertex2f(0.016f, 0.11f);
	glVertex2f(0.016f, 0.09f);

	///
	glVertex2f(0.0035f, 0.09f);
	glVertex2f(0.0035f, 0.11f);

	glVertex2f(0.01f, 0.09f);
	glVertex2f(0.01f, 0.11f);

	///WINDOW-02
	glVertex2f(0.103f, 0.08f);
	glVertex2f(0.082f, 0.08f);

	glVertex2f(0.082f, 0.08f);
	glVertex2f(0.082f, 0.11f);

	glVertex2f(0.082f, 0.11f);
	glVertex2f(0.103f, 0.11f);

	glVertex2f(0.103f, 0.11f);
	glVertex2f(0.103f, 0.08f);

	///
	glVertex2f(0.089f, 0.08f);
	glVertex2f(0.089f, 0.11f);

	glVertex2f(0.096f, 0.08f);
	glVertex2f(0.096f, 0.11f);

	///WINDOW-03
	glVertex2f(0.14f, 0.11f);
	glVertex2f(0.16f, 0.13f);

	glVertex2f(0.14f, 0.11f);
	glVertex2f(0.14f, 0.14f);

	glVertex2f(0.14f, 0.14f);
	glVertex2f(0.16f, 0.152f);

	glVertex2f(0.16f, 0.152f);
	glVertex2f(0.16f, 0.126f);

	///
	glVertex2f(0.147f, 0.12f);
	glVertex2f(0.147f, 0.148f);

	glVertex2f(0.154f, 0.122f);
	glVertex2f(0.154f, 0.148f);

	glEnd();
}

void Home_6()
{
    glLoadIdentity();
    glTranslatef(-1.0f, 0.2f, 0.0f);
    glScalef(0.6f, 0.85f, 0.0f);

    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.68f, -0.14f);
	glVertex2f(0.68f, -0.04f);
	glVertex2f(0.52f, -0.04f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.52f, -0.04f);
	glVertex2f(0.70f, -0.04f);
	glVertex2f(0.68f, 0.02f);

	///DOOR
	glColor3ub(17, 114, 100);

	glVertex2f(0.58f, -0.14f);
	glVertex2f(0.62f, -0.14f);
	glVertex2f(0.62f, -0.06f);
	glVertex2f(0.58f, -0.06f);

	///VARANDA
	glColor3ub(150, 150, 150);

	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.585f, -0.152f);
	glVertex2f(0.58f, -0.14f);

	glVertex2f(0.62f, -0.14f);
	glVertex2f(0.625f, -0.152f);
	glVertex2f(0.685f, -0.152f);
	glVertex2f(0.68f, -0.14f);

	glColor3ub(0, 0, 0);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.525f, -0.178f);
	glVertex2f(0.585f, -0.178f);
	glVertex2f(0.585f, -0.152f);

	glVertex2f(0.625f, -0.152f);
	glVertex2f(0.625f, -0.178f);
	glVertex2f(0.685f, -0.178f);
	glVertex2f(0.685f, -0.152f);

	glEnd();

	glBegin(GL_POLYGON);
	glLoadIdentity();

	glColor3ub(255, 255, 255);

	///LEFT SIDE
	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.52f, -0.04f);
	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.44f, 0.0f);
	glVertex2f(0.44f, -0.06f);

	///GROUND LEFT SIDE
	glColor3ub(0, 0, 0);
	glVertex2f(0.44f, -0.06f);
	glVertex2f(0.44f, -0.08f);
	glVertex2f(0.525f, -0.178f);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.52f, -0.14f);


	glEnd();

	///WALL
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(0.68f, -0.14f);
	glVertex2f(0.68f, -0.04f);

	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.52f, -0.04f);

	glVertex2f(0.44f, -0.06f);
	glVertex2f(0.44f, 0.0f);

	glColor3ub(255, 0, 0);
	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.43f, -0.01f);

	///WINDOW
	glColor3ub(0, 0, 0);

	glVertex2f(0.536f, -0.115f);
	glVertex2f(0.56f, -0.115f);

	glVertex2f(0.536f, -0.115f);
	glVertex2f(0.535f, -0.08f);

	glVertex2f(0.536f, -0.08f);
	glVertex2f(0.56f, -0.08f);

	glVertex2f(0.56f, -0.08f);
	glVertex2f(0.56f, -0.115f);

	///
	glVertex2f(0.544f, -0.115f);
	glVertex2f(0.544f, -0.08f);

	glVertex2f(0.552f, -0.115f);
	glVertex2f(0.552f, -0.08f);

	///RIGHT WINDOW


	glVertex2f(0.64f, -0.115f);
	glVertex2f(0.664f, -0.115f);

	glVertex2f(0.64f, -0.115f);
	glVertex2f(0.64f, -0.08f);

	glVertex2f(0.64f, -0.08f);
	glVertex2f(0.664f, -0.08f);

	glVertex2f(0.664f, -0.08f);
	glVertex2f(0.664f, -0.115f);

	///
	glVertex2f(0.648f, -0.115f);
	glVertex2f(0.648f, -0.08f);

	glVertex2f(0.656f, -0.115f);
	glVertex2f(0.656f, -0.08f);

	///left WINDOW


	glVertex2f(0.46f, -0.03f);
	glVertex2f(0.484f, -0.05f);

	glVertex2f(0.46f, -0.03f);
	glVertex2f(0.46f, -0.06f);

    glVertex2f(0.46f, -0.06f);
	glVertex2f(0.484f, -0.08f);

	glVertex2f(0.484f, -0.08f);
	glVertex2f(0.484f, -0.05f);



	///

	glVertex2f(0.468f, -0.04f);
	glVertex2f(0.468f, -0.065f);

	glVertex2f(0.476f, -0.04f);
	glVertex2f(0.476f, -0.07f);

	///STAIR

	glVertex2f(0.585f, -0.152f);
	glVertex2f(0.625f, -0.152f);

	glVertex2f(0.585f, -0.178f);
	glVertex2f(0.625f, -0.178f);

	glVertex2f(0.585f, -0.165f);
	glVertex2f(0.625f, -0.165f);


	glEnd();
}

void Home_7()
{
    glLoadIdentity();

    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(0.56f, 0.42f);
	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.50f, 0.34f);
	glVertex2f(0.50f, 0.46f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(0.49f, 0.45f);
	glVertex2f(0.55f, 0.41f);
	glVertex2f(0.60f, 0.48f);
	glVertex2f(0.54f, 0.52f);

	///DOOR

    glColor3ub(0, 0, 0);

	glVertex2f(0.51f, 0.33f);
	glVertex2f(0.53f, 0.32f);
	glVertex2f(0.53f, 0.39f);
	glVertex2f(0.51f, 0.40f);

	///GROUND
	glColor3ub(150, 150, 150);

	glVertex2f(0.50f, 0.34f);
	glVertex2f(0.49f, 0.33f);
	glVertex2f(0.563f, 0.28f);
	glVertex2f(0.56f, 0.30f);


	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.563f, 0.28f);
	glVertex2f(0.645f, 0.37f);
	glVertex2f(0.64f, 0.37f);


	glEnd();

	///RIGHT SIDE
	glBegin(GL_POLYGON);

	glColor3ub(255, 255, 255);

	glVertex2f(0.56f, 0.42f);
	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.64f, 0.37f);
	glVertex2f(0.64f, 0.42f);
	glVertex2f(0.60f, 0.48f);

	glEnd();

	///WALL
	glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(0.50f, 0.442f);
	glVertex2f(0.50f, 0.34f);

	glVertex2f(0.50f, 0.34f);
	glVertex2f(0.56f, 0.30f);

	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.56f, 0.422f);

	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.64f, 0.37f);

	glVertex2f(0.64f, 0.37f);
	glVertex2f(0.64f, 0.42f);

	///WINDOW RIGHT SIDE
	glVertex2f(0.585f, 0.36f);
	glVertex2f(0.615f, 0.385f);

	glVertex2f(0.615f, 0.385f);
	glVertex2f(0.615f, 0.415f);

	glVertex2f(0.615f, 0.415f);
	glVertex2f(0.585f, 0.39f);

	glVertex2f(0.585f, 0.39f);
	glVertex2f(0.585f, 0.36f);

	///WINDOW SHED
	glVertex2f(0.595f, 0.397f);
	glVertex2f(0.595f, 0.367f);

	glVertex2f(0.605f, 0.404f);
	glVertex2f(0.605f, 0.374f);

	///WINDOW FRONT SIDE
	glVertex2f(0.535f, 0.37f);
	glVertex2f(0.535f, 0.34f);

	glVertex2f(0.535f, 0.34f);
	glVertex2f(0.55f, 0.33f);

	glVertex2f(0.55f, 0.33f);
	glVertex2f(0.55f, 0.362f);

	glVertex2f(0.55f, 0.362f);
	glVertex2f(0.535f, 0.37f);

	///WINDOW SHED
	glVertex2f(0.54f, 0.37f);
	glVertex2f(0.54f, 0.34f);

	glVertex2f(0.545f, 0.365f);
	glVertex2f(0.545f, 0.335f);


	glColor3ub(255, 0, 0);

	glVertex2f(0.60f, 0.48f);
	glVertex2f(0.645f, 0.412f);

	glEnd();
}

void Home_8()
{

    //glLoadIdentity();
    glTranslatef(-0.17f, 0.38f, 0.0f);
    glScalef(0.4f, 0.45f, 0.0f);
    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(-0.02f, 0.08f);
	glVertex2f(0.12f, 0.06f);
	glVertex2f(0.12f, 0.16f);
	glVertex2f(-0.02f, 0.16f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(-0.027f, 0.155f);
	glVertex2f(0.12f, 0.155f);
	glVertex2f(0.15f, 0.24f);
	glVertex2f(0.0f, 0.22f);

	///DOOR
	glColor3ub(0, 0, 0);

	glVertex2f(0.035f, 0.07f);
	glVertex2f(0.065f, 0.069f);
	glVertex2f(0.065f, 0.13f);
	glVertex2f(0.035f, 0.13f);

	///GROUND
	glColor3ub(100, 100, 100);

	glVertex2f(-0.02f, 0.08f);
	glVertex2f(-0.03f, 0.065f);
	glVertex2f(0.122f, 0.045f);
	glVertex2f(0.12f, 0.06f);

	glVertex2f(0.12f, 0.06f);
	glVertex2f(0.122f, 0.045f);
	glVertex2f(0.182f, 0.115f);
	glVertex2f(0.18f, 0.12f);


	glEnd();

	glBegin(GL_POLYGON);

	glColor3ub(255, 255, 255);

	///RIGHT SIDE
	glVertex2f(0.15f, 0.24f);
	glVertex2f(0.12f, 0.16f);
	glVertex2f(0.12f, 0.06f);
	glVertex2f(0.18f, 0.12f);
	glVertex2f(0.18f, 0.20f);


	glEnd();

	///WALL
	glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(0.18f, 0.20f);
	glVertex2f(0.18f, 0.115f);

	glVertex2f(0.12f, 0.16f);
	glVertex2f(0.12f, 0.06f);

	glVertex2f(-0.02f, 0.154f);
    glVertex2f(-0.02f, 0.08f);

    ///
    glColor3ub(255, 0, 0);

	glVertex2f(0.15f, 0.24f);
	glVertex2f(0.187f, 0.195f);

	///WINDOW-01
	glColor3ub(0, 0, 0);

	glVertex2f(0.016f, 0.09f);
	glVertex2f(-0.002f, 0.09f);

	glVertex2f(-0.002f, 0.09f);
	glVertex2f(-0.002f, 0.11f);

	glVertex2f(-0.002f, 0.11f);
	glVertex2f(0.016f, 0.11f);

	glVertex2f(0.016f, 0.11f);
	glVertex2f(0.016f, 0.09f);

	///
	glVertex2f(0.0035f, 0.09f);
	glVertex2f(0.0035f, 0.11f);

	glVertex2f(0.01f, 0.09f);
	glVertex2f(0.01f, 0.11f);

	///WINDOW-02
	glVertex2f(0.103f, 0.08f);
	glVertex2f(0.082f, 0.08f);

	glVertex2f(0.082f, 0.08f);
	glVertex2f(0.082f, 0.11f);

	glVertex2f(0.082f, 0.11f);
	glVertex2f(0.103f, 0.11f);

	glVertex2f(0.103f, 0.11f);
	glVertex2f(0.103f, 0.08f);

	///
	glVertex2f(0.089f, 0.08f);
	glVertex2f(0.089f, 0.11f);

	glVertex2f(0.096f, 0.08f);
	glVertex2f(0.096f, 0.11f);

	///WINDOW-03
	glVertex2f(0.14f, 0.11f);
	glVertex2f(0.16f, 0.13f);

	glVertex2f(0.14f, 0.11f);
	glVertex2f(0.14f, 0.14f);

	glVertex2f(0.14f, 0.14f);
	glVertex2f(0.16f, 0.152f);

	glVertex2f(0.16f, 0.152f);
	glVertex2f(0.16f, 0.126f);

	///
	glVertex2f(0.147f, 0.12f);
	glVertex2f(0.147f, 0.148f);

	glVertex2f(0.154f, 0.122f);
	glVertex2f(0.154f, 0.148f);

	glEnd();
}

void Home_9()
{
    ///********HOME-09 (UPPER SIDE)***********

    glTranslatef(1.4f, 0.22f, 0.0f);
    glScalef(1.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);

	glColor3ub(211, 201, 8);

	///FRONT SIDE
	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.68f, -0.14f);
	glVertex2f(-0.68f, -0.08f);
	glVertex2f(-0.76f, -0.1f);

	///LEFT SIDE
	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.76f, -0.10f);
	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.88f, -0.20f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.75f, -0.11f);
	glVertex2f(-0.67f, -0.09f);
	glVertex2f(-0.70f, -0.04f);


    ///VARANDA
    glColor3ub(70, 70, 46);

	glVertex2f(-0.88f, -0.20f);
	glVertex2f(-0.895f, -0.215f);
	glVertex2f(-0.745f, -0.215f);
	glVertex2f(-0.76f, -0.20f);

	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.745f, -0.215f);
	glVertex2f(-0.675f, -0.155f);
	glVertex2f(-0.68f, -0.14f);

	///DOOR
	glColor3ub(0, 0, 0);
    glVertex2f(-0.71f, -0.165f);
	glVertex2f(-0.73f, -0.178f);
	glVertex2f(-0.73f, -0.128f);
	glVertex2f(-0.71f, -0.12f);

    glEnd();


    ///TRIANGLE
    glBegin(GL_TRIANGLES);

	glColor3ub(211, 201, 8);

	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.76f, -0.10f);

    glEnd();

    ///WALL
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.88f, -0.20f);

	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.76f, -0.10f);

	glVertex2f(-0.68f, -0.14f);
	glVertex2f(-0.68f, -0.09f);

	glColor3ub(255, 0, 0);
	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.89f, -0.11f);

	///WINDOW
	glColor3ub(0, 0, 0);
	glVertex2f(-0.84f, -0.13f);
	glVertex2f(-0.84f, -0.17f);

	glVertex2f(-0.84f, -0.17f);
	glVertex2f(-0.80f, -0.17f);

	glVertex2f(-0.80f, -0.17f);
	glVertex2f(-0.80f, -0.13f);

	glVertex2f(-0.80f, -0.13f);
	glVertex2f(-0.84f, -0.13f);

	///WINDOW SHED

    glVertex2f(-0.83f, -0.13f);
	glVertex2f(-0.83f, -0.17f);

	glVertex2f(-0.82f, -0.13f);
	glVertex2f(-0.82f, -0.17f);

	glVertex2f(-0.81f, -0.13f);
	glVertex2f(-0.81f, -0.17f);


    glEnd();
}

void Home_10()
{
    glLoadIdentity();
    glTranslatef(0.0f, 0.3f, 0.0f);
    glScalef(0.5f, 0.5f, 0.0f);

    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(0.56f, 0.42f);
	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.50f, 0.34f);
	glVertex2f(0.50f, 0.46f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(0.49f, 0.45f);
	glVertex2f(0.55f, 0.41f);
	glVertex2f(0.60f, 0.48f);
	glVertex2f(0.54f, 0.52f);

	///DOOR

    glColor3ub(0, 0, 0);

	glVertex2f(0.51f, 0.33f);
	glVertex2f(0.53f, 0.32f);
	glVertex2f(0.53f, 0.39f);
	glVertex2f(0.51f, 0.40f);

	///GROUND
	glColor3ub(150, 150, 150);

	glVertex2f(0.50f, 0.34f);
	glVertex2f(0.49f, 0.33f);
	glVertex2f(0.563f, 0.28f);
	glVertex2f(0.56f, 0.30f);


	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.563f, 0.28f);
	glVertex2f(0.645f, 0.37f);
	glVertex2f(0.64f, 0.37f);


	glEnd();

	///RIGHT SIDE
	glBegin(GL_POLYGON);

	glColor3ub(255, 255, 255);

	glVertex2f(0.56f, 0.42f);
	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.64f, 0.37f);
	glVertex2f(0.64f, 0.42f);
	glVertex2f(0.60f, 0.48f);

	glEnd();

	///WALL
	glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(0.50f, 0.442f);
	glVertex2f(0.50f, 0.34f);

	glVertex2f(0.50f, 0.34f);
	glVertex2f(0.56f, 0.30f);

	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.56f, 0.422f);

	glVertex2f(0.56f, 0.30f);
	glVertex2f(0.64f, 0.37f);

	glVertex2f(0.64f, 0.37f);
	glVertex2f(0.64f, 0.42f);

	///WINDOW RIGHT SIDE
	glVertex2f(0.585f, 0.36f);
	glVertex2f(0.615f, 0.385f);

	glVertex2f(0.615f, 0.385f);
	glVertex2f(0.615f, 0.415f);

	glVertex2f(0.615f, 0.415f);
	glVertex2f(0.585f, 0.39f);

	glVertex2f(0.585f, 0.39f);
	glVertex2f(0.585f, 0.36f);

	///WINDOW SHED
	glVertex2f(0.595f, 0.397f);
	glVertex2f(0.595f, 0.367f);

	glVertex2f(0.605f, 0.404f);
	glVertex2f(0.605f, 0.374f);

	///WINDOW FRONT SIDE
	glVertex2f(0.535f, 0.37f);
	glVertex2f(0.535f, 0.34f);

	glVertex2f(0.535f, 0.34f);
	glVertex2f(0.55f, 0.33f);

	glVertex2f(0.55f, 0.33f);
	glVertex2f(0.55f, 0.362f);

	glVertex2f(0.55f, 0.362f);
	glVertex2f(0.535f, 0.37f);

	///WINDOW SHED
	glVertex2f(0.54f, 0.37f);
	glVertex2f(0.54f, 0.34f);

	glVertex2f(0.545f, 0.365f);
	glVertex2f(0.545f, 0.335f);


	glColor3ub(255, 0, 0);

	glVertex2f(0.60f, 0.48f);
	glVertex2f(0.645f, 0.412f);

	glEnd();
}

void Home_11()
{

    ///********HOME-11 (LEFT SIDE)***********

    glLoadIdentity();
    glTranslatef(-0.6f, 0.5f, 0.0f);
    glScalef(0.4f, 0.5f, 0.0f);

    glBegin(GL_QUADS);

	glColor3ub(211, 201, 8);

	///FRONT SIDE
	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.68f, -0.14f);
	glVertex2f(-0.68f, -0.08f);
	glVertex2f(-0.76f, -0.1f);

	///LEFT SIDE
	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.76f, -0.10f);
	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.88f, -0.20f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.75f, -0.11f);
	glVertex2f(-0.67f, -0.09f);
	glVertex2f(-0.70f, -0.04f);


    ///VARANDA
    glColor3ub(70, 70, 46);

	glVertex2f(-0.88f, -0.20f);
	glVertex2f(-0.895f, -0.215f);
	glVertex2f(-0.745f, -0.215f);
	glVertex2f(-0.76f, -0.20f);

	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.745f, -0.215f);
	glVertex2f(-0.675f, -0.155f);
	glVertex2f(-0.68f, -0.14f);

	///DOOR
	glColor3ub(0, 0, 0);
    glVertex2f(-0.71f, -0.165f);
	glVertex2f(-0.73f, -0.178f);
	glVertex2f(-0.73f, -0.128f);
	glVertex2f(-0.71f, -0.12f);

    glEnd();


    ///TRIANGLE
    glBegin(GL_TRIANGLES);

	glColor3ub(211, 201, 8);

	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.76f, -0.10f);

    glEnd();

    ///WALL
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(-0.88f, -0.10f);
	glVertex2f(-0.88f, -0.20f);

	glVertex2f(-0.76f, -0.20f);
	glVertex2f(-0.76f, -0.10f);

	glVertex2f(-0.68f, -0.14f);
	glVertex2f(-0.68f, -0.09f);

	glColor3ub(255, 0, 0);
	glVertex2f(-0.82f, -0.04f);
	glVertex2f(-0.89f, -0.11f);

	///WINDOW
	glColor3ub(0, 0, 0);
	glVertex2f(-0.84f, -0.13f);
	glVertex2f(-0.84f, -0.17f);

	glVertex2f(-0.84f, -0.17f);
	glVertex2f(-0.80f, -0.17f);

	glVertex2f(-0.80f, -0.17f);
	glVertex2f(-0.80f, -0.13f);

	glVertex2f(-0.80f, -0.13f);
	glVertex2f(-0.84f, -0.13f);

	///WINDOW SHED

    glVertex2f(-0.83f, -0.13f);
	glVertex2f(-0.83f, -0.17f);

	glVertex2f(-0.82f, -0.13f);
	glVertex2f(-0.82f, -0.17f);

	glVertex2f(-0.81f, -0.13f);
	glVertex2f(-0.81f, -0.17f);


    glEnd();
}

void Home_12()
{
    glLoadIdentity();
    glTranslatef(-0.8f, 0.48f, 0.0f);
    glScalef(0.5f, 0.5f, 0.0f);
    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(0.76f, 0.0f);
	glVertex2f(0.76f, -0.12f);
	glVertex2f(0.88f, -0.12f);
	glVertex2f(0.88f, 0.0f);

	///DOOR
	glColor3ub(62, 85, 127);

	glVertex2f(0.805f, -0.12f);
	glVertex2f(0.835f, -0.12f);
	glVertex2f(0.835f, -0.03f);
	glVertex2f(0.805f, -0.03f);

	///VARANDA
	glColor3ub(150, 150, 150);

	glVertex2f(0.76f, -0.12f);
	glVertex2f(0.76f, -0.135f);
	glVertex2f(0.805f, -0.135f);
	glVertex2f(0.805f, -0.12f);

	glVertex2f(0.835f, -0.135f);
	glVertex2f(0.88f, -0.135f);
	glVertex2f(0.88f, -0.12f);
	glVertex2f(0.835f, -0.12f);

	///WINDOW
	glColor3ub(45, 132, 115);

	glVertex2f(0.772f, -0.10f);
	glVertex2f(0.792f, -0.10f);
	glVertex2f(0.792f, -0.06f);
	glVertex2f(0.772f, -0.06f);

	glVertex2f(0.847f, -0.10f);
	glVertex2f(0.867f, -0.10f);
	glVertex2f(0.867f, -0.06f);
	glVertex2f(0.847f, -0.06f);

	///GROUND
	glColor3ub(0, 0, 0);

	glVertex2f(0.76f, -0.135f);
	glVertex2f(0.76f, -0.16f);
	glVertex2f(0.805f, -0.16f);
	glVertex2f(0.805f, -0.135f);

	glVertex2f(0.835f, -0.135f);
	glVertex2f(0.835f, -0.16f);
	glVertex2f(0.88f, -0.16f);
	glVertex2f(0.88f, -0.135f);

	glEnd();

	glBegin(GL_TRIANGLES);
	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(0.74f, 0.0f);
	glVertex2f(0.90f, 0.0f);
	glVertex2f(0.82f, 0.08f);

	glEnd();

    ///STAIR

	glBegin(GL_LINES);
	glColor3ub(0, 0, 0);

	glVertex2f(0.805f, -0.13f);
	glVertex2f(0.835f, -0.131f);

	glVertex2f(0.805f, -0.14f);
	glVertex2f(0.835f, -0.14f);

	glVertex2f(0.805f, -0.15f);
	glVertex2f(0.835f, -0.15f);

	glVertex2f(0.805f, -0.16f);
	glVertex2f(0.835f, -0.16f);


	glEnd();
}

void Home_13()
{
    glLoadIdentity();
    glTranslatef(-0.90f, 0.5f, 0.0f);
    glScalef(0.35f, 0.4f, 0.0f);
    glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);

	///FRONT SIDE
	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.68f, -0.14f);
	glVertex2f(0.68f, -0.04f);
	glVertex2f(0.52f, -0.04f);

	///SHED
	glColor3ub(210, 7, 7);

	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.52f, -0.04f);
	glVertex2f(0.70f, -0.04f);
	glVertex2f(0.68f, 0.02f);

	///DOOR
	glColor3ub(17, 114, 100);

	glVertex2f(0.58f, -0.14f);
	glVertex2f(0.62f, -0.14f);
	glVertex2f(0.62f, -0.06f);
	glVertex2f(0.58f, -0.06f);

	///VARANDA
	glColor3ub(150, 150, 150);

	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.585f, -0.152f);
	glVertex2f(0.58f, -0.14f);

	glVertex2f(0.62f, -0.14f);
	glVertex2f(0.625f, -0.152f);
	glVertex2f(0.685f, -0.152f);
	glVertex2f(0.68f, -0.14f);

	glColor3ub(0, 0, 0);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.525f, -0.178f);
	glVertex2f(0.585f, -0.178f);
	glVertex2f(0.585f, -0.152f);

	glVertex2f(0.625f, -0.152f);
	glVertex2f(0.625f, -0.178f);
	glVertex2f(0.685f, -0.178f);
	glVertex2f(0.685f, -0.152f);

	glEnd();

	glBegin(GL_POLYGON);
	glLoadIdentity();

	glColor3ub(255, 255, 255);

	///LEFT SIDE
	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.52f, -0.04f);
	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.44f, 0.0f);
	glVertex2f(0.44f, -0.06f);

	///GROUND LEFT SIDE
	glColor3ub(0, 0, 0);
	glVertex2f(0.44f, -0.06f);
	glVertex2f(0.44f, -0.08f);
	glVertex2f(0.525f, -0.178f);
	glVertex2f(0.525f, -0.152f);
	glVertex2f(0.52f, -0.14f);


	glEnd();

	///WALL
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0);

	glVertex2f(0.68f, -0.14f);
	glVertex2f(0.68f, -0.04f);

	glVertex2f(0.52f, -0.14f);
	glVertex2f(0.52f, -0.04f);

	glVertex2f(0.44f, -0.06f);
	glVertex2f(0.44f, 0.0f);

	glColor3ub(255, 0, 0);
	glVertex2f(0.48f, 0.04f);
	glVertex2f(0.43f, -0.01f);

	///WINDOW
	glColor3ub(0, 0, 0);

	glVertex2f(0.536f, -0.115f);
	glVertex2f(0.56f, -0.115f);

	glVertex2f(0.536f, -0.115f);
	glVertex2f(0.535f, -0.08f);

	glVertex2f(0.536f, -0.08f);
	glVertex2f(0.56f, -0.08f);

	glVertex2f(0.56f, -0.08f);
	glVertex2f(0.56f, -0.115f);

	///
	glVertex2f(0.544f, -0.115f);
	glVertex2f(0.544f, -0.08f);

	glVertex2f(0.552f, -0.115f);
	glVertex2f(0.552f, -0.08f);

	///RIGHT WINDOW


	glVertex2f(0.64f, -0.115f);
	glVertex2f(0.664f, -0.115f);

	glVertex2f(0.64f, -0.115f);
	glVertex2f(0.64f, -0.08f);

	glVertex2f(0.64f, -0.08f);
	glVertex2f(0.664f, -0.08f);

	glVertex2f(0.664f, -0.08f);
	glVertex2f(0.664f, -0.115f);

	///
	glVertex2f(0.648f, -0.115f);
	glVertex2f(0.648f, -0.08f);

	glVertex2f(0.656f, -0.115f);
	glVertex2f(0.656f, -0.08f);

	///left WINDOW


	glVertex2f(0.46f, -0.03f);
	glVertex2f(0.484f, -0.05f);

	glVertex2f(0.46f, -0.03f);
	glVertex2f(0.46f, -0.06f);

    glVertex2f(0.46f, -0.06f);
	glVertex2f(0.484f, -0.08f);

	glVertex2f(0.484f, -0.08f);
	glVertex2f(0.484f, -0.05f);



	///

	glVertex2f(0.468f, -0.04f);
	glVertex2f(0.468f, -0.065f);

	glVertex2f(0.476f, -0.04f);
	glVertex2f(0.476f, -0.07f);

	///STAIR

	glVertex2f(0.585f, -0.152f);
	glVertex2f(0.625f, -0.152f);

	glVertex2f(0.585f, -0.178f);
	glVertex2f(0.625f, -0.178f);

	glVertex2f(0.585f, -0.165f);
	glVertex2f(0.625f, -0.165f);


	glEnd();
}

void Tree1()
{
    glLoadIdentity();

    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.03f,0.30f);
    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.40f);
    glVertex2f(-0.03,0.40f);

    glVertex2f(-0.03f,0.33f);
    glVertex2f(0.03f,0.36f);
    glVertex2f(0.02f,0.37f);
    glVertex2f(-0.03,0.34f);

    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.31f);
    glVertex2f(-0.06f,0.34f);
    glVertex2f(-0.0345,0.32f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.035f;
    GLfloat y=0.42f;
    GLfloat radius =.025f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.02f;
    GLfloat y1=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.05f;
    GLfloat y2=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.03f;
    GLfloat y4=0.38f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y4 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.01f;
    GLfloat y5=0.37f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y5 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=-0.06f;
    GLfloat y6=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y6 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=-0.08f;
    GLfloat y7=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y7 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=-0.08f;
    GLfloat y8=0.325f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y8 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();




}

void Tree2()
{
    glLoadIdentity();
    glTranslatef(-0.8f,-0.5f,0.0f);
    glScalef(2.0f,2.0f,0.0f);
    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.03f,0.30f);
    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.40f);
    glVertex2f(-0.03,0.40f);

    glVertex2f(-0.03f,0.33f);
    glVertex2f(0.03f,0.36f);
    glVertex2f(0.02f,0.37f);
    glVertex2f(-0.03,0.34f);

    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.31f);
    glVertex2f(-0.06f,0.34f);
    glVertex2f(-0.0345,0.32f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.035f;
    GLfloat y=0.42f;
    GLfloat radius =.025f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.02f;
    GLfloat y1=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.05f;
    GLfloat y2=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.03f;
    GLfloat y4=0.38f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y4 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.01f;
    GLfloat y5=0.37f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y5 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=-0.06f;
    GLfloat y6=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y6 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=-0.08f;
    GLfloat y7=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y7 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=-0.08f;
    GLfloat y8=0.325f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y8 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Tree3()
{
    glLoadIdentity();

    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.28f,0.23f);
    glVertex2f(-0.29f,0.23f);
    glVertex2f(-0.29f,0.36f);
    glVertex2f(-0.28,0.36f);

    glVertex2f(-0.29f,0.25f);
    glVertex2f(-0.29f,0.26f);
    glVertex2f(-0.24f,0.34f);
    glVertex2f(-0.24,0.33f);

    glVertex2f(-0.29f,0.28f);
    glVertex2f(-0.29f,0.29f);
    glVertex2f(-0.31f,0.32f);
    glVertex2f(-0.315,0.31f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.285f;
    GLfloat y=0.37f;
    GLfloat radius =.03f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.26f;
    GLfloat y1=0.345f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.31f;
    GLfloat y2=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

}

void Tree4()
{
    glLoadIdentity();
    glTranslatef(1.45f,-0.4f,0.0f);
    glScalef(2.0f,2.0f,0.0f);

    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.28f,0.23f);
    glVertex2f(-0.29f,0.23f);
    glVertex2f(-0.29f,0.36f);
    glVertex2f(-0.28,0.36f);

    glVertex2f(-0.29f,0.25f);
    glVertex2f(-0.29f,0.26f);
    glVertex2f(-0.24f,0.34f);
    glVertex2f(-0.24,0.33f);

    glVertex2f(-0.29f,0.28f);
    glVertex2f(-0.29f,0.29f);
    glVertex2f(-0.31f,0.32f);
    glVertex2f(-0.315,0.31f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.285f;
    GLfloat y=0.37f;
    GLfloat radius =.03f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.26f;
    GLfloat y1=0.345f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.31f;
    GLfloat y2=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Tree5()
{
    glLoadIdentity();
    glTranslatef(1.57f,-0.67f,0.0f);
    glScalef(2.2f,2.2f,0.0f);

    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.28f,0.23f);
    glVertex2f(-0.29f,0.23f);
    glVertex2f(-0.29f,0.36f);
    glVertex2f(-0.28,0.36f);

    glVertex2f(-0.29f,0.25f);
    glVertex2f(-0.29f,0.26f);
    glVertex2f(-0.24f,0.34f);
    glVertex2f(-0.24,0.33f);

    glVertex2f(-0.29f,0.28f);
    glVertex2f(-0.29f,0.29f);
    glVertex2f(-0.31f,0.32f);
    glVertex2f(-0.315,0.31f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.285f;
    GLfloat y=0.37f;
    GLfloat radius =.03f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.26f;
    GLfloat y1=0.345f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.31f;
    GLfloat y2=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Tree6()
{
    glLoadIdentity();
    glTranslatef(0.70f,-0.14f,0.0f);
    glScalef(1.2f,1.4f,0.0f);

    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.28f,0.23f);
    glVertex2f(-0.29f,0.23f);
    glVertex2f(-0.29f,0.36f);
    glVertex2f(-0.28,0.36f);

    glVertex2f(-0.29f,0.25f);
    glVertex2f(-0.29f,0.26f);
    glVertex2f(-0.24f,0.34f);
    glVertex2f(-0.24,0.33f);

    glVertex2f(-0.29f,0.28f);
    glVertex2f(-0.29f,0.29f);
    glVertex2f(-0.31f,0.32f);
    glVertex2f(-0.315,0.31f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.285f;
    GLfloat y=0.37f;
    GLfloat radius =.03f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.26f;
    GLfloat y1=0.345f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.31f;
    GLfloat y2=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Tree7()
{
    glLoadIdentity();
    glTranslatef(0.2f,0.3f,0.0f);
    glScalef(0.7f,0.5f,0.0f);
    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.03f,0.30f);
    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.40f);
    glVertex2f(-0.03,0.40f);

    glVertex2f(-0.03f,0.33f);
    glVertex2f(0.03f,0.36f);
    glVertex2f(0.02f,0.37f);
    glVertex2f(-0.03,0.34f);

    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.31f);
    glVertex2f(-0.06f,0.34f);
    glVertex2f(-0.0345,0.32f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.035f;
    GLfloat y=0.42f;
    GLfloat radius =.025f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.02f;
    GLfloat y1=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.05f;
    GLfloat y2=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.03f;
    GLfloat y4=0.38f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y4 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.01f;
    GLfloat y5=0.37f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y5 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=-0.06f;
    GLfloat y6=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y6 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=-0.08f;
    GLfloat y7=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y7 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=-0.08f;
    GLfloat y8=0.325f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y8 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Tree8()
{
    glLoadIdentity();
    glTranslatef(0.8f,0.3f,0.0f);
    glScalef(0.7f,0.5f,0.0f);
    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.03f,0.30f);
    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.40f);
    glVertex2f(-0.03,0.40f);

    glVertex2f(-0.03f,0.33f);
    glVertex2f(0.03f,0.36f);
    glVertex2f(0.02f,0.37f);
    glVertex2f(-0.03,0.34f);

    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.31f);
    glVertex2f(-0.06f,0.34f);
    glVertex2f(-0.0345,0.32f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.035f;
    GLfloat y=0.42f;
    GLfloat radius =.025f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.02f;
    GLfloat y1=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.05f;
    GLfloat y2=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.03f;
    GLfloat y4=0.38f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y4 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.01f;
    GLfloat y5=0.37f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y5 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=-0.06f;
    GLfloat y6=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y6 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=-0.08f;
    GLfloat y7=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y7 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=-0.08f;
    GLfloat y8=0.325f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y8 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Tree9()
{
    glLoadIdentity();
    glTranslatef(-0.55f,0.3f,0.0f);
    glScalef(0.7f,0.5f,0.0f);
    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.03f,0.30f);
    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.40f);
    glVertex2f(-0.03,0.40f);

    glVertex2f(-0.03f,0.33f);
    glVertex2f(0.03f,0.36f);
    glVertex2f(0.02f,0.37f);
    glVertex2f(-0.03,0.34f);

    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.31f);
    glVertex2f(-0.06f,0.34f);
    glVertex2f(-0.0345,0.32f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.035f;
    GLfloat y=0.42f;
    GLfloat radius =.025f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.02f;
    GLfloat y1=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.05f;
    GLfloat y2=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.03f;
    GLfloat y4=0.38f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y4 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.01f;
    GLfloat y5=0.37f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y5 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=-0.06f;
    GLfloat y6=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y6 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=-0.08f;
    GLfloat y7=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y7 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=-0.08f;
    GLfloat y8=0.325f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y8 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Tree10()
{
    glLoadIdentity();
    glTranslatef(-0.25f,0.3f,0.0f);
    glScalef(0.7f,0.5f,0.0f);
    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.03f,0.30f);
    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.40f);
    glVertex2f(-0.03,0.40f);

    glVertex2f(-0.03f,0.33f);
    glVertex2f(0.03f,0.36f);
    glVertex2f(0.02f,0.37f);
    glVertex2f(-0.03,0.34f);

    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.31f);
    glVertex2f(-0.06f,0.34f);
    glVertex2f(-0.0345,0.32f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.035f;
    GLfloat y=0.42f;
    GLfloat radius =.025f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.02f;
    GLfloat y1=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.05f;
    GLfloat y2=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.03f;
    GLfloat y4=0.38f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y4 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.01f;
    GLfloat y5=0.37f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y5 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=-0.06f;
    GLfloat y6=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y6 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=-0.08f;
    GLfloat y7=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y7 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=-0.08f;
    GLfloat y8=0.325f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y8 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Tree11()
{
    glLoadIdentity();
    glTranslatef(-0.8f,0.3f,0.0f);
    glScalef(0.7f,0.5f,0.0f);
    glColor3ub(153, 118, 4);

    glBegin(GL_QUADS);
    glVertex2f(-0.03f,0.30f);
    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.40f);
    glVertex2f(-0.03,0.40f);

    glVertex2f(-0.03f,0.33f);
    glVertex2f(0.03f,0.36f);
    glVertex2f(0.02f,0.37f);
    glVertex2f(-0.03,0.34f);

    glVertex2f(-0.04f,0.30f);
    glVertex2f(-0.04f,0.31f);
    glVertex2f(-0.06f,0.34f);
    glVertex2f(-0.0345,0.32f);

    glEnd();

    int triangleAmount = 30;
    GLfloat x=-0.035f;
    GLfloat y=0.42f;
    GLfloat radius =.025f;
    glColor3ub(12, 104, 20);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=-0.02f;
    GLfloat y1=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius * cos(i *  twicePi / triangleAmount)),
            y1 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=-0.05f;
    GLfloat y2=0.40f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius * cos(i *  twicePi / triangleAmount)),
            y2 + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.025f;
    GLfloat y3=0.35f;
    GLfloat radius1 =.015f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x4=0.03f;
    GLfloat y4=0.38f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x4, y4); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x4 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y4 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x5=0.01f;
    GLfloat y5=0.37f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x5, y5); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x5 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y5 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x6=-0.06f;
    GLfloat y6=0.34f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x6, y6); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x6 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y6 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x7=-0.08f;
    GLfloat y7=0.35f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7, y7); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x7 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y7 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x8=-0.08f;
    GLfloat y8=0.325f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x8, y8); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x8 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y8 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Bush1()
{
   int triangleAmount = 30;
    GLfloat x=0.88f;
    GLfloat y=-0.2f;
    GLfloat radius =.025f;
    glColor3ub(36, 209, 6);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.91f;
    GLfloat y1=-0.19f;
    GLfloat radius1 =.03f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.94f;
    GLfloat y2=-0.19f;
    GLfloat radius3 =.025f;
    glColor3ub(36, 209, 6);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius3 * cos(i *  twicePi / triangleAmount)),
            y2 + (radius3 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.97f;
    GLfloat y3=-0.19f;
    GLfloat radius2 =.035f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius2 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(12, 104, 20);

    glVertex2f(0.96,-0.22);
    glVertex2f(0.92,-0.12);
    glVertex2f(0.94,-0.22);

     glColor3ub(12, 154, 20);

    glVertex2f(0.97,-0.22);
    glVertex2f(0.98,-0.08);
    glVertex2f(0.99,-0.22);
    glEnd();

}

void Bush2()
{
    glLoadIdentity();
    glTranslatef(-1.85f, -0.075f, 0.0f);
    glScalef(1.0f, 1.0f, 0.0f);

    int triangleAmount = 30;
    GLfloat x=0.88f;
    GLfloat y=-0.2f;
    GLfloat radius =.025f;
    glColor3ub(36, 209, 6);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.91f;
    GLfloat y1=-0.19f;
    GLfloat radius1 =.03f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.94f;
    GLfloat y2=-0.19f;
    GLfloat radius3 =.025f;
    glColor3ub(36, 209, 6);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius3 * cos(i *  twicePi / triangleAmount)),
            y2 + (radius3 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.97f;
    GLfloat y3=-0.19f;
    GLfloat radius2 =.035f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius2 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(12, 104, 20);

    glVertex2f(0.96,-0.22);
    glVertex2f(0.92,-0.12);
    glVertex2f(0.94,-0.22);

     glColor3ub(12, 154, 20);

    glVertex2f(0.97,-0.22);
    glVertex2f(0.98,-0.08);
    glVertex2f(0.99,-0.22);
    glEnd();
}

void Bush3()
{
    glLoadIdentity();
    glTranslatef(0.12f, 0.38f, 0.0f);
    glScalef(0.5f, 0.5f, 0.0f);

    int triangleAmount = 30;
    GLfloat x=0.88f;
    GLfloat y=-0.2f;
    GLfloat radius =.025f;
    glColor3ub(36, 209, 6);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.91f;
    GLfloat y1=-0.19f;
    GLfloat radius1 =.03f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.94f;
    GLfloat y2=-0.19f;
    GLfloat radius3 =.025f;
    glColor3ub(36, 209, 6);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius3 * cos(i *  twicePi / triangleAmount)),
            y2 + (radius3 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.97f;
    GLfloat y3=-0.19f;
    GLfloat radius2 =.035f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius2 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(12, 104, 20);

    glVertex2f(0.96,-0.22);
    glVertex2f(0.92,-0.12);
    glVertex2f(0.94,-0.22);

     glColor3ub(12, 154, 20);

    glVertex2f(0.97,-0.22);
    glVertex2f(0.98,-0.08);
    glVertex2f(0.99,-0.22);
    glEnd();
}

void Bush4()
{
    glLoadIdentity();
    glTranslatef(0.26f, -0.05f, 0.0f);
    glScalef(0.5f, 0.5f, 0.0f);

    int triangleAmount = 30;
    GLfloat x=0.88f;
    GLfloat y=-0.2f;
    GLfloat radius =.025f;
    glColor3ub(36, 209, 6);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.91f;
    GLfloat y1=-0.19f;
    GLfloat radius1 =.03f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.94f;
    GLfloat y2=-0.19f;
    GLfloat radius3 =.025f;
    glColor3ub(36, 209, 6);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius3 * cos(i *  twicePi / triangleAmount)),
            y2 + (radius3 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.97f;
    GLfloat y3=-0.19f;
    GLfloat radius2 =.035f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius2 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(12, 104, 20);

    glVertex2f(0.96,-0.22);
    glVertex2f(0.92,-0.12);
    glVertex2f(0.94,-0.22);

     glColor3ub(12, 154, 20);

    glVertex2f(0.97,-0.22);
    glVertex2f(0.98,-0.08);
    glVertex2f(0.99,-0.22);
    glEnd();
}

void Bush5()
{
    glLoadIdentity();
    glTranslatef(0.25f, 0.45f, 0.0f);
    glScalef(0.5f, 0.5f, 0.0f);

    int triangleAmount = 30;
    GLfloat x=0.88f;
    GLfloat y=-0.2f;
    GLfloat radius =.025f;
    glColor3ub(36, 209, 6);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.91f;
    GLfloat y1=-0.19f;
    GLfloat radius1 =.03f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.94f;
    GLfloat y2=-0.19f;
    GLfloat radius3 =.025f;
    glColor3ub(36, 209, 6);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius3 * cos(i *  twicePi / triangleAmount)),
            y2 + (radius3 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.97f;
    GLfloat y3=-0.19f;
    GLfloat radius2 =.035f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius2 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(12, 104, 20);

    glVertex2f(0.96,-0.22);
    glVertex2f(0.92,-0.12);
    glVertex2f(0.94,-0.22);

     glColor3ub(12, 154, 20);

    glVertex2f(0.97,-0.22);
    glVertex2f(0.98,-0.08);
    glVertex2f(0.99,-0.22);
    glEnd();
}

void Bush6()
{
    glLoadIdentity();
    glTranslatef(-1.4f, 0.2f, 0.0f);
    glScalef(0.7f, 0.7f, 0.0f);

    int triangleAmount = 30;
    GLfloat x=0.88f;
    GLfloat y=-0.2f;
    GLfloat radius =.025f;
    glColor3ub(36, 209, 6);

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x1=0.91f;
    GLfloat y1=-0.19f;
    GLfloat radius1 =.03f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x1 + (radius1 * cos(i *  twicePi / triangleAmount)),
            y1 + (radius1 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x2=0.94f;
    GLfloat y2=-0.19f;
    GLfloat radius3 =.025f;
    glColor3ub(36, 209, 6);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x2, y2); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x2 + (radius3 * cos(i *  twicePi / triangleAmount)),
            y2 + (radius3 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat x3=0.97f;
    GLfloat y3=-0.19f;
    GLfloat radius2 =.035f;
    glColor3ub(12, 104, 20);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x3, y3); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x3 + (radius2 * cos(i *  twicePi / triangleAmount)),
            y3 + (radius2 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(12, 104, 20);

    glVertex2f(0.96,-0.22);
    glVertex2f(0.92,-0.12);
    glVertex2f(0.94,-0.22);

     glColor3ub(12, 154, 20);

    glVertex2f(0.97,-0.22);
    glVertex2f(0.98,-0.08);
    glVertex2f(0.99,-0.22);
    glEnd();
}

void Ship1()
{
    ///
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position4,0.0f, 0.0f);

    ///For Ship

      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);

      glVertex2f(0.85f, -0.35f);
      glVertex2f(0.95f, -0.27f);
      glVertex2f(0.4f, -0.27f);
      glVertex2f(0.5f, -0.35f);

      ///For Window
      glColor3ub(0, 0, 0);

      glVertex2f(0.54f, -0.32f);
      glVertex2f(0.54f, -0.30f);
      glVertex2f(0.52f, -0.30f);
      glVertex2f(0.52f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.6f, -0.32f);
      glVertex2f(0.6f, -0.30f);
      glVertex2f(0.58f, -0.30f);
      glVertex2f(0.58f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.66f, -0.32f);
      glVertex2f(0.66f, -0.30f);
      glVertex2f(0.64f, -0.30f);
      glVertex2f(0.64f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.72f, -0.32f);
      glVertex2f(0.72f, -0.30f);
      glVertex2f(0.7f, -0.30f);
      glVertex2f(0.7f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.78f, -0.32f);
      glVertex2f(0.78f, -0.30f);
      glVertex2f(0.76f, -0.30f);
      glVertex2f(0.76f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.84f, -0.32f);
      glVertex2f(0.84f, -0.30f);
      glVertex2f(0.82f, -0.30f);
      glVertex2f(0.82f, -0.32f);

      ///For middle Quad

      glColor3ub(211, 112, 255);

      glVertex2f(0.85f, -0.27f);
      glVertex2f(0.85f, -0.24f);
      glVertex2f(0.5f, -0.24f);
      glVertex2f(0.5f, -0.27f);

      ///For Window

      glColor3ub(0, 0, 0);

      glVertex2f(0.54f, -0.27f);
      glVertex2f(0.54f, -0.24f);
      glVertex2f(0.5f, -0.24f);
      glVertex2f(0.5f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.62f, -0.27f);
      glVertex2f(0.62f, -0.24f);
      glVertex2f(0.58f, -0.24f);
      glVertex2f(0.58f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.7f, -0.27f);
      glVertex2f(0.7f, -0.24f);
      glVertex2f(0.66f, -0.24f);
      glVertex2f(0.66f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.78f, -0.27f);
      glVertex2f(0.78f, -0.24f);
      glVertex2f(0.74f, -0.24f);
      glVertex2f(0.74f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.85f, -0.27f);
      glVertex2f(0.85f, -0.24f);
      glVertex2f(0.81f, -0.24f);
      glVertex2f(0.81f, -0.27f);

      ///For Upper Quad

      glColor3ub(255, 100, 100);

      glVertex2f(0.75f, -0.24f);
      glVertex2f(0.78f, -0.2f);
      glVertex2f(0.6f, -0.2f);
      glVertex2f(0.57f, -0.24f);

      ///Ship Flag

      glColor3ub(0, 0, 0);

      glVertex2f(0.41f, -0.27f);
      glVertex2f(0.41f, -0.13f);
      glVertex2f(0.4f, -0.13f);
      glVertex2f(0.4f, -0.27f);

      glColor3ub(20, 255, 100);

      glVertex2f(0.48f, -0.13f);
      glVertex2f(0.48f, -0.08f);
      glVertex2f(0.4f, -0.08f);
      glVertex2f(0.4f, -0.13f);

    glEnd();

   glPopMatrix();
}

void Ground()
{
    glBegin(GL_QUADS);
    glColor3ub(245, 240, 240);

    glVertex2f(-1.0f, 1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);

    glEnd();
}

void Ship2()
{
    glLoadIdentity();
    glTranslatef(0.4f, -0.45f, 0.0f);
    glScalef(0.5f, 0.5f, 0.0f);

    ///
    glPushMatrix();
    glTranslatef(position5,0.0f, 0.0f);

    ///For Ship

      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);

      glVertex2f(0.85f, -0.35f);
      glVertex2f(0.95f, -0.27f);
      glVertex2f(0.4f, -0.27f);
      glVertex2f(0.5f, -0.35f);

      ///For Window
      glColor3ub(0, 0, 0);

      glVertex2f(0.54f, -0.32f);
      glVertex2f(0.54f, -0.30f);
      glVertex2f(0.52f, -0.30f);
      glVertex2f(0.52f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.6f, -0.32f);
      glVertex2f(0.6f, -0.30f);
      glVertex2f(0.58f, -0.30f);
      glVertex2f(0.58f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.66f, -0.32f);
      glVertex2f(0.66f, -0.30f);
      glVertex2f(0.64f, -0.30f);
      glVertex2f(0.64f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.72f, -0.32f);
      glVertex2f(0.72f, -0.30f);
      glVertex2f(0.7f, -0.30f);
      glVertex2f(0.7f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.78f, -0.32f);
      glVertex2f(0.78f, -0.30f);
      glVertex2f(0.76f, -0.30f);
      glVertex2f(0.76f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.84f, -0.32f);
      glVertex2f(0.84f, -0.30f);
      glVertex2f(0.82f, -0.30f);
      glVertex2f(0.82f, -0.32f);

      ///For middle Quad

      glColor3ub(211, 112, 255);

      glVertex2f(0.85f, -0.27f);
      glVertex2f(0.85f, -0.24f);
      glVertex2f(0.5f, -0.24f);
      glVertex2f(0.5f, -0.27f);

      ///For Window

      glColor3ub(0, 0, 0);

      glVertex2f(0.54f, -0.27f);
      glVertex2f(0.54f, -0.24f);
      glVertex2f(0.5f, -0.24f);
      glVertex2f(0.5f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.62f, -0.27f);
      glVertex2f(0.62f, -0.24f);
      glVertex2f(0.58f, -0.24f);
      glVertex2f(0.58f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.7f, -0.27f);
      glVertex2f(0.7f, -0.24f);
      glVertex2f(0.66f, -0.24f);
      glVertex2f(0.66f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.78f, -0.27f);
      glVertex2f(0.78f, -0.24f);
      glVertex2f(0.74f, -0.24f);
      glVertex2f(0.74f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.85f, -0.27f);
      glVertex2f(0.85f, -0.24f);
      glVertex2f(0.81f, -0.24f);
      glVertex2f(0.81f, -0.27f);

      ///For Upper Quad

      glColor3ub(255, 100, 100);

      glVertex2f(0.75f, -0.24f);
      glVertex2f(0.78f, -0.2f);
      glVertex2f(0.6f, -0.2f);
      glVertex2f(0.57f, -0.24f);

      ///Ship Flag

      glColor3ub(0, 0, 0);

      glVertex2f(0.41f, -0.27f);
      glVertex2f(0.41f, -0.13f);
      glVertex2f(0.4f, -0.13f);
      glVertex2f(0.4f, -0.27f);

      glColor3ub(20, 255, 100);

      glVertex2f(0.48f, -0.13f);
      glVertex2f(0.48f, -0.08f);
      glVertex2f(0.4f, -0.08f);
      glVertex2f(0.4f, -0.13f);

    glEnd();

   glPopMatrix();
}

void Ship3()
{
    glLoadIdentity();
    glTranslatef(-1.1f, -0.60f, 0.0f);
    glScalef(0.7f, 0.7f, 0.0f);

    ///
    glPushMatrix();
    glTranslatef(position6,0.0f, 0.0f);

    ///For Ship

      glBegin(GL_QUADS);
      glColor3ub(255, 255, 255);

      glVertex2f(0.85f, -0.35f);
      glVertex2f(0.95f, -0.27f);
      glVertex2f(0.4f, -0.27f);
      glVertex2f(0.5f, -0.35f);

      ///For Window
      glColor3ub(0, 0, 0);

      glVertex2f(0.54f, -0.32f);
      glVertex2f(0.54f, -0.30f);
      glVertex2f(0.52f, -0.30f);
      glVertex2f(0.52f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.6f, -0.32f);
      glVertex2f(0.6f, -0.30f);
      glVertex2f(0.58f, -0.30f);
      glVertex2f(0.58f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.66f, -0.32f);
      glVertex2f(0.66f, -0.30f);
      glVertex2f(0.64f, -0.30f);
      glVertex2f(0.64f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.72f, -0.32f);
      glVertex2f(0.72f, -0.30f);
      glVertex2f(0.7f, -0.30f);
      glVertex2f(0.7f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.78f, -0.32f);
      glVertex2f(0.78f, -0.30f);
      glVertex2f(0.76f, -0.30f);
      glVertex2f(0.76f, -0.32f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.84f, -0.32f);
      glVertex2f(0.84f, -0.30f);
      glVertex2f(0.82f, -0.30f);
      glVertex2f(0.82f, -0.32f);

      ///For middle Quad

      glColor3ub(211, 112, 255);

      glVertex2f(0.85f, -0.27f);
      glVertex2f(0.85f, -0.24f);
      glVertex2f(0.5f, -0.24f);
      glVertex2f(0.5f, -0.27f);

      ///For Window

      glColor3ub(0, 0, 0);

      glVertex2f(0.54f, -0.27f);
      glVertex2f(0.54f, -0.24f);
      glVertex2f(0.5f, -0.24f);
      glVertex2f(0.5f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.62f, -0.27f);
      glVertex2f(0.62f, -0.24f);
      glVertex2f(0.58f, -0.24f);
      glVertex2f(0.58f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.7f, -0.27f);
      glVertex2f(0.7f, -0.24f);
      glVertex2f(0.66f, -0.24f);
      glVertex2f(0.66f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.78f, -0.27f);
      glVertex2f(0.78f, -0.24f);
      glVertex2f(0.74f, -0.24f);
      glVertex2f(0.74f, -0.27f);

      glColor3ub(0, 0, 0);

      glVertex2f(0.85f, -0.27f);
      glVertex2f(0.85f, -0.24f);
      glVertex2f(0.81f, -0.24f);
      glVertex2f(0.81f, -0.27f);

      ///For Upper Quad

      glColor3ub(255, 100, 100);

      glVertex2f(0.75f, -0.24f);
      glVertex2f(0.78f, -0.2f);
      glVertex2f(0.6f, -0.2f);
      glVertex2f(0.57f, -0.24f);

      ///Ship Flag

      glColor3ub(0, 0, 0);

      glVertex2f(0.93f, -0.27f);
      glVertex2f(0.93f, -0.13f);
      glVertex2f(0.92f, -0.13f);
      glVertex2f(0.92f, -0.27f);

      glColor3ub(20, 255, 100);

      glVertex2f(0.93f, -0.13f);
      glVertex2f(0.93f, -0.08f);
      glVertex2f(0.85f, -0.08f);
      glVertex2f(0.85f, -0.13f);

    glEnd();

   glPopMatrix();
}

void Path()
{
    ///HOME-08
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);

    glVertex2f(-0.40f, 0.23f);
    glVertex2f(-0.38f, 0.23f);
    glVertex2f(-0.385f, 0.40f);
    glVertex2f(-0.39f, 0.40f);

    ///HOME-11
    glVertex2f(-0.59f, 0.23f);
    glVertex2f(-0.61f, 0.23f);
    glVertex2f(-0.685f, 0.43f);
    glVertex2f(-0.69f, 0.43f);

    ///HOME-09
    glVertex2f(-0.25f, 0.23f);
    glVertex2f(-0.23f, 0.23f);
    glVertex2f(-0.15f, 0.41f);
    glVertex2f(-0.155f, 0.41f);

    ///HOME-10
    glVertex2f(0.07f, 0.23f);
    glVertex2f(0.05f, 0.23f);
    glVertex2f(0.26f, 0.46f);
    glVertex2f(0.255f, 0.46f);

    ///HOME-12
    glVertex2f(0.16f, 0.35f);
    glVertex2f(0.17f, 0.36f);
    glVertex2f(0.11f, 0.40f);
    glVertex2f(0.10f, 0.395f);

    ///HOME-13
    glVertex2f(-0.65f, 0.35f);
    glVertex2f(-0.66f, 0.36f);
    glVertex2f(-0.89f, 0.41f);
    glVertex2f(-0.88f, 0.405f);

    glEnd();



}

void Bird1()
{
    glPushMatrix();
    glTranslatef(position1,0.0f,0.0f);
	glColor3f(1.0f,1.0f,0.0f);

	int i10;

	GLfloat x10=0.1f; GLfloat y10=0.65f; GLfloat radius10 =.08f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	int i8;

	GLfloat x8=0.0f; GLfloat y8=0.7f; GLfloat radius8 =.06f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glColor3f(1.0f,0.0f,0.0f);
	int i9;

	GLfloat x9=0.0f; GLfloat y9=0.7f; GLfloat radius9 =.02f;
//	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
//	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount8;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi8 / triangleAmount8)),
			    y9 + (radius9 * sin(i9 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.2f,0.8f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.16f,0.85f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(0.15f,0.65f);
	glVertex2f(0.25f,0.58f);
	glVertex2f(0.15f,0.6f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(-0.05f,0.73f);
	glVertex2f(-0.1f,0.7f);
	glVertex2f(-0.05f,0.67f);
	glEnd();


	glPopMatrix();

}

void Bird2()
{
    glPushMatrix();
    glTranslatef(position7,0.0f,0.0f);
    glTranslatef(0.7f,0.7f,0.0f);
    glScalef(0.2f, 0.2f,0.0f);
	glColor3ub(black,black,black);

	int i10;

	GLfloat x10=0.1f; GLfloat y10=0.65f; GLfloat radius10 =.08f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	int i8;

	GLfloat x8=0.0f; GLfloat y8=0.7f; GLfloat radius8 =.06f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glColor3ub(white,white,white);
	int i9;

	GLfloat x9=0.0f; GLfloat y9=0.7f; GLfloat radius9 =.02f;
//	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
//	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount8;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi8 / triangleAmount8)),
			    y9 + (radius9 * sin(i9 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.2f,0.8f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.16f,0.85f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(black,black,black);
	glVertex2f(0.15f,0.65f);
	glVertex2f(0.25f,0.58f);
	glVertex2f(0.15f,0.6f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(red10, 0, 0);
	glVertex2f(-0.05f,0.73f);
	glVertex2f(-0.1f,0.7f);
	glVertex2f(-0.05f,0.67f);
	glEnd();


	glPopMatrix();

}

void Bird3()
{
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(position7,0.0f,0.0f);
    glTranslatef(0.75f,0.7f,0.0f);
    glScalef(0.2f, 0.2f,0.0f);
	glColor3ub(black,black,black);

	int i10;

	GLfloat x10=0.1f; GLfloat y10=0.65f; GLfloat radius10 =.08f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	int i8;

	GLfloat x8=0.0f; GLfloat y8=0.7f; GLfloat radius8 =.06f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glColor3ub(white,white,white);
	int i9;

	GLfloat x9=0.0f; GLfloat y9=0.7f; GLfloat radius9 =.02f;
//	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
//	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount8;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi8 / triangleAmount8)),
			    y9 + (radius9 * sin(i9 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.2f,0.8f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.16f,0.85f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(black,black,black);
	glVertex2f(0.15f,0.65f);
	glVertex2f(0.25f,0.58f);
	glVertex2f(0.15f,0.6f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(red10, 0, 0);
	glVertex2f(-0.05f,0.73f);
	glVertex2f(-0.1f,0.7f);
	glVertex2f(-0.05f,0.67f);
	glEnd();


	glPopMatrix();
}

void Bird4()
{
    glPushMatrix();
    glTranslatef(position7,0.0f,0.0f);
    glTranslatef(0.8f,0.7f,0.0f);
    glScalef(0.2f, 0.2f,0.0f);
	glColor3ub(black,black,black);

	int i10;

	GLfloat x10=0.1f; GLfloat y10=0.65f; GLfloat radius10 =.08f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	int i8;

	GLfloat x8=0.0f; GLfloat y8=0.7f; GLfloat radius8 =.06f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glColor3ub(white,white,white);
	int i9;

	GLfloat x9=0.0f; GLfloat y9=0.7f; GLfloat radius9 =.02f;
//	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
//	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount8;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi8 / triangleAmount8)),
			    y9 + (radius9 * sin(i9 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.2f,0.8f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.16f,0.85f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(black,black,black);
	glVertex2f(0.15f,0.65f);
	glVertex2f(0.25f,0.58f);
	glVertex2f(0.15f,0.6f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(red10, 0, 0);
	glVertex2f(-0.05f,0.73f);
	glVertex2f(-0.1f,0.7f);
	glVertex2f(-0.05f,0.67f);
	glEnd();


	glPopMatrix();
}

void Bird5()
{
    glPushMatrix();
    glTranslatef(position7,0.0f,0.0f);
    glTranslatef(0.73f,0.75f,0.0f);
    glScalef(0.2f, 0.2f,0.0f);
	glColor3ub(black,black,black);

	int i10;

	GLfloat x10=0.1f; GLfloat y10=0.65f; GLfloat radius10 =.08f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	int i8;

	GLfloat x8=0.0f; GLfloat y8=0.7f; GLfloat radius8 =.06f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glColor3ub(white,white,white);
	int i9;

	GLfloat x9=0.0f; GLfloat y9=0.7f; GLfloat radius9 =.02f;
//	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
//	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount8;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi8 / triangleAmount8)),
			    y9 + (radius9 * sin(i9 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.2f,0.8f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.16f,0.85f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(black,black,black);
	glVertex2f(0.15f,0.65f);
	glVertex2f(0.25f,0.58f);
	glVertex2f(0.15f,0.6f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(red10, 0, 0);
	glVertex2f(-0.05f,0.73f);
	glVertex2f(-0.1f,0.7f);
	glVertex2f(-0.05f,0.67f);
	glEnd();


	glPopMatrix();
}

void Bird6()
{
    glPushMatrix();
    glTranslatef(position7,0.0f,0.0f);
    glTranslatef(0.78f,0.75f,0.0f);
    glScalef(0.2f, 0.2f,0.0f);
	glColor3ub(black,black,black);

	int i10;

	GLfloat x10=0.1f; GLfloat y10=0.65f; GLfloat radius10 =.08f;
	int triangleAmount10 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi10 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10); // center of circle
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f(
		            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
			    y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
			);
		}
	glEnd();


	int i8;

	GLfloat x8=0.0f; GLfloat y8=0.7f; GLfloat radius8 =.06f;
	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8); // center of circle
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f(
		            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
			    y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

	glColor3ub(white,white,white);
	int i9;

	GLfloat x9=0.0f; GLfloat y9=0.7f; GLfloat radius9 =.02f;
//	int triangleAmount8 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
//	GLfloat twicePi8 = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9); // center of circle
		for(i9 = 0; i9 <= triangleAmount8;i9++) {
			glVertex2f(
		            x9 + (radius9 * cos(i9 *  twicePi8 / triangleAmount8)),
			    y9 + (radius9 * sin(i9 * twicePi8 / triangleAmount8))
			);
		}
	glEnd();

    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.2f,0.8f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(white,white,white);
	glVertex2f(0.08f,0.6f);
	glVertex2f(0.16f,0.85f);
	glVertex2f(0.08f,0.68f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(black,black,black);
	glVertex2f(0.15f,0.65f);
	glVertex2f(0.25f,0.58f);
	glVertex2f(0.15f,0.6f);
	glEnd();
    glBegin(GL_TRIANGLES);
	glColor3ub(red10, 0, 0);
	glVertex2f(-0.05f,0.73f);
	glVertex2f(-0.1f,0.7f);
	glVertex2f(-0.05f,0.67f);
	glEnd();


	glPopMatrix();
}

void Boat1()
{
      glPushMatrix();
      glTranslatef(position2,0.0f, 0.0f);

      glColor3ub(0, 0, 0);

      glBegin(GL_TRIANGLES);
      glVertex2f(-0.75f, -0.9f);
      glVertex2f(-0.75f, -0.82f);
      glVertex2f(-0.95f, -0.8f);

      glVertex2f(-0.55f, -0.8f);
      glVertex2f(-0.75f, -0.82f);
      glVertex2f(-0.75f, -0.9f);

      ///1ST PAL
      glColor3ub(100, 100, 100);

      glVertex2f(-0.9f, -0.81f);
      glVertex2f(-0.8f, -0.82f);
      glVertex2f(-0.78f, -0.6f);

      ///2ND PAL
      glColor3ub(255, 255, 255);

      glVertex2f(-0.78f, -0.6f);
      glVertex2f(-0.66f, -0.82f);
      glVertex2f(-0.75f, -0.54f);

      glVertex2f(-0.78f, -0.6f);
      glVertex2f(-0.8f, -0.82f);
      glVertex2f(-0.66f, -0.82f);

      ///3RD PAL
      glColor3ub(100, 100, 100);

      glVertex2f(-0.732f, -0.6f);
      glVertex2f(-0.66f, -0.82f);
      glVertex2f(-0.6f, -0.81f);

      glEnd();

      glPopMatrix();
}

void Boat2()
{
      glPushMatrix();
      //glTranslatef(position2,0.0f, 0.0f);
      glTranslatef(1.2f,0.07f,0.0f);
      glScalef(0.5f, 0.5f,0.0f);
      glColor3ub(0, 0, 0);

      glBegin(GL_TRIANGLES);
      glVertex2f(-0.75f, -0.9f);
      glVertex2f(-0.75f, -0.82f);
      glVertex2f(-0.95f, -0.8f);

      glVertex2f(-0.55f, -0.8f);
      glVertex2f(-0.75f, -0.82f);
      glVertex2f(-0.75f, -0.9f);

      ///1ST PAL
      glColor3ub(100, 100, 100);

      glVertex2f(-0.9f, -0.81f);
      glVertex2f(-0.8f, -0.82f);
      glVertex2f(-0.78f, -0.6f);

      ///2ND PAL
      glColor3ub(255, 255, 255);

      glVertex2f(-0.78f, -0.6f);
      glVertex2f(-0.66f, -0.82f);
      glVertex2f(-0.75f, -0.54f);

      glVertex2f(-0.78f, -0.6f);
      glVertex2f(-0.8f, -0.82f);
      glVertex2f(-0.66f, -0.82f);

      ///3RD PAL
      glColor3ub(100, 100, 100);

      glVertex2f(-0.732f, -0.6f);
      glVertex2f(-0.66f, -0.82f);
      glVertex2f(-0.6f, -0.81f);

      glEnd();

      glPopMatrix();
}

void display()
{
    glClearColor(0.93f, 0.88f, 0.88f, 0.0f); /// Set background color to Off White
	glClear(GL_COLOR_BUFFER_BIT);         /// Clear the color buffer (background)
	glLineWidth(.8);
	//PlaySound(TEXT("Bird.wav"),NULL,SND_ASYNC);

	Ship1();
	Ground();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	if(day==0)
    {
        //glPushMatrix();
        glColor3f(0.0, 0.02, 0.07);
		glBegin(GL_POLYGON);
            glVertex2f(-1.0f, 0.50f);
            glColor3f(0.0, 0.02, 0.20);
            glVertex2f(1.0f, 0.50f);
            glColor3f(0.35, 0.35, 0.35);
            glVertex2f(1.0f, 1.0f);
            glColor3f(0, 0, 0);
            glVertex2f(-1.0f,1.0f);
		glEnd();
        //glPopMatrix();

///*********************************************MOON********************************************************///
        //glPushMatrix();
        moon();
        //star();
        //glPopMatrix();
    }

    else
    {
	Sky();
	Sun();
    }

    glLoadIdentity();
	Cloud();
	Mountain();
	Water();
	glLoadIdentity();
	Ship2();
	Ship3();
	glLoadIdentity();
	Stone();
	Road();
    grassRightSide();
    Stair();
    grassLeftSide();
    grassMiddle();
    BridgeLeftSide();
    BridgeFrontSide();

    //Axis();
    Home_1();
    Home_3();
    Home_4();
    Home_5();
    Home_6();
    Home_7();
    Home_8();
    Home_9();
    Home_10();
    Home_11();
    Home_12();
    Home_13();
    glLoadIdentity();
    Tree1();
    Tree2();
    Tree3();
    Tree4();
    Tree5();
    glLoadIdentity();
    Tree6();
    Tree7();
    Tree8();
    Tree9();
    Tree10();
    Tree11();
    glLoadIdentity();
    Bush1();
    glLoadIdentity();
    Bush2();
    glLoadIdentity();
    Bush3();
    glLoadIdentity();
    Bush4();
    glLoadIdentity();
    Bush5();
    glLoadIdentity();
    Bush6();
    glLoadIdentity();
    Path();
    Boat2();
    Bird2();
    Bird3();
    Bird4();
    Bird5();
    Bird6();


    ///**************************************************RAIN*******************************************///
    if(rainy==1)
    {
        red1=red2=red3=.7;
        green1=green2=green3=.7;
        blue1=blue2=blue3=.7;

        glPushMatrix();
        glTranslatef(0.0f,position1, 0.0f);
        Rain();
        glPopMatrix();

    }

    if(rainy==0)
    {
        /*red1=0.980392;
        green1=0.980392;
        blue1=0.823529;*/

        red1=green1=blue1=0.8;

        red2=0.52734375;
        green2=0.8046878;
        blue2=0.99765625;

        //red2=green2=blue2=0.8;

        red3=0.498039;
        green3= 1;
        blue3= 0.831373;

        //red3=green3=blue3=0.8;
    }


    if(starenable==1 && day==0 && rainy==0)
    {
        glPushMatrix();
        star();
        glPopMatrix();
    }

    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);          /// Initialize GLUT
    glutInitWindowSize(1530, 790);
    glutCreateWindow("Natural Beauty");
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutDisplayFunc(display);//
    glutKeyboardFunc(keyboard);
    glutTimerFunc(100, update, 0);
    //sndPlaySound("Night.wav",SND_ASYNC);
    //initGL();
    //glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.
    glutMainLoop();
    return 0;
}
