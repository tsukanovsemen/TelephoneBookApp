#ifndef I_CONTACT_MODEL_H
#define I_CONTACT_MODEL_H

#include <QAbstractListModel>
#include "TelephoneBookModel_export.h"

namespace TelephoneBookModel {
    class IContact;

    /*!
     * \brief Interface of ContactModel
     */
    class TELEPHONEBOOKMODEL_EXPORT IContactModel : public QAbstractListModel
    {
        Q_OBJECT

    public:
        /*!
         * \brief addContact - add new contact
         */
        virtual void addContact() noexcept = 0;

        /*!
         * \brief addContact - add outer contact
         * \param contact - new contact
         */
        virtual void addContact(IContact *contact) noexcept = 0;

        /*!
         * \brief removeContact - remove last contact
         */
        virtual void removeContact() noexcept = 0;

        /*!
         * \brief removeContactByIndex - remove contact by index
         */
        virtual void removeContactByIndex(int index) noexcept = 0;

        /*!
         * \brief contactByIndex - return contact by index
         */
        virtual IContact *contactByIndex(uint index) noexcept = 0;
    };

} // end namespace TelephoneBookModel

#endif // I_CONTACT_MODEL_H
