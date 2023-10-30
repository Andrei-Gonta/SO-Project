#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


void GROUP_PERMISSION(struct stat buf)
{
if(buf.stmode & S_IRWXG)
    printf("R-W-X");
 else
   if(buf.stmode & S_IRUSR)
     printf("R-0-0");

}


int main(int argc, char **argv[]) 
{
  struct stat *buf;
  buf = malloc(sizeof(struct stat));

  creat ("home/student/Andrei_SO/SO-Project/statistici.txt", S_IWUSR | S_IRUSR  );
 

  
  if(argc!=2)
    {
      printf("Usage ./program<fisier_intrare> \n");
      exit -1;
    }
  else
    {
      if(open(argv[1],O_RDONLY)==-1)
	printf("Eroare la deschidere");
	exit -1;
	else
	  {
	    if(lstat(argv[1],buf)==-1)
	      {
		printf("eroare");
		exit-1;
	      }
	    else
	      {
		if(S_ISREG(buf.st_mode))
		  {
		    printf("ESTE FISIER");
		  }
		else
		  {
		    printf("GROUP: \n")'
		    
		      

		     
		  }
	       
	      }
	    
	  }
	
    }
  
  return 0;
}
