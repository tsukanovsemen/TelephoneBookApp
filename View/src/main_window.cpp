#include "main_window.h"

TelephoneBookView::MainWindow::MainWindow(QQmlApplicationEngine *engine) : _engine(engine)
{
    const QUrl mainUrl = QUrl("qrc:/main.qml");
    engine->setBaseUrl(mainUrl);
    engine->load(mainUrl);
}
