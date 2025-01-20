# oProjector
A warper for EPSON projector Web Control make with Qt.

## Instructions
1. Open the `settings.ini` file.
2. Modify the url field by changing `192.168.0.205` to the projector's IP address, and save the file.

## Frequently Asked Questions

Q: What should I do if my `settings.ini` file is broken or missing?  
A: Right-click on oProjector.exe > select Run as Administrator. The file will be regenerated automatically.  

Q: What should I do if I open oProjector and only see a white screen for a long time?  
A: Check if the settings.ini file exists. If it doesn't, refer to the previous FAQ entry. If the file exists, verify your network configuration. If the issue persists, check the program code.

Q: Missing files `VCRuntime140_1.dll`, `VCRuntime140.dll` and `MSVCP140.dll`  
A: Please install [Microsoft Visual C++ Redistributable](https://aka.ms/vs/17/release/vc_redist.x64.exe)
