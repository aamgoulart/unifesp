#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};


GLfloat light1_pos[] = {-2.0, -2.0, 0.0f, 1.0f};
GLfloat direction[] = {0.0f, 0.0f, -1.0f};
float angulo = 0.5;

void lightning(){

    //Fonte de Luz Direcional - Efeito de Holofote
    glLightfv(GL_LIGHT1,GL_POSITION,light1_pos);
    glLightfv(GL_LIGHT1,GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1,GL_SPECULAR, white);
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,direction);  

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
}

void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    gluLookAt(0.0, 0.0, 1.0,  
              0.0, 0.0, 0.0,   
              0.0, 1.0, 0.0);  

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 4.0); 
    glViewport(0, 0, 500, 500);
    lightning();
    glPushMatrix();
}

void esferas(){
        GLfloat diffuse[4];
        GLfloat specular[4];
        GLfloat ns;

    //vermelha
        diffuse[0] = 1.0;
        diffuse[1] = 0.0;
        diffuse[2] = 0.0;
        diffuse[3] = 1.0f;
        specular[0] = 0.0;
        specular[1] = 0.0;
        specular[2] = 0.0;
        specular[3] = 0.0f;
        ns = 100.0f;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
        glMaterialf(GL_FRONT, GL_SHININESS, ns);
    glPushMatrix();
        glRotatef(angulo,0.0,0.0,1.0);
        glTranslatef(-1.5, 0.0, 0.0);
        glutSolidSphere(0.2, 40, 40);
    glPopMatrix();

    //verde
        diffuse[0] = 0.0;
        diffuse[1] = 1.0;
        diffuse[2] = 0.0;
        diffuse[3] = 1.0f;
        specular[0] = 0.0;
        specular[1] = 0.0;
        specular[2] = 0.0;
        specular[3] = 0.0f;
        ns = 20.0f;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
        glMaterialf(GL_FRONT, GL_SHININESS, ns);
    glPushMatrix();
        glRotatef(angulo,0.0,0.0,1.0);
        glTranslatef(1.5, 0.0, 0.0);
        glutSolidSphere(0.2, 40, 40);
    glPopMatrix();

        diffuse[0] = 0.0;
        diffuse[1] = 0.0;
        diffuse[2] = 1.0;
        diffuse[3] = 1.0f;
        specular[0] = 0.0;
        specular[1] = 0.0;
        specular[2] = 0.0;
        specular[3] = 0.0f;
        ns = 20.0f;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
        glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //azul
    glPushMatrix();
        glRotatef(angulo,0.0,0.0,1.0);
        glTranslatef(0.0, -1.5, 0.0);
        glutSolidSphere(0.2, 40, 40);
    glPopMatrix();

        diffuse[0] = 1.0;
        diffuse[1] = 1.0;
        diffuse[2] = 0.0;
        diffuse[3] = 1.0f;
        specular[0] = 0.0;
        specular[1] = 0.0;
        specular[2] = 0.0;
        specular[3] = 0.0f;
        ns = 20.0f;
        glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
        glMaterialf(GL_FRONT, GL_SHININESS, ns);

    //amarela
    glPushMatrix();
        glRotatef(angulo,0.0,0.0,1.0);
        glTranslatef(0.0, 1.5, 0.0);
        glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    
}

void displayFunc() {
        GLfloat diffuse[4];
        GLfloat specular[4];
        GLfloat ns;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

        glMatrixMode(GL_MODELVIEW); //define que a matrix È a model view
        glLoadIdentity(); //carrega a matrix de identidade
        gluLookAt(0.0, 0.0, 1.0,   //posiÁ„o da c‚mera
                  0.0, 0.0, 0.0,   //para onde a c‚mera aponta
                  0.0, 1.0, 0.0);  //vetor view-up
    
        glPushMatrix();
            esferas();
        glPopMatrix();

        lightning();    
        glFlush();
}

void positionController(int estado, float ox, float oy){
    if (estado == GLUT_DOWN)
    {
        light1_pos[0] = ox;
        light1_pos[1] = oy;
        light1_pos[2] = 0.0f;
        light1_pos[3] = 1.0f;
    }
}

void mouse(int botao, int estado, int x, int y)
{
    float mx = x;
    float my = y;
    float ox = (mx / 250 - 1);
    float oy = - (my / 250 - 1);

    switch (botao)
    {
    case GLUT_LEFT_BUTTON:
        positionController(estado, ox, oy);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void anima()
{
    angulo += 0.01;
    glutPostRedisplay();
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Iluminacao");
    glutDisplayFunc(displayFunc);
    glutMouseFunc(mouse);
    glutIdleFunc(anima);
    init();
    glutMainLoop();
    return 0;
}
