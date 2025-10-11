{
  description = "clang + Boost development environment (CMake ready)";

  # See https://github.com/NixOS/nixpkgs/blob/master/pkgs/development/compilers/llvm/default.nix to find correct commit id for specific clang version
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: {
    devShells.x86_64-linux.default = with nixpkgs.legacyPackages.x86_64-linux; mkShell {
      buildInputs = [
        clang
        ninja
        cmake
        ccache
        boost.dev
        cppcheck
        doxygen
        lcov
      ];

      CMAKE_PREFIX_PATH = "${boost.dev}";
      CPLUS_INCLUDE_PATH = "${boost.dev}/include";
    };
  };
}