# Qt C++ Test App

A basic Qt app made using C++.

# Installing dependencies

To install the project dependencies, please run the following commands in the project root directory:

```
# initialize the vcpkg submodule
git submodule update --init

# install sub-dependencies
sudo apt install -y curl pkg-config pip python3-distutils libxi-dev libgl1-mesa-dev libglu1-mesa-dev mesa-common-dev libxrandr-dev libxxf86vm-dev flex bison nasm autoconf automake autopoint libtool autoconf-archive

# build vcpkg without information collection
./vcpkg/bootstrap-vcpkg.sh -disableMetrics
./vcpkg/vcpkg install qt

mkdir build && cd build
cmake ..
make
```