/*==============================================================================================================
  |																											   |	
  |							Library of function for course work in computer science                            |
  | 																										   |
  ==============================================================================================================*/

//#define _CRT_SECURE_NO_WARNINGS     use it, if you use VS ;)

#include <malloc.h>
#include <stdlib.h>
#include <math.h>

/*-------------------------------------------------Block of functions with verification of string-------------------------------------------------*/
int CodeOfSymb(char s)
{
		switch (s)
		{
			case'0': return 0;
			case'1': return 1;
			case'2': return 2;
			case'3': return 3;
			case'4': return 4;
			case'5': return 5;
			case'6': return 6;
			case'7': return 7;
			case'8': return 8;
			case'9': return 9;
			case'*': return 10;
			case'+': return 11;
			case'-': return 12;
			case'/': return 13;
			case'.': return 14;
			case'^': return 15;
			case'(': return 16;
			case')': return 17;
			case's': return 18;
			case'c': return 19;
			case'l': return 20;
			case'f': return 21;
			case'i': return 22;
			case'n': return 23;
			case'o': return 24;
			case'a': return 25;
			case't': return 26;
		}
}


bool verification(char *val)
{
	int m[13][27] =
	{
		{1, 1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,5,-1,8,10,9,12,-1,-1,-1,-1,-1},
		{7,1,1,1,1,1,1,1,1,1,-1,-1,2,-1,-1,-1,2,-1,8,10,9,12,-1,-1,-1,-1,-1},
		{-1,4,4,4,4,4,4,4,4,4,-1,-1,-1,-1,-1,-1,5,6,8,10,9,12,-1,-1,-1,-1,-1},
		{4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,5,6,8,10,9,12,-1,-1,-1,-1,-1},
		{4,4,4,4,4,4,4,4,4,4,-1,-1,4,-1,-1,-1,5,6,8,10,9,12,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,3,3,3,-1,3,-1,6,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3}
	};
	
	int state=1;
	for (int i = 0; i < 10; i++)
	{
		while (val[i] != '\0')
		{
			state = m[state - 1][CodeOfSymb(val[i])];
			if (state - 1 < 0){
				return false;
				break;
			}
		}
	}
	return true;
}
/*-------------------------------------------------end of block of functions with verification of string-------------------------------------------------*/





//add into stack
struct Node *pop_stack(struct Node *head) { 
	struct Node *cur = head;
	head = head->next;
	free(cur->data);
	free(cur);
	return head;
}

//delete from stack
struct Node *push_stack(struct Node *head, char *val){
	struct Node *cur = (struct Node*)malloc(sizeof(struct Node));
	cur->data = (char*)malloc(sizeof(char));
	strcpy(cur->data, val);
	cur->next = head;
	head = cur;
	return head;
}

//show stack (need stdio.h)
void show(struct Node *head){
	struct Node *cur = head;
	while (cur != NULL){
		printf("%s ", cur->data);
		cur = cur->next;
	}
}

//distribution symbols from string into stacks with operation and result
void stackAllocation(struct Node *head1, struct Node *head2, char *str){
	int i = 0;
	char ch[10], c;
	int j = 0;
	while (str[i] != '\0'){
		switch (str[i]){
			case '0': c = str[i]; ch[j] = c; ++j; break;
			case '1': c = str[i]; ch[j] = c; ++j; break;
			case '2': c = str[i]; ch[j] = c; ++j; break;
			case '3': c = str[i]; ch[j] = c; ++j; break;
			case '4': c = str[i]; ch[j] = c; ++j; break;
			case '5': c = str[i]; ch[j] = c; ++j; break;
			case '6': c = str[i]; ch[j] = c; ++j; break;
			case '7': c = str[i]; ch[j] = c; ++j; break;
			case '8': c = str[i]; ch[j] = c; ++j; break;
			case '9': c = str[i]; ch[j] = c; ++j; break;
			case '+': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case '-': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case '*': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case '/': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case '(': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case ')': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case '^': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case '!': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case 's': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; ch[j + 1] = str[i + 1]; ch[j + 2] = str[i + 2]; i += 2; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case 'c': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; ch[j + 1] = str[i + 1]; ch[j + 2] = str[i + 2]; i += 2; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case 'l': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10); ch[j] = str[i]; ch[j + 1] = str[i + 1]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
			case 't': ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10);
			ch[j] = str[i]; ch[j + 1] = str[i + 1]; head2 = push_stack(head2, ch); memset(ch, 0, 10); break;
		}
		i++;
	}
	ch[j] = '\0'; head1 = push_stack(head1, ch); j = 0; memset(ch, 0, 10);
} 	



