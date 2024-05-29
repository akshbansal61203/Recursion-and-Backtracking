//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void addSolution(vector<vector<int>>&ans,vector<vector<int>>&board,int n){
        vector<int>temp;
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(board[i][j]==1){
                    temp.push_back(i+1); // corrected to store row index + 1
                }
            }
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col,vector<vector<int>>&board,int n){
        int x=row, y=col;
        // Check for rows
        for(int i=0;i<col;i++){
            if(board[x][i]==1) return false;
        }
        // Check lower diagonal
        x=row, y=col;
        while(x<n && y>=0){
            if(board[x][y]==1) return false;
            x++;
            y--;
        }
        // Check upper diagonal
        x=row, y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1) return false;
            x--;
            y--;
        }
        return true;
    }

    void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n){
        if(col==n){
            addSolution(ans,board,n);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col]=1;
                solve(col+1,ans,board,n);
                board[i][col]=0;
            }
        }
    }

public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<vector<int>>board(n,vector<int>(n,0));
        solve(0,ans,board,n);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
