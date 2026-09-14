#include "randomx-dataset/work.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--help") {
        std::cerr << "randomx-dataset [rounds]\n";
        return 0;
    }
    std::uint32_t rounds = 16;
    if (argc > 1) {
        rounds = static_cast<std::uint32_t>(std::stoul(argv[1]));
    }
    auto job = rxdataset::make_job(rxdataset::algo());
    auto n = rxdataset::bench(rounds);
    std::cout << "algo=" << rxdataset::algo() << " job=" << job.id << " rounds=" << n << "\n";
    return 0;
}
