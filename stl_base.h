
#include "commonHeader.h"

using namespace std;

namespace zyz
{
	
	namespace vector_test {
		using namespace std;
		void getAns()
		{
			//all ->所有过境人员 amPersons->m 国间谍 d->双重身份 dns ->最终的间谍
			vector<string> allPerson, amPersons, doublePersons, ansPersons;

			int all, am, dol;
			string s;
			while (cin >> all >> am >> dol)
			{
				allPerson.clear();
				amPersons.clear();
				ansPersons.clear();
				//分别根据 all am dol 来初始化三个vector
				cout << "allperson input" << endl;
				for (int i = 0; i < all; i++)
				{
					cin >> s;
					allPerson.push_back(s);
				}

				cout << "amPersons input" << endl;
				for (int i = 0; i < am; i++)
				{
					cin >> s;
					amPersons.push_back(s);
				}

				cout << "doublePersons input" << endl;
				for (int i = 0; i < dol; i++)
				{
					cin >> s;
					doublePersons.push_back(s);
				}

				//判断第二集合在第一行集合中，不在第三行的就是间谍
				for (auto it = amPersons.cbegin(); it != amPersons.end(); it++)
				{
					//在第一个集合中
					if ((find(allPerson.cbegin(), allPerson.cend(), *it) != allPerson.cend())
						&& (find(doublePersons.cbegin(), doublePersons.cend(), *it) ==
							doublePersons.cend())
						)
					{
						ansPersons.push_back(*it);
					}
				}

				//打印间谍
				if (ansPersons.empty())
				{
					cout << "No enemy spy" << endl;
				}
				else {
					for (auto it = ansPersons.cbegin(); it != ansPersons.cend(); it++)
					{
						cout << *it << " ";
					}

					cout << endl;
				}
			}

		}
	}

	namespace queu_test 
	{  
		using namespace std;

		//定义一个点位的结构体
		struct point {
			int x, y;
			int step;
		};
		//计算骑士从起点到终点移动的步数
		//初始化骑士x，y方向移动的距离
		int dx[8] = { -2,-2,-1,1,1,2,2 };
		int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };

		//
		const int maxn = 310;
		bool vis[maxn][maxn];
		//s->起点 e->终点  L棋盘的长度
		//tx ty 是骑士 中间的位置
		int sx, sy, ex, ey, tx, ty, L;

		int bfs()
		{
			//如果起点和重点相同直接返回0
			if (sx == ex && sy == ey) return 0;
			memset(vis, false, sizeof(vis));
			//定义一个队列
			queue<point> Q ;
			point start, node;
			//初始化start
			start.x = sx;
			start.y = sy;
			start.step = 0;
			Q.push(start);

			int step, x, y;
			while (!Q.empty())
			{
				//取出队列的头元素
				start = Q.front(), Q.pop();
				x = start.x;
				y = start.y;
				step = start.step;
				//扩展
				for (int i = 0; i < 8; i++)
				{
					tx = x + dx[i];
					ty = y + dy[i];
					if (tx == ex && ty == ey) return step + 1;
					if (tx >= 0 && tx < L && ty >= 0 && ty < L && !vis[tx][ty])
					{
						node.x = tx;
						node.y = ty;
						node.step = step + 1;
						Q.push(node);
						vis[tx][ty] = true;
					}

				}
			}

		}

