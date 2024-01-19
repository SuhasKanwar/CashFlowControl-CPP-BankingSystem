// Banking system mini project
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int index1=0, index2,index3,transaction;
    int acc_number[10]={1,2,3,4,5,6,7,8,9,10};
    int long long ph_num[10];
    string acc_psswd[10];
    int transaction_count[10]={0,0,0,0,0,0,0,0,0,0};
    int acc_num,acc_num2;
    string holder_first_name[10];
    string holder_second_name[10];
    string guardian_first_name[10];
    string guardian_second_name[10];
    int age[10];
    int long long aadhaar_num[10];
    float balance[10]={0,0,0,0,0,0,0,0,0,0};
    char choice1;
    string password;
    int choice2;
    cout<<"Welcome to the BMU Bank."<<endl;
    do
    {
        cout<<"Do you want to use netbanking (y/n): ";
        cin>>choice1;
        if (choice1 == 'y')
        {
            cout<<"1 = Open an account\n2 = Show account info\n3 = Deposit money\n4 = Withdraw money\n5 = Money transfer\n6 = Exit\n";
            cout<<"Enter your choice: ";
            cin>>choice2;
            if (choice2 == 1) // Opening an account
            {
                cout<<"Opening an account\n";
                cout<<"Enter your first name: ";
                cin>>holder_first_name[index1];
                cout<<"Enter your second name: ";
                cin>>holder_second_name[index1];
                cout<<"Enter your phone number: ";
                cin>>ph_num[index1];
                cout<<"Enter your age: ";
                cin>>age[index1];
                if (age[index1]<18)
                {
                    cout<<"Sorry you are under age you caanot open an account."<<endl;
                    break;
                }
                cout<<"Enter your aadhaar number: ";
                cin>>aadhaar_num[index1];
                cout<<"Enter your guardian's first name: ";
                cin>>guardian_first_name[index1];
                cout<<"Enter your guardian's second name: ";
                cin>>guardian_second_name[index1];
                cout<<"Enter password (password should not include spaces): ";
                cin>>acc_psswd[index1];
                cout<<"Your account is created successfully with account number "<<acc_number[index1]<<endl;
                index1=index1+1;
            }
            else if (choice2 == 2) // Show account info
            {
                cout<<"Account info\n";
                cout<<"Enter your account number: ";
                cin>>acc_num;
                index2=acc_num-1;
                cout<<"Enter password: ";
                cin>>password;
                if (acc_psswd[index2] == password)
                {
                    cout<<"Account holder's name: "<<holder_first_name[index2]<<" "<<holder_second_name[index2]<<endl;
                    cout<<"Phone number: "<<ph_num[index2]<<endl;
                    cout<<"Age: "<<age[index2]<<endl;
                    cout<<"Aadhaar number: "<<aadhaar_num[index2]<<endl;
                    cout<<"Guardin's name: "<<guardian_first_name[index2]<<" "<<guardian_second_name[index2]<<endl;
                    cout<<"Available balance: $"<<balance[index2]<<endl;
                    cout<<"Total transaction count: "<<transaction_count[index2]<<endl;
                }
                else
                {
                    cout<<"Wrong password, try again"<<endl;
                }
            }
            else if (choice2 == 3) // Deposit
            {
                cout<<"Deposit money\n";
                cout<<"Enter your account number: ";
                cin>>acc_num;
                index2=acc_num-1;
                cout<<"Enter password: ";
                cin>>password;
                if (acc_psswd[index2] == password)
                {
                    cout<<"Enter the amount you want to deposit: $";
                    cin>>transaction;
                    balance[index2]=balance[index2]+transaction;
                    cout<<"Transaction completed"<<endl;
                    cout<<"Account balance: $"<<balance[index2]<<endl;
                    transaction_count[index2]=transaction_count[index2]+1;
                }
                else
                {
                    cout<<"Wrong password, try again"<<endl;
                }
            }
            else if (choice2 == 4) // Withdraw
            {
                cout<<"Money withdrawl\n";
                cout<<"Enter your account number: ";
                cin>>acc_num;
                index2=acc_num-1;
                cout<<"Enter password: ";
                cin>>password;
                if (acc_psswd[index2] == password)
                {
                    cout<<"Enter the amount you want to withdraw: $";
                    cin>>transaction;
                    if(balance[index2] >= transaction)
                    {
                        balance[index2]=balance[index2]-transaction;
                        cout<<"Transaction completed"<<endl;
                        cout<<"Available balance: $"<<balance[index2]<<endl;
                        transaction_count[index2]=transaction_count[index2]+1;
                    }
                    else
                    {
                        cout<<"Sorry, insufficent funds."<<endl;
                        cout<<"Available balnce: $"<<balance[index2]<<endl;
                    }
                }
                else
                {
                    cout<<"Wrong password, try again"<<endl;
                }
            }
            else if (choice2 == 5) //Funds transfer
            {
                cout<<"Funds transfer\n";
                cout<<"Enter account number you want to transfer money from: ";
                cin>>acc_num;
                index2=index2-1;
                cout<<"Enter password of account with account number "<<acc_num<<": ";
                cin>>password;
                if (acc_psswd[index2] == password)
                {
                    cout<<"Enter account number you want to transfer money into: ";
                    cin>>acc_num2;
                    index3=acc_num2-1;
                    cout<<"Enter how much money do you want to transfer: $";
                    cin>>transaction;
                    if (balance[index2]>=transaction)
                    {
                        balance[index2]=balance[index2]-transaction;
                        transaction_count[index2]=transaction_count[index2]+1;
                        transaction_count[index3]=transaction_count[index3]+1;
                        balance[index3]=balance[index3]+transaction;
                        cout<<"Transaction completed"<<endl;
                        cout<<"Available balance in account "<<acc_num<<" is "<<balance[index2]<<endl;
                    }
                    else
                    {
                        cout<<"Insufficient Funds."<<endl;
                    }
                }
                else
                {
                    cout<<"Wrong password, try again"<<endl;
                }
            }
            else if (choice2 == 6) // Exit
            {
                cout<<"Thanks for contacting BMU bank.\n";
                break;
            }
            else
            {
                cout<<"Enter 1,2,3,4,5 or 6.";
            }
        }
        else if (choice1 == 'n')
        {
            cout<<"Thanks for contacting BMU bank.";
            break;
        }
        else
        {
            cout<<"Enter y or n."<<endl;
        }
    }
    while(choice2!=6);
    return 0;
}