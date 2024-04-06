#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int reward;
    int worker;

    Task(int r, int w) : reward(r), worker(w) {}
};

bool compare(Task& a, Task& b) {
    return a.reward > b.reward;
}

void distributeTasks(vector<int>& tasks, int m) {
    vector<Task> taskList;
    int totalReward = 0;

    for (int i = 0; i < tasks.size(); ++i) {
        taskList.push_back(Task(tasks[i], 0));
        totalReward += tasks[i];
    }

    sort(taskList.begin(), taskList.end(), compare);

    for (int i = 0; i < taskList.size(); ++i) {
        taskList[i].worker = i % m; 
    }

    for (int i = 0; i < taskList.size(); ++i) {
        cout << "Task " << i + 1 << " co thu lao: " << taskList[i].reward << " cho cong nhan " << taskList[i].worker + 1 << endl;
    }
}

int main() {
    vector<int> tasks = {5, 8, 4, 7, 2, 6}; 
    int m = 3;
    distributeTasks(tasks, m);
    return 0;
}
