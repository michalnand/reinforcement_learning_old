#ifndef _STATE_H_
#define _STATE_H_

#include <vector>
#include <string>

class State
{
  protected:
    std::vector<float> m_state;
    unsigned int m_w, m_h, m_d;

  public:
    State();
    State(unsigned int width, unsigned int height = 1, unsigned int depth = 1);
    State(State &rhs);
    State(const State &rhs);

    virtual ~State();

    State& operator =(State &rhs);
    State& operator =(const State &rhs);

    operator std::vector<float>&();

    void init(unsigned int width, unsigned int height = 1, unsigned int depth = 1);

    void from_vector(std::vector<float> &v);

    std::string to_string();
    void print();

    void set(float value, unsigned int x, unsigned int y = 0, unsigned int z = 0);
    void clear();

  public:
    unsigned int w()
    {
      return m_w;
    }

    unsigned int h()
    {
      return m_h;
    }

    unsigned int d()
    {
      return m_d;
    }

    unsigned int size()
    {
      return m_w*m_h*m_d;
    }
};

#endif
