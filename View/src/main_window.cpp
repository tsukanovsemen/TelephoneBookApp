#include "main_window.h"

#include <QQmlComponent>

#include "contact_model.h"

namespace {
    static void registerTypes()
    {
        // using namespace TelephoneBookModel;

        // qRegisterMetaType<TelephoneBookModel::IContactModel *>("TelephoneBookModel::IContactModel
        // *");
        // qmlRegisterInterface<TelephoneBookModel::IContactModel>("TelephoneBookModel::IContactModel",);
    }
}
Q_CONSTRUCTOR_FUNCTION(registerTypes)

TelephoneBookView::MainWindow::MainWindow(
 QQmlApplicationEngine *engine, std::unique_ptr<TelephoneBookModel::IContactModel> contactModel) :
    _engine(engine),
    _contactModel(std::move(contactModel))
{
    const QUrl mainUrl = QUrl(_qmlPath);
    _engine->setBaseUrl(mainUrl);

    createMainComponent();
}

bool TelephoneBookView::MainWindow::createMainComponent() noexcept
{
    QQmlComponent component(_engine.data(), QUrl(_qmlPath));

    auto object = component.beginCreate(_engine->rootContext());
    if (!object) {
        qWarning() << "Cannot create qml component" << component.errorString();
        return false;
    }

    TelephoneBookModel::ContactModel *cm = new  TelephoneBookModel::ContactModel();

    object->setProperty("width", QVariant::fromValue(_implicitWidth));
    object->setProperty("height", QVariant::fromValue(_implicitHeight));
    object->setProperty("title", QVariant::fromValue(_titleName));
    object->setProperty("backgroundImage", QVariant::fromValue(_backgroundImagePath));
    object->setProperty("contactModel", QVariant::fromValue(cm));

    component.completeCreate();

    return true;
}
