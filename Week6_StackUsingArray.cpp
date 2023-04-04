#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
#define MAX 10

int stack_arr[MAX];
int top = -1;

int isEmpty()
{
    if(top == -1)
    return 1;
    else
    return 0;
}

int isFull()
{
    if(top == MAX -1)
    return 1;
    else
    return 0;
}
void Push(int data)
{
    if (isFull()){
        printf("Stack overflow\n");
        exit(1);
    }
    top += 1;
    stack_arr[top] = data;
}

int Pop()
{
    int value;
    if (isEmpty()) {
        printf("Stack underflow");
        exit(1);
    }
    value = stack_arr[top];
    top -= 1;
    return value;
}

int StackTop()
{
    if (isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    return  stack_arr[top];
}

void Display()
{
    if (isEmpty()){
        printf("Stack underflow\n");
        return;
    }
    for (int i = top; i > -1; i--){
        cout << stack_arr[i];
        cout << " ";
    }   
    printf("\n");
}

int main()
{
    auto start = high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds with stack array" << endl;
}


