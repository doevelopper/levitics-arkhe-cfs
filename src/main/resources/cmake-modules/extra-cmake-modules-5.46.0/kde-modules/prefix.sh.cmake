export PATH=@KDE_INSTALL_FULL_BINDIR@:$PATH

# LD_LIBRARY_PATH only needed if you are building without rpath
# export LD_LIBRARY_PATH=@KDE_INSTALL_FULL_LIBDIR@:$LD_LIBRARY_PATH

export XDG_DATA_DIRS=@KDE_INSTALL_FULL_DATADIR@:${XDG_DATA_DIRS:-/usr/local/share/:/usr/share/}
export XDG_CONFIG_DIRS=@KDE_INSTALL_FULL_CONFDIR@:${XDG_CONFIG_DIRS:-/etc/xdg}

export QT_PLUGIN_PATH=@KDE_INSTALL_FULL_QTPLUGINDIR@:$QT_PLUGIN_PATH
export QML2_IMPORT_PATH=@KDE_INSTALL_FULL_QMLDIR@:$QML2_IMPORT_PATH
