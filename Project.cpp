




//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&






#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>					//including libraries
#include<cstdlib>
using namespace std;
	
class User					//class User
{
public:
	int Accountnumber;
	int PIN;					//declaring data members
	int balance;
public:
	User()
	{						//constructor
	}
	User(int a,int p,int b)
	{
	Accountnumber=a;			//parameterized constructor
	PIN=p;
	balance=b;
	}
	void setAccountnumber(int a);
	void setPIN(int p);
	int getAccountnumber();			//member functions declaration
	int getPIN();
};
void User::setAccountnumber(int a)
{							//member functions definition
	Accountnumber=a;
}
void User::setPIN(int p)
{
	PIN=p;
}
int User::getAccountnumber()			//member functions definition
{
	return Accountnumber;
}
int User::getPIN()
{
	return PIN;
}

	


		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		

	
	
	
	
	
class Mainmenu: public User				//class Mainmenu
{
public:
	int choice;					//declaring data members
	int g;

public:
Mainmenu()						//constructor
	{
	}
Mainmenu(int a,int p,int b,int c):User(a,p,b)
	{
	choice=c;
	balance=b;					//parameterized constructor
	//storing balance using file handling
	}
void setbalance(int b)
{
balance=b;
cout<<"The balance is :"<<balance<<endl;			//member functions defnition
}
int getbalance()
	{
	return balance;		
	}
};




		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		


class Withdraw:public Mainmenu		//class Withdraw
{
private:
	int option;				//declaring data members
public:
Withdraw()
	{					//constructor
	}
Withdraw(int o)
	{
	    option=o;				//parameterized constructor
	}
int amount(char l,Mainmenu a2)					//member functions defnition
{
	if(option==1&&balance>=20)
	{
		balance-=20;
		cout<<"Your balance is "<<balance<<" :)"<<endl;
		a2.setbalance(balance);
	}
	else if(option==2&&balance>=40)
	{
		balance=balance-40;
		cout<<"Your balance is "<<balance<<" :)"<<endl;
		a2.setbalance(balance);
		
	}
	else if(option==3&&balance>=60)
	{
		balance=balance-60;
		cout<<"Your balance is "<<balance<<" :)"<<endl;
		a2.setbalance(balance);
		
	}
	else if(option==4&&balance>=100)
	{
		balance=balance-100;
		cout<<"Your balance is "<<balance<<" :)"<<endl;
		a2.setbalance(balance);
	
	}
	else if(option=5&&balance>=200)
	{
		balance=balance-200;
		cout<<"Your balance is "<<balance<<" :)"<<endl;
		a2.setbalance(balance);
		
	}
	else if(option==6)
	{
		l=='f';
	}
}

};



		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		


class Deposit:public Mainmenu			//class Deposit
{
	private:
	int depositamount;				//declaring data members
	
	public:
	Deposit()						//constructor
	{
	}
	Deposit(int m)				//parameterized constructor
	{
		depositamount=m;
	}
	int amount1(char l,Mainmenu a2)				//member functions defnition
	{
		balance=balance+depositamount;
		cout<<"Your balance is :"<<balance<<endl;
		a2.setbalance(balance);
	
	}
	


};



		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		




int main()
{
	
	int a,p;
	int c;						//declaring and initializing variables
	int o;
	char l='f';
	int m;
	int a1,p1,b1;					//declaring and initializing variables
	int b;
	int s=0;
do				//do while loop to continue displaying welcome msg till accout validates
{
	if(l=='f')						
	{
	while(s==0)
	{
		cout<<"WELCOME!"<<endl;				//displaying welcome msg
		cout<<"Enter  the account number:"<<endl;
		cin>>a;
		cout<<"Enter the PIN number:"<<endl;			//taking input account num and pin
		cin>>p;

		ifstream file("database.txt");			//reading from file
			while(file>>a1>>p1>>b1)
			{
				if(a==a1&&p==p1)		//authenticating user account
				{
					b=b1;			//storing balance
					cout<<b<<endl;			//displaying balance
					User a1(a,p,b);		//calling user constructor to store info
					s=1;
				}
			}
	if(s==0)
	{							//if account is invalid
		cout<<"Invalid account :( "<<endl;
	}
	}
	
	if(s==1)
	{
	do				//do while to display menu after every transaction
	{
	
	cout<<"Enter the choice: "<<endl<<"Press 1 to get balance."<<endl<<"Press 2 to withdraw"<<endl<<"Press 3 to deposit"<<endl<<"Press 4 to Exit"<<endl;		//displaying menu
	cin>>c;
	
	if(c!=1&&c!=2&&c!=3&&c!=4)			//if uer enters wrong input
		cout<<"Enter the valid option i.e 1,2,3 or 4 please :) "<<endl;
	}
	while(c!=1&&c!=2&&c!=3&&c!=4);		//until user enters valid input
	Mainmenu a2(a,p,b,c);		//class mainmenu constructor
	
	if(c==1)				//to display balance
	{
		cout<<"The balance is:";
		cout<<a2.getbalance()<<endl;		//calling member function
	}
	

	if(c==2)			//to withdraw
	{
		l='q';
		cout<<"Enter the option :"<<endl;
		cout<<"Enter 1 to withdraw $20. "<<endl<<"Press 2 to withdraw $40."<<endl<<"Press 3 to withdraw $60."<<endl<<"Press 4 to withdraw $100."<<endl<<"Press 5 to withdraw $200."<<endl<<"Press 6 to cancel transaction."<<endl;					//displaying menu
	
		
	
		cin>>o;			//taking input
		if(o==6)			//cancelling transaction
		l='f';
				//if user has not enough balance to withdraw
		if((o==1&&a2.getbalance()<=21)||(o==2&&a2.getbalance()<=41)||(o==3&&a2.getbalance()<=61)||(o==4&&a2.getbalance()<=101)||(o==5&&a2.getbalance()<=201))
		{
			cout<<"Your current balance is less than the withdrawal amount :("<<endl<<"PLease enter a value according to your current balance that is :"<<a2.getbalance()<<" :)"<<endl;
		l='f';
		}
		if(o==1||o==2||o==3||o==4||o==5)		//if user has enough balance
		{
			l='q';
			Withdraw a3(o);
			a3.amount(l,a2);		//withdrawing money
			//point 6 cash dispenser
			cout<<"Take the money please :) "<<endl;	//displaying msg
			l='f';
		}
		
	}
	if(c==3)			//to deposit money
	{
		l='q';
		cout<<"Enter the deposit amount or type 0 to cancel transaction"<<endl;
		cin>>m;			//taking input
		//input using keypad
		if(m==0)		//cancelling transaction
		{
			l='f';
		}
		else
		{
			l='q';
			cout<<"Insert a deposit envelope into the deposit slot :)"<<endl;
			//within two mins
			Deposit a4(m);
			a4.amount1(l,a2);		//deposting money
			l='f';
		}
	
	}
	
	if(c==4)			//to exit
	{
		l='q';
		cout<<"THANK YOU :) "<<endl;		//displaying msg
		l='f';
	}
	
	}
		
}
}	
while(c==1||c==2||c==3||c==4);		//until user enters correct options 


return 0;
}

