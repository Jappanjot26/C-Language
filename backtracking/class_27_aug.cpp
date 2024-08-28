#include<bits/stdc++.h>
using namespace std;

bool isValid(int n, int m, int i, int j){
    if(i > n || j > m) return false;
    return true;
}

int solve(int mat[4][4], int n, int m, int i, int j){
    if(i == n && j == m){
        return mat[i][j];
    }

    bool ch1Valid = isValid(n, m, i + 1, j);
    bool ch2Valid = isValid(n, m, i, j + 1);

    if(ch1Valid && ch2Valid){
        int ch1 = solve(mat, n, m, i + 1, j);
        int ch2 = solve(mat, n, m, i, j + 1);
        return mat[i][j] + min(ch1, ch2);
    }

    if(ch1Valid){
        int ch1 = solve(mat, n, m, i + 1, j);
        return mat[i][j] + ch1;
    }
    int ch2 = solve(mat, n, m, i, j + 1);
    return mat[i][j] + ch2;


}

int main(){
    int mat[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,0,0}};
    cout<<solve(mat,3,3,0,0)<<endl;
    return 0;
}

// * * * - 00 01 02
// * * * - 10 11 12
// * * * - 20 21 22


//exit
//

















// Base Case - 
// if i == n-1 and j == m-1
// 
// if arr[i][j] == 1
// call for right(j+1) and down(i+1)
// 