/*************************************************************************
    > File Name: main.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180930 123151
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> _res;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        _res.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            _res[i].resize(matrix[i].size());
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            _res[0][j] = matrix[0][j];
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int i = 1; i < matrix.size(); ++i) {
                _res[i][j] = _res[i - 1][j] + matrix[i][j];
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                _res[i][j] += _res[i][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row2 < 0 || col2 < 0) {
            return -1;
        }
        int res = _res[row2][col2];
        if (col1 > 0) {
            res -= _res[row2][col1 - 1];
        }
        if (row1 > 0) {
            res -= _res[row1 - 1][col2];
        }
        if (row1 > 0 && col1 > 0) {
            res += _res[row1 - 1][col1 - 1];
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix{{-4,-5}};
    NumMatrix* obj = new NumMatrix(matrix);
    std::cout << obj->sumRegion(0,1,0,1);
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
