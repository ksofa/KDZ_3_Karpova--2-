#include <fstream>
#include "writer.h"

void writeInfo(std::ofstream &file, const std::string &name, int64_t sum, int edgesAmount, int ribsAmount) {

    file << name << ";"
         << sum << ";"
         << edgesAmount << ";"
         << ribsAmount << "\n";
}