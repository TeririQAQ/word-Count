#include <stdio.h>
#include <stdlib.h>
#include  <assert.h>
#include <string.h>

// ͳ�Ƶ��ʣ��ַ������ĺ��� 
int Count(FILE* file, int* cNum, int* wNum) {
	int flag = 0;//0����ǰ��һ���ַ�Ϊ�ո�򶺺� 
	char temp;
//	������ȡ�ļ��ַ� ��ͳ���ַ��͵������� 
	while ((temp = fgetc(file)) != EOF){
		(*cNum)++;
		if (flag == 0 && (temp != ' ' || temp != ',')) {
			(*wNum)++;
			flag = 1;
		}
		else if (temp == ' ' || temp == ','){
			flag = 0;
		}
	}
	
	return 0;
}

int main(int argc, char* argv[]){
	int cNum = 0, wNum = 0, i;
	FILE* file;	
	file = fopen(argv[argc-1], "r");
	
	if (file == NULL){
		printf("can not open the file\n");
		return 0;
	}
	
	Count(file, &cNum, &wNum);
	for(i=0; i<argc-1; i++){
//		-w ��ӡ������Ŀ 
		if (strcmp(argv[i], "-w")== 0){
			printf("������Ŀ %d\n", wNum);
		} else if (strcmp(argv[i], "-c") == 0){
//		-c ��ӡ�ַ� 
			printf("�ַ���Ŀ %d\n", cNum);
		}
	} 
		
	fclose(file);
	
	return 0;
}

