#include <iostream>
#include <string>
using namespace std;

class SilverStall {
protected:
    string name;
    string detail;
    string owner;
    int cost;

public:
    SilverStall() {}

    SilverStall(string name, string detail, string owner, int cost) : name(name), detail(detail), owner(owner), cost(cost) {}

    int getTotalCost() {
        return cost;
    }
};

class GoldStall : public SilverStall {
private:
    int tvSet;

public:
    GoldStall() {}

    GoldStall(string name, string detail, string owner, int cost, int tvSet) : SilverStall(name, detail, owner, cost), tvSet(tvSet) {}

    int getTotalCost() {
        return SilverStall::getTotalCost() + (tvSet * 100);
    }
};

class PlatinumStall : public GoldStall {
private:
    int projector;

public:
    PlatinumStall() {}

    PlatinumStall(string name, string detail, string owner, int cost, int tvSet, int projector) : GoldStall(name, detail, owner, cost, tvSet), projector(projector) {}

    int getTotalCost() {
        return GoldStall::getTotalCost() + (projector * 500);
    }
};

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        string name, detail, owner;
        int cost;
        cin.ignore();
        getline(cin, name);
        getline(cin, detail);
        getline(cin, owner);
        cin >> cost;
        SilverStall s(name, detail, owner, cost);
        cout << s.getTotalCost() << endl;
    } else if (n == 2) {
        string name, detail, owner;
        int cost, tvSet;
        cin.ignore();
        getline(cin, name);
        getline(cin, detail);
        getline(cin, owner);
        cin >> cost >> tvSet;
        GoldStall g(name, detail, owner, cost, tvSet);
        cout << g.getTotalCost() << endl;
    } else if (n == 3) {
        string name, detail, owner;
        int cost, tvSet, projector;
        cin.ignore();
        getline(cin, name);
        getline(cin, detail);
        getline(cin, owner);
        cin >> cost >> tvSet >> projector;
        PlatinumStall p(name, detail, owner, cost, tvSet, projector);
        cout << p.getTotalCost() << endl;
    } else {
        cout << "Invalid Input" << endl;
    }

    return 0;
}
