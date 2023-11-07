#pragma once

#include "commonHeader.h"

using namespace std;

namespace linear_table 
{
   /*
   * 1�����Ա���Է�Ϊ ���������
   * 2������-��Ϊ�������� ˫������ ѭ������
   *    ����ѭ��������ص��ǣ�����β����Ԫ��ָ��ͷԪ�أ����������ȱ����ֻ�д�ͷ����
   *    ����ȷ���ҵ�ĳ��Ԫ�أ�ѭ���Ļ��Ϳ���������һ��λ�ý��б���
   *    ���������пյķ����� L.next == NULL ����ѭ�� L.next = L (�Լ�ָ���Լ�)
   *    ˫��ѭ������������ ͷ��ָ��β�� L.prev = L.next = L
   */

	/*
	 ���Կ���ƶ�������ָ��
	 move: a���Ϸ��Ŀ��λ
	 onto: b���Ϸ��Ŀ��λ
	 ��������:��a��a�Ϸ��Ŀ��ƶ���b���Ϸ�
	
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
		* ����x��Ӧ������p �� �߶� h
		*/
		void find_pos(int x, int& p, int& h);
		
		//��p��Ѹ߶ȴ���h�Ŀ��λ
		void goback(int p, int h);

		//��p��߶ȴ��ڵ���h�Ŀ飬�ƶ���q����
		void move_all(int p, int h, int q);

		//��ӡ
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
			//��Ϊ�Ǹ����� ����ʹ��delet[] ����ƥ���ͷ�
			delete[] block;
		}

	private:
		vector<int> * block;
		int n;     //��λ������
	};

	void Block::find_pos(int x, int& p, int& h)
	{
		//ѭ������ÿ��Ԫ��
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
		//������ ���ô�С
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

			//��ʾ���ǷǷ���ָ��
			if (ap == bp)
				continue;

			if ("move" == s1) //a ��λ
				block.goback(ap, ah);

			if ("onto" == s2)
				block.goback(bp, bh);//b ��λ

			//�����ǹ�������
			block.move_all(ap, ah, bp);
		}

		block.print();
		cout << "block over....." << endl;
	}

	/*
	  [ �൱�ص����� ]�൱�ڻص���β��
	  �������λ�� list �ȽϺ��ʵ�ѡ��
	*/
	void test_format_text(string s)
	{   
		list<char> text;
		//ָ�����list�ĵ�����
		list<char>::iterator lit = text.begin();
		for (auto slt = s.cbegin(); slt != s.cend(); ++slt)
		{
			char tmp = *slt;
			if ('[' != tmp && ']' != tmp)
			{
				//�������ַ�  һ��Ҫ��litȥ����
				//���ص��ǲ����ֵ�ĵ�����
				lit = text.insert(lit, tmp);
				lit++;
			}
			else if ('[' == tmp)
			{
				//�ܵ�����
				lit = text.begin();
			}
			else if(']' == tmp) {
				//�ܵ���β
				lit = text.end();
			}
		}

		//��list<char> ת��Ϊstring
		string resultStr(text.cbegin(), text.cend());
		cout << "end the text" << endl <<  resultStr << endl;
	}

	//��̬˫������
	class StaticDoubleLink 
	{
	public:
		//��ʼ�����������
		StaticDoubleLink(size_t n_param):count_(n_param)
		{
			//��ʼ��������С
			data_ = make_shared<vector<int>>();
			left_ = make_shared<vector<int>>();
			right_ = make_shared<vector<int>>();
			data_->reserve(count_ + 1);
			left_->reserve(count_ + 1);
			right_->reserve(count_ + 1);

			//�������ݺ�ǰ�����ڵ��ʼ��
			for (int i = 0; i <= count_; ++i)
			{
				//��ʼ��ԭʼ����
				data_->push_back(i);
				//�����ڵ��ʼ��
				count_ != i ? right_->push_back(i+1) : right_->push_back(0);
				//ǰ���ڵ��ʼ��
				0 == i ? left_->push_back(count_) : left_->push_back(i-1);
		    }
		
		 }

		//��ӡ
		void print();

		//����������
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
		shared_ptr<vector<int>> data_; ////data ����
		shared_ptr<vector<int>> left_; //ǰ���ڵ�
		shared_ptr<vector<int>> right_;//��ȥ�ڵ�
		size_t count_;//����Ԫ������
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

			//��δ�ӡ?
			for (int i = 0; i < count_; ++i)
			{
				//�õ���������
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
		//�Ƿ�ת
		bool flag = false;
		//n �ǳ�ʼ�����ݴ�С  m������ָ�������
		size_t n, m;
		try
		{
			while (cin >> n >> m)
			{
				flag = false;
				StaticDoubleLink link(n);
				int action_seq;//ָ�����
				//��Ҫ������ x �� y ������ͬʱҲ������
				int x, y;
				for (int i = 0; i < m; ++i)
				{
					cin >> action_seq >> x >> y;
					if (4 == action_seq)
						flag = true;
					else
					{
						//// == 3 �ǽ���ָ��   ���� x y�������� ��ôֱ�ӽ���
						//if (action_seq == 3 && link.getRight()->at(y) == x)
						//	swap(x, y);

						//���������ת�ı�־����ô��Ӧ��ָ����Ҫ��һ�η�ת�仯
						// 1 =��2 2=��1
						if (action_seq != 3 && flag)
							action_seq = 3 - action_seq;

						//a == 1 x ���� y����� a == 2 x����y���Ҳ�
						if (action_seq == 1 && link.getLeft()->at(y) == x)
							continue;
						if (action_seq == 2 && link.getRight()->at(x) == y)
							continue;

						
						int x_l = link.getLeft()->at(x);
						int x_r = link.getRight()->at(x);
						int y_l = link.getLeft()->at(y);
						int y_r = link.getRight()->at(y);

						//2 ���뵽 4�����
						if (action_seq == 1)
						{
							//ɾ��x
							link.link(x_l, x_r);
							link.link(y_l, x);
							link.link(x, y);
						}
						else if (action_seq == 2)
						{
							// 2 ���뵽 4���Ҳ�
							//ɾ��x
							link.link(x_l, x_r);
							link.link(y, x);
							link.link(x, y_r);
						}
						else if (action_seq == 3)
						{
							//��Ϊx y����
							if (link.getRight()->at(x) == y || link.getRight()->at(y) == x)
							{
								link.link(x_l, y);
								link.link(y, x);
								link.link(x, y_r);
							}
							else
							{//x �� y ������
								link.link(x_l, y);
								link.link(y, x_r);
								link.link(y_l, x);
								link.link(x, y_r);

							}
						}

					}
				}
				//�������  �������
				int t = 0;
				long long sum = 0;

				//��������ĺ�
				for (int i = 1; i <= n; i++)
				{
					t = link.getRight()->at(t);
					if (i % 2 == 1) sum += t;

				}
				//��ת ������ż��  ��ô���վ����ܺͼ�ȥ ������
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