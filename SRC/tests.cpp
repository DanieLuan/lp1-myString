#include "../LIB/String.h"
#include "../LIB/tests.hpp"
#include <cstdlib>
#include <ctime>

#define RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GRAY "\e[0;37m"
#define ANSI_COLOR_GREEN "\e[0;32m"
#define ANSI_COLOR_GREEN_H "\e[0;32;1m"
#define ANSI_COLOR_ROSA "\033[38m"

void runTests(){
    int test;
    std::cout << "Qual método? (Construtores -3, -2 e -1)" << std::endl;
    std::cin >> test;

    flushBuffer();
    switch (test)
    {
    case -1:
        constructor1();
        break; 
    case -2:
        constructor2();
        break; 
    case -3:
        constructor3();
        break; 
    case 1:
        metodo1();
        break;
    case 2:
        metodo2();
        break;
    case 3:
        metodo3();
        break;
    case 4:
        metodo4();
        break;
    case 5:
        metodo5();
        break;
    case 6:
        metodo6();
        break;
    case 7:
        metodo7();
        break;
    case 8:
        metodo8();
        break;
    case 9:
        metodo9();
        break;
    case 10:
        metodo10();
        break;
    case 11:
        metodo11();
        break;
    case 12:
        metodo12();
        break;
    case 13:
        metodo13();
        break;
    case 14:
        metodo14();
        break;
    case 15:
        metodo15();
        break;
    case 16:
        metodo16();
        break;

    default:
        break;
    }
}

void constructor1(){
    std::cout << ANSI_COLOR_RED "CONSTRUTOR 1: VAZIO" << std::endl;

    String teste();

    std::cout << "String:" << teste << "END" << std::endl;
    std::cout << "\n" RESET;
}

void constructor2(){
    std::cout << ANSI_COLOR_GREEN << "CONSTRUTOR 2: ASPAS DUPLAS" << std::endl;

    String teste("testei testando testarei");

    std::cout << "String: '" << teste << "'" << std::endl;
    std::cout << "\n" RESET;
}

void constructor3(){
    std::cout << ANSI_COLOR_RED << "CONSTRUTOR 3: COPIA" << std::endl;

    String teste("testei testando testarei");
    String copia(teste);

    std::cout << "String: '" << copia << "'" << std::endl;
    std::cout << "\n" RESET;
}

void metodo1(){
    std::cout << "METODO 1: SET_STRING" << std::endl;
    String name("123456789");

    std::cout << "String: '" << name << "'" << std::endl;
    std::cout << "SizeOf: " << name.strSize() << std::endl;
    std::cout << "\n";
}

void metodo2(){
    std::cout << "METODO 2: SET_STRING - Apenas palavra" << std::endl;
    String str;
    std::cout << "Coloque sua string: ";
    str.setString();
    std::cout << "Sua String é: " << str << "/END" << std::endl;
    std::cout << "\n";
}

void metodo3(){
    std::cout << "METODO 3: GET_STRING - Receber string" << std::endl;
    String teste("teste testando");

    std::cout << teste << std::endl;
    
    std::cout << "\n";
}

void metodo4(){
    std::cout << "METODO 4: GET_STRING - Linha inteira" << std::endl;
    String str;
    std::cout << "Coloque sua string: ";
    str.setLineString();
    std::cout << "Sua String é: " << str << "/END" << std::endl;
    std::cout << "\n";
}

void metodo5(){
    std::cout << "METODO 5: STRCMP - Compara com outra string" << std::endl;
    
    String word1("teste 1");
    String word2("teste 1");
    String word3("testi 1 ");
    std::cout << "Word1: '" << word1 << "'" <<std::endl;
    std::cout << "Word2: '" << word2 << "'" <<std::endl;
    std::cout << "Word3: '" << word3 << "'" <<std::endl;

    if(word1.strcmp(word2)){
        std::cout << "Word1 == Word2" << std::endl;
    } else {
        std::cout << "Word1 != Word2" << std::endl;
    }
    if(word1.strcmp(word3)){
        std::cout << "Word1 == Word3" << std::endl;
    } else {
        std::cout << "Word1 != Word3" << std::endl;
    }

    std::cout << "\n";
}

void metodo6(){
    std::cout << "METODO 6: CUT_SPACE - Remove espaços antes e depois da string" << std::endl;
    
    String toCut("   nome[10] é um vetor     \t\n\t");
    std::cout << "Antes: '" << toCut << "'" <<std::endl;
    toCut.cutSpace();
    std::cout << "Depois: '" << toCut << "'" <<std::endl;
    std::cout << "\n";
}

