#include <stdlib.h>
#include <GL/glut.h>
int car=0;
int pis=0;
int seg = 0;
float tg=1;

void des_Cen(){
	//Fundo Verde
	 glColor3f(0,1,0); 
	glBegin(GL_QUADS); 
	  glVertex2f(-50, 50);
      glVertex2f(-50, -50);
      glVertex2f(50, -50);
      glVertex2f(50, 50);	
    glEnd();
    
    //Fundo Azul
	glBegin(GL_QUADS); 
	  glColor3f(0,0,1); 
	  glVertex2f(-50, 50);
      glVertex2f(-50, 20);
      glVertex2f(50, 20);
      glVertex2f(50, 50);	
    glEnd();
	}
	
void des_pist(){
	
	//Pista
	glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-8, 20);
    glVertex2f(-30, -50);
    glVertex2f(30, -50);
    glVertex2f(8, 20);
	glEnd();
	glLineWidth(3);
	glPopMatrix();
	
	//Linha lado pista
	glPushMatrix();
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(-8, 20);
	glVertex2f(-30, -50);
	glVertex2f(30, -50);
	glVertex2f(8, 20);
	glVertex2f (0,-50 );
	glPopMatrix();
	
	//Linha centro
	glPushMatrix();
	glColor3f(0.99,0.91,0.06); 
	glVertex2f (0,-40);
	glVertex2f (0,-30);
	glVertex2f (0,-20);
	glVertex2f (0,-10);
	glVertex2f (0,0);
	glVertex2f (0,10);
	glVertex2f (0,20);
	glEnd();
	glPopMatrix();
	}
	
void des_pist_2(){
	
	//Pista
	glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-8, 20);
    glVertex2f(-30, -50);
    glVertex2f(30, -50);
    glVertex2f(8, 20);
	glEnd();
	glLineWidth(3);
	glPopMatrix();
	
	//Linha lado pista
	glPushMatrix();
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(-8, 20);
	glVertex2f(-30, -50);
	glVertex2f(30, -50);
	glVertex2f(8, 20);
	glPopMatrix();
	
	//Linha centro
	glPushMatrix();
	glColor3f(0.99,0.91,0.06); 
	glVertex2f (0,-40);
	glVertex2f (0,-30);
	glVertex2f (0,-20);
	glVertex2f (0,-10);
	glVertex2f (0,0);
	glVertex2f (0,10);
	glEnd();
	glPopMatrix();
	
	glFlush();
	}
	
void des_pist_dir(){
	
	//Pista
	glPushMatrix();	
	glColor3f(0,0,0); 
    glBegin(GL_QUADS);
    glVertex2f(-5, -50);
    glVertex2f(45, -50);
    glVertex2f(48, 20);
    glVertex2f(15, 20);	
	glEnd();
	glLineWidth(3);
	glPopMatrix();
	
	//Linha lado pista
	glPushMatrix();	
	glColor3f(1,1,1); 
	glBegin(GL_LINES);
	glVertex2f(15, 20);
	glVertex2f(-5, -50);
	glVertex2f(45, -50);
	glVertex2f(48, 20);
	glPopMatrix();
	glPopMatrix();
	
	//Linhas centro
	glPushMatrix();
	glColor3f(0.99,0.91,0.06);
	glVertex2f (19,-40);
	glVertex2f (21,-30);
	glVertex2f (23,-20);
	glVertex2f (25,-10);
	glVertex2f (27,0);
	glVertex2f (29,10);
	glEnd();
	glPopMatrix();
	}
	
void des_pist_esq(){
	
	//Pista
	glPushMatrix();
	glColor3f(0,0,0); 
    glBegin(GL_QUADS);
    glVertex2f(5, -50);
    glVertex2f(-40, -50);
    glVertex2f(-35, 20);
    glVertex2f(-5, 20);	
	glEnd();
	glPopMatrix();
	
	//Linha lado pista
	glPushMatrix();
	glLineWidth(3);
	glColor3f(1,1,1); 
	glBegin(GL_LINES);
	glVertex2f(5, -50);
	glVertex2f(-5, 20);
	glVertex2f(-35, 20);
	glVertex2f(-40, -50);
	glPopMatrix();
	
	//Linhas Centro
	glPushMatrix();
	glColor3f(0.99,0.91,0.06);
	glVertex2f (-14.5,-40);
	glVertex2f (-16,-30);
	glVertex2f (-18,-20);
	glVertex2f (-19.5,-10);
	glVertex2f (-20.5,0);
	glVertex2f (-22,10);
	glEnd();
	glPopMatrix();
	}
	
