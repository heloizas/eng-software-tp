#include "../external/utest.h"
#include <stdexcept>

UTEST(foo, bar) {
  ASSERT_TRUE(1);
}

UTEST_MAIN();