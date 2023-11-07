#pragma once

#include "commonHeader.h"

using namespace std;

namespace zyz {
	/*
	* 1、栈是一种先入后出的队列  出栈、入栈、取出栈顶的元素
	*    数组底层结构的实现方式  - 缺点就是不能动态扩容
	*    链表底层结构的实现方式  - 加上限制的大小，可以增加元素功能的限制
	*/
	namespace stack
	{   
		
		template<typename T,int size>
		//
		class Array_Stack
	    { 
		public:
			Array_Stack();

			~Array_Stack()
			{
				base = nullptr;
				top = nullptr;

				delete[] data;
			}
			//简单处理拷贝构造删除、赋值拷贝构造设置为删除函数
			Array_Stack(Array_Stack&) = delete;
			Array_Stack& operator=(Array_Stack&) = delete;

			bool pop();
			bool push(T& t);
			bool push(T&& t);
			
			bool empty();
			/*
			* 取出栈顶的元素
			*/
			T front();
		private :
			T* data;
			T* base;
			T* top;

	    };

		//类后面必须加上去
		template<typename T, int size>
		Array_Stack<T,size>::Array_Stack()
		{
			data = new T[size];
			//栈初始的时候为空  两个指针指向同一个
			if (NULL == data)
				return;
			base = top = data;
		}

		//入栈
		template<typename T,int size>
		bool Array_Stack<T,size>:: push(T& t)
		{
			if (top - base >= size)
			{
				cout << "stack is full" << endl;
				return false;
			}
			*top = t;
			top++;
		}

		//入栈
		template<typename T, int size>
		bool Array_Stack<T, size>::push(T&& t)
		{
			if (top - base >= size)
			{
				cout << "stack is full" << endl;
				return false;
			}
			*top = t;
			++top;
		}


		//出栈
		template<typename T,int size>
		bool Array_Stack<T, size>::pop()
		{
			if (empty()) return false;
			--top;
		}

		//取出栈顶的元素
		template<typename T,int size>
		T Array_Stack<T, size>::front()
		{
			if (empty()) return NULL;
			return *(top - 1);
		}


		//非空判断
		template<typename T,int size>
		bool Array_Stack<T, size>::empty()
		{
			return top == base;
		}


		//构建一个链栈
		template<typename T>
		class Link_Stack {
			struct NODE{
				T  ele;
				//指向下一个节点
				struct NODE* next;
			};
		public:
			Link_Stack();

			~Link_Stack() {
				//todo 遍历每个元素将元素进行释放
			}
			//Link_Stack& (Link_Stack&) = delete;
			Link_Stack& operator=(Link_Stack&) = delete;

			bool push(T& ele);
			void pop();
			bool empty();
			T front();
		private:
			struct NODE* s;
		};

		//一定要在class前面再加上类型符号T
		//初始是指向控制在
		template<typename T>
		Link_Stack<T>::Link_Stack()
		{
			s = NULL;
		}

		template<typename T>
		bool Link_Stack<T>::empty()
		{
			return s == NULL;
		}

		//入栈  构造 node 节点 插入数据 连接指针
		template<typename T>
		bool Link_Stack<T>::push(T& ele)
		{
			//构造一个节点
			struct NODE* node = new struct NODE;

			node->ele = ele;
			node->next = s;

			//栈顶指向新的节点
			s = node;
			return true;
		}

		//出栈 取出栈顶的元素进行释放
		//栈顶指针重新指向
		template<typename T>
		void Link_Stack<T>::pop()
		{
			if (empty()) return;
			struct NODE* p = s;//先暂存头节点
			s = s->next;
			delete p;
		}

		//取栈顶的元素
		template<typename T>
		T Link_Stack<T>::front()
		{
			if (empty()) return nullptr;
			return s->ele;
		}
	}
}
