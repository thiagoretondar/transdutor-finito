### Desenvolvimento de um analisador léxico

#### Reconhecedor/Analisador de variáveis e números.

Ex: 

**Entrada:**  IF (a=10) THEN a=a+1%soma1

**Saída:** P(1)(V(0)=N(10)P(3))V(0)=V(0)+N(1)

**Tabela de variáveis:**
Tabela de Variaveis:
* 0...a

**Palavra Reservada::**
* 0...LET
* 1...IF
* 2...ELSE
* 3...THEN
* 4...GOTO
* 5...PRINT
* 6...READ
* 7...END
* 8...OF


#### Como Construir?

![Alt Text](https://docs.google.com/drawings/d/13_xn4hqaUAwh_HGU0U13xGSxaMyJrqUh0cEusVsVJV4/pub?w=602&h=450)

![Alt Text](https://docs.google.com/drawings/d/1zG4tuqDc8mdR6VH8u65Nuqc4dCKuf1BnJNcEjaJ9oJA/pub?w=596&h=588)
