#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include <string>

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

class System {
public:
    virtual ~System() {}
    virtual std::string getName() const = 0;
    virtual void setName(const std::string& name) = 0;
    virtual double getValue() const = 0;
    virtual void setValue(double value) = 0;
};

class SystemBody : public Body {
    friend class UnitSystem;
    friend class UnitModel;
    friend class SystemHandle;

private:
    std::string name;
    double value;

public:
    SystemBody();
    SystemBody(std::string name, double value);
    SystemBody(const SystemBody& sys);
    virtual ~SystemBody();
    SystemBody& operator=(const SystemBody& sys);

    std::string getName() const;
    void setName(const std::string& value);
    double getValue() const;
    void setValue(double value);
};

class SystemHandle : public System, public Handle<SystemBody> {
    friend class UnitSystem;
    friend class UnitModel;

public:
    SystemHandle();
    SystemHandle(std::string name, double value = 0.0);
    SystemHandle(const SystemHandle& sys);
    virtual ~SystemHandle();
    SystemHandle& operator=(const SystemHandle& sys);

    std::string getName() const override;
    void setName(const std::string& value) override;
    double getValue() const override;
    void setValue(double value) override;
};

#endif