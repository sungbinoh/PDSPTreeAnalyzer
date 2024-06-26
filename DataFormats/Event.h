#ifndef Event_h
#define Event_h

#include "TString.h"

class Event{
public:

  Event();
  ~Event();

  void SetBeam_Momentum(double Beam_Momentum);
  inline double Beam_Momentum() const {return j_Beam_Momentum;}

private:
  double j_Beam_Momentum;

};

#endif
