#include <iostream>
#include <queue>
#include <string>

struct Patient {
    int priority;
    std::string name;

    Patient(int p, const std::string& n) : priority(p), name(n) {}

    bool operator>(const Patient& other) const {
        return priority > other.priority;
    }
};

int main() {
    std::priority_queue<Patient, std::vector<Patient>, std::greater<Patient>> patientQueue;

    while (true) {
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            break;
        } else if (choice == 1) {
            int priority;
            std::string name;
            std::cin >> priority;
            std::cin.ignore(); 
            std::getline(std::cin, name);

            if (priority < 1 || priority > 10) {
                std::cout << "Error: Invalid priority. Please enter a priority between 1 and 10." << std::endl;
            } else {
                Patient patient(priority, name);
                patientQueue.push(patient);
            }
        } else if (choice == 2) {
            if (!patientQueue.empty()) {
                Patient nextPatient = patientQueue.top();
                patientQueue.pop();
                std::cout << "Patient with priority " << nextPatient.priority << " and name " << nextPatient.name << " has been treated." << std::endl;
            } else {
                std::cout << "Error: Queue is empty." << std::endl;
            }
        } else {
            std::cout << "Invalid choice." << std::endl;
        }
    }

    return 0;
}
