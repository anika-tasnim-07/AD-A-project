#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<iomanip>

using namespace std;


// --- 1. Merge Sort (Shormi) ---
struct Product {
    string name;
    int price;
    int rating;
};

void merge(vector<Product>& products, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Product> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = products[left + i];
    for (int j = 0; j < n2; j++) R[j] = products[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].price <= R[j].price) {
            products[k] = L[i];
            i++;
        } else {
            products[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { products[k] = L[i]; i++; k++; }
    while (j < n2) { products[k] = R[j]; j++; k++; }
}

void mergeSort(vector<Product>& products, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(products, left, mid);
    mergeSort(products, mid + 1, right);
    merge(products, left, mid, right);
}

// --- 2. Linear Search (Anika) ---

void searchProduct(const vector<Product>& products, string targetName) {
    bool found = false;
    for (const auto& p : products) {
        if (p.name == targetName) {
            cout << "\n[Found] Product: " << p.name
                 << ", Price: " << p.price
                 << ", Rating: " << p.rating << "/10" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n[Not Found] Sorry, the product '" << targetName << "' was not found." << endl;
    }
}


// --- 3. Knapsack Algorithm (Toufik) ---

void suggestBestCombo(int budget, const vector<Product>& products) {
    int n = products.size();

    vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= budget; w++) {
            if (products[i - 1].price <= w) {


                int valWithItem = products[i - 1].rating + dp[i - 1][w - products[i - 1].price];
                int valWithoutItem = dp[i - 1][w];
                dp[i][w] = max(valWithItem, valWithoutItem);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxRating = dp[n][budget];
    cout << "\n--- Smart Suggestion ---" << endl;
    cout << "Maximum possible Rating Score within budget: " << maxRating << endl;

    cout << "Recommended items to buy:" << endl;
    int w = budget;
    for (int i = n; i > 0 && maxRating > 0; i--) {
        if (maxRating == dp[i - 1][w]) {
            continue;
        } else {

            cout << "- " << products[i - 1].name
                 << " (Price: " << products[i - 1].price
                 << ", Rating: " << products[i - 1].rating << ")" << endl;

            maxRating -= products[i - 1].rating;
            w -= products[i - 1].price;
        }
    }
}

void displayProducts(const vector<Product>& products) {
    cout << "\n--- Product List ---" << endl;
    cout << left << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Rating" << endl;

    cout << "----------------------------------------" << endl;

    for (const auto& p : products) {
        cout << left << setw(15) << p.name
             << setw(10) << p.price
             << setw(10) << p.rating << endl;
    }
}

int main() {
    vector<Product> items = {
        {"Laptop", 50000, 9},
        {"Headphone", 2000, 7},
        {"Mouse", 500, 5},
        {"Keyboard", 1500, 6},
        {"Monitor", 12000, 8},
        {"Pendrive", 800, 4},
        {"Watch", 6000, 6},
        {"Cycle", 23000, 7}
    };

    int choice;
    do {
        cout << "\n==============================" << endl;
        cout << "   SMART SHOPPING ASSISTANT   " << endl;
        cout << "==============================" << endl;
        cout << "1. Show All Products" << endl;
        cout << "2. Sort by Price (Merge Sort)" << endl;
        cout << "3. Search Product (Linear Search)" << endl;
        cout << "4. Budget Planner (Knapsack Algo)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice (0-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayProducts(items);
                break;
            case 2:
                mergeSort(items, 0, items.size() - 1);
                cout << "\n[Success] Products sorted by price (Low to High)." << endl;
                displayProducts(items);
                break;
            case 3: {
                string name;
                cout << "Enter product name to search: ";
                cin >> name;
                searchProduct(items, name);
                break;
            }
            case 4: {
                int budget;
                cout << "Enter your budget: ";
                cin >> budget;
                suggestBestCombo(budget, items);
                break;
            }
            case 0:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
