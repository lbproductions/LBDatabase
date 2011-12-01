#ifndef RELATION_H
#define RELATION_H

#include "listattribute.h"
#include "databaseattribute.h"
#include "table.h"
#include <QObject>

namespace Database {

class Relation : public QObject
{
    Q_OBJECT
public:
    Relation();

    virtual void insertElementAtStartup(Row * /*element*/) {}
};

template<class Owner, class Element>
class OneToManyRelation : public ListAttribute<Element*,Owner,Relation>, public Relation
{
public:
    OneToManyRelation(const QString &name, const QString &displayName, Row *owner);

private:
    friend class Table<Element>;

    void insertElementAtStartup(Row *element);
};

template<class Owner, class Element>
OneToManyRelation<Owner, Element>::OneToManyRelation(const QString &name, const QString &displayName, Row *owner) :
    ListAttribute<Element*,Owner,Relation>(name,displayName,owner),
    Relation()
{
    Attribute<QList<Element*>,Owner,Relation>::changeValue(QList<Element*>());
    owner->addRelation(this);
}

template<class Owner, class Element>
void OneToManyRelation<Owner, Element>::insertElementAtStartup(Row* element)
{
    Attribute<QList<Element*>,Owner,Relation>::m_value.append(static_cast<Element*>(element));
}

template<class Element, class Parent>
class ChildRelation : public Attribute<Parent*, Element, ChildRelation<Element,Parent> >, public Relation
{
public:
    ChildRelation(const QString &name, const QString &displayName, Row *owner);

private:
    Parent* calculate_parent();

    DatabaseAttribute<int, Element, ChildRelation<Element,Parent> >* m_parentId;
};

template<class Element, class Parent>
ChildRelation<Element,Parent>::ChildRelation(const QString &name, const QString &displayName, Row *owner) :
    Attribute<Parent*,Element,ChildRelation<Element,Parent> >(name,displayName,owner),
    Relation()
{
    m_parentId = new DatabaseAttribute<int,Element,ChildRelation<Element,Parent> >(name+"Id",name+"Id",owner);
    owner->registerAttribute(m_parentId);
    owner->registerAttribute(this);
    this->setCalculationFunction(this, &ChildRelation<Element,Parent>::calculate_parent);
}

template<class Element, class Parent>
Parent* ChildRelation<Element,Parent>::calculate_parent()
{
    Row* owner = static_cast<Row*>(Attribute<Parent*,Element,ChildRelation<Element,Parent> >::m_owner);
    return static_cast<Parent*>(owner->table()->rowById(m_parentId->value()));
}


} //namespace Database
#endif // RELATION_H
