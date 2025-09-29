#include <iostream>
using namespace std;
int main(){
    string s; cin >> s;
    int n = s.size();
    char st[100];
    int top = -1;
    for(int i=0;i<n;i++) st[++top]=s[i];
    while(top!=-1) cout<<st[top--];
}
