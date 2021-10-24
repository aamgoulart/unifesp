#include <GL/glut.h>
#include <GL/gl.h>

float X=0.0, Y=0.0, cont=0, X2=0.0, Y2=0.0;

void desenha(){
    glClearColor(0, 0, 0, 0); //Preto
    glColor3f(0.0,0.0,1.0); //azul
    glPointSize(5.0);
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
int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (400 ,400);
    glutCreateWindow ("Semana 2 - Exercicio 1");
    glutDisplayFunc (desenha);
    glutMouseFunc(mouseFunc);
    glutMainLoop ();
    return 0;
}