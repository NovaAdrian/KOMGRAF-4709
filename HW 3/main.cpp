#include <GL/freeglut.h>
#include <iostream>

int X1 = 12, Y1 = 1; // Koordinat titik A
int X2 = 2, Y2 = 8;  // Koordinat titik B

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Warna latar belakang
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 20, 0, 20, -1.0, 1.0); // Rentang tampilan (sesuaikan sesuai koordinat Anda)
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Warna garis (hitam)

    // Algoritma DDA untuk menggambar garis antara dua titik A dan B
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    float X = X1;
    float Y = Y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(X, Y);
        X += Xinc;
        Y += Yinc;
    }
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Tambahkan GLUT_DEPTH untuk mode kedalaman
    glutInitWindowSize(500, 500);                             // Ukuran jendela tampilan
    glutInitWindowPosition(100, 100);                         // Posisi jendela tampilan
    glutCreateWindow("DDA Line Drawing ");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
