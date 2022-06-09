#ifndef STRING_H_
#define STRING_H_

#include <iostream>

class String
{
public:
    //Atributos
    char* strLocal; //Local de memoria para inserir os chars
    int capacity; //Tamanho de espaços de memoria

    //Construtores e Destrutor
    String();
    String(const char *str);
    String(const char str);
    String(String &str_);
    ~String();

    void resizeString(int newCap); //Cresce a String Dinâmicamente

    bool verifyPos(int index); //Verifica a existencia de uma posição

    int stringTimes(String str_); // Retorna o número de vezes que uma String ou um Char aparecem na String

    int stringTimes(char str_); //Retorna o número de vezes que uma String ou um Char aparecem na String
    
    bool nextChars(int n, String str); 

    int strSize(); //1 - Retorna o tamanho da string
    
    void setString(); //2
    
    char* getString(); //3
    
    void setLineString(); //4
    
    bool strcmp(String str1); //5
    
    void cutSpace(); //6
    
    void upper(); //7.1
    
    void lower(); //7.2
    
    bool isPrefix(String &_prefix); //8.1
    
    bool isSufix(String &_sufix); //8.2

    bool insertChar(const char char_, int index);//9
    
    bool removeChar(const char char_); //10
    
    bool searchChar(const char char_); //11
    
    bool switchChar(const char char1, const char char2);//12

    bool insertStr(String toInssert, int index); //13.1
    
    bool removeStr(String toRemove); //13.2
    
    bool searchStr(String toSearch); //13.3
    
    bool switchStr(String str1, String str2); //13.4

    void join(String str_); //14
    
    String *splitChar(const char char_); //15
    
    String *splitStr(String str_); //16
    
};

int strLen(const char *str);
void flushBuffer();

std::ostream &operator<<(std::ostream &COUT, String &string);

std::istream &operator>>(std::istream &CIN, String &string);

#endif