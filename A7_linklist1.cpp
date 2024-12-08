#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this ->data=data;
        this -> next=NULL;
    }
    ~Node(){
      int value = this -> data;
      if(this ->next !=NULL ){
          delete next;
          this -> next=NULL;
      }
      cout<<"Memory is free for node with data";
      cout<<endl;
    }
};

void insertAttail(Node* &tail,int d){
      Node* temp=new Node(d);
      tail ->next=temp;
      tail=temp;
}
void insertAtHead(Node* &head,int d){
      Node* temp=new Node(d);
      temp-> next =head;
      head=temp;
}
int getLength(Node* &head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
    cout<<temp ->data<<" ";
    temp=temp -> next;
    }
}
void insertAtPositon(Node* &tail,Node* &head,int positon,int d){
      Node* temp= new Node(d);
      temp=head;
      int cnt=1;
      if(positon==1){
        insertAtHead(head,d);
        return ;
      }
      while(cnt<positon-1){
        temp=temp->next;
        cnt++;
      }
      if(temp->next==NULL){
        insertAttail(tail,d);
        return ;
      }
      Node* nodeInsertTo=new Node(d);
      nodeInsertTo->next=temp->next;
      temp->next=nodeInsertTo;

}
void deletNode(int position,Node* &head){
   if(position==1){
     Node* temp=head;
    head=head->next;
     temp->next =NULL;
    delete temp;
   }
   else{
    Node* curr=head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt<position){
      prev=curr;
      curr=curr->next;
      cnt++;
    }
    prev->next =curr->next;
    curr->next =NULL;
    delete curr;

   }
 }
int main(){
    Node* node1=new Node(10);
       
    Node* head=node1;
    Node* tail=node1;
    insertAtHead(head,45);
    insertAtHead(head,12);
    insertAttail(tail,87);
    insertAttail(tail,34);
    insertAtPositon(tail,head,2,23);
    print(head);
    cout<<endl;
    cout<<"Length of link list is:"<<getLength(head)<<endl;
    deletNode (4,head);
    print(head);
    cout<<endl;
    cout<<"Length of link list is:"<<getLength(head);
    cout<<endl;
    
}