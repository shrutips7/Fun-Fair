#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#include<stdio.h>
#include <string.h>
#define TEXTID      3
static GLfloat spin = 0.0, dist1= 19.0, dist2=-75.0;
GLint red=0,white=1,k,j=1,n1,n2;
static GLfloat wheel[8][2]= {{200,100},{400,100},{500,200},{500,400},{400,500},{200,500},{100,400},{100,200}};
static GLfloat colors[2][3]= {{1.0,0.0,0.0},{1.0,1.0,1.0}};
static GLint i,d=0,g=0,e=0,up=1,down=1,top=1,z=0;
int n;

void fillCircle(float x1, float y1, double radius)
{
    float x2,y2;
    float angle;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1,y1);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex2f(x2,y2);
    }

    glEnd();
}

typedef struct
{
    float x;
    float y;
} CIRCLE;

CIRCLE circle;

void createcircle (int h, int k, int r)
{
    glBegin(GL_LINES);
    for (i = 0; i < 180; i++)
    {
        circle.x = r * cos(i) - h;
        circle.y = r * sin(i) + k;
        glVertex3f(circle.x + k,circle.y - h,0);

        circle.x = r * cos(i + 0.1) - h;
        circle.y = r * sin(i + 0.1) + k;
        glVertex3f(circle.x + k,circle.y - h,0);
    }
    glEnd();
}

void declare(char *string)
{
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}


void declare2(char *string)
{
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void cover()
{
    glColor3f(0.0,1.0,1.0);
    glRasterPos2f(-475,710);
    declare2("   GRAPHICAL IMPLEMENTATION OF  ");

    glRasterPos2f(-370,650);
    declare2("                    FUN FAIR");

    glColor3f(0.7,0.6,0.1);
    glRasterPos2f(-725,400);
    declare2("     Submitted by :- ");

    glColor3f(1.0,0.5,0.0);
    glRasterPos2f(-650,300);
    declare2("     UMME HANI H ");
    glRasterPos2f(300,300);
    declare2("        SHRUTI PS ");
    glColor3f(0.7,0.8,0.6);
    glRasterPos2f(-650,200);
    declare2("     (1HK12CS108) ");
    glRasterPos2f(300,200);
    declare2("        (1HK12CS093) ");

    glColor3f(0.7,0.6,0.1);
    glRasterPos2f(-425,-250);
    declare2("     Under the guidance of : ");
    glColor3f(1.0,0.5,0.0);
    glRasterPos2f(-425,-320);
    declare2("     Ms. SHAZIA SIDDIQUE  ");
    glColor3f(1.0,0.8,0.4);
    glRasterPos2f(-425,-380);
    declare2("      Asst. Professor, Dept. of CSE ");
    glRasterPos2f(-425,-440);
    declare2("      HKBK COLLEGE OF ENGINEERING");
}

void background()
{
    //grass
    glColor3f(0.0,0.8,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2000,-50);  //-2,-50
    glVertex2f(-2000,-2000);
    glVertex2f(2000,-2000);
    glVertex2f(2000,-50);
    glEnd();

    // sky
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-2000,-50);
    glVertex2f(2000,-50);
    glVertex2f(2000,2000);
    glVertex2f(-2000,2000);
    glEnd();
}

void hot_air_balloon()
{
    //balloon
    glColor3f(0.63,0.16,0.86);
    glPushMatrix();
    glTranslated(900,-120+g,0);
    fillCircle(0,0,150);
    glBegin(GL_POLYGON);
    glVertex2f(-99,-113);
    glVertex2f(99,-113);
    glVertex2f(37,-188);
    glVertex2f(-37,-188);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-37,-188);
    glVertex2f(-37,-225);
    glVertex2f(-18,-225);
    glVertex2f(-18,-188);
    glVertex2f(0,-188);
    glVertex2f(0,-225);
    glVertex2f(18,-188);
    glVertex2f(18,-225);
    glVertex2f(37,-225);
    glVertex2f(37,-188);
    glEnd();
    glColor3f(1.0,1.0,0.0);
    fillCircle(0,0,25);
    fillCircle(75,40,25);
    fillCircle(75,-40,25);
    fillCircle(120,0,20);
    fillCircle(0,90,25);
    fillCircle(-95,40,25);
    fillCircle(-105,-40,25);
    fillCircle(0,-90,25);
    fillCircle(-65,90,20);
    fillCircle(40,-140,18);
    fillCircle(-20,-155,15);

    glPushMatrix();
    glTranslated(-37,-235,0);
    //Person
    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(15,0);
    glVertex2f(15,15);
    glVertex2f(20,20);
    glVertex2f(40,20);
    glVertex2f(45,10);
    glVertex2f(45,0);
    glEnd();
    //head
    glColor3f(0.847059,0.847059,0.74902);
    fillCircle(30,30,12);
    glColor3f(0.0,0.0,0.0);
    fillCircle(25,35,3);
    fillCircle(35,35,3);
    glPopMatrix();

    //basket
    glColor3f(0.52,0.37,0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-37,-225);
    glVertex2f(37,-225);
    glVertex2f(37,-290);
    glVertex2f(-37,-290);
    glEnd();

    glPopMatrix();

    glColor3f(0.0,0.0,1.0);
    glRasterPos2f(710,770);
    declare("HOT AIR BALLOON");


}

