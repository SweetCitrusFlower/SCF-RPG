#pragma once

#ifndef TEAM_H
#define TEAM_H

#include "../src/playable.cpp"
#include "../src/enemy.cpp"

template <class Member> class Team{
protected:
    std::vector<Member> team;
    Member M1, M2, M3;

public:
    Team(Member, Member, Member);
    Team();
    std::vector<Member> GetTeam() {return team;}
    Member& GetMember(const int i) {return team[i];}

    void SetTeam(const std::vector<Member>& TEAM) {team = TEAM;}
    void SetMember(const int i, Member& NewM) {
        switch (i) {
            case 0: M1 = NewM;
            case 1: M2 = NewM;
            case 2: M3 = NewM;
            default: ;
        }
    }
    void ChangeMember(int, int);
    void ShowTeam() const;
    void MemberDeath(const Member&) const;


};

#endif //TEAM_H
