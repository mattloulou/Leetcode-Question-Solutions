using namespace std;
#include <iostream>
#include <string>

//for my usage, answer will only ever be 1 char
bool puzzleSolver(string input, const string& answer) {
    if (input == answer) return true;
    if (input.size() <= answer.size()) return false;
    if (input.size() < answer.at(0) - 'a' + 1) return false; //ONLY IF answer.size() == 1

    //loop through all pairs of adjacent letters and see if there are any combinations that solve it.
    for (int i = 0; i < int(input.size()) - 1; ++i) {
        if (input.at(i) == input.at(i+1) && input.at(i) != 'z') {
            string new_str = input.substr(0, i);
            new_str.push_back(input.at(i)+1);
            new_str += input.substr(i+2);
            if (puzzleSolver(new_str, answer)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int N;
    cin >> N;
    string puzzle, solution;
    for (int i = 0; i < N; ++i) {
        cin >> puzzle >> solution;

        //check for if the largest size char in puzzle is larger than in solution
        char largest_puzzle = 'a';
        char largest_solution = 'b';
        for (const char& c : puzzle) {
            largest_puzzle = min(c, largest_puzzle);
        }
        for (const char& c : solution) {
            largest_solution = min(c, largest_solution);
        }
        if (largest_puzzle > largest_solution) {
            cout << "NO\n";
            break;
        }

        //for each letter in the solution, we must see if the first however many characters can be made to create that letter.
        //each time we make the letter, we then discard the spent chars.
        int puzzle_starting_index = 0;
        for (int j = 0; j < solution.size(); ++j) { //one loop per char in solution
            for (int k = 1; k <= puzzle.size() - puzzle_starting_index; ++ k) { //k is the length of the puzzle substr to test
                if (puzzleSolver(puzzle.substr(puzzle_starting_index, k), solution.substr(j,1))) {
                    puzzle_starting_index += k;
                    break;
                }
            }
        }
        if (puzzle_starting_index == puzzle.size()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

