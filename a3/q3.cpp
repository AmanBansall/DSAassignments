#include <iostream>
#include <stack>
using namespace std;
int main() {
    string expr;cin>>expr;
    stack<char> s;
    bool ok=true;
    for(char c:expr){
        if(c=='('||c=='{'||c=='[') s.push(c);
        else if(c==')'||c=='}'||c==']'){
            if(s.empty()) {ok=false;break;}
            char t=s.top();s.pop();
            if((c==')'&&t!='(')||(c=='}'&&t!='{')||(c==']'&&t!='[')){ok=false;break;}
        }
    }
    if(!s.empty()) ok=false;
    cout<<(ok?"Balanced":"Not Balanced");
}

