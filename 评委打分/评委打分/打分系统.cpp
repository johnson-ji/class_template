#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;

/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
1. 创建五名选手，放到vector中
2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3. sort算法对deque容器中分数排序，去除最高和最低分
4. deque容器遍历一遍，累加总分
5. 获取平均分
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
		//将评委的分数，放入deque容器中
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//输出选手总分
		cout <<"选手" <<it->m_name<< "分数为： " << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;


		//排序
		sort(d.begin(), d.end());

		//去掉最低分和最高分
		d.pop_back();
		d.pop_front();

		//取平均值
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;//累加分数
		}

		int avg = sum / d.size();

		//将平均分赋值给选手
		it->m_score = avg;
		
		
	}
}

void showscore(vector<player>& p)
{
	for (vector<player>::iterator it = p.begin(); it != p.end(); it++)
	{
		cout << "去掉一个最低分，去掉一个最高分，选手" << it->m_name << "的最终得分得分是：" << it->m_score << endl;
	}
}


int main1()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//创建5名选手
	vector<player> p;
	creatplayer(p);

	//测试是否创建成功
	//for (vector<player>::iterator it = p.begin(); it != p.end(); it++)
	//{
	//	cout << "name: " << (*it).m_name << " score: " << (*it).m_score << endl;
	//}
	
	//给五个选手打分
	setscore(p);

	//输出最后的分数
	showscore(p);

	system("pause");
	return 0;

}



