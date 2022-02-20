#include<stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
#include<math.h>
float  s=400,ss=140, a=0,b=0,aa=-70,bb=0;

float x=100,y=0,r=0.5,y11=0,y21=0,y31=0,y41=0,y51=0,y61=0,y71=0,y81=0,y91=0,y10=0,y12=0,y13=0,y14=0,x0=0,xo=0, angle=0.0, pi=3.142;

GLfloat light0_pos[] = {2.0f, 2.0f, 2.0f, 1.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat kd = 0.0f;


void lightning();
void init();
void reshape(GLint w, GLint h);
void fish1() ;
void fish2();
void pedraSmall();
void pedra();
void pedra1();
void pedra2();
void circleFunc(float yc,int d,int x1,int y1);
float checkBubPos(float y,float c);
void circle(int x);
void plant3L(int x1, int x2, int m);
void plant();
void display();
void keyboard (unsigned char key, int x, int y);
void teclasEspeciais(int key, int x, int y);

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    glutCreateWindow("Peixinhos");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(teclasEspeciais);     
    glutMainLoop();
}


void init() {
	glClearColor(0.0,0.5,0.5,0.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    gluLookAt(0.0, 0.0, 1.0,   
              0.0, 0.0, 0.0,   
              0.0, 1.0, 0.0);  

    glMatrixMode(GL_PROJECTION); 
	gluOrtho2D(0,500,0,500);
    glViewport(0, 0, 500, 500);
    lightning();
    glPushMatrix();
}



void lightning(){
    glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,black);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,white);
    glLightfv(GL_LIGHT0,GL_SPECULAR,black);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h>w) {
		gluOrtho2D(0, 500, ((float)h/(float)w)*(0), ((float)h/(float)w)*500);

    } else{
        gluOrtho2D(((float)w/(float)h)*(0), ((float)w/(float)h)*(520), 0, 500);
    }
	
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

void fish1() {


    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(270+a,350+aa);

        glVertex2f(300+a,325+aa);

        glVertex2f(370+a,350+aa);
        glVertex2f(300+a,375+aa);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(360+a,350+aa);
        glColor3ub( rand()%1, rand()%1000, rand()%1000 );
        glVertex2f(405+a,370+aa);
        glVertex2f(395+a,350+aa);
        glVertex2f(405+a,327+aa);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub( rand()%1, rand()%1000, rand()%1000 );
        glVertex2f(302+a,373+aa);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(340+a,409+aa);
        glVertex2f(320+a,360+aa);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub( rand()%1, rand()%1000, 0 );
        glVertex2f(302+a,328+aa);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(340+a,300+aa);
        glVertex2f(320+a,340+aa);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glVertex2f(280+a,355+aa);
    glEnd();
}

void fish2()
{
	 glColor3f(128.0,0.0,128.0);
    
    
    glBegin(GL_POLYGON);
        glVertex2f(70+b,145+bb);
        glColor3ub(rand()%300, rand()%300,0);
        glVertex2f(20+b,120+bb);
        glVertex2f(30+b,145+bb);
        glVertex2f(20+b,170+bb);
    glEnd();


    glColor3f(128.0,0.0,128.0);
    glBegin(GL_POLYGON);
        glVertex2f(65+b,145+bb);

        glVertex2f(125+b,170+bb);

        glVertex2f(165+b,145+bb);
        glVertex2f(125+b,120+bb);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3ub(rand()%500, rand()%500,0);
        glVertex2f(126+b,168+bb);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(110+b,155+bb);
        glVertex2f(85+b,195+bb);
    glEnd();

    
    glBegin(GL_TRIANGLES);
        glColor3ub(rand()%500, rand()%500,0);
        glVertex2f(126+b,122+bb);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(110+b,136+bb);
        glVertex2f(85+b,95+bb);
    glEnd();

    glColor3f(67.0,59.0,103.0);
  
    glPointSize(4.0);
    glBegin(GL_POINTS);
        glVertex2f(150+b,149+bb);
    glEnd();

}


void pedraSmall(){

    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(46,47,47);
        y =(sin(angle*pi/180)*30);
        x =(cos(angle*pi/180)*50);
        glVertex2f(x+150,y-5);
    }
    glEnd();
}

