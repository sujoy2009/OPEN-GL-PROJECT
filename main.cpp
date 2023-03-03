
#include "header.h"


void display();
void init();


void drawSofa2();
void POINT_light();

void fanWheel(float cx, float cy, float cz, float r, int num_segments);
void robot2();
void animate();
void reshape(int, int);
void set_light_0_1();
int width=1200;
int height=600;
int pitch=0, roll=0, yaw=0;
float theta = 0;
float rot = 0;
float rotz = 0;
float left_hand_pos_for_up=0;
int left_hand_pos=20;
float spot_rotz = 0;
float spot_rotx = 0;
float tr_x = 0;
float tr_y = 0;
float tr_z = 0;
float sc = 0.5;
float cup_pos=-2.0;
float cup_pos_x=-3;
float cup_pos_z=0.0;
float rob_rotation=45;
 bool rotate_fan = false;
 int fan_speed =6;

double translate_x=0,translate_y=0,translate_z=0;
double rot_x=0,rot_y=0,rot_z=0;
double zoom_x=0,zoom_y=0,zoom_z=0;
double eye_x = 0;
double eye_y = 0;
double eye_z = 0;
int flag=0;
int texture=0;
float clock_rotate = 0;
//position for animation
int stop=0;
int change_pos=0;
int change_leg=0;
int change_leg_up=0;
int change_pos_back=0;
int head_left=0;
int head_right=0;
int drink_tea=0;
int back_to_original=0;
int change_robot_win=0;
int change_robot_win2=0;

 int change_pos_up=0;
 float rob_pos_x=0;
 float rob_pos_y=0;
 float rob_pos_z=0;
 float head_pos=0;
 float leg_size_inc=1;
int stop_rot=0;
int change_window=0;

int  change_hand_pos=0;
int  change_hand_pos_right=0;
float leg_size=0.7;
float window_pos=0;

GLfloat angle1;
double angle=0,speed=5,maino=0,romo=0,tro=0,mgo=0,sgo=0;

GLfloat centerX = -0.5;
GLfloat centerY = -0.5;
GLfloat centerZ = -0.5;
int rotating_angle_fan = 0;


static GLdouble CameraRad = 0;
static GLdouble CameraTheta = 0;
static GLdouble camHeight = 0;
static GLdouble camRoll = 90;
static GLdouble CameraCenterX = 0;
static GLdouble CameraCenterY = 0;
static GLdouble CameraCenterZ = -100;
GLdouble CameraZ=10;
GLdouble CameraX=0;
GLdouble CameraY=0;

float spot_x = -2.0;
float spot_y = 15.0;
float spot_z = 0.0;
int depth = 0;
int h_rot = 1;

float x_pos = -10.0;
int rev = 1;
int state = 1;
GLUquadric* qobj;
RGBpixmap pix[10];

static GLubyte cube_plane_indics[6][4] =
{
    //consider y axis upper
    {0, 2, 6, 4}, //back
    {1, 5, 7, 3}, //front
    {0, 4, 5, 1}, //bottom
    {2, 3, 7, 6}, //top
    {0, 1, 3, 2}, //left
    {4, 6, 7, 5}  //right
};
static GLfloat cube_vertices[8][3] =
{
    {0, 0, 0},
    {0, 0, 1},
    {0, 1, 0},
    {0, 1, 1},

    {1, 0, 0},
    {1, 0, 1},
    {1, 1, 0},
    {1, 1, 1}
};

