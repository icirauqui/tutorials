load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//cc/my_lib:my_lib",
        "@arrayfire//:arrayfire",
    ],
    visibility = ["//visibility:public"],
)