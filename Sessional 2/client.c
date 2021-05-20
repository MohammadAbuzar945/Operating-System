//Sir Chaudhary Nadeem Ghafoor's Excat code. 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}
  // use netstat -tp
int main(int argc, char *argv[])
{
    char c;
    int sockfd, portno, n, term_con = 0;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = portno; // htons(portno);
    //printf("h_addr: %s\n", inet_ntoa(serv_addr.sin_addr));
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    while(1)
    {
	    printf("Please enter a single char: ");

	    c = (char)getc(stdin);
	    getc(stdin);
	    n = write(sockfd,&c,1);
	    if (n < 0) 
		 error("ERROR writing to socket");
	    if ( c == 'Q')
	    {
		close(sockfd);
		return 0;
	    }
	    n = read(sockfd,&c,1);
	    if (n < 0) 
		 error("ERROR reading from socket");
	    printf("I got %c  from server\n",c);
    }
}

© 2021 GitHub, Inc.