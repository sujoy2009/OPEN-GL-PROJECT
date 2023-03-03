#include "header.h"


void wall()
{

    glPushMatrix();
    //bottom
    glColor3f(0.3,0.3,0.3);
    glTranslatef(0,-2.0,0.0);
    glScalef(4.0, .1, 8.0);
    if(texture==1)
    {
        glBindTexture(GL_TEXTURE_2D,2);
        glEnable(GL_TEXTURE_2D);
    }
    rect();
    if(texture==1)
        glDisable(GL_TEXTURE_2D);


    //left
    glColor3f(0.4,0.4,0.4);
    glScalef(1/4.0, 1/0.1, 1/8.0);
    glScalef(4.0, 3.0, 0.1);
    glTranslatef(-0,1.02,0.0);
    if(texture==1)
    {
        glBindTexture(GL_TEXTURE_2D,3);
        glEnable(GL_TEXTURE_2D);
    }
    glRotatef(90, 0, 1, 0);
    glScalef(32.0, 1.0, 0.1);
    glTranslatef(0,0,-9.65);
    rect();
    //right
    if(texture==1)
    {
        glBindTexture(GL_TEXTURE_2D,3);
        glEnable(GL_TEXTURE_2D);
    }
    glTranslatef(0,0,19.3);
    rect();
    glTranslatef(0,0,-9.65);
    glScalef(1/32.0, 1/1.0, 1/0.1);
    glRotatef(-90, 0, 1, 0);
    glScalef(1/4.0, 1/3.0, 1/0.1);

    /// wall picture
    glRotatef(90, 0, 1, 0);
    glScalef(1, 1, 0.1);
    glTranslatef(0, 1, 37);
    if(texture==1)
    {
        glBindTexture(GL_TEXTURE_2D,7);
        glEnable(GL_TEXTURE_2D);
    }
    glutSolidCube(2);
    if(texture==1)
        glDisable(GL_TEXTURE_2D);

    /// spiral picture
    glTranslatef(0, -1, 2);
    glScalef(1, 1, 0.7);
////    if(texture==1)
////    {
////        glBindTexture(GL_TEXTURE_2D,7);
////        glEnable(GL_TEXTURE_2D);
////    }
//    glutSolidCube(5);
    glScalef(1, 1, 1/0.7);
    glTranslatef(0, 0, -37);
    glScalef(1, 1, 1/0.1);
    glRotatef(-90, 0, 1, 0);


    //back
    if(texture==1)
    {
        glBindTexture(GL_TEXTURE_2D,3);
        glEnable(GL_TEXTURE_2D);
    }
    glTranslatef(-4.0,0,0);
    glColor3f(0.5,0.5,0.5);
    //glScalef(1/0.1, 1/3.0, 1/8.0);
    glScalef(4.0, 1.03, 0.1);
    glTranslatef(0.98,-2.025,-32.4);
    rect();
    glScalef(1/4.0, 1/1.03, 1/0.1);
    glScalef(1.0, 1.53, 0.1);
    glTranslatef(-3.0, 1.5, 0);
    rect();
    glTranslatef(6.0, 0.0, 0);
    rect();
    glTranslatef(-3.0, 1.3, 0.);
    glScalef(4.0, 0.53, 0);
    rect();
    if(texture==1)
        glDisable(GL_TEXTURE_2D);


    glPopMatrix();

    //celling
      glPushMatrix();

    glColor3f(0.3,0.3,0.3);
    glTranslatef(0,4,0.0);
    glScalef(4.0, .1, 8.0);

    rect();
    glPopMatrix();

}


void table()
{
    glPushMatrix();
    //table surface
    glColor3f(0.3,0.3,0.9);
    glTranslatef(0,0.0,0.0);
    glScalef(2.2, .1, 4.0);
    if(texture==1)
    {
        glBindTexture(GL_TEXTURE_2D,4);
        glEnable(GL_TEXTURE_2D);
    }
    rect();

    //front-left
    glColor3f(0.1, 0.1, 0.1);
    glScalef(1/3.0, 1/0.1, 1/4.0);
    glScalef(.2, 0.9, 0.4);
    glTranslatef(0.0,-1.11,0.0);
    glTranslatef(-14.5,0,2.0);
    rect();
//    //back-left
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(0,0,-4.0);
    rect();

//    //back-right
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(29.0,0,0.0);
    rect();
//    //front-right
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(0,0,4.0);
    rect();
//    middle back
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(-15,0,-4.0);
    rect();
    // middle front
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(-1.2,0,4.3);
    rect();
    if(texture==1)
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();



}





