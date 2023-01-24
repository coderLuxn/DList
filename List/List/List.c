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

//初始化
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//free销毁
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

//打印
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

//尾插
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

//头插
void ListPushFront(ListNode* phead, SLDataType x)
{
	assert(phead);
	ListNode* newnode = BuyListNode(x);
	//1,用first链接
	ListNode* first = phead->next;
	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;

	//2直接链接 先连后断 (顺序不能换）
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;

	ListInsert(phead->next, x);
}


//头删
void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next!=phead);//当删除到头节点时不能继续删除
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;

	free(first);
	first = NULL;

	ListErase(phead->next);
}

//尾删
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

//查找一个数据并返回它的位置
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

//pos位置之前插入x
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

//删除在pos位置的值
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