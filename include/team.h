#pragma once

#ifndef TEAM_H
#define TEAM_H

#include "../src/playable.cpp"
#include "../src/enemy.cpp"

template <class Member> class Team{
protected:
    std::vector<Member> team{nullptr, nullptr, nullptr};

public:
    Team(Member, Member, Member);
    Team();
    std::vector<Member>& GetTeam() {return team;}
    Member& GetMember(const int i) {return team[i];}

    void SetTeam(const std::vector<Member>& TEAM) {team = TEAM;}
    void SetMember(const int i, const Member NewM) {
        team[i - 1] = NewM;
    }
    void ChangeMember(int, int);
    void ShowTeam() const;
    void MemberDeath(const Member&) const;

};

#endif //TEAM_H
