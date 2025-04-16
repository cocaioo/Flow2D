#ifdef __APPLE__ // MacOS
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else // Windows e Linux
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <cstdlib>
//Forma primitiva do Circulo para Flow2D
#include "circuloFlow.h"
#include <stdbool.h>

//Variaveis Globais usadas para definicao de cores
float R,G,B;

// Declaracoes antecipadas (forward) de funcoes para as funcoes callback do OpenGL
void init(void);
void reshape(int w, int h);
void display(void);

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0); //Limpa a tela com a cor branca;
    R = 0.0;
    G = 0.0;
    B = 0.0;
}

void reshape(int w, int h){
	// Reinicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    // Definindo o Viewport para o tamanho da janela
	glViewport(0, 0, w, h);

    glOrtho (0, 800, 0, 600, -1 ,1);  // Define o volume de projecao ortografica;
                                      // Nesse caso, o ponto (0,0,0) se encontra no
                                      // canto inferior esquerdo da tela e o viewport
                                      // tem 0 a 512 pixel no eixo x, 0 a 512 pixel no
                                      // eixo y. Como sera trabalhado imagens 2D definimos
                                      // o eixo z com tamanho -1 a 1;

//   glOrtho (-256, 256, -256, 256, -1 ,1); // Nesse caso, continuamos com 512 pixels, porem o
                                            // centro dos eixos passa a se localizar no centro
                                            // da tela.

//   glOrtho (-(w/2), (w/2),-(h/2),(h/2), -1 ,1);   // Nesse caso, ficamos com a quantidade de pixels variavel,
                                                    // dependente da largura e altura da janela, e o
                                                    // centro dos eixos continua a se localizar no centro
                                                    // da tela.
    
   // muda para o modo GL_MODELVIEW (nao pretendemos alterar a projecao
   // quando estivermos desenhando na tela)
	glMatrixMode(GL_MODELVIEW);
}

void desenhaRetangulo(float x, float y, float comprimento, float largura){
	glBegin(GL_QUADS);
		glVertex2f(x,y); //Ponto inicial (inferior esquerdo)
		glVertex2f(x + comprimento,y); // ponto inferior direito
		glVertex2f(x + comprimento,y + largura);
		glVertex2f(x,y + largura);
	glEnd();
}

void desenhaTriangulo(float x, float y, float lado){
	glBegin(GL_TRIANGLES);
		glVertex2f(x, y);                         // vértice inferior esquerdo
		glVertex2f(x + lado, y);                  // vértice inferior direito
		glVertex2f(x + lado / 2, y + (lado * sqrt(3.0f) / 2)); // vértice superior (equilátero)
	glEnd();
}


void desenhaF(){
	glColor3f(0.0f,0.0f,0.0f);
	
	desenhaRetangulo(295,300, 100, 20 ); //Parte de cima do F
	
	desenhaRetangulo(310, 220, 20, 80 ); //Parte que liga
	
	desenhaRetangulo(300, 250, 70,20); //Parte do meio

	
}

void desenhaL(){
	glColor3f(0.0f,0.0f,0.0f);
	
	desenhaRetangulo(310, 220, 20.0f, 100.0f );
}

void desenhaO() {
    glPushMatrix();
        // Círculo preto preenchido
        glTranslatef(256.0f, 256.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.0f);
        desenhaCirculo(40.0f, 200, true);
    glPopMatrix();

    glPushMatrix();
        // Círculo branco, deslocado um pouco para a esquerda
        glTranslatef(246.0f, 256.0f, 0.0f); // 10 unidades à esquerda
        glColor3f(1.0f, 1.0f, 1.0f);
        desenhaCirculo(20.0f, 200, true);
    glPopMatrix();
}

void desenhaW(){
	glPushMatrix();
		glColor3f(0.0f,0.0f,0.0f);
		desenhaTriangulo(256.0f,256.0f, 100.0f);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(1.0f,1.0f,1.0f);
    	desenhaTriangulo(285.f,256.f, 40.0f);
 	glPopMatrix();
 	
 	glPushMatrix();
 		glColor3f(0.0f,0.0f,0.0f);
 		desenhaRetangulo(256.0f,256.0f, 25, 85);
    glPopMatrix();
    
    glPushMatrix();
    	glColor3f(0.0f,0.0f,0.0f);
		desenhaRetangulo(332.0f,256.0f,25,85);
}

void desenhaFlow() {
    glPushMatrix();
        glTranslatef(250.0f, 40.0f, 0.0f); // Posição inicial do "F"
        desenhaF();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(355.0f, 40.0f, 0.0f); // "L" à direita do F
        desenhaL();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(480.0f, 40.0f, 0.0f); // "O" à direita do L
        desenhaO();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(530.0f, 0.0f, 0.0f); // "W" à direita do O
        desenhaW();
    glPopMatrix();
}

