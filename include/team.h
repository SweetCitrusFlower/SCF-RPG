#pragma once

#include "playable.h"
#include "enemy.h"

#ifndef TEAM_H
#define TEAM_H

template <class Member> class Team{
protected:
    std::vector<Member> team{};

public:
    Team(Member m1, Member m2, Member m3) : team ({m1, m2, m3}) {}
    Team() {
        team.push_back(Member());
        team.push_back(Member());
        team.push_back(Member());
    }
    ~Team() = default;
    std::vector<Member>& GetTeam() {return team;}
    Member& GetMember(const int i) {return team[i];}

    void SetTeam(const std::vector<Member>& TEAM) {team = TEAM;}
    void SetMember(const int i, const Member& NewM) {
        team[i] = NewM;
    }
    void ChangeMember(const int i, const int k) {
        std::vector<Playable*> AllPlayables = {new Mera, new Dragos, new sans};
        team[i - 1] = AllPlayables[k - 1];
    }
};

#endif //TEAM_H
