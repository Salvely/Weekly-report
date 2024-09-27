# Time log

- 15:36:04 POSIX Recitation 看完了
- 16:58:08 SimpleFileReader 实现，准备测试
- 19:19:46 SimpleFileReader 所有测试通过
- 19:27:56 总结完成，准备开始实现`BufferFileReader`
- 23:00:30 `good()`未修复，应当增加一个`private`变量，当下一次读取发现问题时再设置`good`为`false`，而不是直接就退出读取

# Summary

## `SimpleFileReader.h`

- 添加了`offset`值，以便直接获取偏移量，而无需使用两次`lseek`做减法

## `SimpleFileReader.cc`

1. 构造函数

```C++
SimpleFileReader::SimpleFileReader(const string& fname){
    this->good_ = false;
    this->fd_ = -1;
    this->offset = 0;
    this->open_file(fname);
}
```

设置`good_`为`false`，`fd_`为-1，`offset`为 0，然后再`open_file`

2. `open_file`

```C++
void SimpleFileReader::open_file(const string& fname){
    if(this->good()) {
        this->close_file();
    }
    this->fd_ = open(fname.c_str(),O_RDONLY);
    if(this->fd_ == -1) {
        this->good_ = false;
    }
    else {
        this->good_ = true;
        this->offset = 0;
    }
}
```

注意`open()`调用时传入的文件名为 char\*格式，不能是`string`，需要使用`fname.c_str()`进行类型转换

3. `get_chars()`

```C++
string SimpleFileReader::get_chars(size_t n){
    char buffer[n+1];
    if(this->good()) {
        ssize_t s = read(this->fd_, buffer, n);
        if(s < n) {
            this->good_ = false;
        }
        buffer[s] = '\0';
        this->offset += s;
        return string(buffer);
    }
    else {
        return "";
    }
}
```

注意读取到的`s < n`时，即可判断已经阅读到文件末尾，需要将`this->good_`置为`false`，将`buffer[s]`（注意不是`buffer[n]`！）置为`\0`，且添加`offset`值

4. `rewind()`

```C++
void SimpleFileReader::rewind(){
    if(this->fd_ != -1) {
        this->good_ = true;
        lseek(this->fd_,0,SEEK_SET);
        this->offset = 0;
    }
}
```

注意`rewind`后，因为文件读写头移动到开头，因此需要把`this->good_`置为`true`(很重要！刚刚因为这里错误的调试了半天`get_char()`和`get_chars()`！)
