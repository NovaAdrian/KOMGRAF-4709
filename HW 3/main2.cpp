#include <GL/freeglut.h>

int x1 = 2, y1 = 12; // Koordinat awal
int x2 = 4, y2 = 10; // Koordinat akhir

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Warna putih
    glBegin(GL_LINES);
    glVertex2f(x1 / 12.0, y1 / 12.0); // Normalisasi koordinat
    glVertex2f(x2 / 12.0, y2 / 12.0);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");
    glClearColor(0.0, 0.0, 0.0, 1.0); // Warna latar hitam
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
