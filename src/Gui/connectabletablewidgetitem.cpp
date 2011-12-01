#include "connectabletablewidgetitem.h"

#include <QDebug>

namespace Gui {
namespace Misc {

ConnectableTableWidgetItem::ConnectableTableWidgetItem() :
    QObject(), QTableWidgetItem()
{
}

void ConnectableTableWidgetItem::setText(const QString &text)
{
    QTableWidgetItem::setText(text);
}

} // namespace Misc
} // namespace Gui
