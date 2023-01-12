#!/usr/bin/env python

"""
Copyright (c) 2018 Doyub Kim

I am making my contributions/submissions to this project solely in my personal
capacity and am not conveying any rights to any intellectual property of any
third parties.
"""

import inspect
import os
import utils

dirname = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))


def main():
    include_dir = os.path.join(dirname, "../include/jet")
    filenames = utils.get_all_files(include_dir, ["*.h"])
    filenames.sort()
    header = os.path.join(dirname, "../include/jet/jet.h")

    with open(header, "w") as header_file:
        header_file.write("""/* Copyright (c) 2023 Wontae Lee
*
* Reference: Fluid Engine Development. 2018. Doyub Kim
* License: MIT License
*
* Copyright (c) 2018 Doyub Kim
*
* I am making my contributions/submissions to this project solely in my
* personal capacity and am not conveying any rights to any intellectual
* property of any third parties.
*/
        

""")
        header_file.write("#ifndef INCLUDE_JET_JET_H_\n")
        header_file.write("#define INCLUDE_JET_JET_H_\n")

        for path, dirs, files in os.walk("../include/jet/"):

            for file in files:
                if file.split('.')[-1] == "h" and file != "jet.h":
                    path_temp = path.split('/')[3:]
                    header_path = ""
                    for name in path_temp:
                        header_path = header_path + "/" + name

                    header_file.write(f"#include \"{header_path[1:]}/{file}\"\n")

        header_file.write("#endif  // INCLUDE_JET_JET_H_\n")
    header_file.close()


if __name__ == "__main__":
    main()
