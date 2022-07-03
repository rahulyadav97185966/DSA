#include<bits/stdc++.h>
using namespace std;

bool checkOperator(stack<char> &st){
    bool isOperator = false;
    while(st.top() != '('){
        if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){   
            isOperator = true;
            st.pop();
        }
    }
    st.pop();
    return isOperator;
}

int main(){
    string s = "(a+c*b)+(c))";
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '*' || ch == '-' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')'){
            if(!checkOperator(st)){
                cout<<"Redundant";
                return 0;
            }
        }
    }
    cout<<"No redundant";
    
    return 0;
}