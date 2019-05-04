#include <malloc.h>
#include <stdlib.h>
#include <math.h>

/*-------------------------------------------------Block of functions with verification of string-------------------------------------------------*/
int CodeOfSymb(char s);
bool verification(char *val);
/*-------------------------------------------------end of block of functions with verification of string-------------------------------------------------*/


//add into stack
struct Node *pop_stack(struct Node *head);
//delete from stack
struct Node *push_stack(struct Node *head, char *val);
//show stack (need stdio.h)
void show(struct Node *head);


//distribution symbols from string into stacks with operation and result
void stackAllocation(struct Node *head1, struct Node *head2, char *str);


/*-------------------------------------------------block of functions with arithmetic operations-------------------------------------------------*/
char* myPlus(char *str1, char *str2);
char* myMinus(char *str1, char *str2);
char* myMult(char *str1, char *str2);
char* myDel(char *str1, char *str2);
char* mySin(char *str1);
char* myCos(char *str1);
char* myTg(char *str1);
char* myCtg(char *str1);
char* myLn(char *str1);
char* myPow(char *str1, char *str2);
char* myFak(char *str1);
/*-------------------------------------------------end of block of functions with arithmetic operations-------------------------------------------------*/



/*-------------------------------------------------return code of operation in stack with operation and find result-------------------------------------------------*/
char* decode(char *op);
void exec(struct Node *head1, struct Node *head2);
/*-------------------------------------------------end of this block of functions-------------------------------------------------*/

