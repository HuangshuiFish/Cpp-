/*
 * @Author: 光城
 * @Date: 2021-05-08 11:25:52
 * @LastEditors: 光城
 * @LastEditTime: 2021-05-08 11:26:17
 * @Description:
 * @FilePath: \code\kg\string\string.cpp
 */

#include "string.h"

String::String()
{
    data_ = new char[1024];
    size_ = sizeof(data_);
}

String::String(const char *str)                 // 构造
{
    __init(str);
}


String::String(const String &other)             // 拷贝构造
{
    size_ = other.size_;
    data_ = new char[strlen(other.data_) + 1];
    *data_ = *(other.data_);
}


String &String::operator=(const String &other)  // 拷贝赋值
{
    if (&other != this)  // 防止自赋值
    {
        if (data_ != NULL)
        {
            delete data_;
            data_ = NULL;
        }
        size_ = other.size_;
        data_ = new char[strlen(other.data_) + 1];
        *data_ = *(other.data_);
    }

    return *this;
}

String::String(String&& other) noexcept             // 移动构造
{
    data_ = other.data_;
    // size_ 如何确定
}

String& String::operator=(String&& other) noexcept  // 移动赋值
{
    
}

String::~String()                               // 析构
{
    __clean();
}

void String::__init(const char *str)
{
    data_ = new char[strlen(str) + 1];
    size_ = sizeof(data_);
}

void String::__clean()
{
    if (data_ != NULL)
    {
        delete data_;
    }
}