#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

ListNode* BuyListNode(SLDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//��ʼ��
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//free����
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

//��ӡ
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//β��
void ListPushBack(ListNode* phead, SLDataType x)
{
	assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	ListInsert(phead->prev, x);
}

//ͷ��
void ListPushFront(ListNode* phead, SLDataType x)
{
	assert(phead);
	ListNode* newnode = BuyListNode(x);
	//1,��first����
	ListNode* first = phead->next;
	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;

	//2ֱ������ ������� (˳���ܻ���
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;

	ListInsert(phead->next, x);
}


//ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next!=phead);//��ɾ����ͷ�ڵ�ʱ���ܼ���ɾ��
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;

	free(first);
	first = NULL;

	ListErase(phead->next);
}

//βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	phead->prev = prev;
	prev->next = phead;

	free(tail);
	tail = NULL;

	ListErase(phead->next);
}

//����һ�����ݲ���������λ��
ListNode* ListFind(ListNode* phead, SLDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//posλ��֮ǰ����x
void ListInsert(ListNode* pos, SLDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = prev;
	prev->next = newnode;
}

//ɾ����posλ�õ�ֵ
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}