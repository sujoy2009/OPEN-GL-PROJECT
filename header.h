#ifndef HEADER
#define HEADER
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <fstream>
#include <iostream>

#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))

#define checkImageWidth 512
#define checkImageHeight 512

extern int texture;

using namespace std;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;


static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

class mRGB
{
public:
	uchar r,g,b,a;
	mRGB(){r = g = b = 0,a=255;}
};

class RGBpixmap
{
	public:
		int nRows,nCols;
		mRGB *pixel;
		void readBMPFile(char *frame);
		void makeCheckerBoard();
		void makeCheckImage();
		void setTexture(GLuint textureName);
};

void mountain();
void robot();
void LookAtView();
void key(unsigned char, int, int);
void timer(int);
void rect();
void trian();
void body();
void legs();
void head();
void hands();
void arms();
void draw_cylinder(GLfloat,GLfloat, GLubyte, GLubyte, GLubyte);   //from net
void draw_finger(GLfloat,GLfloat, GLubyte, GLubyte, GLubyte);
void set_color(GLfloat ,GLfloat , GLfloat , GLfloat );

void room();
void wall();
void table();
void jack();


#endif // HEADER
