#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

float theta=0.0;

void olho(){
    int i;
    float angulo = 0.0;
    glBegin(GL_POLYGON);
        for (i=0;i<=100;i++) {
            angulo= 2 * PI * i / 100.0;
            glVertex2f(0.09*cos(angulo), 0.09*sin(angulo)); //não deixei redondinho perfeito para podermos o efeito de giro
        }
    glEnd ();
}

void robo(){
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0.6);
        glVertex2f(-0.25, 0.85);
        glVertex2f(0.25, 0.85);
        glVertex2f(0.25, 0.6);
    glEnd();
}

void braco()
{
    glBegin(GL_POLYGON);
        glVertex2f(-0.25, 0.6);
        glVertex2f(-0.25, 0.85);
        glVertex2f(0.25, 0.85);
        glVertex2f(0.25, 0.6);
    glEnd();
}

void desenha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3f(0.811,0.709,0.231);
    glTranslatef(-0.35,-0.1,0.0);  
    glRotatef(theta,0,0,1);
    glTranslatef(0,-0.7,0);
    glScalef(1,0.5,1.0);
    robo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.811,0.709,0.231); 
    glTranslatef(0,-0.2,0.0);           //pescoco
    glScalef(0.15,1.0,1.0);
    robo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.709,0.647,0.258);
    glTranslatef(0,-1.1,0.0);          //corpo
    glScalef(1.0,1.8,1.0);
    robo();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.804,0.804,0.804);
    glTranslatef(0,0,0.0);       //cabeca
    robo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.196,0.6,0.8);
    glTranslatef(0.115,0.725,0.0);    //olho direito de quem ve 
    olho();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.196,0.6,0.8);
    glTranslatef(-0.115,0.725,0.0);    //olho esquerdo de quem ve
    olho();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.811,0.709,0.231);
    glTranslatef(0.175,-1.29,0.0);          //perna direita de quem ve
    glScalef(0.3,1.5,1.0);
    robo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.811,0.709,0.231);
    glTranslatef(-0.175,-1.29,0.0);          //perna esquerda de quem ve
    glScalef(0.3,1.5,1.0);
    robo();
    glPopMatrix();

    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            theta-=10;
            break;
        case GLUT_KEY_LEFT:
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
    glutCreateWindow ("Robo");
    glutDisplayFunc (desenha);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}