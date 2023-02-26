load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

# arrayfire
cmake(
    name = "arrayfire",
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
        "AF_BUILD_CPU": "ON",
        "AF_BUILD_CUDA": "OFF",
        "AF_BUILD_OPENCL": "OFF",
        "AF_BUILD_EXAMPLES": "OFF",
        "AF_WITH_IMAGEIO": "OFF",
        "BUILD_TESTING": "OFF",
        "AF_BUILD_DOCS": "OFF",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    copts = [
        "-fPIC",
    ],
    lib_source = "@arrayfire//:all_srcs",
    out_shared_libs = [
      "libaf.so", 
      "libaf.so.3", 
      "libafcpu.so",
      "libafcpu.so.3",
    ],
    visibility = ["//visibility:public"],
)

