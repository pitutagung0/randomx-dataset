#include "randomx-dataset/work.h"

#include <cstdlib>
#include <iostream>

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "fail: " #cond " (" << __FILE__ << ":" << __LINE__  \
                      << ")\n";                                              \
            return 1;                                                        \
        }                                                                    \
    } while (0)

int main() {
    auto a = rxdataset::make_job("pool");
    auto b = rxdataset::make_job("pool");
    CHECK(a.id == b.id);
    CHECK(rxdataset::hash_nonce(a, 1) != rxdataset::hash_nonce(a, 2));
    CHECK(rxdataset::bench(8) == 8);
    CHECK(rxdataset::algo() != nullptr);
    std::cout << "ok\n";
    return 0;
}
