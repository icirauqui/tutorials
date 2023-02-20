load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "my_lib",
    srcs = ["cc/my_lib/my_lib.cpp"],
    hdrs = ["cc/my_lib/my_lib.hpp"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["cc/main.cpp"],
    deps = [
        "//:my_lib",
    ],
    visibility = ["//visibility:public"],
)