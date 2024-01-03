#include "../template.h"
#include "sort.h"

#undef T
#define T int32_t
#include "sort.template.c"

#undef T
#define T float
#include "sort.template.c"

#undef T
#define T double
#include "sort.template.c"

#undef T
#define T void_ptr
#include "sort.template.c"
