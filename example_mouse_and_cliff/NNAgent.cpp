#include "NNAgent.h"

#define NNAgentDefaultGamma   ((float)0.9)
#define NNAgentDefaultE       ((float)0.1)

NNAgent::NNAgent(IEnvironment &env_)
           :IAgent(env_)
{
  gamma = NNAgentDefaultGamma;
  e     = NNAgentDefaultE;

  std::string nn_config = "nn_parameters.json";
  sGeometry input_geometry;
  sGeometry output_geometry;

  input_geometry.w = env->w();
  input_geometry.h = env->h();
  input_geometry.d = env->d();

  output_geometry.w = 1;
  output_geometry.h = 1;
  output_geometry.d = env->get_actions_count();

//  nn = new CNN(nn_config, input_geometry, output_geometry);


  q_batch.resize(10000);

  q_values.resize(env->get_actions_count());


  q.resize(env->get_state().size());
  for (unsigned int j = 0; j < q.size(); j++)
    q[j].resize(env->get_actions_count());

  for (unsigned int j = 0; j < q.size(); j++)
    for (unsigned int i = 0; i < q[j].size(); i++)
      q[j][i] = (((rand()%20000)/10000.0) - 1.0)*0.01;
}

NNAgent::NNAgent(NNAgent& other)
           :IAgent(other)
{
  gamma = NNAgentDefaultGamma;
  e     = NNAgentDefaultE;
}

NNAgent::NNAgent(const NNAgent& other)
           :IAgent(other)
{
  gamma = NNAgentDefaultGamma;
  e     = NNAgentDefaultE;
}

NNAgent::~NNAgent()
{
  /*
  if (nn != nullptr)
  {
    delete nn;
    nn = nullptr;
  }
  */
}

NNAgent& NNAgent::operator= (NNAgent& other)
{
  gamma       = other.gamma;
  e           = other.e;

  return *this;
}

NNAgent& NNAgent::operator= (const NNAgent& other)
{
  env         = other.env;

  gamma       = other.gamma;
  e           = other.e;

  return *this;
}

void NNAgent::process(bool learn)
{
  State state = env->get_state();

/*
  nn->forward_vector(q_values, state);
  unsigned int action = select_action(q_values, e);
*/

  unsigned int state_idx = argmax(state);
  unsigned int action = select_action(q[state_idx], e);


  env->execute_action(action);

  if (learn)
  {
    q_batch.add(state, action, env->get_reward());

    if (q_batch.is_full())
    {
      q_batch.compute(gamma);

      for (unsigned int i = 0; i < q_batch.size(); i++)
      {
        QBatchItem item = q_batch.get_random();

        unsigned int state_idx = argmax(item.get_state_vector());

        q[state_idx][item.get_action()]+= 0.01*(item.get_q() - q[state_idx][item.get_action()]);


    //    nn->learn_single_output_vector(item.get_q(), item.get_state_vector(), item.get_action());
      }

      q_batch.clean();
    }
  }
}


unsigned int NNAgent::select_action(std::vector<float> &q_values, float e)
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

unsigned int NNAgent::argmax(std::vector<float> &v)
{
  unsigned int max_i = 0;
  for (unsigned int i = 0; i < v.size(); i++)
    if (v[i] > v[max_i])
      max_i = i;

  return max_i;
}
