# Learn OpenGL

## Build

### CMake

Run CMake with `-DASSIMP_BUILD_TESTS=OFF` variable.

### Windows

```shell script
cd out
cmake ..
cmake --build . --config Release

# To install app to Program Files
cd apps
cmake --install .
```
