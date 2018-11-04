#include <stdio.h>
#include <stdlib.h>

#include "personalAssistant.h"
#include "BinarySearchTreeAPI.h"

Rule *createRule(char* keyWord, char* sentence, double userRating, double systemRating, double learningRate, int numOccurences) {

    Rule* rule = malloc(sizeof(Rule));
    rule->keyWord = malloc(sizeof(char) * strlen(keyWord));
    rule->keyWord = keyWord;
    rule->sentence = malloc(sizeof(char) * strlen(sentence));
    rule->sentence = sentence;
    rule->userRating = userRating;
    rule->systemRating = systemRating;
    rule->learningRate = learningRate;
    rule->numOccurences = numOccurences;
    return rule;
}
char *getKeyWord(Rule* rule) {
    return rule->keyWord;
}

char* getSentence(Rule* rule) {
    return rule->sentence;
}

double getUserRating(Rule* rule) {
    return rule->userRating;
}
double getSystemRating(Rule* rule) {
    return rule->systemRating;
}

double getlearningRate(Rule* rule) {
    return rule->learningRate;
}

int getnumOccurences(Rule* rule) {
    return rule->numOccurences;
}

void printRule(void * r) {
    printf("%-15s %-15.2lf %-15.2lf %d\n", getKeyWord(r), getUserRating(r), getSystemRating(r), getnumOccurences(r));
    return;
}

void deleteRule(void * r) {
    free((Rule*)r);
    return;
}

int compareRules( const void * a, const void * b) {
    Rule *ia = (Rule*)a;
    Rule *ib = (Rule*)b;
    return strcmp(ia->keyWord, ib->keyWord);
}

int stringCompareRule( const void * a, const void * b) {
    Rule *ia = (Rule*)a;
    char *ib = (char*)b;

    return strcmp(ia->keyWord, ib);
}

FILE *openFile(char filename[]) {
    FILE* infile = NULL;
    infile = fopen(filename, "r");
    
    while (infile == NULL) {
        printf("%%\n");
        fgets(filename, 100, stdin);
        filename[(strlen(filename)) - 1] = '\0';
        infile = fopen(filename, "r");
    }

    return infile; 
}
