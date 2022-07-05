// turns out this problem is meant to be done in bash, not c++ lol.

// #include <fstream>
// #include <iostream>
// #include <string>
// using namespace std;

// bool type1(const string& line) {
//     if (line.size() != 12) return false;
//     for (int i = 0; i < line.size(); ++i) {
//         if (i == 3 || i == 7) {
//             if (line[i] != '-') return false;
//         } else {
//             if (line[i] < '0' || line[i] > '9') return false;
//         }
//     }
//     return true;
// }

// bool type2(const string& line) {
//     if (line.size() != 12) return false;
//     for (int i = 0; i < line.size(); ++i) {
//         if (i == 3 || i == 7) {
//             if (line[i] != ' ') return false;
//         } else {
//             if (line[i] < '0' || line[i] > '9') return false;
//         }
//     }
//     return true;
// }

// bool type3(const string& line) {
//     if (line.size() != 14) return false;
//     for (int i = 0; i < line.size(); ++i) {
//         if (i == 0) {
//             if (line[i] != '(') return false;
//         } else if (i == 4) {
//             if (line[i] != ')') return false;
//         } else if (i == 5) {
//             if (line[i] != ' ') return false;
//         } else if (i == 9) {
//             if (line[i] != '-') return false;
//         } else {
//             if (line[i] < '0' || line[i] > '9') return false;
//         }
//     }
//     return true;
// }

// int main() {
//     ifstream input("file.txt");
//     string line;
//     while (getline(input, line)) {
//         if (type1(line) || type2(line) || type3(line)) {
//             cout << line << endl;
//         }
//     }
// }