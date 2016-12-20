 #include <stdio.h>
  #include <unistd.h>
  #include <sys/stat.h>
  #include <sys/types.h>
  #include <fcntl.h>

  void main()
  {
      int fd;
      char buf[1000];
      ssize_t num_bytes;

      fd = open("/coda/testserver.coda.cs.cmu.edu/playground/zhuoc/file", O_WRONLY);
      if (fd == -1) {
          printf("open error\n");
      }

      strcpy(buf, "Overwrite");
      while (1) {
        num_bytes = read(fd, buf, sizeof(buf));
        fprintf(stderr, "Number of bytes read=%ld\n", num_bytes);
        if (num_bytes != sizeof(buf))
            break;
      }

      close(fd);
  }
