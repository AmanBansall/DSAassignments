#include <iostream>
#include <stack>
using namespace std;
int prec(char c){if(c=='+'||c=='-') return 1; if(c=='*'||c=='/') return 2; if(c=='^') return 3; return 0;}
int main(){
    string infix;cin>>infix;stack<char> s;string post="";
    for(char c:infix){
        if(isalnum(c)) post+=c;
        else if(c=='(') s.push(c);
        else if(c==')'){while(!s.empty()&&s.top()!='('){post+=s.top();s.pop();}s.pop();}
        else{while(!s.empty()&&prec(s.top())>=prec(c)){post+=s.top();s.pop();}s.push(c);}
    }
    while(!s.empty()){post+=s.top();s.pop();}
    cout<<post;
}
