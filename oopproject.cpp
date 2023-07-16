
#include<iostream>
#include<string>
using namespace std;

class atm 
{
    private:
       long int account_no;
       string name;
       int pin;
       double balance;
       string mobile_no;

    public:
       void setdata( long int account_no_a, string name_a, int pin_a,
                     double balance_a, string mobile_no_a )
       {
            account_no = account_no_a ;
            name = name_a ;
            pin = pin_a ;
            balance = balance_a ;
            mobile_no = mobile_no_a ;
        }

        long int getaccountno()
        {   return account_no ;  }

        string getname()
        {   return name ;   }

        int getpin()
        {   return pin ;   }

        double getbalance()
        {   return balance ;   }

        string getmobileno()
        {   return mobile_no ;   }

        
        void setmobile( string mob_pre, string mob_new)
        {
            if( mob_pre == mobile_no )
            {
                mobile_no = mob_new ;
                cout << endl << " Successfully updated mobile number ";
               
            }

            else
            {
                cout << endl << " Incorrect! old mobile number ";
                
            }
        }


        void cashwithdraw( int amount_a )
        {
            if( amount_a > 0 && amount_a < balance )
            {
                balance -= amount_a ;
                cout << endl << " Please collect yoyr cash ";
                cout << endl << " Availabe balance : " << balance ;
                
            }

            else
            {
                cout << endl << " Invalid input or Insufficient balance ";
                
            }
        }

};

int main(){

    int choice = 0, enterpin ;
    long int enteraccountno ;

    system ("cls") ;

    atm user1 ;
    user1.setdata( 123456789 , " Malk" , 1111 , 45000.90 , "4888000311" );

    do
    {
       system ("cls") ;

       cout << " ***** Welcome to ATM ****** " << endl ;
       cout << endl << " Enter your account number " ;
       cin >> enteraccountno ;
       cout << endl << " Enter PIN " ;
       cin >> enterpin ;

       if( ( enteraccountno == user1.getaccountno() ) && ( enterpin == user1.getpin() ) )
       {
        do
        {
            int amount = 0 ;
            string oldmobileno, newmobileno ;
            
            system ("cls") ;

            cout << " ***** Welcome to ATM ****** " << endl ;
            cout << endl << " Select options ";
            cout << endl << " 1. Check Balance " ;
            cout << endl << " 2. Cash Withraw " ;
            cout << endl << " 3. Show User Details " ;
            cout << endl << " 4. Update MObile Number " ;
            cout << endl << " 5. EXit " << endl ;
            cin >> choice ;

            switch (choice)
            {
                case 1 :
                   cout << endl << " Your bank balance is " << user1.getbalance() ;
                   
                   break;
                
                case 2 :
                   cout << endl << " Enter the amount : " ;
                   cin >>amount ;
                   user1.cashwithdraw( amount ) ;
                   break;

                case 3 :
                   cout << endl << " User details are : " ;
                   cout << endl << " ** Account number " << user1.getaccountno() ;
                   cout << endl << " ** Name " << user1.getname() ;
                   cout << endl << " ** Balance " << user1.getbalance() ;
                   cout << endl << " ** Mobile number " << user1.getmobileno() ;
                   
                   break;

                case 4 :
                   cout << endl << " Enter old mobile number " ;
                   cin >> oldmobileno ;
                   cout << endl << " Enter new mobile number " ;
                   cin >> newmobileno ;
                   user1.setmobile( oldmobileno, newmobileno);
                   break;

                case 5 :
                   exit(0);

                default :
                   cout << endl << " Enter valid data ! " ;


            }
            

        } while( 1 );
       }
    } while( 1 );
}