void tower()
{
    glColor3f(0.0,0.0,1.0);
    glRasterPos2f(-1080,700);
    declare("TOWER");

    glPushMatrix();
    glTranslated(-950,-300,0);
    //Blue parts of Tower
    glColor3f(0.00,0.00,0.61);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(-150,0);
    glVertex2f(-150,600);
    glVertex2f(0,600);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0,650);
    glVertex2f(-150,650);
    glVertex2f(-150,750);
    glVertex2f(0,750);
    glEnd();

    glColor3f(0.958824,0.439216,0.676471);
    glBegin(GL_POLYGON);
    glVertex2f(10,600);
    glVertex2f(-160,600);
    glVertex2f(-160,650);
    glVertex2f(10,650);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(10,0);
    glVertex2f(-160,0);
    glVertex2f(-160,-100);
    glVertex2f(10,-100);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-160,750);
    glVertex2f(-75,900);
    glVertex2f(10,750);
    glEnd();

    //flag
    glPushMatrix();
    glTranslated(-75,900,0);
    glColor3f(0.00,0.00,0.61);
    glBegin(GL_POLYGON);
    glVertex2f(3,0);
    glVertex2f(-3,0);
    glVertex2f(-3,60);
    glVertex2f(3,60);
    glEnd();
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(3,60);
    glVertex2f(50,50);
    glVertex2f(3,20);
    glEnd();
    glPopMatrix();
    glPopMatrix();


    //top door
    glPushMatrix();
    glTranslated(-950,-300,0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-100,650);
    glVertex2f(-50,650);
    glVertex2f(-50,680);
    glVertex2f(-100,680);
    glEnd();
    fillCircle(-75,680,25);

    glPushMatrix();
    glTranslated(-100,650,0);
    //Person
    //body
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(15,0);
    glVertex2f(15,15);
    glVertex2f(20,20);
    glVertex2f(40,20);
    glVertex2f(45,10);
    glVertex2f(45,0);
    glEnd();
    //head
    glColor3f(0.847059,0.847059,0.74902);
    fillCircle(30,30,12);
    glColor3f(0.0,0.0,0.0);
    fillCircle(25,35,3);
    fillCircle(35,35,3);
    glPopMatrix();



    //other doors
    for(i=1; i<6; i++)
    {
        if(e==i)
            glColor3f(1.0,1.0,0.0);
        else
            glColor3f(0.87,0.58,0.98);
        glBegin(GL_POLYGON);
        glVertex2f(-100,-70+i*120);
        glVertex2f(-50,-70+i*120);
        glVertex2f(-50,-20+i*120);
        glVertex2f(-100,-20+i*120);
        glEnd();
    }
    glPopMatrix();


}
void ferris_wheel()
{
    glColor3f(0.0,0.0,1.0);
    glRasterPos2f(170,600);
    declare("FERRIS WHEEL");

    //base of ferris wheel
    glColor3f(1.0,0.0,0.8);
    glBegin(GL_POLYGON);
    glVertex2f(300,300);
    glVertex2f(400,-100);
    glVertex2f(450,-100);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(300,300);
    glVertex2f(150,-100);
    glVertex2f(200,-100);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(150,-100);
    glVertex2f(450,-100);
    glVertex2f(450,-120);
    glVertex2f(150,-120);
    glEnd();


    glPushMatrix();
    glTranslatef(300, 300, 0);
    glRotatef(spin,0,0,1);
    glTranslatef(-300, -300, 0);

    //the wheel of the ferris wheel
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glLineWidth(8.0);
    for(i=0; i<8; i++)
        glVertex2fv(wheel[i]);
    glEnd();


    //the spokes
    for(i=0; i<8; i++)
    {
        glBegin(GL_LINES);
        glVertex2f(300,300);
        glVertex2fv(wheel[i]);
        glEnd();
    }

    glPushMatrix();
    glColor3f(1.0,0.0,0.5);
    glTranslatef(300, 300, 0);
    createcircle(0,0,50);
    createcircle(0,0,160);
    glColor3f(0.0,0.0,1.0);
    createcircle(0,0,100);
    glPopMatrix();

    //cabs  of ferris wheel
    for(i=0; i<8; i++)
    {
        glPushMatrix();
        glColor3f(1.0,1.0,0.0);
        glTranslatef(wheel[i][0],wheel[i][1],0);
        glRectf(-15,-15,15,15);
        glPopMatrix();
    }

    glPopMatrix();



}

