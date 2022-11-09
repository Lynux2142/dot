# Raspberry dot

## Linux setup
```
sudo apt-get install libsdl2-dev libsdl2-image-dev -y
git clone https://github.com/Lynux2142/dot.git
cd dot
make
```

## Windows setup
Mingw must be installed on your system.

You can download the latest version here:
```
https://github.com/brechtsanders/winlibs_mingw/releases/download/12.2.0-14.0.6-10.0.0-ucrt-r2/winlibs-x86_64-posix-seh-gcc-12.2.0-mingw-w64ucrt-10.0.0-r2.7z
```
Then go in the project directory, run install.bat and compile the project with mingw32-make.exe

## Usage
- Arrows keys to move the dot
- '=' / '-' to UP/DOWN scale the dot
- 'U' / 'O' to go through the differents dots or boards images
- 'I' to change between dot mode or board mode
- 'Space' to reset
- 'Escape' to quit the program
