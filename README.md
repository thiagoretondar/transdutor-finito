### Desenvolvimento de um transdutor finito

#### Reconhecedor/Analisador de variáveis e números.

Ex: 

**Entrada:** AB A 28 A28   A C

**Saída:** V(0)V(1)N(28)v(2)v(1)v(3)

**Tabela de variáveis:**
0 ...... AB
1 ...... A
2 ...... A28
3 ...... C

#### Como Construir?

![Alt Text](https://docs.google.com/drawings/d/1iLvCmsWKuda5XgLps2NVUjl2hypf3KBzqazarT_R5rc/pub?w=620&h=236)

γ ... transição
δ ... ação

No nosso caso...

![Alt Text](https://docs.google.com/drawings/d/1X9lTSMUyR-Dfp6lvYdc2UvP1Xa24CTv9TfXCTiol4Lc/pub?w=620&h=330)
Ações

Existem:
          * tempS (string-vetor char)
          * tempN (Numérico)
          * tabela de variáveis (matriz char)

* γ1 ... tempS <- símbolo (tempS[0] <- símbolo)
* γ2 ... Anexa símbolo em tempS
* γ3 ... Finaliza tempS

Procura temps na tabela de variáveis se encontrou então

  * produz v([]) na saída.
  * inserir tempS na tabela de Variáveis
  * produz v([]) na saída.

v([]) -> posição na tabela


* δ4 ... tempN ←- símbolo - ‘0’ (Valor numérico do símbolo).
* δ5 ... tempN ←- tempN * 10 + (simbolo - ‘0’)
* δ6 ... produz n([]) na saída.

n([])  -> TempN
