/*
 * bionic's processed kernel headers (libc_uapi_headers) replace the kernel's
 * struct __kernel_sockaddr_storage with <bits/sockaddr_storage.h>, which the C
 * library provides. glibc defines struct sockaddr_storage in <sys/socket.h>.
 */
#pragma once

#include <sys/socket.h>
