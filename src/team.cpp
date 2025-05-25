#include "../include/team.h"

template <class Member>
Team<Member>::Team(Member m1, Member m2, Member m3) : team ({m1, m2, m3}) {}

template <class Member>
Team<Member>::Team() {}

template <class Member>
void Team<Member>::ShowTeam() const {
    for(int i = 0; i < 3; ++i)
        std::cout << this->team[i] << std::endl;
}

template <class Member>
void Team<Member>::MemberDeath(const Member& TM) const {
    const auto* it = find(this->GetTeam().begin(), this->GetTeam().end(), TM);
    if(it != this->GetTeam().end())
        this->team.remove(team.begin() + it);
}

template <class Member>
void Team<Member>::ChangeMember(const int i, const int k) {
    team[i - 1] = AllPlayables[k - 1];
}

