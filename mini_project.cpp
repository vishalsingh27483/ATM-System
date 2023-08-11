#include <conio.h>
#include <iostream>
#include <string>
using namespace std;

class ATM{
    
    private :

    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

    public :
    void setData(long int account_no_x, string name_x, int PIN_x, double baalnce_x, string mobile_no_x){
        
        account_no = account_no_x;
        name = name_x;
        PIN = PIN_x;
        balance=baalnce_x;
        mobile_no = mobile_no_x;
    }

    long int getAccountNO(){
        return account_no;
    }

    string getName(){
        return name;
    }

    int getPIN(){
        return PIN;
    }

    double getBalance(){
        return balance;
    }

    string getMobileNo(){
        return mobile_no;
    }

    //For updating the user mobile number
    
    void setmobile(string mob_prev, string mob_new){

        if (mob_prev == mobile_no){
            mobile_no = mob_new;

            cout <<endl <<"Successfully updated mobile number " ;
            _getch;
        }
        else{
            cout <<endl <<"Incorrect !!! old mobile number ";
            _getch;
        }
    }

    void cashWithDraw(int amount_a){
        if(amount_a < 0 && amount_a <balance){
            balance -= amount_a;
            cout << endl <<"Please collect the cash ";
            cout <<endl <<"Available balance : " <<balance;
            _getch;
        }
        else{
            cout << endl <<"Invalid Input or Insufficient balance ";
            _getch;
        }
    }

};

int main()
{
    int choice = 0, enterPIN;
    long int enterAccountNo;

    system("cls");

    ATM user1;
    user1.setData(3078000100196984, "Vishal", 7752, 800000, "9821278517");

    do{
        system ("cls");

        cout <<endl <<"******WELCOME TO THE ATM******"<<endl;
        cout <<endl <<"Enter the account number : "<<endl;
        cin>>enterAccountNo;

        cout <<endl <<"Enter your PIN : " <<endl;           //by taking account no. and PIN we are simply authenticating the user.
        cin>>enterPIN;

        if ((enterAccountNo == user1.getAccountNO()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system ("cls");
                cout <<endl <<"******WELCOME TO THE ATM******" <<endl;
                cout <<endl <<"Select Option" <<endl;
                cout <<endl <<"1. Check Balance " <<endl;
                cout <<endl <<"2. Cash Withdaraw " <<endl;
                cout <<endl <<"3. Show User Details " <<endl;
                cout <<endl <<"4. Update Mobile number " <<endl;
                cout <<endl <<"5. Exit "<<endl;
                cin>>choice;

                switch (choice){
                    case 1:
                        cout<<endl <<"Your ACcount Balance is : " <<user1.getBalance();
                        _getch();
                        break;

                    case 2:
                        cout<<endl <<"Enter the Amount : ";
                        cin>>amount;
                        user1.cashWithDraw(amount);
                       
                        break;

                    case 3:
                        cout<<endl <<"***User Details Are:-***";
                        cout<<endl <<"-> Account Number " <<user1.getAccountNO();
                        cout<<endl <<"-> Name " <<user1.getName();
                        cout<<endl <<"-> Balance " <<user1.getBalance();
                        cout<<endl <<"-> Mobile Number " <<user1.getMobileNo();

                        _getch();
                        break;

                    case 4:
                        cout<<endl <<"Enter Old Mobile Number ";
                        cin>>oldMobileNo;

                        cout<<endl <<"Enter New Mobile Number ";
                        cin>>newMobileNo;    

                        user1.setmobile(oldMobileNo, newMobileNo);

                        break;

                    case 5:
                        exit(0);

                    default:
                        cout<<endl <<"Enter Valid Data !!! ";

                }

            }
        }
        

    } while(1);

   return 0;
}