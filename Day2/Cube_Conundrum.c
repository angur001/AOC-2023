#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256 // Maximum length of a line

// --------------------------------- SECOND PART --------------------------------------------


int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    const char * separators = ":,;";
    const char * innerSeparators = " ";


    // Open the file for reading
    file = fopen("day2.txt", "r");
    if (file == NULL) {
        perror("Error opening the file");
        return EXIT_FAILURE;
    }
    
    int sum = 0;
    int game = 0;
    // Read and print each line until the end of the file
    while (fgets(line, sizeof(line), file) != NULL) {

        int number;
        char word[10]; // 10 is the maximum length of a word
        //int flag = 0; // 0 -> possible , 1 -> impossible
        int min_red = 0;
        int min_green = 0;
        int min_blue = 0;

        // On cherche à récupérer, un à un, tous les mots (token) de la phrase
        // et on commence par le premier.
        char * strToken = strtok ( line, separators );

        while ( strToken != NULL ) {

        if (sscanf(strToken, "%s %d", word, &number) == 2) {
            if (strcmp(word, "Game") == 0) {
                if (number == game + 1) {
                    game++;
                } else {
                    printf("Invalid game number\n");
                }
            } else {
                printf("Invalid format\n");
            }
        } else {
            // Parsing the number and word from the string format "red ##"
            if (sscanf(strToken, " %d %s", &number, word) == 2) {
                if (strcmp(word, "red") == 0) {
                    if (number > min_red) {
                        min_red = number; 
                    }
                } else if (strcmp(word, "green") == 0) {
                    if (number > min_green) {
                        min_green = number;
                    }
                } else if (strcmp(word, "blue") == 0) {
                    if (number > min_blue) {
                        min_blue = number; 
                    }
                } else {
                    printf(" %s : Invalid color\n", word);
                }
            } else {
                printf("Invalid format\n");
            }
        }
        
                strToken = strtok ( NULL, separators );
                
        }

        
        sum += min_red * min_green * min_blue;
        printf("Game %d : Red : %d ; Green : %d ; Blue : %d ; Sum : %d\n", game, min_red, min_green, min_blue, sum);
        

    }

    printf("Sum: %d\n", sum);
    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}

// --------------------------------- FIRST PART --------------------------------------------

/*
int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    const char * separators = ":,;";
    const char * innerSeparators = " ";
    const int RED_MAX = 12;
    const int GREEN_MAX = 13;
    const int BLUE_MAX = 14;

    // Open the file for reading
    file = fopen("day2.txt", "r");
    if (file == NULL) {
        perror("Error opening the file");
        return EXIT_FAILURE;
    }
    
    int sum = 0;
    int game = 0;
    // Read and print each line until the end of the file
    while (fgets(line, sizeof(line), file) != NULL) {

        int number;
        char word[10]; // 10 is the maximum length of a word
        int flag = 0; // 0 -> possible , 1 -> impossible

        // On cherche à récupérer, un à un, tous les mots (token) de la phrase
        // et on commence par le premier.
        char * strToken = strtok ( line, separators );

        while ( strToken != NULL ) {

        if (sscanf(strToken, "%s %d", word, &number) == 2) {
            if (strcmp(word, "Game") == 0) {
                if (number == game + 1) {
                    game++;
                } else {
                    printf("Invalid game number\n");
                }
            } else {
                printf("Invalid format\n");
            }
        } else {
            // Parsing the number and word from the string format "red ##"
            if (sscanf(strToken, " %d %s", &number, word) == 2) {
                if (strcmp(word, "red") == 0) {
                    if (number > RED_MAX) {
                        flag = 1; 
                    }
                } else if (strcmp(word, "green") == 0) {
                    if (number > GREEN_MAX) {
                        flag = 1; 
                    }
                } else if (strcmp(word, "blue") == 0) {
                    if (number > BLUE_MAX) {
                        flag = 1; 
                    }
                } else {
                    printf(" %s : Invalid color\n", word);
                }
            } else {
                printf("Invalid format\n");
            }
        }
        
                strToken = strtok ( NULL, separators );
                
        }

        if (flag == 0) {
            sum += game;
            printf("Game %d : possible ; Sum : %d\n", game, sum);
        } else {
            printf("Game %d : impossible\n", game);
        }

    }

    printf("Sum: %d\n", sum);
    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}
*/
