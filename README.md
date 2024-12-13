```bash
mkdir build
cd build
cmake ..
cmake --build .
cd ..
g++ main.cpp -o build/main -I./include -L./build/mdflibrary -lmdflibrary
```

```bash
em++ hello.cpp -o build/hello.html --use-port=zlib
```
