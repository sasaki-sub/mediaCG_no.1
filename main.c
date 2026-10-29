#include <GL/glut.h>

#ifdef _MSC_VER  // Windowsならば
#define _USE_MATH_DEFINES
#endif
#include <math.h>

void circle(float r, float r2, float X, float Y)
{
  int n = 100;
  float x, y;
  double angle;

  glBegin(GL_POLYGON);
  for (int i = 0; i < n; i++) {
    angle = (double)2.0 * M_PI * i / n;
    x = r * cos(2.0 * M_PI * angle) + X;
    y = r2 * sin(2.0 * M_PI * angle) + Y;
    glVertex3f(x, y, 0.0);
  }
  glEnd();
}

void display(void)
{
  /* 変更なし */
}

void resize(int w, int h)
{
  /* ウィンドウ全体をビューポートにする */
  glViewport(0, 0, w, h);

  /* 変換行列の初期化 */
  glLoadIdentity();

  /* スクリーン上の表示領域をビューポートの大きさに比例させる */
  glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}


void init(void)
{
  glClearColor(0.0, 0.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  init();
  glutMainLoop();
  return 0;
}