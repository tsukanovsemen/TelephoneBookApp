#include "contact_model.h"

#include <QDebug>

int TelephoneBookModel::ContactModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _contacts.size();
}

QVariant TelephoneBookModel::ContactModel::data(const QModelIndex &index, int role) const
{
    const auto contact = _contacts.at(index.row());

    if (role == ContactRole)
        return QVariant::fromValue(contact);

    return QVariant();
}

QHash<int, QByteArray> TelephoneBookModel::ContactModel::roleNames() const
{
    return { { Roles::ContactRole, "contact" } };
}

void TelephoneBookModel::ContactModel::addContact() noexcept
{
    auto lastIndex = _contacts.size();

    beginInsertRows(QModelIndex(), lastIndex, lastIndex);
    {
        _contacts.push_back(new Contact(this));
    }
    endInsertRows();
}

void TelephoneBookModel::ContactModel::addContact(Contact *contact) noexcept
{
    auto lastIndex = _contacts.size();

    beginInsertRows(QModelIndex(), lastIndex, lastIndex);
    {
        _contacts.push_back(contact);
    }
    endInsertRows();
}

void TelephoneBookModel::ContactModel::removeContact() noexcept
{
    if (_contacts.isEmpty()) {
        qWarning() << "Can't remove contact, Contacts list is empty";
        return;
    }

    auto lastIndex = _contacts.size() - 1;

    beginRemoveRows(QModelIndex(), lastIndex, lastIndex);
    {
        auto deletingContact = _contacts.last();
        _contacts.removeLast();
        delete deletingContact;
    }
    endRemoveRows();
}

void TelephoneBookModel::ContactModel::removeContactByIndex(int index) noexcept
{
    beginRemoveRows(QModelIndex(), index, index);
    {
        auto deletingContact = _contacts.at(index);
        _contacts.remove(index);
        delete deletingContact;
    }
    endRemoveRows();
}

TelephoneBookModel::Contact *TelephoneBookModel::ContactModel::contactByIndex(uint index) noexcept
{
    if (index >= _contacts.size()) {
        qWarning() << "Index is not valid";
        return nullptr;
    }

    return _contacts.at(index);
}
