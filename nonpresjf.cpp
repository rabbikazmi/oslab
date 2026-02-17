#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Process {
    int id, at, bt, ct, tat, wt;
};

bool compare(Process a, Process b) {
    return a.bt < b.bt;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for(int i = 0; i < n; i++) {
        p[i].id = i+1;
        cout << "Enter AT and BT: ";
        cin >> p[i].at >> p[i].bt;
    }

    sort(p.begin(), p.end(), compare);

    int time = 0;
    for(int i = 0; i < n; i++) {
        if(time < p[i].at)
            time = p[i].at;

        p[i].ct = time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        time = p[i].ct;
    }

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
        cout << p[i].id << "\t" << p[i].at << "\t"
             << p[i].bt << "\t" << p[i].ct << "\t"
             << p[i].tat << "\t" << p[i].wt << endl;

    return 0;
}

// exmple to run: 
// 4
// 0 8
// 1 4
// 2 9
// 3 5  

