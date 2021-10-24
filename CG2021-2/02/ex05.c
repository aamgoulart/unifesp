#include <GL/glut.h>
#include <GL/gl.h>

float X=0.0, Y=0.0, cont=0, X2=0.0, Y2=0.0, X3=0.0, Y3=0.0;
int hasLine = 1;

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(5);
    glColor3f(0.0,0.0,1.0); //azul
}


void desenha(){
    if (hasLine) {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINES);
        glVertex2f(X,Y);
        glVertex2f(X2,Y2);
        glEnd();
        glFlush();
    } else {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glVertex2f(X,Y);
        glVertex2f(X2,Y2);
        glVertex2f(X3, Y3);
        glEnd();
        glFlush();
    }

}

void mouseFunc(int botao, int estado, int x, int y){
     switch (botao){
        case GLUT_LEFT_BUTTON:
           if (estado == GLUT_DOWN){
              if(cont==0){
                X = (x/200.0)-1.0;
                Y = (y/200.0)-1.0;
                Y *= -1.0;
              }
              else{
                 if(cont==1){
                    X2 = (x/200.0)-1.0;
                    Y2 = (y/200.0)-1.0;
                    Y2 *= -1.0;
                 }
                 if(hasLine) {
                    X3 = (x/200.0)-1.0;
                    Y3 = (y/200.0)-1.0;
                    Y3 *= -1.0;
                 }
              }
              cont++;
           }
        break;
        default:
        break;
     }
     if (hasLine) {
        if(cont==2){
            glutPostRedisplay();
            cont = 0;
        }
     } else {
        if(cont==3){
            glutPostRedisplay();
            cont = 0;
        }
     }

}

void Keyboard (unsigned char key, int x, int y){
    switch(key){
       case '0':
          glColor3f(1.0,1.0,1.0);
          break;
       case '1':
          glColor3f(0.5,0.0,0.0);
          break;
       case '2':
          glColor3f(1.0,0.0,0.0);
          break;
       case '3':
          glColor3f(0.0,0.5,0.0);
          break;
       case '4':
          glColor3f(0.0,1.0,0.0);
          break;
       case '5':
          glColor3f(0.0,0.0,0.5);
          break;
       case '6':
          glColor3f(0.0,0.0,1.0);
          break;
       case '7':
          glColor3f(1.0,0.5,0.0);
          break;
       case '8':
          glColor3f(1.0,1.0,0.0);
          break;
       case '9':
          glColor3f(1.0,0.5,1.0);
          break;
        case 'r':
        case 'R':
            hasLine = 1;
        case 't':
        case 'T':
            hasLine = 0;
    }
    glutPostRedisplay();
}

int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (400 ,400);
    glutCreateWindow ("Semana 2 - Exercicio 5");
    init();
    glutDisplayFunc (desenha);
    glutMouseFunc(mouseFunc);
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();
    return 0;
}