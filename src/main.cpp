#include <iostream>

#include <QApplication>
#include <QCommandLineParser>
#include <QUrl>
#include <QDir>

#include <KAboutData>
#include <KLocalizedString>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  KLocalizedString::setApplicationDomain("omr-demonstrator");

  KAboutData aboutData(
      // The program name used internally. (componentName)
      QStringLiteral("omr-demonstrator"),
      // A displayable program name string. (displayName)
      i18n("OMR Demonstrator"),
      // The program version string. (version)
      QStringLiteral("0.1"),
      // Short description of what the app does. (shortDescription)
      i18n("OMR algorithm explorer"),
      // The license this code is released under
      KAboutLicense::GPL,
      // Copyright Statement (copyrightStatement = QString())
      i18n("(c) 2020"),
      // Optional text shown in the About box.
      // Can contain any information desired. (otherText)
      i18n("Explore algorithms used for the Optical Recognition of Music Scores (OMR)"),
      // The program homepage string. (homePageAddress = QString())
      QStringLiteral("https://github.com/kwon-young/omr-demonstrator"),
      // The bug report email address
      // (bugsEmailAddress = QLatin1String("submit@bugs.kde.org")
      QStringLiteral("kwon-young.choi@hotmail.fr"));
  aboutData.addAuthor(i18n("Kwon-Young Choi"), i18n(""),
                      QStringLiteral("kwon-young.choi@hotmail.fr"),
                      QStringLiteral("https://kwon-young.github.io"),
                      QStringLiteral("kwon-young"));
  KAboutData::setApplicationData(aboutData);

  QCommandLineParser parser;
  aboutData.setupCommandLine(&parser);
  parser.process(app);
  aboutData.processCommandLine(&parser);

  auto window = new MainWindow();
  window->show();

  return app.exec();
}
