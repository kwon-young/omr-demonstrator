#include "mainwindow.h"

#include <QApplication>
#include <QAction>
#include <QUrl>
#include <QFileDialog>
#include <QTextStream>

#include <KLocalizedString>
#include <KActionCollection>
#include <KTextEdit>
#include <KStandardAction>
#include <KIO/Job>
#include <KMessageBox>

MainWindow::MainWindow(QWidget *parent) :
  KXmlGuiWindow(parent),
  textArea(new KTextEdit()),
  filename(QString())
{
  setCentralWidget(textArea);
  setupActions();
}

void MainWindow::setupActions()
{
  auto clearAction = new QAction(this);
  clearAction->setText(i18n("&Clear"));
  clearAction->setIcon(QIcon::fromTheme("document-new"));
  actionCollection()->setDefaultShortcut(clearAction, Qt::CTRL + Qt::Key_W);
  actionCollection()->addAction("clear", clearAction);
  connect(clearAction, &QAction::triggered, textArea, &KTextEdit::clear);

  KStandardAction::quit(qApp, &QApplication::closeAllWindows, actionCollection());

  KStandardAction::open(this, SLOT(openFile()), actionCollection());

  setupGUI(Default, "omr-demonstratorui.rc");
}

void MainWindow::openFile()
{
  QUrl fileNameFromDialog = QFileDialog::getOpenFileUrl(this, i18n("Open File"));
  openFile(fileNameFromDialog);
}

void MainWindow::openFile(const QUrl &inputFileName)
{
  if (!inputFileName.isEmpty()) {
    KIO::Job* job = KIO::storedGet(inputFileName);
    filename = inputFileName.toLocalFile();
    connect(job, &KIO::Job::result, this, &MainWindow::downloadFinished);

    job->exec();
  }
}

void MainWindow::downloadFinished(KJob* job)
{
  if (job->error()) {
    KMessageBox::error(this, job->errorString());
    filename.clear();
    return;
  }

  auto storedJob = (KIO::StoredTransferJob*)job;
  textArea->setPlainText(QTextStream(storedJob->data(), QIODevice::ReadOnly).readAll());
}
