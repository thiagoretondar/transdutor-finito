#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

// criado um tipo para especificar a chamada
// de estados na pilha
typedef void (*ptr_estado)();

/* Cabeçalhos */
int ehNumero(char);
int ehBranco(char);
int ehFinalPalavra(char);
int ehAbreParenteses(char);
int ehFechaParenteses(char);
int ehOperador(char);
void verificaAceitacao();

void eA();
void eB();
void eC();
void eD();

/* Variáveis globais */
char palavra[200];

int posicaoPalavra = 0;
int posicaoMatrizVariaveis = 0;
int posicaoMatrizNumeros = 0;
int posicaoTempS = 0;

// pilha de estados (eA, eB, ...)
ptr_estado pilha_estados[20];
int posicao_pilha = 0;

int pilhaEstaVazia(ptr_estado* pilha) {

	if (pilha[0] == NULL) {
		printf("\nPilha está vazia\n");
		return true;
	}

	return false;
}

void empilha(void (*estado_func)(), ptr_estado* pilha, int* posicao) {
	pilha[(*posicao)++] = *estado_func;
}

ptr_estado desempilha(ptr_estado* pilha, int* posicao) {

	if (!pilhaEstaVazia(pilha)) {
		ptr_estado estado_func = pilha[--(*posicao)];
		pilha[(*posicao)] = NULL;
		return estado_func;
	}

	return NULL;
}

int main(int argc, char const *argv[]) {

	printf("Entrada: ");
	fgets(palavra, 200, stdin);

	// Limpa a palavra, pois fgets coloca um '\n' na
	// penúltima posição, antes do '\0'. Assim forçamos
	// o '\0' ser no lugar do '\n'
	palavra[tamanhoString(palavra) - 1] = '\0';

	printf("Saída: ");
	// estado inicial
	eA();

	return 0;
}

void eA() {

	char simbolo = palavra[posicaoPalavra];

	if (ehNumero(simbolo)) {
		posicaoPalavra++;
		eD();
	} else if (ehAbreParenteses(simbolo)) {
		posicaoPalavra++;
		eB();
	} else {
		if (!pilhaEstaVazia(pilha_estados)) {
			ptr_estado estado_desempilhado = desempilha(pilha_estados, &posicao_pilha);
			estado_desempilhado();
		} else {
			printf("\nPILHA ESTÁ VAZIA\n");
		}
		// TODO
		// senão
			// erro sintático
	}
}

void eB() {

	empilha(eC,pilha_estados, &posicao_pilha);

	// chamada da própria máquina
	eA();
}

void eC() {

	printf("\nChamando eC()\n");
	char simbolo = palavra[posicaoPalavra];

	if (ehFechaParenteses(simbolo)) {
		posicaoPalavra++;
		eD();
	}
}

void eD() {

	char simbolo = palavra[posicaoPalavra];

	if (!ehFinalPalavra(simbolo)) {
		if (ehOperador(simbolo)) {
			posicaoPalavra++;
			eA();
		} else {
			if (!pilhaEstaVazia(pilha_estados)) {
				ptr_estado estado_desempilhado = desempilha(pilha_estados, &posicao_pilha);
				estado_desempilhado();
			} else {
				printf("\nPILHA ESTÁ VAZIA\n");
			}
			// TODO
			// senão
				// erro sintático
		}
	} else {
		verificaAceitacao();
	}
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

int tamanhoString(char* string) {

	int tamanho;
	for (tamanho = 0; *string != '\0'; string++) {
		tamanho++;
	}

	return tamanho;
}

int ehAbreParenteses(char simbolo) {

	if (simbolo == '(') {
		return true;
	}

	return false;
}

int ehFechaParenteses(char simbolo) {

	if (simbolo == ')') {
		return true;
	}

	return false;
}

int ehOperador(char simbolo) {

	switch(simbolo) {
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		default:
			return false;
	}
}

void verificaAceitacao() {

	printf("Verifica aceitacao");
}
