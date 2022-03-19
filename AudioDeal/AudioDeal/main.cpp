
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
	int startTime = 0, endTime = 0;
	ClassAudioTool testFunction;
	//ClassAudioTool at;
	int ret = 0;
	string str;
	int functionTest = 0;
	int times = 0;

	while (1)
	{
		printf("������Ƶ******************************����1\n"
			"�ϳ���Ƶ******************************����2\n"
			"ƴ����Ƶ******************************����3\n"
			"��ȡָ��Ƭ����Ƶ������ʱ�䣩**********����4\n"
			"���д��ļ���Ƶ������2G�ļ���**********����5\n");
		functionTest = getchar();

		if (functionTest == '1')
		{
			break;
		}
		else if (functionTest == '2')
		{
			break;
		}
		else if (functionTest == '3')
		{
			break;
		}
		else if (functionTest == '4')
		{
			break;
		}
		else if (functionTest == '5')
		{
			break;
		}
		else
		{
			times++;
			printf("��������%d�Σ�����������\n", times);
			if (times >= 4)
			{
				printf("����������˳�");
				system("pause");
				return 0;
			}
		}
	}
	
	memset(tm1, 0, 128);
	memset(tm2, 0, 128);
	switch (functionTest)
	{
	case '1':
		printf("��������е���Ƶ�ļ���");
		scanf("%s", tm1);
		printf("\n");

		printf("����������Ƶ�ļ�·����");
		scanf("%s", tm2);
		printf("\n");

		printf("�����������Ƶ��ͨ������");
		scanf("%d", &num);
		printf("\n");

		ret = testFunction.audioCut(tm1, tm2, num);
		printf("audioCut ret is %d\n", ret);
		break;
	case '2':
		printf("������ϳɵ���Ƶ�ļ�·����");
		scanf("%s", tm1);
		printf("\n");

		str = "out";
		testFunction.audioCompound(tm1, str);

		printf("�ϳɳɹ�\n");
		break;
	case '3':
		printf("������ƴ�ӵ���Ƶ�ļ�·����");
		scanf("%s", tm1);
		printf("\n");

		testFunction.audioSplicing(tm1);
		printf("ƴ�ӽ���\n");
		break;
	case '4':
		printf("��������е���Ƶ�ļ���");
		scanf("%s", tm1);
		printf("\n");

		printf("�����������Ƶ��ͨ������");
		scanf("%d", &num);
		printf("\n");

		printf("�����������Ƶ����ʼ�㣺(��λ��)");
		scanf("%d", &startTime);
		printf("\n");

		printf("�����������Ƶ���յ㣺(��λ��)");
		scanf("%d", &endTime);
		printf("\n");

		ret = testFunction.audioCutForTime(tm1, num, startTime, endTime);
		printf("audioCutForTime ret is %d\n", ret);
		break;
	case '5':
		printf("��������е���Ƶ�ļ���");
		scanf("%s", tm1);
		printf("\n");

		printf("����������Ƶ�ļ�·����");
		scanf("%s", tm2);
		printf("\n");

		printf("�����������Ƶ��ͨ������");
		scanf("%d", &num);
		printf("\n");

		ret = testFunction.audioCutForBigFile(tm1, tm2, num);
		printf("audioCut ret is %d\n", ret);
		break;
	default:
		break;
	}

	system("pause");

	return 0;
}