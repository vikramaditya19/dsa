#include <iostream>
using namespace std;
int main(){
    string s; cin>>s;
    char st[100]; int top=-1;
    for(char c:s){
        if(c=='(') st[++top]=c;
        else if(c==')'){
            if(top==-1){ cout<<"Not Balanced"; return 0; }
            top--;
        }
    }
    if(top==-1) cout<<"Balanced";
    else cout<<"Not Balanced";
}
