#include <stdio.h>
#include <stdlib.h>
#include  <assert.h>
#include <string.h>

// 统计单词，字符数量的函数 
int Count(FILE* file, int* cNum, int* wNum) {
	int flag = 0;//0代表前面一个字符为空格或逗号 
	char temp;
//	挨个读取文件字符 ，统计字符和单词数量 
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
//		-w 打印单词数目 
		if (strcmp(argv[i], "-w")== 0){
			printf("单词数目 %d\n", wNum);
		} else if (strcmp(argv[i], "-c") == 0){
//		-c 打印字符 
			printf("字符数目 %d\n", cNum);
		}
	} 
		
	fclose(file);
	
	return 0;
}

