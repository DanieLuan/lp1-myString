#include <iostream>
#include <limits>
#include <iomanip>
#include "../LIB/String.h"

#define RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"

String::String(){
    capacity = 1;
    strLocal = new char[capacity];
    strLocal[0] = '\0';
}

String::String(String &str){
    capacity = str.capacity;
    strLocal = new char[capacity];
    int i;
    for(i = 0; i < capacity; i++){
        strLocal[i] = str.strLocal[i];
    }
    strLocal[i] = '\0';
}

String::String(const char char_){
    capacity = 2;
    strLocal = new char[capacity];
    strLocal[0] = char_;
    strLocal[1] = '\0';
}

String::String(const char *str){
    const char* end = str;
    for( ; *end != '\0'; ++end);
    int lenght = end - str;

    capacity = lenght;
    strLocal = new char[capacity];
    int i;
    for(i = 0; i < lenght; i++){
        strLocal[i] = str[i];
    }
    strLocal[i] = '\0';
}

String::~String(){
    delete strLocal;
    strLocal = nullptr;
}

void String::resizeString(int newCap){
    delete strLocal;
    strLocal = new char[newCap];
    capacity = newCap;
}
int String::stringTimes(char char_){
    int times{0};

    for(int i = 0; i < strSize(); i++){
        if(strLocal[i] == char_){
            times++;
        }
    }

    return times;
}
int String::stringTimes(String str_){

    if(str_.strLocal[0] == '\0'){
        str_.strLocal[0] = -120;
    }

    int times = 0;
    int verify = 0;
    int j = 0;
    for(int i = 0; i < strSize(); i++){
        int aux = i;
        for(j = 0; j < str_.strSize(); j++){
            if(strLocal[aux] == str_.strLocal[j]){
                verify++;
                aux++;
            }
            else {
                break;
            }
        }
        if(verify == str_.strSize()){
            times++;
        }
        verify = 0;
    }
    str_.strLocal[0] = '\0';
    return times;
}
bool String::nextChars(int n, String str){
    int splitCount{0}, verify{0};
    while(strLocal[n] == str.strLocal[splitCount] && splitCount < str.strSize()){
        n++;
        splitCount++;
        verify++;
    }
    if(verify == str.strSize()){
        return true;
    } else {
        return false;
    }
}

bool String::verifyPos(int index){
    int size = strSize();
    if(index > size){
        return false;
    }
    
    return true;
}

void String::setString(){
	char aux;
    char *buffer;
    buffer = new char[1000];
	int len = 0;

    while(std::cin.get(aux)){
		if(aux == '\n' || aux == ' ')
			break;
		buffer[len] = aux;
		len++;
	}
    buffer[len] = '\0';

    flushBuffer();

    resizeString(len);

    for(int i = 0; i <= len; i++){
        strLocal[i] = buffer[i];
    }

    delete buffer;
    buffer = nullptr;
    
}

void String::setLineString(){
    char aux;
    char *buffer;
    buffer = new char[1000];
	int len = 0;

    while(std::cin.get(aux)){
		if(aux == '\n'){
            break;
        }
		buffer[len] = aux;
		len++;
	}
    buffer[len] = '\0';

    flushBuffer();

    resizeString(len);

    for(int i = 0; i <= len; i++){
        strLocal[i] = buffer[i];
    }

    delete buffer;
    buffer = nullptr;
}

char* String::getString(){
    return strLocal;
}

int String::strSize(){
  	const char* end = strLocal;
    for( ; *end != '\0'; ++end);
    return end - strLocal;
}
int strLen(const char *str){
    const char* end = str;
    for( ; *end != '\0'; ++end);
    return end - str;
}

bool String::strcmp(String str1){
    if(str1.strSize() == strSize()){
        int verify = 0;
        for(int i = 0; i < str1.strSize(); i++){
            if(str1.strLocal[i] == strLocal[i]){
                verify++;
            }
            else{
                return false;
            }
        }
        if(verify == str1.strSize()){
            return true;
        }
        else{
            return false;
        }
            
    }
    else{
        return false;
    }
        
}