void metodo7(){
    std::cout << "METODO 7: UPPER e LOWER - Torna todos caracteres maiúsculos ou minúsculos" << std::endl;
    
    std::cout << "UPPERCASE:" << std::endl;
    String str1("Caio Ferreira Costa");
    std::cout << "Antes: '" << str1 << "'" <<std::endl;
    str1.upper();
    std::cout << "Depois: '" << str1 << "'" <<std::endl;

    std::cout << "LOWERCASE:" << std::endl;
    String str2("Jeanne D'Arc");
    std::cout << "Antes: '" << str2 << "'" <<std::endl;
    str2.lower();
    std::cout << "Depois: '" << str2 << "'" <<std::endl;
    std::cout << "\n";
}

void metodo8(){
    std::cout << "METODO 8: IS_PREFIX e IS_SUFIX" << std::endl;
    
    std::cout << "IS_PREFIX:" << std::endl;
    String str1("Palavra Digital");
    String str2("Pala");
    String str3("ala");
    std::cout << "Word1: '" << str1 << "'" <<std::endl;
    std::cout << "Word2: '" << str2 << "'" <<std::endl;
    std::cout << "Word3: '" << str3 << "'" <<std::endl;
    if(str1.isPrefix(str2)){
        std::cout << "'" << str2 << "' é prefixo de '" << str1 <<"'" << std::endl;
    } else {
        std::cout << "'" << str2 << "' não é prefixo de '" << str1 <<"'" << std::endl;
    }
    if(str1.isPrefix(str3)){
        std::cout << "'" << str3 << "' é prefixo de '" << str1 <<"'" << std::endl;
    } else {
        std::cout << "'" << str3 << "' não é prefixo de '" << str1 <<"'" << std::endl;
    }
    std::cout << "\n";

    std::cout << "IS_SUFIX:" << std::endl;
    String str4("Tecladinho");
    String str5("inho");
    String str6("inh");
    std::cout << "Word1: '" << str4 << "'" <<std::endl;
    std::cout << "Word2: '" << str5 << "'" <<std::endl;
    std::cout << "Word3: '" << str6 << "'" <<std::endl;
    if(str4.isSufix(str5)){
        std::cout << "'" << str5 << "' é sufixo de '" << str4 <<"'" << std::endl;
    } else {
        std::cout << "'" << str5 << "' não é sufixo de '" << str4 <<"'" << std::endl;
    }
    if(str4.isSufix(str6)){
        std::cout << "'" << str6 << "' é sufixo de '" << str4 <<"'" << std::endl;
    } else {
        std::cout << "'" << str6 << "' não é sufixo de '" << str4 <<"'" << std::endl;
    }
    std::cout << "\n";
}

void metodo9(){
    std::cout << "METODO 9: INSSERT_CHAR" << std::endl;

    String word("tamanho");
    std::cout << "Word1: '" << word << "'" <<std::endl;
    std::cout << "Char: '.' "<< std::endl;
    int size = word.strSize()-1;
    unsigned seed = time(0);
    srand(seed);

    if(word.insertChar('.', rand()%size)){
        std::cout << "Char inserido! Nova string: '" << word << "'" <<std::endl;
    } else {
        std::cout << "Erro, posição não possível!" << std::endl;
    }

    std::cout << "\n";
}

void metodo10(){
    std::cout << "METODO 10: REMOVE_CHAR" << std::endl;

    String word("tamanduá");
    std::cout << "Word1: '" << word << "'" <<std::endl;
    std::cout << "Char to remove: 'a' "<< std::endl;

    if(word.removeChar('a')){
        std::cout << "Char removido! Nova string: '" << word << "'" <<std::endl;
    } else {
        std::cout << "Erro, char não encontrado!" << std::endl;
    }

    std::cout << "\n";
}

void metodo11(){
    std::cout << "METODO 11: SEARCH_CHAR" << std::endl;
    String word("Baleia-jubarte");
    std::cout << "Word1: '" << word << "'" <<std::endl;
    std::cout << "Char to search: 'b', 'c'"<< std::endl;

    if(word.searchChar('b')){
        std::cout << "Char 'b' Encontrado!" << std::endl;
    } else {
        std::cout << "Erro, char 'b' não encontrado!" << std::endl;
    }

    if(word.searchChar('c')){
        std::cout << "Char 'c' Encontrado!" << std::endl;
    } else {
        std::cout << "Erro, char 'c' não encontrado!" << std::endl;
    }

    std::cout << "\n";
}

void metodo12(){
    std::cout << "METODO 12: SWITCH_CHAR" << std::endl;
    
    String word("Ser ou nao ser, eis a questao");
    std::cout << "String: '" << word << "'" <<std::endl;
    std::cout << "Char to search: 'e', '#'"<< std::endl;

    word.switchChar('e', '#');
    
    std::cout << "New String: '" << word << "'" <<std::endl;
    std::cout << "\n";
}

