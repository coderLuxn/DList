#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

void Test1()
{
		ListNode* plist =ListInit();//��ַ

		//β��
		ListPushBack(plist, 1);
		ListPushBack(plist, 2);
		ListPushBack(plist, 3);
		ListPushBack(plist, 4);
		ListPrint(plist);

		//ͷ��
		ListPushFront(plist, 5);
		ListPushFront(plist, 6);
		ListPushFront(plist, 7);
		ListPushFront(plist, 8);
		ListPrint(plist);

		//ͷɾ
		ListPopFront(plist);
		ListPopFront(plist);
		ListPrint(plist);

		//βɾ
		ListPopBack(plist);
		ListPopBack(plist);
		ListPrint(plist);
}

void Test2()
{
	ListNode* plist = ListInit();//��ַ

	//β��
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	//����
	ListNode* pos=ListFind(plist,3);//���Ը�
	if (pos)
	{
		pos->data = 30;
		printf("�ҵ���,���ҽڵ��ֵ����10\n");
	}
	else
	{
		printf("�Ҳ���");
	}
	ListPrint(plist);

	//����
	ListInsert(pos, 300);
	ListPrint(plist);

	//ɾ��
	ListErase(pos);
	ListPrint(plist);
}

int main()
{
	Test2();
	return 0;
}