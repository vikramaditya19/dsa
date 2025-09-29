#include <iostream>
#include <stack>
using namespace std;
int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}
int main() {
    string infix, postfix="";
    cout << "Enter infix: ";
    cin >> infix;
    stack<char> s;

    for(char ch: infix){
        if(isalnum(ch)) postfix+=ch;
        else if(ch=='(') s.push(ch);
        else if(ch==')'){
            while(s.top()!='('){ postfix+=s.top(); s.pop(); }
            s.pop();
        }
        else{
            while(!s.empty() && precedence(s.top())>=precedence(ch)){
                postfix+=s.top(); s.pop();
            }
            s.push(ch);
        }
    }

    while(!s.empty()){ postfix+=s.top(); s.pop(); }

    cout << "Postfix: " << postfix << endl;
    return 0;
}
