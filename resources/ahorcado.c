#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#define MAX_IMG 128
#define MAX_DOTS 18

void print_lscreen(FILE * f);
void ahorcado();
void clear();

int main(void){
    char * filenom = "image.txt";
    FILE * f = NULL;

    if((f = fopen(filenom,"r")) == NULL){
        printf("Error opening %s\n",filenom);
        return 1;
    }

    print_lscreen(f);
    fclose(f);
    ahorcado();

    return 0;
}

void print_lscreen(FILE * f){
    char image[MAX_IMG];
    char dots[MAX_DOTS];
    float percent = 1;
    int i;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    for (i = 0; i <= MAX_DOTS; i++) {
      dots[i] = '\0';
    }

    dots[0] = '.';
    i = 1;
    while (i <= MAX_DOTS) {
      percent = (float)i/MAX_DOTS *100;
      printf("LOADING %s %.01f%c", dots, percent,'%');
      Sleep(400);
      dots[i] = '.';
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      i++;
    }

    system("COLOR 0A");
    PlaySound(TEXT("Transformers_title.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    while(fgets(image, sizeof(image), f) != NULL){
      printf("%s",image);
    }

}

void ahorcado() {
  char palabra [21];
  char aux [21];
  char repetidas [30];
  char letra;
  int letras = 0, j = 0, i = 0, k = 0, m = 0, ex = 0, correcto = 1, letrabien = 0, repetida = 0;

  printf("Introduce tu palabra, maximo 20 letras: ");
  scanf("%s", aux);
  while (getchar() != '\n');
  system("COLOR 07");
  clear();
  letras = strlen(aux);         //longitud palabra.
  PlaySound(TEXT("Transformers_Start.wav"), NULL, SND_ASYNC|SND_FILENAME);

  //llenamos la palabra con asteriscos.
  for (i = 0; i < letras; i++) {
    palabra[i] = '_';
  }
  palabra[i] = '\0';

  printf("\n[%s]\n", palabra);
  i = 0;

  //vaciamos la cadena de letras repetidas.
  do{
    repetidas[i] = '\0';
    i++;
  }while(i < 30);

  i = 0;        //inicializamos el contador de i.

  do {

    printf("Letra: ");
    scanf("%c", &letra);
    while (getchar() != '\n');
    clear();
    repetida = 0;
    k = 0;

    do{

      if (letra == repetidas[k]) {
        repetida = 1;
      }
      k++;
    }while (repetidas[k] != '\0' && repetida == 0);

    if (repetida == 0) {
      m++;
      repetidas[m] = letra;
      repetida = 0;
    }

    if (repetida == 1) {
      printf("Letra repetida!\n");
      repetida = 0;
      printf("\n[%s]\n", palabra);
    }else{

      do{

        if (letra == aux[i]) {
          printf("Letra Correcta!\n");
          ex ++;
          palabra[i] = letra;
          letrabien = 1;
        }
        i++;
      }while (aux[i] != '\0');

      if (letrabien == 0) {
        printf("Letra Incorrecta!\n");
        j++;
        printf("\n[%s]\n", palabra);
      }else{
        printf("\n[%s]\n", palabra);
      }

      if (j == 1) {
        printf("\n  O\n");
      }

      if (j == 2) {
        printf("  O\n");
        printf("  |\n");
      }

      if (j == 3) {
        printf("  O\n");
        printf("  |\n");
        printf(" / \\");
        printf("\n");
      }

      if (j == 4) {
        printf("  O\n");
        printf(" -|-\n");
        printf(" / \\");
        printf("\n");
      }

      if (j == 5) {
        printf("  X\n");
        printf(" -|-\n");
        printf("_/ \\_");
        printf("\n");
      }


      letrabien = 0;
      i = 0;

      if (ex == letras){
        correcto = 0;
        printf("Has Ganado!\n");
      }
      if (j == 5 && correcto != 0) {
        printf("Has Perdido!\n");
        PlaySound(TEXT("Transformers_GameOver.wav"), NULL, SND_ASYNC|SND_FILENAME);
      }
    }

  } while(j < 5 && correcto != 0);
  Sleep(10000);
}


void clear (){
  system("cls");
}
