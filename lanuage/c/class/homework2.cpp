#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class library;
class book
{
private:
	string id, name, author, pub;
private:
	friend class library;
	friend bool cmp(const book &a, const  book &b);
};
bool cmp(const book &a,const book &b)
{
	return a.name < b.name;
}
class library
{
public:
	void addbook();
	void listbook();
	void query();
	library(string);
	~library();
private:
	vector<book> cap;
	string name;
};

int main()
{
	library a("library_a_data");
	void show(string page);
	show("start");
	string com;
	int k;
	while (1)
	{
		cin >> com;
		if (com == "addbook")	k = 1;
		else if (com == "listbook")	k = 2;
		else if (com == "query")	k = 3;
		else if (com == "exit")	k = 4;
		else k = 5;
		switch (k)
		{
		case 1:a.addbook();	break;
		case 2:a.listbook();	break;
		case 3:a.query();	break;
		case 4: break;
		case 5:show("error");
		}
		if (k == 4) { show("end");	break; }
	}
    return 0;
}
void show(string page)
{
	system("clear");
	if (page == "start")
	{
		cout << "Copyright:2016060107001 Î¤ËÃÇ§ @2017/6/4" << endl;
		cout << "library data storage in library_*_data" << endl;
		cout << "offer the function addbook¡¢listbook ans query" << endl;
		cout << "you can just type the function's name to use it" << endl;
		cout << "have a good day!" << endl;
	}
	else if (page == "end")
	{
		cout << "Thanks for use" << endl;
		cout << "Good bye!" << endl;
	}
	else if(page == "error")
	{
		cout << "Input not right" << endl;
		cout << "enter the function's name just like addbook etc." << endl;
	}
}
library::library(string s)
{
	fstream f;
	f.open(s, ios::in);
	name = s;
	int n;
	book a;
	f >> n;
	while (n--)
	{
		f >> a.id >> a.name >> a.author >> a.pub;
		cap.insert(cap.end(),a);
	}
}
library::~library()
{
	fstream f;
	f.open(name, ios::out);
	f << cap.size() << endl;
	vector<book>::iterator p = cap.begin();
	while (p!= cap.end())
	{
		f << p->id << " " << p->name << " " << p->author << " " << p->pub << endl;
		p++;
	}
}
void library::listbook()
{
	vector<book>::iterator p = cap.begin();
	sort(cap.begin(), cap.end(), cmp);
	while (p!= cap.end())
	{
		cout << p->id << " " << p->name << " " << p->author << " " << p->pub << endl;
		p++;
	}
}
void library::addbook()
{
	book a;
	cout << "Input the book's id-name-author-publish_Data:" << endl;
	cin >> a.id >> a.name >> a.author >> a.pub;
	cap.insert(cap.end(), a);
}
void library::query()
{
	cout << "Enter the query name:" << endl;
	vector<book>::iterator q = cap.begin();
	string s;
	cin >> s;
	bool have=false;
	while (q!= cap.end())
	{
		if (q->name.find(s) != string::npos)
		{
			cout << q->id << " " << q->name << " " << q->author << " " << q->pub << endl;
			have=true;
		}
		q++;
	}
	if (!have)	cout << "Not found" << endl;
}