#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

void Test1()
{
		ListNode* plist =ListInit();//地址

		//尾插
		ListPushBack(plist, 1);
		ListPushBack(plist, 2);
		ListPushBack(plist, 3);
		ListPushBack(plist, 4);
		ListPrint(plist);

		//头插
		ListPushFront(plist, 5);
		ListPushFront(plist, 6);
		ListPushFront(plist, 7);
		ListPushFront(plist, 8);
		ListPrint(plist);

		//头删
		ListPopFront(plist);
		ListPopFront(plist);
		ListPrint(plist);

		//尾删
		ListPopBack(plist);
		ListPopBack(plist);
		ListPrint(plist);
}

void Test2()
{
	ListNode* plist = ListInit();//地址

	//尾插
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	//查找
	ListNode* pos=ListFind(plist,3);//可以改
	if (pos)
	{
		pos->data = 30;
		printf("找到啦,并且节点的值乘以10\n");
	}
	else
	{
		printf("找不到");
	}
	ListPrint(plist);

	//增加
	ListInsert(pos, 300);
	ListPrint(plist);

	//删除
	ListErase(pos);
	ListPrint(plist);
}

int main()
{
	Test2();
	return 0;
}