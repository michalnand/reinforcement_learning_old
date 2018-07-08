#ifndef _Q_BATCH_ITEM_H_
#define _Q_BATCH_ITEM_H_

#include <State.h>
#include <vector>

class QBatch;

class QBatchItem
{
  friend QBatch;

  private:
    State state;
    unsigned int action;

    float reward, q;

  public:
    QBatchItem();
    QBatchItem(QBatchItem& other);
    QBatchItem(const QBatchItem& other);

    virtual ~QBatchItem();

    QBatchItem& operator= (QBatchItem& other);
    QBatchItem& operator= (const QBatchItem& other);

    std::vector<float>& get_state_vector()
    {
      return state;
    }

    float get_q()
    {
      return q;
    }

    unsigned int get_action()
    {
      return action;
    }
};

#endif
