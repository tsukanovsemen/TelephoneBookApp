#include "contact_tools_validate.h"

#include <format>

bool TelephoneBookModel::ContactToolsValidate::validateTelephoneNumber(
 const QString &telephoneNumber)
{
    QString availableCharacters = "1234567890+()-";

    for (const auto character : telephoneNumber) {
        if (!availableCharacters.contains(character)) {
            QString errorMessage("Not available symbol for telephone number ");
            throw errorMessage.append(character);
            return false;
        }
    }

    return true;
}

bool TelephoneBookModel::ContactToolsValidate::validateEmail(const QString &email)
{
    QString notAvailableCharacters = "`~!#$%^&*()_-+=\\|?//><'\":;";

    for (const auto notAvailableCharacter : notAvailableCharacters) {
        if (email.contains(notAvailableCharacter)) {
            QString errorMessage("Not available symbol for email ");
            throw errorMessage.append(notAvailableCharacter);
            return false;
        }
    }

    return true;
}
