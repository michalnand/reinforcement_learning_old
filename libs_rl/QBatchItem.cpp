#include "QBatchItem.h"


QBatchItem::QBatchItem()
{
  action = 0;
  reward = 0.0;
  q = 0.0;
}

QBatchItem::QBatchItem(QBatchItem& other)
{
  action = other.action;
  reward = other.reward;
  q      = other.q;
  state  = other.state;
}

QBatchItem::QBatchItem(const QBatchItem& other)
{
  action = other.action;
  reward = other.reward;
  q      = other.q;
  state  = other.state;
}

QBatchItem::~QBatchItem()
{

}


QBatchItem& QBatchItem::operator= (QBatchItem& other)
{
  action = other.action;
  reward = other.reward;
  q      = other.q;
  state  = other.state;

  return *this;
}

QBatchItem& QBatchItem::operator= (const QBatchItem& other)
{
  action = other.action;
  reward = other.reward;
  q      = other.q;
  state  = other.state;

  return *this;
}
