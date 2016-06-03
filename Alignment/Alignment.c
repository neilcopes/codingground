#include <stdio.h>
#include <stdlib.h>

int main()

{ // begin the main function

    // global variables
    int index     = 0;
    int file_size = 0;
    int file_byte = 0;
    char *FASTA   = NULL;
    FILE *file    = NULL;
    
    // open the FASTA file
    file = fopen("FASTA.txt", "r");
    
    // calculate the size of the file
    while(file_byte != EOF)
    
        { // begin the while statement
        
            // read in the next byte
            file_byte = fgetc(file);
            file_size++;
            
        } // end the while statement
        
    // rewind the file
    rewind(file);
    file_byte = 0;
        
    // set aside the proper amount of memory for FASTA
    FASTA = (char *)malloc(file_size);

    while(file_byte != EOF)
    
        { // begin while statement
        
            // read in the next byte
            file_byte = fgetc(file);
            
            if (file_byte != EOF)
            
             { // the end of the file has not been reached
            
                // transfer the byte to the FASTA variable
                FASTA[index] = (char)file_byte;
                
             } // end if
            
            // increment the index
            index++;
            
        } // end while statement
        
    // print the contents of the file
    printf("%s \n", FASTA);
    
    // close the file
    fclose(file);
    
    // clean up
    free(FASTA);

    return 0;

} // end the main function

