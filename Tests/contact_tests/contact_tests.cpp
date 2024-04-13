#include <QtTest>

#include <contact.h>

class ContactTests : public QObject
{
    Q_OBJECT

public:
    explicit ContactTests() = default;

private:
    Q_SLOT void setEmail_correctValue();
    Q_SLOT void setEmail_incorrectValue();

    Q_SLOT void setTelephoneNumber_correctValue();
    Q_SLOT void setTelephoneNumber_incorrectValue();
};

void ContactTests::setEmail_correctValue()
{
    // Arrange
    TelephoneBookModel::Contact contact;
    auto correctEmail = "sematsukanovvv@gmail.com";
    auto expectedResult = correctEmail;

    // Act
    contact.setEmail(correctEmail);
    auto actualResult = contact.email();

    // Assert
    QCOMPARE(actualResult, expectedResult);
}

void ContactTests::setEmail_incorrectValue()
{
    // Arrange
    TelephoneBookModel::Contact contact;
    auto currentEmail = "apple.semen@mail.ri";
    auto incorrectEmail = "`apple.semen@mail.ru-+";
    auto expectedEmail = currentEmail;
    contact.setEmail(currentEmail);

    // Act
    contact.setEmail(incorrectEmail);
    auto actualEmail = contact.email();

    // Assert
    QCOMPARE(actualEmail, expectedEmail);
}

void ContactTests::setTelephoneNumber_correctValue()
{
    // Arrange
    TelephoneBookModel::Contact contact;
    auto correctTelNumber = "+7(909)534-44-23";
    auto expectedTelNumber = correctTelNumber;

    // Act
    contact.setTelephoneNumber(correctTelNumber);
    auto actualTelNumber = contact.telephoneNumber();

    // Assert
    QCOMPARE(actualTelNumber, expectedTelNumber);
}

void ContactTests::setTelephoneNumber_incorrectValue()
{
    // Arrange
    TelephoneBookModel::Contact contact;
    auto currentTelNumber = "+7(909)534-44-23";
    auto incorrectTelNumber = "ABCD123";
    auto expectedTelNumber = currentTelNumber;
    contact.setTelephoneNumber(currentTelNumber);

    // Act
    contact.setTelephoneNumber(incorrectTelNumber);
    auto actualTelNumber = contact.telephoneNumber();

    // Assert
    QCOMPARE(actualTelNumber, expectedTelNumber);
}

QTEST_MAIN(ContactTests)
#include "contact_tests.moc"
