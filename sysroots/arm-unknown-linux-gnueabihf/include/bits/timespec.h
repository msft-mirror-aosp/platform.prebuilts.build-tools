/*
 * bionic's processed kernel headers (libc_uapi_headers) include <bits/timespec.h> in
 * place of a kernel definition, which the C library provides. glibc defines struct timespec here.
 */
#pragma once

#include <bits/types/struct_timespec.h>
