
/*Mohammad Abuzar SP19-BCS-089 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void *socket_t(void *arg);
int sockfd, newsockfd, portno;
    socklen_t clilen;
    char c;
    struct sockaddr_in serv_addr, cli_addr;
    int n;

int main(int argc , char *argv[])


{

int thread=0 ;
pthread_t id;

//thread=pthread_create(&id, NULL, socket , NULL);

    if (argc < 2) {
         fprintf(stderr, "ERROR, no port provided\n");
         exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
         error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = portno; 
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
  //  int pid;
    while (1) 
    {
         newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
         if (newsockfd < 0)
                error("ERROR on accept");
	    if( pthread_create( &id , NULL ,  socket_t , (void*)&newsockfd) < 0)
        {
            perror("could not create thread");
            return 1;
        }
  
	pthread_join(id,NULL);    
    } 


return 0;	
    }
   



void *socket_t(void *arg)
{


	newsockfd=*(int*) arg;
  
         
	   
	    
	    {
		    n = read(newsockfd, &c, 1);
		    if (n < 0)
		        error("ERROR reading from socket");
		    printf("I got: %c from client\n", c);
		    ++c;
		    n = write(newsockfd, &c, 1);
		    if (n < 0)
		         error("ERROR writing to socket");
	    } while (--c != 'Q');
            close(newsockfd);
	    return 0;
	    
	    











}




















