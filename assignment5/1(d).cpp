#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int val){
        data=val;
    }
};
class List{
    Node*head;
    Node*tail;
    public:
    List(){
        head=tail=NULL;
    }
    void pop_front(){
      Node*temp=head;
    
      if(head==NULL){
        cout<<"empty";
        return;
       }else{
         head=head->next;
         temp->next=NULL;
         delete temp;
       }
    }
};
