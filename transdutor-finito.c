#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0


char tempS[200];
char tempN[200];

/* Cabeçalhos */
void e0();
void e1();
void e2();

// delta1
void insereEmTempS();

// delta2
void anexaEmTempS();

// delta3
void finalizaTempS();

// delta4
void insereEmTempN();

// delta5
void anexaEmTempN();

// delta6
void finalizaTempN();

int main(int argc, char const *argv[]) { 

	// TODO: fazer palavra ser um input
	char palavra = "AB A 28 A28 A C";
	int posicaoAtual = 0;

	e0();

	return 0; 
}

void e0() {

	if (ehLetra(palavra)) {
		insereEmTempS(palavra, posicaoAtual);
		e1();
	} else if (ehNumero(palavra)) {
		e2();
	}
}

void e1() {

	if (ehLetra(palavra) || ehNumero(palavra)) {
		anexaEmTempS();
		e1();
	}
}

void e2() {

	if (ehNumero(palavra)) {
		anexaEmTempN();
		e2();
	}
}
