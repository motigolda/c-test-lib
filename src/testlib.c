#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "testlib.h"

typedef char* output_color;

#define COLOR_RED     "\033[0;31m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_WHITE   "\033[0;37m"
#define COLOR_YELLOW  "\033[1;33m"

#define TEMPLATE_STR_ASSERTION_PRINT "expected: \t%s\nactual: \t%s\n"
#define TEMPLATE_INT_ASSERTION_PRINT_DECIMAL "expected: \t%d\nactual: \t%d\n"
#define TEMPLATE_INT_ASSERTION_PRINT_HEX "expected: \t0x%x\nactual: \t0x%x\n"
#define TEMPLATE_BOOL_ASSERTION_PRINT "expected: \t%s\nactual: \t%s\n"
#define TEMPLATE_CHAR_ASSERTION_PRINT "expected: \t%d\nactual: \t%d\n"

#define NULL_TO_PRINT "NULL"

static void SetOutputColor(output_color color);

static void PrintTestOutput(bool success, char *description);

static bool CompareStrings(char *str1, char *str2);

bool AssertStrEquals(char *expected, char *actual, char *description){
    bool success = CompareStrings(expected, actual);

    unsigned int description_length = 0;
    if (description != NULL)
        description_length = strlen(description);

    size_t output_text_length = description_length;
    if (expected != NULL)
        output_text_length += strlen(expected);
    else
        output_text_length += strlen(NULL_TO_PRINT);

    if (actual != NULL)
        output_text_length += strlen(actual);
    else
        output_text_length += strlen(NULL_TO_PRINT);
        
    if(!success)
        output_text_length += strlen(TEMPLATE_STR_ASSERTION_PRINT);

    char *output_text = malloc(output_text_length);
    memset(output_text, 0, output_text_length);
    if(!success)
        sprintf(output_text, 
                TEMPLATE_STR_ASSERTION_PRINT, 
                expected != NULL ? expected : NULL_TO_PRINT, 
                actual != NULL ? actual : NULL_TO_PRINT);

    if(description != NULL)
        strcat(output_text, description);

    PrintTestOutput(success, output_text);

    free(output_text);

    return success;
}

bool AssertIntEquals(int expected, int actual, char *description){
    bool success = expected == actual;

    unsigned int description_length = 0;
    if (description != NULL)
        description_length = strlen(description);
    
    size_t output_text_size = sizeof(unsigned int)*16  + description_length;

    if (!success)
        output_text_size += strlen(TEMPLATE_INT_ASSERTION_PRINT_DECIMAL);

    char *output_text = malloc(output_text_size);
    memset(output_text, 0, output_text_size);

    if (!success)
        sprintf(output_text, 
            TEMPLATE_INT_ASSERTION_PRINT_DECIMAL, 
            expected, actual);

    strcat(output_text, description);

    PrintTestOutput(success, output_text);

    free(output_text);

    return success;
}

bool AssertBoolEquals(bool expected, bool actual, char *description){
    bool success = expected == actual;

    unsigned int description_length = 0;
    if (description != NULL)
        description_length = strlen(description);
    
    size_t output_text_size = sizeof(unsigned int)*16  + description_length;

    if (!success)
        output_text_size += strlen(TEMPLATE_BOOL_ASSERTION_PRINT);

    char *output_text = malloc(output_text_size);
    memset(output_text, 0, output_text_size);

    if (!success)
        sprintf(output_text, 
            TEMPLATE_BOOL_ASSERTION_PRINT, 
            expected ? "true" : "false", 
            actual ? "true" : "false");

    strcat(output_text, description);

    PrintTestOutput(success, output_text);

    free(output_text);

    return success;   
}

bool AssertUnsignedCharEquals(unsigned char expected, unsigned char actual, char *description){
    bool success = expected == actual;

    unsigned int description_length = 0;
    if (description != NULL)
        description_length = strlen(description);
    
    size_t output_text_size = sizeof(unsigned int)*16  + description_length;

    if (!success)
        output_text_size += strlen(TEMPLATE_CHAR_ASSERTION_PRINT);

    char *output_text = malloc(output_text_size);
    memset(output_text, 0, output_text_size);

    if (!success)
        sprintf(output_text, 
            TEMPLATE_CHAR_ASSERTION_PRINT, 
            expected, actual);

    strcat(output_text, description);

    PrintTestOutput(success, output_text);

    free(output_text);

    return success;
}

static void PrintTestOutput(bool success, char *description){
    if (success)
        SetOutputColor(COLOR_GREEN);
    else 
        SetOutputColor(COLOR_RED);

    printf("%s\n", description);

    SetOutputColor(COLOR_WHITE);
}

static void SetOutputColor(output_color color){
    printf("%s", color);
}

static bool CompareStrings(char *str1, char *str2){
    if (str1 == NULL && str2 == NULL)   
        return true;

    if (str1 == NULL && str2 != NULL)
        return false;

    if (str1 != NULL && str2 == NULL)
        return false;

    return strcmp(str1, str2) == 0;
}