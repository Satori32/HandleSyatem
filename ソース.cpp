#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

template<class T>
class HandleSystem {
public:
	typedef std::size_t Handle;
/** /
	T& Get(Handle H) {
		auto I = std::find_if(D.begin(), D.end(), [&](auto& In) {return (Handle)In.I == H; });
		if (I == D.end()) { throw std::logic_error("Data is empty!"); }
		return I->D;
	}
/**/
	T* Get(Handle H) {
		auto I = std::find_if(D.begin(), D.end(), [&](auto& In) {return (Handle)In.I == H; });
		if (I == D.end()) { return nullptr; }
		return &(I->D);
	}
	Handle New() {
		Data X;
		X.I = C++;
		D.push_back(X);
		return (Handle)X.I;
	}

	bool Erase(Handle H) {
		auto I = std::find_if(D.begin(), D.end(), [&](auto& In) {return (Handle)In.I == H; });
		if (I == D.end()) { return false; }
		D.erase(I);
		return true;
	}

	bool Find(Handle H) {
		auto I = std::find_if(D.begin(), D.end(), [&](auto& In) {return (Handle)In.I == H; });
		return I != D.end();
	}

	std::size_t Size() {
		return D.size();
	}

	T& operator [](std::size_t In) {
		return D[In].D;
	}
protected:
	struct Data
	{
		std::size_t I=0;
		T D = {0,};

	};
	std::vector <Data> D;
	std::size_t C = 0;
};

int main() {
	HandleSystem<int> HS;//are you need HandleSystem to grobal variable.

	auto A = HS.New();

	auto D = HS.Find(A);

	auto B = HS.Get(A);

	*B = 0xdeadbeef;

	auto C = HS.Size();

	for (std::size_t i = 0; i < HS.Size(); i++) {
		auto X = HS[i];
	}

	HS.Erase(A);
	HS.Erase(A);
	return 0;
}