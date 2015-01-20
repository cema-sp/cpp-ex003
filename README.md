# Tiny Rendered #
Tiny renderer project from [habrahabr][1].  
It uses [TGAImage], TGAColor, Model, Vec2, Vec3 classes 
from [this][2] repository.

## Make commands ##

* make - build main target (see $(TARGET) in Makefile);
* make test - build test target (see $(TEST) in Makefile);
* make clean - clean build files and binaries.

## Directory Structure ##

* bin - for binary files (including tests);
* build - all object files (`make clean` to empty it);
* include - all header files;
* lib - all compiled libs;
* src - application source files;
* test - tests;
* tmp - for output files.

[1]: http://habrahabr.ru/post/248153/
[2]: https://github.com/ssloy/tinyrenderer
[TGAImage]: http://en.wikipedia.org/wiki/Truevision_TGA
