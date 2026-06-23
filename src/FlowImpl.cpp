#include "FlowImpl.hpp"

FlowBody::FlowBody() {
    name = "";
    source = nullptr;
    target = nullptr;
}

FlowBody::FlowBody(std::string name, System* source, System* target) {
    this->name = name;
    this->source = source;
    this->target = target;
}

FlowBody::FlowBody(const FlowBody& copy) {
    name = copy.name;
    source = copy.source;
    target = copy.target;
}

FlowBody::~FlowBody() {}

FlowBody& FlowBody::operator=(const FlowBody& copy) {
    if (this == &copy)
        return *this;

    name = copy.name;
    source = copy.source;
    target = copy.target;

    return *this;
}

void FlowBody::setSource(System* source) {
    this->source = source;
}

System* FlowBody::getSource() const {
    return source;
}

void FlowBody::setTarget(System* target) {
    this->target = target;
}

System* FlowBody::getTarget() const {
    return target;
}

std::string FlowBody::getName() const {
    return name;
}

void FlowBody::setName(const std::string& value) {
    name = value;
}

void FlowBody::removeSource() {
    source = nullptr;
}

void FlowBody::removeTarget() {
    target = nullptr;
}

FlowHandle::FlowHandle() {
    pImpl_->setName("");
    pImpl_->setSource(nullptr);
    pImpl_->setTarget(nullptr);
}

FlowHandle::FlowHandle(std::string name, System* source, System* target) {
    pImpl_->setName(name);
    pImpl_->setSource(source);
    pImpl_->setTarget(target);
}

FlowHandle::FlowHandle(const FlowHandle& copy) {
    if (copy.pImpl_) {
        pImpl_ = new FlowBody(*(copy.pImpl_));
    } else {
        pImpl_ = new FlowBody();
    }
}

FlowHandle::~FlowHandle() {}

FlowHandle& FlowHandle::operator=(const FlowHandle& copy) {
    if (this == &copy)
        return *this;

    if (copy.pImpl_) {
        *pImpl_ = *(copy.pImpl_);
    }

    return *this;
}

std::string FlowHandle::getName() const {
    return pImpl_->getName();
}

void FlowHandle::setName(const std::string& name) {
    pImpl_->setName(name);
}

System* FlowHandle::getSource() const {
    return pImpl_->getSource();
}

void FlowHandle::setSource(System* source) {
    pImpl_->setSource(source);
}

System* FlowHandle::getTarget() const {
    return pImpl_->getTarget();
}

void FlowHandle::setTarget(System* target) {
    pImpl_->setTarget(target);
}

void FlowHandle::removeSource() {
    pImpl_->removeSource();
}

void FlowHandle::removeTarget() {
    pImpl_->removeTarget();
}

double FlowBody::equation() {
    return 0.0;
}