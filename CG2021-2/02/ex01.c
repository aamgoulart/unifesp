#include <GL/glut.h>
#include <GL/gl.h>

float X=0.0, Y=0.0;

void desenha(){
    glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0); //azul
    glPointSize(5.0);
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

int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (400 ,400);
    glutCreateWindow ("Semana 2 - Exercicio 1");
    glutDisplayFunc (desenha);
    glutMouseFunc(mouse);
    glutMainLoop ();
    return 0;
}