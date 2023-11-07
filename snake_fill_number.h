#pragma once

#include "commonHeader.h"

using namespace std;

namespace zyz {


	/*
     n 是的行维度的参数
    */
	void fill_snake_numbers(int n)
	{
		//初始化一个二维数组
		int** a = new int* [n];
		//对数组的每一项进行初始化
		for (int i = 0; i < n; ++i)
		{
			a[i] = new int[n];
			memset(a[i], 0, n * sizeof(int));
		}

		//打印二维数组
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(5) << a[i][j];
			}

			cout << endl;
		}

		//填充数据
		int x, y;
		x = y = 0;
		int total;
		total= a[0][0] = 1;

		while (total < n * n)
		{
			//向右边
			while (y + 1 < n  && !a[x][y + 1])
				a[x][++y] = ++total;
			//向下
			while (x + 1 < n && !a[x + 1][y])
			{
				a[++x][y] = ++total;
			}
				
			//向左
			while (y - 1 >= 0 && !a[x][y - 1])
				a[x][--y] = ++total;
			//向上  直到不满足while循环
			while (x - 1 >= 0 && !a[x - 1][y])
				a[--x][y] = ++total;
		}

		//
		cout << "fill number over" << endl;

		//

		//打印二维数组
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(5) << a[i][j];
			}

			cout << endl;
		}

		//数组内存释放
		for (int i = 0; i < n; i++)
		{   
			//二维数组中的每个数组进行释放
			delete[] a[i];
		}

		//外围的数组释放
		delete[] a;
	}



}

