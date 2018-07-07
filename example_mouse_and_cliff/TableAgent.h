#ifndef _TABLE_AGENT_H_
#define _TABLE_AGENT_H_

#include <IAgent.h>

class TableAgent: public IAgent
{
  private:
    std::vector<std::vector<float>> q;

    unsigned int state, state_prev;
    unsigned int action, action_prev;

    float alpha, gamma, e;

  public:
    TableAgent(IEnvironment &env_);
    TableAgent(TableAgent& other);
    TableAgent(const TableAgent& other);

    virtual ~TableAgent();
    TableAgent& operator= (TableAgent& other);
    TableAgent& operator= (const TableAgent& other);

  public:
    void process();

    void set_alpha(float alpha)
    {
      this->alpha = alpha;
    }

    void set_gamma(float gamma)
    {
      this->gamma = gamma;
    }

    void set_e(float e)
    {
      this->e = e;
    }


  private:
    unsigned int arg_max(std::vector<float> &v);
    unsigned int select_action(std::vector<float> &q_values, float e);

};

#endif
