#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;

/*
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
1. ��������ѡ�֣��ŵ�vector��
2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
3. sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
4. deque��������һ�飬�ۼ��ܷ�
5. ��ȡƽ����
*/

class player
{
public:
	player(string name, int score)
	{
		m_name = name;
		m_score = score;
	}


	int m_score;
	string m_name;

};

void creatplayer(vector<player> &p)
{
	string nameseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "player";
		name += nameseed[i];

		int score = 0;
		player pn(name, score);

		p.push_back(pn);
	}
}

void setscore(vector<player>& p)
{
	for (vector<player>::iterator it = p.begin(); it != p.end(); it++)
	{
		//����ί�ķ���������deque������
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//���ѡ���ܷ�
		cout <<"ѡ��" <<it->m_name<< "����Ϊ�� " << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;


		//����
		sort(d.begin(), d.end());

		//ȥ����ͷֺ���߷�
		d.pop_back();
		d.pop_front();

		//ȡƽ��ֵ
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;//�ۼӷ���
		}

		int avg = sum / d.size();

		//��ƽ���ָ�ֵ��ѡ��
		it->m_score = avg;
		
		
	}
}

void showscore(vector<player>& p)
{
	for (vector<player>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "ȥ��һ����ͷ֣�ȥ��һ����߷֣�ѡ��" << it->m_name << "�����յ÷ֵ÷��ǣ�" << it->m_score << endl;
	}
}


int main1()
{
	//���������
	srand((unsigned int)time(NULL));

	//����5��ѡ��
	vector<player> p;
	creatplayer(p);

	//�����Ƿ񴴽��ɹ�
	//for (vector<player>::iterator it = p.begin(); it != p.end(); it++)
	//{
	//	cout << "name: " << (*it).m_name << " score: " << (*it).m_score << endl;
	//}
	
	//�����ѡ�ִ��
	setscore(p);

	//������ķ���
	showscore(p);

	system("pause");
	return 0;

}



