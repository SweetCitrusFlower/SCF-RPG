#pragma once

#include "playable.h"
#include "enemy.h"

#ifndef TEAM_H
#define TEAM_H

template <class Member> class Team{
protected:
    std::vector<Member>* team = new std::vector<Member>;

public:
    Team(Member m1, Member m2, Member m3){
        team->push_back(m1);
        team->push_back(m2);
        team->push_back(m3);
    }
    Team() {}
    ~Team() {
        for (auto& m : *team) {
            m.~Member();
            m = nullptr;
        }
        while (!team->empty()) {team->pop_back();}
        team = nullptr;
    }
    std::vector<Member>*& GetTeam() {return team;}
    Member& GetMember(const int i) {return team->at(i);}

    void SetTeam(std::vector<Member>*& TEAM) {
        team->assign(TEAM->begin(), TEAM->end());
    }
    void SetMember(const int i, Member NewM) {
        if (team->empty()) {
            team->push_back(NewM);
        }
        else {
            delete team->at(i);
            team->at(i) = NewM;
        }
    }
};

#endif //TEAM_H
