<font color=red><b>Warning! This tool is no longer required since Steam implemented the option for us to disable event notifications! This project is discontinued!</b></font>


<b>Download:</b><br>
<a href="https://github.com/nandee95/Steam_Event_Notification_Blocker/releases/download/1.0.1/SENB.zip">Latest build</a><br><br>
<b>Other resources:</b><br>
<a href="https://virustotal.com/en/url/2256e7d03e96b6e0b73ae6071eb7f40d3537ebba8596743294d4255bf180e146/analysis/1471527104/">Virustotal</a><br>
<a href="https://www.steamgifts.com/discussion/LomSD/">Steamgifts Discussion</a><br>
<a href="http://steamcommunity.com/sharedfiles/filedetails/?id=741797149">Steam guide</a><br>
<br>
<b>Description</b><br>
This small app blocks <a href="http://steamcommunity.com">Steam</a>'s annoying event notifications.
<br><br>
<b>How it works?</b><br>
It's a background application (It uses as small amount of resources as possible). When It detects an event notification window It closes it. It scans for event notification windows once a second. The program is automatically starts with Windows! Just install it and you will never have to care about it!
<br><br>
<b>How to install this tool?</b><br>
1. Download the latest build from <a href="https://github.com/nandee95/Steam_Event_Notification_Blocker/raw/master/Build/SENB.rar">here</a>.<br>
2. Extract the Winrar archive.<br>
3. Run install.bat
<br><br>
<b>How to uninstall It?</b><br>
Simply run uninstall.bat
<br><br>
<b>Is it safe? Can i get VAC using this tool?</b><br>
No, you can't. It's totally safe. The program not using any injection method or bothering Steam files and processes.
<br><br>
<b>Attached Batch files:</b>
<table>
<thead><tr><td><b>Batch file</b></td><td><b>Description</b></td><td><b>What it does?</b></td></tr></thead>
<tr><td>install.bat</td><td>One click install script</td><td>1. Detects Steam installation<br>2. Terminates senb.exe process<br>3. Copies senb.exe to steam directory<br>4. Adds senb.exe to the startup applications.<br>5. Starts senb.exe</td></tr>
<tr><td>uninstall.bat</td><td>One click uninstall script</td><td>1. Detects Steam installation<br>2. Terminates senb.exe process<br>3. Removes senb.exe from steam directory<br>4. Remove senb.exe from startup applications</td></tr>
<tr><td>terminate.bat</td><td>Terminates the senb.exe process</td><td>Terminates the senb.exe process</td></tr>
</table>

<b>License:</b> MIT

<b>Changelog:</b>
```
1.0
 First release
1.0.1
 Removed VC Redist 2015 dependency (executable's size increased)
 Replaced the 'cp' with 'copy' command in the batch installer
```
