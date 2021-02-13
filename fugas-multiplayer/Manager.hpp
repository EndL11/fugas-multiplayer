#pragma once
#include <list>
#include <string>

template<typename T>
class Manager {
protected:
	std::list<T> m_list;
public:
	Manager() {};
	~Manager() {};
	T GetByName(std::string t_name) {
		try {
			for (auto t : this->m_list) {
				if (t.name() == t_name) {
					return t;
				}
			}
			throw "Not found";
		}
		catch (std::string e) {
			std::cout << "Error: " << e << std::endl;
		}
	}

	T& GetById(int t_id) {
		try {
			for (auto &t : this->m_list) {
				if (t.id() == t_id) {
					return t;
				}
			}
			throw 1;
		}
		catch (int e) {
			std::cout << "Error: " << e << std::endl;
		}
	}

	void Delete(int t_id) {
		T t = this->GetById(t_id);
		list.remove(t);
	}
	void Delete(const T &t_player) {
		list.remove(t_player);
	}
	void ShowInfo(int t_id) {
		T t = this->GetById(t_id);
		t.showInfo();
	};
	void ShowInfo(std::string t_name) {
		T t = this->GetByName(t_name);
		t.showInfo();
	};
	void ShowInfo(T &t) {
		t.showInfo();
	};
	std::list<T>& list() { return this->m_list; }
};
