#include<stdio.h>
#include<ctype.h> // Used to check whether second argument is an int.
#include<stdlib.h>
#include<string.h>
#include<cs50.h>

int key = 0;

int main(int argc, string argv[])
{
    
    if (argc == 2 && isdigit(*argv[1]))
    {
        
        // Convert the value of user input to int
        string userKey = argv[1];
        for (int i = 0; i < strlen(userKey); i++ ){
            if (!isdigit(userKey[i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            } 
            else 
            {
                key = atoi(userKey);
            }
        }

        // Get user input && print prompt tp display answer
        string plaintext = get_string("plaintext:  "); 
        printf("ciphertext: ");
        
        int stringLength = strlen(plaintext);
        // Loop through user entered tex until we come across null terminating character.
        for (int i = 0; i < stringLength; i++)
        {
            // Retrieve the current character we are working with.
            char letter = plaintext[i];
            
            // Check if retrieved character is both a letter from A - Z and lowercase.
            if (isalpha(letter) && islower(letter)) 
            {
                // Convert the ASCII value to a zero index for easier working.
                printf("%c", ((letter - 'a' + key) % 26 + 'a'));
            }
            
            // Check if retrieved character is both a letter from A - Z and lowercase.
            else if (isalpha(letter) && isupper(letter)) 
            {
                // Convert the ASCII value to a zero index for easier working.
                printf("%c", ((letter - 'A' + key) % 26 + 'A'));
            }
            
            // If the character we are working with is not an alphabet, then no need to 
            // work on it and we just print it as is.
            else
            {
                printf("%c", letter);
            }
        }
        
        // Finish the program by throwing the commandline prompt to the next line. 
        printf("\n");
    }
    
    // Wrong command line usage.
    else
    {

        printf("Usage: ./caesar key\n");
        return 1;
       
    }
}

