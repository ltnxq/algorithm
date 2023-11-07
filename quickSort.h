#pragma once
#include "commonHeader.h"

//快速排序的原理就获取两个相对有序序列进行递归分解

namespace zyz
{
	using namespace std;


	int get_mid(int A[],int low,int high)
	{
		if (sizeof(A) <= 0)
		{
			cout << "arry must not be empty" << endl;
			return -1;
		}

		//选取第一个元素为 基准元素
		int i = low, j = high, prior = A[low];
		
		while (i < j)
		{
			//从右向左循环，查找比priot低的元素进行交换
			while (i < j && prior < A[j])
				j--;
			if (i < j)
				swap(A[i++], A[j]);  //两个元素进行交换，并且右边的索引要加1

			//从左向右循环，查找比priot高的元素进行交换
			while (i < j && prior >= A[i])
				i++;
			if (i < j)
				swap(A[j--],A[i]);
		}
		//
		return i;
	}

	//一个优化的方法不对prior进行交换
	int get_mid_2(int A[], int low, int high)
	{
		int i = low, j = high, prior = A[low];

		while (i < j)
		{   
			//先从右往左
			while (i < j && A[j] > prior) j--;
			//再从左往右
			while (i < j && A[i] <= prior) i++;
			//先交换i和j，然后再更新i和j的值
			if (i < j)
				swap(A[i++], A[j--]);
		}

		//退出循环 也就是 i = j = 18
		if (A[i] > prior)
		{
			swap(A[i-1], A[low]);
			return i - 1;
		}

		swap(A[i], A[low]);
		return i;
			
	}

	void  quickSort(int A[], int low, int high)
	{   
		//递归终止的条件
		if (low < high)
		{
			int mid = get_mid_2(A, low, high);
			quickSort(A, low, mid - 1);
			quickSort(A, mid + 1, high);
		}
		
	}
}
