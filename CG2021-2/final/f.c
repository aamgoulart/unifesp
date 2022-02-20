#include <GL/glut.h>
#include <stdlib.h>


GLubyte fish[] = {
  0x00, 0x60, 0x01, 0x00,
  0x00, 0x90, 0x01, 0x00,
  0x03, 0xf8, 0x02, 0x80,
  0x1c, 0x37, 0xe4, 0x40,
  0x20, 0x40, 0x90, 0x40,
  0xc0, 0x40, 0x78, 0x80,
  0x41, 0x37, 0x84, 0x80,
  0x1c, 0x1a, 0x04, 0x80,
  0x03, 0xe2, 0x02, 0x40,
  0x00, 0x11, 0x01, 0x40,
  0x00, 0x0f, 0x00, 0xe0,
};

int peixes = 5;
GLfloat pan = 80;
float soma;

GLfloat randomFloat() {
  return (GLfloat)rand() / RAND_MAX;
}


void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1, 0, 1);
}

void parede(float altura, float direita){

  GLUquadricObj *quadratic;
  quadratic = gluNewQuadric();

  glPopMatrix();
  glPushMatrix();

  glRotatef(90,1,0,0);
  glTranslatef(pan-direita, 0, -25+altura);

  gluCylinder(quadratic, 12, 12, 10, 32, 32);

  glPopMatrix();
  glPushMatrix();

  glRotatef(90,1,0,0);
  glTranslatef(pan-direita, 0, -235+altura);

  gluCylinder(quadratic, 10, 10, 220, 32, 32);


  glPopMatrix();
  glPushMatrix();

  glRotatef(-90,1,0,0);
  glTranslatef(pan-direita, 0, -25-altura);

  gluCylinder(quadratic, 12, 12, 10, 32, 32);

  glPopMatrix();
  glPushMatrix();

  glRotatef(-90,1,0,0);
  glTranslatef(pan-direita, 0, -235-altura);

  gluCylinder(quadratic, 10, 10, 220, 32, 32);
  soma +=50;
}


void display() {
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.0,0.8,0.0);
  parede(0, 0);
  parede(-10, -50);
  parede(-20, -100);
  parede(10, -150);
  parede(-30, -200);
  parede(0, -250);
  parede(-40, -300);
  parede(-10, -350);

  glutSwapBuffers();

  for (int i = 0; i < peixes; i++) {
    glColor3f(randomFloat(), randomFloat(), randomFloat());
    glRasterPos3f(randomFloat(), randomFloat(), 0.0);
    glBitmap(27, 11, 0, 0, 0, 0, fish);
  }
  glFlush();
}

void TeclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_UP) {
        peixes++;
    }
    if(key == GLUT_KEY_DOWN) {
        peixes--;
    }
    glutPostRedisplay();
}


   

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(400, 300);
  glutCreateWindow("Peixinhos");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutSpecialFunc(TeclasEspeciais);     
  glutMainLoop();
}