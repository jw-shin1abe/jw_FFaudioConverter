/* ----------------------------------------------------------------------
FFaudioConverter
Copyright (C) 2018  Elias Martin (Bleuzen)
https://github.com/Bleuzen/FFaudioConverter
supgesu@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
---------------------------------------------------------------------- */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore>
#include <QString>
#include <QDir>
#include <QStandardPaths>

class Settings
{
public:
    static void init();

    static QString FFmpegBinary;
    static QString OutputFormat;
    static QString Quality;
    static QString OutputSamplerate;
    static QString OutputDirectory;
    static bool UseSoXresampler;
    static bool QuickConvertMode;
    static int Threads;
};

#endif // SETTINGS_H
