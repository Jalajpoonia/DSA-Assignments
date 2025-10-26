#include<iostream>
using namespace std;

// Ques: 1
    // class Queue{
    //     int arr[50],front,rear;
    //     public:
    //         Queue(){
    //             front=-1;
    //             rear=-1;
    //         }

    //         bool isEmpty(){
    //             if(front==-1||front>rear){
    //                 return true;
    //             }
    //             else{
    //                 return false;
    //             }
    //         }

    //         bool isFull(){
    //             if(rear==49){
    //                 return true;
    //             }
    //             else{
    //                 return false;
    //             }
    //         }

    //         void enqueue(int num){
    //             if(isFull()){
    //                 cout<<"Queue is full"<<endl;
    //             }
    //             else{
    //                 if(front==-1){
    //                     front++;
    //                 }
    //                 rear++;
    //                 arr[rear]=num;
    //             }
    //         }

    //         int dequeue(){
    //             if(isEmpty()){
    //                 cout<<"Queue is empty"<<endl;
    //             }
    //             else{
    //                 int value=arr[front];
    //                 front++;
    //                 return value;
    //             }
    //         }

    //         void display(){
    //             int idx=front;
    //             while(idx<=rear){
    //                 cout<<arr[idx]<<" ";
    //                 idx++;
    //             }
    //             cout<<endl;
    //         }

    //         void peek(){
    //             cout<<"Element in front is:"<<arr[front]<<endl;
    //         }
    // };

    // int main(){
    //     int queue[5]={1,2,3,4,5};
    //     Queue *ptr=new Queue;
    //     for(int i=0;i<5;i++){
    //         ptr->enqueue(queue[i]);
    //     }
    //     ptr->dequeue();
    //     ptr->display();
    //     ptr->peek();
    //     delete ptr;
    //     return 0;
    // }


//Ques: 2
// #include<iostream>
// using namespace std;

// class Cqueue{
//     int arr[4],front,rear,counter;
//     public:
//         Cqueue(){
//             front=-1;
//             rear=-1;
//             counter=0;
//         }

//         bool isFull(){
//             if(counter==4){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isEmpty(){
//             if(counter==0){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         void enqueue(int num){
//             if(isFull()){
//                 cout<<"Queue is full"<<endl;
//             }
//             else{
//                 if(front==-1){
//                     front++;
//                 }
//                 rear=(rear+1)%4;
//                 arr[rear]=num;
//                 counter++;
//             }
//         }

//         int dequeue(){
//             if(isEmpty()){
//                 cout<<"Queue is empty"<<endl;
//             }
//             else{
//                 int value=arr[front];
//                 front=(front+1)%4;
//                 counter--;
//                 return value;
//             }
//         }

//         void display(){
//             int idx=front;
//             for(int i=0;i<counter;i++){
//                 cout<<arr[idx]<<" ";
//                 idx=(idx+1)%4;
//             }
//             cout<<endl;
//         }

//         void peek(){
//             cout<<arr[front]<<endl;
//         }
// };

// int main(){
//     int queue[4]={1,2,3,4};
//         Cqueue *ptr=new Cqueue;
//         //for(int i=0;i<4;i++){
//             //ptr->enqueue(queue[i]);
//         //}
//         ptr->enqueue(1);
//         ptr->enqueue(2);
//         ptr->enqueue(3);
//         ptr->enqueue(4);
//         ptr->peek();
//         ptr->display();
//         ptr->dequeue();
//         ptr->peek();
//         ptr->display();
//         ptr->enqueue(5);
//         ptr->peek();
//         ptr->display();

        
//         delete ptr;
//     return 0;
// }


//Ques: 3
// #include<iostream>
// using namespace std;

// class Queue{
//     int front, rear, capacity, top, counter, arr1[50], arr2[50];
    
//     public:
//         Queue(int size){
//             front=-1;
//             rear=-1;
//             top=-1;
//             counter=0;
//             capacity=size;
//         }

//         ~Queue(){
//         }

