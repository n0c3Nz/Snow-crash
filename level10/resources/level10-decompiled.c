
int main(int argc,char **argv)

{
  uint16_t port;
  int stat_fd;
  int file_fd;
  ssize_t write_bytes_len;
  size_t read_bytes_len;
  int *piVar1;
  int in_GS_OFFSET;
  char *argv1;
  char *file;
  char *host;
  int fd;
  int ffd;
  int rc;
  char buffer [4096];
  sockaddr_in sin;
  undefined1 fileToRead [4096];
  sockaddr servaddr;
  int local_14;
  char *filePath;
  char *remoteHost;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (argc < 3) {
    printf("%s file host\n\tsends file to host if you have access to it\n",*(undefined4 *)argv1);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  filePath = *(char **)(argv1 + 4);
  remoteHost = *(char **)(argv1 + 8);
  stat_fd = access(*(char **)(argv1 + 4),4);
  if (stat_fd == 0) {
    printf("Connecting to %s:6969 .. ",remoteHost);
    fflush(stdout);
    stat_fd = socket(2,1,0);
    servaddr.sa_data[2] = '\0';
    servaddr.sa_data[3] = '\0';
    servaddr.sa_data[4] = '\0';
    servaddr.sa_data[5] = '\0';
    servaddr.sa_data[6] = '\0';
    servaddr.sa_data[7] = '\0';
    servaddr.sa_data[8] = '\0';
    servaddr.sa_data[9] = '\0';
    servaddr.sa_data[10] = '\0';
    servaddr.sa_data[0xb] = '\0';
    servaddr.sa_data[0xc] = '\0';
    servaddr.sa_data[0xd] = '\0';
    servaddr.sa_family = 2;
    servaddr.sa_data[0] = '\0';
    servaddr.sa_data[1] = '\0';
    servaddr.sa_data._2_4_ = inet_addr(remoteHost);
    port = htons(0x1b39);
    servaddr.sa_data._0_2_ = port;
    file_fd = connect(stat_fd,&servaddr,0x10);
    if (file_fd == -1) {
      printf("Unable to connect to host %s\n",remoteHost);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    write_bytes_len = write(stat_fd,".*( )*.\n",8);
    if (write_bytes_len == -1) {
      printf("Unable to write banner to host %s\n",remoteHost);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    printf("Connected!\nSending file .. ");
    fflush(stdout);
    file_fd = open(filePath,0);
    if (file_fd == -1) {
      puts("Damn. Unable to open file");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    read_bytes_len = read(file_fd,fileToRead,4096);
    if (read_bytes_len == 0xffffffff) {
      piVar1 = __errno_location();
      filePath = strerror(*piVar1);
      printf("Unable to read from file: %s\n",filePath);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    write(stat_fd,fileToRead,read_bytes_len);
    stat_fd = puts("wrote file!");
  }
  else {
    stat_fd = printf("You don\'t have access to %s\n ",filePath);
  }
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return stat_fd;
}

