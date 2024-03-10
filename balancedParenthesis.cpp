#include <bits/stdc++.h> 
using namespace std; 

int main(){ 
    string gg = "({a+[b*[c-d]]+{e*(f/g)}-k})";

    stack<char> s;
    int flag=0;

    for(auto it: gg){

        if(it=='(' || it=='{' || it=='['){
            s.push(it);

            stack<char> ss;
            ss = s;
            while(!ss.empty()){
                cout << ss.top();
                ss.pop();
            }
            cout << endl;
        }
        else if(it==')' || it=='}' || it==']'){

            if(s.empty()){
                flag=1;
                cout << "empty" << endl;
                break;
            }
                
            char top = s.top();
            s.pop();

            if((it==')' && top=='(') || (it=='}' && top=='{') || (it==']' && top=='[')){
                continue;
            }
            else{
                flag = 1;
                break;
            }
        }
    }

    if(!s.empty())
        flag=1;

    if(flag == 1)
        cout << "not balanced" << endl;
    else
        cout << "balanced" << endl;
}
