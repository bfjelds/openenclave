//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <vector>

// size_type max_size() const;

#include <cassert>
#include <limits>
#include <type_traits>
#include <vector>

#include "test_allocator.h"
#include "test_macros.h"


int main() {
  {
    typedef limited_allocator<int, 10> A;
    typedef std::vector<int, A> C;
    C c;
    assert(c.max_size() <= 10);
    LIBCPP_ASSERT(c.max_size() == 10);
  }
  {
    typedef limited_allocator<int, (size_t)-1> A;
    typedef std::vector<int, A> C;
    const C::difference_type max_dist =
        std::numeric_limits<C::difference_type>::max();
    C c;
    assert(c.max_size() <= max_dist);
    LIBCPP_ASSERT(c.max_size() == max_dist);
  }
  {
    typedef std::vector<char> C;
    const C::difference_type max_dist =
        std::numeric_limits<C::difference_type>::max();
    C c;
    assert(c.max_size() <= max_dist);
    assert(c.max_size() <= alloc_max_size(c.get_allocator()));
  }
}
