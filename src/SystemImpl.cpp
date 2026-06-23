#include "SystemImpl.hpp"

SystemBody::SystemBody() {
    name = "";
    value = 0.0;
}

SystemBody::SystemBody(std::string name, double value) {
    this->name = name;
    this->value = value;
}

SystemBody::SystemBody(const SystemBody& sys) {
    name = sys.name;
    value = sys.value;
}

SystemBody::~SystemBody() {}

SystemBody& SystemBody::operator=(const SystemBody& sys) {
    if (this == &sys)
        return *this;

    name = sys.name;
    value = sys.value;

    return *this;
}

std::string SystemBody::getName() const {
    return name;
}

void SystemBody::setName(const std::string& value) {
    name = value;
}

double SystemBody::getValue() const {
    return value;
}

void SystemBody::setValue(double value) {
    this->value = value;
}

SystemHandle::SystemHandle() {
    pImpl_->setName("");
    pImpl_->setValue(0.0);
}

SystemHandle::SystemHandle(std::string name, double value) {
    pImpl_->setName(name);
    pImpl_->setValue(value);
}

SystemHandle::SystemHandle(const SystemHandle& sys) {
    if (sys.pImpl_) {
        pImpl_ = new SystemBody(*(sys.pImpl_));
    } else {
        pImpl_ = new SystemBody();
    }
}

SystemHandle::~SystemHandle() {}

SystemHandle& SystemHandle::operator=(const SystemHandle& sys) {
    if (this == &sys)
        return *this;

    if (sys.pImpl_) {
        *pImpl_ = *(sys.pImpl_);
    }

    return *this;
}

std::string SystemHandle::getName() const {
    return pImpl_->getName();
}

void SystemHandle::setName(const std::string& value) {
    pImpl_->setName(value);
}

double SystemHandle::getValue() const {
    return pImpl_->getValue();
}

void SystemHandle::setValue(double value) {
    pImpl_->setValue(value);
}