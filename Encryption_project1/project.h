/*************************************************************
CIS 241 project 1 header
@author Gionata Bonazzi
@version 13 February 2018
*************************************************************/

#ifndef project_h
#define project_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*************************************************************
The method takes a word and makes a string containing first
the word, then the rest of the alphabet in reverse order.
@param word the encryption key.
@return the address of the string.
*************************************************************/
char* encryptionAlphabet(char* word);

/*************************************************************
 Create a rearranged alphabet.
 start with the standard alphabet from 'a' to 'z'.
 Take the encrypted alphabet as well.
 The relative position of a character in the ecnrypted alphabet
 and 'a' is the index for the new array.
 In that position, put the first available letter from the
 standard alphabet.
 A letter is available when it has never been copied in the
 new array, so repetition is not allowed.
 the array's scan goes from the left to the right (from 0 to the end).
 This way, the relative position of an encrypted letter from 'a'
 gives the index for its decrypted counterpart in the new array.
 @param eArr the encrypted alphabet.
 @return the address of a string containing the rearranged alphabet
 *************************************************************/
char* decryptionAlphabet(char* word);

/*************************************************************
Method to encrypt the contents of a file.
@param key word to use for encryption.
@param source the file to encrypt.
@param target the encrypted copy of the original file.
*************************************************************/
void encryption(char* key, FILE* source, FILE* target);

/*************************************************************
Method to decrypt the contents of a file.
@param key word to use for decryption.
@param source the file to decrypt.
@param target the decrypted copy of the encrypted file.
*************************************************************/
void decryption(char* key, FILE* source, FILE* target);

/*************************************************************
Method containing different error messages.
Pass an integer, and print the corresponding error.
@param error an integer associated with an error essage.
*************************************************************/
void emergencyStop(int error);

#endif /* project_h */
