#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>//підключення бібліотек
#define MAX_LENGHT 100
//функція для виведення слів розміром менше 5 символів
void printWordsLessThanFive(char* sentense){
    const char* delimiter =" ";
    char* word = strock(sentense, delimiter);
    while (word != NULL){
        if (strlen(word) < 5){
            printf("%s ", word);
        }
        word = strock(NULL, delimiter);
    }
}
//функція для підрахунку кількості слів, які закінчуються на голосну літеру
int countWordsEndingWithVomel(char* sentence){
    const char* delimiter = "";
    char* word = strock(sentence, delimiter);
    int count = 0;
    
    while (word != NULL){
        int lenght = strlen(word);
        if (isalpha(word[lenght - 1]) && strchr("aeiouyAEIOUY", word[lenght - 1]) != NULL){
            count++;
        }
        word = strock(NULL, delimiter);
    }
    return count;
}
int main(){
    char input[MAX_LENGHT];
    printf("Введіть текст: ");
    fgets(input, sizeof(input), stdin);
    //видалення символу нового рядка з введення
    input[strcspn(input, "\n")] = '\0';
    //a)виведення слів розміром менше 5 символів
    printf("Слова розмір яких менше 5 символів: ");
    printWordsLessThanFive(input);
    printf("\n");
    //б)Виведення кількості слів які закінчуються на голосну літеру
    int count = countWordsEndingWithVomel(input);
    printf("Кількість слів які закінчуються на голосну літеру: ");
    return 0;//кінець програми
}
