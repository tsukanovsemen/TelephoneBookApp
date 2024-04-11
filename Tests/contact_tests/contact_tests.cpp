#include <QtTest/QtTest>

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

}

void ContactTests::setTelephoneNumber_correctValue()
{

}

void ContactTests::setTelephoneNumber_incorrectValue()
{

}

QTEST_MAIN(ContactTests)
#include "contact_tests.moc"
