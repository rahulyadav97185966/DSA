#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(char closeBracket, stack<int> &st){
    if(st.empty()){
        return false;
    }
    if(closeBracket == '}' && st.top() == '{'){
        st.pop();
        return true;
    }
    else if(closeBracket == ']' && st.top() == '['){
        st.pop();
        return true;
    }
    else if(closeBracket == ')' && st.top() == '('){
        st.pop();
        return true;
    }
}

int main(){

    string s = "[()]{}{[()()]()}";
    
    if(s.length()%2 == 1){
        cout<<"Invalid";
    }
    stack<int> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(!validParenthesis(ch, st)){
                cout<<"Invalid";
                return 0;
            }
        }
    }
    if(st.empty()){
        cout<<"Valid";
    }
    cout<<"Invalid";
    return 0;
}