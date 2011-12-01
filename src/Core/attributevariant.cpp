#include "attributevariant.h"

#include <QDateTime>
#include <QObject>

AttributeVariant::AttributeVariant() :
    QVariant()
{
}

void AttributeVariant::setDisplayRole(DisplayRole role){
    m_currentRole = role;
}

QVariant AttributeVariant::displayVariant() const
{
     return QVariant();
}
