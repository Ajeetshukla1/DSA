class Solution {
  public:
    void fn(stack<int> &st, int x){
        if(st.empty()){
            //if stack is empty x will be at the bottom
            st.push(x);
            return;
        }
        int top=st.top();
        st.pop();
        
        //recursively reach the bottom
        fn(st,x);
        
        // put the removed element
        st.push(top);
        
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.size()<=1) return;
        int top=st.top();
        //remove top
        st.pop();
        
        //reverse remaining stack
        reverseStack(st);
        
        // insert top at bottom
        fn(st,top);
        
        
    }
};