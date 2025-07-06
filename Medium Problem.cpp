#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int median(vector<vector<int>> &mat) {
  
    vector<int> arr;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            arr.push_back(mat[i][j]);
        }
    }

    sort(arr.begin(), arr.end());

    int mid = arr.size() / 2;
    return arr[mid];
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << median(matrix) << endl;

    return 0;
}