//         bool isFull_stack(){
//             if(top==49){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isEmpty_stack(){
//             if(top==-1){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isFull_queue(){
//             if(counter==49){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isEmpty_queue(){
//             if(counter==0){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         void push(int num){
//             if(isFull_stack()){
//                 cout<<"Cannot add more element"<<endl;
//             }
//             else{
//                 top++;
//                 arr2[top]=num;
//             }
            
//         }

//         int pop(){
//             if(isEmpty_stack()){
//                 cout<<"Stack is empty"<<endl;
//                 return 0;
//             }
//             else{
//                 int value=arr2[top];
//                 top--;
//                 return value;
//             }
            
//         }

//         void enqueue(int num){
//             if(front==-1){
//                 front++;
//             }
//             if(isFull_queue()){
//                 cout<<"Cannot add more element"<<endl;
//             }
//             else{
//                  rear=(rear+1)%capacity;
//                  arr1[rear]=num;
//                  counter++;
//             }
           
//         }

//         int dequeue(){
//             if(isEmpty_queue()){
//                 cout<<"Queue is empty"<<endl;
//                 return 0;
//             }
//             else{
//                 int value=arr1[front];
//                 front=(front+1)%capacity;
//                 counter--;
//                 return value;
//             }
            
//         }

//          void display(){
//             int idx=front;
//             for(int i=0;i<counter;i++){
//                 cout<<arr1[idx]<<" ";
//                 idx=(idx+1)%capacity;
//             }
//             cout<<endl;
//         }


// };

// int main(){
//     int size;
//     cout<<"Enter the size of queue and stack: ";
//     cin>>size;
//     int arr[size];
//     Queue *ptr=new Queue(size);
//     cout<<"Enter "<<size<<" integers: ";
//     for(int i=0;i<size;i++){
//         cin>>arr[i];
        
//     }

//     for(int i=0;i<size;i++){
//         ptr->enqueue(arr[i]);
//     }

//     ptr->display();

//     for(int i=0;i<(size/2);i++){
//         ptr->push(ptr->dequeue());
//     }

//     ptr->display();

//     for(int i=0;i<(size/2);i++){
//         ptr->enqueue(ptr->pop());
//     }

//     ptr->display();

//     for(int i=0;i<(size/2);i++){
//         ptr->push(ptr->dequeue());
//     }

//     ptr->display();

//     for(int i=0;i<(size/2);i++){
//         ptr->enqueue(ptr->pop());
//         ptr->push(ptr->dequeue());
//         ptr->enqueue(ptr->pop());
//     }

//     ptr->display();

//     for(int i=0;i<size;i++){
//         ptr->push(ptr->dequeue());
//     }

//     ptr->display();

//     for(int i=0;i<size;i++){
//         ptr->enqueue(ptr->pop());
//     }

//     ptr->display();

//     return 0;
// }


//Ques: 4
// #include<iostream>
// #include<string>
// using namespace std;

// class Queue{
//     int front, rear;
//     char arr[50];
//     public:
//         Queue(){
//             front=-1;
//             rear=-1;
//         }

//         bool isFull(){
//             if(rear==49){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isEmpty(){
//             if(front==-1||front>rear){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         void enqueue(char ch){
//             if(isFull()){
//                 cout<<"Queue is full"<<endl;
//                 return;
//             }
//             else{
//                 if(front==-1){
//                     front++;
//                 }
//                 rear++;
//                 arr[rear]=ch;
//             }
//         }

//         void dequeue(){
//             if(isEmpty()){
//                 cout<<"Queue is empty"<<endl;
//                 return;
//             }
//             front++;

//         }

//         char peek(){
//             if(isEmpty()){
//                 cout<<"Queue is empty"<<endl;
//                 return 0;
//             }
//             return arr[front];
//         }
// };

