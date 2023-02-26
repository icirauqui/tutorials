load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

cmake(
    name = "flashlight",
    deps = [
      "@oneDNN//:oneDNN",
      "@arrayfire//:arrayfire",
    ],
    cache_entries = {
        "CMAKE_BUILD_TYPE": "Release",
        "FL_BUILD_ALL_LIBS": "ON",
        "FL_BACKEND": "CPU",
        "DNNL_DIR": "$EXT_BUILD_DEPS/oneDNN/lib/cmake/dnnl",
    },
    build_args = [
        "--verbose",
        "--",
        "-j `nproc`",
    ],
    copts = [
        "-fPIC",
    ],
    tags = [
      "requires-network"
    ],
    lib_source = "@flashlight//:all_srcs",
    out_static_libs = ["libflashlight.a"],
    visibility = ["//visibility:public"],
)