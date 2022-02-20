#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int op = 1;

GLfloat light0_pos[] = {2.0f, 2.0f, 2.0f, 1.0f};
GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat black[] = {0.0f, 0.0f, 0.0f, 1.0f};

GLfloat kd = 0.0f;
GLfloat ks = 0.0f;

float angX = 0;
float angY = 0;
float angZ = 0;

int texNum = 0;

typedef struct BMPImagem
{
    int   width;
    int   height;
    char *data;
}BMPImage;

/* Qtd máxima de texturas a serem usadas no programa */
#define MAX_NO_TEXTURES 6

/* vetor com os números das texturas */
GLuint texture_id[MAX_NO_TEXTURES];

char* filenameArray[MAX_NO_TEXTURES] = {
        "earthTexture.bmp",
        "surface1.bmp",
        "surface2.bmp",
        "surface3.bmp",
        "surface4.bmp",
        "surface5.bmp"
};

GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;

//-----------------------------------------------------------------------------
// Name: getBitmapImageData()
// Desc: Simply image loader for 24 bit BMP files.
//-----------------------------------------------------------------------------
void getBitmapImageData( char *pFileName, BMPImage *pImage )
{
    FILE *pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
    int i;

    if( (pFile = fopen(pFileName, "rb") ) == NULL )
        printf("ERROR: getBitmapImageData - %s not found.\n", pFileName);

    // Seek forward to width and height info
    fseek( pFile, 18, SEEK_CUR );

    if( (i = fread(&pImage->width, 4, 1, pFile) ) != 1 )
        printf("ERROR: getBitmapImageData - Couldn't read width from %s.\n ", pFileName);

    if( (i = fread(&pImage->height, 4, 1, pFile) ) != 1 )
        printf("ERROR: getBitmapImageData - Couldn't read height from %s.\n ", pFileName);

    if( (fread(&nNumPlanes, 2, 1, pFile) ) != 1 )
        printf("ERROR: getBitmapImageData - Couldn't read plane count from %s.\n", pFileName);

    if( nNumPlanes != 1 )
        printf("ERROR: getBitmapImageData - Plane count from %s.\n ", pFileName);

    if( (i = fread(&nNumBPP, 2, 1, pFile)) != 1 )
        printf( "ERROR: getBitmapImageData - Couldn't read BPP from %s.\n ", pFileName);

    if( nNumBPP != 24 )
        printf("ERROR: getBitmapImageData - BPP from %s.\n ", pFileName);

    // Seek forward to image data
    fseek( pFile, 24, SEEK_CUR );

    // Calculate the image's total size in bytes. Note how we multiply the
    // result of (width * height) by 3. This is becuase a 24 bit color BMP
    // file will give you 3 bytes per pixel.
    int nTotalImagesize = (pImage->width * pImage->height) * 3;

    pImage->data = (char*) malloc( nTotalImagesize );

    if( (i = fread(pImage->data, nTotalImagesize, 1, pFile) ) != 1 )
        printf("ERROR: getBitmapImageData - Couldn't read image data from %s.\n ", pFileName);

    //
    // Finally, rearrange BGR to RGB
    //

    char charTemp;
    for( i = 0; i < nTotalImagesize; i += 3 )
    {
        charTemp = pImage->data[i];
        pImage->data[i] = pImage->data[i+2];
        pImage->data[i+2] = charTemp;
    }
}


/*Função para Carregar uma imagem .BMP */
void CarregaTexturas()
{
    BMPImage textura;

    /* Define quantas texturas serão usadas no programa  */
    glGenTextures(MAX_NO_TEXTURES, texture_id); /* 1 = uma textura; */
                                /* texture_id = vetor que guardas os números das texturas */

    int i;
    for ( i=0; i<MAX_NO_TEXTURES; i++ ) {
        getBitmapImageData( filenameArray[i], &textura);
        glBindTexture(GL_TEXTURE_2D, texture_id[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, textura.width, textura.height, 0, GL_RGB, GL_UNSIGNED_BYTE, textura.data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    }
}

/* **********************************************************************
  void initTexture(void)
        Define a textura a ser usada

 ********************************************************************** */
void initTexture (void)
{

    /* Habilita o uso de textura bidimensional  */
    glEnable ( GL_TEXTURE_2D );
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    /*Carrega os arquivos de textura */
  //  CarregaTextura("tunnelTexture.bmp");
    //CarregaTextura("tex2.bmp");
    CarregaTexturas();

}


void lightning(){
    glLightfv(GL_LIGHT0,GL_POSITION,light0_pos);
    glLightfv(GL_LIGHT0,GL_AMBIENT,black);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,white);
    glLightfv(GL_LIGHT0,GL_SPECULAR,white);

    //Fonte de Luz Direcional - Efeito de Holofote
    GLfloat light1_pos[] = {-2.0, 0.0, 0.0f, 1.0f};
    glLightfv(GL_LIGHT1,GL_POSITION,light1_pos);
    glLightfv(GL_LIGHT1,GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1,GL_SPECULAR, white);
    GLfloat direction[] = {1.0f, 0.0f, 0.0f};
    glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,direction);       //vetor direção
    glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,30.0f);               //espalhamento angular
    glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,0.5f);              //atenuação angular

    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}


