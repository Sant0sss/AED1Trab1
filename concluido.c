#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct substring {
    int inicio;
    int fim;
};

// Para verificar se uma substring e "nice"
bool dividirstr(char *s, int inicio, int fim) {
    bool *minusculo = (bool *)calloc(26, sizeof(bool)); 
    bool *maiuscula = (bool *)calloc(26, sizeof(bool));

// Verificar quais caracteres minusculos e maiusculos estao presentes na substring
    for (int i = inicio; i <= fim; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            minusculo[s[i] - 'a'] = true;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            maiuscula[s[i] - 'A'] = true;
        }
    }


// Verificar se cada caractere da substring tem seu oposto tanto maiusculo como minusculo
    for (int i = inicio; i <= fim; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (!maiuscula[s[i] - 'a'])
                return false;

        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            if (!minusculo[s[i] - 'A'])
                return false;
                
        }
    }

    return true;
}

// Funcao para encontrar a substring mais longa que e "nice"
struct substring substrlonga(char *s) {
    int len = strlen(s);
    struct substring longa = {0, -1};

// Percorrer todas as substrings possiveis
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (dividirstr(s, i, j) && j - i + 1 > longa.fim - longa.inicio + 1) {
                longa.inicio = i;
                longa.fim = j;
            }
        }
    }

    return longa;
}

// Para extrair a substring real a partir do início e fim
char *acharstr(char *s, int inicio, int fim) {
    int comp = fim - inicio + 1;
    char *substring = (char *)malloc((comp + 1) * sizeof(char));
    strncpy(substring, s + inicio, comp);
    substring[comp] = '\0';
    return substring;
}

int main(void) {
    char *s = "YazaAay";
    struct substring longa = substrlonga(s);
    char *res = acharstr(s, longa.inicio, longa.fim);
    printf("%s\n", res);
    free(res);
    return 0;
}
