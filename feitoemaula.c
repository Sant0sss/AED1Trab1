#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct body {
  int inicio;
  int fim;
 };

int dividirstr(char *c, int inicio, int fim) {
  bool *minuscula = (bool *)calloc(26, sizeof(bool));
  bool *maiuscula = (bool *)calloc(26, sizeof(bool));

  for (int i = inicio; i < fim; i++) {
    if (c[i] >= 'A' && c[i] <= 'Z') {
      maiuscula[c[i] - 'A'] = true;
    } else {
      minuscula[c[i] - 'a'] = true;
    }
  }

  for (int i = inicio; i < fim; i++) {
    if (c[i] >= 'A' && c[i] <= 'Z') {
      if (minuscula[c[i] - 'A'] == false)
        return i;
    } else {
      if (maiuscula[c[i] - 'a'] == false)
        return i;
    }
  }

  return -1;
 }

struct body acharstr(char *s, int inicio, int fim) {
  struct body res;
  res.inicio = inicio;
  res.fim = fim;


  int ponto = dividirstr(s, inicio, fim);

  if (ponto == -1) {
    return res;
   }
 }

int main(void) {
  char *res = longestNiceSubstring("YazaAay");
  printf(res);
  return 0;
}