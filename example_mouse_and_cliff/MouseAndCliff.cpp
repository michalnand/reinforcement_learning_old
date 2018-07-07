#include "MouseAndCliff.h"
#include <iostream>

MouseAndCliff::MouseAndCliff()
              :IEnvironment()
{
  srand(time(NULL));

  width   = 16;
  height  = 10;

  x = 0;
  y = 0;

  rewards.resize(height);
  for (unsigned int j = 0; j < height; j++)
  {
    rewards[j].resize(width);
    for (unsigned int i = 0; i < width; i++)
      rewards[j][i] = 0.0;
  }

  for (unsigned int i = 1; i < (width-1); i++)
    rewards[0][i] = -1.0;

  rewards[0][width-1] = 1.0;

  actions_count = 4;

  state.init(width, height, 1);

  update_state();

  steps_now = 0;
  steps_prev = 0;
  path_length = 0;
}


MouseAndCliff::MouseAndCliff(MouseAndCliff& other)
              :IEnvironment(other)
{
  rewards = other.rewards;
  x = other.x;
  y = other.y;

  steps_now = other.steps_now;
  steps_prev = other.steps_prev;
  path_length = other.path_length;
}

MouseAndCliff::MouseAndCliff(const MouseAndCliff& other)
              :IEnvironment(other)
{
  rewards = other.rewards;
  x = other.x;
  y = other.y;

  steps_now = other.steps_now;
  steps_prev = other.steps_prev;
  path_length = other.path_length;
}

MouseAndCliff::~MouseAndCliff()
{

}

MouseAndCliff& MouseAndCliff::operator= (MouseAndCliff& other)
{
  // this->IEnvironment::operator=other;
  state         = other.state;
  actions_count = other.actions_count;
  reward        = other.reward;

  x = other.x;
  y = other.y;
  rewards = other.rewards;

  steps_now   = other.steps_now;
  steps_prev  = other.steps_prev;
  path_length = other.path_length;

  return *this;
}

MouseAndCliff& MouseAndCliff::operator= (const MouseAndCliff& other)
{
  state         = other.state;
  actions_count = other.actions_count;
  reward        = other.reward;

  x = other.x;
  y = other.y;
  rewards = other.rewards;

  steps_now   = other.steps_now;
  steps_prev  = other.steps_prev;
  path_length = other.path_length;

  return *this;
}



void MouseAndCliff::execute_action(unsigned int action_id)
{
  int x_ = x;
  int y_ = y;

  switch (action_id)
  {
    case 0: x_++; break;
    case 1: x_--; break;
    case 2: y_++; break;
    case 3: y_--; break;
  }

  if (x_ < 0)
    x_ = 0;
  if (x_ >= (int)width)
    x_ = width-1;

  if (y_ < 0)
    y_ = 0;
  if (y_ >= (int)height)
    y_ = height-1;

  x = x_;
  y = y_;

  reward = rewards[y][x];

  score+= reward;

  if (reward > 0.0)
  {
    x = 0;
    y = 0;
  }

  if (reward < 0.0)
  {
    x = 0;
    y = 0;
  }

  if (reward > 0.0)
  {
      path_length = steps_now - steps_prev;
      steps_prev = steps_now;
  }

  steps_now++;

  update_state();
}

void MouseAndCliff::print()
{
  std::cout << "score " << score << " length " << path_length << "\n";

  for (unsigned int j = 0; j < rewards.size(); j++)
  {
    for (unsigned int i = 0; i < rewards[j].size(); i++)
    {
      if ((j == y)&&(i == x))
        std::cout << "M";
      else if (rewards[j][i] < 0.0)
        std::cout << "*";
      else if (rewards[j][i] > 0.0)
        std::cout << "T";
      else
        std::cout << ".";
      std::cout << " ";
    }

    std::cout << "\n";
  }

  std::cout << "\n\n";
}

void MouseAndCliff::update_state()
{
  state.clear();
  state.set(1.0, x, y);
}
