#if !defined __AARCH64EB__
# include <gnu/stubs-lp64.h>
#endif
#if defined __AARCH64EB__
# include <gnu/stubs-lp64_be.h>
#endif
