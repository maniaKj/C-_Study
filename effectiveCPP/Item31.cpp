#pragma once
#include "Item31.h"
#include "Item31_Plus.h"
//Item31.cpp
namespace Item31 {
	PersonHandle::PersonHandle(const std::string & name, const Date & birthday, const Address & addr)
		: pImpl(new PersonImpl(name, birthday, addr)) {}

	shared_ptr<PersonInterface> PersonInterface::create(const std::string& name, const Date& birthday, const Address& addr) {
		return shared_ptr<PersonInterface>(new RealPerson(name, birthday, addr));
	}
}
