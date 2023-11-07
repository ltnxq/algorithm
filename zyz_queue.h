#pragma once
#include "commonHeader.h"

using namespace std;

namespace zyz
{
	/*
	1��������һ���Ƚ��ȳ������ݽṹ
	*/
	namespace queue {

		/*
		1�����е������ʹ��c++ ��array
		*/
		template<typename T, int maxSize>
		class Array_Queue {
		public:
			Array_Queue();

			~Array_Queue() {
				delete[] data;
			}

			int length() const;
			bool empty() const;
			bool full() const;
			bool enQueue(T& ele);
			bool enQueue(T&& ele);
			T deQueue();
			T getHead() const;

		private:
			T* data;
			int front;
			int rear;
		};

		//���캯��
		template<typename T,int maxSize>
		Array_Queue<T, maxSize>::Array_Queue()
		{
			data = new T[maxSize];
			front = rear = 0;
		}

		//�����Ƿ�����
		template<typename T, int maxSize>
		bool Array_Queue<T, maxSize>::full()const
		{
			return (rear + 1) % maxSize == front;
		}

		//���
		template<typename T,int maxSize>
		bool Array_Queue<T, maxSize>::enQueue(T& ele)
		{
			if (full()) return false;
			data[rear] = ele;
			rear = (rear + 1) % maxSize;
		}

		template<typename T,int maxSize>
		bool Array_Queue<T, maxSize>::enQueue(T&& ele)
		{
			if (full()) return false;
			data[rear] = ele;
			rear = (rear + 1) % maxSize;
		}

		//�ж��Ƿ�Ϊ��
		template<typename T,int maxSize>
		bool Array_Queue<T, maxSize>::empty()const
		{
			return front == rear;
		}

		//������
		template<typename T,int maxSize>
		T Array_Queue<T, maxSize>::deQueue()
		{
			if (empty()) return NULL;
			T ele = data[front];
			front = (front + 1) % maxSize;
			return ele;
		}

		//����г���
		template<typename T,int maxSize>
		int Array_Queue<T, maxSize>::length()const
		{

			//�ٷ�Ϊ���������ȥ����
			/*if (rear >= front)
				return rear - front + 1;
			else
				return rear - front + maxSize;*/

			//�� ֱ��һ����λ
			//��һ�� maxSize ��ֹ����  �ڶ�����ֹ ����
			return (rear - front + maxSize) % maxSize;
		}

		//ȡ��ͷ��Ԫ��
		template<typename T,int maxSize>
		T Array_Queue<T, maxSize>::getHead()const
		{
			if (empty()) return false;
			return T[front];
		}

		/*
		1�������У�����Ԫ��ָ��ͷ����β��
		*/
		template<typename T>
		class LinkQueue {
			//
			struct node {
				T data;
				struct node* next = NULL;
			};

		public:
			LinkQueue();
			LinkQueue (LinkQueue&) = delete;
			LinkQueue& operator=(LinkQueue&) = delete;
			~LinkQueue()
			{
				//todo �����е�ÿ��Ԫ�ؽ����ڴ���ͷ�
			}
			void enQueue(T& ele);
			void enQueue(T&& ele);

			T deQueue();
			T getHeader() const;

			bool empty() const;
		private:
			struct node* front;
			struct node* rear;
		};

		template<typename T>
		LinkQueue<T>::LinkQueue()
		{
			front = rear = new struct node;
			front->next = NULL;
		}

		/*
		1�������-�����µ�Ԫ��
		2������Ԫ�أ���βԪ�ص�nextָ���µ�Ԫ��
		3��rearָ������ָ���µ�Ԫ��
		*/
		template<typename T>
		void LinkQueue<T>::enQueue(T& ele)
		{
			struct node* new_node = new struct node;
			new_node->data = ele;
			rear->next = new_node;
			rear = new_node;
		}


		template<typename T>
		void LinkQueue<T>::enQueue(T&& ele)
		{
			struct node* new_node = new struct node;
			new_node->data = ele;
			rear->next = new_node;
			rear = new_node;
		}

		/*
		�����е��߼�
		1��ȡ��ͷԪ�ص�ַ����ʱ������ֵ
		2��ͷ�ڵ�front ָ��֮ǰͷ�ڵ����һ��node�ڵ�
		3�������������Ҫ�ж϶����ǲ����Ѿ�û��Ԫ���ˣ�û��Ԫ��Ҫ����һЩ����Ĳ���
		*/

		template<typename T>
		T LinkQueue<T>::deQueue()
		{
			if (empty()) return NULL;
			
			//ȡ����һ��Ԫ��
			auto first_node = front->next;
			T ele = first_node->data;

			//ȡ����һ���ڵ����һ���ڵ�ĵ�ַ
			auto p = first_node->next;
			first_node->next = NULL;
			front->next = p;

			//˵���������һ���ڵ�
			if (NULL == p)
				rear = front;

			return ele;
		}

		/*
		1��ȡ��ͷ��Ԫ��
		*/
		template<typename T>
		T LinkQueue<T>::getHeader() const
		{
			if (empty()) return NULL;
			return front->next->data;
		}

		template<typename T>
		bool LinkQueue<T> ::empty() const
		{
			return front == rear;
		}

	}
}