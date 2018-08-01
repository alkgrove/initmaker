### initmaker script issue
The scripts are written for unix end of line linefeed and will probably malfunction if converted to crlf.
It looks like git has cursed autocrlf that defaults to true on Windows. It can be turned off with:
```
git config core.autocrlf "false"
```
If the files were already brought over then run this to remove the carraige returns. 
```
cd <initmaker>/initmaker/scripts
find . -type f -not -path '*/\.*' -exec grep -Il '.' {} \; | xargs -d '\n' -L 1 dos2unix -k
```

This seems to affect only the scripts. 
Geez, auto crlf is worse than mosquitoes on a hot summer night.
