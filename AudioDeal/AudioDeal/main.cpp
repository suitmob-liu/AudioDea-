
#include "ClassAudioTool.h"
#include "ClassDebug.h"

#include <stdio.h>
#include <iostream>
#pragma warning(disable:4996)

int main()
{
//	printf("this is test\n");
	char tm1[128] = { 0 };
	char tm2[128] = { 0 };
	int num = 0;
#if 0
	printf("��������е���Ƶ�ļ���");
	scanf("%s",tm1);
	printf("\n");

	printf("����������Ƶ�ļ�·����");
	scanf("%s", tm2);
	printf("\n");

	printf("�����������Ƶ��ͨ������");
	scanf("%d", &num);
	printf("\n");

	ClassAudioTool at;
	int ret = 0;
	ret = at.audioCut(tm1, tm2, num);
	printf("audioCut ret is %d\n", ret);
#endif

	ClassDebug &cd = ClassDebug::getInStance();
	ClassDebug &cd2 = ClassDebug::getInStance();
	string str = "";
	cd.debugLog(str, 0);

	return 0;
}