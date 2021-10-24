#include <GL/glut.h>
#include <GL/gl.h>

float X=0.0, Y=0.0;

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(5);
    glColor3f(0.0,0.0,1.0); //azul
}

void desenha(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2f(X,Y);
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

void keyboard (unsigned char key, int x, int y){
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
    glutCreateWindow ("Semana 2 - Exercicio 2");
    init();
    glutDisplayFunc (desenha);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop ();
    return 0;
}