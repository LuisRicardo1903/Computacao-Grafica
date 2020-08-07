#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE 0x812F
#endif 

char title[] = "Prisma 3D";
GLfloat angleCube = 0.0f, fAspecto;
int ref = 15;
int opaco = GL_FALSE, cor = 1, mover = 0;
float angulo = 60;
float xpos = 0, ypos = 10, zpos = 0, xrot = 0, yrot = 0, angle=0.0;
float ultx, ulty, vel = 0;
float mult = 1;

void desenhaCubo(int pos, float c1, float c2, float c3) {
    glBegin(GL_QUADS);
    
    	//Verde Musgo
    	glPushMatrix();
    	glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);
        glPopMatrix();

		//Rosa
		glPushMatrix();
		glColor3f(1.0f,0.5f,1.0f);
        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
        glPopMatrix();

		//Azul
		glPushMatrix();
		glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
        glPopMatrix();
    	glEnd();
    
    	//Roxo
   		glBegin(GL_TRIANGLES);
    	glPushMatrix();
    	glColor3f(0.7f,0.3f,0.9f);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,0,-0.5);
        glPopMatrix();

		//Verde
		glPushMatrix();
		glColor3f(0.4f,0.9f,0.0f);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
        glPopMatrix();
    	glEnd();
}
void initGL() {
	glEnable(GL_BLEND);
   	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void camera(void) {
    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
    glTranslated(-xpos,-ypos,-zpos);
}

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    if(mover == 1) {
    	glRotatef(angleCube, 0.5f, 0.0f, 0.0f);
    }
    
    if(!opaco) {
       glEnable(GL_BLEND);     
       mover = 0;
       glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   	}
   	
    desenhaCubo(-10,0.0,0.0,1.0);
    glutSwapBuffers();
    glFlush();
    angleCube -= 0.05f + vel;
    angle++;
}

void EspecificaParametrosVisualizacao(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angulo,fAspecto,0.01,20000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluLookAt(0,1,1, 0,0,0, 0,1,0);
}	

void redesenha(GLsizei w, GLsizei h) {
    if ( h == 0 ) h = 1;
    glViewport(0, 0, w, h);
    fAspecto = (GLfloat)w/(GLfloat)h;
    EspecificaParametrosVisualizacao();
}

void GerenciaMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			if (angulo >= 10) angulo -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
			if (angulo <= 130) angulo += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void Teclado(unsigned char key, int x, int y) {
    if (key == 'w') {
	    float xrotrad, yrotrad;
	    yrotrad = (yrot / 180 * 3.141592654f);
	    xrotrad = (xrot / 180 * 3.141592654f); 
	    xpos += mult*float(sin(yrotrad)) ;
	    zpos -= mult*float(cos(yrotrad)) ;
	    ypos -= mult*float(sin(xrotrad)) ;
    }

    if (key == 's') {
	    float xrotrad, yrotrad;
	    yrotrad = (yrot / 180 * 3.141592654f);
	    xrotrad = (xrot / 180 * 3.141592654f); 
	    xpos -= mult*float(sin(yrotrad));
	    zpos += mult*float(cos(yrotrad));
	    ypos += mult*float(sin(xrotrad));
    }

    if (key == 'd') {
	    float yrotrad;
	    yrotrad = (yrot / 180 * 3.141592654f);
	    xpos += mult*float(cos(yrotrad)) * 0.2;
	    zpos += mult*float(sin(yrotrad)) * 0.2;
    }

    if (key == 'a') {
	    float yrotrad;
	    yrotrad = (yrot / 180 * 3.141592654f);
	    xpos -= mult*float(cos(yrotrad)) * 0.2;
	    zpos -= mult*float(sin(yrotrad)) * 0.2;
    }
    
	if(xpos > 100) xpos=100;
	if(xpos < -100) xpos=100;
	if(zpos > 100) zpos=100;
	if(zpos < -100) zpos=100;

    if (key == 27) exit(0);
}

void mouseMovement(int x, int y) {
    int diffx = x-ultx;
    int diffy = y-ulty;
    ultx = x;
    ulty = y;
    xrot += (float)diffy;
    yrot += (float)diffx;
}

int main(int argc, char** argv) {
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
   glutInitWindowSize(1440, 900);
   glutInitWindowPosition(50, 50);
   glutCreateWindow(title);
   glutDisplayFunc(desenha);
   glutIdleFunc(desenha); 
   glutReshapeFunc(redesenha);
   glutMouseFunc(GerenciaMouse);
   glutKeyboardFunc(Teclado);
   glutPassiveMotionFunc(mouseMovement);
   initGL();
   glutMainLoop();
   return 0;
}
