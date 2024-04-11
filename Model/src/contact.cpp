#include "contact.h"

#include <QDebug>

#include "contact_tools_validate.h"

QString TelephoneBookModel::Contact::email() const
{
    return _email;
}

void TelephoneBookModel::Contact::setEmail(const QString &email) noexcept
{
    if (_email == email)
        return;

    try {
        ContactToolsValidate::validateEmail(email);
    } catch (const QString errorMessage) {
        qWarning() << "Error!" << errorMessage;
        return;
    }

    _email = email;
    emit emailChanged(email);
}

QString TelephoneBookModel::Contact::telephoneNumber() const
{
    return _telephoneNumber;
}

void TelephoneBookModel::Contact::setTelephoneNumber(const QString &telephoneNumber) noexcept
{
    if (_telephoneNumber == telephoneNumber)
        return;

    try {
        ContactToolsValidate::validateTelephoneNumber(telephoneNumber);
    } catch (const QString errorMessage) {
        qWarning() << "Error!" << errorMessage;
        return;
    }

    _telephoneNumber = telephoneNumber;
    emit telephoneNumberChanged(telephoneNumber);
}
