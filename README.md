<a href='https://pledgie.com/campaigns/32359'><img alt='Click here to lend your support to: Steam Event Notification Blocker and make a donation at pledgie.com !' src='https://pledgie.com/campaigns/32359.png?skin_name=chrome' border='0' ></a><br>
<b>Download:</b><br>
 <a href="https://github.com/nandee95/Steam_Event_Notification_Blocker/raw/master/Build/SENB.rar">Latest build</a><br><br>
<b>Description</b><br>
This small app blocks <a href="http://steamcommunity.com">Steam</a>'s annoying event notifications.
<br><br>
<b>How it works?</b><br>
It runs in the background all the time (It uses as small amount of resources as possible). When it detect an event notification window its closes it. It scans for windows once a second. The program is automatically starts with Windows!
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
