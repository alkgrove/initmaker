### Building SAMD51 Documentation

The SAMD51 low level drivers has doxygen tags and I've included a basic config file, samd5xdocs` to build documentation.
Atmel has some doxygen tags and you can expand the documentation to include those by change the line in samd5xdocs:

`INPUT   =..\..\samd5x\inc`

to 

`INPUT   =..\..\samd5x\inc ..\..\samd5x\inc\component ..\..\samd5x\inc\instance`

Run 

`doxygen samd5xdocs` 

documentation should be in ./samd5x/html. 

### auto CRLF
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


