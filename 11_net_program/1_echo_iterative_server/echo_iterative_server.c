#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>



int main(int argc, char **argv)
{
	if(argc < 3)
	{
		printf("error\n");
		exit(1);
	}
	
	//int listen_ip = atoi(argv[1]);
	int listen_port = atoi(argv[2]);
	
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	inet_aton(argv[1], &server_addr.sin_addr);
	server_addr.sin_port = htons(listen_port);
	int server_addr_length = sizeof(server_addr);

	bind(listenfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(listenfd, 3);


	struct sockaddr_in client_addr;
	int client_addr_length = sizeof(client_addr);
	
	int connfd;
	char buf[255];

	while(1)
	{
		connfd = accept(listenfd, (struct sockaddr *)&client_addr, &client_addr_length);
		
		memset(buf, '\0', sizeof(buf));
		recv(connfd, buf, 255, 0);
		printf("data:%s\n", buf);

		close(connfd);
	}
	exit(0);
}