const GLfloat light0_ambient[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
const GLfloat light0_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light0_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light0_position[] = { 2.0f, 5.0f, 0.0f, 1.0f };

//const GLfloat light0_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
//const GLfloat light0_diffuse[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
 //const GLfloat light0_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };

const GLfloat light1_ambient[]  = { 0.05f, 0.05f, 0.05f, 1 };
const GLfloat light1_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light1_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light1_position[] = { spot_x, spot_y, spot_z, 1.0f };

static GLfloat light1_spot_direction[] = {0,-1 ,0, 0 };
static GLfloat light1_spot_cutoff[] = { 20 };

GLfloat table_ambient[]    = { 0.9f, 0.9f, 0.9f, 1.0f };
GLfloat table_diffuse[]    = { 0.4f, 0.4f, 0.5f, 1.0f };
GLfloat table_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat table_shininess[] = { 100.0f };

GLfloat jack_ambient[]    = { 0.1f, 0.5f, 0.1f, 1.0f };
GLfloat jack_diffuse[]    = { 0.2f, 1.0f, 0.2f, 1.0f };
GLfloat jack_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat jack_shininess[] = { 50.0f };

GLfloat wall_ambient[]    = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat wall_diffuse[]    = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat wall_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat wall_shininess[] = { 100.0f };

GLfloat robot_ambient[]    = { 0.2f, 0.2f, 1.0f, 1.0f };
GLfloat robot_diffuse[]    = { 0.2f, 0.2f, 1.0f, 1.0f };
GLfloat robot_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat robot_shininess[] = { 50.0f };

GLfloat spot_ambient[]    = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat spot2_ambient[]    = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat spot_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat spot_shininess[] = { 120.0f };

GLfloat env_ambient[]    = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat env_diffuse[]    = { 0.3f, 0.3f, 0.3f, 1.0f };
GLfloat env_specular[]   = { .5f, .5f, .5f, 1.0f };
GLfloat env_shininess[] = { 20.0f };
static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2 - x1;
    Uy = y2 - y1;
    Uz = z2 - z1;

    Vx = x3 - x1;
    Vy = y3 - y1;
    Vz = z3 - z1;

    Nx = Uy * Vz - Uz * Vy;
    Ny = Uz * Vx - Ux * Vz;
    Nz = Ux * Vy - Uy * Vx;

    glNormal3f(Nx, Ny, Nz);
}
void cube(float red = 0.5, float green = 0.5, float blue = 0.5, float alpha = 1)
{
    GLfloat no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat mat_ambient[] = {red, green, blue, 1.0f};
    GLfloat mat_diffuse[] = {red, green, blue, 1.0f};
    GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat high_shininess[] = {50.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glBegin(GL_QUADS);
    for (GLint i = 0; i < 6; i++)
    {
        getNormal3p(cube_vertices[cube_plane_indics[i][0]][0], cube_vertices[cube_plane_indics[i][0]][1], cube_vertices[cube_plane_indics[i][0]][2],
                    cube_vertices[cube_plane_indics[i][1]][0], cube_vertices[cube_plane_indics[i][1]][1], cube_vertices[cube_plane_indics[i][1]][2],
                    cube_vertices[cube_plane_indics[i][2]][0], cube_vertices[cube_plane_indics[i][2]][1], cube_vertices[cube_plane_indics[i][2]][2]);

        for (GLint j = 0; j < 4; j++)
        {
            glVertex3fv(&cube_vertices[cube_plane_indics[i][j]][0]);
        }
    }
    glEnd();
}
void axis()
{
    float length = 10;
    float width = 0.3;
    //x-axis
    glPushMatrix();
    glTranslated(length / 2, 0, 0);
    glScaled(length, width, width);
    glTranslated(centerX, centerY, centerZ);
    cube(1.0, 0.0, 0.0);
    glPopMatrix();

    //y-axis
    glPushMatrix();
    glTranslated(0, length / 2, 0);
    glScaled(width, length, width);
    glTranslated(centerX, centerY, centerZ);
    cube(0.0, 0.0, 1.0);
    glPopMatrix();

    //z-axis
    glPushMatrix();
    glTranslated(0, 0, length / 2);
    glScaled(width, width, length);
    glTranslated(centerX, centerY, centerZ);
    cube(0.0, 1.0, 0.0);
    glPopMatrix();
}

void fan(float x = 0, float y = 0, float z = 0)
{
    glPushMatrix();
    glTranslated(x, y, z);

    //handle of fan
    glPushMatrix();
    glTranslated(0, 1.45, 0);
    glScaled(0.25, 2, 0.25);
    glTranslated(centerX, centerY, centerZ);
    cube(0.40, 0.30, 0.0);
    glPopMatrix();

    //fan wing 1
    glPushMatrix();
    glRotated(rotating_angle_fan, 0, 1, 0);
    glTranslated(1.75, 0.45, 0);
    glScaled(2.75, 0, .5);
    glTranslated(centerX, centerY, centerZ);
    cube(0.8, 0.8, 0.8);
    glPopMatrix();

    //fan wing 2
    glPushMatrix();
    glRotated(rotating_angle_fan, 0, 1, 0);
    glRotated(120, 0, 1, 0);
    glTranslated(1.75, 0.45, 0);
    glScaled(2.75, 0, .5);
    glTranslated(centerX, centerY, centerZ);
    cube(0.8, 0.8, 0.8);
    glPopMatrix();

    //fan wing 3
    glPushMatrix();
    glRotated(rotating_angle_fan, 0, 1, 0);
    glRotated(240, 0, 1, 0);
    glTranslated(1.75, 0.45, 0);
    glScaled(2.75, 0, .5);
    glTranslated(centerX, centerY, centerZ);
    cube(0.8, 0.8, 0.8);
    glPopMatrix();

    //circle of fan
    glPushMatrix();
    glRotated(rotating_angle_fan, 0, 1, 0);
    glTranslated(0.5, -0.1, -1.5);
    glRotated(90, 1, 0, 0);
    glTranslated(centerX, centerX, centerZ);
    fanWheel(0.0, 2.0, 0.0, 1.25, 10000);
    glPopMatrix();

    glPopMatrix();
}

void set_color(GLfloat ambient[],GLfloat diffuse[], GLfloat specular[], GLfloat shininess[])
{
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, specular);
}

