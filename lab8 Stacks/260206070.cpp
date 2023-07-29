#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// A structure to represent a stack
struct Deck{
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Deck* createStack(unsigned capacity)
{
    struct Deck* stack = (struct Deck*)malloc(sizeof(struct Deck));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Deck* stack)
{
    return stack->top == stack->capacity - 1;
}
 
int isEmpty(struct Deck* stack)
{
    return stack->top == -1;
}
 
void push(struct Deck* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
 
int pop(struct Deck* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
int peek(struct Deck* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

void print(struct Deck *stack,int size)
{
    for (int i = size-1; i >= 0; i--)
        printf("%d ", stack->array[i]);
    printf("\n");    
}

void fillDeck(struct Deck *stack, int size) {
    for(int i=size;i>0;i--) {
      push(stack, i);
    }
}
void riffle(struct Deck *stack, int size) {
  struct Deck* temp1 = createStack(size/2);
  struct Deck* temp2 = createStack(size/2);
  printf("Riffle Shuffled Hands:");
  for(int j=0;j<size;j++) {
  for(int i=0;i<size/2;i++) {
    push(temp1, pop(stack));
  }
  for(int i=0;i<size/2;i++) {
    push(temp2, pop(stack));
  }
  for(int i=0;i<size;i++) {
    push(stack, pop(temp1));
    push(stack, pop(temp2));
  }
  printf("\nShuffle %d : ",j+1);
  print(stack, size);
  } 
}
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void fisheryates(struct Deck *stack,int size) {
  srand ( time(NULL) );
    int i, j, tmp;
    printf("\nRandomly picked positions: ");
    for (int i = size-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        printf("%d ",j);
        swap(&stack->array[i], &stack->array[j]);
    }
    printf("\nShuffled Hand (fisher-yates): ");
    print(stack, 10);

}

int main()
{   

    struct Deck* stack = createStack(10);
    fillDeck(stack, 10);
    printf("Orginal Hand: \n");
    print(stack, 10);
    riffle(stack,10);
    fisheryates(stack, 10);
 
 
    return 0;
}
