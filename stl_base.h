
#include "commonHeader.h"

using namespace std;

namespace zyz
{
	
	namespace vector_test {
		using namespace std;
		void getAns()
		{
			//all ->���й�����Ա amPersons->m ����� d->˫����� dns ->���յļ��
			vector<string> allPerson, amPersons, doublePersons, ansPersons;

			int all, am, dol;
			string s;
			while (cin >> all >> am >> dol)
			{
				allPerson.clear();
				amPersons.clear();
				ansPersons.clear();
				//�ֱ���� all am dol ����ʼ������vector
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

				//�жϵڶ������ڵ�һ�м����У����ڵ����еľ��Ǽ��
				for (auto it = amPersons.cbegin(); it != amPersons.end(); it++)
				{
					//�ڵ�һ��������
					if ((find(allPerson.cbegin(), allPerson.cend(), *it) != allPerson.cend())
						&& (find(doublePersons.cbegin(), doublePersons.cend(), *it) ==
							doublePersons.cend())
						)
					{
						ansPersons.push_back(*it);
					}
				}

				//��ӡ���
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

		//����һ����λ�Ľṹ��
		struct point {
			int x, y;
			int step;
		};
		//������ʿ����㵽�յ��ƶ��Ĳ���
		//��ʼ����ʿx��y�����ƶ��ľ���
		int dx[8] = { -2,-2,-1,1,1,2,2 };
		int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };

		//
		const int maxn = 310;
		bool vis[maxn][maxn];
		//s->��� e->�յ�  L���̵ĳ���
		//tx ty ����ʿ �м��λ��
		int sx, sy, ex, ey, tx, ty, L;

		int bfs()
		{
			//��������ص���ֱͬ�ӷ���0
			if (sx == ex && sy == ey) return 0;
			memset(vis, false, sizeof(vis));
			//����һ������
			queue<point> Q ;
			point start, node;
			//��ʼ��start
			start.x = sx;
			start.y = sy;
			start.step = 0;
			Q.push(start);

			int step, x, y;
			while (!Q.empty())
			{
				//ȡ�����е�ͷԪ��
				start = Q.front(), Q.pop();
				x = start.x;
				y = start.y;
				step = start.step;
				//��չ
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
		1��list��ר��API,merge(b),�ںϲ�֮ǰ����list�������ź�˳���,�������ֱ���쳣��ֹ
		2��unique()��������ͬ��Ԫ�ؽ���ѹ����������������Ļ����޷�����ѹ����
		   ����һ���Ƚ���������ѹ��
		3��front()/back() ֻ�Ƿ����ײ���ͷ����Ԫ��  pop_front/pop_back ��
		*/

		void test_list_merge() {
			list<int> list1 = { 5,1,2,3,6 };
			list<int> list2 = { 7,5,3,8 };

			//list ר��sort���� ����Ч�ʸ�
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
							it = a.erase(it);//ע���������itָ����һλ��ʿ���ĵ�ַ
						else
							it++;
					}

					k = (k == 2 ? 3 : 2);
				}

				//ѭ������
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
		1��deque��һ��˫�˶��У���Ҫ���˽��в����Ļ�������ʹ��deque
		2��push_front/push_back pop_front/pop_back front/back �Ȳ���
		*/
		void read(int& x)
		{
			char ch = getchar(); x = 0;
			//С��0 ���ߴ���9 ������
			for (; ch < '0' || ch > '9'; ch = getchar());
			//����0����С��9������
			for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';

		}

		const int maxn = 1000;
		int m, n;
		//d ���� ÿ��Ԫ�ض���deque
		deque<int> d[maxn];

		void test_deque()
		{
			while (~scanf_s("%d%d", &n, &m))
			{
				for (int i = 1; i < n; i++)
					d[i].clear();
				//m �Ƕ��������� 1 1 1 23
				//k - ��Ӧ�Ĳ������� 
				//u - ��ʾ���Ϊu�Ķ��� v - value w-��ʾ�Զ����ĸ��������
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
							//˳���
							d[u].insert(d[u].end(), d[v].begin(), d[v].end());
						}
						else 
						{
						   //�����
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
		* priority_queue<Type, Container, Functional>  Container �����������͵�����
		1�������ȼ����У����ȼ���ߵ��ȳ��ӣ��ڲ���ʵ���Ƕѵ����ݽṹ��������ɾ��ָ����Ԫ��
		2��pop���ӡ�topȡ��ͷ
		*/

		void test_priority_queue()
		{
			//���ȼ���Ķ���
			priority_queue<int> q1;
			//���ȼ�С�Ķ�
			priority_queue<int, vector<int>, greater<int>> q2;

			int a[1000];

			// n ���ڵڼ���  m ���ܹ����ٸ�����
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
					//q1��Ϊ����a[cnt]<q1.top() ˵��a[cnt]����ǰi-1�����
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
		1�����캯��  ��ס���ֳ�ʼ����ʽ
		bitset<n> b; n��������λ���� 0  bitset<n>(unsigned long) bitset<n>(string)
		2��һЩ����
		   || ~ & | ^ >> << == !=  ��һЩ���ڶ����Ƶ�����
		   cout(ͳ��1�ĸ���)��any() ֻҪ��һ��Ϊ1����true set(k) ��kλ����Ϊ1
		   reset(k) = set(k,0)
		   flip(k) ��kλȡ�� flip()ȫ��ȡ��
		   to_ulong()��������ת��Ϊunsigned long�Ľ�������������Χ���򱨴�
		   to_string() 
		*/

		void test_bit_set()
		{
			try
			{   
				//1������to_long  һ��Ҫ��long�ķ�Χ��,�����׳�bitset overflow
				bitset<10000> b("11111111111111111111");
				cout << b.to_ulong() << endl;
				//2����ʮ����ת��Ϊ������
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
			//s[x] ��ʾԪ��x�������ϵĶ����Ʊ�ʾ
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

			//�������ѯ��Ԫ��
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
	  1��map<int,string,greater<int>> �ֱ���key�����͡�value�����ͣ��Ƚϵĺ��������
	     ����ͨ��make_pair���ɼ�ֵ�Եķ�ʽ����������
	  2��find(k) ���Ҽ�Ϊk�Ķ�Ԫ��λ�� 
	  3��[] ��������Եõ���Ӧkey��ֵ��Ҳ���� [key] = value����ȥ����ֵ
	     
	     ��Ҫ�ر�ע����ǣ�������ҵ�key�����ڣ�
		 ��ִ��h[key]֮����Զ��½�һ����Ԫ��(key,0)������0��
		 ���ж�β���֮���п��ܰ����ܶ����õĶ�Ԫ�顣���ʹ�ò���ʱ����Ȳ�ѯkey�Ƿ���ڡ�
	  4��multimap .count(k)  ��ѯ���������ж��ٸ���Ϊk��Ԫ��
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

			//�������x������
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
			1��ע��memset �ǰ����ֽڵ�λ����ʼ���� һ���ʼ��Ϊ0 -1����������
			2��ע��32bit���ֵ��ʼ������ʹ�� 0x3f3f3f3f ʮ���� 10^9���������
			   ����ʹ��0x7fffffff ��Ϊ��1�ͻ��ɸ�����ֵ �������� ������һ������ 
			   ����������Ҫ��
			3��functional �ṩ��һЩ���� equal_to<Type> ��not_equal_to<Type>��less<Type>
			   ����ֱ��ʹ��,less<Type>Ϊ��������greater<int>Ϊ��������
			4��nth_element(begin,bigin+k,end,compare)���÷�  ע��������ҿ� [begin,k)  
			   ���k+1С����/��k+1����� 
			5��lower_bound(begin,end,x) /upper_bound(begin,end,x) ���ҵ�һ�����ڻ��ߵ���x��Ԫ�� 
			   ���ҵ�һ��С�ڵ���x��Ԫ��
			6��next_permutation(begin,end) ��[begin,end)�������ȫ���� 
			7��

			*/
			int a[4] = { 1 };
			cout << a << endl;
			memset(a, 0, sizeof(a));

			int b[] = { 8,7,10,3,6,89 };
			//sort ���һ��������һ���������� ����  ����ָ���
			/*sort(b, b + sizeof(b) / sizeof(int), greater<int>());

			for (int i = 0; i < sizeof(b) / sizeof(int); ++i)
			{
				cout << b[i] << " ";
			}

			cout << endl;*/

			//�����С��Ԫ�� nth_element���÷� nth_element(a,a+2,a+9)
			nth_element(b, b + 2, b + ( sizeof(b) / sizeof(int)));
			for (int i = 0; i < sizeof(b) / sizeof(int); ++i)
			{
				cout << b[i] << " ";
			}
			cout << endl;
			//��ڶ����Ԫ��

			nth_element(b, b + 2, b + (sizeof(b) / sizeof(int)),greater<int>());
			for (int i = 0; i < sizeof(b) / sizeof(int); ++i)
			{
				cout << b[i] << " ";
			}

			cout << endl;

			//�������ȫ����
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

				//���м�����  5 ����1λ��2
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

			//����ȫ����
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
		//�Զ���ȫ�������
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