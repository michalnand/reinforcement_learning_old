#ifndef _I_ENVIRONMENT_H_
#define _I_ENVIRONMENT_H_


#include <State.h>

class IEnvironment
{
  protected:
    State state;
    unsigned int actions_count;
    float reward, score;

  public:
    IEnvironment();
    IEnvironment(IEnvironment& other);
    IEnvironment(const IEnvironment& other);

    virtual ~IEnvironment();
    IEnvironment& operator= (IEnvironment& other);
    IEnvironment& operator= (const IEnvironment& other);

  public:
    State& get_state()
    {
      return state;
    }

    unsigned int get_actions_count()
    {
      return actions_count;
    }

    float get_reward()
    {
      return reward;
    }

    float get_score()
    {
      return score;
    }

  public:
    unsigned int w()
    {
      return state.w();
    }

    unsigned int h()
    {
      return state.h();
    }

    unsigned int d()
    {
      return state.d();
    }

  public:
    virtual void execute_action(unsigned int action_id);
    virtual void print();
};


#endif
