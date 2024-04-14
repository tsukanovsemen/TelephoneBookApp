#ifndef CONTACT_MODEL_H
#define CONTACT_MODEL_H

#include <QObject>
#include <QPointer>

#include "i_contact.h"
#include "i_contact_model.h"
#include "TelephoneBookModel_export.h"

namespace TelephoneBookModel {
    /*!
     * \brief Contact's list model
     */
    class TELEPHONEBOOKMODEL_EXPORT ContactModel : public IContactModel
    {
        Q_OBJECT

    public:
        enum Roles
        {
            ContactRole = Qt::UserRole + 1
        };

        /*!
         * \brief default constructor
         */
        explicit ContactModel() = default;

        // QAbstractListModel interface

        /*!
         * \brief rowCount - return model size
         * \param parent - model index
         * \return model size
         */
        int rowCount(const QModelIndex &parent) const override;

        /*!
         * \brief data - return data of concrete contact
         * \param index - index of concrete contact
         * \param role - data's role
         * \return - data
         */
        QVariant data(const QModelIndex &index, int role) const override;

        /*!
         * \brief roleNames - return roles alias
         * \return roles alias
         */
        QHash<int, QByteArray> roleNames() const override;

        /*!
         * \brief addContact - add new contact
         */
        void addContact() noexcept override;

        /*!
         * \brief addContact - add outer contact
         * \param contact - new contact
         */
        void addContact(IContact *contact) noexcept override;

        /*!
         * \brief removeContact - remove last contact
         */
        void removeContact() noexcept override;

        /*!
         * \brief removeContactByIndex - remove contact by index
         */
        void removeContactByIndex(int index) noexcept override;

        /*!
         * \brief contactByIndex - return contact by index
         */
        IContact *contactByIndex(uint index) noexcept override;

    private:
        QVector<QPointer<IContact>> _contacts; ///< list contacts
    };
} // end namespace TelephoneBookModel

#endif // CONTACT_MODEL_H
