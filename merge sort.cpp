#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Product
{
    string name;
    int price;
    int rating;
};


void mergeProducts(vector<Product>& arr, int left, int mid, int right)
{
    vector<Product> leftArr, rightArr;

    for (int i = left; i <= mid; i++)
        leftArr.push_back(arr[i]);

    for (int i = mid + 1; i <= right; i++)
        rightArr.push_back(arr[i]);

    int i = 0, j = 0, k = left;

    while (i < leftArr.size() && j < rightArr.size())
    {
        if (leftArr[i].price <= rightArr[j].price)
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
}


void mergeSort(vector<Product>& arr, int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    mergeProducts(arr, left, mid, right);
}

int main()
{
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    vector<Product> arr(n);

    cout << "\nEnter product details (name price rating):\n";
    cin.ignore(); 

    for (int i = 0; i < n; i++)
    {
        getline(cin, arr[i].name, ' ');
        cin >> arr[i].price >> arr[i].rating;
        cin.ignore();
    }

    cout << "\nBefore Sorting:\n";
    for (auto& p : arr)
        cout << p.name << "  Price: " << p.price
             << "  Rating: " << p.rating << endl;

    mergeSort(arr, 0, n - 1);

    cout << "\nAfter Sorting (price ascending):\n";
    for (auto& p : arr)
        cout << p.name << "  Price: " << p.price
             << "  Rating: " << p.rating << endl;

    return 0;
}