// int main(){
//     Queue *ptr=new Queue;
//     string word;
//     cout<<"Enter any word: ";
//     cin>>word;
//     for(int i=0;i<word.length();i++){
//         if(word[i]==ptr->peek()){
//             ptr->dequeue();
//         }
//         else{
//             ptr->enqueue(word[i]);
//         }
//     }
//     cout<<"First non-repeating character is: "<<ptr->peek()<<endl;
//     return 0;
// }


//Ques: 4
// #include<iostream>
// #include<string>
// using namespace std;

// class Queue{
//     int front,rear;
//     char arr[50];
//     public:
//         Queue(){
//             front=-1;
//             rear=-1;
//         }

//         bool isEmpty(){
//             if(front==-1||front>rear){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isFull(){
//             if(rear==49){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         void enqueue(char c){
//             if(front==-1){
//                 front++;
//             }
//             if(isFull()){
//                 cout<<"Queue is full"<<endl;
//                 return;
//             }
//             rear++;
//             arr[rear]=c;
//         }

//         char dequeue(){
//             if(isEmpty()){
//                 cout<<"Queue is empty"<<endl;
//                 return '-';
//             }
//             else{
//                 char val=arr[front];
//                 front++;
//                 return val;
//             }
            
//         }

//         char peek(){
//             return arr[front];
//         }
        
//         void display(){
//             int idx=front;
//             while(idx<=rear){
//                 cout<<arr[idx]<<" ";
//                 idx++;
//             }
            
            
//         }

//         void check(string word){
//             char ch;
//             int freq[256]={0};
//             for(int i=0;i<word.length();i++){
//                 ch=word[i];
//                 enqueue(ch);
//                 freq[ch]++;  
//                 while(!isEmpty()&&freq[peek()]>1){
//                     dequeue();
//                 } 
                
//                 if(!isEmpty()){
//                 cout<<peek()<<" ";
//                 }
//                 else{
//                     cout<<"-1 ";
//                 }
//             }

            

            
//         }
//     };
// int main(){
//     string word;
//     cout<<"Enter any word: ";
//     cin>>word;
//     Queue *ptr= new Queue();
//     ptr->check(word);
//     return 0;
// }



//Ques: 5

//a)
// #include<iostream>
// using namespace std;

// class Queue{
//     int front,rear,arr[50],counter;
//     public:
//         Queue(){
//             front=-1;
//             rear=-1;
//             counter=0;
//             arr;
//         }

//         bool isEmpty(){
//             if(counter==0){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isFull(){
//             if(counter==49){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         void enqueue(int num){
//             if(isFull()){
//                 cout<<"Queue id full"<<endl;
//             }
//             else{
//                 if(front==-1){
//                     front++;
//                 }
//                 rear=(rear+1)%50;
//                 arr[rear]=num;
//                 counter++;
//             }
//         }

        

//         void display(){
//             int idx=front;
//             for(int i=0;i<counter;i++){
//                 cout<<arr[idx]<<" ";
//                 idx=(idx+1)%50;
//             }
//             cout<<endl;
//         }

//         void stack(Queue *obj1,Queue *obj2){
//             for(int i=0;i<(obj1->counter-1);i++){
//                 obj2->enqueue(obj1->dequeue());
//             }

//             for(int i=0;i<(obj2->counter-1);i++){
//                 obj1->enqueue(obj2->dequeue());
//             }
//         }

//         int dequeue(){
//             int value=arr[front];
//             front=(front+1)%50;
//             counter--;
//             return value;
//         }

//         int pop(Queue obj){
//             obj.dequeue();
//         }

// };

// int main(){
//     Queue q1,q2;
//     int size;
//     cout<<"Enter size of queue: ";
//     cin>>size;
//     int arr[size];
//     cout<<"Enter the elements: ";
//     for(int i=0;i<size;i++){
//         cin>>arr[i];
//     }
//     for(int i=0;i<size;i++){
//         q1.enqueue(arr[i]);
//         q1.stack(&q1,&q2);
//     }

    
//     cout<<"Topmost element of stack is: "<<q1.pop(q1)<<endl;
    
//     return 0;
// }


