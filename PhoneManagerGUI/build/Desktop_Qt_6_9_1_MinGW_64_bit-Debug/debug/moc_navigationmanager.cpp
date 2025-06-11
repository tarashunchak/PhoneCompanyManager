/****************************************************************************
** Meta object code from reading C++ file 'navigationmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../NeoCom/PhoneCompanyManager/PhoneManagerGUI/includes/navigationmanager.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navigationmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN17NavigationManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto NavigationManager::qt_create_metaobjectdata<qt_meta_tag_ZN17NavigationManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "NavigationManager",
        "show_small_buttons",
        "",
        "hide_small_buttons",
        "open_chat",
        "showLoginPage",
        "showRegistrationPage",
        "showPasswordRecoveryPage",
        "showDashboardPage",
        "showCustomersPage",
        "showEmployeesPage",
        "showTariffsPage",
        "showRequestsPage",
        "showCustomersDetailsPage",
        "showChatsPage",
        "showEmployeesDetailsPage"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'show_small_buttons'
        QtMocHelpers::SignalData<void() const>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hide_small_buttons'
        QtMocHelpers::SignalData<void() const>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'open_chat'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'showLoginPage'
        QtMocHelpers::SlotData<void() const>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showRegistrationPage'
        QtMocHelpers::SlotData<void() const>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showPasswordRecoveryPage'
        QtMocHelpers::SlotData<void() const>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showDashboardPage'
        QtMocHelpers::SlotData<void() const>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showCustomersPage'
        QtMocHelpers::SlotData<void() const>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showEmployeesPage'
        QtMocHelpers::SlotData<void() const>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showTariffsPage'
        QtMocHelpers::SlotData<void() const>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showRequestsPage'
        QtMocHelpers::SlotData<void() const>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showCustomersDetailsPage'
        QtMocHelpers::SlotData<void(const uint) const>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 2 },
        }}),
        // Slot 'showChatsPage'
        QtMocHelpers::SlotData<void() const>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showEmployeesDetailsPage'
        QtMocHelpers::SlotData<void(const uint) const>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<NavigationManager, qt_meta_tag_ZN17NavigationManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject NavigationManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17NavigationManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17NavigationManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17NavigationManagerE_t>.metaTypes,
    nullptr
} };

void NavigationManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<NavigationManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->show_small_buttons(); break;
        case 1: _t->hide_small_buttons(); break;
        case 2: _t->open_chat((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->showLoginPage(); break;
        case 4: _t->showRegistrationPage(); break;
        case 5: _t->showPasswordRecoveryPage(); break;
        case 6: _t->showDashboardPage(); break;
        case 7: _t->showCustomersPage(); break;
        case 8: _t->showEmployeesPage(); break;
        case 9: _t->showTariffsPage(); break;
        case 10: _t->showRequestsPage(); break;
        case 11: _t->showCustomersDetailsPage((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        case 12: _t->showChatsPage(); break;
        case 13: _t->showEmployeesDetailsPage((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (NavigationManager::*)() const>(_a, &NavigationManager::show_small_buttons, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (NavigationManager::*)() const>(_a, &NavigationManager::hide_small_buttons, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (NavigationManager::*)(const QString & )>(_a, &NavigationManager::open_chat, 2))
            return;
    }
}

const QMetaObject *NavigationManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavigationManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17NavigationManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NavigationManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void NavigationManager::show_small_buttons()const
{
    QMetaObject::activate(const_cast< NavigationManager *>(this), &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NavigationManager::hide_small_buttons()const
{
    QMetaObject::activate(const_cast< NavigationManager *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NavigationManager::open_chat(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
