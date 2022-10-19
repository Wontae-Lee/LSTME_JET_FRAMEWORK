// Copyright (c) 2020 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "../../lstme/structures/array/array1.hpp"
#include "../../lstme/structures/vector/vector3.hpp"
#include <pystring/pystring.h>

inline bool readPositions(const std::string& filename,
                          lstme::Array1<lstme::Vector3D>& positions) {
    if (pystring::endswith(filename, ".xyz")) {
        std::ifstream xyzFile(filename.c_str());
        while (xyzFile) {
            lstme::Vector3D xyz;

            xyzFile >> xyz.x >> xyz.y >> xyz.z;

            if (xyzFile.fail() || xyzFile.eof()) {
                break;
            }

            positions.append(xyz);
        }

        xyzFile.close();
        return true;
    } else {
        std::ifstream posFile(filename.c_str(), std::ifstream::binary);
        if (posFile) {
            std::vector<uint8_t> buffer(
                (std::istreambuf_iterator<char>(posFile)),
                (std::istreambuf_iterator<char>()));
            deserialize(buffer, &positions);
            posFile.close();
            return true;
        } else {
            return false;
        }
    }
}
