#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Logger{
	private:
		vector<string>info;
		public:
			void loginfo(){
				info.push_back("INFO");
			}
			void logwarning(){
				info.push_back("WARN");
			}
			void logError(){
				info.push_back("Error");
			}
};
int main(){
	
}
