#include <stdlib.h>
#include <GL/glut.h>

// Fun��o callback de redesenho da janela de visualiza��o
void Desenha(void)
{
	GLint width;
   
	// Limpa a janela de visualiza��o com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);
    
	// Especifica a cor preta - Voc� pode trocar de cor, use: RGB
	glColor3f(0.0f, 0.0f, 0.0f); 

	// Especifica a espessura da linha
	glLineWidth(2);
    
	// Desenha linhas de espessura 5 e cor azul
	// na parte inferior da janela
	// Desenha as linhas dos gr�ficos - x e y
	
    
    
  glBegin(GL_LINES);
  glVertex2i(40,0);
  glVertex2i(40,0);
  glEnd();
	//especifica o tamanho do ponto
    	glPointSize(4);

    	//especifica a cor do ponto
    	
    	
    	
    	
    	//Fundo Azul
    	glColor3f(0.0f, 0.8f, 1.0f);
    	glBegin(GL_QUADS);
			glVertex2i(50,-60);
        	glVertex2i(-50,-60);
        	glVertex2i(-50,60);
        	glVertex2i(50,60);
		glEnd();
    	
    	//Fundo Verde
    	glColor3f(0.4f, 0.8f, 0.1f); 
    	glBegin(GL_QUADS);
    	    glVertex2i(50,-50);
        	glVertex2i(-50,-50);
        	glVertex2i(-50,20);
        	glVertex2i(50,20);
    	glEnd();
    	
    	//Quadrado Menor 
    	glColor3f(0.0f, 1.0f, 0.6f);
    	glBegin(GL_QUADS);
			glVertex2i(-25,-25);
        	glVertex2i(0,-25);
        	glVertex2i(0,0);
        	glVertex2i(-25,0);
		glEnd();
		
		//Triangulo		
		glColor3f(0.4f, 0.0f, 0.0f);
		glBegin(GL_TRIANGLES);
			glVertex2i(-25,0);
        	glVertex2i(0,0);
        	glVertex2i(-13.5,18);
        glEnd();
        
        //Teto
        glColor3f(0.4f, 0.0f, 0.0f);
    	glBegin(GL_QUADS);
			glVertex2i(0,0);
        	glVertex2i(25,15);
        	glVertex2i(15,30);
        	glVertex2i(-13.5,18);
		glEnd();
		
		//Quadrado Maior (Lado da Casa)
		glColor3f(0.0f, 1.0f, 0.6f);
    	glBegin(GL_QUADS);
			glVertex2i(0,-25);
        	glVertex2i(25,-5);
        	glVertex2i(25,15);
        	glVertex2i(0,0);
		glEnd();
		
		//Porta
		glColor3f(0.5f, 0.0f, 0.0f);
    	glBegin(GL_QUADS);
			glVertex2i(-17,-25);
        	glVertex2i(-10,-25);
        	glVertex2i(-10,-13);
        	glVertex2i(-17,-13);
		glEnd();
		
		//Janela
		glColor3f(0.0f, 0.2f, 0.5f);
    	glBegin(GL_QUADS);
			glVertex2i(5,-15);
        	glVertex2i(20,-4);
        	glVertex2i(20,7);
        	glVertex2i(5,-3);
		glEnd();
		
		
		//Sombra
		glColor3f(0.2f, 0.3f, 0.0f);
    	glBegin(GL_QUADS);
			glVertex2i(0,-25);
        	glVertex2i(50,-13);
        	glVertex2i(50,3);
        	glVertex2i(25,-5);
		glEnd();
		
		//Linhas
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex2i(0,0);
			glVertex2i(-25, 0);
			glVertex2i(0,0);
			glVertex2i(0, -25);
			glVertex2i(0,-25);
			glVertex2i(-25, -25);
			glVertex2i(-25,-25);
			glVertex2i(-25, 0);
		glEnd();
		
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
			glVertex2i(-25,0);
        	glVertex2i(0,0);
        	glVertex2i(-13.5,18);
        	glEnd();
		
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
			glVertex2i(-17,-25);
        	glVertex2i(-10,-25);
        	glVertex2i(-10,-13);
        	glVertex2i(-17,-13);
        glEnd();
		
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
			glVertex2i(5,-15);
        	glVertex2i(20,-4);
        	glVertex2i(20,7);
        	glVertex2i(5,-3);
        glEnd();
        
        glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
			glVertex2i(0,-25);
        	glVertex2i(25,-5);
        	glVertex2i(25,15);
        	glVertex2i(0,0);
        glEnd();
        
        glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
			glVertex2i(0,0);
        	glVertex2i(25,15);
        	glVertex2i(15,30);
        	glVertex2i(-13.5,18);
        glEnd();
        	
	// Executa os comandos OpenGL 
	glFlush();
}

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Evita a divisao por zero
	if(h == 0) h = 1;
                           
	// Especifica as dimens�es da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de sele��o (esquerda, direita, inferior, 
	// superior) mantendo a propor��o com a janela de visualiza��o
	if (w <= h) 
		gluOrtho2D (-50.0f, 50.0f, -50.0f*h/w, 50.0f*h/w);
	else 
		gluOrtho2D (-50.0f*w/h, 50.0f*w/h, -50.0f, 50.0f);
}

// Fun��o callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

// Fun��o respons�vel por inicializar par�metros e vari�veis
void Inicializa (void)
{   
	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Programa Principal 
int main(void)
{
	// Define do modo de opera��o da GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
	// Especifica a posi��o inicial da janela GLUT
	glutInitWindowPosition(5,5); 
    
	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(450,450); 
    
	// Cria a janela passando como argumento o t�tulo da mesma
	glutCreateWindow("Casinha 2D Top das Gal�xia");
    
	// Registra a fun��o callback de redesenho da janela de visualiza��o
	glutDisplayFunc(Desenha);
    
	// Registra a fun��o callback de redimensionamento da janela de visualiza��o
	glutReshapeFunc(AlteraTamanhoJanela);

	// Registra a fun��o callback para tratamento das teclas ASCII
	glutKeyboardFunc (Teclado);
    
	// Chama a fun��o respons�vel por fazer as inicializa��es 
	Inicializa();
    
	// Inicia o processamento e aguarda intera��es do usu�rio
	glutMainLoop();
    
	return 0;
}
