#include<iostream>
#include<vector>
using namespace std;

int findRoute(bool* map, int num) {
    int idx = num;
    int ans = num;
    while (idx != 0) {
        if (map[idx]) {
            ans = idx;
        }
        idx /= 2;
    }
    if (ans == num) map[num] = true;
    return ans;
}

int seatArrange(int N, int Q, vector<int>& queue) {
    bool* map = new bool[N + 1];
    int* ans = new int[Q]; 
    for (int i = 0; i < N + 1; i++) map[i] = false;
    for (int i = 0; i < Q; i++) {
        int num = queue[i];
        ans[i] = findRoute(map, num);
    }
    // print the answer
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    int N1 = 6;          
    int Q1 = 4;             
    vector<int> queue1 = {3, 5, 6, 2};
    seatArrange(N1, Q1, queue1);

    int N2 = 10;
    int Q2 = 5;
    vector<int> queue2 = {2, 8, 6, 7, 10};
    seatArrange(N2, Q2, queue2);

    int N3 = 13;
    int Q3 = 7;
    vector<int> queue3 = {8, 7, 6, 9, 10, 12, 13};
    seatArrange(N3, Q3, queue3);

    int N4 = 8;
    int Q4 = 4;
    vector<int> queue4 = {1, 2, 3, 4};
    seatArrange(N4, Q4, queue4);
}