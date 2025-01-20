# oProjector
A warper for EPSON projector Web Control make with Qt.

## Instructions
1. Copy the settings.ini file from the application directory (default path:
`C:\Program Files (x86)\oProjecter\settings.ini`) to the desktop.
2. Open the settings.ini file with Notepad.
3. Modify the url field by changing `192.168.0.205` to the projector's IP address, and save the file.
4. Copy the modified `settings.ini` file back to the original directory and overwrite the existing file.

## Frequently Asked Questions

Q: What should I do if my `settings.ini` file is broken or missing?  
A: Right-click on oProjector.exe > select Run as Administrator. The file will be regenerated automatically.  

Q: What should I do if I open oProjector and only see a white screen for a long time?  
A: Check if the settings.ini file exists. If it doesn't, refer to the previous FAQ entry. If the file exists, verify your network configuration. If the issue persists, check the program code.
