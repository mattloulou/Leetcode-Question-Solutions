#include <iostream>
using namespace std;

int main() {
    int N;
    std::cin >> N;


    int smallest_number = INT_MAX;
    int current;
    for (int i = 1; i < N; ++i) {
        std::cin >> current;
        smallest_number = min(smallest_number, current);
    }

    cout << smallest_number-1;
}
