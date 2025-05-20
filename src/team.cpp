#pragma once

#include "playable.cpp"

class Team{
      std::vector<Playable*> Players {};
      std::vector<Playable*> DeadPlayers {};
public:
      void ReviveAlly(const Playable&, Playable&);
};