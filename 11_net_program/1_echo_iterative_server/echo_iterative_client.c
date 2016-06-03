#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc, char **argv)
{
	if(argc < 4)
	{
		printf("error");
		exit(1);
	}

	int port = atoi(argv[2]);

	struct sockaddr_in client_addr;
	client_addr.sin_family = AF_INET;
	inet_aton(argv[1], &client_addr.sin_addr);
	client_addr.sin_port = htons(port);

	int clientfd = socket(AF_INET, SOCK_STREAM, 0);

	connect(clientfd, (struct sockaddr *)&client_addr, sizeof(client_addr));

	send(clientfd, "asdfasfdasdf", 12, 0);

	close(clientfd);

	return 0;
}

