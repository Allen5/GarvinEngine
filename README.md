
### Introduction

Garvin Engine 是一套工具集，涵盖了常用的基础工具如：加解密，MD5，日志封装。提供了网络工具库，也提供了数据访问工具库等等。

旨在封装已有的代码，使之更为易用。

#### 项目约定

项目的构建工具选择CMake, proj 目录可自定义生成指定平台的IDE解决方案文件（如： .xcodeproj, .sln等等）

#### 代码规范

参考Google Cpp Style的代码风格

#### 目录结构说明

- include

  头文件所在路径。根据模块不同，区分不同的头文件。base目录为基础目录。

- src

  cc文件所在路径。

- build

  使用cmake生成的makefile等文件

- proj

  项目的解决访问文件

- test

  单元测试代码

- doc

  文档