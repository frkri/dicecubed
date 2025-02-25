# dicecubed

## Build

To build this project, make sure to have CMake installed locally.

### Desktop

```
mkdir build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
make
```

### Web

```
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release
emmake make
```

## Run

```
./dicecubed
```