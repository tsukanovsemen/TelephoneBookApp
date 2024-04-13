#include <QtTest>

#include "contact_model.h"

class ContactModelTests : public QObject
{
    Q_OBJECT
public:
    explicit ContactModelTests() = default;

private:
    Q_SLOT void rowCount();
    Q_SLOT void data_model();
    Q_SLOT void addContact();
    Q_SLOT void addContact_withParameters();
    Q_SLOT void removeContact();
    Q_SLOT void removeContactByIndex();
    Q_SLOT void contactByIndex();
};

void ContactModelTests::rowCount()
{
    // Arrange
    TelephoneBookModel::ContactModel contactModel;
    int expectedValue = 10;

    for (int i = 0; i < expectedValue; ++i) {
        contactModel.addContact();
    }

    // Act
    auto actualValue = contactModel.rowCount(QModelIndex());

    // Assert
    QCOMPARE(actualValue, expectedValue);
}

void ContactModelTests::data_model()
{
    // Arrange
    TelephoneBookModel::ContactModel contactModel;

    contactModel.addContact();
    contactModel.addContact();

    const int expectedIndex = 1;

    auto expectedContact = contactModel.contactByIndex(expectedIndex);

    // Act
    auto actualVariantContact =
     contactModel.data(contactModel.index(expectedIndex), contactModel.ContactRole);

    auto actualContact = actualVariantContact.value<TelephoneBookModel::Contact *>();

    // Assert
    QCOMPARE(actualContact, expectedContact);
}

void ContactModelTests::addContact()
{
    // Arrange
    TelephoneBookModel::ContactModel contactModel;
    auto expectedSize = 1;

    // Act
    contactModel.addContact();
    auto actualSize = contactModel.rowCount(QModelIndex());

    // Assert
    QCOMPARE(actualSize, expectedSize);
}

void ContactModelTests::addContact_withParameters()
{
    // Arrange
    TelephoneBookModel::ContactModel contactModel;
    TelephoneBookModel::Contact *contact = new TelephoneBookModel::Contact();
    auto email = "abs";
    auto telNumber = "8909";

    contact->setEmail(email);
    contact->setTelephoneNumber(telNumber);
    auto expectedSize = 1;
    auto expectedEmail = email;
    auto expectedTelNumber = telNumber;

    // Act
    contactModel.addContact(contact);
    auto actualSize = contactModel.rowCount(QModelIndex());
    auto actualContact = contactModel.contactByIndex(0);
    auto actualTelNumber = actualContact->telephoneNumber();
    auto actualEmail = actualContact->email();

    // Assert
    QCOMPARE(actualSize, expectedSize);
    QCOMPARE(actualTelNumber, expectedTelNumber);
    QCOMPARE(actualEmail, expectedEmail);
}

void ContactModelTests::removeContact()
{}

void ContactModelTests::removeContactByIndex()
{}

void ContactModelTests::contactByIndex()
{

}

QTEST_MAIN(ContactModelTests)
#include "contact_model_tests.moc"