void t_recur(int level, GLdouble t, GLdouble b, GLdouble l, GLdouble r)
{
    glVertex3d(l, t, 0.01);
    glVertex3d(l, b, 0.01);
    glVertex3d(r, b, 0.01);
    glVertex3d(r, t, 0.01);

    if (level <= 0)
        return;

    GLdouble a = (t-b)/4.0;

    t_recur(level-1, b+a, b-a, l-a, l+a);
    t_recur(level-1, b+a, b-a, r-a, r+a);
    t_recur(level-1, t+a, t-a, l-a, l+a);
    t_recur(level-1, t+a, t-a, r-a, r+a);


}
/// set_color(wall_ambient, wall_diffuse, wall_shininess, wall_specular);
void tSquare(int level)
{
    set_color(env_ambient, env_diffuse, env_shininess, env_specular);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(-0.5, -0.5, 0);
        glVertex3f(0.5, -0.5, 0);
        glVertex3f(0.5, 0.5, 0);
        glVertex3f(-0.5, 0.5, 0);
    glEnd();
    set_color(robot_ambient, robot_diffuse, robot_shininess, robot_specular);
    glColor3f(1.0, 0, 0);
    glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        t_recur(level, 0.2, -0.2, -0.2, 0.2);
    glEnd();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowPosition(50, 50);
    glutInitWindowSize(width, height);

    glutCreateWindow("Robot - 1707102");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutTimerFunc(0, timer, 0);
    init();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
//    glDisable(GL_LIGHT1);
    //glEnable(GL_COLOR_MATERIAL);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);



   // POINT_light();

    glutIdleFunc(animate);
    glutMainLoop();
}

