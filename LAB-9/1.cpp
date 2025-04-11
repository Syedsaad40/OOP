#include<iostream>
#include<string>
using namespace std;
class Wallet{
	private:
		double balance;
		int limit;
		public:
			Wallet(double a,int b):balance(a),limit(b){}
			void spend(double a ){
				if(balance<=0||a>limit){
					cout<<"Insufficient balance cannot spend.."<<endl;
				}
				else{
					balance -=a;
					cout<<"Amount withdrawn new balance is :"<<balance<<endl;
				}
			}
			void deposit(double b){
			balance += b;
			cout<<"Amount deposited new balance is:"<<balance<<endl;
			if(balance>limit){
				cout<<"Balance is now exceeding the limit"<<endl;
			}
			}
			void set_maxlimit(int limit){
				this->limit = limit;
			}
			int get_limit(){
				return limit;
			}
			double get_balance(){
				return balance;
			}
};
class user{
	private:
	int userID;
	string name;
	Walllet wallet;
		public:
			User(int a,string b):userID(a),name(b){}
			void deposit(double a){
				wallet.deposit(a);
			}
			void withdaw(double b){
				wallet.withdraw(b)
			}
			void set_limit(int a){
				wallet.set_maxlimit(a);
			}
};
int main(){
	return 0;
}
