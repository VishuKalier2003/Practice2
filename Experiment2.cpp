/*Assuming that a bank provides two types of account... Saving account with withdrawal facilities
and Compound Interest without chequebook but Current account provides withdrawal facility with 
no interest and chequebook... Create a class to store name, account number and type... Include the
methods as accept deposit and update the balance, Display the balance, Compute and deposit 
interest, permit withdrawal and update balance, check for minimum balance or impose penalty if 
necessary then update the balance... Do not use Constructors*/
#include <iostream>
#include <string>
using namespace std;
class Bank 
{
    public:
    string name;
    int account_number;
    string account_type;
    bool withdrawal_facility;
    bool chequebook;
    int balance;
    public:
    int AcceptDeposit()
    {
        int deposit;
        cout << "Enter the amount to be Deposited in the bank : Rs. ";
        cin >> deposit;
        return deposit;
    }
    public:
    void UpdateBalance(int deposit)
    {
        balance = balance + deposit;
        cout << "The Balance is successfully updated !! " << endl;
    }
    public:
    int PermitWithdrawal()
    {
        int withdraw;
        cout << "Enter amount to be withdrawn : Rs. ";
        cin >> withdraw;
        balance = balance - withdraw;
        if(balance < 0)
        {
            cout << "Your account is now Empty !!" << endl;
            balance = 0;
        }
        cout << "Your amount is successfully Withdrawn !!" << endl;
        return withdraw;
    }
    public:
    void DisplayBalance()
    {
        cout << "The Current Balance in your account is : Rs. " << balance << endl;
    }
};
class SavingsAccount: public Bank 
{
    public:
    double compound_interest;
    int minimum_balance;
    public:
    void CompoundInterest(double pr)
    {
        int r = 5;
        int t;
        double ci;
        cout << "The Compound Interest is calculated yearly !!" << endl; 
        cout << "Enter the time duration (in years) of your account till now : ";
        cin >> t;
        for(int i = 0; i < t; i++)
            ci = ci + (pr * r * t/ 100);
        cout << "The Total Interest of your Account is : Rs. " << ci << endl;
        balance = balance + ci;
    }
    public:
    void Penalty()
    {
        cout << "The minimum balance in Savings account is Rs. 1000 " << endl;
        if(balance < 1000)
        {
            cout << "Since your balance is low.. Penalty of Rs. 100 will be charged !!" << endl;
            balance = balance - 100;
            if(balance < 0)
            {
                cout << "Your account is now Empty !!" << endl;
                balance = 0;
            }
            cout << "Your balance is now successfully updated !!" << endl;
            return;
        }
        cout << "Since your account is working fine.. No penalty will be charged !!" << endl;
    }
};
class CurrentAccount: public Bank 
{
    public:
    int minimum_balance;
    public:
    void ShowInterest()
    {
        cout << "There is no Interest for Savings account !!" << endl;
        cout << "Your current balance is : Rs. " << balance << endl;
    }
    public:
    void Penalty()
    {
        cout << "The minimum balance for Current Account is Rs. 500" << endl;
        if(balance < 500)
        {
            cout << "Since your balance is low.. Penalty will be charged of Rs. 50 !!" << endl;
            balance = balance - 50;
            if(balance < 0)
            {
                cout << "Your account is now Empty !!" << endl;
                balance = 0;
            }
            cout << "Your account is updated successfully !!" << endl;
            return;
        }
        cout << "Since your account is working fine.. No penalty will be imposed !!" << endl;
    }     
};
int main()
{
    string str, ac_type;
    int ac_num;
    cout << "Enter your name ( Account Holder ) : ";
    cin >> str;
    cout << "Enter your account type ( Current or Savings ) : ";
    cin >> ac_type;
    cout << "Enter 10 digit number as your account number : ";
    cin >> ac_num;
    int x;
    if(ac_type == "Savings" || ac_type == "SAVINGS" || ac_type == "savings")
    {
        SavingsAccount savingsaccount;
        savingsaccount.account_number = ac_num;
        savingsaccount.account_type = ac_type;
        savingsaccount.name = str;
        savingsaccount.withdrawal_facility = true;
        savingsaccount.balance = 0;
        savingsaccount.chequebook = true;
        x = savingsaccount.AcceptDeposit();
        savingsaccount.UpdateBalance(x);
        savingsaccount.DisplayBalance();
        x = savingsaccount.PermitWithdrawal();
        savingsaccount.DisplayBalance();
        savingsaccount.CompoundInterest(x);
        savingsaccount.DisplayBalance();
        savingsaccount.Penalty();
        savingsaccount.DisplayBalance();
    }
    if(ac_type == "Current" || ac_type == "CURRENT" || ac_type == "current")
    {
        CurrentAccount currentaccount;
        currentaccount.account_number = ac_num;
        currentaccount.account_type = ac_type;
        currentaccount.name = str;
        currentaccount.withdrawal_facility = true;
        currentaccount.balance = 0;
        currentaccount.chequebook = true;
        x = currentaccount.AcceptDeposit();
        currentaccount.UpdateBalance(x);
        currentaccount.DisplayBalance();
        x = currentaccount.PermitWithdrawal();
        currentaccount.DisplayBalance();
        currentaccount.ShowInterest();
        currentaccount.Penalty();
        currentaccount.DisplayBalance();
        cout << x;
    }
    return 0;
}