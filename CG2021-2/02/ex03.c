#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int scrSizeX=600, scrSizeY=600;
int mouseX1=280, mouseX2=320, mouseY1=300, mouseY2=300, cont=0;

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(5);
    glColor3f(0.0,0.0,1.0);
}

void bresenham_lines(int x1,int x2, int y1,int y2){
     int dx,dy, incSup, incInf, p, x, y, auxX, auxY, incX, incY;

     //Se ambos x e y decrescem, ponto inicial passa a ser ponto final e vice-versa
     if(x2<x1 && y2<y1){
        auxX = x2;
        x2 = x1;
        x1 = auxX;
        auxY = y2;
        y2 = y1;
        y1 = auxY;
     }

     //ponto incial
     x = x1;
     y = y1;

     //cálculo de delta_x e delta_y
     dx = x2-x1;
     dy = y2-y1;

     //Verifica se x e y irão crescer ou decrescer
     if(dx<0)
        incX = -1;
     else
        incX = 1;
     if(dy<0)
        incY = -1;
     else
        incY = 1;

     //Verifica se os incrementos(decrementos) unitários serão em x e/ou y
     //1) delta_x=delta_y - incrementos(decrementos) unitários em ambos
     if(abs(dx)==abs(dy))
        while(x!=x2){
           glVertex2f(((float)x/((float)scrSizeX/2))-1,-(((float)y/((float)scrSizeY/2))-1));
           x+=incX;
           y+=incY;
        }
     else{
        //2) delta_x=0 - incrementos(decrementos) apenas em y
        if(dx==0)
           while(y!=y2){
              glVertex2f(((float)x/((float)scrSizeX/2))-1,-(((float)y/((float)scrSizeY/2))-1));
              y+=incY;
           }
        else{
           //3) delta_y=0 - incrementos(decrementos) apenas em x
           if(dy==0){
              while(x!=x2){
                 glVertex2f(((float)x/((float)scrSizeX/2))-1,-(((float)y/((float)scrSizeY/2))-1));
                 x+=incX;
              }
           }
           else{
              //4) m>1 - incrementos unitários em y
              if(abs(dx)<abs(dy)){
                 p=2*abs(dx)-abs(dy);
                 incInf = 2*abs(dx);
                 incSup = 2*abs(dx)-2*abs(dy);
                 while(y!=y2){
                    if(p<0)
                       p +=incInf;
                    else{
                       p+=incSup;
                       x+=incX;
                    }
                    y+=incY;
                    glVertex2f(((float)x/((float)scrSizeX/2))-1,-(((float)y/((float)scrSizeY/2))-1));
                 }
              }
              //5) 0<m<1 - incrementos unitários em x
              else{
                 p = 2*abs(dy)-abs(dx);
                 incInf = 2*abs(dy);
                 incSup = 2*abs(dy)-2*abs(dx);
                 while(x!=x2){
                    if(p<0)
                    p +=incInf;
                    else{
                       p+=incSup;
                       y+=incY;
                    }
                    x+=incX;
                    glVertex2f(((float)x/((float)scrSizeX/2))-1,-(((float)y/((float)scrSizeY/2))-1));
                 }
              }
           }
        }
     }
}

void desenho(){
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        bresenham_lines(mouseX1,mouseX2,mouseY1,mouseY2);
    glEnd();
    glFlush();
}

void mouseFunc(int botao, int estado, int x, int y){
     switch (botao){
        case GLUT_LEFT_BUTTON:
           if (estado == GLUT_DOWN){
              if(cont==0){
                 mouseX1=x;
                 mouseY1=y;
              }
              else{
                 if(cont==1){
                    mouseX2=x;
                    mouseY2=y;
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

int main( int argc, char *argv[ ] ){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(600,600);
    glutInit(&argc, argv);
    glutCreateWindow("Cria um triângulo");
    init();
    glutDisplayFunc(desenho);
    glutMouseFunc(mouseFunc);
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();
    return 0;
}
