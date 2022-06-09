# Implementação em C++: Tipo "String"

Feito por [Daniel Luan Lourenço de Lima](https://github.com/DanieLuan)

O objetivo desse projeto é desenvolver uma implementação do tipo "String" na linguagem C++. Para tal, foi criada uma classe "String", a qual possui:
### Atributos

Para criar uma String, ou seja, uma sequência de caracteres, foi utilizado um **char* strLocal**, ou seja, um ponteiro que armazenará a sequência de char's.

### Construtores

A classe possui 4 Construtores e 1 Destrutor, sendo eles:

1. `String <var_name>;` : Inicializa uma string sem caracteres. Porém, na realidade a string possui sim um caractere, porém ele é o `\0`.
2. `String <var_name>(const char str);` : Inicializa uma string com apenas um caractere.
3. `String <var_name>("Daniel");` : Inicializa uma string que recebe a sequência por meio de um `const char*`.
4. `String <var_name>(String str);` : Inicializa uma string que recebe um outro String e cria uma cópia do mesmo.

**Destrutor**

O destrutor é utilizado apenas com o intuito de liberar a memória das Strings inicializadas, uma vez que a criação delas depende de alocação dinâmica

### Métodos

A seguir, os métodos da classe `String`:

```c++
    void resizeString(int newCap); // Redimensiona a String Dinâmicamente.

    bool verifyPos(int index); // Verifica a existencia de uma posição.

    int stringTimes(String str_); // Retorna o número de vezes que uma String ou um Char aparecem na String.

    int stringTimes(char str_); // Retorna o número de vezes que uma String ou um Char aparecem na String.

    int strSize(); // Retorna o tamanho da string.
    
    void setString(); // Armazena APENAS UMA PALAVRA para uma nova string pela entrada padrão. 
    
    char* getString(); // Retorna a String no tipo char*.
    
    void setLineString(); // Armazena UMA LINHA INTEIRA para uma nova string pela entrada padrão. 
    
    bool strcmp(String str1); // Compara duas strings e retorna true caso seja verdadeiro, ou false caso seja falso.
    
    void cutSpace(); // Remove os espaços, tabulações e quebras de linhas de antes e depois da String.
    
    void upper(); // Torna todos caracteres minúsculos em maiúsculos.
    
    void lower(); // Torna todos caracteres maiúsculos em minúsculos.
    
    bool isPrefix(String &_prefix); // Verifica se uma string é prefixo de outra.
    
    bool isSufix(String &_sufix); // Verifica se uma string é sufixo de outra.

    bool insertChar(const char char_, int index);// Insere um caractere na posição indicada
    
    bool removeChar(const char char_); // Remove o primeiro caractere indicado
    
    bool searchChar(const char char_); // Retorna verdadeiro caso o caractere indicado esteja presente na String, caso contrário retorna falso.
    
    bool switchChar(const char char1, const char char2);// Troca todos os CHAR1 pelos CHAR2 em uma String, porém apenas caso o char1 esteja presente.

    bool insertStr(String toInssert, int index); // Insere uma string na posição indicada.
    
    bool removeStr(String toRemove); // Remove a primeira string que for atribuída na função.
    
    bool searchStr(String toSearch); // Retorna verdadeiro caso a string indicada esteja presente na outra string, caso contrário retorna falso.
    
    bool switchStr(String str1, String str2); // Troca uma string1 pela string2 na string principal, porém apenas caso a string1 esteja presente.

    void join(String str_); // Metodo que concatena uma nova string à string principal.
    
    String *splitChar(const char char_); // Retorna um vetor de Strings separados por um char.
    
    String *splitStr(String str_); // Retorna um vetor de Strings separados por uma String.
```

### Como compilar

Como foi feita uma implementação, foram criados algumas funções para demonstrar o funcionamento.
Esse passo-a-passo é para sistemas **unix-like**, portanto certifique-se de estar em um ambiente apropriado para executar os passos seguintes.
A forma mais fácil de executar os testes é compilando utilizando **Makefile**, porém é opcional.

#### Com Makefile

1. Primeiramente entre no diretório `SRC` da pasta principal, onde contem os arquivos necessários para compilação;
```
cd SRC
```
2. Agora basta rodar o seguinte comando e os testes iniciarão automaticamente;
```
make tests
```

#### Sem Makefile
1. Primeiramente, crie vergonha e instale o Makefile na sua máquina;
2. Já que insiste...
3. Entre no diretório `SRC` da pasta principal, onde contem os arquivos necessários para compilação;
```
cd SRC
```
4. Em seguida, rode o código utilizando o GNU Compiler, mais especificamente o GNU C++ Compiler; ~~Se não tiver isso crie vergonha na cara~~
```
g++ -Wall -o main main.cpp String.cpp tests.cpp
```
5. Agora basta abrir o arquivo executável. Nesse caso, ele se chama `main`, então basta fazer;
```
./main
```

