#include "ClassAudioTool.h"
#pragma warning(disable:4996)

ClassAudioTool::ClassAudioTool()
{
}

ClassAudioTool::~ClassAudioTool()
{
	if (m_pFileRes != NULL)
	{
		free(m_pFileRes);
		m_pFileRes = NULL;
	}
}

u32_t ClassAudioTool::audioCut(string inputName, string outPutPath, u16_t channel)
{
	char* inRes = NULL;//��ȡ�������ļ��ڴ�
	char* outRes = NULL;//����ļ��ڴ�
	u16_t channelNum = channel;//ͨ����
	string openFileName = inputName;
	ClassDebug &nDebug = ClassDebug::getInStance();
	string strLog = "";

	//need to check file exist

#ifdef OLDLOGIC
	//�������
	fileIn = fopen(openFileName.c_str(), "w+");
	if (fileIn == NULL)
	{
		printf("open file failure\n");
		return AUDIO_OPEN_FILE_FAILURE;
	}

	if (channelNum >= 1 && channelNum <= 16)
	{
		if (channelNum != (u16_t)channelNum)
		{
			printf("The Param is invalid and Param is decimal!\n");
			return AUDIO_INVAIID_PARAM;
		}
	}
	else
	{
		printf("The Param is invalid\n");
		return AUDIO_INVAIID_PARAM;
	}

	u32_t size = 0;//�ļ���С
	fseek(fileIn, 0, SEEK_END);
	size = ftell(fileIn);
	fseek(fileIn, 0, SEEK_SET);

	u32_t sizeRes = size / channelNum;//�������ļ���С
	inRes = (char*)malloc(sizeof(char) * size);
	memset(inRes, 0, size * sizeof(char));
	fread(inRes, sizeof(char), size, fileIn);
	fclose(fileIn);
#else
	u32_t ret = AUDIO_SUCCESS;
	u64_t fileSize = 0;
	ret = readFile(openFileName, &inRes, fileSize);
	u64_t sizeRes = fileSize / channelNum;//�������ļ���С
#endif // OLDLOGIC

	outRes = (char*)malloc(sizeof(char) * sizeRes);
	string outPath = outPutPath;
	char* fileName = NULL;
	fileName = (char*)malloc(sizeof(char) * 100);

	for (u16_t numIndex = 0; numIndex < channelNum; numIndex++)
	{
		memset(fileName, 0, 100 * sizeof(char));
		memset(outRes, 0, sizeRes * sizeof(char));
		unsigned char fileIndex = numIndex + 1;
		sprintf(fileName, "/outFile_%d.pcm", fileIndex);
		u16_t numD = numIndex * 2;
		u64_t j = 0;
		for (u64_t i = 0; i < fileSize; i += channelNum * 2)
		{
			outRes[j] = inRes[i + numD];
			outRes[j + 1] = inRes[i + 1 + numD];
			j += 2;
		}

		outPath = outPutPath;
		outPath += fileName;
		FILE* fp2 = NULL;
		fp2 = fopen(outPath.c_str(), "wb+");
		if (fp2 == NULL)
		{
			printf("open file failure\n");
			strLog = "open file failure\n";
			nDebug.debugLog(strLog);
			return AUDIO_OPEN_FILE_FAILURE;
		}
		int ret = fwrite(outRes, sizeof(char), sizeRes, fp2);
		fclose(fp2);
		fp2 = NULL;
	}
	if (fileName != NULL)
	{
		free(fileName);
		fileName = NULL;
	}
	if (inRes != NULL)
	{
		free(inRes);
		inRes = NULL;
	}
	if (outRes != NULL)
	{
		free(outRes);
		outRes = NULL;
	}
	return AUDIO_SUCCESS;
}

