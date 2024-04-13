#include <QApplication>

#include "main_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    TelephoneBookView::MainWindow mainWindow(&engine);

    return app.exec();
}
