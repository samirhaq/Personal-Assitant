Samir Haq							0968761
CIS*2520							Assignment 4
December 3rd, 2017					samir@uoguelph.ca
********************************************************************************************************
Program Description:
The program acts as a personal assistant that you can communicate with. You are able to add rules, remove rules,
view the rules, modify the rules and discuss with the assistant and offer it feedback.
********************************************************************************************************
Compilation:
To compile this code: 
1. Enter make or make program
2. Enter bin/main assets/<textfile>.txt

To run the testing program:
1. Enter make testing
2. Enter bin/testMain

Make clean removes executable files
********************************************************************************************************
Know Limitations, Issues and Errors:
If the format of the textfile is incorrect the program will not run properly.

********************************************************************************************************
Personalization
Modified createBinTree to include a second compare function in order to compare with a string that the user
entered rather than only comparing with another node. Also added helper recursive functions for insert,
removeNode, printInOrderHelper, printPreOrderHelper, printPostOrderHelper and find to recursively traverse
through the tree using the original functions. Also added getMinimum and getMaximum helper functions in order
to help with the 2 children delete case (Although getMaximum is never actually used but can still be useful) 