void animate(){
    if(stop==0){
          if(change_pos==1){
          rob_pos_x-=.03;
           }
           if(change_pos_up==1){
            rob_pos_z+=.03;
           }
            if(change_hand_pos==1){
                left_hand_pos-=0.3;
            }
            if(change_hand_pos_right==1){
                left_hand_pos=1/0.05;
            }
            if(change_leg==1){
                leg_size+=0.05;
                rob_pos_y-=0.0022;
            }
            if(change_leg_up==1){
                leg_size_inc+=0.001;
                rob_pos_y+=0.0022;
                cup_pos+=0.008;
                //leg_size=0.6;
            }
             if(head_left==1){

                head_pos+=5;

            }
             if(head_right==1){

               head_pos-=5;
              }
              if (change_pos_back==1){
                rob_pos_x+=.03;
               // rob_pos_z-=.03;
                cup_pos_x+=.03;
               // cup_pos_z-=.03;

              }
              if(change_window==1){


                window_pos=-0.8;

              }
              if(change_window==0){
                window_pos=0;
              }
              if(change_robot_win==1){

                    if(rob_rotation<100){
                         rob_rotation+=10;
                    }



              }
                if(change_robot_win2==1){

                   left_hand_pos-=0.3;
                   window_pos=+0.8;


              }
              if(drink_tea==1){
                    left_hand_pos_for_up=-57;

              }

              if(back_to_original==1){

                    rob_rotation=40;

                      //rob_pos_x+=.03;


              }







              if (rotate_fan)
                  {
                 rotating_angle_fan = rotating_angle_fan + fan_speed;
               }
              clock_rotate = clock_rotate + 0.01;
            glutPostRedisplay();
    }









}
void POINT_light()
{
   GLfloat light_ambient[] = {0.7, 0.7, 0.7, 1.0};
   GLfloat light_diffuse[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_specular[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_position[] = {0.0, 0.0, 0.0, 1.0};

    glEnable(GL_LIGHT7);
    glLightfv(GL_LIGHT7, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT7, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT7, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT7, GL_POSITION, light_position);
}

void display()
{
    set_light_0_1();
    //glViewport(0,0, width/2, height);
    glViewport(0,0, width, height);

    if(texture==1)
        glDisable(GL_TEXTURE_2D);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    texture = 1;
    if(yaw==1)
        gluLookAt(eye_x, eye_y, eye_z, CameraCenterX, CameraCenterY, CameraCenterZ, 0, 1, 0);
    else
        LookAtView();

    //glTranslatef(0.0,0.0,-2);
    glRotated(theta, 0, 1, 0);
    glRotated(rot, 1,0,0);
    glRotated(rotz, 0,0,1);
    glTranslatef(tr_x, tr_y, tr_z);
    glScalef(1.1, 0.7, 0.9);



    room();
      glPushMatrix();
     glTranslatef(-4,0,0);
    glTranslated(rob_pos_x,rob_pos_y,rob_pos_z);
      glRotatef(rob_rotation, 0, 1, 0);
     robot2();
    glPopMatrix();

    glTranslatef(0, 0, 4.0);
    glScalef(4, 4, 1);
    glTranslatef(1.45, 0.3, -3);
    glScalef(1.0, 2.0, 8.0);
    glRotatef(90, 0, 1, 0);
    tSquare(depth);



    glutSwapBuffers();
}

void mountain()
{
    glPushMatrix();

    glScalef(2.2, 2.2, 0.5);
    glTranslatef(window_pos, 0.5, -7.0);
    if(texture==1)
    {
        glBindTexture(GL_TEXTURE_2D,10);
        glEnable(GL_TEXTURE_2D);
    }
    rect();
    if(texture==1)
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}
void set_light_0_1()
{
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.005);

    glLightfv(GL_LIGHT1, GL_AMBIENT,  light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, light1_spot_cutoff);// set cutoff angle
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1_spot_direction);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10); // set focusing strength

}

