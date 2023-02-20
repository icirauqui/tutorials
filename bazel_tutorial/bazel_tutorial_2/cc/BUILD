load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "my_lib",
    srcs = ["my_lib/my_lib.cpp"],
    hdrs = ["my_lib/my_lib.hpp"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//cc:my_lib",
    ],
    visibility = ["//visibility:public"],
)