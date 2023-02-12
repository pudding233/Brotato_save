#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int copyFile(char* fileRead, char* fileWrite);
int main() {
	char fileRead[100];  // 要复制的文件名
	char fileWrite[100];  // 复制后的文件名
	// 获取用户输入
	printf("要复制的文件(也可填写简码)：");
	scanf("%s", fileRead);

	if (0==strcmp(fileRead, "233"))
		strcpy(fileRead, "C:\\Users\\Pudding233\\AppData\\Roaming\\Brotato\\76561198048887175\\save.json");
		//转义字符的问题研究了半天,一开始还没注意到
	else
		if (0 == strcmp(fileRead, "2233"))
		{
			strcpy(fileRead, "D:\\Brotato\\save.json");
		}
	printf("复制目录为:%s \n", fileRead);

	printf("将文件复制到(也可填写简码)：");
	scanf("%s", fileWrite);
	if (0==strcmp("233", fileWrite))
		strcpy(fileWrite, "D:\\Brotato\\save.json");
	else
		if (0 == strcmp(fileWrite, "2233"))
		{
			strcpy(fileWrite, "C:\\Users\\Pudding233\\AppData\\Roaming\\Brotato\\76561198048887175\\save.json");
		}
	printf("粘贴目录为:%s \n", fileWrite);

	// 进行复制操作
	if (copyFile(fileRead, fileWrite)) {
		printf("恭喜你，文件复制成功！\n");
	}
	else {
		printf("文件复制失败！\n");
	}
	_getch();
	return 0;
}
/**
* 拼接的代码(x
* 文件复制函数
* @param fileRead 要复制的文件
* @param fileWrite 复制后文件的保存路径
* @return int 1: 复制成功；2: 复制失败
**/
int copyFile(char* fileRead, char* fileWrite) {
	FILE* fpRead;  // 指向要复制的文件
	FILE* fpWrite;  // 指向复制后的文件
	int bufferLen = 1024 * 4;  // 缓冲区长度
	char* buffer = (char*)malloc(bufferLen);  // 开辟缓存
	int readCount;  // 实际读取的字节数
	if ((fpRead = fopen(fileRead, "rb")) == NULL || (fpWrite = fopen(fileWrite, "wb")) == NULL) {
		printf("Cannot open file, press any key to exit!操作失败\n");
		_getch();
		exit(1);
	}
	// 不断从fileRead读取内容，放在缓冲区，再将缓冲区的内容写入fileWrite
	while ((readCount = fread(buffer, 1, bufferLen, fpRead)) > 0) {
		fwrite(buffer, readCount, 1, fpWrite);
	}
	free(buffer);
	fclose(fpRead);
	fclose(fpWrite);
	return 1;
}