void LookAtView()
{
    GLdouble upX = 0, upY = 1, upZ = 0;
    GLdouble tX, tY;

    gluLookAt(CameraX, CameraY, CameraZ, CameraCenterX, CameraCenterY, CameraCenterZ, upX, upY, upZ);

}
void cup(){

     glPushMatrix();

    glColor3f(0.1, 0.1, 0.1);
    glScalef(0.2, 0.3, 0.2);
    glTranslatef(cup_pos_x, cup_pos, cup_pos_z);
    rect();
   // draw_cylinder(1.2, 0.1, 30, 20, 255);
    glPopMatrix();
}
void room()
{
    set_color(wall_ambient, wall_diffuse, wall_shininess, wall_specular);
    glTranslatef(-1.0, 3.0, 1);
    glRotatef(-90, 1, 0, 0);
    glColor3f(1.0, 1.0, 0);

    glPushMatrix();
    glTranslatef(4,0,-1.4);
    glutSolidCone(0.5, 0.5, 500,500);
     glColor3f(1.0, 1.0, 1.0);
    set_color(spot2_ambient, spot2_ambient, spot_shininess, spot_specular);

    glPopMatrix();



    glRotatef(90, 1, 0, 0);
    glTranslatef(2.0, -5.0, 0);
    set_color(wall_ambient, wall_diffuse, wall_shininess, wall_specular);
    glTranslatef(2.0, 5.0, 0);
    glRotatef(-90, 1, 0, 0);
    glColor3f(0, 1.0, 0);
   // glutSolidCone(0.5, 0.5, 500,500);
    glColor3f(1.0, 1.0, 1.0);
    set_color(spot_ambient, spot_ambient, spot_shininess, spot_specular);
    //glutSolidSphere(0.3, 500, 500);
    glRotatef(90, 1, 0, 0);
    glTranslatef(-2.0, -5.0, 0);
    set_color(wall_ambient, wall_diffuse, wall_shininess, wall_specular);
    wall();
    set_color(env_ambient, env_diffuse, env_shininess, env_specular);
    mountain();
    set_color(table_ambient, table_diffuse, table_shininess, table_specular);

    glPushMatrix();
    glTranslatef(-1.7,-2, -1);
    glScalef(0.5,0.5,0.5);
    drawSofa2();
    glPopMatrix();
    //fannnn
    glPushMatrix();
    glScalef(0.5,0.5,0.5);
    fan(-.7,5.7,0);
    glPopMatrix();
    table();
    glScalef(0.7, 0.7, 0.7);
    glTranslatef(-2.0, 1.01, 1.0);
    set_color(jack_ambient, jack_diffuse, jack_shininess, jack_specular);

    cup();
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(2.0, -0.5, -2.0);
    if(texture==1){
        glBindTexture(GL_TEXTURE_2D,6);
        glEnable(GL_TEXTURE_2D);
    }

    glutSolidTeapot(0.5);
    if(texture==1)
        glDisable(GL_TEXTURE_2D);

}
void robot2()
{


    GLfloat robo_ambient[]    = { 0.5f, 0.7f, 0.7f, 1.0f };
    GLfloat robo_diffuse[]    = { 0.5f, 0.7f, 0.7f, 1.0f };
    GLfloat robo_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat robo_shininess[] = { 100.0f };
    glPushMatrix();
    if(texture==1){
        glBindTexture(GL_TEXTURE_2D,9);
        glEnable(GL_TEXTURE_2D);
    }

    set_color(robot_ambient, robot_diffuse, robot_shininess, robot_specular);
    glTranslated(2.5, 1.7, 2.0);
    glRotatef(-20, 0, 1,0);

    //body
     glPushMatrix();

    glColor3f(1.0,0.0,0.0);

    glScalef(0.6, 0.8, 0.9);
    trian();
    glScalef(10/6, 10/6, 10/9);
    //waist
    glColor3f(0.0,0.0,1.0);
    glTranslatef(0.0,-1.2,0.0);
    glScaled(0.98, 0.25, 0.9);
    rect();
    glScaled(100/98, 4, 10/9);
    glTranslatef(0.0,1,0.0);

    glPopMatrix();
    ////legs
     glPushMatrix();
    //left
    glColor3f(0.1,0.1,1.0);
    glTranslatef(-0.4,-1.45,0.0);
    glScalef(0.3, 1/leg_size, 0.7);
    glScalef(1, leg_size_inc, 1);

    rect();
    glTranslatef(0.4,1.35,0.0);
    //right
    glTranslatef(2.23,-1.35,0.0);
    rect();
    //shoe
    glTranslatef(0,-1.0, 0.0);
    glScalef(0.95, 0.05, 1.1);
    trian();
    glTranslatef(-2.75,0,0);
    trian();
    glPopMatrix();
    if(texture==1)
        glDisable(GL_TEXTURE_2D);
    set_color(robo_ambient, robo_diffuse, robo_shininess, robo_specular);

    //head
     glPushMatrix();
    glRotated(-90, 1, 0, 0);
    glRotated(head_pos, 0, 0, 1);
    glTranslatef(0, 0, 0.6);
    draw_cylinder(0.3, 1.0, 255, 255, 0);
    glRotated(90, 1, 0, 0);
    glTranslatef(0, 0.3, 0);
    glRotated(-90, 1, 0, 0);
    draw_cylinder(0.5, 0.6, 230, 250, 20);
    glRotated(90, 1, 0, 0);
    glColor3f(0.0,0.0,0.0);
    glScalef(0.7, 0.7, 0.7);
    glTranslatef(-0.25, 0.5, 0.65);
    glutSolidSphere(0.1, 500, 500);
    glTranslatef(0.45, 0, 0);
    glutSolidSphere(0.1, 500, 500);


    glPopMatrix();

    if(texture==1)
        glDisable(GL_TEXTURE_2D);
    set_color(robot_ambient, robot_diffuse, robot_shininess, robot_specular);

   //hands

    glPushMatrix();
    glRotated(80, 1, 0, 0);
    glTranslatef(-0.6, 0.0, -0.4);
    glRotated(-30, 0, 1, 0);
    draw_cylinder(0.2, 0.6, 0, 0, 255);
    glutSolidSphere(0.2, 100, 100);
    //// joint
    glTranslatef(1.6, 0, -0.275);
    glutSolidSphere(0.2, 100, 100);
    glTranslatef(-1.6, 0, 0.275);
    glRotated(30, 0, 1, 0);

    glTranslatef(1.2, 0.0, 0.0);
    glRotated(30, 0, 1, 0);
   draw_cylinder(0.2, 0.6, 0, 0, 255);
    glutSolidSphere(0.2, 100, 100);
    //// joint
    glTranslatef(-1.6, 0, -0.275);
    glutSolidSphere(0.2, 100, 100);
    glTranslatef(+1.6, 0, 0.275);

    glRotated(-30, 0, 1, 0);
    glPopMatrix();

    glRotated(h_rot, 0.8,0.0,0.0); ///hand rotate

   //arms
    glPushMatrix();
    //glTranslatef(-1.6, 0, -0.275);
    glColor3b(20, 0, 250);
    glTranslatef(0.65, 0.3, -0.1);
    glRotated(left_hand_pos, 1, 0, 0);
    glRotated(left_hand_pos, 0, 1, 0);
    //glRotated(left_hand_pos, 0, 0, 1);

     glRotated(left_hand_pos_for_up, 1, 0, 0);

    glTranslatef(0.15, -0.35, 0.3);
    draw_cylinder(0.2, 0.7, 30, 20, 255);

    glRotated(-40, 0, 1, 0);
    glTranslatef(-1.68, -0.0, 0.6);
    draw_cylinder(0.2, 0.7, 30, 20, 255);

    glTranslatef(0, -0.25, 0.9);
    glRotated(-90, 1, 0, 0);
    glRotated(-50, 0, 0, 1);
    draw_finger(0.2, 0.5, 250,250,0);

    glTranslatef(0.84, 2.25, 0.0);
    glRotated(50, 0, 0, 1);
    draw_finger(0.2, 0.5, 250,250,0);
    glPopMatrix();

    if(texture==1)
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}
///GL_TEXTURE_CUBE_MAP
void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    qobj = gluNewQuadric();

    pix[0].makeCheckImage();
	pix[0].setTexture(1);

	pix[1].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\floor.bmp");
	pix[1].setTexture(2);

	pix[2].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\wall.bmp");
	pix[2].setTexture(3);

	pix[3].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\wood.bmp");
	pix[3].setTexture(4);

    pix[4].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\jack.bmp");
	pix[4].setTexture(5);

	pix[5].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\teapot.bmp");
	pix[5].setTexture(6);

	pix[6].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\sunset.bmp");
	pix[6].setTexture(7);

	pix[7].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\cube.bmp");
	pix[7].setTexture(8);

	pix[8].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\sphere.bmp");
	pix[8].setTexture(9);

	pix[9].readBMPFile("F:\\4.2\\project_graphics\\1707102\\image\\mountain.bmp");
	pix[9].setTexture(10);

}

