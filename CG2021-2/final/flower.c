#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <GL/glut.h>


#define PI 3.14159

GLfloat red[3] = {1.0, 0.0, 0.0};
GLfloat green[3] = {0.0, 1.0, 0.0};
GLfloat blue[3] = {0.0, 0.0, 1.0};
GLfloat black[3] = {0.0, 0.0, 0.0};
GLfloat white[3] = {1.0, 1.0, 1.0};
GLfloat gray[3] = {0.5, 0.5, 0.5};
GLfloat yellow[3] = {1.0, 1.0, 0.0};
GLfloat magenta[3] = {1.0, 0.0, 1.0};
GLfloat cyan[3] = {0.0, 1.0, 1.0};

GLfloat pos[3] = {0,0,0};
GLfloat theta[3] = {0,0,0};

GLint fillmode = 1;

GLint numPetals = 5;

//forward declaration of functions
void display(void);
void keypress(unsigned char key, int x, int y);
void main_menu(int value);

int main(int argc, char** argv) {

  //open a window
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(200,200);
  glutCreateWindow(argv[0]);

  glEnable(GL_DEPTH_TEST);

  //OpenGL init
  glClearColor(0, 0, 0, 0); //set background to black

  //camera is at (0,0,0) looking at negative y axis
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, 1, 1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  pos[2] = -5;
/*   pos[1] = -1.3; */

  //callback functions
  glutDisplayFunc(display);
  glutKeyboardFunc(keypress);

  glutCreateMenu(main_menu);
  glutAddMenuEntry("Quit", 1);
  glutAddMenuEntry("Toggle Fill Mode", 2);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  //event handler
  glutMainLoop();
  return 0;
}

//draws a circle or radius r centered at x,y
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

//draws the center of the flower.  This is basically a short column, made up of many circles.
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
  //draw one circle on the bottom to close it out
  glBegin(GL_POLYGON);
  for(angle = 0; angle < 2*PI; angle += PI/100) {
    x = (r * cos(angle)) + inX;
    y = (r * sin(angle)) + inY;
    glVertex3f(x, y,z);
  }
  glEnd();

}


//draws a petal of the flower. the point of petal that meets the circle is at startx, starty. inAngle is the angle on the center circle at which the petal will be drawn, so it can be oriented in the correct direction. It is constructed from two arcs of 2 very big circle with radius radius.
void drawPetal(GLfloat startx, GLfloat starty, GLfloat inAngle, GLfloat radius) {
  glPushMatrix();
  //rotate the matrix so that the elipse will be oriented correctly
  //convert inAngle to degrees
  GLfloat inAngle_degs = inAngle * 180/PI;
  glRotatef(inAngle_degs, 0.0, 0.0, 1.0);
  glTranslatef(2*radius, 0.0, 0.0);

  glBegin(GL_TRIANGLE_FAN);
  glColor3fv(red);
  glVertex3f(-radius/5, 0.0, -0.2);
  glColor3fv(yellow);

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

  //pop the rotated matrix, so we go back to original
  glPopMatrix();
}

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //just to be sure 
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  //move scene based on input
  glTranslatef(pos[0], pos[1], pos[2]);
  glRotatef(theta[0], 1.0, 0.0, 0.0);
  glRotatef(theta[1], 0.0, 1.0, 0.0);
  glRotatef(theta[2], 0.0, 0.0, 1.0);

  //-----------------------------------
  if(fillmode)
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  else
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  GLfloat radius = .5;

  glColor3fv(white);
  //draw petals
  GLint i;
  GLfloat angle,x,y;
  for(i = 0; i < numPetals; i++){
    angle = i*(2*PI / numPetals);
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
    
  case 'b':
    pos[2] -= 0.5;
    break;
  case 'f':
    pos[2] += 0.5;
    break;
  case 'd':
    pos[1] -= 0.5;
    break;
  case 'u':
    pos[1] +=0.5;
    break;
  case 'l':
    pos[0] -= 0.5;
    break;
  case 'r':
    pos[0] += 0.5;
    break;

  case '+':
    numPetals++;
    break;
  case '-':
    if(numPetals > 2){
      numPetals--;
    }
    break;

  case 'q':
    exit(0);
    break;
  }
  glutPostRedisplay();
}

void main_menu(int value) {
  switch(value) {
  case 1:
    exit(0);
    break;
 case 2:
   fillmode = !fillmode;
   break;
  }
  glutPostRedisplay();
}