void String::cutSpace(){
    int j = strSize()-1;

    while(j > 0){
        if(strLocal[j] == ' ' || strLocal[j] == '\n' || strLocal[j] == '\t'){
            j--;
        } else {
            break;
        }  
    }

    strLocal[j+1] = '\0';

    int current = 0;
    int newpos = 0;
    bool isFirst = false;

    while(current < strSize()){
        if(!(strLocal[current] == ' ' || strLocal[current] == '\n' || strLocal[current] == '\t') && isFirst == false){
            isFirst = true;
            strLocal[newpos] = strLocal[current];
            newpos++;
        }
        else if(isFirst == true){
            strLocal[newpos] = strLocal[current];
            newpos++;
        }
        current++;
    }

    strLocal[newpos] = '\0';
    
}

void String::upper(){
    for(int i = 0; i < strSize(); i++){
        if(strLocal[i] >= 'a' && strLocal[i] <= 'z'){
            strLocal[i] = strLocal[i] - 32;
        }
    }
}

void String::lower(){
    for(int i = 0; i < strSize(); i++){
        if(strLocal[i] >= 'A' && strLocal[i] <= 'Z'){
            strLocal[i] = strLocal[i] + 32;
        }
    }
}

bool String::isPrefix(String &prefix){

    int equal = 0;
    for(int i = 0; i < prefix.strSize(); i++){
        if(strLocal[i] == prefix.strLocal[i]){
            equal++;
        }
    }
    if(equal == prefix.strSize()){
        return true;
    }
    return false;
}

bool String::isSufix(String &sufix_){
    int equal = 0;
    for(int i = strSize()-1, j = sufix_.strSize()-1; i > (strSize()-1)-sufix_.strSize(); i--, j--){
        if(sufix_.strLocal[j] == strLocal[i]){
            equal++;
        }
    }
    if(equal == sufix_.strSize()){
            return true;
    }
    return false;
}

bool String::insertChar(const char char_, int index){
    if(index >= 0 && index <= strSize()){
        
        char *buffer;
        buffer = new char[strSize()+1];
        int i = 0;
        int j = 0;
        while(i < index){
            buffer[i] = strLocal[i];
            i++;
            j = i;
        }
        buffer[i] = char_;
        i++;
        while(strLocal[j] != '\0'){
            buffer[i] = strLocal[j];
            i++;
            j++;
        }
        resizeString(capacity+1);
        //StrCopy()
        for(int i = 0; i < strLen(buffer); i++){
            strLocal[i] = buffer[i];
        }
        return true;
    } else {
        return false;
    }
}

bool String::removeChar(const char char_){
    
    if(searchChar(char_)){
        int i = 0;
        bool removed = false;
        for(; i < strSize(); i++){
            if(strLocal[i] == char_){
                removed= true;
            }
            if(removed){
                strLocal[i] = strLocal[i+1];
            }
        }
        strLocal[i] = '\0';
        return true;
    } else {
        return false;
    }
    

}

bool String::searchChar(const char char_){
    for(int i = 0; i < strSize(); i++){
        if(strLocal[i] == char_){
            return true;
        }
    }
    return false;
}

bool String::switchChar(const char char1, const char char2){
    if(searchChar(char1)){
        for(int i = 0; i < strSize(); i++){
            if(strLocal[i] == char1){
                strLocal[i] = char2;
            }
        }
        return true;
    } else {
        return false;
    }

}

bool String::insertStr(String toInssert, int index){
    if(index >= 0 && index <= strSize()){
        char* buffer;
        buffer = new char[toInssert.strSize()+strSize()+1];
        int i=0, j=0, k=0;
        
        while(i < index){
            buffer[i] = strLocal[i];
            i++;
        }
        k = i;
        while(j < toInssert.strSize()){
            buffer[i] = toInssert.strLocal[j];
            i++;
            j++;
        }
        while(strLocal[k] != '\0'){
            buffer[i] = strLocal[k];
            i++;
            k++;
        }
        resizeString(strLen(buffer)+1);
        for(int i = 0; i < strLen(buffer); i++){
            strLocal[i] = buffer[i];
        }
        return true;
    } else {
        return false;
    }
    
}

