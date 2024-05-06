/*
🔘PROBLEM STATEMET:-
Read the marks obtained by students of second year in an online
examination of particular subject. Find out maximum and minimum marks
obtained in that subject. Use heap data structure.Analyze the algorithm.
*/

/*
#️⃣Quick Revision Notes:-
🔸HEAP DATA STRUCTURE :- When dynamic allocation is done then we use this data structure.
TYPE :- 1. Min Heap :- Root < Child.
        2. Max Heap :- Root > Child.

1. Complete Binary Tree is requaired.
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> findMinMaxMarks(const vector<int>& marks) {
    // Max heap
    priority_queue<int> maxHeap(marks.begin(), marks.end());

    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap(marks.begin(), marks.end());

    // Maximum mark
    int maxMark = maxHeap.top();

    // Minimum mark
    int minMark = minHeap.top();

    return make_pair(maxMark, minMark);
}

int main() {
    // Read marks from the user
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<int> marks(numStudents);
    cout << "Enter the marks obtained by each student: ";
    for (int i = 0; i < numStudents; ++i) {
        cin >> marks[i];
    }

    // Find maximum and minimum marks
    pair<int, int> maxMinMarks = findMinMaxMarks(marks);

    // Display results
    cout << "Maximum mark obtained: " << maxMinMarks.first << endl;
    cout << "Minimum mark obtained: " << maxMinMarks.second << endl;

    return 0;
}