		void test_queue()
		{
			int N;
			scanf_s("%d", &N);
			while (N--)
			{
				scanf_s("%d", &L);

				scanf_s("%d%d", &sx, &sy);

				scanf_s("%d%d", &ex, &ey);

				printf("%d\n", bfs());
			}
		}


	}

	namespace list_test 
	{
		/*
		1、list的专有API,merge(b),在合并之前两个list必须是排好顺序的,否则程序直接异常终止
		2、unique()将连续相同的元素进行压缩，如果不是连续的话是无法进行压缩的
		   所以一般先进行排序再压缩
		3、front()/back() 只是返回首部和头部的元素  pop_front/pop_back 是
		*/

		void test_list_merge() {
			list<int> list1 = { 5,1,2,3,6 };
			list<int> list2 = { 7,5,3,8 };

			//list 专用sort函数 排序效率高
			list1.sort();
			list2.sort();

			try
			{
				list1.merge(list2);
			}
			catch (const std::exception& e)
			{
				cout << e.what() << endl;
				return;
			}


			for (auto it = list1.cbegin(); it != list1.cend(); ++it)
			{
				cout << *it << " ";
			}

			cout << endl;
		}

		void test_list_unique()
		{
			list<int> list1 = { 1,2,3,3,4,3,4 };
			list1.sort();
			list1.unique();

			for (auto it = list1.cbegin(); it != list1.cend(); ++it)
			{
				cout << *it << " ";
			}

			cout << endl;
		}

		void test_soldier_count()
		{
			int T, n;
			list<int> a;
			list<int> ::iterator it;

			scanf_s("%d", &T);
			while (T--)
			{
				scanf_s("%d", &n);
				a.clear();
				int k = 2;
				for (int i = 1; i <= n; i++)
					a.push_back(i);

				while (a.size() > 3)
				{
					int cnt = 1;
					for (it = a.begin(); it != a.end();)
					{
						if (cnt++ % k == 0)
							it = a.erase(it);//注意现在这个it指向下一位的士兵的地址
						else
							it++;
					}

					k = (k == 2 ? 3 : 2);
				}

				//循环便利
				for (auto it = a.cbegin(); it != a.cend(); ++it)
				{
					cout << *it << " ";
				}

				cout << endl;
			}
		}
		

	}

	namespace deque_test 
	{
		/*
		1、deque是一个双端队列，需要两端进行操作的话，优先使用deque
		2、push_front/push_back pop_front/pop_back front/back 等操作
		*/
		void read(int& x)
		{
			char ch = getchar(); x = 0;
			//小于0 或者大于9 的数字
			for (; ch < '0' || ch > '9'; ch = getchar());
			//大于0并且小于9的数字
			for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';

		}

		const int maxn = 1000;
		int m, n;
		//d 数组 每个元素都是deque
		deque<int> d[maxn];

		void test_deque()
		{
			while (~scanf_s("%d%d", &n, &m))
			{
				for (int i = 1; i < n; i++)
					d[i].clear();
				//m 是多少行数据 1 1 1 23
				//k - 对应的操作类型 
				//u - 表示编号为u的队列 v - value w-表示对队列哪个方向操作
				int k, u, v, w;
				while (m--)
				{
					read(k);
					read(u);
					read(w);
					read(v);
					switch (k)
					{
					case 1:
						0 == w ? d[u].push_front(v) : d[u].push_back(v);
						break;
					case 2:
						if (!d[u].empty())
						{
							if (0 == w)
							{
								cout << "the front ele is " << d[u].front() << endl;
								d[u].pop_front();
							}
							else {
								cout << "the end ele is " << d[u].back() << endl;
								d[u].pop_back();
							}
						}
						else {
							cout << "-1" << endl;
						}
						
						break;
					case 3:
						if (0 == w) 
						{  
							//顺序接
							d[u].insert(d[u].end(), d[v].begin(), d[v].end());
						}
						else 
						{
						   //逆序接
							d[u].insert(d[u].end(), d[v].rbegin(), d[v].rend());
						}
						d[v].clear();
						break;
					default:
						break;
					}
				}
			}
		}
		
	}

	namespace priority_queue_test 
	{
		/*
		* 
		* priority_queue<Type, Container, Functional>  Container 必须是数组型的容器
		1、是优先级队列，优先级最高的先出队，内部的实现是堆的数据结构，不可以删除指定的元素
		2、pop出队、top取队头
		*/

		void test_priority_queue()
		{
			//优先级大的队列
			priority_queue<int> q1;
			//优先级小的堆
			priority_queue<int, vector<int>, greater<int>> q2;

			int a[1000];

			// n 等于第几轮  m 是总共多少个数字
			int n, m, x;
			scanf_s("%d%d", &m, & n);
			for (int i = 1; i <= m; i++)
				scanf_s("%d", &a[i]);
			int cnt = 1;
			for (int i = 1; i <= n; i++)
			{
				scanf_s("%d",&x);
				while (cnt <= x)
				{
					//q1不为空且a[cnt]<q1.top() 说明a[cnt]属于前i-1大的数
					if (!q1.empty() && a[cnt] < q1.top())
					{
						q2.push(q1.top());
						q1.pop();
						q1.push(a[cnt]);
					}
					else {
						q2.push(a[cnt]);
					}

					cnt++;
				}

				cout << q2.top() << endl;
				q1.push(q2.top());
				q2.pop();
			}

		}
	}

	namespace bit_set_test 
	{
		/*
		1、构造函数  记住几种初始化方式
		bitset<n> b; n个二进制位都是 0  bitset<n>(unsigned long) bitset<n>(string)
		2、一些方法
		   || ~ & | ^ >> << == !=  等一些关于二进制的运算
		   cout(统计1的个数)、any() 只要有一个为1返回true set(k) 第k位设置为1
		   reset(k) = set(k,0)
		   flip(k) 第k位取反 flip()全部取反
		   to_ulong()：返回它转换为unsigned long的结果，如果超出范围，则报错
		   to_string() 
		*/

		void test_bit_set()
		{
			try
			{   
				//1、测试to_long  一定要做long的范围里,否则抛出bitset overflow
				bitset<10000> b("11111111111111111111");
				cout << b.to_ulong() << endl;
				//2、将十进制转换为二进制
				cout << bitset<8>(16) << endl;
			}
			catch (const std::exception& e)
			{
				cout << e.what() << endl;
			}
			
		}

		void test_belong_number()
		{

			const int maxn = 100;
			//s[x] 表示元素x所属集合的二进制表示
			bitset<1010> s[maxn];

			int N, Q, num, x, y;
			scanf_s("%d", &N);

			for (int i = 1; i <= N; i++)
			{
				scanf_s("%d", &num);
				while (num--)
				{
					scanf_s("%d", &x);
					s[x][i] = 1;
				}
			}

			//输入待查询的元素
			scanf_s("%d", &Q);

			while (Q--)
			{
				scanf_s("%d%d", &x, &y);
				if ((s[x] & s[y]).count() >= 1)
					cout << "yes" << endl;
				else
					cout << "no" << endl;
			}
		}

	}

	namespace map_test 
	{
	  /*
	  1、map<int,string,greater<int>> 分别是key的类型、value的类型，比较的函数或对象
	     可以通过make_pair生成键值对的方式来插入数据
	  2、find(k) 查找键为k的二元组位置 
	  3、[] 运算符可以得到对应key的值，也可以 [key] = value这样去设置值
	     
	     需要特别注意的是，如果查找的key不存在，
		 则执行h[key]之后会自动新建一个二元组(key,0)并返回0，
		 进行多次查找之后，有可能包含很多无用的二元组。因此使用查找时最好先查询key是否存在。
	  4、multimap .count(k)  查询出集合中有多少个键为k的元素
	  */

		void test_multimap()
		{
			multimap<string, int> mp;
			string x("x"), y("y");

			mp.insert(make_pair(x, 50));
			mp.insert(make_pair(x, 60));

			mp.insert(make_pair(x, 55));
			mp.insert(make_pair(y, 55));
			mp.insert(make_pair(x, 70));

			//输出所有x的数据
			size_t count = mp.count(x);
			cout << "x count" << count << endl;

			auto it = mp.find(x);

			for (int k = 0; k < count; ++k, it++)
				cout << it->first << "-" << it->second << endl;

	    }
	}

	//
	namespace stl_func_test 
	{   
		void test_stl_func()
		{
			/*
			1、注意memset 是按照字节单位来初始化的 一般初始化为0 -1等其他数字
			2、注意32bit最大值初始化建议使用 0x3f3f3f3f 十进制 10^9级别的数据
			   而不使用0x7fffffff 因为加1就会变成负数的值 二不满足 无穷大加一个数字 
			   还是无穷大的要求
			3、functional 提供了一些函数 equal_to<Type> 、not_equal_to<Type>、less<Type>
			   可以直接使用,less<Type>为升序排序、greater<int>为降序排序
			4、nth_element(begin,bigin+k,end,compare)的用法  注意是左闭右开 [begin,k)  
			   求第k+1小的数/第k+1大的数 
			5、lower_bound(begin,end,x) /upper_bound(begin,end,x) 查找第一个大于或者等于x的元素 
			   查找第一个小于等于x的元素
			6、next_permutation(begin,end) 对[begin,end)区间进行全排列 
			7、

			*/
			int a[4] = { 1 };
			cout << a << endl;
			memset(a, 0, sizeof(a));

			int b[] = { 8,7,10,3,6,89 };
			//sort 最后一个参数是一个函数对象 或者  函数指针等
			/*sort(b, b + sizeof(b) / sizeof(int), greater<int>());

			for (int i = 0; i < sizeof(b) / sizeof(int); ++i)
			{
				cout << b[i] << " ";
			}

			cout << endl;*/

			//求第三小的元素 nth_element的用法 nth_element(a,a+2,a+9)
			nth_element(b, b + 2, b + ( sizeof(b) / sizeof(int)));
			for (int i = 0; i < sizeof(b) / sizeof(int); ++i)
			{
				cout << b[i] << " ";
			}
			cout << endl;
			//求第二大的元素

			nth_element(b, b + 2, b + (sizeof(b) / sizeof(int)),greater<int>());
			for (int i = 0; i < sizeof(b) / sizeof(int); ++i)
			{
				cout << b[i] << " ";
			}

			cout << endl;

			//求数组的全排列
			int c[3] = { 1,2,3 };
			do {
				cout << c[0] << " " << c[1] << " " << c[2] << endl;
			} while (next_permutation(c, c + 2));
		}

		void test_middle_number()
		{
			int n;
			int a[100] = { 0 };
			while (~scanf_s("%d", &n))
			{
				for (int i = 0; i < n; ++i)
				{
					scanf_s("%d", &a[i]);
				}

				//求中间的序号  5 左移1位是2
				int mid = n >> 1;
				nth_element(a, a + mid, a + n);
				cout << "mid number is " << a[mid];
			}
		}

		void test_full_arrange()
		{
			string inStr;
			cin >> inStr;
			cout << inStr << endl;
			/*sort( inStr.begin(), inStr.end());
			cout << inStr << endl;*/

			//调用全排列
			do
			{
				for (auto it = inStr.cbegin(); it != inStr.end(); ++it)
					cout << *it << " ";
				cout << endl;
			} while (next_permutation(inStr.begin(),inStr.end()));
		}

		bool cmp_my(char a, char b)
		{
			if (tolower(a) != tolower(b))
			{
				return tolower(a) < tolower(b);
			}
			else {
				return a < b;
			}
		}
		//自定义全排序规则
		void test_full_arrange_1()
		{
			string inStr = "aDb";
			sort(inStr.begin(), inStr.end());
			cout << inStr << endl;
			do
			{
				for (auto it = inStr.cbegin(); it != inStr.end(); ++it)
					cout << *it << " ";
				cout << endl;
			} while (next_permutation(inStr.begin(), inStr.end(),cmp_my));
		}
	}
}