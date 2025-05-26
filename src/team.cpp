#include "../include/team.h"

template <class Member>
Team<Member>::Team(Member m1, Member m2, Member m3) : team ({m1, m2, m3}) {}

template <class Member>
Team<Member>::Team() = default;

template <class Member>
void Team<Member>::ShowTeam() const {
    for(int i = 0; i < 3; ++i)
        std::cout << this->team[i] << std::endl;
}

template <class Member>
void Team<Member>::MemberDeath(Member TM){
    const auto it = find(this->GetTeam().begin(), this->GetTeam().end(), TM);
    if(it != this->GetTeam().end())
        this->team.erase(it);
}

template <class Member>
void Team<Member>::ChangeMember(const int i, const int k) {
    std::vector<Playable*> AllPlayables = {new Mera, new Dragos, new sans};
    team[i - 1] = AllPlayables[k - 1];
}

