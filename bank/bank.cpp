#include <iostream>
using namespace std;

class Bankaccount
{
private:
    string accountNumber;
    string accountHolderName;
    
    public:
    
    double balance = 0;
    void get(string name, string accNum)
    {
        accountHolderName = name;
        accountNumber = accNum;
        
    }
    void deposite(double amount)
    {
        this->balance = this->balance + amount;
    }

    void withdraw(double amount)
    {
        if (this->balance >= amount)
        {
            this->balance = this->balance - amount;
            cout << "Collect your cash..." << endl;
        }
        else
        {
            cout << "Insufficient Balance..." << endl;
        }
    }

    void displayAccountInfo()
    {
        cout << "account number = " << this->accountNumber << endl
             << "account holder name = " << this->accountHolderName << endl
             << "balance = " << this->balance << endl;
    }

    void getBalance()
    {
        cout << "Your account balance is " << this->balance << endl;
    }
};
class Savingaccount : public Bankaccount
{
private:
    double intrestRate = 5;

public:
    void calculateIntrest()
    {
        double intrest;
        intrest = this->balance * this->intrestRate * 1 / 100;
        cout << " Your current interst amount is :- " << intrest << endl;
    }
};
class Checkingaccount : public Bankaccount
{
public:
    double overDraftLimit = 10000;

public:
    void withDraw(double num1)
    {
        double amount;
        amount = num1;
        if (this->balance + this->overDraftLimit >= amount)
        {
            this->balance = this->balance - amount;
        }
        else
        {
            cout << "you withdrow exceed your overdraftlimit...." << endl;
        }
    }
    void deposite(double amount)
    {
        this->balance = this->balance + amount;
        if(this->balance >= 0){
            overDraftLimit = 10000;
        }
    }

    void checkOverDarft()
    {
        if (balance < 0 && balance > -10000)
        {
            this->overDraftLimit = overDraftLimit + balance;
            cout << "you have " << this->overDraftLimit << " overDraftLimit left..." << endl;
            overDraftLimit = 10000;
        }
        else
        {
            cout << "You have " << this->overDraftLimit << " overdraftlimit left..." << endl;
        }
    }
};
class Fixeddipositeaccount : public Savingaccount
{
private:
    int term;

public:
    void compuding(int term, double num1)
    {
        double c_amount;
        c_amount = num1;
        this->term = term;
        for (int i = 1; i <= term; i++)
        {
            int compund;
            compund = c_amount * 2.5 * 1 / 100;
            c_amount = c_amount + compund;
        }
        cout << " Your fd after your " << this->term << " month term is :- " << c_amount << endl;
    }
    void simple(int term, double num1)
    {
        double s_amount, simply;
        s_amount = num1;
        this->term = term;
        simply = s_amount * 2.5 * term / 100;
        s_amount = s_amount + simply;
        cout << " Your fd after your " << this->term << " month term is :- " << s_amount << endl;
    }
    void calculateIntrest(int term, double num1)
    {
        double t_amount;
        t_amount = num1;
        this->term = term;
        if (term > 6)
        {
            compuding(term, t_amount);
        }
        else
        {
            simple(term, t_amount);
        }
    }
};

