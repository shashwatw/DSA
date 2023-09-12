//https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    int target = 0;
    int n = q.size();
    
    while(target < k)
    {
        target++;
        int x = q.front();
        q.pop();
        st.push(x);
    }
    
    while(target > 0)
    {
        target--;
        int x = st.top();
        st.pop();
        q.push(x);
    }
    
    target = 0;
    
    while(target < n - k)
    {
        target++;
        int x = q.front();
        q.pop();
        q.push(x);
    }
    
    return q;
}