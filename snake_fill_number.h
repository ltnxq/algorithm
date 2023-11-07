#pragma once

#include "commonHeader.h"

using namespace std;

namespace zyz {


	/*
     n �ǵ���ά�ȵĲ���
    */
	void fill_snake_numbers(int n)
	{
		//��ʼ��һ����ά����
		int** a = new int* [n];
		//�������ÿһ����г�ʼ��
		for (int i = 0; i < n; ++i)
		{
			a[i] = new int[n];
			memset(a[i], 0, n * sizeof(int));
		}

		//��ӡ��ά����
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(5) << a[i][j];
			}

			cout << endl;
		}

		//�������
		int x, y;
		x = y = 0;
		int total;
		total= a[0][0] = 1;

		while (total < n * n)
		{
			//���ұ�
			while (y + 1 < n  && !a[x][y + 1])
				a[x][++y] = ++total;
			//����
			while (x + 1 < n && !a[x + 1][y])
			{
				a[++x][y] = ++total;
			}
				
			//����
			while (y - 1 >= 0 && !a[x][y - 1])
				a[x][--y] = ++total;
			//����  ֱ��������whileѭ��
			while (x - 1 >= 0 && !a[x - 1][y])
				a[--x][y] = ++total;
		}

		//
		cout << "fill number over" << endl;

		//

		//��ӡ��ά����
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << setw(5) << a[i][j];
			}

			cout << endl;
		}

		//�����ڴ��ͷ�
		for (int i = 0; i < n; i++)
		{   
			//��ά�����е�ÿ����������ͷ�
			delete[] a[i];
		}

		//��Χ�������ͷ�
		delete[] a;
	}



}

