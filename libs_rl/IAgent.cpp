#include "IAgent.h"


IAgent::IAgent(IEnvironment &env_)
{
  this->env = &env_;
}

IAgent::IAgent(const IAgent &other)
{
  env = other.env;
}

IAgent::~IAgent()
{

}

IAgent& IAgent::operator= (const IAgent& other)
{
  env = other.env;

  return *this;
}

unsigned long int IAgent::id()
{
  return ((unsigned long int)this);
}

void IAgent::process()
{
  unsigned int action_id = rand()%env->get_actions_count();
  env->execute_action(action_id);
}
