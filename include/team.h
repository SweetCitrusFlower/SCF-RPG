#pragma once

#include "playable.h"
#include "enemy.h"

#ifndef TEAM_H
#define TEAM_H

template <class Member> class Team{
protected:
    std::vector<Member> team{NULL, NULL, NULL};

public:
    Team(Member m1, Member m2, Member m3) : team ({m1, m2, m3}) {};
    Team() = default;
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
    void ShowTeam() const {
        for(int i = 0; i < 3; ++i)
            std::cout << this->team[i] << std::endl;
    }
    void MemberDeath(Member TM){
        const auto it = find(this->GetTeam().begin(), this->GetTeam().end(), TM);
        if(it != this->GetTeam().end())
            this->team.erase(it);
    }
};

#endif //TEAM_H
