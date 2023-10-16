//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
    stack<int> s;
 
    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;
 
    // Traverse given array
    for (int i=0; i<N; i++)
    {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (arr[i] < root)
            return false;
 
        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top()<arr[i])
        {
            root = s.top();
            s.pop();
        }
 
        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(arr[i]);
    }
    return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends