#include<stdio.h>
#include<iostream>

#include "snake_fill_number.h"
#include "mergerSort.h"
#include "quickSort.h"
#include "stl_base.h"
#include "LinearTable.h"
#include "zyz_stack.h"
#include "zyz_queue.h"

using namespace std;

int main()
{
	//①蛇形数组填充
	//zyz::fill_snake_numbers(5);

	//②测试合并
	/*int A[] = { 4,9,15,24,30,2,6,18,20 };
	int low = 0,high = sizeof(A)/sizeof(int)  - 1;
	int mid = (high - low) / 2;
	zyz::merge(A, low, mid, high);*/

	//③测试合并排序
	/*int B[] = { 1,6,3,4,9,89,334,34,56,5 };
	zyz::mergeSort(B, 0, sizeof(B) / sizeof(int)-1);*/


	//④测试快速排序
	/*int A[] = { 30,24,5,58,18,36,12,42,39 };
	zyz::quickSort(A, 0, sizeof(A) / sizeof(int) -1);
	for (int i = 0; i < sizeof(A) / sizeof(int); i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;*/
	//--------------stl相关---------------------------
	//⑤ 测试vector
	//zyz::vector_test::getAns();
	//⑥ 测试queu队列
	//zyz::queu_test::test_queue();

	//⑦ 测试list
	//zyz::list_test::test_list_merge();
	//zyz::list_test::test_list_unique();
	//zyz::list_test::test_soldier_count();

	//⑧ 测试deque
	//zyz::deque_test::test_deque();

	//⑨ 测试bitset
	//zyz::bit_set_test::test_bit_set();
	//zyz::bit_set_test::test_belong_number();

	//⑩ 测试map/multimap
	//zyz::map_test::test_multimap();

	//11 测试stl 常用的函数
	//zyz::stl_func_test::test_stl_func();
	//zyz::stl_func_test::test_middle_number();
	//zyz::stl_func_test::test_full_arrange();

	//12 线性表相关测试
	//linear_table::test_block_move();
	//linear_table::test_format_text("This_is_a_[Beiju]_text");

	/*linear_table::test_static_double_link();

	linear_table::StaticDoubleLink link(6);
	shared_ptr<vector<int>> sp1 = link.getLeft();
	int res = sp1->at(1);
	cout << "res is " << res << endl;*/

	//13 stack 栈相关测试
	//zyz::stack::Array_Stack<int, 2> stack_zyz;
	//cout << "stack is empty begin push elem" << endl;
	//stack_zyz.push(3);
	//stack_zyz.push(5);
	//stack_zyz.push(6);

	//cout << stack_zyz.front() << endl;
	//stack_zyz.pop();

	//cout << stack_zyz.front() << endl;
	//stack_zyz.pop();

	//stack_zyz.pop();

	////左值和右值的区别就是是否可以进行取地址的操作
	//int&& v = 6;
	//int* j = &v;

	//链表栈的测试
	/*zyz::stack::Link_Stack<string> linkStack;
	string s1("hello");
	string s2("world");
	linkStack.push(s1);
	linkStack.push(s2);

	while (!linkStack.empty())
	{
		cout << linkStack.front() << " ";
		linkStack.pop();
	}*/

	//14  队列的相关测试
	
	//zyz::queue::Array_Queue<int, 6> queue;
	

   //14.1-链队的相关测试
   zyz::queue::LinkQueue<int> queue;

   queue.enQueue(1);

   cout << queue.deQueue() << endl;
   cout << queue.deQueue() << endl;

	return 0;
}




