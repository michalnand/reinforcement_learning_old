#include "TableAgent.h"



TableAgent::TableAgent(IEnvironment &env_)
           :IAgent(env_)
{

  q.resize(env->get_state().size());
  for (unsigned int j = 0; j < q.size(); j++)
    q[j].resize(env->get_actions_count());

  for (unsigned int j = 0; j < q.size(); j++)
    for (unsigned int i = 0; i < q[j].size(); i++)
      q[j][i] = 0.0;

  state       = 0;
  state_prev  = 0;
  action      = 0;
  action_prev = 0;

  alpha = 0.1;
  gamma = 0.8;
  e     = 0.1;
}

TableAgent::TableAgent(const TableAgent& other)
           :IAgent(other)
{
  q           = other.q;
  state       = other.state;
  state_prev  = other.state_prev;
  action      = other.action;
  action_prev = other.action_prev;

  alpha = 0.1;
  gamma = 0.8;
  e     = 0.1;
}

TableAgent::~TableAgent()
{

}

TableAgent& TableAgent::operator= (const TableAgent& other)
{
  env         = other.env;

  q           = other.q;
  state       = other.state;
  state_prev  = other.state_prev;
  action      = other.action;
  action_prev = other.action_prev;

  alpha       = other.alpha;
  gamma       = other.gamma;
  e           = other.e;

  return *this;
}

void TableAgent::process()
{
  state_prev = state;
  state = arg_max(env->get_state());

  action_prev = action;
  action = select_action(q[state], e);

  //SARSA
  float reward = env->get_reward();
  q[state_prev][action_prev]+= alpha*(reward + gamma*q[state][action] - q[state_prev][action_prev]);

  env->execute_action(action);
}


unsigned int TableAgent::arg_max(std::vector<float> &v)
{
  unsigned int max_i = 0;
  for (unsigned int i = 0; i < v.size(); i++)
    if (v[i] > v[max_i])
      max_i = i;

  return max_i;
}

unsigned int TableAgent::select_action(std::vector<float> &q_values, float e)
{
  unsigned int best_action = 0;
  float best = -1000000000.0;

  for (unsigned int i = 0; i < q_values.size(); i++)
  {
    if (q_values[i] > best)
    {
      best = q_values[i];
      best_action = i;
    }
  }

  float r = (rand()%1000000)/1000000.0;

  if (r < e)
    best_action = rand()%q_values.size();

  return best_action;
}
