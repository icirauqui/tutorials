load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

cmake(
    name = "oneDNN",
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
        "DNNL_BUILD_EXAMPLES": "OFF",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    copts = [
        "-fPIC",
    ],
    lib_source = "@oneDNN//:all_srcs",
    out_shared_libs = [
      "libdnnl.so",
      "libdnnl.so.2",
    ],
    visibility = ["//visibility:public"],
)