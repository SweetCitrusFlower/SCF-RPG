#pragma once

#ifndef TEAM_H
#define TEAM_H

#include "../src/playable.cpp"
#include "../src/enemy.cpp"

template <class Member> class Team{
protected:
    std::vector<Member> team{NULL, NULL, NULL};

public:
    Team(Member, Member, Member);
    Team();
    ~Team() = default;
    std::vector<Member>& GetTeam() {return team;}
    Member& GetMember(const int i) {return team[i];}

    void SetTeam(const std::vector<Member>& TEAM) {team = TEAM;}
    void SetMember(const int i, const Member& NewM) {
        team[i] = NewM;
    }
    void ChangeMember(int, int);
    void ShowTeam() const;
    void MemberDeath(Member);

};

#endif //TEAM_H