void merry_go_round()
{
    //poles
    for(i=0; i<5; i++)
    {
        glPushMatrix();
        glTranslated(-700+i*100,100,0);
        glColor3f(1.0,1.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(-5,0);
        glVertex2f(5,0);
        glVertex2f(5,-220);
        glVertex2f(-5,-220);
        glEnd();
        glPopMatrix();
    }
    //top blue horses
    for(i=0; i<5; i+=2)
    {
        glPushMatrix();
        glTranslated(-700+i*100,dist1,0.0);
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_POLYGON);
        glVertex2f(-35,25);
        glVertex2f(10,15);
        glVertex2f(30,50);
        glVertex2f(50,30);
        glVertex2f(40,20);
        glVertex2f(25,25);
        glVertex2f(10,5);
        glVertex2f(20,-20);
        glVertex2f(5,-20);
        glVertex2f(-5,0);
        glVertex2f(-20,0);
        glVertex2f(-30,-20);
        glVertex2f(-45,-20);
        glVertex2f(-35,0);
        glEnd();
        glColor3f(0.90,0.16,1.0 );
        glBegin(GL_POLYGON);
        glVertex2f(-35,10);
        glVertex2f(-45,35);
        glVertex2f(-35,30);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(20,60);
        glVertex2f(30,50);
        glVertex2f(5,25);
        glVertex2f(0,40);
        glEnd();

        glColor3f(1.0,1.0,0.0);
        fillCircle(30,35,4);

        glPopMatrix();
    }

    //down brown horses
    for(i=1; i<5; i+=2)
    {
        glPushMatrix();
        glTranslated(-700+i*100,dist2,0);
        glColor3f(0.36,0.25,0.20);
        glBegin(GL_POLYGON);
        glVertex2f(-35,25);
        glVertex2f(10,15);
        glVertex2f(30,50);
        glVertex2f(50,30);
        glVertex2f(40,20);
        glVertex2f(25,25);
        glVertex2f(10,5);
        glVertex2f(20,-20);
        glVertex2f(5,-20);
        glVertex2f(-5,0);
        glVertex2f(-20,0);
        glVertex2f(-30,-20);
        glVertex2f(-45,-20);
        glVertex2f(-35,0);
        glEnd();
        glColor3f(1.0,0.43,0.78);
        glBegin(GL_POLYGON);
        glVertex2f(-35,10);
        glVertex2f(-45,35);
        glVertex2f(-35,30);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(20,60);
        glVertex2f(30,50);
        glVertex2f(5,25);
        glVertex2f(0,40);
        glEnd();

        glColor3f(1.0,1.0,1.0);
        fillCircle(30,35,4);

        glPopMatrix();
    }


    //flag
    glPushMatrix();
    glTranslated(-500,200,0);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(3,0);
    glVertex2f(-3,0);
    glVertex2f(-3,50);
    glVertex2f(3,50);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(3,50);
    glVertex2f(40,40);
    glVertex2f(3,30);
    glEnd();
    glPopMatrix();

    //top cone
    glColor3fv(colors[red]);
    glBegin(GL_POLYGON);
    glVertex2d(-500,200);
    glVertex2d(-750,100);
    glVertex2d(-650,90);
    glEnd();

    glColor3fv(colors[white]);
    glBegin(GL_POLYGON);
    glVertex2d(-500,200);
    glVertex2d(-650,90);
    glVertex2d(-550,80);
    glEnd();

    glColor3fv(colors[red]);
    glBegin(GL_POLYGON);
    glVertex2d(-500,200);
    glVertex2d(-550,80);
    glVertex2d(-450,80);
    glEnd();

    glColor3fv(colors[white]);
    glBegin(GL_POLYGON);
    glVertex2d(-500,200);
    glVertex2d(-450,80);
    glVertex2d(-350,90);
    glEnd();

    glColor3fv(colors[red]);
    glBegin(GL_POLYGON);
    glVertex2d(-500,200);
    glVertex2d(-350,90);
    glVertex2d(-250,100);
    glEnd();

    //base
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUAD_STRIP);
    glVertex2d(-750,-100);
    glVertex2d(-750,-150);
    glVertex2d(-650,-110);
    glVertex2d(-650,-160);
    glVertex2d(-550,-120);
    glVertex2d(-550,-170);
    glVertex2d(-450,-120);
    glVertex2d(-450,-170);
    glVertex2d(-350,-110);
    glVertex2d(-350,-160);
    glVertex2d(-250,-100);
    glVertex2d(-250,-150);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glRasterPos2f(-660,400);
    declare("MERRY-GO-ROUND");


}

