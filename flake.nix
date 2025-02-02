{
  description = "C++ + boost development environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }: {

    packages.x86_64-linux = with nixpkgs.legacyPackages.x86_64-linux; {
      default = stdenv.mkDerivation {
        name = "cpp-boost-env";
        buildInputs = [ clang ninja cmake ];
      };
    };

  };
}
