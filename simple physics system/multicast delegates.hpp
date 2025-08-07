#pragma once
#include <functional>
#include "usefulTypedefs.hpp"
class MultiDelegate {
private:
	std::vector<std::function<void()>> delegates;
public:
	inline void operator +=(std::function<void()>&& del) {
		delegates.push_back(del);
	}
	inline void operator ()(void) {
		for (auto& del : delegates) {
			del();
		}
	}
};