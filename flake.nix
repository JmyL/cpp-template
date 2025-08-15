{
  description = "clang + Boost development environment (CMake ready)";

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
