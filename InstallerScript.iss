; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "APOD Downloader"
#define MyAppVersion "1.0"
#define MyAppPublisher "Anthony Piccinone"
#define MyAppExeName "DownloadAPOD.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application. Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{B349A32E-0E10-4D84-A410-6845A979F0FE}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
; Uncomment the following line to run in non administrative install mode (install for current user only.)
;PrivilegesRequired=lowest
OutputDir=C:\Users\Anthony\Desktop
OutputBaseFilename=DownloadAPODInstaller
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\Anthony\VisualStudioProjects\DownloadAPOD\DownloadAPOD\bin\Release\netcoreapp3.1\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Anthony\VisualStudioProjects\DownloadAPOD\DownloadAPOD\bin\Release\netcoreapp3.1\DownloadAPOD.deps.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Anthony\VisualStudioProjects\DownloadAPOD\DownloadAPOD\bin\Release\netcoreapp3.1\DownloadAPOD.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Anthony\VisualStudioProjects\DownloadAPOD\DownloadAPOD\bin\Release\netcoreapp3.1\DownloadAPOD.pdb"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Anthony\VisualStudioProjects\DownloadAPOD\DownloadAPOD\bin\Release\netcoreapp3.1\DownloadAPOD.runtimeconfig.dev.json"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Anthony\VisualStudioProjects\DownloadAPOD\DownloadAPOD\bin\Release\netcoreapp3.1\DownloadAPOD.runtimeconfig.json"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

