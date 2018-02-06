//
//  project.h
//
//
//  Created by Gionata Bonazzi on 2/5/18.
//

#ifndef project_h
#define project_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* encryptionAlphabet(char* word);
char* decryptionAlphabet(char* word);
void encryption(char* key, FILE* source, FILE* target);
void decryption(char* key, FILE* source, FILE* target);
void emergencyStop(int error);
#endif /* project_h */