int main()
{
    Savingaccount s1;
    Checkingaccount c1;
    Fixeddipositeaccount f1;

    int type;
    string me;
    string name;
    string accountNum;
    
    do
    {
        cout << endl<<"------ welcome to our invisible bank ------" << endl<<endl;
        cout << "------ Select Account Type ------" << endl<<endl;
        cout << "1. Creat Saving Account " << endl;
        cout << "2. Creat Current Account" << endl;
        cout << "3. Creat Fixed Deposit Account" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> type;
        switch (type)
        {
            case 1:
            cout << "You have selected Saving Account." << endl;
            cout << "Enter account holder name: ";
            cin >> name;
            cout << "Enter account number: ";
            cin >> accountNum;
            s1.get(name, accountNum);
            cout <<" Congratulations ! Your saving account has been created successfully." << endl;
            int choice;
            do
            {
                cout << "------ Saving Account Menu ------" << endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Check Balance" << endl;
                cout << "4. Account Information" << endl;
                cout << "5. your Interest amount" << endl;
                cout << "0. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                
                switch (choice)
                {
                    case 1:
                    double money;
                    cout << "----Deposite----" << endl
                         << endl;
                    cout << "Deposite Your Money :- ";
                    cin >> money;
                    if (money > 0)
                    {
                        s1.deposite(money);
                        cout << "Money diposite successfully..." << endl
                             << endl;
                        cout << "Would you like cheak your balance press y/n :- ";
                        cin >> me;
                        cout << endl;
                        if (me == "y")
                        {
                            s1.getBalance();
                        }
                        else if (me == "n")
                        {
                            cout << "Thank you for banking with us..." << endl;
                        }
                        else
                        {
                            cout << "press only y/n..." << endl;
                        }
                    }
                    else
                    {
                        cout << "can't enter minus value" << endl;
                    }
                    break;
                    case 2:
                        double withMoney;
                        cout << "----withdrow----" << endl
                             << endl;
                        cout << "Enter amount to withdraw :- ";
                        cin >> withMoney;
                        cout << endl;
                        if (withMoney > 0)
                        {
                            s1.withdraw(withMoney);
                            cout << "Would you like cheak your balance press y/n :- ";
                            cin >> me;
                            if (me == "y")
                            {
                                s1.getBalance();
                            }
                            else if (me == "n")
                            {
                                cout << "Thank you for banking with us..." << endl;
                            }
                            else
                            {
                                cout << "press only y/n..." << endl;
                            }
                        }
                        break;
                    case 3:
                    cout << "----your balance----" << endl
                    << endl;
                    s1.getBalance();
                    cout << "Thank you..." << endl
                    << endl;
                    break;
                    case 4:
                        cout << "----account detail----" << endl
                             << endl;
                        s1.displayAccountInfo();
                        cout << "Thank you..." << endl
                             << endl;
                        break;
                case 5:
                   cout << "----intrestrate_amount----" << endl
                         << endl;
                    s1.calculateIntrest();
                    cout << "Note :- This intrestrate amount is for 1 year period..." << endl;
                    cout << "Thank you...." << endl;
                    break;
                case 0:
                    cout << "Enter valid choice...." << endl;
                    break;
                default:
                    cout << "Enter valid chice..." << endl
                         << endl;
                    break;
                }
            } while (choice != 0);

            break;
        case 2:
        cout << "You have selected Current Account." << endl;
        cout << "Enter account holder name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> accountNum;
        c1.get(name, accountNum);
        cout <<"Congratulations! Your Current account has been created successfully." << endl;
        int choice1;
            do
            {
                cout << "----Current Account Menu----" << endl;
                cout << "1. Deposit" << endl;
                cout << "2. Withdraw" << endl;
                cout << "3. Check Balance" << endl;
                cout << "4. Account Information" << endl;
                cout << "5. your overdraft limit" << endl;
                cout << "0. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice1;

                switch (choice1)
                {
                    case 1:
                        double money3;
                        cout << "----Deposite----" << endl
                             << endl;
                        cout << "Deposite Your Money :- ";
                        cin >> money3;
                        if (money3 > 0)
                        {
                            c1.deposite(money3);
                            cout << "Money diposite successfully..." << endl
                                 << endl;
                            cout << "Would you like cheak your balance press y/n :- ";
                            cin >> me;
                            cout << endl;
                            if (me == "y")
                            {
                                c1.getBalance();
                            }
                            else if (me == "n")
                            {
                                cout << "Thank you for banking with us..." << endl;
                            }
                            else
                            {
                                cout << "press only y/n..." << endl;
                            }
                        }
                        else
                        {
                            cout << "can't enter minus value" << endl;
                        }
                        break;
                    case 2:
                        double withMoney3;
                        cout << "----withdrow----" << endl
                             << endl;
                        cout << "Enter amount to withdraw :- ";
                        cin >> withMoney3;
                        cout << endl;
                        if (withMoney3 > 0)
                        {
                            c1.withDraw(withMoney3);
                            cout << "Would you like cheak your balance press y/n :- ";
                            cin >> me;
                            if (me == "y")
                            {
                                c1.getBalance();
                            }
                            else if (me == "n")
                            {
                                cout << "Thank you for banking with us..." << endl;
                            }
                            else
                            {
                                cout << "press only y/n..." << endl;
                            }
                        }
                        break;
                    case 3:
                    cout << "----your balance----" << endl
                    << endl;
                    c1.getBalance();
                    cout << "Thank you..." << endl
                    << endl;
                    break;
                    case 4:
                        cout << "----account detail----" << endl
                             << endl;
                        c1.displayAccountInfo();
                        cout << "Thank you..." << endl
                             << endl;
                        break;
                case 5:
                    cout << "----overdraft-limit----" << endl
                         << endl;
                    c1.checkOverDarft();
                    break;
                default:
                    cout << "Enter valid choice..." << endl
                         << endl;
                    break;
                }
            } while (choice1 != 0);

            break;
        case 3:
        cout << "You have selected Fixed Deposit Account." << endl;
        cout << "Enter account holder name: ";
        cin >> name;
        cout << "Enter account number: ";
        cin >> accountNum;
        f1.get(name, accountNum);
        cout <<"Congratulations! Your Fixed Deposit account has been created successfully." << endl;
        int choice2;
            do
            {
                cout << "----Fixed Deposit Account Menu----" << endl;
                     cout << "1. Deposit" << endl;
                     cout << "2. Withdraw" << endl;
                     cout << "3. Check Balance" << endl;
                     cout << "4. Account Information" << endl;
                     cout << "5. interest on fixed deposit account."<< endl;
                     cout << "0. Exit" << endl;
                     cout << "Enter your choice: ";
                     cin >> choice2;

                switch (choice2)
                {
                    case 1:
                        double money1;
                        cout << "----Deposite----" << endl
                             << endl;
                        cout << "Deposite Your Money :- ";
                        cin >> money1;
                        if (money1 > 0)
                        {
                            f1.deposite(money1);
                            cout << "Money diposite successfully..." << endl
                                 << endl;
                            cout << "Would you like cheak your balance press y/n :- ";
                            cin >> me;
                            cout << endl;
                            if (me == "y")
                            {
                                f1.getBalance();
                            }
                            else if (me == "n")
                            {
                                cout << "Thank you for banking with us..." << endl;
                            }
                            else
                            {
                                cout << "press only y/n..." << endl;
                            }
                        }
                        else
                        {
                            cout << "can't enter minus value" << endl;
                        }
                        break;
                    case 2:
                        double withMoney1;
                        cout << "----withdrow----" << endl
                             << endl;
                        cout << "Enter amount to withdraw :- ";
                        cin >> withMoney1;
                        cout << endl;
                        if (withMoney1 > 0)
                        {
                            f1.withdraw(withMoney1);
                            cout << "Would you like cheak your balance press y/n :- ";
                            cin >> me;
                            if (me == "y")
                            {
                                f1.getBalance();
                            }
                            else if (me == "n")
                            {
                                cout << "Thank you for banking with us..." << endl;
                            }
                            else
                            {
                                cout << "press only y/n..." << endl;
                            }
                        }
                        break;
                    case 3:
                    cout << "----your balance----" << endl
                    << endl;
                    f1.getBalance();
                    cout << "Thank you..." << endl
                    << endl;
                    break;
                    case 4:
                        cout << "----account detail----" << endl
                             << endl;
                        f1.displayAccountInfo();
                        cout << "Thank you..." << endl
                             << endl;
                        break;
                case 5:
                    int t, u;
                    cout << "----FD----" << endl;
                    cout << "Welcome to fixed-diposite department..." << endl;
                    cout << "Note :- if your fd term is less than or equal 6 month then the interst rate are calculate on simple intrest-rate if your fd is above 6 month then the intrest rate are calculate on compunding intrest-rate...." << endl;
                    cout << "Note :- we are calucate interst per month and our intrest-rate are 2.5(%) per month" << endl;
                    cout << "Deposite Your Amount for FD :- ";
                    cin >> u;
                    cout << endl;
                    cout << "Enter your term(in month) here :- ";
                    cin >> t;
                    f1.calculateIntrest(t, u);
                    cout << "Thank you..." << endl
                         << endl;
                    break;
                case 0:
                    cout << "Thank you..." << endl
                         << endl;
                    break;

                default:
                    cout << "Enter valid choice..." <<endl<<endl;
                    break;
                }

            } while (choice2 != 0);

            break;

        default:
            break;
        }

    } while (type > 0);

    return 0;
}