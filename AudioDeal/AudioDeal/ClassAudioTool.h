#pragma once

#include "audioType.h"
#include "generalType.h"
#include "ClassDebug.h"

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class ClassAudioTool
{
public:
	ClassAudioTool();
	~ClassAudioTool();

	u32_t audioCut(string inputName, string outPutPath, u16_t channel);//���������Ϊ������
	u32_t audioJoint(u16_t nChannel);//������ת������

	u32_t audioCompound(string inPath, string filter);//�ϳ���Ƶ������������ϳ�һ����������Ƶ

	u32_t audioSplicing(string inPath);//�������Ƶ���ļ�����ƴ�ӳ�һ������Ƶ

	u32_t audioCutForTime(string inputName, u16_t channel, u16_t nStartTime, u16_t nEndTime);//һ����Ƶ�ļ���ȡָ��Ƭ�ε���Ƶ

	void test();

private:
	/*
	* brief:	��ȡ�����ļ����ݣ�����buffer�洢�ļ����ݣ�����bufferָ����ļ���С
	* param:	filePathΪ�����ļ�·����outResΪ�ļ�bufferָ�룬fileSizeΪ�ļ���С
	* return��	AUDIO_OPEN_FILE_FAILURE��	�ļ�������
	*			AUDIO_SUCCESS��				���гɹ�
	*/
	u32_t readFile(string& filePath, char** pRes, u64_t& fileSize); //˽�г�Ա������ר�Ŷ�ȡ�ļ�

	void getFiles(string path, vector<string>& files);
	void getFilesFilter (string path, vector<string>& files, string Filter);

private:
	FILE* fileIn;		//�����ļ�
	FILE* fileOut;		//����ļ�
	char* m_pFileRes;	//�����ļ����
};

