#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int>& subset) {
    for (int i : subset) {
        cout << i << " ";
    }
    cout << endl;
}

bool isBalanced(vector<int>& weights, int sum, int leftSum, int index, vector<int>& subset1) {
    if (leftSum == sum - leftSum) {
        printSubset(subset1);
        return true;
    }
    if (index >= weights.size() || leftSum > sum - leftSum) {
        return false;
    }
    subset1.push_back(weights[index]);
    bool include = isBalanced(weights, sum, leftSum + weights[index], index + 1, subset1);
    subset1.pop_back();
    bool exclude = isBalanced(weights, sum, leftSum, index + 1, subset1);
    return include || exclude;
}

void splitWeights(vector<int>& weights) {
    int sum = 0;
    for (int weight : weights) {
        sum += weight;
    }
    if (sum % 2 != 0) {
        cout << "Khong the chia deu duoc.\n";
        return;
    }
    vector<int> subset1;
    if (!isBalanced(weights, sum, 0, 0, subset1)) {
        cout << "Khong the chia deu duoc.\n";
    }
}

int main() {
    vector<int> weights = {6, 2, 3, 4, 5};
    splitWeights(weights);
    return 0;
}