//b)
// #include<iostream>
// using namespace std;

// class Queue{
//     int front,rear,arr[50],counter;
//     public:
//         Queue(){
//             front=-1;
//             rear=-1;
//             counter=0;
//             arr;
//         }

//         bool isEmpty(){
//             if(counter==0){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isFull(){
//             if(counter==49){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         void enqueue(int num){
//             if(isFull()){
//                 cout<<"Queue id full"<<endl;
//             }
//             else{
//                 if(front==-1){
//                     front++;
//                 }
//                 rear=(rear+1)%50;
//                 arr[rear]=num;
//                 counter++;
//             }
//         }

        

//         void display(){
//             int idx=front;
//             for(int i=0;i<counter;i++){
//                 cout<<arr[idx]<<" ";
//                 idx=(idx+1)%50;
//             }
//             cout<<endl;
//         }

//         void stack(Queue *obj1){
//             for(int i=0;i<(obj1->counter-1);i++){
//                 obj1->enqueue(obj1->dequeue());
//             }
//         }

//         int dequeue(){
//             int value=arr[front];
//             front=(front+1)%50;
//             counter--;
//             return value;
//         }

//         int pop(Queue obj){
//             obj.dequeue();
//         }

// };

// int main(){
//     Queue q1;
//     int size;
//     cout<<"Enter size of queue: ";
//     cin>>size;
//     int arr[size];
//     cout<<"Enter the elements: ";
//     for(int i=0;i<size;i++){
//         cin>>arr[i];
//     }
//     for(int i=0;i<size;i++){
//         q1.enqueue(arr[i]);
//         q1.stack(&q1);
//     }

    
//     cout<<"Topmost element of stack is: "<<q1.pop(q1)<<endl;
    
//     return 0;
// }


//Additional Questions

//Ques: 1
// #include<iostream>
// using namespace std;

// class Queue{
//     int front,rear, arr[100],counter;
//     public:
//         Queue(){
//             front=-1;
//             rear=-1;
//             arr;
//             counter=0;
//         }

//         bool isEmpty(){
//             if(counter==0){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         bool isFull(){
//             if(counter==99){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }

//         void enqueue(int num){
//             if(isFull()){
//                 cout<<"Queue is full"<<endl;
//                 return;
//             }
//             if(front==-1){
//                 front++;
//             }
//             rear=(rear+1)%100;
//             arr[rear]=num;
//             counter++;
//         }

//         int dequeue(){
//             if(isEmpty()){
//                 cout<<"Queue is empty"<<endl;
//                 return 0;
//             }
//             int value=arr[front];
//             front=(front+1)%100;
//             counter--;
//             return value;
//         }

//         void reverse(Queue *obj){
//             for(int i=1;i<counter;i++){
//                 obj->enqueue(obj->dequeue());
//             }
//         }

// };

// int main(){
//     int num;
//     Queue q1;
//     cout<<"Enter any number: ";
//     cin>>num;
//     cout<<"Binary numbers upto "<<num<<" are:"<<endl;
//     for(int i=1;i<=num;i++){
//         int temp=i;
//         while(temp>0){
//             q1.enqueue(temp%2);
//             q1.reverse(&q1);
//             temp=temp/2;
//         }

//         while(!q1.isEmpty()){
//             int val=q1.dequeue();
//             cout<<val;
//         }
//         cout<<endl;
//     }
//     return 0;
// }
//************************************************************************************************************************ */
//Ques: 2
// #include<iostream>
// using namespace std;

// class Queue{
//     int front,rear,arr[50],counter,capacity;
//     public:
//         Queue(int size){
//             front=-1;
//             rear=-1;
//             arr;
//             counter=0;
//             capacity=size;
//         }

//         bool isFull(){
//             return (counter==49);
//         }

//         bool isEmpty(){
//             return (counter==0);
//         }

//         void enqueue(int num){
//             if(isFull()){
//                 cout<<"Queue is full"<<endl;
//                 return;
//             }
//             if(front==-1){
//                 front++;
//             }
//             rear=(rear+1)%50;
//             arr[rear]=num;
//             counter++;
//         }

