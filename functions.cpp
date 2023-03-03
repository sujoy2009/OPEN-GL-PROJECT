#include "header.h"
#include <math.h>

void rect()
{
    glBegin(GL_QUADS);

    //front

    glVertex3f(-1.0,1.0,0.4);
    glVertex3f(-1.0,-1.0,0.4);
    glVertex3f(1.0,-1.0,0.4);
    glVertex3f(1.0,1.0,0.4);
    //back

    glVertex3f(-1.0,1.0,-0.4);
    glVertex3f(1.0,1.0,-0.4);
    glVertex3f(1.0,-1.0,-0.4);
    glVertex3f(-1.0,-1.0,-0.4);
    //left

    glVertex3f(-1.0,1.0,0.4);
    glVertex3f(-1.0,-1.0,0.4);
    glVertex3f(-1.0,-1.0,-0.4);
    glVertex3f(-1.0,1.0,-0.4);
    //top

    glVertex3f(-1.0,1.0,0.4);
    glVertex3f(1.0,1.0,0.4);
    glVertex3f(1.0,1.0,-0.4);
    glVertex3f(-1.0,1.0,-0.4);
    //right

    glVertex3f(1.0,1.0,0.4);
    glVertex3f(1.0,-1.0,0.4);
    glVertex3f(1.0,-1.0,-0.4);
    glVertex3f(1.0,1.0,-0.4);
    //bottom

    glVertex3f(-1.0,-1.0,0.4);
    glVertex3f(-1.0,-1.0,-0.4);
    glVertex3f(1.0,-1.0,-0.4);
    glVertex3f(1.0,-1.0,0.4);

    glEnd();
}
void trian()
{
    glBegin(GL_QUADS);
    //front

    glVertex3f(-1.0,1.0,0.4);
    glVertex3f(-1.2,-1.0,0.4);
    glVertex3f(1.2,-1.0,0.4);
    glVertex3f(1.0,1.0,0.4);
    //back

    glVertex3f(-1.0,1.0,-0.4);
    glVertex3f(1.0,1.0,-0.4);
    glVertex3f(1.2,-1.0,-0.4);
    glVertex3f(-1.2,-1.0,-0.4);
    //left

    glVertex3f(-1.0,1.0,0.4);
    glVertex3f(-1.2,-1.0,0.4);
    glVertex3f(-1.2,-1.0,-0.4);
    glVertex3f(-1.0,1.0,-0.4);
    //top
    glVertex3f(-1.0,1.0,0.4);
    glVertex3f(1.0,1.0,0.4);
    glVertex3f(1.0,1.0,-0.4);
    glVertex3f(-1.0,1.0,-0.4);
    //right
    glVertex3f(1.0,1.0,0.4);
    glVertex3f(1.2,-1.0,0.4);
    glVertex3f(1.2,-1.0,-0.4);
    glVertex3f(1.0,1.0,-0.4);
    //bottom
    glVertex3f(-1.2,-1.0,0.4);
    glVertex3f(-1.2,-1.0,-0.4);
    glVertex3f(1.2,-1.0,-0.4);
    glVertex3f(1.2,-1.0,0.4);


    glEnd();
}



void draw_cylinder(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R,G,B);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 2*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();

    /** Draw the circle on bottom of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while( angle < 2*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, 0.0);
    glEnd();
}

void draw_finger(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R,G,B);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while( angle < 1.6*PI )
    {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glEnd();
}
