#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QQmlApplicationEngine>
#include <QPointer>

#include "TelephoneBookView_export.h"
#include "i_contact_model.h"

namespace TelephoneBookView {

    /*!
     * \brief The MainWindow
     */
    class TELEPHONEBOOKVIEW_EXPORT MainWindow : public QObject
    {
        Q_OBJECT
    public:
        /*!
         * \brief MainWindow - create qml main window
         * \param engine
         */
        explicit MainWindow(QQmlApplicationEngine *engine,
                            std::unique_ptr<TelephoneBookModel::IContactModel> contactModel);

    private:
        /*!
         * \brief createMainComponent - create and set property of main component
         * \return true - if Success, false if fail
         */
        bool createMainComponent() noexcept;

    private:
        QPointer<QQmlApplicationEngine> _engine; ///< qml engine
        std::unique_ptr<TelephoneBookModel::IContactModel> _contactModel; ///< contact's model
        QString _qmlPath { "qrc:/main.qml" }; ///< path to main qml component
        const int _implicitWidth { 500 }; ///< required implicit width of window
        const int _implicitHeight { 750 }; ///< required implicit height of window
        const QString _titleName { "TelephoneBook App" };
        const QString _backgroundImagePath {"qrc:/images/background.jpg"};
    };
}

#endif // MAIN_WINDOW_H
