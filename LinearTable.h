#pragma once

#include "commonHeader.h"

using namespace std;

namespace linear_table 
{
   /*
   * 1、线性表可以分为 数组和链表
   * 2、链表-分为单向链表 双向链表 循环链条
   *    单向循环链表的特点是，链表尾部的元素指向头元素，单向链表的缺点是只有从头遍历
   *    才能确定找到某个元素，循环的话就可以在任意一个位置进行遍历
   *    单向链表判空的方法是 L.next == NULL 单向循环 L.next = L (自己指向自己)
   *    双向循环链表是增加 头部指向尾部 L.prev = L.next = L
   */

	/*
	 测试块的移动，三个指令
	 move: a块上方的块归位
	 onto: b块上方的块归位
	 公共操作:将a和a上方的块移动到b的上发
	
	*/
	class Block
	{
	public:
		Block(int n_param):block(NULL),n(n_param)
		{   
			block = new vector<int>[30];

			for (int i = 0; i < n; ++i)
			{
				block[i].push_back(i);
			}

		}

		/*
		* 查找x对应的索引p 和 高度 h
		*/
		void find_pos(int x, int& p, int& h);
		
		//将p块堆高度大于h的块归位
		void goback(int p, int h);

		//将p块高度大于等于h的块，移动到q堆上
		void move_all(int p, int h, int q);

		//打印
		void print()
		{
			for (int i = 0; i < n; ++i)
			{
				//
				cout << i << ": ";
				for (int j = 0; j < block[i].size(); ++j)
					cout << block[i][j] << " ";
				cout << endl;
			}
		}


		~Block() {
			//因为是个数组 必须使用delet[] 进行匹配释放
			delete[] block;
		}

	private:
		vector<int> * block;
		int n;     //槽位的数量
	};

	void Block::find_pos(int x, int& p, int& h)
	{
		//循环数组每个元素
		for (int i = 0; i < n; ++i)
		{
			for (int k = 0; k < block[i].size(); ++k)
			{
				if (x == block[i][k])
				{
					p = i;
					h = k;
				}
			}
		}
	}

	void Block :: goback(int p, int h)
	{
		for (int i = h + 1; i < block[p].size(); ++i)
		{
			int k = block[p][i];
			block[k].push_back(k);
		}

		block[p].resize(h + 1);
	}

	void Block::move_all(int p, int h, int q)
	{
		for (int i = h; i < block[p].size(); ++i)
		{
			block[q].push_back(block[p][i]);
		}
		//别忘了 重置大小
		block[p].resize(h);
	}
	
	void test_block_move()
	{
		//
		int n;
		cin >> n;
		Block block(n);

		int a, b;
		string s1, s2;
		while (cin >> s1)
		{
			if ("quit" == s1)
				break;
			cin >> a >> s2 >> b;
			int ap = 0, ah = 0, bp = 0, bh = 0;
			block.find_pos(a, ap, ah);
			block.find_pos(b, bp, bh);

			//表示这是非法的指令
			if (ap == bp)
				continue;

			if ("move" == s1) //a 归位
				block.goback(ap, ah);

			if ("onto" == s2)
				block.goback(bp, bh);//b 归位

			//以下是公共操作
			block.move_all(ap, ah, bp);
		}

		block.print();
		cout << "block over....." << endl;
	}

	/*
	  [ 相当回到行首 ]相当于回到行尾部
	  灵活跳动位置 list 比较合适的选择
	*/
	void test_format_text(string s)
	{   
		list<char> text;
		//指定这个list的迭代器
		list<char>::iterator lit = text.begin();
		for (auto slt = s.cbegin(); slt != s.cend(); ++slt)
		{
			char tmp = *slt;
			if ('[' != tmp && ']' != tmp)
			{
				//正常的字符  一定要用lit去接受
				//返回的是插入的值的迭代器
				lit = text.insert(lit, tmp);
				lit++;
			}
			else if ('[' == tmp)
			{
				//跑到行首
				lit = text.begin();
			}
			else if(']' == tmp) {
				//跑到行尾
				lit = text.end();
			}
		}

		//将list<char> 转换为string
		string resultStr(text.cbegin(), text.cend());
		cout << "end the text" << endl <<  resultStr << endl;
	}

