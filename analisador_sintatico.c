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

// pilha de estado
ptr_estado pilha_estados[20];

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
		eD();
	} else if (ehAbreParenteses(simbolo)) {
		eB();
	} else {
		// verifica se tem algo na pilha
			// desempilha chamando o estado desempilhado
		// senão
			// erro sintático
	}
}

void eB() {

	char simbolo = palavra[posicaoPalavra];

	// empilha estado C (eC)
	// chama a própria máquina, indo para o estado A (eA)
}

void eC() {

	char simbolo = palavra[posicaoPalavra];

	if (ehFechaParenteses(simbolo)) {
		// consome simbolo
		// vai para estado D (eD)
	}
}

void eD() {

	char simbolo = palavra[posicaoPalavra];

	if (!ehFinalPalavra(simbolo)) {
		if (ehOperador(simbolo)) {
			// consome simbolo
			// vai para estado A (eA)
		} else {
			// verifica se tem algo na pilha
				// desempilha chamando o estado desempilhado
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
	return true;
}

int ehFechaParenteses(char simbolo) {
	return true;
}

int ehOperador(char simbolo) {
	return true;
}

void verificaAceitacao() {
	printf("Verifica aceitacao");
}