#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
    int N, Q;
    string name;
    cin >> N >> Q;
    vector<unordered_set<string>> media_lists(N);

    int query_type, media_list_index;

    for (int i = 0; i < Q; ++i) {
        cin >> query_type >> media_list_index >> name;
        unordered_set<string>& list = media_lists.at(media_list_index-1);
        if (query_type == 1) {
            cout << list.count(name) << endl;
        } else if (query_type == 2) {
            list.insert(name);
        }
    }
    
}