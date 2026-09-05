class Solution {
  public:
    void insert(stack<int>&st,int x){
        if(st.empty() || st.top()<=x){
            // x is at correct position than simply push it
            st.push(x);
            return;
        }
        // if not then repeat the same 
        int top=st.top();
        st.pop();
        
        // again try to insert x at correct position
        insert(st,x);
        //after x is at correct position simply push the top
        st.push(top);
        
        
    }
    void sortStack(stack<int> &st) {
        // code here
        
       //base condition
       if(st.size()<=1) return;
       int top=st.top();
       st.pop();
       
       // sort the remaining stack
       sortStack(st);
       
       // start sorting for top ans second top
       insert(st,top);
       
       
    }
};
