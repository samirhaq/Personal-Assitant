#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "BinarySearchTreeAPI.h"

/**
*Struct of a Rule, contains the keyWord, sentence, userRating, systemRating and learningRate values of the rule
**/
typedef struct rule {
    char* keyWord;
    char* sentence;
    double userRating;
    double systemRating;
    double learningRate;
    int numOccurences;
} Rule;

/**Function to allocate memory for the Rule struct and populate it.
*@return the Rule struct
*@param the keyWord of the rule
*@param the sentence of the rule
*@param The userRating of the rule
*@param The systemRating of the rule
*@param The learningRate of the rule
*@param The number of occurences of the rule
**/
Rule *createRule(char* keyWord, char* sentence, double userRating, double systemRating, double learningRate, int numOccurences);

/**Function to get the keyWord of the rule
*@return the keyWord of the rule
*@param a Rule struct
**/
char *getKeyWord(Rule* rule);

/**Function to get the sentence from the rule
*@return the sentence of the rule
*@param a Rule struct
**/
char* getSentence(Rule* rule);

/**Function to get the userRating of the rule
*@return the userRating of the rule
*@param a Rule struct
**/
double getUserRating(Rule* rule);

/**Function to get the systemRating of the rule
*@return the systemRating of the rule
*@param a Rule struct
**/
double getSystemRating(Rule* rule);

/**Function to get the learningRate of the rule
*@return the learningRate of the rule
*@param a Rule struct
**/
double getlearningRate(Rule* rule);

/**Function to get the number of occurences of the rule
*@return the number of occurences of the rule
*@param a Rule struct
**/
int getnumOccurences(Rule* rule);

/**Function to print the Rule struct
*@param the item to print out
**/
void printRule(void * r);

/**Function to free the memory from the Rule struct.
*@param Item that needs to be deleted from the list.
**/
void deleteRule(void * r);

/**Function to compare two items
*@return an integer value, 0: if the values are equal
*@param One of the items to compare
*@param The second item to compare against the first one
**/
int compareRules( const void * a, const void * b);

/**Function to compare two items to check for equality in deleteList
*@return an integer value, 0: if the values are equal
*@param One of the items to compare
*@param The second item(string) to compare against the first one
**/
int stringCompareRule( const void * a, const void * b);

/**Function to open the file entered
*@return a file pointer
*@param the file entered in argv
**/
FILE *openFile(char filename[]);

