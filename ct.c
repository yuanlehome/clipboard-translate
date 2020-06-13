#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
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
        read(keys_fd, &t, sizeof(t));
        if(t.type == EV_KEY)
		{
			if(t.code == BTN_LEFT)
			{
				if(t.value == MSC_SERIAL)
				{
					system("~/Translator/goTranslate");
				}
			}
		}
    }
    close(keys_fd);
    return 0;
}
