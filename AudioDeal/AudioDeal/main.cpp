
#include "ClassAudioTool.h"
#include "ClassDebug.h"

#include <stdio.h>
#include <iostream>
#pragma warning(disable:4996)

#define key 5

int main()
{
	char tm1[128] = { 0 };
	char tm2[128] = { 0 };
	int num = 0;
	ClassAudioTool testFunction;
	ClassAudioTool at;
	int ret = 0;
	string str;
	int functionTest = 0;

	while (1)
	{
		printf("������Ƶ����1\n"
			"�ϳ���Ƶ����2\n");
		scanf("%d", &functionTest);
		printf("\n");

		if (functionTest == 1)
		{
			break;
		}
		else if (functionTest == 2)
		{
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	}

	memset(tm1, 0, 128);
	memset(tm2, 0, 128);

	switch (functionTest)
	{
	case 1:
		printf("��������е���Ƶ�ļ���");
		scanf("%s", tm1);
		printf("\n");

		printf("����������Ƶ�ļ�·����");
		scanf("%s", tm2);
		printf("\n");

		printf("�����������Ƶ��ͨ������");
		scanf("%d", &num);
		printf("\n");

		ret = at.audioCut(tm1, tm2, num);
		printf("audioCut ret is %d\n", ret);
		break;
	case 2:
		printf("������ϳɵ���Ƶ�ļ�·����");
		scanf("%s", tm1);
		printf("\n");

		str = "out";
		testFunction.audioCompound(tm1, str);

		printf("�ϳɳɹ�\n");
		break;
	default:
		break;
	}
#if key == 1
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
#elif key == 2

	ClassDebug &cd = ClassDebug::getInStance();
	ClassDebug &cd2 = ClassDebug::getInStance();
	string str = "main is run";
	cd.debugLog(str);
	ClassAudioTool at2;
	at2.audioJoint(4);
	cd.debugLog("run over");

#elif key == 3
	testFunction.test();

#elif key == 4
	printf("������ϳɵ���Ƶ�ļ�·����");
	scanf("%s", tm1);
	printf("\n");

	string str = "out";
	testFunction.audioCompound(tm1, str);

	printf("�ϳɳɹ�\n");
#endif

	system("pause");

	return 0;
}