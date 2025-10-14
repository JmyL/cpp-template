{
  description = "clang + Boost development environment (CMake ready)";

  inputs = { nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable"; };

  outputs = { self, nixpkgs }: {
    devShells.x86_64-linux.default = let
      pkgs = import nixpkgs {
        system = "x86_64-linux";
        config.allowUnfree = true;
      };
    in pkgs.mkShell {
      buildInputs = [
        pkgs.clang
        pkgs.ninja
        pkgs.cmake
        pkgs.ccache
        pkgs.boost.dev
        pkgs.cppcheck
        pkgs.doxygen
        pkgs.lcov
        pkgs.cudatoolkit
      ];
      shellHook = ''
        export CC=clang
        export CXX=clang++
      '';
      CMAKE_PREFIX_PATH = "${pkgs.boost.dev}";
      CPLUS_INCLUDE_PATH = "${pkgs.boost.dev}/include";
    };
  };
}
