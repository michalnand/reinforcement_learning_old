#include "QBatch.h"

#include <iostream>

QBatch::QBatch(unsigned int size)
{
  batch.resize(size);
  current_ptr = 0;
}

QBatch::QBatch(QBatch& other)
{
  batch = other.batch;
  current_ptr = other.current_ptr;
}

QBatch::QBatch(const QBatch& other)
{
  batch = other.batch;
  current_ptr = other.current_ptr;
}

QBatch::~QBatch()
{

}

QBatch& QBatch::operator= (QBatch& other)
{
  batch = other.batch;
  current_ptr = other.current_ptr;

  return *this;
}

QBatch& QBatch::operator= (const QBatch& other)
{
  batch = other.batch;
  current_ptr = other.current_ptr;

  return *this;
}

void QBatch::resize(unsigned int size)
{
  batch.resize(size);
}

void QBatch::compute(float gamma)
{
  unsigned int last = current_ptr;
  batch[last].q = batch[last].reward;

  for (int i = last; i > 0; i--)
    batch[i-1].q = batch[i-1].reward + gamma*batch[i].q;
}

bool QBatch::add(State &state, unsigned int action, float reward)
{
  if (current_ptr < batch.size())
  {
    batch[current_ptr].state  = state;
    batch[current_ptr].action = action;
    batch[current_ptr].reward = reward;
    batch[current_ptr].q      = 0.0;

    current_ptr++;

    return true;
  }

  return false;
}

bool QBatch::is_full()
{
  if (current_ptr < batch.size())
    return false;
  return true;
}

void QBatch::clean()
{
  current_ptr = 0;
}


QBatchItem& QBatch::get(unsigned int idx)
{
  return batch[idx];
}

QBatchItem& QBatch::get_random()
{
  return get(rand()%current_ptr);
}

void QBatch::print()
{
  for (unsigned int i = 0; i < current_ptr; i++)
  {
    std::cout << i << " " << batch[i].reward << " " << batch[i].q << "\n";
    batch[i].state.print();
    std::cout << "\n";
  }
}
