/*
 * bionic's processed kernel headers (libc_uapi_headers) include <bits/flock.h>
 * in place of a kernel definition, which the C library provides. glibc defines
 * struct flock in <fcntl.h>, whose macros clash with <linux/fcntl.h>'s;
 * like musl, this defines nothing.
 */
#pragma once
