#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float angulo = 0.5;
float velocidade = 0.0000000;
int opcao = 0;

void init(){
     glClearColor(0.0,0.0,0.0,0.0);
     glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glOrtho(-7.0,7.0,-7.0,7.0,-7.0,7.0);
     glPushMatrix();
}

void desenhaCentro(){
    glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glutWireSphere(2.0, 20, 20);
    glPopMatrix();
}

void desenhaFolhas(){
    glPushMatrix();
        glColor3f(1.0,0.2,0.2);
        glRotatef(1, 0.0, 0.0, 1.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(0.0, 0.0, 2.0);
        glutWireCone(1.0, 2.0, 10.0, 10.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0,0.2,0.2);
        glRotatef(90.0, 0.0, 0.0, 1.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(0.0, 0.0, 2.0);
        glutWireCone(1.0, 2.0, 10.0, 10.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0,0.2,0.2);
        glRotatef(-90.0, 0.0, 0.0, 1.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(0.0, 0.0, 2.0);
        glutWireCone(1.0, 2.0, 10.0, 10.0);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0,0.2,0.2);
        glRotatef(-180.0, 0.0, 0.0, 1.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glRotatef(angulo,0.0,1.0,0.0);
        glTranslatef(0.0, 0.0, 2.0);
        glutWireCone(1.0, 2.0, 10.0, 10.0);
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

    desenhaCentro();
    desenhaFolhas();

    glutSwapBuffers();
}

void anima()
{
    switch (opcao) {
        case 1:
            if(velocidade<0.075013){
                velocidade = velocidade + 0.000001;
                angulo= angulo + velocidade;
            }else{
                angulo = angulo + velocidade;
            }
            break;
        case 2:
            if(velocidade>0.000000){
                velocidade = velocidade - 0.000001;
                angulo = angulo + velocidade;
            }
            break;

        case 3:
            angulo= angulo + velocidade;
            break;

        case 4:
            if(velocidade>0.000000){
                angulo = angulo + velocidade;
            }
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void rotacoes(int key, int x, int y){
     switch (key){
        case GLUT_KEY_RIGHT :
            opcao = 3;
            velocidade = velocidade + 0.0001;
            break ;
        case GLUT_KEY_LEFT :
            opcao = 4;
            velocidade = velocidade - 0.0001;
            break ;
        default:
           break;
     }
    glutPostRedisplay();
}

void mouse(int botao, int estado, int x, int y)
{
    glutIdleFunc(anima);
    switch (botao)
    {
    case GLUT_LEFT_BUTTON:
        if (estado == GLUT_DOWN){
            opcao = 1;
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if (estado == GLUT_DOWN){
            opcao = 2;
        }
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowPosition(50,50);
     glutInitWindowSize(600,600);
     glutCreateWindow("Catavento Animado - OpenGL");
     glutDisplayFunc(display);
     glutSpecialFunc(rotacoes);
     glutIdleFunc(anima);
     glutMouseFunc(mouse);
     init();
     glutMainLoop();
}