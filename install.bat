set LIBSDL2=SDL2-2.24.2
set LIBSDL2IMAGE=SDL2_image-2.6.2

::
:: Download libsdl2 and libsdl2-image
::
bitsadmin /transfer "Download Lib SDL2" "https://github.com/libsdl-org/SDL/releases/download/release-2.24.2/SDL2-devel-2.24.2-mingw.zip" %CD%\%LIBSDL2%.zip
bitsadmin /transfer "Download Lib SDL2_image" "https://github.com/libsdl-org/SDL_image/releases/download/release-2.6.2/SDL2_image-devel-2.6.2-mingw.zip" %CD%\%LIBSDL2IMAGE%.zip

::
:: Unzip files
::
tar -xf %LIBSDL2%.zip
tar -xf %LIBSDL2IMAGE%.zip

::
:: Create sdl directories
::
mkdir sdl\lib
mkdir sdl\include\SDL2

::
:: Copy bin, lib and include files in the project sdl directory
::
xcopy /y %CD%\%LIBSDL2%\x86_64-w64-mingw32\bin\*.dll %CD%\.
xcopy /y %CD%\%LIBSDL2%\x86_64-w64-mingw32\lib\*.a %CD%\sdl\lib\.
xcopy /y %CD%\%LIBSDL2%\x86_64-w64-mingw32\lib\*.la %CD%\sdl\lib\.
xcopy /y %CD%\%LIBSDL2%\x86_64-w64-mingw32\include\SDL2\*.h %CD%\sdl\include\SDL2\.

xcopy /y %CD%\%LIBSDL2IMAGE%\x86_64-w64-mingw32\bin\*.dll %CD%\.
xcopy /y %CD%\%LIBSDL2IMAGE%\x86_64-w64-mingw32\lib\*.a %CD%\sdl\lib\.
xcopy /y %CD%\%LIBSDL2IMAGE%\x86_64-w64-mingw32\lib\*.la %CD%\sdl\lib\.
xcopy /y %CD%\%LIBSDL2IMAGE%\x86_64-w64-mingw32\include\SDL2\*.h %CD%\sdl\include\SDL2\.

::
:: Remove downloaded files
::
del %LIBSDL2%.zip
del %LIBSDL2IMAGE%.zip
rmdir /s /q %LIBSDL2%
rmdir /s /q %LIBSDL2IMAGE%
