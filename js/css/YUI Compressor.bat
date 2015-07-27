@echo off

pause

(dir %1 /aa /b /s | findstr /e /c:"js") > compressor.tmp

for /f %%i in (compressor.tmp) do (
    echo %%i
    java -jar yuicompressor-2.4.2.jar --line-break 2048 --type js --charset utf-8 -o %%i".tmp" %%i
    copy %%i".tmp" %%i
    del %%i".tmp"
)

(dir %1 /aa /b /s | findstr /e /c:"css") > compressor.tmp

for /f %%i in (compressor.tmp) do (
    echo %%i
    java -jar yuicompressor-2.4.2.jar --line-break 2048 --type css --charset utf-8 -o %%i".tmp" %%i
    copy %%i".tmp" %%i
    del %%i".tmp"
)

del compressor.tmp

pause

echo on