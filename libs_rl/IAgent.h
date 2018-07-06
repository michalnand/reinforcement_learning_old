#ifndef _I_AGENT_H_
#define _I_AGENT_H_

#include <State.h>

class IAgent
{
  protected:
    State state;


    void process(IEnvironment &environment);

  protected:
    
};

#endif
