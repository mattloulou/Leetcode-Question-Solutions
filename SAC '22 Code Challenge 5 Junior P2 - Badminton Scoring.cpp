#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int M, O, wins = 0;
    for (int i = 0; i < N; ++i) {
        cin >> M >> O;
        wins += (M > O) ? 1: 0;
    }
    cout << wins;
}