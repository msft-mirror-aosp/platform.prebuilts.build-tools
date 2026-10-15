/*
 * bionic's processed kernel headers (libc_uapi_headers) include <bits/epoll_event.h>
 * in place of a kernel definition, which the C library provides. glibc defines
 * struct epoll_event in <sys/epoll.h>, whose macros clash with <linux/eventpoll.h>'s;
 * like musl, this defines nothing.
 */
#pragma once
