#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30

const char *low[N]; //contains the lowercase letter in main
const char *up[N]; //contains the uppercase letter in main

struct Node { 
 char letter[N]; 
 struct Node *next; 
}; 

struct Node *Node_combined; //contains the combined list

void print_list(struct Node *Node_Head) {
  while (Node_Head != NULL) {
      printf("%c ", Node_Head -> letter[0]);
      Node_Head = Node_Head->next;
  }
}

struct Node * insert_front(struct Node *Node_Head, int l_select, const char *low_up[N]){
// const char *low_up[N]) › low[] or up[] 
// l_select › selected letter’s number
struct Node *current;
current=(struct Node*)malloc(sizeof(struct Node));
if (Node_Head == NULL)
{
  Node_Head = (struct Node*) malloc(sizeof(struct Node));  // create root
  strcpy(Node_Head->letter, low_up[l_select]);
}
else
{
  current = Node_Head; // start at the beginning...
  while (current->next != NULL)
  {
    current = current->next; // walk to the end of the list
  }
    current->next = (struct Node*)  malloc(sizeof(struct Node));
    current = current->next;
    strcpy(current->letter, low_up[l_select]);
}

	return (current);
}



int letter_check(struct Node *Node_Head,int l_select,const char *low_up[N]){
// const char *low_up[N]) › low[l_select] or up[l_select] 
// l_select › selected letter’s number
//You should use strcmp(char *str1,char *str2) function to compare inputs and it returns "0" if the inputs are equal
while (Node_Head != NULL) {
      if(strcmp(low_up[l_select], Node_Head->letter)==0)
        return 0;
      Node_Head = Node_Head->next;
  }
  return 1;
}

void combine(struct Node *Node_Head_l, struct Node *Node_Head_u){ 
// Node_Head_l is for lowercase list and Node_Head_u is for uppercase list
int i=0;
while (Node_Head_u != NULL) {
  while (Node_Head_l != NULL) {
    if((Node_Head_u->letter[0]) - 'A' == (Node_Head_l->letter[0] - 'a')) {
      Node_combined->letter[i] = Node_Head_u->letter[0];
      i++;
      Node_combined->letter[i] = Node_Head_l->letter[0];
      i++;
    } 
    Node_Head_l = Node_Head_l->next;
  }
    Node_Head_u = Node_Head_u->next;
}

for(int i=0;i< strlen(Node_combined->letter);i++) {
      printf("%c ", Node_combined -> letter[i]);
  }


}

int main(){
low[0]="a"; up[0]="A";
low[1]="b"; up[1]="B";
low[2]="c"; up[2]="C";
low[3]="x"; up[3]="D";
low[4]="y"; up[4]="E";
low[5]="z"; up[5]="F"; 
struct Node *Node_lowerCase = NULL;//list for lowercase
struct Node *Node_upperCase = NULL;//list for uppercase

Node_lowerCase = (struct Node*)malloc(sizeof(struct Node));
Node_upperCase = (struct Node*)malloc(sizeof(struct Node));
// Necessary lines
struct Node *Node_Head_l;
struct Node *Node_Head_u;
int select;
for(int i=0;i<6;i++) {
printf("\nSelect a Uppercase Letter: 1.%s 2.%s 3.%s 4.%s 5.%s 6.%s ",up[0],up[1],up[2],up[3],up[4],up[5]);
r:
printf("\nNumber of Letter: ");
scanf("%d",&select);
if(letter_check(Node_upperCase, select, up) == 0)
  goto r;
else
  Node_Head_u = insert_front(Node_upperCase, select, up);
printf("\nUpperCase Letter: ");
print_list(Node_upperCase);
}



for(int i=0;i<6;i++) {
printf("\n\nSelect a Lowercase Letter: 1.%s 2.%s 3.%s 4.%s 5.%s 6.%s ",low[0],low[1],low[2],low[3],low[4],low[5]);
l:
printf("\nNumber of Letter: ");
scanf("%d",&select);
if(letter_check(Node_lowerCase, select, low) == 0)
  goto l;
else
  Node_Head_l = insert_front(Node_lowerCase, select, low);
printf("\nLowercase Letter: ");
print_list(Node_lowerCase);
}

printf("\nUpperCase Letter: ");
print_list(Node_upperCase);

printf("\nCombined Letters: ");
combine(Node_Head_l, Node_Head_u);




return 0;
}
