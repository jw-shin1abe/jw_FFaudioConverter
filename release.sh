#!/bin/sh
VERSION=$(awk -F '"' '{if(/VERSIONSTR = /) print $2}' CMakeLists.txt)
VERSION=${VERSION/QCoreApplication::setApplicationVersion(\"}
VERSION=${VERSION/\");}
VERSION=$(echo $VERSION | tr -d '\n')

# Set version in appdata.xml
sed -i "/    <release date=/c\    <release date=\"$(date +%Y-%m-%d)\" version=\"$VERSION\"/>" com.github.Bleuzen.FFaudioConverter.appdata.xml

# Package
mkdir -p release
tar -cJf release/FFaudioConverter-$VERSION-src.tar.xz \
    src/ \
    translations/ \
    CMakeLists.txt \
    build_linux.sh \
    build_win32.bat \
    LICENSE \
    com.github.Bleuzen.FFaudioConverter.appdata.xml \
    com.github.Bleuzen.FFaudioConverter.desktop \
    com.github.Bleuzen.FFaudioConverter.png \
    com.github.Bleuzen.FFaudioConverter.ico \
    ffaudioconverter.qrc

cd release/
sha256sum FFaudioConverter-$VERSION-src.tar.xz
