/*
 * bionic's processed kernel headers (libc_uapi_headers) include <bits/in_addr.h> in
 * place of a kernel definition, which the C library provides. glibc defines struct in_addr in <netinet/in.h>.
 */
#pragma once

#include <netinet/in.h>
