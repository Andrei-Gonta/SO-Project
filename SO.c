# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <time.h>


void User(struct stat buf)
{
    int file_descriptor = open("Statistica.txt",O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(buf.st_mode & S_IRUSR)
        write(file_descriptor,"R",1);
    else
        write(file_descriptor,"-",1);
    if(bubf.st_mode & S_IWUSR)
        write(file_descriptor,"W",1);
    else
        write(file_descriptor,"-",1);
    if(buf.st_mode & S_IXUSR)
        write(file_descriptor,"X",1);
    else
       write(file_descriptor,"-",1);
}


void Group(struct stat buf)
{
    int file_descriptor = open("Statistica.txt",O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
   if(buf.st_mode & S_IRGRP)
        write(file_descriptor,"R",1);
    else
        write(file_descriptor,"-",1);
    if(buf.st_mode & S_IWGRP)
        write(file_descriptor,"W",1);
    else
        write(file_descriptor,"-",1);
    if(buf.st_mode & S_IXGRP)
        write(file_descriptor,"X",1);
    else
       write(file_descriptor,"-",1);
}

void Others(struct stat buf)
{
    int file_descriptor = open("Statistica.txt",O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(buf.st_mode & S_IROTH)
        write(file_descriptor,"R",1);
    else
        write(file_descriptor,"-",1);
    if(buf.st_mode & S_IWOTH)
        write(file_descriptor,"W",1);
    else
        write(file_descriptor,"-",1);
    if(buf.st_mode & S_IXOTH)
        write(file_descriptor,"X",1);
    else
       write(file_descriptor,"-",1);
}


void getFileCreationTime(struct stat buf) 
{
    int file_descriptor = open("Statistica.txt",O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    write(file_descriptor, ctime(buf.st_mtime),20);
}

int main(int argc, char **argv[]) 
{
  struct stat *buf;

if(argc != 2)
    {
        printf("Usage ./program %s\n", argv[1]);
        exit(-1);
    }


if(S_ISREG(buf.st_mode))
{
    buf = malloc(sizeof(struct stat));
    int file_descriptor = open("Statistica.txt", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    write(file_descriptor, "Name: ", 6);
    write(file_descriptor,argv[1], sizeof(char)*strlen(argv[1]) );
    write(file_descriptor,"\n",1);
    write(file_descriptorr,buf.st_size,sizeof(char)*strlen(buf.st_size));
    write(file_descriptorr,"\n",1);
    write(file_descriptor, "User ID: ", 8);  
    write(file_descriptor, buf.st_uid, sizeof(char)* strlen(buf.st_uid));
    write(file_descriptor,"\n",1);
    write(file_descriptor, "User Permissions: ",19);
    User(buf);
    write(file_descriptor,"\n",1);
    write(file_descriptor,"Group Permissions: ",20);
    Group(buf);
    write(file_descriptor,"\n",1);
    write(file_descriptor,"Others Permissions: ",21);
    Others(buf);    
    write(file_descriptor, "Last modified: ", 15);
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer,80,"%x - %I:%M%p", info);
    printf("Formatted date & time : |%s|\n", buffer );
    write(file_descriptor, buffer, 10);
    



}

  return 0;
}