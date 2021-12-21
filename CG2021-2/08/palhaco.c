#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float angulo = 20.0;
float tempoDeAnimacao = 100;

void init(){
     glClearColor(0.0,0.0,0.0,0.0);
     glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glOrtho(-7.0,7.0,-7.0,7.0,-7.0,7.0);
     glPushMatrix();
}

void desenhaCabeca(){
    glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glutWireSphere(2.0, 20, 20);
    glPopMatrix();
}

void desenhaChapeu(){
    glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glRotatef(30.0, 0.0, 0.0, 1.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, 2.0);
        glutWireCone(2.0,4.0,20,20);
        glutWireTorus(0.2, 2.2, 10, 25);
    glPopMatrix();
}

void desenhaNariz(){
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glRotatef(angulo,0.0,1.0,0.0);
    glTranslatef(0.0, 0.0, 2.0);
    glutWireSphere(0.5, 20, 20);
    glPopMatrix();
}

void desenhaCabeloEsquerda(){
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(-2.5, 0.0, 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(-2.2, 0.7 , 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(-2.2, -0.7, 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();
}

void desenhaCabeloDireita(){
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(2.5, 0.0, 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(2.2, 0.7 , 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(2.2, -0.7, 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();
}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -9.0);

    glPopMatrix();
    glPushMatrix();

    desenhaCabeca();
    desenhaChapeu();
    desenhaNariz();
    desenhaCabeloEsquerda();
    desenhaCabeloDireita();

    glutSwapBuffers();
}

void animate(int value)
{
    angulo += 5.0;
    if(angulo > 360.0){
        angulo -= 360.0;
    }
    glutTimerFunc(tempoDeAnimacao, animate, 1);
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowPosition(50,50);
     glutInitWindowSize(600,600);
     glutCreateWindow("Palhaco Animado - OpenGL");
     glutDisplayFunc(display);
     glutTimerFunc(5, animate, 1);
     init();
     glutMainLoop();
}