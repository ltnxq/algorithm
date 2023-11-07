#pragma once
#include "commonHeader.h"

namespace zyz
{   
	using namespace std;

	//合并
	void merge(int A[],int low,int mid,int high)
	{
		//申请一个新的数组B 用于存放排序好的数据
		//申请数据一定要严格,而且一定要进行初始化 high - low + 1
		int* B = new int[high - low+1];

		int i = low, j = mid + 1, k = 0;

		while (i <= mid && j <= high)
		{
			if (A[i] < A[j])
			{
				B[k++] = A[i++];
			}
			else
			{
				B[k++] = A[j++];
			}
		}

		while (i <= mid) B[k++] = A[i++];
		while (j <= high) B[k++] = A[j++];

		//将B数组的元素全部放到A中
		for (i = low, k = 0; i <= high; i++)
			A[i] = B[k++];

		//打印A的数组内容
		for (i = 0; i < high - low + 1; i++)
			cout << A[i] << " ";

		cout << endl;

		delete[] B;  
	}



	/*
	1、合并排序的首要目标就是把数组拆分成一个元素，一个元素是天然有序的
	2、然后再将拆分后的数组进行合并
	3、需要额外的数组来保持排序后的数据
	
	*/
	//A[] = [1,3,5,2]

	void mergeSort(int A[],int low,int high)
	{
		if (low < high) //保证至少有两个元素
		{
			int mid = (low + high) / 2;//取中点
			mergeSort(A, low, mid);
			mergeSort(A, mid + 1, high);
			//
			merge(A, low, mid, high);

		}
	}

}

