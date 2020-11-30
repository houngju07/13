#include <stdio.h>
#include <stdlib.h>
#include <keywords.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int main(int argc, char *argv[]) {

	FILE* fp;
	char filename[100];
	char word[100];
	int cnt;
	
	//file open
	printf("input the file name : ");
	scanf("%s", filename);
	
	if((fp = fopen(filename, "r"))==NULL)
	{
		printf("input filename is invalid\n");
		return -1;
	}
	
	//bring word from fp
	while(fget_word(fp, word) != 0){	//bring a word
		count_word(word);
	}
	
	print_word();
	
	fclose(fp);
	
	
	return 0;
}
