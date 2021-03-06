/*************************************************************
CIS 241 project 1
@author Gionata Bonazzi
@version 13 February 2018
*************************************************************/
#include "project.h"
#define SIZE 27 //considering space for 26 letters of the alphabet and the '\0' at the end.


char* encryptionAlphabet(char* word){
    char* result = malloc(SIZE*sizeof(char)); //The encrypted alphabet
    memset(result, '\0', sizeof(*result));//Set every char in result to '\0'
    int found = 1; //using it as a boolean
    int position = strlen(word);
    result = strcat(result, word);//Append the key at the beginning of the alphabet
    for(int i = 'z' - 'a'; i >= 0; i--){//since SIZE accounts for the final '\0', I can't use it as initial value of i.
        found = 1;
        for(int j = 0; j < strlen(word); j++){
            if('a' + i == word[j]){
                found = 0;
                break;
            }
        }
        if(found == 0) continue;
        result[position] = (char) ('a' + i);
        position++;
    }
    result[position] = '\0';
    return result;
}

char* decryptionAlphabet(char* word){
    char* encAlphabet = encryptionAlphabet(word);
    char* decAlphabet = malloc(SIZE * sizeof(char));
    int index;
    for(int i = 0; i < SIZE; i++){
        index = encAlphabet[i] - 'a'; //The relative position of a letter from 'a' is the index of the rearranged array
        decAlphabet[index] = (char) ('a' + i); //Assign a letter of the alphabet to the index linked to its encrypted counterpart.
    }
    decAlphabet[SIZE-1] = '\0';
    free(encAlphabet);
    return decAlphabet;
}

void encryption(char* key, FILE* source, FILE* target){
    char* encAlphabet = encryptionAlphabet(key); //the array used for encryption
    char och; //the original character
    char ech; //the encrypted character
    while(!feof(source)){
        fscanf(source, "%c", &och);
        if(islower(och)) ech = encAlphabet[och-'a'];
        else if(isupper(och)) ech = toupper(encAlphabet[och-'A']); //Preserve the original uppercase letter.
        else ech = och; //Non-letter chars are maintained as they are.
        fprintf(target, "%c", ech);
    }
    free(encAlphabet); //free the memory allocated.
}

void decryption(char* key, FILE* source, FILE* target){
    char* decAlphabet = decryptionAlphabet(key); //the array used for decryption
    char ech; //the encrypted character
    char dch; //the decrypted character
    while(!feof(source)){
        fscanf(source, "%c", &ech);
        if(islower(ech)) dch = decAlphabet[ech-'a'];
        else if(isupper(ech)) dch = toupper(decAlphabet[ech-'A']);
        else dch = ech;
        fprintf(target, "%c", dch);
    }
    free(decAlphabet);
}

void emergencyStop(int error){
    switch(error){
        case 0:     printf("Not enough arguments");
            break;
        case 1:     printf("Error in opening a file");
            break;
        case 2:     printf("Argument for encryption/decription not valid");
            break;
        default:    printf("Unknown Error");
    }
    exit(1);
}
