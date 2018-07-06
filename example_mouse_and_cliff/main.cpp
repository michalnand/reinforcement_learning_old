#include <iostream>
#include <MouseAndCliff.h>


unsigned int arg_max(std::vector<float> v)
{
  unsigned int max_i = 0;
  for (unsigned int i = 0; i < v.size(); i++)
    if (v[i] > v[max_i])
      max_i = i;

  return max_i;
}

unsigned int select_action(std::vector<std::vector<float>> q, unsigned int state)
{
  unsigned int best_action = 0;
  float best = -10000000.0;

  for (unsigned int i = 0; i < q[state].size(); i++)
  {
    if (q[state][i] > best)
    {
      best = q[state][i];
      best_action = i;
    }
  }

  if ((rand()%100) < 10)
    best_action = rand()%q[state].size();

  return best_action;
}

int main()
{
  MouseAndCliff env;

  std::vector<std::vector<float>> q(env.get_state().size());

  for (unsigned int j = 0; j < q.size(); j++)
  {
    q[j].resize(env.get_actions_count());

    for (unsigned int i = 0; i < env.get_actions_count(); i++)
      q[j][i] = 0.0;
  }

  unsigned int state_prev = 0;
  unsigned int state = 0;

  unsigned int action_prev = 0;
  unsigned int action = 0;

  float alpha = 0.1;
  float gamma = 0.8;

  while (1)
  {
    env.print();

    state_prev = state;
    state = arg_max(env.get_state());

    action_prev = action;
    action = select_action(q, state);

    //SARSA
    q[state_prev][action_prev]+= alpha*(env.get_reward() + gamma*q[state][action] - q[state_prev][action_prev]);

    env.execute_action(action);
   }


  std::cout << "program done\n";
  return 0;
}
