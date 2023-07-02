@echo off

if not exist %~dp0..\..\third_party\sdk\lib\bedrock_server_api.lib goto process
if not exist %~dp0..\..\third_party\sdk\lib\bedrock_server_var.lib goto process
goto end

:process
%~dp0..\..\third_party\sdk\tools\PeEditor.exe -c -l -o %~dp0\..\..\third_party\sdk\lib

:end
