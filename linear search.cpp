#include<bits/stdc++.h>
using namespace std;
struct Product
{
string name;
int price;
int rating;
};
void searchProduct(const vector<Product>&products,const string&targetName)
{
    bool found = false;
    for(const auto&p:products)
    {
        if(p.name==targetName)
        {
            cout<<"Product Found:\n";
            cout<<"Name: "<<p.name<<",Price: "<<p.price<<",Rating: "<<p.rating<<endl;
            found=true;
            break;
        }
    }
    if(!found)
    {
        cout<<"Product not found.\n";
    }
}
int main()
{
    vector<Product>products;
    int n;
    cout<<"Enter number of products: ";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        Product p;
        cout<<"Enter name of produt"<<
    }
}
