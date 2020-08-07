#include <stdlib.h>
#include <GL/glut.h>

float factor = 1;
void Inicializa(void)
{
	glClearColor(1,1,1,0);
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Evita a divisao por zero
	if(h == 0) h = 1;
                           
	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	if (w <= h) 
		gluOrtho2D (-5.0f, 5.0f, -5.0f*h/w, 5.0f*h/w);
	else 
		gluOrtho2D (-5.0f*w/h, 5.0f*w/h, -5.0f, 5.0f);
}

void Desenha(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
	
   glColor3f(1.0f, 0.0f, 0.0f);
   //glScalef(1.0*factor,1.0*factor,1.0);
   glPushMatrix();
//	glTranslatef(1.0,-5.0+factor,1.0);  
	glTranslatef(1.0+factor,1.0,1.0); 
   glBegin(GL_QUADS);
      glVertex2f(-0.5f,-0.5f);
      glVertex2f(0.5f,-0.5f);
      glVertex2f(0.5f,0.5f);
      glVertex2f(-0.5f,0.5f);
   glEnd();
   glPopMatrix();
   glFlush();
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 27:     // ESC key
         exit(0);
         break;
      case 'd':
         factor++;
         glutPostRedisplay(); //manda o m?todo "Desenha" ser executado
         break;
      case 'a':
         factor--;
         glutPostRedisplay(); //manda o m?todo "Desenha" ser executado
         break;
		case 'w':
   }
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //buffer simples
	glutInitWindowSize(400,400); //define o tamanho da janela
	glutInitWindowPosition(50, 50); // posiciona a janela, cuja origem ? no canto superior esquerdo
	glutCreateWindow("Primeiro Programa"); //cria uma janela com o t?tulo especificado
	glutDisplayFunc(Desenha); //registra a fun??o callback de redesenhenho
	glutKeyboardFunc(keyboard); //define a fun??o de teclado
	Inicializa(); //inicializa??o pr?pria desse programa
		// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(AlteraTamanhoJanela);
	glutMainLoop(); // entra no la?o de processamento de eventos
	return 0;
}
