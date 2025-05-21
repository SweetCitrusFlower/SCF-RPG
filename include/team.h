#pragma once

#ifndef TEAM_H
#define TEAM_H

#include "playable.h"
#include "enemy.h"

template <class Member> class Team{
    std::vector<Member> team {};
    Member M1, M2, M3;
public:
    Team(Member, Member, Member);
    Team();
    std::vector<Member> GetTeam() const {return team;}
    Member GetMember(const int i) const {return team[i - 1];}
    void ShowTeam() const;
    void MemberDeath(const Member&) const;

};

#endif //TEAM_H
