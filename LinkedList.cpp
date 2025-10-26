// //QUES: 1
// #include<iostream>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node *next;
//         Node(int value){
//             data=value;
//             next=NULL;
//         }
// };

// Node *insertBeginning(int value,Node *head){
//     Node *ptr=new Node(value);
//     if(head==NULL){
//         ptr->next=NULL;
//         head=ptr;
//     }
//     else{
//         ptr->next=head;
//         head=ptr;
//     }
//     return head;
//  }

//  Node *insertEnd(int value,Node *head){
//     Node *ptr=new Node(value);
//     if(head==NULL){
        
//         head=ptr;
//         ptr->next=NULL;
//         return head;
//     }
//     else{
//         Node *temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         ptr->next=NULL;
//         temp->next=ptr;
//         return head;
//     }
//  }

//  Node *insertBet(int value,Node *idx,Node *head){
//     Node *ptr=new Node(value);
//     if(head==NULL){
//         cout<<"No linked list existed, created new"<<endl;
//         head=ptr;
//         ptr->next=NULL;
//     }
//     else{
//         Node*temp=head;
//         while(temp->data!=idx->data){
//             temp=temp->next;
//         }
//         ptr->next=temp->next;
//         temp->next=ptr;
//     }
//     return head;
//  }

// Node *deleteBeginning(Node *head){
//     Node *ptr=head;
//     head=head->next;
//     delete ptr;
//     return head;
// }

// Node *deleteEnd(Node *head){
//     if(head==NULL){
//         return NULL;
//     }

//     if(head->next==NULL){
//         delete head;
//         return NULL;
//     }

//     Node *prev=NULL;
//     Node *curr=head;

//     while(curr->next){
//         prev=curr;
//         curr=curr->next;
//     }
//     delete curr;
//     prev->next=NULL;

//     return head;
// }

// Node *deleteNodeIdx(Node *head,int idx){
//     if(head==NULL){
//         return NULL;
//     }

//     if(idx==0){
//         Node *temp=head;
//         head=head->next;
//         delete temp;
//         return head;
//     }

//     Node *prev=NULL;
//     Node *curr=head;
//     while(idx>0){
//         prev=curr;
//         curr=curr->next;
//         idx--;
//     }
//     prev->next=curr->next;
//     delete curr;
//     return head;
// }

// void search(Node *head,int key){
//     Node *ptr=head;
//     int idx=0;
//     while(ptr){
//         if(ptr->data==key){
//             cout<<"Key present at "<<idx<<" from head"<<endl;
//             return;
//         }
//         else{
//             ptr=ptr->next;
//             idx++;
//         }
//     }

//     cout<<"Element does not exist in Linked list"<<endl;
// }

// void display(Node *head){
//     Node *ptr=head;
//     while(ptr){
//         cout<<ptr->data<<"->";
//         ptr=ptr->next;
//     }
//     cout<<"NULL"<<endl;
// }

// int main(){
//     int arr[4]={1,2,3,4};
//     Node *head=NULL;
//     Node*temp;
//     for(int i=0;i<4;i++){
//         head=insertEnd(arr[i],head);
//     }
//     head=insertBeginning(0,head);
//     head=insertEnd(1,head);
//     head=insertBet(2,head,head);
//     head=deleteBeginning(head);
//     head=deleteEnd(head);
//     search(head,3);
//     display(head);
//     head=deleteNodeIdx(head,3);
//     temp=head;
//     while(temp){
//         cout<<temp->data<<"->";
//         temp=temp->next;
//     }
//     cout<<"NULL";
//     cout<<temp->data;
//     return 0;
// }



//QUES: 2
// #include<iostream>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node *next;

//         Node(int value){
//             data=value;
//             next=NULL;
//         }

       
// };

//  Node *del_key(Node *head, int key){
//             Node *curr=head;
//             Node *prev=NULL;
//             int count=0;
            
//             while(curr){
                
//                 if(curr==head && curr->data==key){
//                     Node *temp=head;
//                     head=head->next;
//                     curr=head;
//                     count++;
                    
//                     delete temp;
//                 }
                
//                 else if(curr->data==key){
//                     Node *temp=curr;
//                     prev->next=curr->next;
//                     curr=prev->next;
//                     delete temp;
//                     count++;
//                 }

//                 else{
//                     prev=curr;
//                     curr=curr->next;
//                 }
//             }
//             cout<<"Number of nodes having the key are: "<<count<<endl;
//             return head;
//         }

//         Node *insert(Node *head,int value){
//             Node *ptr=new Node(value);
//             if(head==NULL){
//                 head=ptr;
//                 ptr->next=NULL;
//                 return head;
//             }
//             else{
//                 Node *temp=head;
//                 while(temp->next){
//                     temp=temp->next;
//                 }
//                 temp->next=ptr;
//                 ptr->next=NULL;
//                 return head;
//             }
//         }

//         void display(Node *head){
//             Node *temp=head;
//             while(temp){
//                 cout<<temp->data<<"->";
//                 temp=temp->next;
//             }
            
//             cout<<"NULL"<<endl;
//         }

// int main(){
//     Node *head=NULL;
//     // int size;
//     // cout<<"Enter the size of Linked list: ";
//     // cin>>size;
//     int arr[]={1,2,1,2,1,3,1};
//     // cout<<"Enter the node elements: ";

//     // for(int i=0;i<size;i++){
//     //     cin>>arr[i];
//     // }



//     for(int i=0;i<7;i++){
//         head=insert(head,arr[i]);
//     }


//     head=del_key(head,1);
//     cout<<"Linked list is: ";
//     display(head);
//     return 0;
// }


//QUES: 3
// #include<iostream>
// using namespace std;

// class Node{
//     public:
//         int data;
//         Node *next;

//         Node(int value){
//             data=value;
//             next=NULL;
//         }
// };

// Node *insert(Node *head,int value){
//     Node *ptr=new Node(value);
//     if(head==NULL){
//         head=ptr;
//         ptr->next=NULL;
//         return head;
//     }
//     else{
//         Node *temp=head;
//         while(temp->next){
//             temp=temp->next;
//         }
//         temp->next=ptr;
//         ptr->next=NULL;
//         return head;
//     }
// }

// Node *mid(Node *head){
//     int size=0;
//     Node *temp=head;
//     while(temp){
//         temp=temp->next;
//         size++;
//     }
//     Node *slow=head;
//     Node *fast=head;

//     if(size%2==0){
//         while(fast){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
//     else{
//         while(fast->next){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
// }

// int main(){
//     int arr[]={1,2,3,4,5,6};
//     Node *head=NULL;
//     for(int i=0;i<6;i++){
//         head=insert(head,arr[i]);
//     }
//     head=mid(head);
//     cout<<"Mid of linked list is "<<head->data<<endl;
//     return 0;
// }


//Ques: 4
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int value){
            data=value;
            next=NULL;
        }

};

Node *insert(Node *head,int value){
    Node *ptr=new Node(value);
    if(head==NULL){
        head=ptr;
        ptr->next=NULL;
        return head;
    }
    else{
        Node *temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=NULL;
        return head;
    }
}

Node *reverse(Node *head){
    Node *curr=head;
    Node *prev=NULL;
    Node *ahead=NULL;
    while(curr){
        ahead=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ahead;
    }
    return prev;
}

void display(Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node *head=NULL;
    int arr[]={1,2,3,4};

    for(int i=0;i<4;i++){
        head=insert(head,arr[i]);
    }
    display(head);

    cout<<"After reversing"<<endl;

    head=reverse(head);
    display(head);
    return 0;
}