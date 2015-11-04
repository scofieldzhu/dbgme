@echo off
echo --------------->Rebuild Solution projectconfig:"Debug|Win32" 
MsBuild.exe VS/dbgme.sln /t:rebuild

echo --------------->Build Finished!

echo --------------->Copy folders and files start...
xcopy VS\_bin\*.lib ..\dist\dbgme\libs /d /e /c /q /k /y /i
xcopy VS\_bin\*.dll ..\dist\dbgme\libs /d /e /c /q /k /y /i
xcopy ..\src\dgr2\*.h ..\dist\dbgme\include /d /e /c /q /k /y /i 
xcopy ..\src\dgr2\*.hpp ..\dist\dbgme\include /d /e /c /q /k /y /i 
rd /s /Q ..\dist\dbgme\include\sqlite-amalgamation
xcopy ..\src\xmlConfKit\*.h ..\dist\dbgme\include\xmlConfKit /d /e /c /q /k /y /i
xcopy ..\src\xmlConfKit\*.hpp ..\dist\dbgme\include\xmlConfKit /d /e /c /q /k /y /i

echo --------------->Copy folders and files finished!
echo --------------->Deploy dbgme finish!
pause

