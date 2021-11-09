#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

float theta=0.0;

void flor(){
    int i;
    float angulo = 0.0;
    glBegin(GL_POLYGON);
        for (i=0;i<=100;i++) {
            angulo= 2 * PI * i / 100.0;
            glVertex2f(0.5*cos(angulo), 0.5*sin(angulo));
        }
    glEnd ();
}

void petalas(){
    glBegin(GL_POLYGON);
        glVertex2f(0, 0.5);
        glVertex2f(0.1, 0.9);
        glVertex2f(0.15, 0.4);
    glEnd();
}

void desenha(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);

    //deixei as petalas na frente da parte de dentro pra podermos termos a noçao certa de pra onde esta girando

    glPushMatrix();
    glColor3f(0.62,0.31,0.13);
    glTranslatef(0,0,0);
    flor();
    glPopMatrix();
    
    glRotatef(theta,0.0,0.0,1.0);

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    petalas();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-11,0.0,0.0,1.0);
    //petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-22,0.0,0.0,1.0);
    //petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-33,0.0,0.0,1.0);
    //petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-44,0.0,0.0,1.0);
    //petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-55,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-66,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-77,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-88,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-99,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-110,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-121,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-132,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-143,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-154,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-165,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-176,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-187,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-198,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-209,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-220,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-231,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-242,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-253,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-264,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-275,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-286,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-297,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-308,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-319,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-330,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-341,0.0,0.0,1.0);
    petalas();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(0,0,0);
    glRotatef(-352,0.0,0.0,1.0);
    petalas();
    glPopMatrix();
    
    glFlush();
}

void tecladoEspecial(int tecla, int x, int y){
    switch (tecla) {
        case GLUT_KEY_RIGHT:
            theta-=5;      //negativo gira pra direita
            break;
        case GLUT_KEY_LEFT:
            theta+=5;       //positivo gira pra esquerda
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (400 ,400);
    glutCreateWindow ("Flor");
    glutDisplayFunc (desenha);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop ();
    return 0;
}