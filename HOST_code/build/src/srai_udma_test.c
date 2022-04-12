#include        <stdio.h>
#include        <fcntl.h>
#include        <string.h>
#include        <sys/types.h>
#include        <sys/mman.h>

int check_buf(unsigned char* buf, unsigned int size)
{
    int i;
    int error_count = 0;
    for(i = 0; i < size; i++) {
        buf[i] = (char)i;
    }
    for(i = 0; i < size; i++) {
        if (buf[i] != (char)i) {
         error_count++;
        }
    }
    return error_count;
}

int clear_buf(unsigned char* buf, unsigned int size)
{
    int error_count = 0;
    memset((void*)buf, 0, size);
    return error_count;
}

void check_buf_test(unsigned int size, unsigned int sync_mode, int o_sync)
{
    int            fd;
    unsigned char  attr[1024];
    struct timeval start_time, end_time;
    int            error_count;
    unsigned char* buf;

    if ((fd  = open("/sys/class/udmabuf/udmabuf0/sync_mode", O_WRONLY)) != -1) {
      sprintf(attr, "%d", sync_mode);
      write(fd, attr, strlen(attr));
      close(fd);
    }

    printf("sync_mode=%d, O_SYNC=%d, ", sync_mode, (o_sync)?1:0);

    if ((fd  = open("/dev/udmabuf0", O_RDWR | o_sync)) != -1) {
      buf = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
      printf ("SRAI__DBG :: Virtual Address = %x\n", buf);
      error_count = check_buf(buf, size);
      close(fd);
    }
}

void clear_buf_test(unsigned int size, unsigned int sync_mode, int o_sync)
{
    int            fd;
    unsigned char  attr[1024];
    struct timeval start_time, end_time;
    int            error_count;
    unsigned char* buf;

    if ((fd  = open("/sys/class/udmabuf/udmabuf0/sync_mode", O_WRONLY)) != -1) {
      sprintf(attr, "%d", sync_mode);
      write(fd, attr, strlen(attr));
      close(fd);
    }

    printf("sync_mode=%d, O_SYNC=%d, ", sync_mode, (o_sync)?1:0);

    if ((fd  = open("/dev/udmabuf0", O_RDWR | o_sync)) != -1) {
      buf = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
      error_count = clear_buf(buf, size);
      close(fd);
    }
}

void main()
{
    int            fd;
    unsigned char  attr[1024];
    unsigned char* buf;
    unsigned int   buf_size;
    unsigned long  phys_addr;
    unsigned long  debug_vma = 0;
    unsigned long  sync_mode = 2;
    int            error_count;
    struct timeval start_time, end_time;

    if ((fd  = open("/sys/class/udmabuf/udmabuf0/phys_addr", O_RDONLY)) != -1) {
      read(fd, attr, 1024);
      sscanf(attr, "%x", &phys_addr);
      close(fd);
    }

    if ((fd  = open("/sys/class/udmabuf/udmabuf0/size"     , O_RDONLY)) != -1) {
      read(fd, attr, 1024);
      sscanf(attr, "%d", &buf_size);
      close(fd);
    }

    if ((fd  = open("/sys/class/udmabuf/udmabuf0/sync_mode", O_WRONLY)) != -1) {
      sprintf(attr, "%d", sync_mode);
      write(fd, attr, strlen(attr));
      close(fd);
    }

    if ((fd  = open("/sys/class/udmabuf/udmabuf0/debug_vma", O_WRONLY)) != -1) {
      sprintf(attr, "%d", debug_vma);
      write(fd, attr, strlen(attr));
      close(fd);
    }

    printf("phys_addr=0x%x\n", phys_addr);
    printf("size=%d\n", buf_size);

    if ((fd  = open("/dev/udmabuf0", O_RDWR)) != -1) {
      long last_pos = lseek(fd, 0, 2);
      if (last_pos == -1) {
        printf("lseek error\n");
        exit(-1);
      }
      close(fd);
    }

    printf("check_buf()\n", buf_size);
    check_buf_test(buf_size, 0, 0);
    check_buf_test(buf_size, 0, O_SYNC);
    check_buf_test(buf_size, 1, 0);
    check_buf_test(buf_size, 1, O_SYNC);
    check_buf_test(buf_size, 2, 0);
    check_buf_test(buf_size, 2, O_SYNC);
    check_buf_test(buf_size, 3, 0);
    check_buf_test(buf_size, 3, O_SYNC);
    check_buf_test(buf_size, 4, 0);
    check_buf_test(buf_size, 4, O_SYNC);
    check_buf_test(buf_size, 5, 0);
    check_buf_test(buf_size, 5, O_SYNC);
    check_buf_test(buf_size, 6, 0);
    check_buf_test(buf_size, 6, O_SYNC);
    check_buf_test(buf_size, 7, 0);
    check_buf_test(buf_size, 7, O_SYNC);

    printf("clear_buf()\n", buf_size);
    clear_buf_test(buf_size, 0, 0);
    clear_buf_test(buf_size, 0, O_SYNC);
    clear_buf_test(buf_size, 1, 0);
    clear_buf_test(buf_size, 1, O_SYNC);
    clear_buf_test(buf_size, 2, 0);
    clear_buf_test(buf_size, 2, O_SYNC);
    clear_buf_test(buf_size, 3, 0);
    clear_buf_test(buf_size, 3, O_SYNC);
    clear_buf_test(buf_size, 4, 0);
    clear_buf_test(buf_size, 4, O_SYNC);
    clear_buf_test(buf_size, 5, 0);
    clear_buf_test(buf_size, 5, O_SYNC);
    clear_buf_test(buf_size, 6, 0);
    clear_buf_test(buf_size, 6, O_SYNC);
    clear_buf_test(buf_size, 7, 0);
    clear_buf_test(buf_size, 7, O_SYNC);
    printf("\n.. Test Done \n", buf_size);
}
