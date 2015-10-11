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
char palavra[200] = "AB A  A28 A C";
char tabelaVariaveis[20][10];
int tabelaNumeros[20];
char tempS[200];
int tempN;

int posicaoPalavra = 0;
int posicaoMatrizVariaveis = 0;
int posicaoMatrizNumeros = 0;
int posicaoTempS = 1;
int posicaoTempN = 1;



int main(int argc, char const *argv[]) { 

	printf("Entrada: %s\n", palavra);
	printf("Saída: ");
	e0();

	printf("\n\nTabela de variáveis:\n");

	int i;
	for (i = 0; i < posicaoMatrizVariaveis; i++) {
		printf("%d ... ... ... %s\n", i, tabelaVariaveis[i]);
	}

	return 0; 
}

void e0() {

	char simbolo = palavra[posicaoPalavra];

	if (ehLetra(simbolo)) {
		insereEmTempS(simbolo);
		posicaoPalavra++;
		e1();
	} else if (ehNumero(simbolo)) {
		insereEmTempN(simbolo);
		posicaoPalavra++;
		e2();
	} else if (ehBranco(simbolo) || ehFinalPalavra(simbolo)) {
		posicaoPalavra++;
		e0();
	}
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

	char simbolo = palavra[posicaoPalavra];

	if (ehNumero(palavra[posicaoPalavra])) {
		anexaEmTempN(palavra[posicaoPalavra]);
		posicaoPalavra++;
		e2();
	} else if (ehBranco(simbolo) || ehFinalPalavra(simbolo)) {
		finalizaTempN();
		posicaoPalavra++;
		e0();
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

	// próximo ciclo do tempS, a posição começara a partir do um novamente
	posicaoTempS = 1;

	// se já existe na tabela de variáveis, não faz nada
	int i;
	for (i = 0; i < posicaoMatrizVariaveis; i++) {
		if (strcmp(tabelaVariaveis[i], tempS) == 0) {
			printf("V(%d)", i);
			return;
		}
	}

	// caso não encontre, cria mais um na tabela de variáveis
	strcpy(tabelaVariaveis[posicaoMatrizVariaveis], tempS);

	printf("V(%d)", posicaoMatrizVariaveis);

	posicaoMatrizVariaveis++;
}

void insereEmTempN(char simbolo) {

	tempN = simbolo - '0';
}

void anexaEmTempN(char simbolo) {

	tempN = tempN * 10 + (simbolo - '0');
	posicaoTempN++;
}

void finalizaTempN() {

	// colaca a valor na tabela de números
	tabelaNumeros[posicaoMatrizNumeros] = tempN;

	printf("N(%d)", tempN);

	// reseta a variável tempN
	tempN = 0;

	posicaoMatrizNumeros++;
}