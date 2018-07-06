#include <iostream>
#include <MouseAndCliff.h>
#include <TableAgent.h>

int main()
{
    MouseAndCliff env;
    TableAgent agent_learn(env);

    for (unsigned int i = 0; i < 100000; i++)
      agent_learn.process();

    TableAgent agent_trained(agent_learn);
    agent_trained.set_e(0.0);


    for (unsigned int i = 0; i < 10000; i++)
    {
      env.print();
      agent_learn.process();
    }

  std::cout << "program done\n";
  return 0;
}
