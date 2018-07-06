#ifndef _ACTIONS_H_
#define _ACTIONS_H_

class Actions
{
  protected:
    std::vector<float> m_actions;

  public:
    Action();
    Action(unsigned int actions_count);
    Action(Action &rhs);

    virtual ~Action();

    Action& operator =(Action &rhs);
    operator std::vector<float>();

    void init(unsigned int width, unsigned int height = 1, unsigned int depth = 1);

    void from_vector(std::vector<float> &v);

    std::string to_string();
    void print();

  public:
    unsigned int size()
    {
      return action.size();
    }
};

#endif
