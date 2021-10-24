#include <GL/glut.h>
#include <GL/gl.h>

float X=0.0, Y=0.0, cont=0, X2=0.0, Y2=0.0;

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(5);
    glColor3f(0.0,0.0,1.0); //azul
}


void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2f(X,Y);
    glVertex2f(X2,Y2);
    glEnd();
    glFlush();
}

void mouse(int botao, int estado, int x, int y)
{
    switch(botao)
    {
        case GLUT_LEFT_BUTTON:
            if(estado == GLUT_DOWN)
            {
                X = (x/200.0)-1.0;
                Y = (y/200.0)-1.0;
                Y *= -1.0;
            }
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
void mouseFunc(int botao, int estado, int x, int y){
     switch (botao){
        case GLUT_RIGHT_BUTTON:
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
              }
              cont++;
           }
        break;
        default:
        break;
     }
     if(cont==2){
        glutPostRedisplay();
        cont = 0;
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
    }
    glutPostRedisplay();
}

int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (400 ,400);
    glutCreateWindow ("Semana 2 - Exercicio 1");
    init();
    glutDisplayFunc (desenha);
    glutMouseFunc(mouseFunc);
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();
    return 0;
}