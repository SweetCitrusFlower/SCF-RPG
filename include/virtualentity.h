#pragma once

#ifndef VIRTUALENTITY_H
#define VIRTUALENTITY_H

class VirtualEntity {

public:
    virtual ~VirtualEntity() = default;
    virtual void ShowEntity() = 0;
};

#endif //VIRTUALENTITY_H
