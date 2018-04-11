#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void sendMsg(int sockfd,char *msg){
	send(sockfd,msg,strlen(msg),0);
}


void EchoServer(int cd){
	char buf[128] ;
	sendMsg(cd,"####################\n");
	sendMsg(cd," Simple echo server\n");
	sendMsg(cd,"####################\n");
	sendMsg(cd,"Enter exit to quit \n");
	while(1){
		memset(buf,0,128);
		sendMsg(cd,"Input:");
		recv(cd,buf,256,0);
		usleep(400000);
		if(!memcmp(buf,"exit",4)){
			sendMsg(cd,"goodbye~");
			return ;
		}	
		sendMsg(cd,"echo ");
		sendMsg(cd,buf);
	}

}


int main(){
	int sd ;
	struct sockaddr_in saddr ,caddr;
	setvbuf(stdout,0,2,0);
	sd = socket(AF_INET,SOCK_STREAM,0) ;
	if(sd == -1 ){
		printf("error");
		return -1 ;
	}
	saddr.sin_family = AF_INET ;
	saddr.sin_addr.s_addr = INADDR_ANY ;
	saddr.sin_port = htons(12543);
	int sock_opt = 1 ;
	setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,(void *)&sock_opt,sizeof(sock_opt));
	if(bind(sd,(struct sockaddr*)&saddr,sizeof(saddr)) < 0){
		printf("bind error");
		return -1 ;
	}
	listen(sd,20);	

	while(1){
		int cd ;
		int c = sizeof(struct sockaddr_in);
		int fpid ;
		cd = accept(sd,(struct sockaddr*)&caddr,(socklen_t*)&c) ;
				
		if(cd < 0 ){
			printf("accept error");
			return -1 ;
		}
		
		fpid = fork();
		if(fpid < 0){
			printf("fork error") ;
		}else if(fpid == 0){
			alarm(60);
			EchoServer(cd) ;
			close(cd);

			exit(0);
		}else{
		
		}	
	}
	close(sd);
	return 0 ;
}
