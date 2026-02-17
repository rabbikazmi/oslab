#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> at(n), bt(n), wt(n), tat(n), ct(n);

    cout << "Enter Arrival Time and Burst Time:\n";
    for(int i = 0; i < n; i++) {
        cout << "Process " << i+1 << ": ";
        cin >> at[i] >> bt[i];
    }

    ct[0] = at[0] + bt[0];
    wt[0] = 0;
    tat[0] = bt[0];

    for(int i = 1; i < n; i++) {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
        cout << i+1 << "\t" << at[i] << "\t" << bt[i]
             << "\t" << ct[i] << "\t" << tat[i]
             << "\t" << wt[i] << endl;

    return 0;
}
