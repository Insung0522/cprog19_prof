#include<stdio.h>


int main()
{
	char fname[100] = "time.log";
	FILE* fp;
	int min, sec;
	int aver=0,aver_min,aver_sec;
	int max = 0,max_min,max_sec;
	int num = 0;
	int time = 0;

	fp = fopen(fname, "r");
	
	if (fp == NULL) {
		printf("Failed to open file\n");
		return 0;
	}

	while(!feof(fp)) {
		fscanf(fp, "(%d:%d)\n", &min, &sec);
		printf("min = %d, sec = %d\n", min, sec);
		time = (min*60) + sec;
		aver = aver + time; num++;
		max = max < time ? time : max;
		// get min, max, avg access time 

	}
	aver = aver/num;
	aver_min = aver/60; aver_sec = aver % 60;
	max_min = max/60; max_sec = max % 60;
	printf("평균 : %d:%d\n최대값 : %d:%d\n", aver_min, aver_sec, max_min, max_sec);
	return 0;
}

