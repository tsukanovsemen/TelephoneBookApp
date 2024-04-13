#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QQmlApplicationEngine>
#include <QPointer>

#include "TelephoneBookView_export.h"

namespace TelephoneBookView {

    /*!
     * \brief The MainWindow
     */
    class TELEPHONEBOOKVIEW_EXPORT MainWindow : public QObject
    {
        Q_OBJECT
    public:
        MainWindow(QQmlApplicationEngine *engine);

    private:
        QPointer<QQmlApplicationEngine> _engine;
    };
}

#endif // MAIN_WINDOW_H
