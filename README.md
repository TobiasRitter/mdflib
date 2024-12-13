```bash
mkdir build
cd build
cmake ..
cmake --build .
cd ..
g++ test.cpp -o test -I./include -L./build/mdflibrary -lmdflibrary
```
