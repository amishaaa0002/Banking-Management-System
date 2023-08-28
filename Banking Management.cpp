#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

class BankAccount{
	
	private:
		string name;
		double balance;
		int accountNumber;
	
	public:
		BankAccount(string n,double b,int ac){
			name = n;
			balance =b;
			accountNumber = ac;
		}
		string getName(){
			return name;
		}
		double getBalance(){
			return balance;
		}
		int getAccountNumber(){
			return accountNumber;
		}
		void depositMoney(double amt){
			balance = balance + amt;
		}
		void withDraw(double amt){
			if(amt >= balance){
				balance = balance - amt;
				cout<<"..........Withdraw Sucessfully done!!.........."<<endl;
			}
			else{
				cout<<"..........Insufficient Balance !!.........."<<endl;
			}
		}
		
};

class BankManagement{
	
	private:
		
		vector<BankAccount> accounts;
		
	public:
		void AddAccount(string name,int accountNum,double balance){
			accounts.push_back(BankAccount(name,balance,accountNum));
		}
		
		void showAllAccounts(){
			cout<<"..........All Accounts Holder.........."<<endl;
			for(int i=0;i<accounts.size();i++){
				cout<<"Name: "<<accounts[i].getName()<<" "<<"Account Number :"<<accounts[i].getAccountNumber()
				<<" "<<"Balance :"<<" "<<accounts[i].getBalance()<<endl;
			}
		}
		
		void searchAccounts(int acc){
			cout<<"Account Holder"<<endl;
			
			for(int i=0;i<accounts.size();i++){
				if(accounts[i].getAccountNumber() == acc){
					cout<<"Name :"<<accounts[i].getName()
					<<" Account Number :"<<accounts[i].getAccountNumber()
					<<" Balance :"<<accounts[i].getBalance()<<endl;
				}
			}
			
		}
		
		BankAccount* findAccount(int accountNum){
			for(int i = 0; i<accounts.size();i++){
				if(accounts[i].getAccountNumber() == accountNum){
					return &accounts[i];
				}
			}
		}		
};
 main(){
	
	
	BankManagement bank;
	int choice;
	char op;
	do{
		system("cls");
		cout<<"\t\t::Bank Management System"<<endl;
		cout<<"\t\t\tMain Menu"<<endl;
		cout<<"\t\t1. Create New Account"<<endl;
		cout<<"\t\t2. Show All Account"<<endl;
		cout<<"\t\t3. Search Account"<<endl;
		cout<<"\t\t4. Deposit Money"<<endl;
		cout<<"\t\t5. Withdraw Money"<<endl;
		cout<<"\t\t6. Exit"<<endl;
		cout<<"\t\t-------------------------------"<<endl;
		cout<<"\t\tEnter Your Choice :";
		cin>>choice;
		switch(choice){
			case 1:{
				string name;
				int accountNum;
				double balance;
				cout<<"\t\tEnter Name :";
				cin>>name;
				cout<<"\t\tEnter Account Number :";
				cin>>accountNum;
				cout<<"\t\tEnter Initial Balance :";
				cin>>balance;
				bank.AddAccount(name,balance,accountNum);
				cout<<"\t\tAccount Created Successfully...."<<endl;
				break;
			
			}
			case 2:{
				bank.showAllAccounts();
				break;
			
			}
			case 3:{
				int accountNum;
				cout<<"Enter Account Number :";
				cin>>accountNum;
				bank.searchAccounts(accountNum);
				break;
			}
			case 4:{
				int accountNum;
				double amount;
				cout<<"\t\tEnter Account Number to Deposit Money :";
				cin>>accountNum;
				BankAccount* account = bank.findAccount(accountNum);
				if(account !=NULL){
					cout<<"\t\tEnter Amount to Deposit :";
					cin>>amount;
					account->depositMoney(amount);
					cout<<"\t\t"<<amount<<" Deposit Successfully ...."<<endl;
				}else{
					cout<<"\t\tAcount Not Found ..."<<endl;
				}
				break;
			}
			case 5:{
				int accountNum;
				double amount;
				cout<<"\t\tEnter Account Number to Withdraw Money :";
				cin>>accountNum;
				BankAccount* account = bank.findAccount(accountNum);
				if(account !=NULL){
					cout<<"\t\tEnter Amount to withdraw :";
					cin>>amount;
					account->withDraw(amount);
					
				}else{
					cout<<"\t\tAcount Not Found ..."<<endl;
				}
				break;
			
			}
			case 6:{
				exit(1);
				break;
			}
	}
	cout<<"\t\tDo You Want to Countinue or Exit [Yes/No] ??";
	cin>>op;
		
	}while(op == 'y'||op =='Y');
	
}
