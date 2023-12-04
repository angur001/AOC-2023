#include <stdio.h>
#define MAX_LINE_LENGTH 256  // Maximum length of a line in the file
#include <ctype.h>
#include <stdlib.h> 
#include <string.h>



// --------------------------------- SECOND PART --------------------------------------------

int main() {
    FILE *filePointer;
    char line[MAX_LINE_LENGTH];
    int sum = 0;

    typedef struct {
        int value;
        int key;
        const int num;
    } character;

    const char *digits[ ] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    printf("%s\n", digits[5]);

    


    // Open the file in read mode
    filePointer = fopen("day1.txt", "r");

    // Check if the file is opened successfully
    if (filePointer == NULL) {
        printf("Unable to open the file.\n");
        return -1;
    }

    // Read and print each line of the file until the end
    while (fgets(line, sizeof(line), filePointer)) {

        int right = 0;
        int left = 0;
        int flag = 0;

        character characters[9] = {
            {0, 3, 1},
            {0, 3, 2},
            {0, 5, 3},
            {0, 4, 4},
            {0, 4, 5},
            {0, 3, 6},
            {0, 5, 7},
            {0, 5, 8},
            {0, 4, 9}
        };

        for (int i = 0; i < strlen(line); i++) {
            if (flag == 1) {
                break;
            }
            if (isdigit(line[i])) {
                left = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 9; j++) {
                    if (line[i] != digits[j][characters[j].value]) {
                        characters[j].value = 0;
                    }
                    if (line[i] == digits[j][characters[j].value]) {
                        characters[j].value++;
                        if (characters[j].value == characters[j].key) {
                            left = characters[j].num;
                            flag = 1;
                            break;
                        }
                    } 
                } 
            }
        }

        // reset values
        for (int i = 0; i < 9; i++) {
            characters[i].value = characters[i].key - 1;
        }
        flag = 0;

        for (int i = strlen(line)-1 ; i >= 0; i--) {
            char current = line[i];

            if (flag == 1) {
                break;
            }
            if (isdigit(line[i])) {
                right = line[i] - '0';
                break;
            } else {
                for (int j = 0; j < 9; j++) {

                    if (line[i] != digits[j][characters[j].value]) {
                        characters[j].value = characters[j].key - 1;;
                    }

                    if (line[i] == digits[j][characters[j].value]) {
                        characters[j].value--;
                        if (characters[j].value < 0) {
                            right = characters[j].num; 
                            flag = 1;
                            break;
                        }
                    }
                } 
            }
        }


        printf("%d%d ;", left, right);
        sum += right + 10*left;
        printf(" %s", line);


    }

    // Close the file
    fclose(filePointer);
    printf("\nSum: %d\n", sum);

    return 0;
}

// --------------------------------- FIRST PART --------------------------------------------

/*
int main() {
    FILE *filePointer;
    char line[MAX_LINE_LENGTH];
    int sum = 0;


    // Open the file in read mode
    filePointer = fopen("day1.txt", "r");

    // Check if the file is opened successfully
    if (filePointer == NULL) {
        printf("Unable to open the file.\n");
        return -1;
    }

    // Read and print each line of the file until the end
    while (fgets(line, sizeof(line), filePointer)) {

        char temp[3];
        temp[2] = '\0';

        for (int i = 0; i < strlen(line); i++) {
            if (isdigit(line[i])) {
                temp[0] = line[i];
                break;
            }
        }

        for (int i = strlen(line)-1 ; i >= 0; i--) {
            if (isdigit(line[i])) {
                temp[1] = line[i];
                break;
            }
        }

        sum += atoi(temp);
        printf("%s\n", temp);
    }

    // Close the file
    fclose(filePointer);
    printf("Sum: %d\n", sum);

    return 0;
}
*/
