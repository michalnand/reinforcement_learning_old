#ifndef _Q_BATCH_H_
#define _Q_BATCH_H_


#include <QBatchItem.h>

class QBatch
{
  private:
    std::vector<QBatchItem> batch;
    unsigned int current_ptr;

  public:
    QBatch(unsigned int size = 0);
    QBatch(QBatch& other);
    QBatch(const QBatch& other);

    virtual ~QBatch();

    QBatch& operator= (QBatch& other);
    QBatch& operator= (const QBatch& other);

    void resize(unsigned int size);


  public:
    bool add(State &state, unsigned int action, float reward);
    bool is_full();

    void clean();

    void compute(float gamma);

    QBatchItem& get(unsigned int idx);
    QBatchItem& get_random();

    void print();

};


#endif
