
#include <GL/glut.h>

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
      glBegin(GL_LINES);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.85, 0.25, 0.0);
    glEnd();
    glFlush();
}

void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("OpenGL triangle Lesson");
    Initialize();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}