void pedra(){

    pedraSmall();
    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub( 142,20,30);
        y =(sin(angle*pi/180)*45);
        x =(cos(angle*pi/180)*75);
        glVertex2f(x+250,y-10);
    }
    glEnd();
}

 void pedra1(){

    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub( 20,20,20);
        y =(sin(angle*pi/180)*35);
        x =(cos(angle*pi/180)*65);
        glVertex2f(x+370,y-5);
    }
    glEnd();
}
 void pedra2(){

    glBegin(GL_TRIANGLE_FAN);
    for(angle=0; angle<360.0; angle+=.1){
        glColor3ub(36, 60, 2);
        y =(sin(angle*pi/180)*40);
        x =(cos(angle*pi/180)*75);
        glVertex2f(x+610,y+10);
    }
    glEnd();
}

void circleFunc(float yc,int d,int x1,int y1){
    for(angle=0; angle<360.0; angle+=.1)
	{
        y =yc+(sin(angle*pi/180)*d);
        x =(cos(angle*pi/180)*d);
        glVertex2f(x+x1,y-y1);
	}
}
float checkBubPos(float y,float c){
    if(y<500){
        return y+c;
    }
    else{
        return 0;
    }
}
void circle(int x){

    glBegin(GL_POINTS);
    circleFunc(y21,15,x+10,30);
    circleFunc(y31,5,x,60);
    circleFunc(y41,7,x+10,90);
    circleFunc(y51,12,x,120);
    circleFunc(y61,15,x+10,150);
    circleFunc(y71,5,x,180);
    circleFunc(y81,3,x+10,210);
    circleFunc(y81,15,x,240);
    circleFunc(y91,12,x+10,270);
    circleFunc(y10,10,x,300);
    circleFunc(y12,16,x+10,330);
    circleFunc(y13,15,x,360);
    circleFunc(y14,10,x+10,400);
	glEnd();

	y11 = checkBubPos(y11,2.0);
	y21 = checkBubPos(y21,3.0);
	y31 = checkBubPos(y31,4.5);
	y41 = checkBubPos(y41,7.0);
	y51 = checkBubPos(y51,6.5);
	y61 = checkBubPos(y61,18.0);
	y71 = checkBubPos(y71,17.5);
	y81 = checkBubPos(y81,8.0);
	y91 = checkBubPos(y91,7.5);
	y10 = checkBubPos(y10,10.0);
	y12 = checkBubPos(y12,11.0);
	y14 = checkBubPos(y14,8.0);
	y12 = checkBubPos(y12,9.0);
	y13 = checkBubPos(y13,1.0);
	glutPostRedisplay();

}

void plant3L(int x1, int x2, int m){
    int dis = x2-x1;
    dis = dis/3;
    glColor3ub( 40,170,5);
    glBegin(GL_POLYGON);
    glVertex2f(x1,0);
    glVertex2f(x1-10,m-10);
    glColor3f(0.0,0.5,0.0);
    glVertex2f(x1+dis,15);
    glVertex2f(x1+((x2-x1)/2),m);
    glVertex2f(x2-dis,15);
    glVertex2f(x2+12,m+10);
    glVertex2f(x2,0);
    glEnd();
}


void plant()
{
    plant3L(50,40,40);
    plant3L(95,85,50);
    plant3L(120,110,45);
    plant3L(70,60,60);
    plant3L(140,130,43);
    plant3L(470,460,40);
    plant3L(490,480,55);
    plant3L(520,510,40);
    plant3L(540,530,50);

    plant3L(10,20,60);
    plant3L(160,170,50);
    plant3L(310,320,70);
    plant3L(435,445,60);

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat diffuse[4];
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    gluLookAt(0.0, 0.0, 1.0,   
                  0.0, 0.0, 0.0,   
                  0.0, 1.0, 0.0);  
    
    glPushMatrix();

    diffuse[0] = kd;
    diffuse[1] = kd;
    diffuse[2] = kd;
    diffuse[3] = 1.0f;
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);

    pedra1();
    pedra();
    plant();
    fish1();
    fish2();


    glColor3f(1.0,1.0,1.0);
    glPointSize(2.0);
    circle(30);
    circle(150);
    circle(300);
    circle(500);

    lightning();

    glFlush();
    glutSwapBuffers();
}


void keyboard (unsigned char key, int x, int y){
     switch (key){
        case '+' :
             if(kd<1.0)
                 kd+=0.1;
             break ;
        case '-' :
             if(kd>0.0)
                 kd-=0.1;
             break ;
        default:
             break;
     }
     glutPostRedisplay() ;
}


void teclasEspeciais(int key, int x, int y)
{
    if(key == GLUT_KEY_LEFT) {
        a=a-9.0;
    }
    if(key == GLUT_KEY_RIGHT) {
        a=a+9.0;
    }

    if(key == GLUT_KEY_DOWN) {
        b=b+10;
    }
    if(key == GLUT_KEY_UP) {
        b=b-10;
    }

    glutPostRedisplay();
}
   




