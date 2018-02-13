/*************************************************************
Main method to run the CIS 241 project 1 code.
@author Gionata Bonazzi
@version 13 February 2018
*************************************************************/

#include "project.h"

int main(int argc, char* argv[]){
	if(argc != 5) emergencyStop(0);
	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen(argv[3], "w");
  char* key = argv[2];
  for(int i = 0; key[i] != '\0'; i++) key[i] = tolower(key[i]);
	if(in == NULL || out == NULL) emergencyStop(1);
	if(strcmp(argv[4], "e")) encryption(key, in, out);
	else if(strcmp(argv[4], "d")) decryption(key, in, out);
	else emergencyStop(2);
  fclose(in);
  fclose(out);
  return 0;
}
