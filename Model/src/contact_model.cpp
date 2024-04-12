#include "contact_model.h"

int TelephoneBookModel::ContactModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? _contacts.size() : 0;
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

void TelephoneBookModel::ContactModel::removeContact() noexcept
{
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
