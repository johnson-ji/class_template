#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class my_arr
{
public:
	my_arr(int len)//有参构造函数
	{
		cout << "有参构造调用" << endl;
		this->m_len = len;
		this->m_size = 0;
		this->arr_address = new T[this->m_len];
	}

	my_arr(const my_arr& arr)//拷贝构造函数
	{
		cout << "拷贝构造调用" << endl;
		this->m_len = arr.m_len;
		this->m_size = arr.m_size;

		//深拷贝创建空间
		this->arr_address = new T[m_len + 8];

		//深拷贝，拷贝
		for (int i = 0; i < this->m_size; i++)
		{
			this->arr_address[i] = arr.arr_address[i];
		}
	}

	my_arr& operator=(const my_arr& arr)
	{
		//先判断原来堆区是否有数据，如果有，先释放
		if (this->arr_address != NULL)
		{
			delete[] this->arr_address;
			this->arr_address = NULL;
			this->m_len = 0;
			this->m_size = 0;
		}

		this->m_len = arr.m_len;
		this->m_size = arr.m_size;

		//深拷贝创建空间
		this->arr_address = new T[m_len + 8];

		//深拷贝，拷贝
		for (int i = 0; i < this->m_size; i++)
		{
			this->arr_address[i] = arr.arr_address[i];
		}

		return *this;
	}

	//尾插法
	void push_back(const T& val)
	{
		//先判断容量是否等于大小.
		if (this->m_len == this->m_size)
		{
			return;
		}

		this->arr_address[this->m_size] = val;
		m_size++;//renew it 
	}

	//尾删法
	void pop_back()
	{
		//让用户访问不到最后一个元素，即在逻辑上尾删（空间仍然存在）
		if (this->m_size == 0)
		{
			return;
		}

		this->m_size--;
	}

	//reload []，用户可通过[]访问数组数据
	T& operator[](int index)
	{
		return this->arr_address[index];
	}

	//返回数组容量
	int get_len()
	{
		return this->m_len;
	}

	//返回数组大小
	int get_size()
	{
		return this->m_size;
	}

	~my_arr()
	{
		if (this->arr_address != NULL)
		{
			delete[] arr_address;
			this->arr_address = NULL;
			this->m_len = 0;
			this->m_size = 0;
		}
	}

private://The properties used to control the array are placed in privacy
	T* arr_address;//array 
	int m_len;//列表可用容量
	int m_size;//实际大小
};