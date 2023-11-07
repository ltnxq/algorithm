#pragma once
#include "commonHeader.h"

//���������ԭ��ͻ�ȡ��������������н��еݹ�ֽ�

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

		//ѡȡ��һ��Ԫ��Ϊ ��׼Ԫ��
		int i = low, j = high, prior = A[low];
		
		while (i < j)
		{
			//��������ѭ�������ұ�priot�͵�Ԫ�ؽ��н���
			while (i < j && prior < A[j])
				j--;
			if (i < j)
				swap(A[i++], A[j]);  //����Ԫ�ؽ��н����������ұߵ�����Ҫ��1

			//��������ѭ�������ұ�priot�ߵ�Ԫ�ؽ��н���
			while (i < j && prior >= A[i])
				i++;
			if (i < j)
				swap(A[j--],A[i]);
		}
		//
		return i;
	}

	//һ���Ż��ķ�������prior���н���
	int get_mid_2(int A[], int low, int high)
	{
		int i = low, j = high, prior = A[low];

		while (i < j)
		{   
			//�ȴ�������
			while (i < j && A[j] > prior) j--;
			//�ٴ�������
			while (i < j && A[i] <= prior) i++;
			//�Ƚ���i��j��Ȼ���ٸ���i��j��ֵ
			if (i < j)
				swap(A[i++], A[j--]);
		}

		//�˳�ѭ�� Ҳ���� i = j = 18
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
		//�ݹ���ֹ������
		if (low < high)
		{
			int mid = get_mid_2(A, low, high);
			quickSort(A, low, mid - 1);
			quickSort(A, mid + 1, high);
		}
		
	}
}