u32_t ClassAudioTool::audioJoint()
{
	u32_t ret = AUDIO_SUCCESS;
	u16_t fileNum;//�������ļ�������������UI�ж�
	fileNum = 4;
	string pathNameTmp1;//�ļ����ƣ�����ͨ��UI����
	string pathNameTmp2;
	string pathNameTmp3;
	string pathNameTmp4;

	char* fileResTmp1 = NULL;
	char* fileResTmp2 = NULL;
	char* fileResTmp3 = NULL;
	char* fileResTmp4 = NULL;

	u64_t fileSizeTmp1 = 0;//�ĸ��������ļ���װ�Ļ����ļ���СӦ��һ�£��˴�����һ���������ɣ����һ�������ж�
	u64_t fileSizeTmp2 = 0;
	u64_t fileSizeTmp3 = 0;
	u64_t fileSizeTmp4 = 0;

	pathNameTmp1 = "D:\\SOFT\\audioCut\\out0.pcm";
	pathNameTmp2 = "D:\\SOFT\\audioCut\\out1.pcm";
	pathNameTmp3 = "D:\\SOFT\\audioCut\\out2.pcm";
	pathNameTmp4 = "D:\\SOFT\\audioCut\\out3.pcm";

	ret = readFile(pathNameTmp1, &fileResTmp1, fileSizeTmp1);
	ret = readFile(pathNameTmp2, &fileResTmp2, fileSizeTmp2);
	ret = readFile(pathNameTmp3, &fileResTmp3, fileSizeTmp3);
	ret = readFile(pathNameTmp4, &fileResTmp4, fileSizeTmp4);
	if (ret != 0)
	{
		printf("fail to readFile\n");
		return AUDIO_FAILE;
	}

	u64_t fileSizeSum = fileSizeTmp1 + fileSizeTmp2 + fileSizeTmp3 + fileSizeTmp4;//��������͸����ȥ
	char* fileResSum = NULL;
	fileResSum = (char*)malloc(fileSizeSum);
	u64_t j = 0;
	for (u64_t i = 0; i < fileSizeSum; i += 8)
	{
		fileResSum[i] = fileResTmp1[j];
		fileResSum[i + 1] = fileResTmp1[j + 1];

		fileResSum[i + 2] = fileResTmp2[j];
		fileResSum[i + 3] = fileResTmp2[j + 1];

		fileResSum[i + 4] = fileResTmp3[j];
		fileResSum[i + 5] = fileResTmp3[j + 1];

		fileResSum[i + 6] = fileResTmp4[j];
		fileResSum[i + 7] = fileResTmp4[j + 1];
		j += 2;
	}

	string outPath = "./outFile.pcm";
	FILE* fp = fopen(outPath.c_str(), "wb+");
	fwrite(fileResSum, sizeof(char), fileSizeSum, fp);
	fclose(fp);

	if (fileResSum != NULL)
	{
		free(fileResSum);
		fileResSum = NULL;
	}

	if (fileResTmp1 != NULL)
	{
		free(fileResTmp1);
		fileSizeTmp1 = NULL;
	}
	if (fileResTmp2 != NULL)
	{
		free(fileResTmp2);
		fileResTmp2 = NULL;
	}
	if (fileResTmp3 != NULL)
	{
		free(fileResTmp3);
		fileResTmp3 = NULL;
	}
	if (fileResTmp4 != NULL)
	{
		free(fileResTmp4);
		fileSizeTmp4 = NULL;
	}

	return 0;
}

u32_t ClassAudioTool::readFile(string& filePath, char** pRes, u64_t& fileSize)
{
	char* tmp = NULL;
	FILE* inputHandle = NULL;
	inputHandle = fopen(filePath.c_str(), "r");
	if (inputHandle == NULL)
	{
		printf("open file failure\n");
		return AUDIO_OPEN_FILE_FAILURE;
	}

	u32_t resSize = 0;
	fseek(inputHandle, 0, SEEK_END);
	resSize = ftell(inputHandle);
	fseek(inputHandle, 0, SEEK_SET);

	tmp = (char*)malloc(resSize);
	memset(tmp, 0, resSize);
	fread(tmp, 1, resSize, inputHandle);
	fclose(inputHandle);
	inputHandle = NULL;
	*pRes = tmp;
	fileSize = resSize;
	return AUDIO_SUCCESS;
}
