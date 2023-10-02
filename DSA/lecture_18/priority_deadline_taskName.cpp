#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int priority;
    int deadline;
    string name;
    
    Task(int p, int d, string n) : priority(p), deadline(d), name(n) {}
};

class PriorityQueue {
public:
    vector<Task> tasks;
    
    void push(Task task) {
        tasks.push_back(task);
        sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            if (a.priority == b.priority) {
                return a.deadline < b.deadline;
            }
            return a.priority > b.priority;
        });
    }
    
    Task pop() {
        if (empty()) {
            return Task(-1, -1, "");
        }
        Task topTask = tasks.front();
        tasks.erase(tasks.begin());
        return topTask;
    }
    
    Task top() {
        if (empty()) {
            return Task(-1, -1, "");
        }
        return tasks.front();
    }
    
    bool empty() {
        return tasks.empty();
    }
};

int main() {
    int N;
    cin >> N;
    
    PriorityQueue pq;
    
    for (int i = 0; i < N; i++) {
        int priority, deadline;
        string taskName;
        cin >> priority >> deadline >> taskName;
        Task task(priority, deadline, taskName);
        pq.push(task);
    }
    
    cout << "Executed Tasks:" << endl;
    while (!pq.empty()) {
        Task task = pq.pop();
        cout << task.name << endl;
    }
    
    return 0;
}
