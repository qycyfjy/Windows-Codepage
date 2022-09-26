## 主要目的
演示Windows的蛋疼的编码问题
因为没有直接的方法将本机环境的编码（我的是GB2312）转为UTF-8，得以宽字符为中介

## 示例说明
files.dll是rust写的一个共享库
其中只有一个函数remove_dir，传入参数为一个const char*，要求是以utf-8编码的路径名，返回true删除成功，false失败
命令行模式下直接用`std::cin >> path`，然后传入`path.c_str()`作为参数是不行的，因为path的编码方式是本机环境的编码
所以要转换一下