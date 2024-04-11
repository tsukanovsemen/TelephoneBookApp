#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>

#include "TelephoneBookModel_export.h"
#include "i_contact.h"

namespace TelephoneBookModel {

    /*!
     * \brief Buisness logic Contact
     */
    class TELEPHONEBOOKMODEL_EXPORT Contact final : public IContact
    {
        Q_OBJECT

    public:
        /*!
         * \brief Contact - default constructor
         */
        explicit Contact() = default;

        /*!
         * \brief email - return email of contact
         * \return contact's email
         */
        QString email() const override;

        /*!
         * \brief setEmail - email setter
         * \param email - new email
         */
        void setEmail(const QString &email) noexcept override;

        /*!
         * \brief telephoneNumbe - telephone number
         * \return numer telephone of contact
         */
        QString telephoneNumber() const override;

        /*!
         * \brief setTelephoneNumber - setter of telephone number
         * \param telephoneNumber - tel number
         */
        void setTelephoneNumber(const QString &telephoneNumber) noexcept override;

    private:
        QString _email { " " }; ///< contact's email
        QString _telephoneNumber { " " }; ///< contact tel number
    };
} // end namespace TelephoneBookModel

#endif // CONTACT_H
