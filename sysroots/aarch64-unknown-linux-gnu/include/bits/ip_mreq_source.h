/*
 * bionic's processed kernel headers (libc_uapi_headers) include <bits/ip_mreq_source.h> in
 * place of a kernel definition, which the C library provides. glibc defines struct ip_mreq_source in <netinet/in.h>.
 */
#pragma once

#include <netinet/in.h>
