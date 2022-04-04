/*

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int a[MAX];
int front,rear;

void initializeQueue();
int isFull();
int isEmpty();
int size();
void insert(int x);
int delete();
int peek();
void display();

void main(){
  int choice,x;

  initializeQueue();

  while(1){
      printf("1.Insert an element in the queue \n");
      printf("2.Delete an item in the queue\n");
      printf("3.Show size of the queue \n");
      printf("4.Display items in the queue \n");
      printf("5.Top element in the queue \n");
      printf("6.Quit \n\n");

      printf("Enter your choice:: ");
      scanf("%d",&choice);
      printf("\n");

      if (choice==6)
        break;

        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted : \n");
            scanf("%d",&x);
            insert(x);
            break;
        case 2:
            x=delete();
            printf("Element deleted is : %d \n",x);
            break;
        case 3:
            printf("Size of the queue is %d \n",size());
            break;
        case 4:
            display();
            break;
        case 5:
            printf("The element at the front is: %d \n",peek());
            break;
        default:
            printf("Invalid option \n");
            break;
        }
        printf("\n");
  }  
    
}
void initializeQueue(){
    front=-1;
    rear=-1;
}
int isEmpty(){
    if(front==-1 || front==rear+1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(rear==MAX-1){
        return 1;
    }
    return 0;
}
int peek(){
    if(isEmpty()){
        printf("Queue underflow \n");
        exit(1);
    }
    return a[front];
}
int size(){
    if(isEmpty()){
        return 0;
    }
    return rear-front+1;
}
void insert(int x){
    if(isFull()){
        printf("Queue overflow \n");
        return;
    }
    if(front==-1)
        front=0;
    rear=rear+1;
    a[rear]=x;    

}
int delete(){
    int x;
    if(isEmpty()){
        printf("Queue underflow \n");
        exit(1);
    }
    x=a[front];
    front=front+1;
    return x;
}
void display(){
    int i;
    if(isEmpty()){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue is : \n\n");
    for(i=front;i<=rear;i++)
        printf("%d  ",a[i]);
    printf("\n");
}
