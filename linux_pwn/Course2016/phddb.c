#include <stdio.h>

struct phd{
	char name[20];
	int age ;
	int length ;
	char *thesis ;
};

struct phd *phdlist[100] ;
int phdconut = 0 ;

void menu(){
	puts("");
	puts("|----------PHDdb Menu----------|");
	puts("1.dump a phd profile");
	puts("2.add a phd profile");
	puts("3.edit a phd profile");
	puts("4.remove a phd profile");
	puts("5.exit");
	puts("|------------------------------|");
	printf("Your choice:");
	fflush(stdout);
}

int addphd(){
	puts("");
	struct phd *stu = NULL ;
	int size ;
	int index ;
	char intbuf[10] ;
	if(phdconut < 100){
		puts("*****add a phd profile*****");
		stu = malloc(sizeof(struct phd));
		printf("Enter the phd's name (length < 16) : ");
		fflush(stdout);
		scanf("%15s",stu->name);
		fflush(stdout);
		printf("Enter the phd's age : ");
		fflush(stdout);
		read(0,intbuf,8);
		stu->age = atoi(intbuf);
		printf("Enter the length of the phd's thesis : ");
		fflush(stdout);
		read(0,intbuf,8);
		size = atoi(intbuf);
		if(size <= 0){
			puts("Invalid size");
			free(stu);
			return 0;
		}
		stu->length = size ;
		stu->thesis =(char*)malloc(size);
		printf("Enter the content of the phs's thesis : ");
		fflush(stdout);
		read(0,stu->thesis,size);
		for(index = 0 ; index <= 100 ; index++){
			if(!phdlist[index]){
				phdlist[index] = stu;
				break ;
			}
		}
		phdconut++;
		puts("Successful!!");
	}else{
		puts("The PHDdb is full");
		return 0;
	}
	return 1 ;
}

int dumpphd(){
	char intbuf[10];
	int index ;
	puts("");
	puts("*****dump the phd profile*****");
	fflush(stdout);
	if(!phdconut){
		puts("No phd profile in the db");
		return 0 ;
	}else{
		printf("Enter the index of phd's profile :");
		fflush(stdout);
		read(0,intbuf,8);
		index = atoi(intbuf);
		if(index >= 100 || index < 0 || !phdlist[index]){
			puts("Invalid index");
			return 0 ;
		}else{
			printf("name:%s\nage:%d\n",(phdlist[index])->name,(phdlist[index])->age);
			fflush(stdout);
			printf("thesis:\n%s",(phdlist[index])->thesis);
			fflush(stdout);
			return 1 ;
		}
		
	}
}

int editphd(){
	char intbuf[10];
	int index ;
	int oldsize ;
	int size ;
	char *thesis ;
	puts("");
	puts("*****edit a phd profile*****");
	if(!phdconut){
		puts("No phd's profile in the db");
		return 0;
	}else{
		printf("Enter the index of phd's profile : ");
		fflush(stdout);
		read(0,intbuf,8);
		index = atoi(intbuf);
		if(index >= 100 || index < 0 || !phdlist[index]){
			puts("Invalid index");
			return 0 ;
		}else{
			printf("Enter the phd's name (length < 16) : ");
			fflush(stdout);
			scanf("%15s",(phdlist[index])->name);
			printf("Enter the phd's age : ");
			fflush(stdout);
			read(0,intbuf,8);
			(phdlist[index])->age = atoi(intbuf);
			printf("Enter the length of phd's thesis : ");
			fflush(stdout);
			read(0,intbuf,8);
			size = atoi(intbuf);
			oldsize = (phdlist[index])->length ;
			if(size != oldsize){
				if((thesis = realloc((phdlist[index])->thesis,size)) == NULL){
					puts("Invalid length"); 
					fflush(stdout);
					return 0;
				}
			}else{
				thesis = (phdlist[index])->thesis ;
			}
			printf("Enter the content of phd's thesis : ");
			fflush(stdout);
			read(0,thesis,size);
			(phdlist[index])->thesis = thesis ;
			(phdlist[index])->length = size ;
			return 1 ;
		}
	}

}

int removephd(){
	char intbuf[10] ;
	int index ;
	puts("");
	puts("*****remove the phd's profile*****");
	if(!phdconut){
		puts("No phd's profile in the db");
		return 0 ;
	}else{
		printf("Enter the index of phd's profile : ");
		fflush(stdout);
		read(0,intbuf,8);
		index = atoi(intbuf);
		if(index >= 100 || index < 0 || !phdlist[index]){
			puts("Invalid index");
			return 0 ;
		}
		free((phdlist[index])->thesis) ;
		free(phdlist[index]);
		phdlist[index] = NULL ;
		phdconut-- ;
		puts("Successful!!");
		return 1 ;
	}

}

int main(void){
	int choice ;
	char choicebuf[10];

	while(1){
		menu();
		read(0,choicebuf,8);
		choice = atoi(choicebuf);
		switch(choice){
			case 1:
				dumpphd();
				break ;
			case 2 :
				addphd();
				break ;
			case 3 :
				editphd();
				break ;
			case 4 :
				removephd() ;
				break ;
			case 5 :
				puts("See Your next time!!");
				puts("Nerver give up!!");
				fflush(stdout);
				exit(0);
				break ;
			default :
				puts("Invalid choice");
				fflush(stdout);
				break ;
		}

	}
	return 0 ;
}

