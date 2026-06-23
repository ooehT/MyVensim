#ifndef MODELIMPL_H
#define MODELIMPL_H

#include <string>
#include <vector>

// Forward Declarations (Substituem os includes pesados)
class System;
class Flow;

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

class Model {
public:
    virtual ~Model() {}
    virtual void execute(double start, double end, double increment) = 0;
    virtual void add(System* s) = 0;
    virtual void add(Flow* f) = 0;
    virtual bool remove(System* s) = 0;
    virtual bool remove(Flow* f) = 0;
    virtual std::string getName() const = 0;
    virtual void setName(const std::string& name) = 0;
    virtual std::vector<System*>::iterator beginSystems() = 0;
    virtual std::vector<System*>::iterator endSystems() = 0;
    virtual std::vector<Flow*>::iterator beginFlows() = 0;
    virtual std::vector<Flow*>::iterator endFlows() = 0;
};

class ModelBody : public Body {
    friend class UnitModel;
    friend class ModelHandle;

private:
    std::string name;
    std::vector<System*> systems;
    std::vector<Flow*> flows;
    static std::vector<Model*> models;

public:
    ModelBody();
    ModelBody(std::string name);
    ModelBody(const ModelBody& copy);
    virtual ~ModelBody();
    ModelBody& operator=(const ModelBody& copy);

    void execute(double start, double end, double increment);
    void add(System* s);
    void add(Flow* f);
    bool remove(System* s);
    bool remove(Flow* f);
    std::string getName() const;
    void setName(const std::string& name);

    std::vector<System*>::iterator beginSystems();
    std::vector<System*>::iterator endSystems();
    std::vector<Flow*>::iterator beginFlows();
    std::vector<Flow*>::iterator endFlows();
};

class ModelHandle : public Model, public Handle<ModelBody> {
    friend class UnitModel;

public:
    ModelHandle();
    ModelHandle(std::string name);
    ModelHandle(const ModelHandle& copy);
    virtual ~ModelHandle();
    ModelHandle& operator=(const ModelHandle& copy);

    void execute(double start, double end, double increment) override;
    void add(System* s) override;
    void add(Flow* f) override;
    bool remove(System* s) override;
    bool remove(Flow* f) override;
    std::string getName() const override;
    void setName(const std::string& name) override;

    std::vector<System*>::iterator beginSystems() override;
    std::vector<System*>::iterator endSystems() override;
    std::vector<Flow*>::iterator beginFlows() override;
    std::vector<Flow*>::iterator endFlows() override;
};

#endif