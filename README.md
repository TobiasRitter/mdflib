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

```bash
g++ main.cpp ImportMdf4.cpp mdf4.cpp mdFile.cpp md5.cpp -o build/main
em++ main.cpp ImportMdf4.cpp mdf4.cpp mdFile.cpp md5.cpp -o build/main.js -s EXPORTED_FUNCTIONS="['_mf4read']"
```
