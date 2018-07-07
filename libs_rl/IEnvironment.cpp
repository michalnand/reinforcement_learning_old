#include "IEnvironment.h"


IEnvironment::IEnvironment()
{
  actions_count = 0;
  reward        = 0.0;
  score         = 0.0;
}

IEnvironment::IEnvironment(IEnvironment& other)
{
  state         = other.state;
  actions_count = other.actions_count;
  reward        = other.reward;
}

IEnvironment::IEnvironment(const IEnvironment& other)
{
  state         = other.state;
  actions_count = other.actions_count;
  reward        = other.reward;
}

IEnvironment::~IEnvironment()
{

}

IEnvironment& IEnvironment::operator= (IEnvironment& other)
{
  state         = other.state;
  actions_count = other.actions_count;
  reward        = other.reward;

  return *this;
}

IEnvironment& IEnvironment::operator= (const IEnvironment& other)
{
  state         = other.state;
  actions_count = other.actions_count;
  reward        = other.reward;

  return *this;
}

void IEnvironment::execute_action(unsigned int action_id)
{
  (void)action_id;
}

void IEnvironment::print()
{

}
