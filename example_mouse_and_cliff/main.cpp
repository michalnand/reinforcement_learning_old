#include <iostream>
#include <MouseAndCliff.h>
#include <TableAgent.h>
#include <NNAgent.h>



int main()
{
    MouseAndCliff env;

    NNAgent agent(env);
    agent.set_e(0.2);

    unsigned int training_iterations = 500000;
    for (unsigned int i = 0; i < training_iterations; i++)
    {
      agent.process();
      if ((i%100) == 0)
        std::cout << "training done " << i*100.0/training_iterations << "%\n";
    }

    env.reset_score();

    for (unsigned int i = 0; i < 10000; i++)
    {
      env.print();
      agent.process();
    }
    
    std::cout << "program done\n";
    return 0;
}
