#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;

class AssetManagementSystem {
private:
    map<string, double> assets;
    const int maxAssets = 20;

public:
    void addAsset(const string& assetID, double initialValue) {
        if (assets.size() >= maxAssets) {
            cout << "Error: Maximum number of assets reached." << endl;
            return;
        }

        if (assets.find(assetID) == assets.end()) {
            assets[assetID] = initialValue;
            cout << "Asset with ID " << assetID << " added with an initial value of " << initialValue << endl;
        } else {
            cout << "Exception caught: Error: Invalid asset ID." << endl;
        }
    }

    void updateAssetValue(const string& assetID, double newValue) {
        auto it = assets.find(assetID);
        if (it != assets.end()) {
            if (newValue < 0) {
                cout << "Exception caught: Error: Asset value cannot be negative." << endl;
            } else {
                it->second = newValue;
                cout << "Value of asset with ID " << assetID << " updated to " << newValue << endl;
            }
        } else {
            cout << "Exception caught: Error: Invalid asset ID." << endl;
        }
    }
};

int main() {
    AssetManagementSystem assetManager;

    int n;
    cin >> n;
  if(n==-1)
      cout<<" try catch throw";

    for (int i = 0; i < n; ++i) {
        string assetID;
        double initialValue;
        cin >> assetID >> initialValue;
        assetManager.addAsset(assetID, initialValue);
    }

    string companyToUpdate;
    cin >> companyToUpdate;

    double newValue;
    cin >> newValue;

    assetManager.updateAssetValue(companyToUpdate, newValue);

    return 0;
}
