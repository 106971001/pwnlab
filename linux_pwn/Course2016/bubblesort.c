#include <stdio.h>

int main(){
	unsigned int n,i,j ;
	unsigned int tmp ;
	unsigned int buf[8];
	while(1){
		puts("How many numbers do you have ?");
		fflush(stdout);
		scanf("%u",&n);
		for(i = 0 ; i < n ; i++){
			printf("Enter the %d number : ",i);
			fflush(stdout);
			scanf("%u",&buf[i]);
		}
		puts("Processing......");
		fflush(stdout);
		sleep(1);
		for(i = n ; i > 0 ; i--){
			for( j = 0 ; j < i ; j++){
				if(buf[j] > buf[j+1]){
					tmp = buf[j] ;
					buf[j] = buf[j+1];
					buf[j+1] = tmp ;
				}
			}	
		}
		
		puts("Result :");
		fflush(stdout);
		for(i = 0 ; i < n ; i++){
			printf("%u ",buf[i]);
		}
		puts("");
		puts("Continue (yes:1,no:0) ?");
		fflush(stdout);
		scanf("%u",&tmp);
		if(tmp != 1){
			puts("Thank you ~");
			fflush(stdout);
			break ;
		}

	}

	return 0 ;
}
