load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

# gsl
cmake(
    name = "gsl",
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
        "NO_AMPL_BINDINGS": "1",
        "GSL_DISABLE_TESTS": "1",
        "DOCUMENTATION": "OFF",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    copts = [
        "-fPIC",
    ],
    lib_source = "@gsl//:all_srcs",
    out_static_libs = [
      "libgsl.a",
    ],
    visibility = ["//visibility:public"],
)