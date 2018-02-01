#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define alphabetSize 26;
/*************************************************************
 The method uses the ASCII codes to create an array made up of lower case alphabet letters.
 This account for future changes in the alphabet, as long as the ASCII standard is up to date, as long as the alphabetSize variable is changed to accomodate the new letters.
 *************************************************************/
char* makeAlphabet(){
    char* alphabet[alphabetSize];
    for(int i = 0; i < alphabetSize; i++) alphabet[i] = (char) ('a' + i);
    return alphabet;
}

char* encryptionAlphabet(char* key){
    char* alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char* eAlphabet[26];
    strcpy(eAlphabet, key);
    for(int i = strlen(alphabet) - 1; i >= 0; i--){
        for(int j = 0; j < strlen(key); j++){
            if(alphabet[i] == key[i]) continue;
        }
        strcat(eArr, alphabet[i]);
    }
    return eAlphabet;
}

/*************************************************************
 Create a rearranged alphabet.
 start with the standard alphabet from 'a' to 'z'.
 Take the encrypted alphabet as well.
 The relative position of a character in the ecnrypted alphabet and 'a' is the index for the new array.
 In that position, put the first available letter from the standard alphabet.
 A letter is available when it has never been copied in the new array, so repetition is not allowed.
 the array's scan goes from the left to the right (from 0 to the end).
 This way, the relative position of an encrypted letter from 'a' gives the index for its decrypted counterpart in the new array.
 @param eArr the encrypted alphabet.
 *************************************************************/
char* decryptionAlphabet(char* key){
    char* alphabet = "abcdefghijklmnopqrstuvwxyz";
    char* encAlphabet = encryptionAlphabet(key);
    char* decAlphabet;
    int index;
    for(int i = 0; i < 27; i++){
        index = encAlphabet[i] - 'a';
        decAlphabet[index] = alphabet[i];
    }
    return decAlphabet;
}

void encryption(char* key, FILE* source, FILE* target){
    char* eAlphabet = encryptionAlphabet(key); //the array used for encryption
    char och; //the original character
    char ech; //the encrypted character
    while(!feof(source)){
        fscanf(source, "%c", &och);
        if(islower(och)) ech = arr[och-'a'];
        if(isupper(och)) ech = toupper(arr[och-'A']);
        else ech = och;
        fprintf(target, "%c", ech);
    }
}
void decryption(char* key, FILE* source, FILE* target){
    char* dAlphabet = decryptionAlphabet(key); //the array used for decryption
    char ech; //the encrypted character
    char dch; //the decrypted character
    while(!feof(source)){
        fscanf(source, "%c", &ech);
        if(islower(ech)) dch = dAlphabet[ech-'a'];
        if(isupper(ech)) dch = toupper(dAlphabet[ech-'A']);
        else dch = ech;
        fprintf(target, "%c", *dch);
}

void emergencyStop(int error){
	switch(error){
		case 0:     printf("Error in opening a file");
                    break;
		case 1:     printf("Argument for encryption/decription not valid");
                    break;
		default:    printf("Unknown Error");
                    break;
	}
	exit(1);
}
int main(int argc, char* argv){
	if(argc != 5) exit(1);
	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen(argv[3], "w");
    char* key = tolower(argv[2]);
	if(in == NULL || out == NULL) emergencyStop(0);
	if(strcmp(argv[4], "e") == 0) encryption(key, in, out);
	else if(strcmp(argv[4], "d") == 0) decryption(key, in, out);
	else emergencyStop(1);
}
