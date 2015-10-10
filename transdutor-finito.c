#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

/* Cabeçalhos */
int ehLetra(char);
int ehNumero(char);
int ehBranco(char);
int ehFinalPalavra(char);

void e0();
void e1();
void e2();

// delta1
void insereEmTempS(char);

// delta2
void anexaEmTempS(char);

// delta3
void finalizaTempS();

// delta4
void insereEmTempN(char);

// delta5
void anexaEmTempN(char);

// delta6
void finalizaTempN();

/* Variáveis globais */
// TODO: fazer palavra ser um input
char palavra[200] = "AB A A28 A C";
char tabelaVariaveis[20][10];
char tempS[200];
char tempN[200];

int posicaoPalavra = 0;
int posicaoMatrizVariaveis = 0;
int posicaoTempS = 1;
int posicaoTempN = 1;



int main(int argc, char const *argv[]) { 

	e0();

	return 0; 
}

void e0() {

	char simbolo = palavra[posicaoPalavra];

	if (ehLetra(simbolo)) {
		insereEmTempS(simbolo);
		posicaoPalavra++;
		e1();
	} /*else if (ehNumero(simbolo)) {
		e2();
	}*/
}

void e1() {

	char simbolo = palavra[posicaoPalavra];

	if (ehLetra(simbolo) || ehNumero(simbolo)) {
		anexaEmTempS(simbolo);
		posicaoPalavra++;
		e1();
	} else if (ehBranco(simbolo) || ehFinalPalavra(simbolo)) {
		finalizaTempS();
		posicaoPalavra++;
		e0();
	}
}

void e2() {

	if (ehNumero(palavra[posicaoPalavra])) {
		//anexaEmTempN(palavra[posicaoPalavra]);
		e2();
	}
}

int ehLetra(char simbolo) {

	if (simbolo >= 'A' && simbolo <= 'Z' || 
		simbolo >= 'a' && simbolo <= 'z') {
		return true;
	}

	return false;
}

int ehNumero(char simbolo) {

	if (simbolo >= '0' && simbolo <= '9') {
		return true;
	}

	return false;
}

int ehBranco(char simbolo) {

	if (simbolo == ' ') {
		return true;
	}

	return false;
}

int ehFinalPalavra(char simbolo) {

	if (simbolo == '\0') {
		return true;
	}

	return false;
}

void insereEmTempS(char simbolo) {

	tempS[0] = simbolo;
}

void anexaEmTempS(char simbolo) {

	tempS[posicaoTempS] = simbolo;
	posicaoTempS++;
}

void finalizaTempS() {

	// Encerra a string de tempS
	tempS[posicaoTempS] = '\0';

	strcpy(tabelaVariaveis[posicaoMatrizVariaveis], tempS);

	posicaoMatrizVariaveis++;

	posicaoTempS = 1;

	printf("variavel = %s\n", tempS);
}