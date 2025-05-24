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
    std::vector<Member> GetTeam() const& {return team;}
    Member GetMember(const int i) const {return team[i];}

    void SetTeam(std::vector<Member> TEAM) {team = TEAM;}
    Member& SetMember(const int i, Member NewM) {
        switch (i) {
            case 0: M1 = NewM; return M1;
            case 1: M2 = NewM; return M2;
            case 2: M3 = NewM; return M3;
            default: return 0;
        }
    }
    void ChangeMember(int, int);
    void ShowTeam() const;
    void MemberDeath(const Member&) const;


};

#endif //TEAM_H
