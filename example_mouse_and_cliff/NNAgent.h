#ifndef _NN_AGENT_H_
#define _NN_AGENT_H_

#include <IAgent.h>
#include <cnn.h>
#include <QBatch.h>

class NNAgent: public IAgent
{
  private:
    float gamma, e;

    CNN *nn;
    QBatch q_batch;

    std::vector<float> q_values;

    std::vector<std::vector<float>> q;

  public:
    NNAgent(IEnvironment &env_);
    NNAgent(NNAgent& other);
    NNAgent(const NNAgent& other);

    virtual ~NNAgent();
    NNAgent& operator= (NNAgent& other);
    NNAgent& operator= (const NNAgent& other);

  public:
    void process(bool learn = true);

    void set_gamma(float gamma)
    {
      this->gamma = gamma;
    }

    void set_e(float e)
    {
      this->e = e;
    }

  private:
    unsigned int select_action(std::vector<float> &q_values, float e);
    unsigned int argmax(std::vector<float> &v);


};

#endif
