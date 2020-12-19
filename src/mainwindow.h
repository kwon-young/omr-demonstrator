#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <KXmlGuiWindow>

class KTextEdit;
class KJob;

class MainWindow: public KXmlGuiWindow
{

  Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent=nullptr);
    void openFile(const QUrl &inputFileName);

  private:
    void setupActions();

  private slots:
    void openFile();

    void downloadFinished(KJob* job);

  private:
    KTextEdit* textArea;
    QString filename;
};

#endif /* ifndef MAINWINDOW_H */
