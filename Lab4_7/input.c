#include "input.h"
#include "convert.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

YESNO ask_yes_no(const char *msg, const char *error_msg) 
{
    char input[10];
    while (true) {
        printf("%s (y/n): ", msg);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return -1;
        }
        if (strcmp(input, "y\n") == 0 || strcmp(input, "Y\n") == 0) {
            return YES;
        } else if (strcmp(input, "n\n") == 0 || strcmp(input, "N\n") == 0) {
            return NO;
        } else {
            printf("%s\n", error_msg);
        }
    }
}

int ask_int(const char *msg, const char *error_msg) 
{                     
    int num;
    char input[100];
    int valid = 0;
    
while (!valid) {
        printf("%s", msg);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        valid = 1;
        for (size_t i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            num = atoi(input);
        } 
        else {
            printf("%s", error_msg);
        }
    }

    return num;
}

double ask_double(const char *msg, const char *error_msg) 
{
    char input[100];
    double result;
    while (true) {
        printf("%s: ", msg);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return 0;
        }
        if (try_convert_to_double(input, &result)) {
            return result;
        } else {
            printf("%s\n", error_msg);
        }
    }
}

char *ask_string(const char *msg, const char *error_msg) 
{
    char input[100];
    while (true) {
        printf("%s: ", msg);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            return NULL;
        }
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) > 0) {
            return strdup(input);
        } else {
            printf("%s\n", error_msg);
        }
    }
}