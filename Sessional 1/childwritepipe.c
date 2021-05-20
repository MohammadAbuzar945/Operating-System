/*Sir Nadeem Gafoor Exact Code */
/*Mohammad Abuzar SP19-BCS-089 */

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
   pid_t childpid;  
   int fd[2]; 
    
   if (pipe(fd) == -1) {
      perror("Failed to create the pipe"); 
      return 1; 
   } 
   childpid = fork();
   if (childpid == -1) {
      perror("Failed to fork"); 
      return 1;
   }
   if (childpid)
   {
   	if (dup2(fd[0], STDIN_FILENO) == -1)
	      perror("Failed to redirect standard input");
	close(fd[0]); close(fd[1]);
	execl ("/usr/bin/grep","grep", "m",NULL);
      	return 1;   
   }
   else
   {
   	if (dup2(fd[1], STDOUT_FILENO) == -1) 
	      perror("Failed to redirect standard output");
	close(fd[0]); close(fd[1]);
	execl ("/usr/bin/ls","ls", NULL);
      	return 1;
   }
}
