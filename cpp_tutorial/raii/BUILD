cc_binary (
    name = "raii",
    srcs = ["main.cpp"],
    copts = ["-std=c++17"],
    # Link the binary statically against its dependencies.
    linkstatic = 1,
    # The `linkopts` attribute specifies additional options to pass to the linker.
    # In this case, we are not passing any additional options.
    linkopts = [],
    # The `deps` attribute specifies the dependencies of this binary.
    deps = [
        "//cpp_tutorial/raii:raii_lib",
    ],
)

cc_library (
    name = "raii_lib",
    srcs = ["raii_example.cpp"],
    hdrs = ["raii_example.h"],
    visibility = ["//visibility:public"],
)