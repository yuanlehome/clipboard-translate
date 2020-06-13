#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int keys_fd;
    struct input_event t;
    keys_fd = open("/dev/input/event2", O_RDONLY);
    if(keys_fd <= 0)
    {
        printf("open /dev/input/event2 error!\n");
        return -1;
    }
    while(1)
    {
        read(keys_fd, &t, sizeof(struct input_event));
        if(t.type == 1)
		{
			if(t.value == 0)
				system("~/Translator/goTranslate.sh");
		}
    }
    close(keys_fd);
    return 0;
}

