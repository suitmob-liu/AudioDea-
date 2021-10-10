#pragma once

#include "audioType.h"
#include "generalType.h"
#include "ClassDebug.h"

#include <stdio.h>
#include <string>

using namespace std;

class ClassAudioTool
{
public:
	ClassAudioTool();
	~ClassAudioTool();

	u32_t audioCut(string inputName, string outPutPath, u16_t channel);//���������Ϊ������
	u32_t audioJoint();//������ת������

private:
	/*
	* brief:	��ȡ�����ļ����ݣ�����buffer�洢�ļ����ݣ�����bufferָ����ļ���С
	* param:	filePathΪ�����ļ�·����outResΪ�ļ�bufferָ�룬fileSizeΪ�ļ���С
	* return��	AUDIO_OPEN_FILE_FAILURE��	�ļ�������
	*			AUDIO_SUCCESS��				���гɹ�
	*/
	u32_t readFile(string& filePath, char** pRes, u64_t& fileSize); //˽�г�Ա������ר�Ŷ�ȡ�ļ�

private:
	FILE* fileIn;		//�����ļ�
	FILE* fileOut;		//����ļ�
	char* m_pFileRes;	//�����ļ����
};

