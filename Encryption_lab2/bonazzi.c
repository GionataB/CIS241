#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt_decrypt(char ch, int k);
void setKeys(char* word, int* keys, int choice);

int main(int argc, char* argv[])
{
	int choice = 0, index, key[4];
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher inputFile key outputFile option(e or d)\n");
		printf ("Option e for encryption and d for decryption");
		exit(1);
	}

	if (strcmp(argv[4],"d")==0) choice = 1; //decryption

	setKeys(argv[2], key, choice);//Set the keys

	fin = fopen(argv[1], "r");
	fout = fopen(argv[3], "w");

  if (fin ==  NULL || fout == NULL)
	{
		printf("File could not be opened!\n");
		exit(1);
	}

	index = 0;//initialize the index to 0

	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt_decrypt(ch, key[index]));
		index = (index + 1) % 4;
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

char encrypt_decrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';

	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';

	return ch;
}

//Fill an array of keys.
void setKeys(char* word, int* keys, int choice){
	for(int i = 0; i < 4; i++){
		keys[i] = (int)(word[i] - 'A');//the key is the relative position of the letter from 'A'.
		if(choice != 0) keys[i] = -keys[i];//decryption
	}
}
