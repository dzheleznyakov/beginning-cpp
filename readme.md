# How to compile

To compile a `.cpp` file, run the following script from the project root directory:
```bash
./start.sh <cppfilepath> [-c]
```
where optional parameter `c` flags that the file should be compiled first. 
Running the script without the parameter will fun the already compiled version.

For example:
```bash
./start.sh chapter-02/examples/Ex2_06.cpp -c
```

To compile all `.cpp` files, run
```bash
find chapter-0* -name "*.cpp" -print0 | xargs -0 -I{} ./start.sh {} -co
```