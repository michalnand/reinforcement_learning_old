#ifndef _MOUSE_AND_CLIFF_H_
#define _MOUSE_AND_CLIFF_H_

#include <IEnvironment.h>


class MouseAndCliff: public IEnvironment
{
  private:
    unsigned int width, height;

    std::vector<std::vector<float>> rewards;
    unsigned int x, y;

    unsigned int steps_now;
    unsigned int steps_prev;
    unsigned int path_length;

  public:

    MouseAndCliff();
    MouseAndCliff(MouseAndCliff& other);
    virtual ~MouseAndCliff();
    MouseAndCliff& operator= (MouseAndCliff& other);

  public:
    void execute_action(unsigned int action_id);
    void print();

  private:
    void update_state();

};


#endif
