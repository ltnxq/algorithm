#pragma once
#include "commonHeader.h"

using namespace std;

namespace zyz
{
	/*
	1、队列是一种先进先出的数据结构
	*/
	namespace queue {

		/*
		1、队列的设计是使用c++ 的array
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

		//构造函数
		template<typename T,int maxSize>
		Array_Queue<T, maxSize>::Array_Queue()
		{
			data = new T[maxSize];
			front = rear = 0;
		}

		//队列是否满了
		template<typename T, int maxSize>
		bool Array_Queue<T, maxSize>::full()const
		{
			return (rear + 1) % maxSize == front;
		}

		//入队
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

		//判断是否为空
		template<typename T,int maxSize>
		bool Array_Queue<T, maxSize>::empty()const
		{
			return front == rear;
		}

		//出队列
		template<typename T,int maxSize>
		T Array_Queue<T, maxSize>::deQueue()
		{
			if (empty()) return NULL;
			T ele = data[front];
			front = (front + 1) % maxSize;
			return ele;
		}

		//求队列长度
		template<typename T,int maxSize>
		int Array_Queue<T, maxSize>::length()const
		{

			//①分为两种情况的去讨论
			/*if (rear >= front)
				return rear - front + 1;
			else
				return rear - front + maxSize;*/

			//② 直接一步到位
			//第一个 maxSize 防止负数  第二个防止 正数
			return (rear - front + maxSize) % maxSize;
		}

		//取队头的元素
		template<typename T,int maxSize>
		T Array_Queue<T, maxSize>::getHead()const
		{
			if (empty()) return false;
			return T[front];
		}

		/*
		1、链队列，两个元素指向头部和尾部
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
				//todo 链表中得每个元素进行内存的释放
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
		1、入队列-构造新的元素
		2、设置元素，将尾元素的next指向新的元素
		3、rear指针重新指向新的元素
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
		出队列的逻辑
		1、取出头元素地址，临时保存其值
		2、头节点front 指向之前头节点的下一个node节点
		3、特殊情况就是要判断队列是不是已经没有元素了，没有元素要进行一些额外的操作
		*/

		template<typename T>
		T LinkQueue<T>::deQueue()
		{
			if (empty()) return NULL;
			
			//取出第一个元素
			auto first_node = front->next;
			T ele = first_node->data;

			//取出第一个节点的下一个节点的地址
			auto p = first_node->next;
			first_node->next = NULL;
			front->next = p;

			//说明到了最后一个节点
			if (NULL == p)
				rear = front;

			return ele;
		}

		/*
		1、取得头部元素
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