#include<iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// define the node struct
struct Node {
    int data;
    Node* next;
};

// define the stack struct
struct Stack {
    Node* top;
};

// function to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

// function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

// function to push a new element onto the stack
void Push(Stack* stack, int data) {
    Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// function to pop an element off the stack
void Pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    delete(temp);
}

// function to get the top element of the stack
int StackTop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return stack->top->data;
}

// function to display the stack
void Display(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = stack->top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// main function
int main() {
    Stack* stack = new Stack;
    stack->top = NULL;

    auto start = high_resolution_clock::now();
    Push(stack,8);
    Push(stack,10);
    Push(stack,5);
    Push(stack,11);
    Push(stack,15);
    Push(stack,23);
    Push(stack,6);
    Push(stack,18);
    Push(stack,20);
    Push(stack,17);
    Display(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Pop(stack);
    Display(stack);
    Push(stack,4);
    Push(stack,30);
    Push(stack,3);
    Push(stack,1);
    Display(stack);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds with linked list approach" << endl;
  return 0;
}
