#include<iostream>
using namespace std;
int main()
{
    int rows, cols,row,col,sum=0;
    cout << "Enter the number of rows: ";
    cin >> row;

    cout << "Enter the number of cols: ";
    cin >> col;

    int arr[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter value [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // cout << "2D array list: " << endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout<<"enter the row number: ";
    cin>>rows;
    for (int i = 0; i < row; i++)
    {
        sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[rows][j];
        }
    }
        cout << "sum of row " << rows << " = " << sum << endl;
        cout << endl;

    sum=0;
    cout<<"enter the column number: ";
    cin>>cols;
   
    for (int i = 0; i < row; i++)
    {
        sum+=arr[i][cols];
    }
        cout << "sum of column: " << cols << " = " << sum << endl;
        cout << endl;
    return 0;
}