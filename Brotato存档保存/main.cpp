#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int copyFile(char* fileRead, char* fileWrite);
int main() {
	char fileRead[100];  // Ҫ���Ƶ��ļ���
	char fileWrite[100];  // ���ƺ���ļ���
	// ��ȡ�û�����
	printf("Ҫ���Ƶ��ļ�(Ҳ����д����)��");
	scanf("%s", fileRead);

	if (0==strcmp(fileRead, "233"))
		strcpy(fileRead, "C:\\Users\\Pudding233\\AppData\\Roaming\\Brotato\\76561198048887175\\save.json");
		//ת���ַ��������о��˰���,һ��ʼ��ûע�⵽
	else
		if (0 == strcmp(fileRead, "2233"))
		{
			strcpy(fileRead, "D:\\Brotato\\save.json");
		}
	printf("����Ŀ¼Ϊ:%s \n", fileRead);

	printf("���ļ����Ƶ�(Ҳ����д����)��");
	scanf("%s", fileWrite);
	if (0==strcmp("233", fileWrite))
		strcpy(fileWrite, "D:\\Brotato\\save.json");
	else
		if (0 == strcmp(fileWrite, "2233"))
		{
			strcpy(fileWrite, "C:\\Users\\Pudding233\\AppData\\Roaming\\Brotato\\76561198048887175\\save.json");
		}
	printf("ճ��Ŀ¼Ϊ:%s \n", fileWrite);

	// ���и��Ʋ���
	if (copyFile(fileRead, fileWrite)) {
		printf("��ϲ�㣬�ļ����Ƴɹ���\n");
	}
	else {
		printf("�ļ�����ʧ�ܣ�\n");
	}
	_getch();
	return 0;
}
/**
* ƴ�ӵĴ���(x
* �ļ����ƺ���
* @param fileRead Ҫ���Ƶ��ļ�
* @param fileWrite ���ƺ��ļ��ı���·��
* @return int 1: ���Ƴɹ���2: ����ʧ��
**/
int copyFile(char* fileRead, char* fileWrite) {
	FILE* fpRead;  // ָ��Ҫ���Ƶ��ļ�
	FILE* fpWrite;  // ָ���ƺ���ļ�
	int bufferLen = 1024 * 4;  // ����������
	char* buffer = (char*)malloc(bufferLen);  // ���ٻ���
	int readCount;  // ʵ�ʶ�ȡ���ֽ���
	if ((fpRead = fopen(fileRead, "rb")) == NULL || (fpWrite = fopen(fileWrite, "wb")) == NULL) {
		printf("Cannot open file, press any key to exit!����ʧ��\n");
		_getch();
		exit(1);
	}
	// ���ϴ�fileRead��ȡ���ݣ����ڻ��������ٽ�������������д��fileWrite
	while ((readCount = fread(buffer, 1, bufferLen, fpRead)) > 0) {
		fwrite(buffer, readCount, 1, fpWrite);
	}
	free(buffer);
	fclose(fpRead);
	fclose(fpWrite);
	return 1;
}