#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])   
{
	if(argc > 1){ //Accepts only 1 command-line argument
		printf("This program does not allow more than one comman-line arguments!\n");
		return 1;
	}
 	char ch;
  	FILE *in, *out;
  	in = fopen ("input.txt","r" );
	out = fopen ("output.txt", "w" );
	if ( in == NULL || out == NULL )	
	{
	printf ( "file could not be opened!\n" );
	exit (1);
	}
	while ( ! feof(in) ){
	fscanf ( in, "%c", &ch );
	if(ch >= 'A' && ch < 'a') ch = 'a' - 'A' + ch; //From upper case to lower case
 	else if(ch >= 'a' && ch <= 'z')  ch = ch - 'a' + 'A';//From lower case to upper case
	fprintf ( out, "%c", ch );
	}
	fclose(in);
	fclose(out);
	return 0;
}
