#include <iostream>

using namespace std;

class PC {

private:
    int cpus;
    int memory;
    bool power;

public:

    static int CREATED_PCS;

    PC():
    cpus(0), memory(0), power(false)
    {
        cout << "Create PC via default constructor" << endl;
        CREATED_PCS++;
    }

    PC(int cpus, int memory, bool power):
    cpus(cpus), memory(memory), power(power)
    {
        cout << "Create PC via params constructor" << endl;
        PC::CREATED_PCS++;
    }

    PC(const PC& pc) {
        cout << "Create PC via copy constructor" << endl;

        this->cpus = pc.cpus;
        this->memory = pc.memory;
        this->power = pc.power;

        CREATED_PCS++;
    }

    int get_cpus() {
        return this->cpus;
    }

    int set_cpus() {
        return this->cpus;
    }

    int get_memory() {
        return this->memory;
    }

    bool get_power() {
        return power;
    }

    bool set_power() {
        return power;
    }

};

int PC::CREATED_PCS = 0;

void print_pc(PC pc) {
    cout << "CPUs: " << pc.get_cpus() << " ";
    cout << "Memory: " << pc.get_memory() << " ";
    cout << "Power: " << pc.get_power() << endl;
}

void print_created_pcs() {
    cout << ">>> Created PCs: " << PC::CREATED_PCS << endl;
}

int main(int argc, char** argv) {

    print_created_pcs();

    PC default_pc = PC();
    print_pc(default_pc);

    print_created_pcs();

    PC custom_pc = PC(1, 128, false);
    print_pc(custom_pc);

    print_created_pcs();

    PC copy_pc = custom_pc;
    print_pc(copy_pc);

    print_created_pcs();

    return 0;
}