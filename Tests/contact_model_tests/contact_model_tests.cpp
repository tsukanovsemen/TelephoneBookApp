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
{
    // Arrange
    TelephoneBookModel::ContactModel contactModel;

    auto contact1 = new TelephoneBookModel::Contact();
    auto contact1Email = "first";
    contact1->setEmail(contact1Email);

    auto contact2 = new TelephoneBookModel::Contact();
    auto contact2Email = "second";
    contact2->setEmail(contact2Email);

    auto expectedEmail = contact1Email;
    auto expectedSize = 1;

    contactModel.addContact(contact1);
    contactModel.addContact(contact2);

    // Act
    contactModel.removeContact();
    auto actualSize = contactModel.rowCount(QModelIndex());
    auto actualEmail = contactModel.contactByIndex(actualSize - 1)->email();

    // Assert
    QCOMPARE(actualEmail, expectedEmail);
    QCOMPARE(actualSize, expectedSize);
}

void ContactModelTests::removeContactByIndex()
{
    // Arrange
    TelephoneBookModel::ContactModel contactModel;

    auto index = 0;

    auto contact1 = new TelephoneBookModel::Contact();
    auto contact1Email = "first";
    contact1->setEmail(contact1Email);

    auto contact2 = new TelephoneBookModel::Contact();
    auto contact2Email = "second";
    contact2->setEmail(contact2Email);

    auto expectedEmail = contact2Email;
    auto expectedSize = 1;

    contactModel.addContact(contact1);
    contactModel.addContact(contact2);

    // Act
    contactModel.removeContactByIndex(index);
    auto actualSize = contactModel.rowCount(QModelIndex());
    auto actualEmail = contactModel.contactByIndex(actualSize - 1)->email();

    // Assert
    QCOMPARE(actualEmail, expectedEmail);
    QCOMPARE(actualSize, expectedSize);
}

void ContactModelTests::contactByIndex()
{
    // Arrange
    TelephoneBookModel::ContactModel contactModel;

    auto index = 1;

    auto contact1 = new TelephoneBookModel::Contact();
    auto contact2 = new TelephoneBookModel::Contact();
    auto contact3 = new TelephoneBookModel::Contact();

    contactModel.addContact(contact1);
    contactModel.addContact(contact2);
    contactModel.addContact(contact3);

    auto email = "abcd";
    auto telNumber = "1234";

    contact2->setEmail(email);
    contact2->setTelephoneNumber(telNumber);

    auto expectedEmail = email;
    auto expectedTelNumber = telNumber;

    // Act
    auto actContact = contactModel.contactByIndex(index);
    auto actualEmail = actContact->email();
    auto actualTelNumber = actContact->telephoneNumber();

    // Assert
    QCOMPARE(actualEmail, expectedEmail);
    QCOMPARE(actualTelNumber, expectedTelNumber);
}

QTEST_MAIN(ContactModelTests)
#include "contact_model_tests.moc"