void metodo13(){
    
    std::cout << "METODO 13.1: INSERT_STR" << std::endl;
    String nome("Exemplificação");
    String nome2("EXEMPLO");
    std::cout << "String1: '" << nome << "'" << std::endl;
    std::cout << "String2: '" << nome2 << "'" << std::endl;

    if(nome.insertStr(nome2, 2)){
        std::cout << "String inserida! Nova string: '" << nome << "'" <<std::endl;
    } else {
        std::cout << "Erro, possição não disponível" <<std::endl;
    }

    std::cout << "\n";

    std::cout << "METODO 13.2: REMOVE_STR" << std::endl;
    std::cout << "String1: '" << nome << "'" << std::endl;
    std::cout << "String2: '" << nome2 << "'" << std::endl;
    
    if(nome.removeStr(nome2)){
        std::cout << "String removida! Nova string: '" << nome << "'" <<std::endl;
    } else {
        std::cout << "Erro, string não encontrada!" <<std::endl;
    }
    std::cout << "\n";

    std::cout << "METODO 13.3: SEARCH_STR" << std::endl;
    String nome3("ação");
    std::cout << "String1: '" << nome << "'" << std::endl;
    std::cout << "String2: '" << nome3 << "'" << std::endl;
    
    if(nome.searchStr(nome3)){
        std::cout << "String Encontrada!" << "'" << std::endl;
    } else {
        std::cout << "Erro, string não encontrada!" << std::endl;
    }
    std::cout << "\n";

    std::cout << "METODO 13.4: SWITCH_STR" << std::endl;

    String str("Papel Pato Palhaço");
    String str1("Pa");
    String str2("@");

    std::cout << "String: '" << str << "'" << std::endl;
    std::cout << "STR1: '" << str1 << "'" << std::endl;
    std::cout << "STR2: '" << str2 << "'" << std::endl;
    
    if(str.switchStr(str1, str2)){
        std::cout << "String removida! Nova string: '" << str << "'" <<std::endl;
    } else {
        std::cout << "Erro, string não encontrada!" <<std::endl;
    }
    std::cout << "\n";
}

void metodo14(){
    std::cout << "METODO 14: JOIN" << std::endl;
    String str1("palavra 1");
    String str2("frase 3");

    std::cout << "String1: '" << str1 << "'" << std::endl;
    std::cout << "String2: '" << str2 << "'" << std::endl;
    str1.join(str2);
    std::cout << "String1+String2: '" << str1 << "'" << std::endl;

    std::cout << "\n";
}

void metodo15(){
    std::cout << "METODO 15: SPLIT_CHAR" << std::endl;

    std::cout << "TESTE 1: NORMAL" << std::endl;
    String frase("Pedro de Alcântara João");
    char div{' '};
    int times = frase.stringTimes(div);

    String *splits;
    splits = new String[times+1];
    std::cout << "String1: '" << frase << "'" << std::endl;
    std::cout << "Char2: '" << div << "'" << std::endl;

    for(int i = 0; i < times +1; i++){
        splits[i] = frase.splitChar(div)[i];
    }
    
    for(int o = 0; o < times+1; o++){
        std::cout << o+1 << ") '"<< splits[o] << "'" << std::endl;
    }

    std::cout << "\n";

    std::cout << "TESTE 2: SEM TROCA" << std::endl;

    String frase2("pneumoultramicroscopicossilicovulcanoconiótico");
    char div2{'Z'};
    int times2 = frase2.stringTimes(div2);

    String *splits2;
    splits2 = new String[times2+1];
    std::cout << "String2: '" << frase2 << "'" << std::endl;
    std::cout << "Char2: '" << div2 << "'" << std::endl;

    for(int i = 0; i < times2 +1; i++){
        splits2[i] = frase2.splitChar(div2)[i];
    }
    
    for(int o = 0; o < times2+1; o++){
        std::cout << o+1 << ") '"<< splits2[o] << "'" << std::endl;
    }
    std::cout << "\n";
}

void metodo16(){
    std::cout << "METODO 16: SPLIT_STR" << std::endl;
    
    std::cout << "TESTE 1: NORMAL" << std::endl;
    String frase("Chega da escola e vai da TV até damasco");
	String cut("da");
    String *splits;

    int times = frase.stringTimes(cut);
    splits = new String[times+1];

    std::cout << "String: '" << frase << "'" << std::endl;
    std::cout << "Cutter: '" << cut << "'" << std::endl;
    
    splits = frase.splitStr(cut);
    for(int o = 0; o < times+1; o++){
        std::cout << o+1;
        std::cout << ") '"<< splits[o] << "'" << std::endl;
    }
    std::cout << "\n";

    std::cout << "TESTE 2: NÃO DIVIDIR" << std::endl;
    String frase2("três pratos de trigo para três tigres tristes");
	String cut2("dividir");
    String *splits2;

    int times2 = frase2.stringTimes(cut2);
    splits2 = new String[times2+1];

    std::cout << "String: '" << frase2 << "'" << std::endl;
    std::cout << "Cutter: '" << cut2 << "'" << std::endl;
    
    splits2 = frase2.splitStr(cut2);
    for(int o = 0; o < times2+1; o++){
        std::cout << o+1;
        std::cout << ") '"<< splits2[o] << "'" << std::endl;
    }
    std::cout << "\n";
}

