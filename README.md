# Cpp Template

This application is written in C++ and built with CMake.

## More information

- Installation instructions are in the INSTALL file
- License is in the LICENSE file

## Prerequisites

- direnv
- Install [nix](https://nixos.org/download/) and create `~/.config/nix/nix.conf` with `experimental-features = nix-command flakes` as it's contents.

All prerequisites will be installed by nix package manager.
You can configure this by editing `flake.nix` file.
Build type is set as RelWithDebInfo by default.
You can set the `BUILD_TYPE` environment variable manually in the shell, as shown below:

```{bash}
export BUILD_TYPE=Debug
```

## Configure

```{bash}
cmake -B $BUILD_TYPE -DCMAKE_BUILD_TYPE=$BUILD_TYPE
```

## Test

```{bash}
cmake --build $BUILD_TYPE && ./$BUILD_TYPE/test/calc/calc_test
```

## Benchmark

```{bash}
cmake --build $BUILD_TYPE && python3 ./$BUILD_TYPE/compare.py filters ./$BUILD_TYPE/test/calc/calc_benchmark UseSet UseRuntimeConfigurableSet
```