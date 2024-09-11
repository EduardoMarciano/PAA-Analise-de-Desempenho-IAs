#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> galeShapley(const vector<vector<int>>& studentPrefs, const vector<vector<int>>& hospitalPrefs) {
    int n = studentPrefs.size();
    vector<int> studentMatches(n, -1);
    vector<int> hospitalMatches(n, -1);
    vector<int> studentNextProposal(n, 0);
    
    vector<unordered_map<int, int>> hospitalRanking(n);
    for (int h = 0; h < n; ++h) {
        for (int rank = 0; rank < n; ++rank) {
            hospitalRanking[h][hospitalPrefs[h][rank]] = rank;
        }
    }

    queue<int> freeStudents;
    for (int s = 0; s < n; ++s) {
        freeStudents.push(s);
    }

    while (!freeStudents.empty()) {
        int student = freeStudents.front();
        freeStudents.pop();

        int hospital = studentPrefs[student][studentNextProposal[student]];
        ++studentNextProposal[student];

        if (hospitalMatches[hospital] == -1) {
            studentMatches[student] = hospital;
            hospitalMatches[hospital] = student;
        } else {
            int currentStudent = hospitalMatches[hospital];
            if (hospitalRanking[hospital][student] < hospitalRanking[hospital][currentStudent]) {
                studentMatches[student] = hospital;
                studentMatches[currentStudent] = -1;
                freeStudents.push(currentStudent);
                hospitalMatches[hospital] = student;
            } else {
                freeStudents.push(student);
            }
        }
    }

    return studentMatches;
}

int main() {
    vector<vector<int>> studentPrefs = {{0, 1, 2}, {1, 2, 0}, {2, 0, 1}};
    vector<vector<int>> hospitalPrefs = {{0, 1, 2}, {1, 0, 2}, {2, 1, 0}};

    vector<int> matches = galeShapley(studentPrefs, hospitalPrefs);
    for (int s = 0; s < matches.size(); ++s) {
        cout << "Student " << s << " matched with Hospital " << matches[s] << endl;
    }
    return 0;
}
