#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include <string>

class System;

class Body {
public:
    virtual ~Body() {}
};

template <typename T>
class Handle {
protected:
    T* pImpl_;
public:
    Handle() : pImpl_(new T()) {}
    virtual ~Handle() { delete pImpl_; }
};

class Flow {
public:
    virtual ~Flow() {}
    virtual std::string getName() const = 0;
    virtual void setName(const std::string& name) = 0;
    virtual System* getSource() const = 0;
    virtual void setSource(System* source) = 0;
    virtual System* getTarget() const = 0;
    virtual void setTarget(System* target) = 0;
    virtual void removeSource() = 0;
    virtual void removeTarget() = 0;
    virtual double equation() = 0;
};

class FlowBody : public Body {
    friend class UnitFlow;
    friend class UnitModel;
    friend class FlowHandle;

private:
    std::string name;
    System* source;
    System* target;

public:
    FlowBody();
    FlowBody(std::string name, System* source, System* target);
    FlowBody(const FlowBody& copy);
    virtual ~FlowBody();
    FlowBody& operator=(const FlowBody& copy);

    void setSource(System* source);
    System* getSource() const;
    void setTarget(System* target);
    System* getTarget() const;
    std::string getName() const;
    void setName(const std::string& name);
    void removeSource();
    void removeTarget();
    virtual double equation();
};

class FlowHandle : public Flow, public Handle<FlowBody> {
    friend class UnitFlow;
    friend class UnitModel;

public:
    FlowHandle();
    FlowHandle(std::string name, System* source = nullptr, System* target = nullptr);
    FlowHandle(const FlowHandle& copy);
    virtual ~FlowHandle();
    FlowHandle& operator=(const FlowHandle& copy);

    std::string getName() const override;
    void setName(const std::string& name) override;
    System* getSource() const override;
    void setSource(System* source) override;
    System* getTarget() const override;
    void setTarget(System* target) override;
    void removeSource() override;
    void removeTarget() override;
    double equation() override;
};

#endif