void desenhaGato(){
		// Orelha direita com rotação suave
	glPushMatrix();
		glTranslatef(380.f, 450.0f, 0.0f); // move o sistema para a base da orelha
		glRotatef(-30.0f, 0.0f, 0.0f, 1.0f); // gira levemente no plano 2D
		glColor3f(0.0f, 0.0f, 0.0f);
		desenhaTriangulo(0.f, 0.0f, 250.0f); // desenha com base no novo centro
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(420.f, 450.0f, 0.0f); // move o sistema para a base da orelha
		glRotatef(-30.0f, 0.0f, 0.0f, 1.0f); // gira levemente no plano 2D
		glColor3f(0.396f, 0.200f, 0.196f);
		desenhaTriangulo(0.f, 0.0f, 180.0f); // desenha com base no novo centro
	glPopMatrix();
	
	
		// Orelha esquerda com rotação suave
	glPushMatrix();
		glTranslatef(210.f, 320.0f, 0.0f); // move o sistema para a base da orelha
		glRotatef(30.0f, 0.0f, 0.0f, 1.0f); // gira levemente no plano 2D
		glColor3f(0.0f, 0.0f, 0.0f);
		desenhaTriangulo(0.f, 0.0f, 250.0f); // desenha com base no novo centro
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(232.f, 355.0f, 0.0f); // move o sistema para a base da orelha
		glRotatef(30.0f, 0.0f, 0.0f, 1.0f); // gira levemente no plano 2D
		glColor3f(0.396f, 0.200f, 0.196f);
		desenhaTriangulo(0.f, 0.0f, 180.0f); // desenha com base no novo centro
	glPopMatrix();
	
	//Forma da cabeça do gato
	glPushMatrix();
		glTranslatef(400.0f,300.0f,0.0f);
		glColor3f(0.102f, 0.102f, 0.102f);
		desenhaCirculo(200.0f,80, true);
    glPopMatrix();
    
    //Nariz
    glPushMatrix();
    	glColor3f(0.396f, 0.200f, 0.196f);
    	desenhaRetangulo(375.0f,200.0f, 60.0f,25.0f);
        desenhaRetangulo(392.0f,172.0f,25.0f,30.0f);
 	glPopMatrix();
 	
 	//Narina esquerda
 	glPushMatrix();
 		glColor3f(0.0f,0.0f,0.0f);
 		glTranslatef(390.0f,195.0f,0.0f);
    	desenhaCirculo(7.0f,100,true);
 	glPopMatrix();
 	
 	//Narina Direita
 	glPushMatrix();
 		glColor3f(0.0f,0.0f,0.0f);
 		glTranslatef(419.0f,195.0f,0.0f);
    	desenhaCirculo(7.0f,100,true);
 	glPopMatrix();
 	
 	
    
    //Olho esquerdo
    glPushMatrix();
		glTranslatef(300.0f,300.0f,0.0f);
		glColor3f(0.643f, 0.514f, 0.314f);
		desenhaCirculo(60.0f,100, true);
    glPopMatrix();
    
	//Olho direito
	glPushMatrix();
		glTranslatef(500.0f,300.0f,0.0f);
		glColor3f(0.643f, 0.514f, 0.314f);
		desenhaCirculo(60.0f,100, true);
    glPopMatrix();	

    //Pupila esquerda
    glPushMatrix();
    	glTranslatef(310.0f,295.0f,0.0f);
    	glColor3f(0.0f,0.0f,0.0f);
    	desenhaCirculo(48.0f, 100, true);
 	glPopMatrix();
 	
 	//Pupila direita
    glPushMatrix();
    	glTranslatef(490.0f,295.0f,0.0f);
    	glColor3f(0.0f,0.0f,0.0f);
    	desenhaCirculo(48.0f, 100, true);
 	glPopMatrix();
 // 	
 	//Sinais brancos olho direito
 	glPushMatrix();
 		glTranslatef(498.0f,295.0f,0.0f);
 	    glColor3f(1.0f,1.0f,1.0f);
    	desenhaCirculo(5.0f, 100, true);
 	glPopMatrix();
 	
 	glPushMatrix();
 		glTranslatef(515.0f,310.0f,0.0f);
 	    glColor3f(1.0f,1.0f,1.0f);
    	desenhaCirculo(5.0f, 100, true);
 	glPopMatrix();
 	
 	//Sinais brancos olho esquerdo
	glPushMatrix();
		glTranslatef(302.0f,295.0f,0.0f); 
		glColor3f(1.0f,1.0f,1.0f);
		desenhaCirculo(5.0f, 100, true);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(285.0f,310.0f,0.0f); 
		glColor3f(1.0f,1.0f,1.0f);
		desenhaCirculo(5.0f, 100, true);
	glPopMatrix();
	
}



void display(void){
	//Limpa o Buffer de Cores e reinicia a matriz
    glClear(GL_COLOR_BUFFER_BIT); 
	glLoadIdentity();
	
	//Desenhar o Gato
	glPushMatrix();
		glScalef(0.5f,0.5f, 0.0f);
		glTranslatef(30.0f,280.0f,0.0f);
		desenhaGato();
    glPopMatrix();
    
    //Desenha nome Flow
	glPushMatrix();
		glScalef(1.0f, 1.0f, 0.0f);
		glTranslatef(-180.0f, -30.0f,0.0f);
		desenhaFlow();
    glPopMatrix();
    

    glFlush(); // manda o OpenGl renderizar as primitivas

}


int main(int argc, char** argv){
    glutInit(&argc, argv); // Passagens de parametros C para o glut
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // Selecao do Modo do Display e do Sistema de cor utilizado
    glutInitWindowSize (800, 600);  // Tamanho da janela do OpenGL (era 512x512)
    glutInitWindowPosition (100, 100); //Posicao inicial da janela do OpenGL
    glutCreateWindow ("Computcao Grafica: Flow2D"); // Da nome para uma janela OpenGL
    init(); // Chama a funcao init();
    glutReshapeFunc(reshape); //funcao callback para redesenhar a tela
    glutDisplayFunc(display); //funcao callback de desenho
    glutMainLoop(); // executa o loop do OpenGL
    return EXIT_SUCCESS; // retorna 0 para o tipo inteiro da funcao main()
}