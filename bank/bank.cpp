#include <iostream>
using namespace std;

class BankAccount
{
private:
    string accountHolderName;
    int accountNumber;

public:
    double balance;
    BankAccount(string name, int accNum, double initialBalance)
    {
        accountHolderName = name;
        accountNumber = accNum;
        balance = 0;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        }
    }

    void checkBalance()
    {
        cout << "Current balance: $" << balance << endl;
    }

    void displayAccountInfo()
    {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

   

 
    
};
class SavingAccount : public BankAccount
{
    public :
     void interestRate(double balance)
    {
        double interestRate;
        interestRate = balance * 4 * 1 / 100;
        cout << "you interest is " << interestRate << endl;
    }
}
// class CurrentAccount : public BankAccount
// {
//     public:
//     double newoverdarftLimit;
//      void overdraftLimit(double amount)
//     {
//          if (amount > 0 && amount <= balance)
//         {
//             balance -= amount;
//             cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
//         }
//         else
//         {
//             cout << "Invalid withdrawal amount or insufficient funds!" << endl;
//         }
//         double overdraftLimit1;
//         double overdraftLimit=1000;
//         overdraftLimit1 = balance + overdraftLimit;
//         newoverdarftLimit=overdraftLimit1-amount;
//         if (newoverdarftLimit <= 0){
//             cout << "overdraft limit is reached." << endl;
//         }else{
//             cout << "your overdraft limit is " << newoverdarftLimit<< endl;
//         }
//     }


//     void checkBalance()
//     {
//         cout << "Current balance: $" << newoverdarftLimit << endl;
//         cout <<"megi"<<endl;
//     }
// };
class CheckingAccount : public BankAccount
{
    public:
    double overdraftLimit;
    CheckingAccount() {
        overdraftLimit = 10000; // Always set it here
    }
    double withdraw(double amount) {
        if ((balance - amount) < -overdraftLimit) {
            cout << "Transaction failed! Withdrawal exceeds overdraft limit." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
        return balance;
    }

    // check overdraft
    void checkOverdraft() {
        if (balance < 0) {
            cout << "You are in overdraft. Overdraft used: " << -balance << endl;
            cout << "Remaining overdraft limit: " << overdraftLimit + balance << endl;
        } else {
            cout << "No overdraft. Your current balance is: " << balance << endl;
        }
    }
};
class FixedDepositAccount : public BankAccount
{
    public:
    double term, interestRate, money;
    double calculateInterest() {
        cout << "Enter amount for calaculate interest on fixeddeposit account.";
        cin >> money;
        cout << "Enter term (years): ";
        cin >> term;
        cout << "Enter interest rate (%): ";
        cin >> interestRate;

        double now_balance = money;

        for (int i = 0; i < term; ++i)
        {
            double yearlyInterest = (now_balance * interestRate) / 100;
            now_balance += yearlyInterest;
        }

        double totalInterest = now_balance - money;

        cout << "Final amount in " << term << " years: " << now_balance << endl;
        return totalInterest;
    }
};
int main()
{ CheckingAccount c2;
    SavingAccount s1;
    CurrentAccount c1;
    FixedDepositAccount f1;
    string name;
    int accountNum;
    double initialBalance;
    double amount=0;
    cout << "------ welcome to our invisible bank ------" << endl;
    cout << "Enter Account Holder Name: ";
    cin >> name;
    cout << "Enter Account Number: ";
    cin >> accountNum;
    // cout << "Enter Initial Balance: $";
    // cin >> initialBalance;

    BankAccount account(name, accountNum, initialBalance);

    int type;
    do
    {
        cout << "------ Account Type ------" << endl;
        cout << "1. Saving Account" << endl;
        cout << "2. Current Account" << endl;
        cout << "3. Fixed Deposit Account" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> type;
        switch (type)
        {
        case 1:
            cout << "You have selected Saving Account." << endl;
            int choice;
            do
            {
                cout << "------ Bank Menu ------" << endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Check Balance" << endl;
                cout << "4. Account Information" << endl;
                cout << "5. Interest Rate" << endl;
                cout << "0. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                double amount;
                switch (choice)
                {
                case 1:
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    account.deposit(amount);
                    break;

                case 2:
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    account.withdraw(amount);
                    break;

                case 3:
                    s1.checkBalance();
                    break;

                case 4:
                    s1.displayAccountInfo();
                    break;

                case 5:
                    cout << "your blance is  " << amount << "  and your interestrate is 4% ,for 1 year. " << endl;
                    account.interestRate(amount);
                    break;
                case 0:
                    cout << "Exiting the Saving Account system." << endl;
                    break;

                default:
                    cout << "Invalid choice! Please try again." << endl;
                }
            } while (choice != 0);
            break;
        case 2:
            cout << "You have selected Current Account." << endl;
            int choice1;
            do
            {
                cout << "------ Bank Menu ------" << endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Check Balance" << endl;
                cout << "4. Account Information" << endl;
                cout << "0. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice1;

                double amount;
                switch (choice1)
                {
                case 1:
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    account.deposit(amount);
                    break;

                case 2:
                    cout << " Note :- your overdaft limit is 1000" << endl;
                  cout << "Enter amount for withdraw: ";
                    cin >> amount;
                    double blnc = c1.withdraw(amount);
                    cout << "your balance is successfully withdraw." << endl;
                    break;

                case 3:
                    c1.checkBalance();
                    break;

                case 4:
                    c1.displayAccountInfo();
                    break;

                case 0:
                    cout << "Exiting the Current Account system." << endl;
                    break;

                default:
                    cout << "Invalid choice! Please try again." << endl;
                }
            } while (choice1 != 0);
            break;
        case 3:
            cout << "You have selected Fixed Deposit Account." << endl;
            int choice2;
            do
            {
                cout << "------ Bank Menu ------" << endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Check Balance" << endl;
                cout << "4. Account Information" << endl;
                cout << "5. interest on fixed deposit account."<< endl;
                cout << "0. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice2;

                double amount;
                switch (choice2)
                {
                case 1:
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    f1.deposit(amount);
                    break;

                case 2:
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    f1.withdraw(amount);
                    break;

                case 3:
                    f1.checkBalance();
                    break;

                case 4:
                    f1.displayAccountInfo();
                    break;
                case 5 :
                    f1.calculateInterest();
                    break;
                case 0:
                    cout << "Exiting the Fixed Deposit Account system." << endl;
                    break;

                default:
                    cout << "Invalid choice! Please try again." << endl;
                }
            } while (choice2 != 0);
            break;
        case 0:
            cout << "Exiting the Bank system...." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (type != 0);

 

    return 0;
}
