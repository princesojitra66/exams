#include<iostream>
using namespace std;

// UDF
 int add(int n1 , int n2){
    return n1 + n2;
 }
 int sub(int n1 , int n2){
    return n1 - n2;
 }

  int mul(int n1 , int n2){
    return n1 * n2;
 }

   float di(int n1 , int n2){
    return n1 / n2;
 }

   int mod(int n1 , int n2){
    return n1 % n2;
 }


int main(){
    int n;
    // loop
       do{
        cout << "====== your numbers your hand ======"<<endl;
        cout<<" press 1 (+)"<<endl;
        cout<<" press 2 (-)"<<endl;
        cout<<" press 3 (*)"<<endl;
        cout<<" press 4 (/)"<<endl;
        cout<<" press 5 (%)"<<endl;
        cout<<" press 0 exit"<<endl;
        cout<<"press any one number : - ";
        cin>>n;
    // switch
        switch (n)
        {
    
            case 1:
            int an1 ,an2 ;
              cout << "enter first value = " ;
              cin >> an1;
              cout << "enter second value = " ;
              cin >> an2;
            //   add(n1,n2);

              cout <<"  your addition is "<< an1 << " + " << an2 << " = " << add(an1,an2) << endl;
            break;
            case 2:
                int sn1 ,sn2 ;
              cout << "enter first value = " ;
              cin >> sn1;
              cout << "enter second value = " ;
              cin >> sn2;
              cout <<"  your subtraction is "<< sn1 << " - " << sn2 << " = " << sub(sn1,sn2) << endl;
             break;
            case 3:
                 int mn1 ,mn2 ;
              cout << "enter first value = " << endl;
              cin >> mn1;
              cout << "enter second value = " << endl;
              cin >> mn2;
              cout<<"  your multiplication is " << mn1 << " * " << mn2 << " = " << mul(mn1,mn2) << endl;
             break;
            case 4:
                int dn1 ,dn2 ;
              cout << "enter first value = " << endl;
              cin >> dn1;
              cout << "enter second value = " << endl;
              cin >> dn2;
              cout <<"  your division is "<< dn1 << " / " << dn2 << " = " << di(dn1,dn2) << endl;
            break;
            case 5: 
                 int mon1 ,mon2 ;
              cout << "enter first value = " << endl;
              cin >> mon1;
              cout << "enter second value = " << endl;
              cin >> mon2;
              cout <<"  your modulus is "<< mon1 << " % " << mon2 << " = " << mod(mon1,mon2) << endl;
            break;
            case 0:
                cout << "Exit...." << endl;
            break;
            default:
                cout << "Invalid choice!!! Please enter valid choice." << endl;
             break;
        }
    }while(n>0);


    return 0;
}