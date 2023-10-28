#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(const char *inputFileName, const char *outputFileName, int shift) {
    FILE *inputFile, *outputFile;
    char ch;

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        exit(1);
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        if (isalpha(ch)) {
            if (islower(ch))
                ch = 'a' + (ch - 'a' + shift) % 26;
            else
                ch = 'A' + (ch - 'A' + shift) % 26;
        }
        fputc(ch, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption complete.\n");
}

void decryptFile(const char *inputFileName, const char *outputFileName, int shift) {
    // Decryption is the same as encryption, but with a negative shift value
    encryptFile(inputFileName, outputFileName, -shift);
    printf("Decryption complete.\n");
}

int main() {
    int choice, shift;
    char inputFileName[100], outputFileName[100];

    printf("File Encryption and Decryption Tool\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    printf("Enter the Caesar cipher shift (a number between 1 and 25): ");
    scanf("%d", &shift);

    if (choice == 1) {
        encryptFile(inputFileName, outputFileName, shift);
    } else if (choice == 2) {
        decryptFile(inputFileName, outputFileName, shift);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

