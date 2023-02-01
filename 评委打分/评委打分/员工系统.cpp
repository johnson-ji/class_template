#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

# define CEHUA 0
# define MEISHU 1
# define YANFA 2

/*
* 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
* 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
* 随机给10名员工分配部门和工资
* 通过multimap进行信息的插入  key(部门编号) value(员工)
* 分部门显示员工信息
*/

class employee
{
public:
	string m_name;
	int m_salary;
};

void set_v(vector<employee>& v)
{
	for (int i = 0; i < 10; i++)
	{
		string nameseed = "ABCDEFGHIJ";
		employee worker;
		worker.m_name = "employee ";
		worker.m_name = +nameseed[i];

		worker.m_salary = rand() % 10000 + 10000;

		int dep = rand() % 3;
		v.push_back(worker);
	}
}

void set_dep(vector<employee>& v, multimap<int, employee>& m)
{
	for (vector<employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		int dep = rand() % 3;
		m.insert(make_pair(dep, *it));
	}
}

void show_worker(multimap<int, employee>& m)
{

	cout << "策划部门：" << endl;
	map<int, employee>::iterator ret = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; ret != m.end() && index < count; index++, ret++)
	{
		cout << "name: " << (*ret).second.m_name << " salary: " << (*ret).second.m_salary << endl;
	}

	cout << "============================" << endl;
	cout << "美术部门：" << endl;
	ret = m.find(MEISHU);
	count = m.count(MEISHU);
	index = 0;
	for (; ret != m.end() && index < count; index++, ret++)
	{
		cout << "name: " << (*ret).second.m_name << " salary: " << (*ret).second.m_salary << endl;
	}

	cout << "============================" << endl;
	cout << "研发部门：" << endl;
	ret = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; ret != m.end() && index < count; index++, ret++)
	{
		cout << "name: " << (*ret).second.m_name << " salary: " << (*ret).second.m_salary << endl;
	}
}

int main()
{
	//put the employee into vector.
	vector <employee> v_emp;
	set_v(v_emp);

	//test.
	//for (vector<employee>::iterator it = v_emp.begin(); it != v_emp.end(); it++)
	//{
	//	cout << "name: " << (*it).m_name << " salary: " << (*it).m_salary << endl;
	//}

	//set department.
	multimap<int, employee> company;
	set_dep(v_emp,company);

	//show workers.
	show_worker(company);

	system("pause");
	return 0;

}



