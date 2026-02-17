#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> at(n), bt(n), rt(n), priority(n);
    vector<int> wt(n, 0), tat(n), ct(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter AT, BT and Priority: ";
        cin >> at[i] >> bt[i] >> priority[i];
        rt[i] = bt[i];
    }

    int complete = 0, time = 0;

    while(complete < n) {
        int highest = -1, minPriority = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && priority[i] < minPriority) {
                minPriority = priority[i];
                highest = i;
            }
        }

        if(highest == -1) {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0) {
            complete++;
            ct[highest] = time;
            tat[highest] = ct[highest] - at[highest];
            wt[highest] = tat[highest] - bt[highest];
        }
    }

    cout << "\nP\tAT\tBT\tPr\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
        cout << i+1 << "\t" << at[i] << "\t"
             << bt[i] << "\t" << priority[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t"
             << wt[i] << endl;

    return 0;
}

// exmple to run:
// 4
// 0 8 2
// 1 4 1
// 2 9 3
// 3 5 2