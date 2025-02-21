#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Car{
	string name;
	int car_id;
	public:
		Car(string n,int id):name(n),car_id(id){
			cout<<"Car constructed"<<endl;
		}
		string get_name(){
			return name;
		}
		int get_car_id(){
			return car_id;
		}
		~Car(){
			cout<<"Car destructed"<<endl;
		}
};
class Garage{
	vector<Car*>cars;
	public:
		Garage(){
			cout<<"Garage constructed"<<endl;
		}
		void parkCar(Car* car){
			cars.push_back(car);
		}
		void listCars(){
			for(Car* car:cars){
				cout<<car->get_name()<<endl;
			}
		}
		~Garage(){
			cout<<"Garage destructed"<<endl;
		}
};
int main(){
	Car c1("Bugatti",1001);
	Car c2("Elantra",1001);
	Garage g;
	g.parkCar(&c1);
	g.parkCar(&c2);
	g.listCars();
	return 0;
}