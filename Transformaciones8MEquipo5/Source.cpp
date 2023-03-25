#include <GL/glut.h>

// Definimos las variables que nos permitirán controlar la transformación
GLfloat angle = 0.0f;  // Ángulo de rotación
GLfloat xTrans = 0.0f; // Traslación en el eje x
GLfloat yTrans = 0.0f; // Traslación en el eje y
GLfloat scale = 0.5f;  // Escala

// Función que se encarga de dibujar la escena
void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Aplicamos la transformación
    glLoadIdentity();
    glTranslatef(xTrans, yTrans, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, scale);

    // Dibujamos un triángulo
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glEnd();

    glutSwapBuffers();
}

// Función que se encarga de actualizar la escena
void updateScene(int value)
{
    // Incrementamos el ángulo de rotación
    angle += 2.0f;
    if (angle > 360.0f)
    {
        angle -= 360.0f;
    }

    // Actualizamos la escena
    glutPostRedisplay();
    glutTimerFunc(25, updateScene, 0);
}

// Función principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Transformations");
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glutDisplayFunc(renderScene);
    glutTimerFunc(25, updateScene, 0);
    glutMainLoop();
    return 0;
}