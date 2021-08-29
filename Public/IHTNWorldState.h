#pragma once

class IHTNWorldState
{
public:
    IHTNWorldState() {}
    virtual ~IHTNWorldState() {}
    virtual void Print() = 0;

    virtual IHTNWorldState* clone()  const = 0;
};
