#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
            cout << "Enter index " << i << " at value: ";
            cin >> arr[i];
    }

    cout << "Array list: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Negative number list: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            cout << arr[i] << " ";
        }
    }
    
    return 0;
}