void reshape(int width, int height)
{
    const double ar = (double) width / (double) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
    gluLookAt(0, 0, 25, 0, 0, 0, 0, 1, 0);

}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/100, timer, 0);




}

void drawCube(float x, float y, float z)
{
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f+x, 0.0f, 0.0f);
    glVertex3f(0.0f+x, 0.0f+y, 0.0f);
    glVertex3f(0.0f, 0.0f+y, 0.0f);



    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f+x, 0.0f, 0.0f);
    glVertex3f(0.0f+x, 0.0f, 0.0f-z);
    glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
    glVertex3f(0.0f+x, 0.0f+y, 0.0f);


    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.0f+x, 0.0f, 0.0f-z);
    glVertex3f(0.0f, 0.0f, 0.0f-z);
    glVertex3f(0.0f, 0.0f+y, 0.0f-z);
    glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);


    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f-z);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f+y, 0.0f);
    glVertex3f(0.0f, 0.0f+y, 0.0f-z);


    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f+y, 0.0f);
    glVertex3f(0.0f+x, 0.0f+y, 0.0f);
    glVertex3f(0.0f+x, 0.0f+y, 0.0f-z);
    glVertex3f(0.0f, 0.0f+y, 0.0f-z);


    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f+x, 0.0f, 0.0f);
    glVertex3f(0.0f+x, 0.0f, 0.0f-z);
    glVertex3f(0.0f, 0.0f, 0.0f-z);



    glEnd();
}



