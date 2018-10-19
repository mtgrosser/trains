
# Fixing Märklin cs2.app on macOS Sierra

When starting the Märklin CS2 app on macOS Sierra, it crashes due to some libraries not being loaded in the `gfpsim` executable. This is due to their load paths not being correct, which can be fixed using `otool`:

```sh
install_name_tool -change /Applications/QT/4.8.5/clang_32/lib/QtGui.framework/Versions/4/QtGui @executable_path/../../../../Frameworks/QtGui.framework/Versions/4/QtGui /Applications/cs2.app/Contents/Resources/gfpsim.app/Contents/MacOS/gfpsim

install_name_tool -change /Applications/QT/4.8.5/clang_32/lib/QtCore.framework/Versions/4/QtCore @executable_path/../../../../Frameworks/QtCore.framework/Versions/4/QtCore /Applications/cs2.app/Contents/Resources/gfpsim.app/Contents/MacOS/gfpsim

install_name_tool -change /Applications/QT/4.8.5/clang_32/lib/QtNetwork.framework/Versions/4/QtNetwork @executable_path/../../../../Frameworks/QtNetwork.framework/Versions/4/QtNetwork /Applications/cs2.app/Contents/Resources/gfpsim.app/Contents/MacOS/gfpsim

install_name_tool -change @executable_path/../Frameworks/QtCore.framework/Versions/4/QtCore @loader_path/../../../QtCore.framework/Versions/4/QtCore /Applications/cs2.app/Contents/Frameworks/QtGui.framework/Versions/4/QtGui

install_name_tool -change @executable_path/../Frameworks/QtCore.framework/Versions/4/QtCore @loader_path/../../../QtCore.framework/Versions/4/QtCore /Applications/cs2.app/Contents/Frameworks/QtNetwork.framework/Versions/4/QtNetwork
```

# Getting the CS2 app

https://www.maerklin.de/de/service/downloads/cs2-updates/
