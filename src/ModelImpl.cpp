#include "Modelimpl.hpp"
#include "SystemImpl.hpp"
#include "Flow.hpp"

std::vector<Model*> ModelBody::models;

ModelBody::ModelBody() {
    name = "";
}

ModelBody::ModelBody(std::string name) {
    this->name = name;
}

ModelBody::ModelBody(const ModelBody& copy) {
    name = copy.name;
    systems = copy.systems;
    flows = copy.flows;
}

ModelBody::~ModelBody() {
    for (System* s : systems) {
        delete s;
    }
    systems.clear();

    for (Flow* f : flows) {
        delete f;
    }
    flows.clear();
}

ModelBody& ModelBody::operator=(const ModelBody& copy) {
    if (this == &copy)
        return *this;

    name = copy.name;
    systems = copy.systems;
    flows = copy.flows;

    return *this;
}

void ModelBody::execute(double start, double end, double increment) {
    for (double t = start; t < end; t += increment) {
        std::vector<double> results;
        for (Flow* f : flows) {
            results.push_back(f->equation());
        }

        size_t i = 0;
        for (Flow* f : flows) {
            System* source = f->getSource();
            System* target = f->getTarget();

            if (source != nullptr) {
                source->setValue(source->getValue() - results[i]);
            }
            if (target != nullptr) {
                target->setValue(target->getValue() + results[i]);
            }
            i++;
        }
    }
}

void ModelBody::add(System* s) {
    systems.push_back(s);
}

void ModelBody::add(Flow* f) {
    flows.push_back(f);
}

bool ModelBody::remove(System* s) {
    for (auto it = systems.begin(); it != systems.end(); ++it) {
        if (*it == s) {
            systems.erase(it);
            return true;
        }
    }
    return false;
}

bool ModelBody::remove(Flow* f) {
    for (auto it = flows.begin(); it != flows.end(); ++it) {
        if (*it == f) {
            flows.erase(it);
            return true;
        }
    }
    return false;
}

    std::string ModelBody::getName() const {
    return name;
}

void ModelBody::setName(const std::string& name) {
    this->name = name;
}

std::vector<System*>::iterator ModelBody::beginSystems() {
    return systems.begin();
}

std::vector<System*>::iterator ModelBody::endSystems() {
    return systems.end();
}

std::vector<Flow*>::iterator ModelBody::beginFlows() {
    return flows.begin();
}

std::vector<Flow*>::iterator ModelBody::endFlows() {
    return flows.end();
}

ModelHandle::ModelHandle() {
    pImpl_->setName("");
}

ModelHandle::ModelHandle(std::string name) {
    pImpl_->setName(name);
}

ModelHandle::ModelHandle(const ModelHandle& copy) {
    if (copy.pImpl_) {
        pImpl_ = new ModelBody(*(copy.pImpl_));
    } else {
        pImpl_ = new ModelBody();
    }
}

ModelHandle::~ModelHandle() {}

ModelHandle& ModelHandle::operator=(const ModelHandle& copy) {
    if (this == &copy)
        return *this;

    if (copy.pImpl_) {
        *pImpl_ = *(copy.pImpl_);
    }

    return *this;
}

void ModelHandle::execute(double start, double end, double increment) {
    pImpl_->execute(start, end, increment);
}

void ModelHandle::add(System* s) {
    pImpl_->add(s);
}

void ModelHandle::add(Flow* f) {
    pImpl_->add(f);
}

bool ModelHandle::remove(System* s) {
    return pImpl_->remove(s);
}

bool ModelHandle::remove(Flow* f) {
    return pImpl_->remove(f);
}

std::string ModelHandle::getName() const {
    return pImpl_->getName();
}

void ModelHandle::setName(const std::string& name) {
    pImpl_->setName(name);
}

std::vector<System*>::iterator ModelHandle::beginSystems() {
    return pImpl_->beginSystems();
}

std::vector<System*>::iterator ModelHandle::endSystems() {
    return pImpl_->endSystems();
}

std::vector<Flow*>::iterator ModelHandle::beginFlows() {
    return pImpl_->beginFlows();
}

std::vector<Flow*>::iterator ModelHandle::endFlows() {
    return pImpl_->endFlows();
}