void init(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(1.0, 1.0, 1.0,   //posição da câmera
              0.0, 0.0, 0.0,   //para onde a câmera aponta
              0.0, 1.0, 0.0);  //vetor view-up

    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
    glLoadIdentity(); //carrega a matrix de identidade
    glOrtho(-1.0, 1.0, -1.0, 1.0, 0.0, 8.0); //define uma projeção ortogonal
    lightning();
    glPushMatrix();
}

void sweep(){
    double theta = 0.0;
    double step;
    int n = 20;
    
    glBindTexture(GL_TEXTURE_2D, texture_id[texNum]);
    
    step = (2*M_PI)/n;
    for(int i=0;i<n;i++){
        glBegin(GL_QUADS);
            glNormal3f(0.5*cos(theta),0.75,0.5*sin(theta));
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(0.5*cos(theta),0.75,0.5*sin(theta));
            glNormal3f(0.5*cos(theta+step),0.75,0.5*sin(theta+step));
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(0.5*cos(theta+step),0.75,0.5*sin(theta+step));
            glNormal3f(0.05*cos(theta+step),0.0,0.05*sin(theta+step));
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(0.05*cos(theta+step),0.0,0.05*sin(theta+step));
            glNormal3f(0.05*cos(theta),0.0,0.05*sin(theta));
            glTexCoord2f(0.0f,1.0f);
            glVertex3f(0.05*cos(theta),0.0,0.05*sin(theta));
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(0.05*cos(theta),0.0,0.05*sin(theta));
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(0.05*cos(theta),0.0,0.05*sin(theta));
            glNormal3f(0.05*cos(theta+step),0.0,0.05*sin(theta+step));
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(0.05*cos(theta+step),0.0,0.05*sin(theta+step));
            glNormal3f(0.05*cos(theta+step),-0.75,0.05*sin(theta+step));
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(0.05*cos(theta+step),-0.75,0.05*sin(theta+step));
            glNormal3f(0.05*cos(theta),-0.75,0.05*sin(theta));
            glTexCoord2f(0.0f,1.0f);
            glVertex3f(0.05*cos(theta),-0.75,0.05*sin(theta));
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(0.05*cos(theta),-0.75,0.05*sin(theta));
            glTexCoord2f(0.0f,0.0f);
            glVertex3f(0.05*cos(theta),-0.75,0.05*sin(theta));
            glNormal3f(0.05*cos(theta+step),-0.75,0.05*sin(theta+step));
            glTexCoord2f(1.0f,0.0f);
            glVertex3f(0.05*cos(theta+step),-0.75,0.05*sin(theta+step));
            glNormal3f(0.5*cos(theta+step),-0.75,0.5*sin(theta+step));
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(0.5*cos(theta+step),-0.75,0.5*sin(theta+step));
            glNormal3f(0.5*cos(theta),-0.75,0.5*sin(theta));
            glTexCoord2f(1.0f,1.0f);
            glVertex3f(0.5*cos(theta),-0.75,0.5*sin(theta));
        glEnd();
        theta+=step;
    }
}


void displayFunc() {
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat ns;
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //limpa o buffer
    glMatrixMode(GL_MODELVIEW); //define que a matrix é a de modelo
    diffuse[0] = kd;
    diffuse[1] = kd;
    diffuse[2] = kd;
    diffuse[3] = 1.0f;
    specular[0] = ks;
    specular[1] = ks;
    specular[2] = ks;
    specular[3] = 1.0f;
    ns = 50.0f;
    glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,specular);
    glMaterialf(GL_FRONT, GL_SHININESS, ns);

    glPopMatrix();
    glPushMatrix();
    glRotatef(angX,1,0,0);
    glRotatef(angY,0,1,0);
    glRotatef(angZ,0,0,1);
    sweep();
    glFlush();
}

void keyboardSpecial(int key, int x, int y){
     switch (key){
        case GLUT_KEY_UP :
             if(kd<1.0)
                 kd+=0.1;
             if(ks<1.0)
                 ks+=0.1;
             break ;
        case GLUT_KEY_DOWN :
             if(kd>0.0)
                 kd-=0.1;
             if(ks>0.0)
                 ks-=0.1;
             break ;
        default:
             break;
     }
     glutPostRedisplay() ;
}

void keyboard(unsigned char key, int x, int y){
     switch (key){
        case 'x' :
             angX+=15;
             break ;
        case 'y' :
             angY+=15;
             break ;
         case 'z' :
             angZ+=15;
             break ;
         case '0':
             texNum = 0;
             break;
         case '1':
             texNum = 1;
             break;
         case '2':
             texNum = 2;
             break;
         case '3':
             texNum = 3;
             break;
         case '4':
             texNum = 4;
             break;
         case '5':
             texNum = 5;
             break;
        default:
             break;
     }
     glutPostRedisplay() ;
}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Superquádricas");
    glutDisplayFunc(displayFunc);
    glutSpecialFunc(keyboardSpecial);
    glutKeyboardFunc(keyboard);
    init();
    initTexture();
    glutMainLoop();
    return 0;
}