#include <iostream>
using namespace std;
#define MAX 5

int st[MAX],top=-1;

void push(int x){ if(top<MAX-1) st[++top]=x; }
void pop(){ if(top>=0) top--; }
void display(){ for(int i=top;i>=0;i--) cout<<st[i]<<" "; cout<<endl; }
void peek(){ if(top>=0) cout<<st[top]<<endl; }
void isEmpty(){ cout<<(top==-1?"Yes":"No")<<endl; }
void isFull(){ cout<<(top==MAX-1?"Yes":"No")<<endl; }

int main(){
    int ch,x;
    do{
        cin>>ch;
        if(ch==1){cin>>x; push(x);}
        else if(ch==2) pop();
        else if(ch==3) isEmpty();
        else if(ch==4) isFull();
        else if(ch==5) display();
        else if(ch==6) peek();
    }while(ch!=7);
}
