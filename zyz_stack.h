#pragma once

#include "commonHeader.h"

using namespace std;

namespace zyz {
	/*
	* 1��ջ��һ���������Ķ���  ��ջ����ջ��ȡ��ջ����Ԫ��
	*    ����ײ�ṹ��ʵ�ַ�ʽ  - ȱ����ǲ��ܶ�̬����
	*    ����ײ�ṹ��ʵ�ַ�ʽ  - �������ƵĴ�С����������Ԫ�ع��ܵ�����
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
			//�򵥴���������ɾ������ֵ������������Ϊɾ������
			Array_Stack(Array_Stack&) = delete;
			Array_Stack& operator=(Array_Stack&) = delete;

			bool pop();
			bool push(T& t);
			bool push(T&& t);
			
			bool empty();
			/*
			* ȡ��ջ����Ԫ��
			*/
			T front();
		private :
			T* data;
			T* base;
			T* top;

	    };

		//�����������ȥ
		template<typename T, int size>
		Array_Stack<T,size>::Array_Stack()
		{
			data = new T[size];
			//ջ��ʼ��ʱ��Ϊ��  ����ָ��ָ��ͬһ��
			if (NULL == data)
				return;
			base = top = data;
		}

		//��ջ
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

		//��ջ
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


		//��ջ
		template<typename T,int size>
		bool Array_Stack<T, size>::pop()
		{
			if (empty()) return false;
			--top;
		}

		//ȡ��ջ����Ԫ��
		template<typename T,int size>
		T Array_Stack<T, size>::front()
		{
			if (empty()) return NULL;
			return *(top - 1);
		}


		//�ǿ��ж�
		template<typename T,int size>
		bool Array_Stack<T, size>::empty()
		{
			return top == base;
		}


		//����һ����ջ
		template<typename T>
		class Link_Stack {
			struct NODE{
				T  ele;
				//ָ����һ���ڵ�
				struct NODE* next;
			};
		public:
			Link_Stack();

			~Link_Stack() {
				//todo ����ÿ��Ԫ�ؽ�Ԫ�ؽ����ͷ�
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

		//һ��Ҫ��classǰ���ټ������ͷ���T
		//��ʼ��ָ�������
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

		//��ջ  ���� node �ڵ� �������� ����ָ��
		template<typename T>
		bool Link_Stack<T>::push(T& ele)
		{
			//����һ���ڵ�
			struct NODE* node = new struct NODE;

			node->ele = ele;
			node->next = s;

			//ջ��ָ���µĽڵ�
			s = node;
			return true;
		}

		//��ջ ȡ��ջ����Ԫ�ؽ����ͷ�
		//ջ��ָ������ָ��
		template<typename T>
		void Link_Stack<T>::pop()
		{
			if (empty()) return;
			struct NODE* p = s;//���ݴ�ͷ�ڵ�
			s = s->next;
			delete p;
		}

		//ȡջ����Ԫ��
		template<typename T>
		T Link_Stack<T>::front()
		{
			if (empty()) return nullptr;
			return s->ele;
		}
	}
}