	//静态双向链表
	class StaticDoubleLink 
	{
	public:
		//初始化链表的容量
		StaticDoubleLink(size_t n_param):count_(n_param)
		{
			//初始化容器大小
			data_ = make_shared<vector<int>>();
			left_ = make_shared<vector<int>>();
			right_ = make_shared<vector<int>>();
			data_->reserve(count_ + 1);
			left_->reserve(count_ + 1);
			right_->reserve(count_ + 1);

			//数组内容和前后驱节点初始化
			for (int i = 0; i <= count_; ++i)
			{
				//初始化原始数据
				data_->push_back(i);
				//后驱节点初始化
				count_ != i ? right_->push_back(i+1) : right_->push_back(0);
				//前驱节点初始化
				0 == i ? left_->push_back(count_) : left_->push_back(i-1);
		    }
		
		 }

		//打印
		void print();

		//连接两个点
		void link(int L, int R)
		{
			right_->at(L) = R;
			left_->at(R) = L;
		}

		shared_ptr<vector<int>> getData()
		{
			return data_;
		}

		shared_ptr<vector<int>> getLeft()
		{
			return left_;
		}

		shared_ptr<vector<int>> getRight()
		{
			return right_;
		}

		

		~StaticDoubleLink()
		{
		}
	private:
		shared_ptr<vector<int>> data_; ////data 数组
		shared_ptr<vector<int>> left_; //前驱节点
		shared_ptr<vector<int>> right_;//后去节点
		size_t count_;//数组元素数量
	};

	void printVector(vector<int>::iterator begin, vector<int>::iterator end)

	{
		for (auto it = begin; it != end; ++it)
			cout << *it << " ";

		cout << endl;

	}
	

	void StaticDoubleLink::print()
	{
		try
		{
			printVector(data_->begin(), data_->end());
			printVector(left_->begin(), left_->end());
			printVector(right_->begin(), right_->end());

			//如何打印?
			for (int i = 0; i < count_; ++i)
			{
				//得到数组索引
				int index = right_->at(i);
				cout << data_->at(index) << " ";
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
	}

	void test_static_double_link()
	{
		//是否反转
		bool flag = false;
		//n 是初始化数据大小  m是输入指令的条数
		size_t n, m;
		try
		{
			while (cin >> n >> m)
			{
				flag = false;
				StaticDoubleLink link(n);
				int action_seq;//指令序号
				//需要操作的 x 和 y 是数据同时也是索引
				int x, y;
				for (int i = 0; i < m; ++i)
				{
					cin >> action_seq >> x >> y;
					if (4 == action_seq)
						flag = true;
					else
					{
						//// == 3 是交换指令   并且 x y是相连的 那么直接交换
						//if (action_seq == 3 && link.getRight()->at(y) == x)
						//	swap(x, y);

						//如果遇到翻转的标志，那么对应的指令需要做一次翻转变化
						// 1 =》2 2=》1
						if (action_seq != 3 && flag)
							action_seq = 3 - action_seq;

						//a == 1 x 插入 y的左侧 a == 2 x插入y的右侧
						if (action_seq == 1 && link.getLeft()->at(y) == x)
							continue;
						if (action_seq == 2 && link.getRight()->at(x) == y)
							continue;

						
						int x_l = link.getLeft()->at(x);
						int x_r = link.getRight()->at(x);
						int y_l = link.getLeft()->at(y);
						int y_r = link.getRight()->at(y);

						//2 插入到 4的左侧
						if (action_seq == 1)
						{
							//删除x
							link.link(x_l, x_r);
							link.link(y_l, x);
							link.link(x, y);
						}
						else if (action_seq == 2)
						{
							// 2 插入到 4的右侧
							//删除x
							link.link(x_l, x_r);
							link.link(y, x);
							link.link(x, y_r);
						}
						else if (action_seq == 3)
						{
							//分为x y相邻
							if (link.getRight()->at(x) == y || link.getRight()->at(y) == x)
							{
								link.link(x_l, y);
								link.link(y, x);
								link.link(x, y_r);
							}
							else
							{//x 和 y 不相邻
								link.link(x_l, y);
								link.link(y, x_r);
								link.link(y_l, x);
								link.link(x, y_r);

							}
						}

					}
				}
				//排序完成  进行输出
				int t = 0;
				long long sum = 0;

				//求出奇数的和
				for (int i = 1; i <= n; i++)
				{
					t = link.getRight()->at(t);
					if (i % 2 == 1) sum += t;

				}
				//翻转 并且是偶数  那么最终就是总和减去 奇数和
				if (flag && n % 2 == 0)
					sum = (long long)n *(n + 1) / 2 - sum;

				cout << "final sum is " << sum << endl;
			}
		}
		catch (const std::exception& e)
		{
			cout << e.what() << endl;
		}
		

	}
	
	
}