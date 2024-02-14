#include <QApplication>
#include <QTextEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;
    QTextEdit *textEdit = new QTextEdit(&window);
    window.setCentralWidget(textEdit);

    QMenuBar *menuBar = window.menuBar();
    QMenu *fileMenu = menuBar->addMenu("File");

    QAction *newAction = new QAction("New", &window);
    fileMenu->addAction(newAction);

    QAction *openAction = new QAction("Open", &window);
    fileMenu->addAction(openAction);

    QAction *saveAction = new QAction("Save", &window);
    fileMenu->addAction(saveAction);

    QAction *exitAction = new QAction("Exit", &window);
    fileMenu->addAction(exitAction);

    QObject::connect(newAction, &QAction::triggered, textEdit, &QTextEdit::clear);
    QObject::connect(openAction, &QAction::triggered, textEdit, &QTextEdit::clear);
    QObject::connect(saveAction, &QAction::triggered, textEdit, &QTextEdit::clear);
    QObject::connect(exitAction, &QAction::triggered, &app, &QApplication::quit);

    window.show();

    return app.exec();
}