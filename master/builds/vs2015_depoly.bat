@echo off
echo --------------->Rebuild Solution projectconfig:"Debug|Win32" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/dgr2/dgr2.vcxproj" /projectconfig "Debug|Win32" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/xmlConfKit/xmlConfKit.vcxproj" /projectconfig "Debug|Win32" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/test/test.vcxproj" /projectconfig "Debug|Win32" 

echo --------------->Rebuild Solution projectconfig:"Release|Win32" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/dgr2/dgr2.vcxproj" /projectconfig "Release|Win32" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/xmlConfKit/xmlConfKit.vcxproj" /projectconfig "Release|Win32" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/test/test.vcxproj" /projectconfig "Release|Win32" 

echo --------------->Rebuild Solution projectconfig:"Debug|x64" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/dgr2/dgr2.vcxproj" /projectconfig "Debug|x64" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/xmlConfKit/xmlConfKit.vcxproj" /projectconfig "Debug|x64" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/test/test.vcxproj" /projectconfig "Debug|x64" 

echo --------------->Rebuild Solution projectconfig:"Release|x64" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/dgr2/dgr2.vcxproj" /projectconfig "Release|x64" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/xmlConfKit/xmlConfKit.vcxproj" /projectconfig "Release|x64" 
devenv "VS/dbgme.sln" /rebuild Debug /project "VS/test/test.vcxproj" /projectconfig "Release|x64" 

echo --------------->Build Finished!

echo --------------->Copy folders and files start...
xcopy VS\_bin\*.lib ..\dist\dbgme\libs /d /e /c /q /k /y /i
xcopy VS\_bin\*.dll ..\dist\dbgme\libs /d /e /c /q /k /y /i
xcopy ..\src\dgr2\*.h ..\dist\dbgme\include /d /e /c /q /k /y /i
xcopy ..\src\dgr2\*.hpp ..\dist\dbgme\include /d /e /c /q /k /y /i
xcopy ..\src\xmlConfKit\*.h ..\dist\dbgme\include\xmlConfKit /d /e /c /q /k /y /i
xcopy ..\src\xmlConfKit\*.hpp ..\dist\dbgme\include\xmlConfKit /d /e /c /q /k /y /i

echo --------------->Copy folders and files finished!
echo --------------->Deploy dbgme finish!
pause

