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
{}

void ContactModelTests::removeContact()
{}

void ContactModelTests::removeContactByIndex()
{}

QTEST_MAIN(ContactModelTests)
#include "contact_model_tests.moc"