void train()
{
    glColor3f(0.0,0.0,1.0);
    glRasterPos2f(0,-750);
    declare("TRAIN RIDE");


    //train track
    for(k=0; k<100; k++)
    {
        glPushMatrix();
        glTranslated(-2010+k*40,-710,0);
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(0,0);
        glVertex2f(30,40);
        glVertex2f(80,40);
        glVertex2f(50,0);
        glEnd();
        glPopMatrix();
    }

    for(k=0; k<5; k++)
    {
        //train boggy
        glPushMatrix();
        glTranslated(-2390+k*245+d*90,-660,0);
        glColor3f(1.0,0.5,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(0,100);
        glVertex2f(200,100);
        glVertex2f(200,0);
        glEnd();

        //joint
        glColor3f(0.372549,0.623529,0.623529);
        glBegin(GL_POLYGON);
        glVertex2f(200,10);
        glVertex2f(200,30);
        glVertex2f(250,30);
        glVertex2f(250,10);
        glEnd();

        //train window 1
        glColor3f(1.00,1.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(25,40);
        glVertex2f(25,85);
        glVertex2f(90,85);
        glVertex2f(90,40);
        glEnd();

        glPushMatrix();
        glTranslated(25,85,0);
        //Person
        //body
        glColor3f(0.35,0.35,0.87);
        glBegin(GL_POLYGON);
        glVertex2f(15,0);
        glVertex2f(15,10);
        glVertex2f(20,20);
        glVertex2f(40,20);
        glVertex2f(45,10);
        glVertex2f(45,0);
        glEnd();
        //head
        glColor3f(0.847059,0.847059,0.74902);
        fillCircle(30,30,12);
        glColor3f(0.0,0.0,0.0);
        fillCircle(25,35,3);
        fillCircle(35,35,3);
        glPopMatrix();


        //train window 2
        glColor3f(1.00,1.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(110,85);
        glVertex2f(175,85);
        glVertex2f(175,40);
        glVertex2f(110,40);
        glEnd();

        glPushMatrix();
        glTranslated(110,85,0);
        //person
        //body
        glColor3f(0.35,0.35,0.87);
        glBegin(GL_POLYGON);
        glVertex2f(15,0);
        glVertex2f(15,10);
        glVertex2f(20,20);
        glVertex2f(40,20);
        glVertex2f(45,10);
        glVertex2f(45,0);
        glEnd();
        //head
        glColor3f(0.847059,0.847059,0.74902);
        fillCircle(30,30,12);
        glColor3f(0.0,0.0,0.0);
        fillCircle(25,35,3);
        fillCircle(35,35,3);
        glPopMatrix();

        glPopMatrix();

        //wheels
        glColor3f(0.0,0.0,0.0);
        glPushMatrix();
        glTranslated(-2360+k*245+d*90,-670,0);
        fillCircle(0,0,20);
        glPopMatrix();
        glPushMatrix();
        glTranslated(-2220+k*245+d*90,-670,0);
        fillCircle(0,0,20);
        glPopMatrix();
    }
    //Engine
    glPushMatrix();
    glTranslated(-1180+d*90,-660,0);//140
    glColor3f(1.0,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,150);
    glVertex2f(100,150);
    glVertex2f(100,100);
    glVertex2f(200,100);
    glVertex2f(200,0);
    glEnd();
    fillCircle(200,50,50);

    //Smoke from chimney
    glPushMatrix();
    glTranslated(130,130,0);
    glColor3f(0.658824,0.658824,0.758824);
    for(i=0; i<20; i++)
        fillCircle(-5+1*i,0,10);
    for(i=0; i<8; i++)
        fillCircle(5*i,10,10);
    for(i=0; i<10; i++)
        fillCircle(2*i,20,10);
    for(i=0; i<18; i++)
        fillCircle(1*i,30,10);
    for(i=0; i<9; i++)
        fillCircle(-1+1*i,40,10);
    fillCircle(-2,50,15);
    fillCircle(-3,60,10);
    fillCircle(-20,60,12);

    glPopMatrix();

    //Engine Chimney
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(140,100);
    glVertex2f(130,130);
    glVertex2f(170,130);
    glVertex2f(160,100);
    glEnd();

    //Engine Window
    glColor3f(1.00,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(20,80);
    glVertex2f(20,130);
    glVertex2f(80,130);
    glVertex2f(80,80);
    glEnd();

    //Engine Driver
    //body
    glColor3f(0.8,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(35,80);
    glVertex2f(35,90);
    glVertex2f(40,100);
    glVertex2f(60,100);
    glVertex2f(65,90);
    glVertex2f(65,80);
    glEnd();
    //head
    glColor3f(0.847059,0.847059,0.74902);
    fillCircle(50,110,12);
    glColor3f(0.0,0.0,0.0);
    fillCircle(45,115,3);
    fillCircle(55,115,3);
    glPopMatrix();

    //Engine wheels
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslated(-1130+d*90,-655,0);
    fillCircle(0,0,35);
    glPopMatrix();
    glPushMatrix();
    glTranslated(-1020+d*90,-660,0);
    fillCircle(0,0,30);
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(z<50)
    {
        for(z=0; z<=50; z++)
        {
            cover();
            glutPostRedisplay();
            glutSwapBuffers();
            glFlush();
        }
    }
    else
    {

        background();
        ferris_wheel();
        merry_go_round();
        //balloons();
        train();
        hot_air_balloon();
        tower();

        glutSwapBuffers();
    }
}

void spinDisplay(void)
{
    //Hot Air Balloon moving
    if(g<680) g+=60;

    //tower elevator working
    if(e<6 && up==1)
    {
        e++;
        up=1;
    }
    else if(e>0)
    {
        up=0;
        e--;
    }
    else
        up=1;

    //rotation of ferris wheel
    spin = spin +20.0;
    if (spin > 360.0)
        spin = spin - 360.0;

    //merry_go_round horse movement
    //dist1=20 ; dist2=-70
    if(down==1)
    {
        dist1=dist1-20.0;
        if(dist1< -75)
            down=0;
    }
    if(down==0)
    {
        dist1=dist1+20.0;
        if(dist1> 19)
            down=1;
    }

    if(top==1)
    {
        dist2=dist2+20.0;
        if(dist2> 19)
            top=0;
    }
    if(top==0)
    {
        dist2=dist2-20.0;
        if(dist2< -75)
            top=1;
    }


    //merry_go_round cone rotation
    j+=1;
    if(j%3==0)
    {
        red=0;
        white=1;
    }
    else
    {
        red=1;
        white=0;
    }

    //train moving
    d++;
    if(d>38) d=0;
    glutPostRedisplay();
}


void myReshape(int w, int h)
{

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
        glOrtho(-800.0, 800.0, -800.0 * (GLfloat) h / (GLfloat) w, 800.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-800.0 * (GLfloat) w / (GLfloat) h, 800.0 * (GLfloat) w / (GLfloat) h, -800.0, 800.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
        break;
    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1024,768);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Fun Fair");
    glutFullScreen();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