bool String::removeStr(String toRemove){
    if(searchStr(toRemove)){
        int size = strSize() - (toRemove.strSize()) + 1;
        char *buffer;
        buffer = new char[size];

        int i = 0, j = 0, k = 0, ib;
        bool once = false;
        int verifyLen = 0;
        for(; i < strSize(); i++){
            ib = i;
            while(strLocal[ib] == toRemove.strLocal[j]){
                verifyLen++;
                ib++;
                j++;
            }
            if(verifyLen == toRemove.strSize() && once == false){
                i = i + (toRemove.strSize());
                once = true;
            }
            verifyLen = 0;
            j = 0;
            buffer[k] = strLocal[i];
            k++;            
        }
        buffer[k] = '\0';

        resizeString(size);

        for(int i = 0; i < size; i++){
            strLocal[i] = buffer[i];
        }
        delete buffer;
        buffer = nullptr;

        return true;
    } else {
        return false;
    }
}

bool String::searchStr(String toSearch){
    int i, j = 0, ver = 0, aux;
    for(i = 0; i < strSize(); i++){
        aux = i;
        while(j < toSearch.strSize() && strLocal[i] == toSearch.strLocal[j]){
            ver++;
            i++;
            j++;
        }
        if(ver == toSearch.strSize()){
            return true;
        }
        ver = 0;
        j = 0;
        i = aux;
    }
    
    return false;
}

bool String::switchStr(String str1, String str2){
    if(searchStr(str1)){
        char *buffer;
        buffer = new char[strSize()+(str1.strSize()+str2.strSize())];

        int i = 0, k = 0, j = 0, ib;
        int verifyLen = 0; 
        for(; i < strSize(); i++){
            ib = i;
            while(strLocal[ib] == str1.strLocal[j] && j < str1.strSize()){
                verifyLen++;
                j++;
                ib++;
            }
            if(str1.strSize() == verifyLen){
                j = 0;
                i = i + verifyLen-1;
                verifyLen = 0;
                while(j < str2.strSize()){
                    buffer[k] = str2.strLocal[j];
                    j++;
                    k++;
                }
                j = 0;
            } else {
                buffer[k] = strLocal[i];
                k++;
            }
        }
        buffer[k] = '\0';

        resizeString(strLen(buffer));
        int c;
        for(c = 0; buffer[c] != '\0'; c++){
            strLocal[c] = buffer[c];
        }
        strLocal[c] = '\0';

        delete buffer;
        buffer = nullptr;
        return true;
    } else {
        return false;
    }
}

void String::join(String str_){
    insertStr(str_, strSize());
}

String *String::splitChar(const char char_){
    String *splited;
    
    splited = new String[stringTimes(char_)+1];
    int jStart{0}, jEnd, strVet{0}, k{0};
    int i;
    for(i = 0; i < strSize(); i++){
        if(strLocal[i] == char_ || i == strSize()-1){
            if(i == strSize()-1){
                jEnd = i;
            } else {
                jEnd = i-1;
            }
            splited[strVet].resizeString(jEnd+1);
            while((jStart <= jEnd) && (strLocal[jStart] != char_)){
                splited[strVet].strLocal[k] = strLocal[jStart];
                jStart++;
                k++;
            }
            splited[strVet].strLocal[k] = '\0';
            jStart++;
            strVet++;
            k = 0;
        }
    }
    return splited;
}

String *String::splitStr(String toSplit){
    char *buffer;
    buffer = new char[strSize()+1];

    if(toSplit.strLocal[0] == '\0'){
        toSplit.strLocal[0] = -120;
    }

    String *splited;
    splited = new String[stringTimes(toSplit)+1];
    
    int strVet{0}, k{0};
    
    for(int i = 0; i < strSize(); i++){
        if(nextChars(i, toSplit)){
            i = i + toSplit.strSize();
        }
        while(!(nextChars(i, toSplit)) && i < strSize()){
            buffer[k] = strLocal[i];
            i++;
            k++;
        }
        i--;
        buffer[k] = '\0';
        
        for(int o = 0; o <= strLen(buffer); o++){
            splited[strVet].strLocal[o] = buffer[o];
        }
        
        strVet++;
        k = 0;
    }
    toSplit.strLocal[0] = '\0';
    
    delete buffer;
    buffer = nullptr;
    
    return splited;
}

    
void flushBuffer(){
    std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::ostream &operator<<(std::ostream &COUT, String &string){
    COUT << string.getString();
    return COUT;
}

std::istream &operator>>(std::istream &CIN, String &string){
    CIN >> string.getString();
    return CIN;
}
