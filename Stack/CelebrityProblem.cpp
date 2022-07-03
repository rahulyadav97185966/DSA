#include<bits/stdc++.h>
using namespace std;
bool Knows(vector<vector<int>> &mat, int A, int B){
    if(mat[A][B] == 1){
        return true;
    }
    return false;
}
int main(){
    vector<vector<int>> mat = {
        {0, 1},
        {1, 0}
    };

    stack<int> st;
    int n = mat.size();
    for(int i=0;i<n;i++){
        st.push(i);
    }

    while(st.size() > 1){
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();
        if(Knows(mat, A, B)){
            st.push(B);
        }
        else{
            st.push(A);
        }
    }
    if(st.size() == 0){
        cout<<"Celebrity Not Present"<<endl;
    }
    else{
        //check for rows
        for(int i=0;i<n;i++){
            if(mat[st.top()][i] == 1 && st.top() != i){
                cout<<"No Celebrity";
                return 0;
            }
        }
        //check For cols
        for(int i=0;i<n;i++){
            if(mat[i][st.top()] == 0 && st.top() != i){
                cout<<"No Celebrity";
                return 0;
            }
        }
        cout<<"celebrity is: "<<st.top()<<endl;
    }
    return 0;
}