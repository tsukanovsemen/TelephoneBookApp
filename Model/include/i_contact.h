#ifndef I_CONTACT_H
#define I_CONTACT_H

#include <QObject>

#include "TelephoneBookModel_export.h"

namespace TelephoneBookModel {
    class TELEPHONEBOOKMODEL_EXPORT IContact : public QObject
    {
        Q_OBJECT

        /*!
         * \brief Runtime using email
         */
        Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)

        /*!
         * \brief Runtime using tel number
         */
        Q_PROPERTY(QString telephoneNumber READ telephoneNumber WRITE setTelephoneNumber NOTIFY
                    telephoneNumberChanged)

    public:
        /*!
         * \brief IContact - set parent object
         * \param parent
         */
        explicit IContact(QObject *parent) : QObject(parent)
        {}

        /*!
         * \brief IContact - defaul constructor
         */
        explicit IContact() = default;

        /*!
         * \brief email - return email of contact
         * \return contact's email
         */
        virtual QString email() const = 0;

        /*!
         * \brief setEmail - email setter
         * \param email - new email
         */
        virtual void setEmail(const QString &email) noexcept = 0;

        /*!
         * \brief signal of changing email
         */
        Q_SIGNAL void emailChanged(const QString &email);

        /*!
         * \brief telephoneNumbe - telephone number
         * \return numer telephone of contact
         */
        virtual QString telephoneNumber() const = 0;

        /*!
         * \brief setTelephoneNumber - setter of telephone number
         * \param telephoneNumber - tel number
         */
        virtual void setTelephoneNumber(const QString &telephoneNumber) noexcept = 0;

        /*!
         * \brief signal of changing tel number
         */
        Q_SIGNAL void telephoneNumberChanged(const QString &telephoneNumber);
    };
} // end namespace TelephoneBookModel

#endif // I_CONTACT_H
