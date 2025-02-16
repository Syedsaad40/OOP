#include<iostream>
using namespace std;
class Invoice{
	string number;
	string description;
	int quantity;
	double price_per_item;
	public:
		Invoice(string num,string desc,int quan,double price):number(num),description(desc),quantity(quan),price_per_item(price){}
		double getInvoiceAmount(){
			if(quantity<0||price_per_item<0){
				quantity=0;
				price_per_item=0;
			}
			
			return quantity*price_per_item;
		}
};
int main(){
	Invoice i("111110","this is a beautiful item",10,5.75);
	cout<<"The invoice amount per month is:"<<i.getInvoiceAmount()<<endl;
	return 0;
}