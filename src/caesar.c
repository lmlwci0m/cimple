/*
 * caesar: basic implementation of caesar cipher with variable key.
 * WARNING: ONLY FOR LEARNING PURPOSES.
 *
 * usage: 
 *     encryption
 *         from console text:
 *             echo plain text | test > cipher.txt
 *         from file:
 *             cat plain.txt | test > cipher.txt
 *         with key = 10:
 *             cat plain.txt | test 0 10 > cipher.txt
 *     decryption    
 *         from file:
 *             cat cipher.txt | test 1 > plain.txt
 *         with key = 10:
 *             car cipher.txt | test 1 10 > plain.txt
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    
    int c;

    int opt;
    int key;

    opt = 0;
    if (argc > 1) {
        opt = atoi(argv[1]);
    }

    key = 3;
    if (argc > 2) {
        key = atoi(argv[2]);
    }

    c = fgetc(stdin);
    while (c != EOF) {
        switch (opt) {
        case 1:
            c -= key;
            break;
            
        case 0:
        default:
            c += key;
            break;

        }

        fputc(c, stdout);
        c = fgetc(stdin);
    }

    return EXIT_SUCCESS;

}