//         int dequeue(){
//             if(isEmpty()){
//                 cout<<"Queue is empty"<<endl;
//                 return 0;
//             }
//             int value=arr[front];
//             front=(front+1)%50;
//             counter--;
//             return value;
//         }

//         void ascending(int min,int i){
//             int num=0;
//             int j=0;
//             int curr_value=0;
//             while(j<(capacity-i)){
//                 num=front;
//                 curr_value=dequeue();
//                 if(curr_value<min){
//                     min=curr_value;
//                     enqueue(curr_value);
//                 }
                
//                 j++;
//             }

//             while

//         }

// };

// int main(){
//     int size;
//     cout<<"Enter size of queue: ";
//     cin>>size;
//     Queue *q1=new Queue(size);
//     int arr[size];
//     cout<<"Enter numbers: ";
//     for(int i=0;i<size;i++){
//         cin>>arr[i];
//     }

//     for(int i=0;i<size;i++){
//         q1->enqueue(arr[i]);
//     }

//     for(int i=0;i<size;i++){
        
//         int min=INT16_MAX;
//         q1->ascending(min,i);
//     }

//     for(int i=0;i<size;i++){
//         int num=q1->dequeue();
//         cout<<num<<" ";
//     }
//     return 0;
// }\
//***************************************************************************************************************************************** */


//Ques: 3
// #include<iostream>
// using namespace std;

// class Sort{
//     int front,top,rear,stack[50],queue[50],counter,capacity;
//     public:
//         Sort(int size){
//             front=-1;
//             rear=-1;
//             top=-1;
//             counter=0;
//             capacity=size;
//         }

//         bool isEmpty_queue(){
//             return (counter==0);
//         }

//         bool isFull_queue(){
//             return (counter==49);
//         }

//         bool isEmpty_stack(){
//             return (top==-1);
//         }

//         bool isFull_stack(){
//             return (top==49);
//         }

//         void enqueue(int num){
//             if(isFull_queue()){
//                 cout<<"Queue is full"<<endl;
//                 return;
//             }
//             if(front==-1){
//                 front++;
//             }
//             rear=(rear+1)%50;
//             queue[rear]=num;
//             counter++;
//         }

//         int dequeue(){
//             if(isEmpty_queue()){
//                 cout<<"Queue is empty"<<endl;
//                 return 0;
//             }
//             int value=queue[front];
//             front=(front+1)%50;
//             counter--;
//             return value;
            
//         }

//         void push(int num){
//             if(isFull_stack()){
//                 cout<<"Stack is full"<<endl;
//                 return;
//             }
//             top++;
//             stack[top]=num;
//         }

//         int pop(){
//             if(isEmpty_stack()){
//                 cout<<"Stack is empty"<<endl;
//                 return 0;
//             }
//             int value=stack[top];
//             top--;
//             return value;
//         }

//         void is_sorted(){
//             int static num=1;
                
//             for(int j=0;j<capacity;j++){
//                 int value=dequeue();
//                 if(num==value){
//                     enqueue(value);
//                     num++;
//                 }
//                 else{
//                     push(value);
//                 }
//             }

            
//            while((!isEmpty_stack())&&(pop()==num)){
//             num++;
//            }
//            if(num==(capacity+1)){
//             cout<<"Queue can be sorted"<<endl;
//            }
//            else{
//             cout<<"Queue cannot be sorted"<<endl;
//            }
//         }
//     };

// int main(){
//     int size;
//     cout<<"Enter the size of queue: ";
//     cin>>size;
//     int arr[size];
//     Sort obj(size);
//     cout<<"Enter elements of Queue: ";
//     for(int i=0;i<size;i++){
//         cin>>arr[i];
//     }

//     for(int i=0;i<size;i++){
//         obj.enqueue(arr[i]);
//     }

//     obj.is_sorted();
    
//     return 0;
// }



