#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class my_arr
{
public:
	my_arr(int len)//�вι��캯��
	{
		cout << "�вι������" << endl;
		this->m_len = len;
		this->m_size = 0;
		this->arr_address = new T[this->m_len];
	}

	my_arr(const my_arr& arr)//�������캯��
	{
		cout << "�����������" << endl;
		this->m_len = arr.m_len;
		this->m_size = arr.m_size;

		//��������ռ�
		this->arr_address = new T[m_len + 8];

		//���������
		for (int i = 0; i < this->m_size; i++)
		{
			this->arr_address[i] = arr.arr_address[i];
		}
	}

	my_arr& operator=(const my_arr& arr)
	{
		//���ж�ԭ�������Ƿ������ݣ�����У����ͷ�
		if (this->arr_address != NULL)
		{
			delete[] this->arr_address;
			this->arr_address = NULL;
			this->m_len = 0;
			this->m_size = 0;
		}

		this->m_len = arr.m_len;
		this->m_size = arr.m_size;

		//��������ռ�
		this->arr_address = new T[m_len + 8];

		//���������
		for (int i = 0; i < this->m_size; i++)
		{
			this->arr_address[i] = arr.arr_address[i];
		}

		return *this;
	}

	//β�巨
	void push_back(const T& val)
	{
		//���ж������Ƿ���ڴ�С.
		if (this->m_len == this->m_size)
		{
			return;
		}

		this->arr_address[this->m_size] = val;
		m_size++;//renew it 
	}

	//βɾ��
	void pop_back()
	{
		//���û����ʲ������һ��Ԫ�أ������߼���βɾ���ռ���Ȼ���ڣ�
		if (this->m_size == 0)
		{
			return;
		}

		this->m_size--;
	}

	//reload []���û���ͨ��[]������������
	T& operator[](int index)
	{
		return this->arr_address[index];
	}

	//������������
	int get_len()
	{
		return this->m_len;
	}

	//���������С
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
	int m_len;//�б��������
	int m_size;//ʵ�ʴ�С
};