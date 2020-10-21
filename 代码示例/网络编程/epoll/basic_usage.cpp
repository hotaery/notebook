#include <sys/epoll.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

void processIn(struct epoll_event* event) {
    char c;
    int n = read(event->data.fd, &c, 1);
    printf("get char: %c\n", c);
    return;
}

int main() {
    int epfd = epoll_create(32);
    if (epfd < 0) {
        fprintf(stderr, "epoll_create failed[%s]\n", strerror(errno));
        return -1;
    }

    struct epoll_event event;
    event.events |= EPOLLIN;
    event.events |= EPOLLET; //是否打开ET
    event.data.fd = STDIN_FILENO;
    if (epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event) < 0) {
        fprintf(stderr, "epoll_ctl failed[%s]\n", strerror(errno));
        return -1;
    }

    while (true) {
        struct epoll_event events[2];
        int n = epoll_wait(epfd, events, 2, -1);
        if (n < 0) {
            fprintf(stderr, "epoll_wait failed[%s]\n", strerror(errno));
            return -1;
        }
        for (int i = 0; i < n; ++i) {
            if (events[i].events & EPOLLIN) {
                // 根据是否是ET程序有不同的表现：
                //  - LT下，标准输入输入数据时终端将会不停打印get char
                //  - ET下，由于缓冲区没有仅仅是数据在累加，但是没有发生
                //    状态变化，因此只会输出一行get char
                printf("get char\n");
            }
        }
    }
}