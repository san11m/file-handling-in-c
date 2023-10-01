#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char ch;
    int wordCount = 0;

    // Get the input file name from the user
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    // Open the input file for reading
    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("Could not open the input file.\n");
        return 1; // Exit the program with an error code
    }

    // Get the output file name from the user
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    // Open the output file for writing
    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL) {
        printf("Could not open the output file.\n");
        fclose(inputFile); // Close the input file
        return 1; // Exit the program with an error code
    }

    // Count the number of words in the input file
    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            wordCount++;
        }
    }

    // Close the input file
    fclose(inputFile);

    // Write the word count to the output file
    fprintf(outputFile, "Word count: %d\n", wordCount);

    // Close the output file
    fclose(outputFile);

    printf("Word count has been written to %s.\n", outputFileName);

    return 0; // Exit the program successfully
}
