/***************************************

Sistema
sistema.cpp

Prof: Gustavo Vinhal

Alunos: GIULIANNO G LATORRACA
		VINICIUS HENRIQUE DA SILVA SOUZA

****************************************/

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 3;



void timer( int value )
{
    if( zRotated > 360.0 )
    {
        zRotated -= 360.0 * floor( zRotated / 360.0 ); 
    }

    if( yRotated > 360.0 )
    {
        yRotated -= 360.0 * floor( yRotated / 360.0 ); 
    }

    zRotated += 1.0;
    yRotated += 1.0;

    glutTimerFunc( 16, timer, 0 );
    glutPostRedisplay();
}

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, 640, 0, 480, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glPushMatrix();
    {
        glColor3f( 0.6, 0.6, 0.6 );
        glPointSize( 3 );
        glBegin( GL_POINTS );
        for( int i = 1; i < 100; i++ )
        {
            int x = rand() % 640;
            int y = rand() % 480;
            glVertex2i( x, y );
        }
        glEnd();
    }
    glPopMatrix();


   
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    gluPerspective( 20.0, w / h, 0.1, 80.0 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 0.0, 0.0, -40.0 );

    glPushMatrix();
    {
        glutSolidSphere( radius, 25, 25 );
       
    }
    glPopMatrix();

    glPushMatrix();
    {
        glRotatef( yRotated, 0.0, 2.0, 0.0 );
        glTranslatef( 5.0, 0.0, 0.0 );
        glutSolidSphere( radius / 6, 25, 25 );
       
    }
    glPopMatrix();

    glutSwapBuffers();
}

int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize( 1000, 600 );
    glutCreateWindow( "sistema" );

    xRotated = yRotated = zRotated = 0.0;

    glutDisplayFunc( display );
    glutTimerFunc( 0, timer, 0 );
    glutMainLoop();
    return 0;
}
