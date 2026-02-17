#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> at(n), bt(n), rt(n), wt(n, 0), tat(n), ct(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter AT and BT: ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    int complete = 0, time = 0;

    while(complete < n) {
        int shortest = -1;
        int minm = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < minm) {
                minm = rt[i];
                shortest = i;
            }
        }

        if(shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0) {
            complete++;
            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
        cout << i+1 << "\t" << at[i] << "\t"
             << bt[i] << "\t" << ct[i] << "\t"
             << tat[i] << "\t" << wt[i] << endl;

    return 0;
}

// exmple to run:
// 4
// 0 8
// 1 4
// 2 9
// 3 5