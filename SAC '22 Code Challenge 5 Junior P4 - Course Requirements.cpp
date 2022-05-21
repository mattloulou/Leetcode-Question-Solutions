#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
int main() {
    int N, num_prereqs, prereq;
    cin >> N;

    //each node should know what its prereqs are, and also what it is a prereq for.
    vector<unordered_set<int>> prereqs(N); //prereqs for this course
    vector<unordered_set<int>> required_for(N); //which courses need this one as a prereq
    queue<int> completed_courses;

    //take in the data
    for (int course_number = 1; course_number <= N; ++course_number) {
        cin >> num_prereqs;

        //when a course has no prereqs
        if (num_prereqs == 0) {
            cout << course_number << " ";
            completed_courses.push(course_number);

        //when a course has prereqs
        } else {
            for (int course = 0; course < num_prereqs; ++course) {
                cin >> prereq;
                prereqs.at(course_number-1).insert(prereq);
                required_for.at(prereq-1).insert(course_number);
            }
            
        }
    }

    //now we must keep finding courses without any prereqs and output them too.
    while (!completed_courses.empty()) {
        int current_course = completed_courses.front();
        completed_courses.pop();

        //go through each course it is a prereq for and see if any can be completed
        for (const int& course : required_for.at(current_course-1)) {

            //remove this course as a prereq for all courses that require it
            prereqs.at(course-1).erase(current_course);
            if (prereqs.at(course-1).size() == 0) {
                cout << course << " ";
                completed_courses.push(course);
            }
        }
    }
    
    
}