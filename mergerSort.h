#pragma once
#include "commonHeader.h"

namespace zyz
{   
	using namespace std;

	//�ϲ�
	void merge(int A[],int low,int mid,int high)
	{
		//����һ���µ�����B ���ڴ������õ�����
		//��������һ��Ҫ�ϸ�,����һ��Ҫ���г�ʼ�� high - low + 1
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

		//��B�����Ԫ��ȫ���ŵ�A��
		for (i = low, k = 0; i <= high; i++)
			A[i] = B[k++];

		//��ӡA����������
		for (i = 0; i < high - low + 1; i++)
			cout << A[i] << " ";

		cout << endl;

		delete[] B;  
	}



	/*
	1���ϲ��������ҪĿ����ǰ������ֳ�һ��Ԫ�أ�һ��Ԫ������Ȼ�����
	2��Ȼ���ٽ���ֺ��������кϲ�
	3����Ҫ�������������������������
	
	*/
	//A[] = [1,3,5,2]

	void mergeSort(int A[],int low,int high)
	{
		if (low < high) //��֤����������Ԫ��
		{
			int mid = (low + high) / 2;//ȡ�е�
			mergeSort(A, low, mid);
			mergeSort(A, mid + 1, high);
			//
			merge(A, low, mid, high);

		}
	}

}

