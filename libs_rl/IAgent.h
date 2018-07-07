#ifndef _I_AGENT_H_
#define _I_AGENT_H_

#include <State.h>
#include <IEnvironment.h>

class IAgent
{
  protected:
    IEnvironment *env;

  public:
    IAgent(IEnvironment &env_);
    IAgent(IAgent& other);
    IAgent(const IAgent& other);

    virtual ~IAgent();
    IAgent& operator= (IAgent& other);
    IAgent& operator= (const IAgent& other);

    unsigned long int id();

  public:
    virtual void process();
};

#endif
