#include <iostream>
#include <stack>
using namespace std;
int main(){
    string postfix;
    cout << "Enter postfix (single-digit operands): ";
    cin >> postfix;

    stack<int> s;
    for(char ch: postfix){
        if(isdigit(ch)) s.push(ch-'0');
        else{
            int b=s.top(); s.pop();
            int a=s.top(); s.pop();
            if(ch=='+') s.push(a+b);
            else if(ch=='-') s.push(a-b);
            else if(ch=='*') s.push(a*b);
            else if(ch=='/') s.push(a/b);
        }
    }

    cout << "Result: " << s.top() << endl;
    return 0;
}