void des_carro(){
	
	//Roda direita cima
	glPushMatrix();
	glColor3f(0.43,0.21,0.1);
    glBegin(GL_QUADS);
    glVertex2f(5+car, -27);
    glVertex2f(5+car, -31);
    glVertex2f(3+car, -31);
    glVertex2f(3+car, -27);	
	glEnd();
	glPopMatrix();
	
	//Roda direita baixo
	glPushMatrix();
	glColor3f(0.43,0.21,0.1);
	glBegin(GL_QUADS);
    glVertex2f(3+car, -34);
    glVertex2f(3+car, -38);
    glVertex2f(5+car, -38);
    glVertex2f(5+car, -34);	
	glEnd();
	glPopMatrix();
	
	//Roda esquerda cima
	glPushMatrix();
	glColor3f(0.43,0.21,0.1);
	glBegin(GL_QUADS);
	glVertex2f(-3+car, -27);
    glVertex2f(-3+car, -31);
    glVertex2f(-5+car, -31);
    glVertex2f(-5+car, -27);	
	glEnd();
	glPopMatrix();
	
	//Roda esquerda baixo
	glPushMatrix();
	glColor3f(0.43,0.21,0.1);
	glBegin(GL_QUADS);
    glVertex2f(-3+car, -34);
    glVertex2f(-3+car, -38);
    glVertex2f(-5+car, -38);
    glVertex2f(-5+car, -34);	
	glEnd();
	glPopMatrix();
	
	//Carro
	glPushMatrix();
	glColor3f(1,0.1,0);
	glBegin(GL_QUADS);
	glVertex2f(-4+car, -25);
    glVertex2f(-4+car, -40);
    glVertex2f(+4+car, -40);
    glVertex2f(+4+car, -25);	
	glEnd();
	glPopMatrix();
	}
      
 void keyboard(int key, int x, int y) {
   switch (key) {
      case GLUT_KEY_LEFT:
        car--;
         glutPostRedisplay();
         break;
      case GLUT_KEY_RIGHT:
         car++;
         glutPostRedisplay();
         break;
   }
}

void Desenha(void){
	
	GLint width;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f); 
	glLineWidth(2);
	des_Cen();
	
	if(pis%2==0){
		des_pist();
	}
	else if (pis%3==0){
		des_pist_dir();
	}
	else{
		des_pist_esq();
	}
    des_carro();
	glFlush();
}

void Timer(int value) {
	
   if(seg==1){
       tg = tg*2;
       seg=0;   
	   pis++;      
   }
   else{
       tg = tg/2;
       seg=1;
       pis+2;
   }
   glutPostRedisplay();
   glutTimerFunc(2000, Timer, 0);
}

	

void AlteraTamanhoJanela(GLsizei w, GLsizei h){
	if(h == 0) h = 1;
                           
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) 
		gluOrtho2D (-50.0f, 50.0f, -50.0f*h/w, 50.0f*h/w);
	else 
		gluOrtho2D (-50.0f*w/h, 50.0f*w/h, -50.0f, 50.0f);
}

void Inicializa (void){   
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

int main(void){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
	glutInitWindowPosition(5,5); 
    
	glutInitWindowSize(450,450); 
    
	glutCreateWindow("Desenho de Linhas");
    
	glutDisplayFunc(Desenha);
	
	glutSpecialFunc(keyboard);
    
	glutReshapeFunc(AlteraTamanhoJanela);
	glutTimerFunc(1000, Timer, 0);
    
	Inicializa();
    
	glutMainLoop();
	
	return 0;
}
