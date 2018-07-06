#include "State.h"
#include <iostream>


State::State()
{
  m_w = 0;
  m_h = 0;
  m_d = 0;
}

State::State(unsigned int width, unsigned int height, unsigned int depth)
{
  m_w = 0;
  m_h = 0;
  m_d = 0;

  init(width, height, depth);
}

State::State(State &rhs)
{
  m_w = 0;
  m_h = 0;
  m_d = 0;

  init(rhs.w(), rhs.h(), rhs.d());
  from_vector(rhs.m_state);
}

State::~State()
{

}

State& State::operator =(State &rhs)
{
  init(rhs.w(), rhs.h(), rhs.d());
  from_vector(rhs.m_state);

  return *this;
}


State::operator std::vector<float>& ()
{
  return m_state;
}

void State::init(unsigned int width, unsigned int height, unsigned int depth)
{
  if ((width != m_w)||(height != m_h)||(depth != m_d))
  {
    m_w = width;
    m_h = height;
    m_d = depth;


    m_state.resize(size());
  }

  clear();
}

void State::from_vector(std::vector<float> &v)
{
  for (unsigned int i = 0; i < m_state.size(); i++)
    m_state[i] = v[i];
}

std::string State::to_string()
{
  std::string result;
  unsigned int ptr = 0;

  for (unsigned int d = 0; d < m_d; d++)
  {
    for (unsigned int h = 0; h < m_h; h++)
    {
      for (unsigned int w = 0; w < m_w; w++)
      {
        result+= std::to_string(m_state[ptr]) + " ";
        ptr++;
      }

      result+= "\n";
    }

    result+= "\n";
  }

  result+= "\n";


  return result;
}

void State::print()
{
  std::cout << to_string();
}


void State::set(float value, unsigned int x, unsigned int y, unsigned int z)
{
  unsigned int idx = (z*m_h + y)*m_w + x;

  m_state[idx] = value;
}

void State::clear()
{
  for (unsigned int i = 0; i < m_state.size(); i++)
    m_state[i] = 0.0;
}
