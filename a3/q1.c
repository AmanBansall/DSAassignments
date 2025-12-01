#include <iostream>
using namespace std;
int main() {
    const int MAX=100;
    int arr[MAX],top=-1,choice,val;
    do {
        cout<<"\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cin>>choice;
        switch(choice){
            case 1: cin>>val;
                    if(top==MAX-1) cout<<"Overflow\n";
                    else arr[++top]=val;
                    break;
            case 2: if(top==-1) cout<<"Underflow\n";
                    else cout<<"Popped "<<arr[top--]<<endl;
                    break;
            case 3: if(top==-1) cout<<"Empty\n";
                    else cout<<arr[top]<<endl;
                    break;
            case 4: if(top==-1) cout<<"Empty\n";
                    else{for(int i=top;i>=0;i--) cout<<arr[i]<<" ";cout<<endl;}
                    break;
            case 5: cout<<"Exiting\n"; break;
            default: cout<<"Invalid\n";
        }
    }while(choice!=5);
}

