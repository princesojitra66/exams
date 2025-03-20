#include<iostream>
using namespace std;
int main()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of cols: ";
    cin >> cols;

    int arr[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "2D array list: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int max_ele = arr[0][0];

    cout << "Largest element is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max_ele)
            {
                max_ele = arr[i][j];
            }
        }
        cout << endl;
    }
    cout << max_ele << endl;
    return 0;
}