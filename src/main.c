#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "BinarySearchTreeAPI.h"
#include "personalAssistant.h"

int main(int argc, char * argv[])
{
    FILE *infile = NULL;
    infile = openFile(argv[1]);
    Tree* assistant = createBinTree(&compareRules, &stringCompareRule, &deleteRule);
    char word[25];
    char inputSentence[300];
    char* keyWord;
    char* sentence;
    int i;
    int userInt;
    char userWord[25];
    char userSentence[300];
    double userRating;
    char* findData;

    while (!feof(infile)) {
        fscanf(infile, "%s ", word);
        fgets(inputSentence, 300, infile);
        keyWord = malloc(sizeof(char) * strlen(word));
        strcpy(keyWord, word);
        for (i = 0; i < strlen(keyWord); ++i) {
            keyWord[i] = tolower(keyWord[i]);
        }
        sentence = malloc(sizeof(char) * strlen(inputSentence));
        strcpy(sentence, inputSentence);
        Rule* rule = createRule(keyWord, sentence, 0.5, 0.5, 0.05, 0);
        addToTree(assistant, rule);
    }
    int exit = 0;

    while (exit == 0) {
        Rule* relevantRule = NULL;
        double highestImportance = 0;
        char* tokens;
        printf("\n1: Add a new rule\n");
        printf("2: Remove a rule\n");
        printf("3: Display rule rating\n");
        printf("4: Modify rule rating\n");
        printf("5: Discuss\n\n");
        printf("9: Quit\n");
        printf("Please enter an integer.\n");
        scanf("%d", &userInt);
        getchar();

        switch (userInt) {

            case 1:
                printf("Enter a keyword to add:\n");
                scanf("%s", userWord);
                getchar();
                keyWord = malloc(sizeof(char) * strlen(userWord));
                strcpy(keyWord, userWord);
                for (i = 0; i < strlen(keyWord); ++i) {
                        keyWord[i] = tolower(keyWord[i]);
                }
                if (findInTree(assistant, keyWord) == NULL) {
                    printf("Enter a one-line sentence:\n");
                    fgets(userSentence, 300, stdin);
                    sentence = malloc(sizeof(char) * strlen(userSentence));
                    strcpy(sentence, userSentence);
                    printf("How important is this rule?(0-1):\n");
                    scanf("%lf", &userRating);
                    getchar();
                    Rule* rule = createRule(keyWord, sentence, userRating, 0.5, 0.05, 0.5);
                    addToTree(assistant, rule);
                    printf("Rule added!\n");
                }

                else {
                    printf("Rule for keyword already exists.\n");
                }
                
                break;
            
            case 2:
                printf("Please enter a keyword to remove:\n");
                scanf("%s", userWord);
                getchar();
                findData = malloc(sizeof(char) * strlen(userWord));
                strcpy(findData, userWord);
                if (findInTree(assistant, findData) == NULL) {
                    printf("Rule does not exist\n");
                }

                else {
                    removeFromTree(assistant, findData);
                    printf("Rule removed!\n");
                }
                break;

            case 3:
                printInOrder(assistant, printRule);
                break;

            case 4:
                printf("Please enter a keyword for which rule to modify:\n");
                scanf("%s", userWord);
                getchar();
                findData = malloc(sizeof(char) * strlen(userWord));
                strcpy(findData, userWord);
                Rule* rule = findInTree(assistant, findData);
                if (rule == NULL) {
                    printf("Rule does not exist\n");
                }

                else {
                    printf("What do you want to modify the rating to?(0-1):\n");
                    scanf("%lf", &userRating);
                    getchar();
                    rule->userRating = userRating;
                    printf("Rule modified!\n");
                }
                break;

            case 5:
                printf("User:\n");
                fgets(userSentence, 300, stdin);
                tokens = strtok(userSentence, " ");
                while (tokens != NULL) {
                    if (tokens[strlen(tokens) - 1] == '\n') {
                        tokens[strlen(tokens) - 1] = '\0';
                    }

                    if (!isalpha(tokens[strlen(tokens) - 1])) {
                        tokens[strlen(tokens) - 1] = '\0';
                    }
                    for (i = 0; i < strlen(tokens); ++i) {
                        tokens[i] = tolower(tokens[i]);
                    }
                    Rule* rule = findInTree(assistant, tokens);
                    if (rule != NULL) {
                        if ((rule->userRating + rule->systemRating) >= highestImportance) {
                            highestImportance = rule->userRating + rule->systemRating;
                            relevantRule = rule;
                        }
                    }
                    tokens = strtok(NULL, " ");
                }
                if (relevantRule != NULL) {
                    relevantRule->numOccurences += 1;
                    printf("Personal Assistant: %s\n", relevantRule->sentence);
                    printf("Was this feedback helpful \'y\' or \'n\':\n");
                    char userFeedback;
                    scanf(" %c", &userFeedback);
                    getchar();

                    if (userFeedback == 'n') {
                        relevantRule->systemRating = relevantRule->systemRating - (relevantRule->systemRating * relevantRule->learningRate/relevantRule->numOccurences);
                    }

                    else if (userFeedback == 'y') {
                        relevantRule->systemRating = relevantRule->systemRating + (relevantRule->systemRating * relevantRule->learningRate/relevantRule->numOccurences);
                    }

                    else {
                        printf("I'm sorry you did not give me valid feedback so I cannot adjust :/\n");
                    }
                }

                else {
                    printf("Sorry I have no knowledge on this topic yet :(\n");
                }
                break;

            case 9:
                printf("See you again soon!\n");
                exit = 1;
                break;
            
            default:
                printf("I don't understand... please try again\n");
                break;
        } 
    }
    destroyBinTree(assistant);  
    fclose(infile);
    return 0;
}





