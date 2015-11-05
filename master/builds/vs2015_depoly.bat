@echo off
echo --------------->Rebuild Solution projectconfig:"Debug|Win32" 
msbuild VS/dbgme.sln /p:configuration=debug /p:platform="x86"

echo --------------->Rebuild Solution projectconfig:"Debug|x64" 
msbuild VS/dbgme.sln /p:configuration=debug /p:platform="x64"

echo --------------->Rebuild Solution projectconfig:"Release|Win32"
msbuild VS/dbgme.sln /p:configuration=release /p:platform="x86"

echo --------------->Rebuild Solution projectconfig:"Release|x64"
msbuild VS/dbgme.sln /p:configuration=release /p:platform="x64"

echo --------------->Copy folders and files 
rd /s /Q "./../dist/"
md .\..\dist\dbgme\include
md .\..\dist\dbgme\libs
xcopy VS\_bin\*.lib ..\dist\dbgme\libs /d /e /c /q /k /y /i
xcopy VS\_bin\*.dll ..\dist\dbgme\libs /d /e /c /q /k /y /i
xcopy ..\src\dgr2\*.h ..\dist\dbgme\include /d /e /c /q /k /y /i 
xcopy ..\src\dgr2\*.hpp ..\dist\dbgme\include /d /e /c /q /k /y /i 
rd /s /Q ..\dist\dbgme\include\sqlite-amalgamation
xcopy ..\src\xmlConfKit\*.h ..\dist\dbgme\include\xmlConfKit /d /e /c /q /k /y /i
xcopy ..\src\xmlConfKit\*.hpp ..\dist\dbgme\include\xmlConfKit /d /e /c /q /k /y /i
rd /s /Q "VS/_bin/"

echo ---------------->clean build output files
rd /s /Q "VS/test/Debug/"
rd /s /Q "VS/test/Release/"
rd /s /Q "VS/test/x64/"

rd /s /Q "VS/dgr2/Debug/"
rd /s /Q "VS/dgr2/Release/"
rd /s /Q "VS/dgr2/x64/"

rd /s /Q "VS/xmlConfKit/Debug/"
rd /s /Q "VS/xmlConfKit/Release/"
rd /s /Q "VS/xmlConfKit/x64/"

echo --------------->Deploy dbgme finish!
pause

