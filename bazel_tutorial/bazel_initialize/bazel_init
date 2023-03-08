#!/bin/bash

# Check if project name argument is provided
if [ -z "$1" ]; then
  echo "Please provide a project name as the first argument."
  exit 1
fi


# Create a new Bazel workspace
echo "Creating new Bazel workspace"
mkdir "$1"
cd "$1"
cat << EOF > WORKSPACE
workspace(name = "$1")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Setup rules_foreign_cc (CMake integration)
http_archive(
    name = "rules_foreign_cc",
    strip_prefix = "rules_foreign_cc-8d540605805fb69e24c6bf5dc885b0403d74746a", # 0.9.0
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/8d540605805fb69e24c6bf5dc885b0403d74746a.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

http_archive(
      name = "name",
      build_file = "//:third_party/name.BUILD",
      sha256 = "8df0079cdbe179748a18d44731af62a245a45ebf5085223dc03133954c662973",
      strip_prefix = "name-prefix",
      urls = ["https://github.com/....tar.gz"],
)

EOF


# Create folders
echo "Creating folders"
mkdir -p src
mkdir -p src/mylib
mkdir -p third_party


# Add Bazel BUILD files for C++ development
echo "Creating Bazel BUILD files for C++ binary"
cat << EOF > src/BUILD
load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "$1",
    srcs = [
        "main.cpp",
        ],
    includes = [
      "src",
    ],
    deps = [
        "//src/mylib:mylib",
    ],
    visibility = ["//visibility:public"],
)
EOF


# Add Bazel BUILD file for a C++ library
echo "Creating Bazel BUILD files for C++ library"
cat << EOF > src/mylib/BUILD
load("@rules_cc//cc:defs.bzl", "cc_library")
cc_library(
    name = "mylib",
    srcs = [
        "mylib.cpp",
    ],
    hdrs = [
        "mylib.hpp",
    ],
    visibility = ["//visibility:public"],
)
EOF





# Initialize a sample C++ source file
echo "Initializing a sample C++ source file"
cat << EOF > src/main.cpp
#include <iostream>
#include "mylib/mylib.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    int a = mylib();
    return 0;
}
EOF


# Initialize a sample C++ library source file
echo "Initializing a sample C++ library source file"
cat << EOF > src/mylib/mylib.cpp
#include "mylib.hpp"

int mylib() {
    std::cout << "Hello, MyLib!" << std::endl;
    return 1;
}
EOF


# Initialize a sample C++ library source file
echo "Initializing a sample C++ library header file"
cat << EOF > src/mylib/mylib.hpp
#include <iostream>

int mylib();
EOF