void drawSofa2()
{
     set_color(wall_ambient, wall_diffuse, wall_shininess, wall_specular);
    glColor3f(0.8, 0.8, 0.3);
    glTranslatef(-4,0,8);
    drawCube(0.3,2.5,3);
    glTranslatef(4,0,-8);

    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(-3.7,0,8.1);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-8.1);

    glTranslatef(-3.7,0,5);
    drawCube(1.5,2,0.3);
    glTranslatef(3.7,0,-5);

    glColor3f(0.7, 0.7, 0.7);

    glTranslatef(-3.7,0.5,8);
    drawCube(1.2,0.2,3);
    glTranslatef(3.7,-0.5,-8);

}
void fanWheel(float cx, float cy, float cz, float r, int num_segments)
{

    GLfloat no_mat[] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat mat_ambient[] = {0.7, 0.7, 0.5, 1.0f};
    GLfloat mat_diffuse[] = {0.7, 0.7, 0.5, 1.0f};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0f};
    GLfloat high_shininess[] = {50.0f};

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle
        float x = r * cosf(theta);                                         //calculate the x component
        float y = r * sinf(theta);                                         //calculate the y component
        glVertex3f(x + cx, y + cy, cz);                                    //output vertex
    }
    glEnd();
}


void key(unsigned char key, int x, int y)
{

    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;


    /// y = yaw (y-axis)
    /// u = roll (z-axis)
    /// i = pitch (x-axis)

    case 'y':
        yaw = 1;
        CameraTheta += rev * .1;
        eye_x = 10 * cos(CameraTheta)  ;
        eye_z = 10 * sin(CameraTheta)  ;
        break;


    /// Rotation

    case 'D':
        theta += 4;
        break;

    case 'd':
        theta -= 4;
        break;

    case 'r':
        rotz -= 4;
        break;

    case 'R':
        rotz += 4;
        break;

    /// Translate


    /// Scaling

    case '+':
        CameraZ++;

        break;
    case '-':
        CameraZ--;
        break;

    /// light on



    case 'l':


            glEnable(GL_LIGHT1);
            spot_ambient[0] = 1.0;
            spot_ambient[1] = 1.0;
            spot_ambient[2] = 1.0;




        break;
    //light off
    case '0':
          glDisable(GL_LIGHT1);
            spot_ambient[0] = 0.0;
            spot_ambient[1] = 0.0;
            spot_ambient[2] = 0.0;

    break;

    /// POINT light manipulation

    case 'm':
         POINT_light();
        break;
    case 's':
       stop=0;
        change_pos=1;
        break;
    case 'u':
     stop=0;
        change_pos_up=1;
        break;
     case 'p':

       stop=1;
        change_pos=0;
        change_pos_up=0;
        change_hand_pos=0;
        change_leg=0;
        change_leg_up=0;
         head_left=0;
        head_right=0;
       change_pos_back=0;
       back_to_original=0;
        break;
     case 'P':

       stop=1;
        change_pos=0;
        change_pos_up=0;
        change_hand_pos=0;
        change_leg_up=0;

        change_leg=0;
        head_left=0;
        head_right=0;
        back_to_original=0;
        change_pos_back=0;
        break;

     case 'h':

        stop=0;
        change_hand_pos=1;
        break;
     case 'g':

        stop=0;
        change_leg=1;
        break;
     case 'x':

        stop=0;
        drink_tea=1;
        break;
    case 'G':

        stop=0;
        change_leg_up=1;
        break;
     case 'a':

        stop=0;
        head_left=1;
        break;

      case 'e':
        stop=0;
        head_right=1;
        break;

      case 'w':
          stop=0;
        change_pos_back=1;
        break;
      case 'j':
          stop=0;

          if(change_window==0){
            change_window=1;
          }

         break;
      case 'k':
          stop=0;

          if(change_window==1){
            change_window=0;
          }

         break;
      case '1':
          stop=0;

          change_robot_win=1;

         break;
      case '2':
          stop=0;

          change_robot_win2=1;

         break;

     case '3':
          stop=0;

          back_to_original=1;

         break;
     case '4':
        stop=0;
        change_hand_pos_right=1;
        break;

      case 'f':
        rotate_fan = !rotate_fan;
        break;
      case '7':
          fan_speed=fan_speed+1;
        break;
      case '8':
       fan_speed=fan_speed-1;
      break;


    }
    //printf("%f %f %f\n", spot_x, spot_y, spot_z);

    glutPostRedisplay();
}







