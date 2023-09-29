l#include <iostream>
#include <list>

using namespace std;

class PrinterQueue {
private:
    list<int> jobs;

public:
    void enqueue(int pages) {
        jobs.push_back(pages);
        cout << "Print job with " << pages << " pages is enqueued." << endl;
    }

    void dequeue() {
        if (jobs.empty()) {
            cout << "Queue is empty." << endl;
        } else {
            int pages = jobs.front();
            jobs.pop_front();
            cout << "Processing print job: " << pages << " pages" << endl;
        }
    }

    void displayQueue() {
        if (jobs.empty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Print jobs in the queue:";
            for (int pages : jobs) {
                cout << " " << pages << " pages";
            }
            cout << endl;
        }
    }
};

int main() {
    PrinterQueue pq;

    int option;
    while (cin >> option) {
        if (option == 1) {
            int pages;
            cin >> pages;
            pq.enqueue(pages);
        } else if (option == 2) {
            pq.dequeue();
        } else if (option == 3) {
            pq.displayQueue();
        } else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}
