#ifndef STRING.HH
#define STRING.HH
#include <iostream>
using namespace std;

class strings{
private:
    char* strg; // Puntero al arreglo de caracteres
    int length; // Longitud de la cadena
public:
    strings(): strg(nullptr), length(0) {} // Constructor base

    strings(const char* s){
        length = 0;
        while (s[length] != '\0'){
            length++;
        }
        strg = new char[length + 1];
        for (int i = 0; i < length; i++){
            strg[i] = s[i];
        }
        strg[length] = '\0';
    }// Constructor con argumento

    bool empty() const {
        return length == 0;
    } // Valida si la longitud es 0, retorna verdadero si es así

    char& back() const {
        return strg[length - 1];
    } // Devuelve el último caracter de la cadena

    char& front() const {
        return strg[0];
    } // Devuelve el primer caracter de la cadena

    void print() const {
        for(int i = 0; i < length; i++){
            cout << strg[i];
        }
    }

    // Método find_first_not_of
    size_t find_first_not_of(const char* chars) const {
        for (size_t i = 0; i < length; ++i) {
            bool found = false;
            for (size_t j = 0; chars[j] != '\0'; ++j) {
                if (strg[i] == chars[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return i;
            }
        }
        return string::npos;
    }

    // Método find_first_of
    size_t find_first_of(const char* chars) const {
        for (size_t i = 0; i < length; ++i) {
            for (size_t j = 0; chars[j] != '\0'; ++j) {
                if (strg[i] == chars[j]) {
                    return i;
                }
            }
        }
        return string::npos;
    }

    // Método substr
    strings substr(size_t pos, size_t len) const {
        if (pos >= length) {
            return "";
        }
        len = min(len, static_cast<size_t>(length - pos));
        char* substrData = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            substrData[i] = strg[pos + i];
        }
        substrData[len] = '\0';
        return strings(substrData);
    }
};

#endif
