/*
	*类&&对象
	*struct
*/
#include<iostream>
#include<string>
using namespace std;
class student
{
	public:
		string name;
		void setgrade();//定义与实现分离，利与开发
		void showgrade();
	private:
		int grade;
};
void student::setgrade()  //作用域限定符
{
	cout<<"input name"<<endl;
	cin>>name;
	cout<<"input grade"<<endl;
	cin>>grade;
}
void student::showgrade()
{
	cout<<name<<"'s grade: "<<grade<<endl;
}

/*std class*/
/***************************************************************/
/*struct class*/
struct teacher
{
        public:
                string name;
                void setgrade();
                void showgrade();
        private:
                int grade;

};

int main()
{
//	string name="noclass";
	student a;
	a.setgrade();
	a.showgrade();
//	cout<<name<<endl;
//	cout<<a.name<<endl;
}
