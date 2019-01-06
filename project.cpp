#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
int w = 0;
using namespace std;


class employee;
employee creat(employee *);
void deletei(employee *);
int find(employee *);
void correct(employee *);
void count(employee *);
void sort(employee *);
void menu(employee *);

class employee
{
	protected:
		char name[20];
		char id[20];
		char num[20];
		char depart[20];
	public:
		void set_name()
		{
			cout << "姓名：";
			cin >> name; 
		}
		void set_id()
		{
			cout << "ID:";
			cin >> id;
		}
		void set_num()
		{
			cout << "联系方式：";
			cin >> num;
		}
		void set_depart()
		{
			cout << "部门：";
			cin >> depart;
		}
		char *get_name()
		{
			return name;
		}
		char *get_id()
		{
			return id;
		}
		char *get_num()
		{
			return num;
		}
		char *get_depart()
		{
			return depart;
		}
		void display()
		{
			cout << "姓名：" << name << endl;
			cout << "ID:" << id << endl;
			cout << "联系方式：" << num << endl;
			cout << "部门：" << depart << endl;
		}
		employee& operator = (const employee& other)
		{
			strcpy(name,other.name);
			strcpy(id,other.id);
			strcpy(num,other.num);
			strcpy(depart,other.depart);
			return *this;
		}
};

employee creat(employee *e)
{
	cout << "请输入添加的信息：" << endl;
	e[w].set_name();
	e[w].set_id();
	e[w].set_num();
	e[w].set_depart();
	w++;
	return e[w];
}

void deletei(employee *e)
{
	int i = find(e);
	for(int j=i;j<(w-1);j++)
	{
		e[j] = e[j+1];
	}
	w--;
	cout << "删除成功！";
}
int find(employee *e)
{
	char a[20];
	int i;
	cout << "输入ID：";
	cin >> a;
	for(i=0;i<w;i++)
	{
		if(strcmp(e[i].get_id() ,a) == 0)
		{
			return i;
		}
	}

}
void correct(employee *e)
{
	int i = find(e);
	e[i].set_name() ;
	e[i].set_id() ;
	e[i].set_depart() ;
	e[i].set_num();
}
void count(employee *e)
{
	char m[20];
	int n = 0;
	cout << "请输入部门：";
	cin >> m;
	for(int i=0;i<w;i++)
	{
		if(strcmp(e[i].get_depart(),m) == 0)
		{
			n++;
		}
	}
	cout << "总人数：" << n;
}
void sort(employee *e)
{
	for(int i=1;i<w;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(strcmp(e[i].get_id(),e[j].get_id())>0)
			{
				employee t = e[j];
				e[j] = e[j-1];
				e[j-1] = t;
			}
		}
	}
	for(int i=0;i<w;i++)
		e[i].display();
}
void menu(employee *e)
{
	int i;
	cout << "1、创建信息" << endl; 
	cout << "2、删除信息" << endl;
	cout << "3、修改信息" << endl;
	cout << "4、查询信息" << endl;
	cout << "5、排序信息" << endl;
	cout << "6、统计信息" << endl;
	cout << "7、关闭" << endl;

	while(1)
	{
	cout << "请选择功能：";
	cin >> i;		
		if(i == 1)
		{
			cout << "请输入ID进行查重" << endl;
			cout << "若无此人将进行添加" << endl;
			cout << endl;
			if(find(e) == 1)
				cout << "已有该人员信息" << endl;
			else 
				e[w] = creat(e);
			cout << endl; 
		}
		else if(i == 2)
		{
			cout << "请输入ID进行查重" << endl;
			if(find(e) != 1)
				cout << "不存在此人" << endl;
			else 
				{
				cout << "请输入要删除的ID" << endl;
				deletei(e);
				}
			cout << endl;
		}
		else if(i == 3)
		{
			cout << "请输入ID进行查重"<< endl;
			if(find(e) != 1)
				cout << "不存在此人" << endl;
			else 
				correct(e);
			cout << endl;
		}
		else if(i == 4)
		{
			int a =0;
			cout << "请输入ID进行查重："<< endl;
			a = find(e);
			if(a == 1)
				e[a].display();
			else 
				cout << "不存在此人！" << endl;
			
			cout << endl;
		}
		else if(i == 5)
		{
		
			count(e);
			cout << endl;
		}
		else if(i == 6)
		{
			sort(e);
			cout << endl;			
		}
		else if(i == 7)
			break;
	}
}
int main()
{
	employee b[100];
	fstream file("company.txt",ios::out);
	if(!file)
	{
		cout << "Error!" << endl;
		exit(0);
	}
	menu(b);
	for(int i=0;i<w;i++)
	{
		file << b[i].get_name();
		file << b[i].get_id() ;
		file << b[i].get_num() ;
		file << b[i].get_depart();
	}
	file.close();
	return 0;
}
