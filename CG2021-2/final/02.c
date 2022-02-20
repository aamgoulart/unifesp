#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <GL/glut.h>


#define PI 3.14

GLfloat white[3] = {1.0, 1.0, 1.0};
GLfloat magenta[3] = {1.0, 0.0, 1.0};
GLfloat cyan[3] = {0.0, 1.0, 1.0};

GLfloat pos[3] = {0,0,0};
GLfloat theta[3] = {0,0,0};


void display(void);
void keypress(unsigned char key, int x, int y);
void main_menu(int value);
void tecladoEspecial(int tecla, int x, int y);

int main(int argc, char** argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1000,1000);
  glutInitWindowPosition(1000,1000);
  glutCreateWindow(argv[0]);

  glEnable(GL_DEPTH_TEST);

  glClearColor(0, 0, 0, 0); 

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1, 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  pos[2] = -5;

  glutDisplayFunc(display);
  glutKeyboardFunc(keypress);
  glutSpecialFunc(tecladoEspecial);

  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutMainLoop();
  return 0;
}

void circle(GLfloat r, GLfloat inX, GLfloat inY, GLfloat inZ) {

  GLfloat angle,x,y;
  glBegin(GL_POLYGON);
  for(angle = 0; angle < 2 * PI; angle += .1) {
    x = (r * cos(angle)) + inX;
    y = (r * sin(angle)) + inY;
    glVertex2f(x, y);
  }
  glEnd();
}

void drawCenter(GLfloat r, GLfloat inX, GLfloat inY) {
  GLfloat angle, x, y, z;
  glBegin(GL_POLYGON);
  for(z = -.1; z < .1; z += .01) {
    for(angle = 0; angle < 2*PI; angle += PI/100) {
      x = (r * cos(angle)) + inX;
      y = (r * sin(angle)) + inY;
      glVertex3f(x, y, z);
    }
  }
  glEnd();
  glBegin(GL_POLYGON);
  for(angle = 0; angle < 2*PI; angle += PI/100) {
    x = (r * cos(angle)) + inX;
    y = (r * sin(angle)) + inY;
    glVertex3f(x, y,z);
  }
  glEnd();

}


void drawPetal(GLfloat startx, GLfloat starty, GLfloat inAngle, GLfloat radius) {
  glPushMatrix();

  GLfloat inAngle_degs = inAngle * 180/PI;
  glRotatef(inAngle_degs, 0.0, 0.0, 1.0);
  glTranslatef(2*radius, 0.0, 0.0);

  glBegin(GL_TRIANGLE_FAN);
  glColor3fv(magenta);
  glVertex3f(-radius/5, 0.0, -0.2);
  glColor3fv(cyan);

  GLfloat angle, z_value;
  for(angle = 0; angle < 2.01*PI; angle += 2*PI/100){
    if(angle <=PI) {
      z_value = .2 * (1-(angle/PI));
    }
    else {
      z_value = .2 * ((angle-PI)/PI);
    }
    glVertex3f(2*radius * cos(angle), radius/2 * sin(angle), z_value);
  }
  glEnd();

  glPopMatrix();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  glTranslatef(pos[0], pos[1], pos[2]);
  glRotatef(theta[0], 1.0, 0.0, 0.0);
  glRotatef(theta[1], 0.0, 1.0, 0.0);
  glRotatef(theta[2], 0.0, 0.0, 1.0);

  GLfloat radius = .5;

  glColor3fv(white);
  GLint i;
  GLfloat angle,x,y;
  for(i = 0; i < 5; i++){
    angle = i*(2*PI / 5);
    x = radius * cos(angle);
    y = radius * sin(angle);
    drawPetal(x, y, angle, radius);
  }

  glColor3fv(white);
  //draw center circle
  drawCenter(radius, 0, 0);

  glFlush();

}

void keypress(unsigned char key, int x, int y) {
  switch(key) {

    //object movement
  case 'x':
    theta[0] += 5.0;
    break;
  case 'X':
    theta[0] -= 5.0;
    break;
  case 'y':
    theta[1] += 5.0;
    break;
  case 'Y':
    theta[1] -= 5.0;
    break;
  case 'z':
    theta[2] += 5.0;
    break;
  case 'Z':
    theta[2] -= 5.0;
    break;
  }

  glutPostRedisplay();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            pos[0] += 0.5;
            break;
        case GLUT_KEY_LEFT:
            pos[0] -= 0.5;
            break;
        case GLUT_KEY_UP:
            pos[1] += 0.5;
            break;
        case GLUT_KEY_DOWN:
            pos[1] -= 0.5;
            break;
        case GLUT_KEY_INSERT:
            pos[2] += 0.5;
            break;
        case GLUT_KEY_END:
            pos[2] -= 0.5;
            break;
            
        default:
            break;
    }
    printf("%d %d %d\n",pos[0], pos[1], pos[2] );
    glutPostRedisplay();
}

void home()
{
    //Roof
    glClear(GL_COLOR_BUFFER_BIT);     // Clear display window
    // Set line segment color as glColor3f(R,G,B)
    glColor3f(0.3, 0.5, 0.8);
    glBegin(GL_POLYGON);
    glVertex2i(200, 500);
    glVertex2i(600, 500);
    glVertex2i(700, 350);
    glVertex2i(300, 350);
    glEnd();
    // Top of Front Wall
    glColor3f(0.1, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2i(200, 500);
    glVertex2i(100, 350);
    glVertex2i(300, 350);
    glEnd();
    // Front Wall
    glColor3f(0.7, 0.2, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(100, 350);
    glVertex2i(300, 350);
    glVertex2i(300, 100);
    glVertex2i(100, 100);
    glEnd();
    // Front Door
    glColor3f(0.7, 0.2, 0.9);
    glBegin(GL_POLYGON);
    glVertex2i(150, 250);
    glVertex2i(250, 250);
    glVertex2i(250, 100);
    glVertex2i(150, 100);
    glEnd();

    // Front Door Lock
    glColor3f(0.3, 0.7, 0.9);
    glPointSize(15);
    glBegin(GL_POINTS);
    glVertex2i(170, 170);
    glEnd();

    //side Wall
    glColor3f(0.1, 0.2, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(300, 350);
    glVertex2i(700, 350);
    glVertex2i(700, 100);
    glVertex2i(300, 100);
    glEnd();
    // window one
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(330, 320);
    glVertex2i(450, 320);
    glVertex2i(450, 230);
    glVertex2i(330, 230);
    glEnd();
    // line of window one
    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(390, 320);
    glVertex2i(390, 230);
    glVertex2i(330, 273);
    glVertex2i(450, 273);
    glEnd();
    // window two
    glColor3f(0.2, 0.4, 0.3);
    glBegin(GL_POLYGON);
    glVertex2i(530, 320);
    glVertex2i(650, 320);
    glVertex2i(650, 230);
    glVertex2i(530, 230);
    glEnd();
    // lines of window two
    glColor3f(0.1, 0.7, 0.5);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(590, 320);
    glVertex2i(590, 230);
    glVertex2i(530, 273);
    glVertex2i(650, 273);
    glEnd();

    // Entrance Path
    glColor3f(0.3, 0.5, 0.7);
    glLineWidth(3);
    glBegin(GL_POLYGON);
    glVertex2i(150, 100);
    glVertex2i(250, 100);
    glVertex2i(210, 0);
    glVertex2i(40, 0);
    glEnd();
    // Process all OpenGL routine s as quickly as possible
    glFlush();
}