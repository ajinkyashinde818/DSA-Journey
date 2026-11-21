#include<stdio.h>
#define max 5

int stack[max];
int top=-1;

void push(int data){
    if(top==max-1){
        printf("The Stack is oveflow\n");
    }else{
        top++;
        stack[top]=data;
        printf("%d The Elements is Inserted:\n",data);
    }
}

void pop(){
    if(top==-1){
        printf("The Stach is Underflow\n");
    }else{
        printf("The removed Data is:%d\n",stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("The Stack is Empty\n");
    } else {
        printf("The Top Element is: %d\n", stack[top]);
    }
}


void display(){
    int i;

    for(i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
}


int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);


    pop();
    pop();
    pop();

    peek();
}