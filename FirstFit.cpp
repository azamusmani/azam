#include <iostream>
#include <vector>

using namespace std;

// Function to allocate memory using First Fit technique
void firstFit(vector<int>& blockSize, vector<int>& processSize) {
    vector<int> allocation(processSize.size(), -1);

    for (int i = 0; i < processSize.size(); ++i) {
        for (int j = 0; j < blockSize.size(); ++j) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size.\tBlock No\n";
    for (int i = 0; i < processSize.size(); ++i) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1;
        } else {
            cout << "Not allocated";
        }
        cout << endl;
    }
}

// Function to allocate memory using Best Fit technique
void bestFit(vector<int>& blockSize, vector<int>& processSize) {
    vector<int> allocation(processSize.size(), -1);

    for (int i = 0; i < processSize.size(); ++i) {
        int bestIdx = -1;
        for (int j = 0; j < blockSize.size(); ++j) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size.\tBlock No\n";
    for (int i = 0; i < processSize.size(); ++i) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1;
        } else {
            cout << "Not allocated";
        }
        cout << endl;
    }
}

// Function to allocate memory using Worst Fit technique
void worstFit(vector<int>& blockSize, vector<int>& processSize) {
    vector<int> allocation(processSize.size(), -1);

    for (int i = 0; i < processSize.size(); ++i) {
        int worstIdx = -1;
        for (int j = 0; j < blockSize.size(); ++j) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size.\tBlock No\n";
    for (int i = 0; i < processSize.size(); ++i) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1;
        } else {
            cout << "Not allocated";
        }
        cout << endl;
    }
}

// Function to allocate memory using Next Fit technique
void nextFit(vector<int>& blockSize, vector<int>& processSize) {
    vector<int> allocation(processSize.size(), -1);
    int idx = 0; // Start from the first block for next fit

    for (int i = 0; i < processSize.size(); ++i) {
        while (idx < blockSize.size() && (blockSize[idx] < processSize[i] || allocation[i] != -1)) {
            idx = (idx + 1) % blockSize.size(); // Wrap around if reached the end
        }
        if (idx < blockSize.size()) {
            allocation[i] = idx;
            blockSize[idx] -= processSize[i];
            idx = (idx + 1) % blockSize.size(); // Move to the next block for the next allocation
        }
    }

    cout << "\nProcess No.\tProcess Size.\tBlock No\n";
    for (int i = 0; i < processSize.size(); ++i) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1;
        } else {
            cout << "Not allocated";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of memory blocks: ";
    cin >> n;
    vector<int> blockSize(n);
    cout << "Enter size of each memory block: ";
    for (int i = 0; i < n; ++i) {
        cin >> blockSize[i];
    }

    cout << "Enter number of processes: ";
    cin >> m;
    vector<int> processSize(m);
    cout << "Enter size of each process: ";
    for (int i = 0; i < m; ++i) {
        cin >> processSize[i];
    }

    cout << "First Fit Allocation:\n";
    firstFit(blockSize, processSize);

    cout << "\nBest Fit Allocation:\n";
    bestFit(blockSize, processSize);

    cout << "\nWorst Fit Allocation:\n";
    worstFit(blockSize, processSize);

    cout << "\nNext Fit Allocation:\n";
    nextFit(blockSize, processSize);

    return 0;
}
