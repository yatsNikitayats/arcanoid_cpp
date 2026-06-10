#include "Utils.h"

std::mt19937 gen(std::random_device{}());

int rnd(int l, int r) {
    std::uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}

