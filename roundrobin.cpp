#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> at(n), bt(n), rt(n), wt(n, 0), tat(n), ct(n);

    for(int i = 0; i < n; i++) {
        cout << "Enter AT and BT: ";
        cin >> at[i] >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0, complete = 0;

    while(complete < n) {
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                    complete++;
                }
            }
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
// 3