### script issue
The scripts are written for unix end of line to be linefeed and will malfunction if converted to crlf.
When installing git on a Windows it will give an option to enable automatic conversion cr or lf to crlf.
This will come back and byte you. 

It can be turned off with:
```
git config core.autocrlf "false"
```
If the files were already brought over then run this to remove the carraige returns. 
```
cd <initmaker>/initmaker/scripts
find . -type f -not -path '*/\.*' -exec grep -Il '.' {} \; | xargs -d '\n' -L 1 dos2unix -k
```


