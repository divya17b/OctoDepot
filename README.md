# OctoDepot

## Introduction

Octodepot is the objective-oriented software design project for CPSC 462 class of Cal State Univ Fullerton.

By Yoko Kanazuki and Nan Jiang.

## Installation
Guide to compile and run this project. Until now, OctoDepot is built and tested on Arch Linux and Debian with no error.

### Requirements
This project uses **SQLite3**, please make sure SQLite3 or libsqlite3-dev is installed on the machine you would like to compile this project.

1. For Arch Linux
    ```
    # pacman -S sqlite
    ```
2. For Debian (or other distros based on it)
    ```
    # apt install libsqlite3-dev
    ```
3. For CentOS (or Fedora / RHEL)
    ```
    # yum install libsqlite3x-devel.x86_64
    ```
4. For Windows Systems
    Please use the [precompiled binaries](https://www.sqlite.org/2018/sqlite-dll-win64-x64-3250200.zip) from the SQLite3 official website.
5. For windows Systems with WSL  
   Please Follow Linux instructions  

Before commencing to build the program, make sure you are in the project **root directory**; in which you can see LICENSE, Makefile, and build.bat

### How to Build
1. For Linux with g++/Make
   ```
   $ make octodepot
   ```
   or if you have a multi-core processor (for example I have 14 core/ 28-thread processor); add -j flag with number of thread you want to work in parallel.
   ```
   $ make octodepot -j28
   ```

2. For Windows with MinGW and g++
   ```
   build.bat
   ```
3. For Windows with Cgywin and g++
   ```
   $ make octodepot
   ```
4. For Windows with WSL  
   ```
   $ make octodepot
   ```

### How to Run the Program
1. For Linux
   ```
   ./bin/octodepot
   ```
2. For Windows (MinGW)  
   Please open "bin" folder and double click octodepot.exe to run
3. For Windows (Cygwin)
   ```
   ./bin/octodepot
   ```
4. For Windows (WSL)
   ```
   ./bin/octodepot
   ```