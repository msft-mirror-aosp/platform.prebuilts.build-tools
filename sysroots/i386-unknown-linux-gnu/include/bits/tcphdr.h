/*
 * bionic's processed kernel headers (libc_uapi_headers) include <bits/tcphdr.h> in
 * place of a kernel definition, which the C library provides. glibc defines struct tcphdr in <netinet/tcp.h>.
 */
#pragma once

#include <netinet/tcp.h>
