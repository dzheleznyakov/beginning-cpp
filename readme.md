# How to compile

To compile a `.cpp` file, run the following command:
```bash
g++ <path>/<filename>.cpp -std=c++17 -o data/<filename>
```

To run the compiled binary file, run
```bash
./data/<filename>
```

To compile and run the binary right after that, run
```bash
g++ <path>/<filename>.cpp -std=c++17 -o data/<filename> && ./data/<filename>
```

For example:
```bash
g++ chapter-02/examples/Ex2_06.cpp -std=c++17 -o data/Ex2_06 && ./data/Ex2_06
```