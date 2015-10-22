#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

/* Cabeçalhos */
int ehLetra(char);
int ehNumero(char);
int ehBranco(char);
int ehFinalPalavra(char);
void limpaPalavra();
int comparaStrings(char*, char*);
void copiaString(char*, const char*);
int tamanhoString(char*);

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

// delta7
void finalizaTempNeAnexaEmTempS(char);

/* Variáveis globais */
// TODO: fazer palavra ser um input
char palavra[200];
char tabelaVariaveis[20][10];
int tabelaNumeros[20];
char tempS[200];
int tempN;

int posicaoPalavra = 0;
int posicaoMatrizVariaveis = 0;
int posicaoMatrizNumeros = 0;
int posicaoTempS = 0;


int main(int argc, char const *argv[]) { 

	printf("Entrada: ");
	fgets(palavra, 200, stdin);

	// Limpa a palavra, pois fgets coloca um '\n' na
	// penúltima posição, antes do '\0'. Assim forçamos 
	// o '\0' ser no lugar do '\n'
	palavra[tamanhoString(palavra) - 1] = '\0';

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

	if (!ehFinalPalavra(simbolo)) {
		if (ehLetra(simbolo)) {
			insereEmTempS(simbolo);
			posicaoPalavra++;
			e1();
		} else if (ehNumero(simbolo)) {
			insereEmTempN(simbolo);
			posicaoPalavra++;
			e2();
		} else if (ehBranco(simbolo)) {
			posicaoPalavra++;
			e0();
		}
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

	if (ehNumero(simbolo)) {
		anexaEmTempN(simbolo);
		posicaoPalavra++;
		e2();
	} else if(ehLetra(simbolo)) {
		finalizaTempNeAnexaEmTempS(simbolo);
		posicaoPalavra++;
		e1();
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

	// verifica espaço em branco
	if (simbolo == ' ') {
		return true;
	}

	return false;
}

int ehFinalPalavra(char simbolo) {

	// verifica final de string
	if (simbolo == '\0') {
		return true;
	}

	return false;
}

void insereEmTempS(char simbolo) {

	tempS[posicaoTempS] = simbolo;
	posicaoTempS++;
}

void anexaEmTempS(char simbolo) {

	tempS[posicaoTempS] = simbolo;
	posicaoTempS++;
}

void finalizaTempS() {

	// Encerra a string de tempS
	tempS[posicaoTempS] = '\0';

	// próximo ciclo do tempS, a posição começara a partir do um novamente
	posicaoTempS = 0;

	// se já existe na tabela de variáveis, não faz nada
	int i;
	for (i = 0; i < posicaoMatrizVariaveis; i++) {
		if (comparaStrings(tabelaVariaveis[i], tempS)) {
			printf("V(%d)", i);
			return;
		}
	}

	// caso não encontre, cria mais um na tabela de variáveis
	copiaString(tabelaVariaveis[posicaoMatrizVariaveis], tempS);

	printf("V(%d)", posicaoMatrizVariaveis);

	posicaoMatrizVariaveis++;
}

void insereEmTempN(char simbolo) {

	// insere o valor inteiro do símbolo
	tempN = simbolo - '0';
}

void anexaEmTempN(char simbolo) {

	// insere o valor inteiro do símbolo na proxima casa
	tempN = tempN * 10 + (simbolo - '0');
}

void finalizaTempN() {

	// colaca a valor na tabela de números
	tabelaNumeros[posicaoMatrizNumeros] = tempN;

	printf("N(%d)", tempN);

	// reseta a variável tempN
	tempN = 0;

	posicaoMatrizNumeros++;
}

void finalizaTempNeAnexaEmTempS(char simbolo) {

	// se aparece uma letra, o número finaliza
	finalizaTempN();

	// e a letra que apareceu é anexada
	anexaEmTempS(simbolo);
}

int comparaStrings(char str1[], char str2[]) {

	// percorre str1 até encontrar caracter
	// finalizador (\0)
	int c;
	for (c = 0; str1[c]; c++) {
		if (str1[c] != str2[c]) {
			return false;
		}
	}

	if (str1[c] == str2[c]) {
		return true;
	} else {
		return false;
	}
}

void copiaString(char dest[], const char fonte[]) {
	int i = 0;

	// copia primeiro e depois verifica se a cópia
	// não é igual a caractere finalizador (\0)
	while ((dest[i] = fonte[i]) != '\0') {
		i++;
	}
}

int tamanhoString(char* string) {
	int tamanho;
	for (tamanho = 0; *string != '\0'; string++) {
		tamanho++;
	}
	return tamanho;
}