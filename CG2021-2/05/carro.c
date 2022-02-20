#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

float theta=0.0;
float right=0.0;

void roda(){
    int i;
    float angulo = 0.0;
    glBegin(GL_POLYGON);
        for (i=0;i<=8;i++) {
            angulo= 2 * PI * i / 8.0;
            glVertex2f(0.09*cos(angulo), 0.09*sin(angulo)); 
        }
    glEnd ();
}

void carro(){
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, 0.1);
        glVertex2f(-0.5, 0.4);
        glVertex2f(-0.2, 0.4);
        glVertex2f(-0.07, 0.6);
        glVertex2f(0.3, 0.6);
        glVertex2f(0.37, 0.4);
        glVertex2f(0.45, 0.4);
        glVertex2f(0.45, 0.2);
        glVertex2f(0.47, 0.2);
        glVertex2f(0.47, 0.15);
        glVertex2f(0.45, 0.15);
        glVertex2f(0.45, 0.1);
    glEnd();
}

void desenha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);
    
    glTranslatef(right,0.0,0.0);
    
    glPushMatrix();
    glColor3f(1.0,0.0,0.0);
    glTranslatef(0,0,0.0);
    carro();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-0.3,0.1,0.0);
    glRotatef(theta,0.0,0.0,1.0);
    roda();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(0.26,0.1,0.0);
    glRotatef(theta,0.0,0.0,1.0);
    roda();
    glPopMatrix();

    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            right+=0.05;
            theta-=10;
            break;
        case GLUT_KEY_LEFT:
            right-=0.05;
            theta+=10;
            break;
            
        default:
            break;
    }
    glutPostRedisplay();
}

int main( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (400 ,400);
    glutCreateWindow ("Carro");
    glutDisplayFunc (desenha);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}