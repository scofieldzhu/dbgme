@echo off
echo --------------->Rebuild Solution projectconfig:"Debug|Win32" 
msbuild VS2010/dbgme.sln /p:configuration=debug /p:platform="win32" /t:rebuild /m

echo --------------->Rebuild Solution projectconfig:"Release|Win32"
msbuild VS2010/dbgme.sln /p:configuration=release /p:platform="win32" /t:rebuild /m

echo --------------->Copy folders and files 
rd /s /Q "./../dist/"
md .\..\dist\dbgme\include
md .\..\dist\dbgme\libs
xcopy VS2010\_bin\*.lib ..\dist\dbgme\libs /d /e /c /q /k /y /i
xcopy VS2010\_bin\*.dll ..\dist\dbgme\libs /d /e /c /q /k /y /i
xcopy ..\src\dgr2\*.h ..\dist\dbgme\include /d /e /c /q /k /y /i 
xcopy ..\src\dgr2\*.hpp ..\dist\dbgme\include /d /e /c /q /k /y /i 
rd /s /Q ..\dist\dbgme\include\sqlite-amalgamation
xcopy ..\src\xmlConfKit\*.h ..\dist\dbgme\include\xmlConfKit /d /e /c /q /k /y /i
xcopy ..\src\xmlConfKit\*.hpp ..\dist\dbgme\include\xmlConfKit /d /e /c /q /k /y /i

echo ---------------->clean build output files
rd /s /Q "VS2010/_bin/"
rd /s /Q "VS2010/dgr2/Debug/"
rd /s /Q "VS2010/dgr2/Release/"
rd /s /Q "VS2010/xmlConfKit/Debug/"
rd /s /Q "VS2010/xmlConfKit/Release/"

echo --------------->Deploy dbgme finish!
pause

