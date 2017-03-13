无法运行？提示找不到Msvcr120d.dll/Msvcp120d.dll文件
1、复制文件“msvcr120d.dll/Msvcp120d.dll”到系统目录下，系统目录一般为：C:\Windows\SysWOW64。32位系统为C:\Windows\System32
（该文件有备份在本程序的根目录下）
2、如果还不能运行，点击开始菜单-->运行-->输入regsvr32 msvcr120d.dll 后，回车即可解决