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
    static bool ChangeSamplerate;
    static bool SkipExistingFiles;
    static bool Multithreading;
};

#endif // SETTINGS_H