/*-------------------------------------------------block of functions with arithmetic operations-------------------------------------------------*/
char* myPlus(char *str1, char *str2){
	double num1, num2;
	sscanf(str1, "%lf", &num1);
	sscanf(str2, "%lf", &num2);

	num1 += num2;

	char arr[sizeof(num1)];

	return memcpy(arr,&num1,sizeof(num1));
}

char* myMinus(char *str1, char *str2){
	double num1, num2;
	sscanf(str1, "%lf", &num1);
	sscanf(str2, "%lf", &num2);

	num1 -= num2;

	char arr[sizeof(num1)]

	return memcpy(arr,&num1,sizeof(num1));
}

char* myMult(char *str1, char *str2){
	double num1, num2;
	sscanf(str1, "%lf", &num1);
	sscanf(str2, "%lf", &num2);

	num1 *= num2;

	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&num1,sizeof(num1));
}

char* myDel(char *str1, char *str2){
	double num1, num2;
	sscanf(str1, "%lf", &num1);
	sscanf(str2, "%lf", &num2);

	num1 /= num2;

	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&num1,sizeof(num1));
}

char* mySin(char *str1){
	double num1;
	sscanf(str1, "%lf", &num1);
	num1 = sin(num1);
	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&num1,sizeof(num1));
}

char* myCos(char *str1){
	double num1;
	sscanf(str1, "%lf", &num1);
	num1 = cos(num1);
	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&num1,sizeof(num1));
}

char* myTg(char *str1){
	double num1;
	sscanf(str1, "&lf", &num1);
	num1 = mySin(str1) / myCos(str1);
	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&num1,sizeof(num1));
}

char* myCtg(char *str1){
	double num1;
	sscanf(str1, "&lf", &num1);
	num1 = myCos(str1) / mySin(str1);
	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&num1,sizeof(num1));
}

char* myLn(char *str1){
	double num1;
	sscanf(str1, "%lf", &num1);
	num1 = log(num1);
	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&num1,sizeof(num1));
}

char* myPow(char *str1, char *str2){
	int num1, num2, res;
	sscanf(str1, "%lf", &num1);
	sscanf(str2, "%lf", &num2);

	num1 = pow(num1, num2);
	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&num1,sizeof(num1));
}

char* myFak(char *str1){
	int num1;
	int res=1;
	sscanf(str1, "%lf", &num1);

	for (int i=1; i<num1; i++){
		res*=i;
	}

	char arr = (char)malloc(sizeof(num1));

	return memcpy(arr,&res,sizeof(res));
}
/*-------------------------------------------------end of block of functions with arithmetic operations-------------------------------------------------*/



/*-------------------------------------------------return code of operation in stack with operation and find result-------------------------------------------------*/
char* decode(char *op){
	int i = 0;
	switch (op[i]){
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case 's': return 4;
		case 'c': if (op[i + 1] == 'o'){ return 5; }
				  else{ return 6; }
		case 't': return 7;
		case 'l': return 8;
		case '^': return 9;
		case '!': return 10;
	}
}

void exec(struct Node *head1, struct Node *head2){
	struct Node *cur = head1;
	struct Node *curOp = head2;

	char* operation = (char)malloc(sizeof(struct Node));
	char* result = (char)malloc(sizeof());
	operation = cur->data;
	switch(decode(&operation)) {
		case 0: result = myPlus(*cur->data, *cur->next->data); pop_stack(&cur); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 1: result = myMinus(*cur->data, *cur->next->data); pop_stack(&cur); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 2: result = myMult(*cur->data, *cur->next->data); pop_stack(&cur); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 3: result = myDel(*cur->data, *cur->next->data); pop_stack(&cur); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 4: result = mySin(*cur->data); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 5: result = myCos(*cur->data); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 6: result = myCtg(*cur->data); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 7: result = myTg(*cur->data); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 8: result = myLn(*cur->data); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 9: result = myPow(*cur->data, *cur->next->data); pop_stack(&cur); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break;
		case 10: result = myFak(*cur->data); pop_stack(&cur); push_stack(&cur, result); pop_stack(&curOp); break; 
		default: break; 
	} 
	free(cur);
	free(curOP);
}
/*-------------------------------------------------end of this block of functions-------------------------------------------------*/