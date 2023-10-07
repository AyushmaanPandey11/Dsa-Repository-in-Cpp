#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.')); 
        
        unordered_map<int, int> cols, diag1, diag2; // Custom hashmap for tracking queens
        
        solve(result, board, cols, diag1, diag2, 0, n);
        return result;
    }
    
    void solve(vector<vector<string>>& result, vector<string>& board, unordered_map<int, int>& cols, unordered_map<int, int>& diag1, unordered_map<int, int>& diag2, int row, int n) {
        if (row == n) {
            result.push_back(board); // Found a valid solution
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols[col] == 0 && diag1[row - col] == 0 && diag2[row + col] == 0) {
                board[row][col] = 'Q';
                cols[col] = 1;
                diag1[row - col] = 1;
                diag2[row + col] = 1;
                solve(result, board, cols, diag1, diag2, row + 1, n);
                board[row][col] = '.';
                cols[col] = 0;
                diag1[row - col] = 0;
                diag2[row + col] = 0;
            }
        }
    }
};

int main() {
    Solution solution;
    int n = 4;
    vector<vector<string>> solutions = solution.solveNQueens(n);

    for (const auto& solution : solutions) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
