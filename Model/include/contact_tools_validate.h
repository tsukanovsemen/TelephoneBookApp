#ifndef CONTACT_TOOLS_VALIDATE_H
#define CONTACT_TOOLS_VALIDATE_H

#include <QString>

#include "TelephoneBookModel_export.h"

namespace TelephoneBookModel {
    /*!
     * \brief Tools for validate contact's fields
     */
    class TELEPHONEBOOKMODEL_EXPORT ContactToolsValidate
    {
    public:
        /*!
         * \brief ContactToolsValidate - default constructor
         */
        explicit ContactToolsValidate() = default;

        /*!
         * \brief validateTelephoneNumber - check validating tel number
         * \param telephoneNumber - tel number
         * \return true - if validate is ok, false - if fail
         */
        static bool validateTelephoneNumber(const QString &telephoneNumber);

        /*!
         * \brief validateEmail - check email
         * \param email - email
         * \return true - if ok, false if fail
         */
        static bool validateEmail(const QString &email);
    };
} // end namespace TelephoneBookModel

#endif // CONTACT_TOOLS_VALIDATE_H
