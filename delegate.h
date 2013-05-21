#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>

class Delegate : public QItemDelegate
{
   Q_OBJECT
public:
   Delegate(QObject *parent = 0);
   void setEditorData(QWidget *editor,
					  const QModelIndex &index) const;
   void setModelData(QWidget *editor,
					 QAbstractItemModel *model,
					 const QModelIndex &index) const;
};

#endif // DELEGATE_H
