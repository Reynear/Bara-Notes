#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack data structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Queue data structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Initialize stack
void initializeStack(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push an item onto the stack
void push(Stack *stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Pop an item from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Initialize queue
void initializeQueue(Queue *queue) {
    queue->front = queue->rear = -1;
}

// Check if queue is empty
int isQueueEmpty(Queue *queue) {
    return queue->front == -1;
}

// Enqueue an item
void enqueue(Queue *queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (isQueueEmpty(queue))
        queue->front = 0;
    queue->items[++queue->rear] = value;
}

// Dequeue an item
int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    int value = queue->items[queue->front++];
    if (queue->front > queue->rear)
        initializeQueue(queue);
    return value;
}

// Function to evaluate a postfix expression
int evaluatePostfix(char *expression) {
    Stack stack;
    initializeStack(&stack);

    int i, operand1, operand2;
    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
