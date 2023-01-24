#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;
//typedef struct listNode ListNode;

typedef struct listNode
{
	struct listNode* next; //ºó¼Ì
	struct listNode* prev; //Ç°Çý
	SLDataType data;
}ListNode;

ListNode* ListInit();
void ListPushBack(ListNode* phead, SLDataType x);
void ListPushFront(ListNode* phead, SLDataType x);
void ListPopBack(ListNode* phead);
void ListPopFront(ListNode* phead);
void ListDestory(ListNode* phead);
void ListPrint(ListNode* phead);
ListNode* ListFind(ListNode* phead, SLDataType x);
void ListInsert(ListNode* phead, SLDataType x);
void ListErase(ListNode* phead);