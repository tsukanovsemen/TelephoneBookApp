#include "application.h"

#include "contact_model.h"

namespace {
    static void registerTypes()
    {
        qRegisterMetaType<TelephoneBookModel::ContactModel *>("ContactModel *");
    }
}
Q_CONSTRUCTOR_FUNCTION(registerTypes)

Application::Application() : _engine(std::make_unique<QQmlApplicationEngine>())
{}

void Application::start()
{
    _mainWindow = std::make_unique<TelephoneBookView::MainWindow>(
     _engine.get(), std::unique_ptr<TelephoneBookModel::ContactModel>());
}
