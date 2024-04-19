#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QQmlApplicationEngine>

#include "main_window.h"

/*!
 * \brief Class wich start application
 */
class Application : public QObject
{
    Q_OBJECT

public:
    /*!
     * \brief Application - default constructor
     */
    explicit Application();

    /*!
     * \brief start - start app
     */
    void start();

private:
    std::unique_ptr<QQmlApplicationEngine> _engine; ///< qml engine
    std::unique_ptr<TelephoneBookView::MainWindow> _mainWindow; ///< main window app
};

#endif // APPLICATION_H
